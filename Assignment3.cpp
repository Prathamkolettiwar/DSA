/* Assignment 3:
Consider the playlist in a music player. Implement a playlist feature in music player application
using singly linked list. Each song in the playlist is represented as a node in the linked list. Each
node contains information about the song (such as title or artist or duration, etc.).
The playlist should allow users to:
a. Add songs
b. Remove songs
c. Display the entire playlist
d. Play specific songs

    Name - Pratham Santosh Kolettiwar
    PRN: 123B1B169
    Batch: C-2  */
#include<iostream>
using namespace std;

class song
{
    public:
    string title;
    song *next;

        song()
        {
            title="None";
            next=NULL;
        }

        song(string name)
        {
            title=name;
            next=NULL;
        }
};

class Playlist
{
    song *head;
    song *temp= new song();

    public:
    
    void insert_start(string name)
    {
        song *nn=new song(name);
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            head=nn;
            return;
        }
        else
        {
            nn->next=head;
            head=nn;
        }
    }
    void insert_end(string name)
    {
            song *temp = new song();
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            song *nn = new song(name);
            temp->next = nn;
    }

    void delete_start()
    {
        if(head == NULL)
        {
            cout<<"LL is empty";
        }
        else{
            head = head->next;
        }
    }

    void delete_end()
    {
        if(head == NULL)
        {
            cout<<"LL is empty.";
        }
        else{
            song *temp= new song();
            song *temp1= new song();
            temp= head;
            while(temp->next != NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = NULL;
        }
    }

    void print()
    {
        cout<<"Displaying Playlist"<<endl;

        song *temp=new song();
        temp=head;
        while(temp->next!=NULL)
        {
            cout<<temp->title<<endl;
            temp=temp->next;
        }
        cout<<temp->title;
    }
    
    void search(string val)
    {
        song *t=new song();
        t=head;
        
        while(t->next!=NULL)
        {
            if(t->title==val)
            {
                cout<<"song found"<<endl;
                cout<<"playing Song"<<endl;
            }
            else
            {
            t=t->next;
            }
        }
        if(t->title!=val)
        {
        cout<<"song not found"<<endl;
        }    
        
    }
};


int main()
{
    Playlist p;
    string song,ch,val;
    int n;
    do
   {
        cout<<"\n1.Insert song at start \n2.Insert song at the end \n3.To print playlist \n4.To search song \n5.Delete song at start \n6.Delete song at end \n7.Exit";
        cout<<"Enter Respective no.: ";
        cin>>n;
        switch(n)
        {
            case 1:cout<<"Enter song name: ";
                    cin>>song;
                    p.insert_start(song);
                    break;
            case 2:cout<<"Enter song name: ";
                    cin>>song;
                    p.insert_end(song);
                    break;
            case 3:p.print();
                    break;
            case 4:cout<<"Enter the song to search";
                    cin>>val;
                    p.search(val);
                    break; 
            case 5:p.delete_start();
                    break;
            case 6:p.delete_end();
                    break;
            case 7: return 0;
            default : break;
        }
        cout<<"\nEnter y to continue : ";
        cin>>ch;
   }while(ch == "y"||ch == "Y");
    return 0;
}