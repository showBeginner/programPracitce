//泡沫排序 Bubble sort 時間複雜度:O(n^2)
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cout<<"Please Enter array size:";
	cin>>n;
	int array[n];
	cout<<"Please Enter array element:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}

	//BubbleSort
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(array[j] > array[j+1])
				swap(array[j],array[j+1]);
		}
	}

	cout<<"BubbleSort Array:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	return 0;
}
