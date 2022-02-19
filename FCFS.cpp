/* This program is used to implement the First Come First Serve (FCFS) scheduling algorithm. There are 4 functions: input to take input of processes with their arrival time and burst time, sort to sort them based on their arrival times, processing to calculate ct, wt and tat and display to display the final solution. */

#include <iostream>

using namespace std;

int n;
int at[100], bt[100], ct[100], tat[100], wt[100];
float awt, atat;

void input() // taking input of processes
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

void sort() // sorting on basis of arrival times
{
    int t1, t2;

    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(at[j]>at[j+1])
            {
                t1=at[j];
                at[j]=at[j+1];
                at[j+1]=t2;

                t1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t2;
        
            }
        }
    }

}

void processing() //calculating ct, wt, tat, average wt and average tat
{
    float s1,s2;
    for (int i=0; i<n; i++)
    {
        if(i == 0)
        {
            ct[i] = at[i]+ bt[i];
        }
        else
        {
            ct[i] = ct[i-1]+ bt[i];
        }
        tat[i]= ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        s1 += tat[i];
        s2 += wt[i];
    }
    atat = s1/n;
    awt = s2/n;
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
    // function calls
    input();
    sort();
    processing();
    display();
}