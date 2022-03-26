//雞尾酒排序 cocktail sort 時間複雜度:O(n^2)

#include<iostream>
#include<algorithm>

using namespace std;


void cocktailSort(int arr[],int size)
{
	for(int i=0;i<size;++i)
	{
		for(int j=size-1-i;j>i;--j)
		{
			if(arr[j]<arr[j-1])
				swap(arr[j],arr[j-1]);
		}

		/*
		cout<<"測試後退:"<<endl;
		for(int t=0;t<size;++t)
		{
			cout<<arr[t]<<" ";
		}
		cout<<endl;

		*/

		for(int k=i;k<size-1-i;++k)
		{
			if(arr[k]>arr[k+1])
				swap(arr[k],arr[k+1]);
		}

		/*

		cout<<"測試正向:"<<endl;
                for(int t=0;t<size;++t)
                {
                        cout<<arr[t]<<" ";
                }
                cout<<endl;

		*/

	}
}


int main()
{
	int array[10] = {5,4,8,9,1,6,7,5,3,4};
	cocktailSort(array,10);
	cout<<"Answer:"<<endl;

	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

	return 0;
}
