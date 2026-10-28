#include<vector>
#include"sort.h"
void sort::BubbleSort(int *arr,int iSize)
{
	for(int iCounter1 = 0;iCounter1<iSize;iCounter1++)
	{
		for(int iCounter2 = 0;iCounter2<iSize-iCounter1-1;iCounter2++)
		{
			if(arr[iCounter2]>arr[iCounter2+1])
			{
				std::swap(arr[iCounter2],arr[iCounter2+1)];
			}
		}
	}
}
void  sort::QuickSort(int *arr,int lb,int ub)
{
	if(lb<ub)
	{
		int iTemp = Partition(arr,lb,ub);
		QuickSort(arr,lb,iTemp-1);
		QuickSort(arr,iTemp+1,ub);
	}
}
int sort::Partition(int *arr,int lb,int ub)
{
	int iPivot = arr[lb];
	int iStart = lb;
	int iEnd   = ub;
	if(iStart<iEnd)
	{
		while(arr[iStart]<=iPivot)
		{
			iStart++;
		}
		while(arr[iEnd]>iPivot)
		{
			iEnd--;
		}

		if(iStart<iEnd)
		{
			swap(arr[iStart],arr[iEnd]);
		}
	}
	if(iStart>iEnd)
	{
		swap(arr[lb],arr[iEnd]);
	}
	return iEnd;
}
void merge(int *arr,int lb,int mid,int lb)
{
	int i = lb;
	int j = mid +1;
	int k = 0;
	std::vector<int>TempArr;

	while(i<=mid && j<=lb)
	{
		if(arr[i]>arr[j])
		{
			TempArr.push_back(arr[j]);
			j++;
		}
		else
		{
			TempArr.push_back(arr[i]);
			i++;
		}
	}
	while(i<=mid)
	{
		TempArr.push_back(arr[i]);
		i++;
	}
	while( j<=lb)
	{
		TempArr.push_back(arr[j]);
		j++;
	}

	for(int indx =0;indx<=(int)TempArr.size();indx++)
	{
		arr[indx+lb] = TempArr[indx];
	}
}
void MergeSort(int *arr,int lb,int ub)
{
	if(lb<ub)
	{
		int mid = (lb+ub)/2;
		MergeSort(arr,lb,mid);
		MergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}

