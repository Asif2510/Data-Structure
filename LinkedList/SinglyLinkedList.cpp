#include<iostream>
#include"SinglyLinkedList.h"
using namespace std;

SinglyLinkedList::SinglyLinkedList()
{
    head  = nullptr;
    Last  = nullptr;
    iSize = 0;
}
bool SinglyLinkedList::insertFirst(int iData)
{
    Node * NewNode = new Node();

    if(NewNode==NULL)
       return false;

    NewNode->iData = iData;
    NewNode->pNext = NULL;
    if(head==NULL)
    {
        head = Last = NewNode;
    }
    else
    {
       NewNode->pNext = head;
       head = NewNode;
    }
    iSize++;
    return true;
}
bool SinglyLinkedList::insertLast(int iData)
{
    Node * NewNode = new Node();

    if(NewNode==NULL)
       return false;
    NewNode->iData = iData;
    NewNode->pNext = NULL;
 
    if(head==NULL)
    {
        head = Last = NewNode;
    }
    
    Last->pNext = NewNode;
    Last = NewNode;   
    
    iSize++;
    return true;
}
bool SinglyLinkedList::insertMidel(int iData,int iPos)
{
    if(iPos>=iSize+1)
       return false;
    else if(iPos == 0)
    {
       return insertFirst(iData);
    }
    else if(iPos == iSize)
    {
        return insertLast(iData);
    }
    else
    {
       int iCounter = 0;
       Node *Traverse = head;
       Node *Previous = NULL;
       Node * NewNode = new Node();

       if(NewNode==NULL)
          return false;

       NewNode->iData = iData;
       NewNode->pNext = NULL;

       while(iCounter<iPos)
       {
         Previous = Traverse;
         Traverse = Traverse->pNext;
         iCounter++;
       }
       Previous->pNext = NewNode;
       NewNode->pNext  = Traverse;
       iSize++;
    }    
    return true;
}

bool SinglyLinkedList::DeleteFirst()
{
    if(head)
    {
      Node *Temp = head;
      head = head->pNext;
      delete Temp;
      iSize--;
      if(iSize ==0)
         head = Last = NULL;
      return true;
    }
    return false;
}
bool SinglyLinkedList::DeleteLast()
{
    Node *Traverse = head;
    Node *Prev = NULL;

    if(head)
    {
        while(Traverse->pNext!=NULL)
        {
            Prev     = Traverse;
            Traverse = Traverse->pNext;
        }

        delete Traverse;
        Traverse = NULL;
        Prev->pNext = NULL;
        Last = Prev;

        iSize--;
        if(iSize ==0)
         head = Last = NULL; 
        return true;
    }
    return false;
}

bool SinglyLinkedList::DeleteMidel(int iPos)
{
    if(iPos>=iSize)
       return false;
    else if(iPos==0)
    {
        return DeleteFirst();
    }
    else if(iPos == iSize-1)
    {
        return DeleteLast();
    }
    else
    {
       Node *Traverse = head;
       Node *Prev = NULL;
       int iCounter = 0;

       if(head)
       {
          while(iCounter < iPos)
          {
            Prev     = Traverse;
            Traverse = Traverse->pNext;
            iCounter++;
          }
          Prev->pNext = Traverse->pNext;
          delete Traverse;
          Traverse = NULL;
          iSize--;
          return true;
        }
    }

    return false;
}
void SinglyLinkedList::Show()
{
    Node *Traverse = head;

    while(Traverse!=NULL)
    {
        cout<<Traverse->iData<<"\t";
        Traverse = Traverse->pNext;
    }
}
int SinglyLinkedList::size()
{
    return iSize;
}
int main(void)
{
    SinglyLinkedList CList;
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