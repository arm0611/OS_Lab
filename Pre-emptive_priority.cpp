/* This program is used to implement the Pre-emptive Priority scheduling algorithm of the operating system. There are 3 functions: input to take input of processes with their arrival time and burst time, processing to calculate ct, wt and tat and display to display the final solution. */

#include <iostream>

using namespace std;

int n;
int at[100], bt[100], ct[100], tat[100], wt[100],b_t[100], priority[100];
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
        b_t[i] = bt[i];
        // entering priority values for execution scheduling
        cout << "Enter priority of process P"<< i <<": " ;  
        cin >> priority[i];
    }
}

void processing()  // calculating the values
{
    int current_time = 0;
    int pid = -1;
    int complete = 0;
    int m = -1;   
    float s1,s2;

    while(complete < n)
    {
        for (int i = 0 ; i < n; i++)
        {
            if(at[i] <= current_time && ct[i] == 0)
            {
                if(priority[i] > m)  // getting the process with least priority
                {
                    pid = i;          
                    m = priority[i];
                }

                if(priority[i] == m) // if 2 processes have same priority
                {
                    if(at[i] < at[pid]) 
                    {
                        m = priority[i];
                        pid = i;
                    }
                }                
            }
        }

        if(pid >= 0)   // if process enters the queue
        {
            b_t[pid] -= 1; 
            current_time++;    
        
        
            if(b_t[pid]==0)  // if process execution complete
            {
                ct[pid] = current_time;
                tat[pid] = ct[pid] - at[pid];
                wt[pid] = tat[pid] - bt[pid];
    
                s1 += wt[pid];
                s2 += tat[pid];
    
                complete++;
                m = -1;
            }
        }
        
        else // if no process is scheduled
        {
            current_time++;
        }
        
    }

    awt = s1/n;
    atat = s2/n;
            
}

void display() // to display calculated values
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