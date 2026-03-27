/*
-it contain At least 2 Children leaf Node
*/
#include<iostream>
using namespace std;
struct Node
{
	int iVal;
	Node *Right;
	Node *Left;

	Node()
	{
		iVal  = 0;
		Right = NULL;
		Left  = NULL;
	}

};

class MyBST
{
	struct Node *head;
	void DeleteHead();
public:
	MyBST()
	{
		head = NULL;
	}
	void insert(int iData);
	void Delete(int iData);
};
void MyBST::insert(int iData)
{
	Node * TempLeaf = NULL;
	Node * newLeaf = new Node();
	newLeaf->iVal = iData;

	if(head==NULL)
	{
		head = newLeaf;
	} 
	else
	{
		TempLeaf = head;
		bool bLeft = false;
		while(TempLeaf!=NULL)
		{
			if(TempLeaf->iVal >= newLeaf->iVal)
			{
				if(TempLeaf->Left!=NULL)
				{
					TempLeaf = TempLeaf->Left;
				}
				else
				{
					bLeft = true;
					break;
				}
				
			}
			else if(TempLeaf->iVal < newLeaf->iVal )
			{
				if(TempLeaf->Right!=NULL)
				{
					TempLeaf = TempLeaf->Right;
				}
				else
				{
					bLeft = false;
					break;
				}
			}
		}

		if(bLeft)
		  TempLeaf->Left = newLeaf;
		else
		  TempLeaf->Right = newLeaf;
	}



}
void MyBST::DeleteHead()
{
	Node * RightSideSmall = head->Right;
	Node * PreviousLeaf = NULL;

	while(RightSideSmall->Left!=NULL)
	{
		PreviousLeaf   = RightSideSmall;
		RightSideSmall = RightSideSmall->Left;
	}

	swap(head->iVal,RightSideSmall->iVal);

	delete RightSideSmall;
	PreviousLeaf->Left = NULL;

}
void MyBST::Delete(int iData)
{


	if(head->iVal == iData)
	{
		DeleteHead();
	}
	else
	{
		Node * TempLeaf = NULL;
		Node * PrevLeaf = NULL;

		TempLeaf        = head;

		bool bLeft      = false;
		while(TempLeaf!=NULL)
		{
			PrevLeaf = TempLeaf;

			if(TempLeaf->iVal > iData)
			{	
				TempLeaf = TempLeaf->Left;
				bLeft = true;
			}
			else if(TempLeaf->iVal < iData)
			{
				TempLeaf = TempLeaf->Right;	
				bLeft = false;
			}

			if(TempLeaf->iVal == iData)
			{
				if(TempLeaf->Right!=NULL)
				{
					PrevLeaf = TempLeaf->Right;
				}
				else if (TempLeaf->Left!=NULL)
				{
					PrevLeaf = TempLeaf->Left;
				}

				delete TempLeaf;
				TempLeaf = NULL;

				if(bLeft)
					PrevLeaf->Left = NULL;
				else
					PrevLeaf->Right = NULL;

			}

		}
	}
}

int main(void)
{
	MyBST obj;
	obj.insert(8);
	obj.insert(3);
	obj.insert(10);
	obj.insert(1);
	obj.insert(9);
	obj.insert(14);
	obj.insert(6);

	obj.Delete(8);


	return 0;
}