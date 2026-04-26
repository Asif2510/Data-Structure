#include<iostream>
using namespace std;
void BubbleSort(int *arr,int iSize)
{
    for(int iCounter1 = 0;iCounter1<iSize;iCounter1++)
    {
        bool swap = false;
        for(int iCounter2=0;iCounter2<iSize-iCounter1;iCounter2++)
        {
            if(arr[iCounter2]>arr[iCounter2+1])
            {
                arr[iCounter1] = arr[iCounter1]^arr[iCounter2];
                arr[iCounter2] = arr[iCounter1]^arr[iCounter2];
                arr[iCounter1] = arr[iCounter1]^arr[iCounter2];
                swap = true;
            }
        }
        if(!swap)
           break;
    }
}
int main(void)
{
    int iNoOfElement = 10;
    int iCounter = 0;
    int arr[10]={3,2,5,9,10,8,4,1,7,6};
    BubbleSort(arr,iNoOfElement);
    while(iCounter<iNoOfElement)
    {
        cout<<arr[iCounter]<<"\t";
        iCounter++;
    }
    
    return 0;
}