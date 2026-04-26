#include<iostream>
using namespace std;
int LinearSearch(int arr[],int Key,int Size)
{
    int iCounter = 0;
    while(iCounter<=Size)
    {
        if(arr[iCounter]==Key)
        {
            return iCounter;
        }
        iCounter++;
    }
    return -1;
}
int main(void)
{
	int iSize = 0;
	int ikey   = 15;
	int arr[] = {6,7,2,12,13,4,1,14};

	iSize = sizeof(arr)/sizeof(arr[0]);

	iSize = LinearSearch(arr,ikey,iSize-1);
    cout<<"key found Index is :- "<<iSize<<endl;
    return 0;
}