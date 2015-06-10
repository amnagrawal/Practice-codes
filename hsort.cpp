#include<iostream>
using namespace std;

#define parent(i) (int)(i/2)
#define left(i) 2*i
#define right(i) (2*i)+1
#define length(a) (((sizeof(a))/(sizeof(a[0])))-1)

int hsize;
void max_heapify(int a[], int i)
{
	int largest = i;
	int l = left(i);
	int r = right(i);
	int temp;
	if (l<=hsize && a[l]>a[i])
		l = largest;
	if (r<=hsize && a[r]>a[largest])
		r = largest;
	
	if (largest != i)
		{
			temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			
			max_heapify(a, largest);
		}
}

void build_max_heap(int a[])
{
	hsize = length(a);
	
	for(int i = length(a)/2; i >= 0 ; i-- )
		max_heapify(a, i);
}


void heapsort(int a[])
{
	int temp, i;
	
	build_max_heap(a);

	for(i = length(a); i>=1; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;	
		
		hsize -= 1;
		max_heapify(a, 0);
	}	
}

int main()
{
	int a[16], i;
	
	cout<<"Enter the elements of the array";
	for(i = 0; i<16; i++)
		cin>>a[i];
		
	//cout<<length(a);
	heapsort(a);
	cout<<"The sorted array is: ";
	
	for(i = 0; i<16; i++)
		cout<<a[i]<<"  ";
	
	return 0;
}
