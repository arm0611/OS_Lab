/* This process is used to implement round robin (RR) scheduling algorithm for Operating System There are 4 functions: input to take input of processes with their arrival time and burst time, sort to sort them, processing to calculate ct, wt and tat and display to display the final solution. */

#include <iostream>

using namespace std;

int n;
// quantum is to input time quantum of system
int at[100], bt[100], b_t[100], ct[100], tat[100], wt[100], quantum; 
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
        b_t[i] = bt[i];

    }

    cout << "Enter time quantum: " ;
    cin >> quantum;
    cout << endl;

}

void sort() // sorting the values
{
    int t1, t2,t3;

    for(int i=0; i<(n-1); i++)
    {
        for(int j=0; j<(n-i-1); j++)
        {
            if(at[j]>at[j+1])
            {
                t1=at[j];
                at[j]=at[j+1];
                at[j+1]=t2;

                t2=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t2;

                t3=b_t[j];
                b_t[j]=b_t[j+1];
                b_t[j+1]=t3;
            }
        }
    }

}

void processing()
{
    int current_time = 0; 
	while (1)  // while (1) is an infinite loop which will continue till break condition is satisfied
	{
        // Somehow using the complete condition as in previous programs was giving an error which I couldn't resolve. Hence, the different approach
		bool flag = true;  // flag to verify if all processes have been executed completely

		for (int i = 0 ; i < n; i++)   
		{
			if (b_t[i] > 0)     // if burst time still remaining
			{
				flag = false;  // processes still remain to be executed
				if (b_t[i] > quantum)  
                // if remaining time more than quantum, subtract quantum from bt and increment same amount of timer
				{
					current_time += quantum;
					b_t[i] -= quantum;
				}
				else
                // if remaining time less than quantum, calculate ct[i]
				{
					current_time = current_time + b_t[i];
                    ct[i] = current_time;
					b_t[i] = 0;
				}
			}
		}

		if (flag == true) // if all processes completed
		break;
	}

    for (int i = 0; i < n ; i++) // calculating tat and wt
	{
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

void display() // displaying the values
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