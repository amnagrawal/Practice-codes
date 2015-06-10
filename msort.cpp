#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
	int a[10], i, k;
	void msort(int a[], int ini, int fin);
    cout<<"Enter 10 elements";
	for(i = 0; i<10; i++)
		cin>>a[i];

	cout<<"your array is:";
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";

	cout<<"\n";

	msort(a, 0, 9);
	cout<<"\nthe sorted array is:";
	for(i=0; i<10; i++)
		cout<<a[i]<<" ";

	return 0;
}

void msort(int a[], int ini, int fin)
{
	void merge(int a[], int ini, int mid, int fin);
	int mid = (ini + fin)/2;
	if (ini<fin)
	{
		msort(a, ini, mid);
		msort(a, mid+1, fin);
		merge(a, ini, mid, fin);
	}
}

void merge(int a[], int ini=0, int mid=0, int fin=0)
{
	int i=0, j=0, k=0;
	int l1 = mid - ini + 2;
	int l2 = fin - mid +1;
	int l[l1], r[l2];

	l[l1-1] = r[l2 - 1] = INT_MAX;

	for(i=0;i<l1-1;i++)
	{
		l[i] = a[ini+i];
	}

	for(i=0; i<l2-1;i++)
	{
		r[i] = a[mid+i+1];
	}

	for(i=0, j=0, k=ini; k<=fin; k++)
	{
		if(l[i]<r[j])
		{
			a[k] = l[i];
			i++;
		}
		else
		{
			a[k] = r[j];
			j++;
		}
	}
}
