/* Assignment 2:  
Consider Employee database of PCCOE (at least 20 records). Database contains different fields of
every employee like EMP-ID, EMP-Name and EMP-Salary.
a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort
b. Arrange list of Employee alphabetically using Merge Sort
    
    Name - Pratham Santosh Kolettiwar
    PRN: 123B1B169
    Batch: C-2*/
#include<iostream>
using namespace std;

class employee
{
    public:
    string name;
    int id;
    int salary;
    int mid;

    void input()
    {
        cout<<"Enter the Name:"<<endl;
        cin>>name;
        cout<<"Enter the ID:"<<endl;
        cin>>id;
        cout<<"Enter the salary:"<<endl;
        cin>>salary;
    }
    void quicksort(employee a[],int f,int l)
        {
            if(f<l)
            {
                int pivot=f;
                int i=f+1;
                int j=l;
                while(i<j)
                {
                    while(a[i].id < a[pivot].id)
                    {
                        i++;
                    }
                    while(a[j].id > a[pivot].id)
                    {
                        j--;
                    }
                    if(i<j)
                    {
                        employee temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                    }
                    else
                    {
                        break;
                    }
                }
                employee t;
                t=a[j];
                a[j]=a[pivot];
                a[pivot]=t;
    
                quicksort(a,f,j-1);
                quicksort(a,j+1,l);
            }
        }
    void mergesort(employee a[],int l,int r)
    {
        if(l>=r)
        return ;
        else
        {
        mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
        }
    }
    
    void merge(employee a[],int l,int mid,int r)
    {
        int n1=mid+l+1,n2=r-mid;
        employee L[n1],R[n2];
    
        for(int i=0;i<n1;i++)
        {
            L[i]=a[l+i];
        }
    
        for(int j=0;j<n2;j++)
        {
            R[j]=a[mid+1+j];
        }
        int x=0; int y=0; int k=l;
    while(x<n1 && y<n2)
    {
    if(L[x].name<=R[y].name)
    {
    a[k]=L[x];
    x++;
    }
    else
    {
    a[k]=R[y];
    y++;
    }
    k++;
    }
    while(x<n1)
    {
    a[k]=L[x];
    x++; k++;
    }
    while(y<n2)
    {
    a[k]=R[y];
    y++,k++;
    }
    }
    
    void display()
    {
        cout<<"Name of the employee:"<<name<<endl;
        cout<<"ID:"<<id<<endl;
        cout<<"Salary:"<<salary<<endl;
    }
};

int main()
{
    employee a[20],x;
    int n,f=0,m;
    cout<<"Enter no. of employee: ";
    cin>>n;
    int l=0,r=n-1;
    cout<<"\n1.Add Data \n2.Display Data \n3.Sort according to id \n4.Sort according to names \n5.Exit \n";
    cout<<'\n';
    while(1)
    {
        cout<<"Enter respective no. to proceed : ";
        cin>>m;
        switch(m)
        {
            case 1: for(int i=0;i<n;i++)
                    {
                        a[i].input();
                    }
                    break;
            case 2: for(int i=0;i<n;i++)
                    {
                        cout<<i+1<<")"<<endl;
                        a[i].display();
                    }
                    break;
            case 3:x.quicksort(a,f,n-1);
                    break;
            case 4: x.mergesort(a,l,r);
                    break;
            case 5: return 0;
            default:break;
        }
    }
     return 0;
}