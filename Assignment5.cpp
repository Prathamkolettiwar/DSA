/*  Assignment 5 :
    Implement a navigation system for a delivery service using a circular linked list to represent 
    routes. The navigation system should support the following functionalities:
    a). Add route
    b). Remove route
    c). Display route

    Name - Pratham Santosh Kolettiwar
    PRN: 123B1B169
    Batch: C-2 */

#include<iostream>
using namespace std;

class Node
{
    public:
    int route;
    Node *next;
    Node *prev;

    Node()
    {
        route=0;
        next=NULL;
        prev=NULL;
    }

    Node(int d)
    {
        route=d;
        next=NULL;
        prev=NULL;
    }
};

class LL
{
    Node *head;

    public:
    
    LL()
    {
        head=0;
    }

    void insert_start(int d)
    {
        Node *nn =new Node(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while(temp->next != head && temp->next != NULL)
            {
                temp=temp->next;
            }
            head->prev=nn;
            nn->next = head;
            nn->prev = temp;
            temp->next = nn;
            head = nn; 
        }
    }
    void insert_end(int d)
    {
        Node *nn=new Node(d);
        if (head==NULL)
        {
            //cout<<"List is empty"<<endl;
            head=nn;
            return;
        }
        else
        {
            Node *temp=new Node();
            temp=head;

            while(temp->next!=head && temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            head->prev=nn;
            nn->prev=temp;
            nn->next=head;
        
        }
    }
    void display()
    {
        cout<<"Displaying Route:"<<endl;

        Node *temp=new Node();
        temp=head;
        
        while(temp->next!=head && temp->next!=NULL)
        {
            cout<<temp->route<<"  ";
            temp=temp->next;
        }
        cout<<temp->route;
    }
    void delete_start()
    {
        if(head==NULL)
        {
            cout<<"Route not present.";
        }
        else
        {
            Node *temp = new Node();
            temp = head;
            while(temp->next != head && temp->next !=NULL)
            {
                temp = temp->next;
            }
            head = head->next;
            head->prev = temp;
            temp->next = head;
        }
    }
    void delete_end()
    {
        if(head == NULL)
        {
            cout<<"LL is empty";
            return;
        }
        else{
            Node *temp = new Node();
            temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->prev->next = head;
        }
    }
};

int main()
{
    LL list;
    int d;
    string ch;
    int n;

    do
   {
        cout<<"\n1.Add route at start \n2.Add route at the end  \n3.Delete route at start \n4.Delete route at end \n5.To display route \n";
        cout<<"Enter Respective No. :";
        cin>>n;
        switch(n)
        {
            case 1:cout<<"Enter route : ";
                    cin>>d;
                    list.insert_start(d);
                    break;
            case 2:cout<<"Enter route : ";
                    cin>>d;
                    list.insert_end(d);
                    break;
            case 3:list.delete_start();
                    break;
            case 4:list.delete_end();
                    break;
            case 6:list.display();
                    break;
            default : break;
        }
        cout<<"\nEnter y to continue : ";
        cin>>ch;
   }while(ch == 'y'||ch == 'Y');
    return 0;
}