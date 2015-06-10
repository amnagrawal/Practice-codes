#include<iostream>
using namespace std;

int main()
{
	int a[10], item, pos;
	int b_search(int a[], int item, int i, int j);
	cout<<"Enter 10 numbers \n";
	for(int i=0;i<10;i++)
		cin>>a[i];

	cout<<"enter item to be searched for";
	cin>>item;
	pos = b_search(a, item, 0, 10);
	cout<<"item found at position:"<<pos+1;
	return 0;
}

int b_search(int a[], int item, int i, int j)
{
	int mid = (i+j)/2;
	if(a[mid]==item)
		return mid;
	else
	{
		if(a[mid]>item)
			return b_search(a, item, i, mid-1);
		if(a[mid]<item)
			return b_search(a, item, mid+1, j);
		else return mid;
	}

	return -1;
}


