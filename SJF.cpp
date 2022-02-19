/* This program is used to implement the Shortest Job First (SJF) algorithm of the operating system.There are 3 functions: input to take input of processes with their arrival time and burst time, processing to calculate ct, wt and tat and display to display the final solution. */

#include <iostream>

using namespace std;

int n;
int at[100], bt[100], ct[100], tat[100], wt[100];
float awt, atat;

void input()  // taking input of processes
{
    cout << "Enter number of processes: " ;
    cin >> n;
    cout << endl;

    for(int i = 0; i < n ; i++)
    {
        cout << "Enter arrival time of process P" << i <<": " ;
        cin >> at[i];
        cout << "Enter burst time of process P"<< i <<": " ;
        cin >> bt[i];
    }
}

void processing() //calculating ct, wt, tat, average wt and average tat
{
    int current_time = 0;
    // process which needs to be executed. The starting value is -1 to prevent 0th process from executing
    int pid = -1;   
    int complete = 0;    //flag to check if all processes complete
    int min = 1000000;   // to get shortest execution time. Default value is arbitary high value
    float s1,s2;

    while(complete < n)
    {
        for (int i = 0 ; i < n; i++)
        {
            if(at[i] <= current_time)
            {
                if(bt[i] < min && ct[i] == 0)
                {
                    pid = i;          //process which is chosen
                    min = bt[i];      // shortest execution time is burst time of i
                }

                if(bt[i] == min)    // if 2 processes have same burst times
                {
                    if(at[i] < at[pid]) // using arrival time to make decision
                    {
                        min = bt[i];
                        pid = i;
                    }
                }                
            }
        }

        if(pid >= 0)   // this is executed only if process enters the queue
        {
            complete++;
            min = 1000000;
            current_time += bt[pid];
            ct[pid] = current_time;
            tat[pid] = ct[pid] - at[pid];
            wt[pid] =  tat[pid]- bt[pid];
 
            s1 += wt[pid];
            s2 += tat[pid];
 
            pid = -1;
        }
        else   // if no process is present to be scheduled, timer gets incremented
        {
            current_time++;
        }
    }

    awt = s1/n;
    atat = s2/n;
            
}

void display() // displaying calculated values
{
    cout << "Pid\tAT\tBT\tCT\tTAT\tWT " << endl;
    for (int i=0; i<n; i++)
    {
        cout <<"P" << i <<"\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    cout << "Average Waiting Time: " << awt << endl;
    cout << "Average Turnaround Time: " << atat << endl;
}


int main()
{
    //function calls
    input();
    processing();
    display();
}