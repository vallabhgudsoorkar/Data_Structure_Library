#include<iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    struct node * next;
};
template <class T>
class Queue
{
    public:                        // Characteristics
     struct node <T> * Head;
      Queue()
      {
          Head = NULL;
      }         
     int iSize = 0;
    void Enqueue(T value)
{
    struct node <T> * newn = NULL;
     newn = new struct node <T> ;  
    newn->data = value;
    newn->next = NULL;
    
    if(Head == NULL)
    {
        Head = newn;
    }
    else
    {
          struct node <T> * temp = Head;
        while (temp->next!= NULL)
        {
            temp= temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}
T Dequeue()
{
    if(Head == NULL)
    {
        cout<<"Queue is empty";
        return -1;
    }
    else
    {
        struct node <T> * temp = Head;
        Head = Head->next;
        int no = temp->data;
        delete temp;
        
        iSize--;
        
        return no;
    }
}
void Display()
{
      struct node <T> * temp = Head;
    
    while(temp!= NULL)
    {
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"\n";
}
int Count()
{
    return iSize;
}


}; // End of class Declartion






/*
int main()
{
    int choice = 1, no = 0, pos = 0;
    Queue obj;
    
    while(choice)
    {
        cout<<"Enter choice\n";
        cout<<"1 Insert in Queue: \n";
        cout<<"2 Remove from queue: \n";
        cout<<"3 Display the elements: \n";
        cout<<"4 Count number of node: \n";
        cout<<"0 Exit the application: \n";
    
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter number\n";
                cin>>no;
                obj.Enqueue(no);
            break;
            
            case 2:
                no = obj.Dequeue();
                cout<<"Removed element is : "<<no<<"\n";
            break;
            
            case 3:
                cout<<"Elements are \n";
                obj.Display();
                break;
            
            case 4:
                no = obj.Count();
                cout<<"Number of elements are : "<<no<<"\n";
                break;
            
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Wrong choice\n";
                break;
        }// End of swirch
    }   // End of while
    
    return 0;
}// End of main

*/






















