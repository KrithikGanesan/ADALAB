#include<iostream>
#include <ctime>
using namespace std;

// merge two arrays!!
void merge(int arr[],int low,int mid,int high){
	int n = high-low+1;
	
	int temp[n];
	int i = 0;
	int left = low;
	int right = mid+1;
	
	while(left<=mid && right<=high){
		if(arr[left] <= arr[right]){
			temp[i] = arr[left];
			i++;
			left++;
		}
		else {
			temp[i] = arr[right];
			i++;
			right++;
		}
	}
	
	while(left<=mid){
		temp[i] = arr[left];
		i++;
		left++;
	}
	
	while(right<=high){
		temp[i] = arr[right];
		i++;
		right++;
	}
	
	int ind = low;
	for(int i=0;i<n;i++){
		arr[ind] = temp[i];
		ind++;
	}
}

//recursive merge sort!!
void mergeSort(int arr[],int low,int high){
	if(low>=high) return;
	
	int mid = (low+high)/2;
	mergeSort(arr,low,mid);
	mergeSort(arr,mid+1,high);
	merge(arr,low,mid,high);
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
    cout<<"Array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
     cout<<endl;
	
	clock_t start = clock();  // Start measuring execution time
	mergeSort(arr, 0, n - 1);
	clock_t end = clock();

	double execution_time = double(end - start) / double(CLOCKS_PER_SEC);


	
	cout<<"After merge sort: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	// Display execution time
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;

	return 0;
}


