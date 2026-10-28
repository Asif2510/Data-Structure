class sort
{
private:
	int Partition(int *arr,int lb,int ub);
	void merge(int *arr,int lb,int mid,int lb);
	
public:
	void BubbleSort(int *arr,int iSize);
	void QuickSort(int *arr,int lb,int ub);
	void MergeSort(int *arr,int lb,int ub);
};
