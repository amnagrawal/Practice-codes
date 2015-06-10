#include<iostream>
using namespace std;

void qsort(int a[], int ini, int fin)
{
	int partition(int a[], int ini, int fin);

	if(ini<fin)
	{
		int q = partition(a, ini, fin);
		qsort(a, ini, q-1);
		qsort(a, q+1, fin);
	}

}

int partition(int a[], int ini , int fin)
{
	int piv = a[fin];
	int i = ini-1;
	int temp;

	for(int j=ini; j<=fin-1; j++)
	{
		if(a[j]<piv)
		{
			i+=1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	temp = piv;
	a[fin] = a[i+1];
	a[i+1] = piv;

	return i+1;
}

int main()
{
	int a[8];
	cout<<"Enter the elements of the array";

	for(int i=0; i<8; i++)
	{
		cin>>a[i];
		//a[i] = 10 - i;
	}

	qsort(a, 0, 7);

	cout<<"the sorted array is:";

	for (int i = 0; i<8 ; i++)
		cout<<"  "<<a[i];

	return 0;
}
