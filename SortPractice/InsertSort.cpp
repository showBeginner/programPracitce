//插入排序 Insert Sort 時間複雜度:O(n^2)
#include<iostream>

using namespace std;


void InsertSort(int arr[],int len)
{
	int i,j,key;


	for(i=1;i<len;i++)
	{
		key = arr[i];
		j = i-1;

		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


int main()
{
	int array[10] = {8,7,9,2,7,6,0,7,10,5};

	int n=sizeof(array)/sizeof(array[0]);

	InsertSort(array,n);

	cout<<"InsertSort :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
