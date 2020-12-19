
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
    struct Node *prev;
};

template<class T>
class DoublyLinkedList
{
    public:
    struct Node  <T> *  Head ;
    DoublyLinkedList()
    {
        Head = NULL;
    }
    void InsertFirst(T no )
    {
          struct Node  <T> *  newn = new Node<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        if(Head == NULL)
        {
            Head = newn;
        }
        else
        {
                newn -> next = Head;
                 Head -> prev = newn;
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
    void InsertLast(T no)
    {
        
         struct Node  <T> * newn = new Node<T>;
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;
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
        temp -> prev = temp;
      }
        
    }
    void DeleteFirst()
    {
        
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
            Head = Head -> next;
            free(Head -> prev);
            Head ->prev = NULL; 
        }
        
    }
    void DeleteLast()
    {
            struct Node <T> * temp  = Head ;
            if(Head == NULL)
            {
                return;
            }
            else if(Head -> next == NULL)
            {
                free(Head);
                Head  = NULL;
            }

            else
            {
                while(temp -> next -> next  != NULL)
                {
                 
                   temp = temp -> next;
                  
                }   
                  free(temp -> next);
                  temp -> next = NULL;
            }
            
            
    }
    int  Count()
    {
        struct Node <T> * temp = Head;
        int iCnt = 0;
        while(temp  != NULL)
        {
            iCnt++;
            temp = temp -> next;
        }
       
        return iCnt;
    }
    void InsertAtPos(T no,int pos)
    {
        int size = 0 , i = 0;
        struct Node <T> * temp = Head;
       

        size = Count();

        if((pos<1) || (pos>size+1))
        {
            return;
        }
        else if(pos == 1)
        {
            InsertFirst( no );
        }   
        else if(pos == size+1)
        {
           
            InsertLast( no );
        }
        else
        {
              struct Node  <T> *  newn = new Node<T>;
            
                newn -> data = no;
                newn -> next = NULL;
                newn -> prev = NULL;
                 for( i=1 ;i<pos - 1;i++)
                    {
                        temp = temp -> next;
                    }
                newn ->  next = temp -> next;
                temp -> next -> prev = newn;

                temp -> next = newn;
                newn -> prev = temp;
         }        
   
    }
    void DeleteAtPos(int pos)
    {
        int size = 0 , i = 0;
        size = Count();
        if(pos <1 || pos > size)
        {
            return ;
        }
        else if(pos==1)
        {
            DeleteFirst();
        }
        else if(pos == size)
        {
            DeleteLast();
        }
        else
        {
            struct Node <T> * temp = Head; 
            for(i=1 ; i<pos-1; i++)
            {   
                temp = temp -> next;
            }
            temp -> next  = temp -> next-> next;
            
            free(temp -> next -> prev);
            temp -> next -> prev = temp;

        }
        
    }
};
/*
int  main()
{ 
    DoublyLinkedList <int> obj;
   
    obj.InsertLast(10);   
    obj.InsertLast(11); 
    obj.InsertLast(12); 
    obj.InsertLast(13);
    obj.InsertFirst(9);
    obj.InsertAtPos(20,3);
    
    obj.Display();
     obj.DeleteAtPos(4);
      obj.Display();
    obj.DeleteFirst();
    obj.DeleteLast();
   
    obj.Display();
    obj.Count();

    DoublyLinkedList <char> obj1;
   
    obj1.InsertFirst('D');   
    obj1.InsertFirst('C'); 
    obj1.InsertFirst('B'); 
    obj1.InsertFirst('A');
    obj1.InsertLast('E');
     obj1.InsertAtPos('F',3);
    obj1.Display();
    obj1.Count();

   return 0;
}
*/