#include<iostream>
using namespace std;

int BinarySearch(int arr[],int iKey,int start,int end)
{
	int mid = 0;

	mid = (end+start)/2;
	if(arr[mid]==iKey)
	{
		return mid;
	}
	else if(start > end)
	{
		return -1;
	}
	else if(arr[mid]>iKey)
	{
		end   = mid-1;
	}
	else
	{
		start = mid+1;
	}
	return BinarySearch(arr,iKey,start,end);

}
int main(void)
{
	int iSize = 0;
	int ikey   = 14;
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	iSize = sizeof(arr)/sizeof(arr[0]);

	iSize = BinarySearch(arr,ikey,0,iSize-1);
	return 0;
}