#include<iostream>
#include"doublyLinkedList.h"
using namespace std;

doublyLinkedList::doublyLinkedList()
{
    head  = nullptr;
    Last  = nullptr;
    iSize = 0;
}
bool doublyLinkedList::insertFirst(int iData)
{
    Node * NewNode = new Node(iData);

    if(NewNode == nullptr)
       return false;

    if(head == nullptr)
        head = Last = NewNode;
    else
    {
        NewNode->pNext = head;
        head->pPrev    = NewNode;
        head           = NewNode;
    }

    iSize++;
    return true;
}
bool doublyLinkedList::insertLast(int iData)
{
    Node * NewNode = new Node(iData);

    if(NewNode == nullptr)
       return false;

    if(head == nullptr)
        head = Last = NewNode;
    else
    {
        Last->pNext = NewNode;
        NewNode->pPrev = Last;
        Last = NewNode;
    }
    iSize++;
    return true;
}
bool doublyLinkedList::insertMidel(int iData,int iPos)
{
    if(iPos>=iSize+1)
        return false;
    else if(iPos==0)
    {
        return insertFirst(iData);
    }
    else if(iPos == iSize)
    {
        return insertLast(iData);
    }
    else
    {
       Node * NewNode = new Node(iData);
       Node *PrevNode = nullptr;
       Node *Traverse = head;
       if(NewNode == nullptr)
          return false; 

       int iCounter = 0;   
       while(iCounter<iPos)
       {
          PrevNode = Traverse;
          Traverse = Traverse->pNext;
          iCounter++;
       }   
       
       PrevNode->pNext = NewNode;
       NewNode->pPrev  = PrevNode;
       NewNode->pNext  = Traverse;
       Traverse->pPrev = NewNode;

       iSize++;
       return true;
    }
}
bool doublyLinkedList::DeleteFirst()
{
    if(head)
    {
        Node * Temp = head;
        
        head = head->pNext;
        head->pPrev = nullptr;
        delete Temp;
        iSize--;
        if(iSize==0)
           head = Last = nullptr;
        return true;
    }
    return false;
}
bool doublyLinkedList::DeleteLast()
{
    if(Last)
    {

        Node * Temp = Last->pPrev;
        
        delete Last;
        Temp->pNext = nullptr;
        iSize--;
        if(iSize==0)
           head = Last = nullptr;
        return true;
    }
    return false;
}
bool doublyLinkedList::DeleteMidel(int iPos)
{
    if(iPos>=iSize)
       return false;
    if(iPos==0)
    {
        return DeleteFirst();
    }
    else if(iPos == iSize-1)
    {
        return DeleteLast();
    }
    else
    {
        if(head==nullptr)
           return 0;
        int iCounter = 0;
        Node * Temp = head;
        Node * PrevNode = nullptr;
        while(iCounter<iPos)
        {
            PrevNode = Temp;
            Temp     = Temp->pNext;
            iCounter++;
        }

        PrevNode->pNext = Temp->pNext;
        Temp->pNext->pPrev = PrevNode;
        delete Temp;

        iSize--;
    }
}
void doublyLinkedList::Show()
{
    Node *Temp = head;
    while(Temp!=nullptr)
    {
        cout<<Temp->iData<<"\t";
        Temp = Temp->pNext;
    }
}
int doublyLinkedList::size()
{
    return iSize;
}
int main(void)
{
    doublyLinkedList CList;
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