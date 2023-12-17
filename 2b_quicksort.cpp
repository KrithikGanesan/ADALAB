#include<iostream>
#include<ctime>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) i++;

		while (arr[j] > pivot) j--;

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}


void quickSort(int arr[],int start,int end){
	if(start>=end)
        return;
    int p = partition(arr,start,end);
    quickSort(arr,start,p-1);
    quickSort(arr,p+1,end);
	
}
		
int main(){

	srand(time(0));  
	cout<<"Enter number of elements in array: ";
	int n;
	cin>>n;
	int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=(rand()%100);
    }
    cout<<"Random Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    clock_t start = clock();
	quickSort(arr,0,n-1);
   	clock_t end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "  <<fixed<<time_taken<<" sec\n";

	cout<<"After Quick Sort: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
 