#include<iostream>
#include"DoublyCircularLinkedList.h"
using namespace std;
doublyCircularLinkedList::doublyCircularLinkedList()
{
    head  = nullptr;
    Last  = nullptr;
    iSize = 0;
}
bool doublyCircularLinkedList::insertFirst(int iData)
{
    Node *NewNode = new Node(iData);
    if(NewNode==nullptr)
       return false;
    if(head==nullptr)
    {
        head = Last = NewNode;
        head->pNext = head;
        head->pPrev = head;
    }
    else
    {
        NewNode->pNext = head;
        head->pPrev    = NewNode;
        head           = NewNode;
		head->pPrev    = Last;
		Last->pNext    = head;        
    }
    iSize++;
    return true;
}
bool doublyCircularLinkedList::insertLast(int iData)
{
    Node *NewNode = new Node(iData);
    if(NewNode==nullptr)
       return false; 

    if(head==nullptr)
    {
        head = Last = NewNode;
        head->pNext = head;        
    }
    else
    {
        Last->pNext    = NewNode;
        NewNode->pPrev = Last;
        NewNode->pNext = head;
        head->pPrev    = NewNode;
        Last           = NewNode;
    }

    iSize++;
    return false;
}
bool doublyCircularLinkedList::insertMidel(int iData,int iPos)
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
        Node *NewNode = new Node(iData);

        Node * Traverse = head;
        Node * PrevNode     = nullptr;

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
bool doublyCircularLinkedList::DeleteFirst()
{
    if(head!=nullptr)
    {
        if(head==Last)
        {
            delete head;
            head = Last = nullptr;
        }
        else
        {
            Node *Temp  = head;
            head        = head->pNext;
            Last->pNext = head;
            head->pPrev = Last;
            delete Temp;
        }
        iSize--;
        if(iSize==0)
           head = Last = nullptr; 
        return true;
    }
    return false;
}
bool doublyCircularLinkedList::DeleteLast()
{
    if(Last!=nullptr)
    {
        if(head==Last)
        {
            delete head;
            head = Last = nullptr;
        }
        else
        {
            Node *Temp = Last->pPrev;
            
            delete Last;
            Temp->pNext = head;
            head->pPrev = Temp;
        }
        iSize--;
        if(iSize==0)
           head = Last = nullptr;
        return true;
    }  
    return false;  
}
bool doublyCircularLinkedList::DeleteMidel(int iPos) 
{
    if(iPos>=iSize)
       return false;
    else if(iPos==0)
    {
        return DeleteFirst();
    }   
    else if(iPos==iSize-1)
    {
        return DeleteLast();
    }
    else
    {
        Node *Traverse = head;
        Node *PrevNode = nullptr;

        int iCounter = 0;
        while(iCounter<iPos)
        {
            PrevNode = Traverse;
            Traverse = Traverse->pNext;
            iCounter++;
        }

        PrevNode->pNext = Traverse->pNext;
        Traverse->pNext->pPrev = PrevNode;

        delete Traverse;

        iSize--;
        return true;

    }
}
void doublyCircularLinkedList::Show()
{
    

    if(head==nullptr)
       return ;

    Node *Temp = head;
    
    do
    {
       cout<<Temp->iData<<"\t";
       Temp = Temp->pNext;
    } while (Temp!=head);
    
}
int  doublyCircularLinkedList::size()
{
    return iSize;
}
int main(void)
{
    doublyCircularLinkedList CList;
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