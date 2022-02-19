/* This program is used to implement the Pre-emptive Shortest Job First (SRTF) or Shortest Remaining Time First algorithm of the operating system. There are 3 functions: input to take input of processes with their arrival time and burst time, processing to calculate ct, wt and tat and display to display the final solution. */

#include <iostream>

using namespace std;

int n;
int at[100], bt[100], ct[100], tat[100], wt[100],b_t[100];
float awt, atat;

void input()    // taking input of processes
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
        // b_t[i] is a copy array of bt[i] to manipulate the burst times without losing the original
        b_t[i] = bt[i]; 
    }
}

void processing()    //calculating ct, wt, tat, average wt and average tat
{
    // variables same as SJF
    int current_time = 0;
    int pid = -1;
    int complete = 0;
    int min = 1000000;
    float s1,s2;

    while(complete < n)
    {
        for (int i = 0 ; i < n; i++)
        {
            if(at[i] <= current_time)
            {
                if(b_t[i] < min && ct[i] == 0)
                {
                    pid = i;          //to know which process is chosen
                    min = b_t[i];     //  shortest execution time is burst time of i
                }

                if(b_t[i] == min)     // if 2 processes have same burst times
                {
                    if(at[i] < at[pid]) // using arrival time to make decision
                    {
                        min = b_t[i];
                        pid = i;
                    }
                }                
            }
        }

        if(pid >= 0)   // if process enters the queue
        {
            b_t[pid] -= 1;    // burst time of process reduced by one 
            current_time++;   // timer incremented by one
        
        
            if(b_t[pid]==0)  // if process has been completely executed
            {
                ct[pid] = current_time;
                tat[pid] = ct[pid] - at[pid];
                wt[pid] = tat[pid] - bt[pid];
    
                s1 += wt[pid];
                s2 += tat[pid];
    
                complete++;   // complete flag incremented
                min = 1000000; // min value reset
            }
        }
        
        else // if no process scheduled by scheduler
        {
            current_time++;   // timer is incremented by one
        }
        
    }

    awt = s1/n;
    atat = s2/n;
            
}

void display()  // displaying calculated values
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
    // function calls
    input();
    processing();
    display();
}