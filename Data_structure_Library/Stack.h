#include<iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    struct node * next;
};
template <class T>
class Stack
{
    public:
   struct node <T> * Head;

    Stack()
    {
        Head = NULL;
    }
    void push(T No)
    {
      struct node <T> * newn = NULL;
        newn = new struct node <T> ;        // like malloc in c++ use new operator
        newn->data = No;
        newn->next = NULL;
        
        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn->next = Head;
            Head = newn;
        }
    }
    int  Pop()
    {
      if(Head == NULL)        // stack is empty
        {
            cout<<"Stack is empty\n";
            return -1;
        }
        else                        // Stack conrtains atleast one node
        {
            int no = 0;
            no = Head->data;
            struct node <T> * temp = Head;
            Head = Head ->next;
            delete temp;        //delete is llike a free in c
            return no;
        }
      
        
       

    }
    
    void Display()
    {
       struct node <T> * temp = Head;
        
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"\n";
    }
    int Count()
    {
       struct node <T> * temp = Head;
        int icnt = 0;
        while(temp != NULL)
        {
            icnt++;
            temp = temp -> next;
        }

    return icnt;


    }





};

/*
int main()
{
    
   int choise = 1;
     Stack <char>obj1;
    char no;
    int icnt = 0;
   while(choise != 0)
   {
       cout<<"Entre Your Choise";
       cout<<"\n 1: Push the element into the stack \n";
       cout<<"\n 2: Pop the element \n";
       cout<<"\n 3: Display the element\n";
       cout<<"\n 4: Count  the elements\n";
       cout<<"\n 0: Exit the Application\n";

      
        cin>>choise;
    switch(choise)
    {
        case 1 :
                cout<<"Entre the Number\n";
                    cin>>no;
                    obj1.push(no);
                     break;
        case 2 :
                no = obj1.Pop();
                    cout<<"Poped element is : "<<no<<"\n";
                 break;
        case 3: 
                cout<<"Elements of stack are\n";
                obj1.Display();
                 break;
        case 4:
                
                icnt= obj1.Count();
                 cout<<"Number of Elements in Stack are : "<<no<<"\n";
                 break;
        case 0:
                 cout<<"Thank you for using the application\n";
                     break;
                
        default:
                 cout<<"Wrong choice\n";
          
    }

   }
    
    return 0;
}
*/