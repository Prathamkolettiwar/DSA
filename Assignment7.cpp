/*
Assignment 7: 
Implement a browser history management system using a stack data structure to track the user's
browsing history. The system should support the following functionalities:
a. Add visited page
b. Navigate back
c. View current page
d. Check if history is empty or not

    Name - Pratham Santosh Kolettiwar
    PRN: 123B1B169
    Batch: C-2 */
#include<iostream>
#include<stack>
using namespace std;

class History
{   
    public:
    
    string stack1[5];
    string stack2[5];
    int top1,top2;

    void push (string page)
    {
        if(top1<5)
        {
            top1++;
            stack1[top1]=page;
        }
    }

    void pop()
    {
        if (top1<5)
        {
            stack1[top1]=stack2[top2];
            top1--;
        }
    }

    void viewcurrent()
    {
         if(top1==-1)
        {
            cout<<"No Page available"<<endl;
        }
        else
        {
            cout<<"Current page is:"<<stack1[top1]<<endl;
        }
    }

    void check()
    {
        if (top1==-1)
            {
                cout<<"No Browsing history present"<<endl; 
            }
        else
            {
                cout<<"Browsing History:"<<endl;
                for(int i=top1-1;i>=0;i--)
            {
                cout<<stack1[i]<<endl;
            }     
            } 
    }
};

int main()
{
    History S;
    int choice;
    string x;
    char ch;
    do
    {
        cout<<"\n1.Add visited page.\n2.Navigate back.\n3.View current page.\n4.Check if history is empty or not. \n";
        cout<<"Enter the choice."<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:cout<<"Enter url to add: ";
                    cin>>x;
                    S.push(x);
                    break;

            case 2:S.pop();

            case 3:S.viewcurrent();

            case 4:S.check();
                    
        }
        cout<<"Enter Y to continue:";
        cin>>ch;
    }
    while(ch=='y');

    return 0;
}