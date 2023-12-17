#include <iostream>
#include <ctime>
using namespace std;



void sort(int arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++) {

		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}

		if (min != i)
			swap(arr[min], arr[i]);
	}
}


int main()
{   
    clock_t start, end;
 
    
    srand(time(0));  
	int arr[5];
    for(int i=0;i<5;i++)
    {
        arr[i]=(rand()%100);
    }
    cout<<"Array: ";
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
	int n = sizeof(arr) / sizeof(arr[0]);

    	start = clock();
 	sort(arr, n);
	end = clock();
    

	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) 
    {
		cout << arr[i] << " ";
	}
    cout<<endl;

    
 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : "  <<fixed<<time_taken;
    cout << " sec " << endl;

    //calculating sapce complexity
	int size = sizeof(arr[0])*n;
	cout << "Space used by the array: " << size<< " bytes" << endl;
    
	return 0;
}
