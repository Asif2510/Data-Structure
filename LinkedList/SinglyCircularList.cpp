#include<iostream>
#include"SinglyCircularList.h"
using namespace std;

SinglyCircularLinkedList::SinglyCircularLinkedList()
{
    head  = NULL;
    Last  = NULL;
    iSize = 0;    
}
bool SinglyCircularLinkedList::insertFirst(int iData)
{
    Node *NewNode = new Node();

    if(NewNode==NULL)
       return false;
    NewNode->iData = iData;
    NewNode->pNext = NULL;
    if(head==NULL)
    {
        head = Last = NewNode;
        NewNode->pNext = NewNode;
    }
    else
    {
         NewNode->pNext = head;
         Last->pNext    = NewNode;
         head           = NewNode;
    }
    iSize++;
    return true;
}
bool SinglyCircularLinkedList::insertLast(int iData)
{
    Node *NewNode = new Node();

    if(NewNode==NULL)
       return false;
    NewNode->iData = iData;
    NewNode->pNext = NULL;
    if(head==NULL)
    {
        head = Last = NewNode;
        NewNode->pNext = NewNode;
    }
    else
    {
         Last->pNext = NewNode;
         NewNode->pNext = head;
         Last    = NewNode;
    }
    iSize++;
    return true; 
}
bool SinglyCircularLinkedList::insertMidel(int iData,int iPos)
{
    if(iPos>=iSize+1)
       return false;
    else if(iPos==0)
    {
        return insertFirst(iData);
    }
    else if(iPos==iSize)
    {
        return insertLast(iData);
    }
    else
    {
        Node * NewNode  = new Node();
        NewNode->iData = iData;
        Node * Traverse = NULL;
        Node * Prev     = NULL;
        int iCounter    = 0;

        if(NewNode==NULL)
           return false;

        Traverse = head;

        while(iCounter<iPos)
        {
            Prev     = Traverse;
            Traverse = Traverse->pNext;
            iCounter++;
        }   

        Prev->pNext    = NewNode;
        NewNode->pNext = Traverse;

        iSize++;
    }
    return true;
}
bool SinglyCircularLinkedList::DeleteFirst()
{

    if(head)
    {
      Node * NewNode = head;
      head  = head->pNext;

      Last->pNext = head;
      delete NewNode;
      iSize--;

      if(iSize==0)
       Last = head = NULL;  

      return true;
    }
    return false;
}
bool SinglyCircularLinkedList::DeleteLast()
{

    if(Last)
    {
      if(iSize==1)
         return DeleteFirst();
      Node * NewNode = head;
      Node * Prev = NULL;
      while(NewNode->pNext!= head)
      {
        Prev    = NewNode;
        NewNode = NewNode->pNext;
      }
      Prev->pNext = head;

      delete NewNode;
      Last = Prev;
      iSize--;
      if(iSize ==0)
        head = Last = NULL;  
      return true;
    }
    return false;
}
bool SinglyCircularLinkedList::DeleteMidel(int iPos)
{
    if(iPos>=iSize+1)
       return false;
    if(iPos == 0)
    {
        return DeleteFirst();
    }
    else if(iPos == iSize)
    {
        return DeleteLast();
    }
    else
    {
        Node *Traverse = head;
        Node *Prev     = NULL;
        
        int iCounter = 0;
        while(iCounter<iPos)
        {
            Prev = Traverse;
            Traverse = Traverse->pNext;
            iCounter++;
        }

        Prev->pNext = Traverse->pNext;
        delete Traverse;
        iSize--;
        return true;
    }
}
void SinglyCircularLinkedList::Show()
{
    Node *Traverse = head;

	if(head==NULL)
		return;
	do
	{
        cout<<Traverse->iData<<"\t";
        Traverse = Traverse->pNext;
	}
    while(Traverse!=head);
}
int SinglyCircularLinkedList::size()
{
    return iSize;
}
int main(void)
{
    SinglyCircularLinkedList CList;
	CList.insertFirst(20);
	CList.insertLast(30);
	CList.insertLast(50);
	CList.insertMidel(40,2);
	CList.insertFirst(10);
	CList.insertMidel(60,5);

	cout<<"Element In Linked List Is :-";
    CList.Show();
    cout<<"Size of Linked List is "<<CList.size()<<endl;
	
	CList.DeleteFirst();
	cout<<"Element In Linked List After 1st is Delete  :-";
    CList.Show();
    cout<<"Size of Linked List is "<<CList.size()<<endl;


	CList.DeleteLast();
	cout<<"Element In Linked List After Last is Delete  :-";
    CList.Show();
    cout<<"Size of Linked List is "<<CList.size()<<endl;

	CList.DeleteMidel(1);
	cout<<"Element In Linked List After Middle Postion is Delete  :-";
    CList.Show();
    cout<<"Size of Linked List is "<<CList.size()<<endl;    
    return 0;
}