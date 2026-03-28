#include<iostream>
template <typename T>
class Node
{
public:
	Node <T>*Prev;
	T iData;
	Node <T>*pNext;
	Node()
	{
		pNext = NULL;
		Prev  = NULL;
	}
};
template <typename T>
class queue
{
	Node <T>*front;
	Node <T>*rear;

public:
	queue()
	{
		front = NULL;
		rear  = NULL;
	}
	bool enqueue(T iData)
	{
		Node <T>* NewNode = new Node<T>();
		if(NewNode==NULL)
			return false;

		NewNode->Prev  = NULL;
		NewNode->pNext = NULL;
		NewNode->iData = iData;

		if(front==NULL)
		{
			front = rear = NewNode;
			rear->pNext = NULL;
			rear->Prev  = NULL;
		}
		else
		{
			NewNode->pNext = front;
			front->Prev    = NewNode;
			front          = NewNode;
		}	
	}
	bool dequeue()
	{
		if(rear!=NULL)
		{
			if(rear == front)
			{
				delete rear;
				rear        = NULL;
				front       = NULL;
			}
			else 
			{
				Node <T>* NewNode = rear->Prev;
				delete rear;
				rear = NewNode;
				NewNode->pNext = NULL;
			}
			return true;
		}

		return false;
	}

	T Peekfront()
	{
		return front->iData;
	}

	T PeekRear()
	{
		return rear->iData;
	}


};

int main(void)
{
	queue<int> obj;
	obj.enqueue(10);
	obj.enqueue(20);
	obj.enqueue(30);
	obj.enqueue(40);
	obj.enqueue(50);


	obj.dequeue();
	obj.dequeue();

	int iFront = obj.Peekfront();
	int iRear = obj.PeekRear();

	return 0;
}


