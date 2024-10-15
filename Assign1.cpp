/* Assignment 1:
Consider a student database of SY COMP class (at least 15 records). Database contains different
fields of every student like Roll No, Name and SGPA.
a. Design a roll call list, arrange list of students according to roll numbers in ascending order
using Insertion Sort
b. Arrange list of students alphabetically using shell sort 

Name: Pratham Santosh Kolettiwar
PRN: 123B1B169
Batch: C-2 */

#include<iostream>
using namespace std;

class student
{
    private:
    int roll_no;
    string name;
    public:

    void input()
        {
            std::cout<<"Enter name:";
            cin>>name;
            std::cout<<"Enter roll no.:";
            cin>>roll_no;
        }

    void display()
        {
            std::cout<<"Roll no:"<<roll_no<<endl;
            std::cout<<"Name:"<<name<<endl;
        }
    void insertion_sort(student s[],int m)
    {
        for(int i=1;i<m;i++)
        {
            int j=i-1;
            student val=s[i];
            while(j>=0 && s[j].roll_no > val.roll_no)
            {
                s[j+1]=s[j];
                j--;
            }
            s[j+1]=val;
        }
    }
    void shell_sort(student a[],int m)
    {
        int gap=m/2;
        while(gap>=1)
        {
            for(int j=gap;j<m;j++)
            {
                for(int i=j-gap;i>=0;i=i-gap)
                {
                    if(a[i+gap].name>a[i].name)
                    {
                        break;
                    }
                    else{
                        student temp;
                        temp=a[i+gap];
                        a[i+gap]=a[i];
                        a[i]=temp;
                    }
                }
            } 
            gap=gap/2;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter no of students:";
    cin>>n;
    student s[100],x;
    char ch;
    int p;
    do
    {
        cout<<"\n1.Add data \n2.To display data \n3.Sorting by Roll No. \n4.Sorting by Names\n";
        cout<<"Enter respective no to proceed:";
        cin>>p;
        switch(p)
        {
            case 1:for(int i=0;i<n;i++)
                    {
                        s[i].input();
                    }
                    break;
            case 2:for(int i=0;i<n;i++)
                    {
                        s[i].display();
                    }
                    break;
            case 3:x.insertion_sort(s,n);
                    for(int i=0;i<n;i++)
                    {
                        s[i].display();
                    }
                    break;
            case 4:x.shell_sort(s,n);
                    for(int i=0;i<n;i++)
                    {
                        s[i].display(); 
                    }
                    break;
            default:break;
        }
        cout<<"To continue Enter y:";
        cin>>ch;
    } while (ch=='y');
    
    return 0;
}