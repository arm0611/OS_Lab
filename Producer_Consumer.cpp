/*This program successfully implements the producer-consumer problem using semaphores. There are 5 functions: Producer, Consumer, Status, Wait and Signal*/

#include<iostream> 
using namespace std;
int x, mutex=1, full=0, empty=x;

void wait(int *c)
{
    *c=*c-1;
}

void signal(int *c)
{
    *c=*c+1;
}

void producer()
{
    if(full==x)
        cout<<"Stack overflow"<<endl;
    else
    {
        wait(&empty); 
        wait(&mutex);
        cout<<"Process "<<full+1<<" entered"<<endl;
        signal(&mutex); signal(&full);
    }
}


void consumer()
{
    if(empty==0)
        cout<<"Stack Underflow"<<endl; 
    else
    {
        wait(&full); 
        wait(&mutex);
        cout<<"Process "<<full+1<<" consumed"<<endl;
        
        signal(&mutex); signal(&empty);
    }
}


void status()
{
 
    cout<<"Buffer status:"<<endl<<endl; 
    cout<<"Size of buffer: "<<x<<endl; 
    for(int i=0; i<full; i++) 
    {
        cout<<"Process "<<i+1<<endl;
    }
}

int main()
{

    int done = 0, m;
    
    cout<<"Enter size of buffer"<<endl; 
    cin>>x;
    cout<<endl;
    while(m != 4)
    {
        cout<<"1. Produce"<<endl;
        cout<<"2. Consume"<<endl; 
        cout<<"3. Check buffer status"<<endl; 
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:"<<endl; 
        cin>>m;
        
    
    
        switch(m)
        {
            case 1: producer();
                    break;
            case 2: consumer();
                    break; 
            case 3: status();
                    break;
            case 4: cout << "Exit" << endl;
                    break;
            default:cout << "Error" << endl;
         
        }    
    }
}
