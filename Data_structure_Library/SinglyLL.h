/*  
    Linked List Templet
*/
#include<cstddef>
#include<iostream>
using namespace std;
typedef int BOOL;

#define true 1
#define false 0
template <class T>
struct Node
{
   T data ;
    struct Node *next;
};

template<class T>
class SinglyLinkedList
{
    public:
    struct Node  <T> *  Head ;
    SinglyLinkedList()
    {
        Head = NULL;
    }
    void InsertFirst(T no )
    {
          struct Node  <T> *  newn = new Node<T>;

        newn -> data = no;
        newn -> next = NULL;

        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
            newn -> next = Head;
            Head = newn;
        }
    }
    void Display()
    {
         struct Node  <T> * temp = NULL;
        temp = Head ;
        while(temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp -> next;
        } 
        cout<<"\n";
    }
    void InserLast(int no)
    {
        
         struct Node  <T> * newn = new Node<T>;
        newn -> data = no;
        newn -> next = NULL;
        if(Head == NULL)
        {
            Head = newn;
        }
      else
      {
         struct Node  <T> *  temp = Head;
         while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
      }
        
    }
    int  Count()
    {
        int iCnt = 0;
        struct Node <T> * temp = Head;
        while(temp != NULL)
        {
            iCnt++;
            temp = temp -> next;
        }
        return iCnt;
    }
    void DeleteFirst()
    {
        struct Node <T> * temp = Head;

             Head =  Head -> next;
            free(temp);
           
        
        
    }
    void DeleteLast()
    {
        struct Node <T> * temp = Head;
        if(Head == NULL)
        {
            return;
        }
        else if(Head -> next == NULL)
        {
            free(Head);
            Head = NULL;
        } 
        else   
       { 
           while(temp -> next -> next != NULL)
            {
             temp = temp -> next;
            }

            free(temp -> next);
            temp -> next = NULL;
       } 
    }
    void InserAtPos(T no , int pos)
    {
        int size = 0 , i =0;
        size = Count();
        if((pos<1 ) || (pos>size+1))
        {
            return;
        } 
        else if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == size+1)
        {
            InserLast(no);
        }
        else
        {
            struct Node <T> * temp = Head;
            struct Node <T> * newn = new Node<T>;
            newn -> data = no;
            newn -> next = NULL;
            for(i=1;i<pos-1;i++)
            {
                temp = temp -> next;
            }
            newn -> next = temp -> next;
           temp -> next =  newn;

        }
        
    }
    void DeleteAtPos(int pos)
    {
        int size = 0  ,i = 0;
        size = Count();
        if((pos<1) || (pos >size+1))
        {
            return;
        }
        else if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == size+1)
        {
            DeleteLast();
        }
        else
        {
            struct Node <T> * temp = Head;
            for(i= 0;i<pos-1;i++)
            {
                temp = temp -> next;
            }
            temp -> next = temp -> next -> next;
            free(temp -> next);
        }
        

    }
};
/*
int  main()
{ 
    SinglyLinkedList <int> obj;
   
    obj.InsertFirst(10);   
    obj.InsertFirst(11); 
    obj.InsertFirst(12); 
    obj.InserLast(9);
    obj.Display();
    obj.InserAtPos(15,2);
      obj.Display();
    obj.DeleteAtPos(3);
     obj.Display();

    SinglyLinkedList <char> obj1;
   
    obj1.InsertFirst('A');   
    obj1.InsertFirst('B'); 
    obj1.InsertFirst('C'); 
    obj1.InserLast('D');
    obj1.Display();

   return 0;
}
*/