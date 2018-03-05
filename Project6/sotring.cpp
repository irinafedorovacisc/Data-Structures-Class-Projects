#include<iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
void randomize(int arr[],int n);
void print(int a[], int n);
void fillarray(int arr[], int n);
void reverseit(int arr[], int n);
void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void swap2(int arr[], int n);
void heapSort(int arr[], int n);


int main(){

 int a1[10],a2[10],a3[10];  //a1- is almost sorted a2-random, a3-reversed
 int b1[50],b2[50],b3[50];
 int c1[100],c2[100],c3[100];

fillarray(a1,10);
cout << "10 Almost sorted numbers before sorting: " << endl;
print(a1,10);
randomize(a2,10);
cout << "10 Random numbers before sorting: " << endl;
print(a2,10);
reverseit(a3,10);
cout << "10 Reversed numbers before sorting: " << endl;
print(a3,10);
// the sorting
bubbleSort(a1,10);
cout << "Array after the bubble sort: " << endl;
print(a1,10);
fillarray(a1,10);
quickSort(a1,0,9);
cout << "Array after the quickSort sort: " << endl;
print(a1,10);
fillarray(a1,10);
heapSort(a1,10);
cout << "Array after the heap: " << endl;

print(a2,10);
bubbleSort(a2,10);
cout << "Array after the bubble sort: " << endl;
print(a2,10);

fillarray(b1,50);
cout << "50 Almost sorted numbers before sorting: " << endl;
print(b1,50);
randomize(b2,50);
cout << "50 Random numbers before sorting: " << endl;
print(b2,50);
reverseit(b3,50);
cout << "50 Reversed numbers before sorting: " << endl;
print(b3,50);

fillarray(c1,100);
cout << "100 Almost sorted numbers before sorting: " << endl;
print(c1,100);
randomize(c2,100);
cout << "100 Random numbers before sorting: " << endl;
print(c2,100);
reverseit(c3,100);
cout << "100 Reversed numbers before sorting: " << endl;
print(c3,100);

}
void swap2(int arr[], int n){
     int temp = arr[0];
     arr[0] = arr[1];
     arr[1] = temp;
     temp =arr[n-1];
     arr[n-1] = arr[n-2];
     arr[n-2] = temp;
}

void fillarray(int arr[], int n){
 int temp;
 for(int i = 0; i < n; i++)
        arr[i]=i;
    swap2(arr,n);
}
void reverseit(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i]=i;
   int temp;
   for (int i = 0; i < n/2; ++i)
   {
      temp = arr[i];
      arr[i] = arr[n-i-1];
      arr[n-i-1] = temp;
   }
}
void randomize(int arr[], int n){
    for(int i = 0; i < n; i++)
        arr[i]=(rand() % 100);
}

void print(int a[], int n) {
	cout << "{";
	for (int i = 0; i < n; i++)
		cout << a[i] << (i < n-1 ? ", " : "");
	cout << "}" <<endl<<endl;
}

// bubble sort

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
//A function to implement a quickSort

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


