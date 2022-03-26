//雞尾酒排序 cocktail sort 時間複雜度:O(n^2)

#include<iostream>

using namespace std;


void cocktailSort(int array[],int size)
{
	int leng = size;
	int font=0;
	int end = leng-1;
	int sort =1;
	while(font < size && end >= 0){
		sort = 1;
		for(int i=font;i<end;i++){
			if(array[i] > array[i+1]){
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				sort = 0;
			}
		}
		if(sort)
			break;
		--end;
		sort=1;
		for(int j=end;j>font;j--){
			if(array[j] < array[j-1]){
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
				sort=0;
			}
		}
		if(sort)
			break;
		++font;
	
	}
}


int main()
{
	int array[10] = {5,4,8,9,1,6,7,5,3,4};
	cout<<"array:"<<endl;
	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cocktailSort(array,10);
	cout<<"Answer:"<<endl;

	for(int i=0;i<10;i++)
	{
		cout<<array[i]<<" ";
	}
	cout<<endl;

	return 0;
}
