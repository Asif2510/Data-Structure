#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:
    T iData;
    Node <T>*pNext;
    Node()
    {
        pNext = NULL;
    }

};
template<typename T>
class Stack
{
   Node <T>*head;
   public:
   Stack()
   {
      head = NULL; 
   }
   Stack(Stack <T>&Data)
   {
       if(Data.head)
       {
          head = new Node<T>();
          if(head)
          {
            head = Data.head;
          }
       }
   }
   Stack* operator=(Stack<T>&Data)
   {
       if(Data.head)
       {
          head = new Node<T>();
          if(head)
          {
            head = Data.head;
          }
       }
      return this;
   } 
   bool push(T iData)
   {
        Node <T>*NewNode =  new Node<T>();
        if(head==NULL && NewNode!=NULL)
        {
            NewNode->iData = iData;
            head = NewNode;
			head->pNext = NULL;
        }
        else if(NewNode)
        {
            NewNode->iData = iData;
            NewNode->pNext = head;
            head = NewNode;
        }
        else
        {
            return false;
        }
        return true;
   }
   bool pop()
   {
     if(head)
     {
        Node<T> *NewNode =  head->pNext;
        delete []head;
        head = NewNode;
        return true;
     }
     return false;
   } 
   void show()
   {
	   Node<T> *NewNode =  head;
       while(NewNode)
	   {
		   cout<<NewNode->iData<<"\t";
		   NewNode = NewNode->pNext;
	   }
   }
};
int main(void)
{
	Stack<char>obj;
	obj.push('a');
	obj.push('s');
	obj.push('i');
	obj.push('f');

	obj.show();

	obj.pop();
	obj.pop();
	cout<<"\n";
	obj.show();
    return 0;
}