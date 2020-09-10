#include<iostream>
using std::cout;
using std::endl; 
const int RUN = 32; 

typedef int (*func)(void *a,void *b);


int cmp(void *a,void *b)
{
	int my_a = *((int*)a);
	int my_b = *((int*)b);
	if(my_a < my_b)
		return -1;
	else if(my_b < my_a)
		return 1;
	else
		return 0;
}

template<typename T>
void insertionSort(T arr[], int left, int right , func f) 
{ 
    for (int i = left + 1; i <= right; i++) 
    { 
        T temp = arr[i]; 
        int j = i - 1; 
        while (f(&arr[j],&temp)!= -1 && j >= left) 
        { 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 

template<typename T>
void merge(T arr[], int l, int m, int r,func f) 
{ 
    int len1 = m - l + 1, len2 = r - m; 
    T left[len1], right[len2]; 
    for (int i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (int i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    int i = 0; 
    int j = 0; 
    int k = l; 
  
    while (i < len1 && j < len2) 
    { 
        if (f(&left[i],&right[j]) != 1) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 

    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
  
template<typename T>
void timSort(T arr[], int n , func f) 
{ 

    for (int i = 0; i < n; i+=RUN) 
    {
    	int min = i+31;
    	if(min > n-1)
    		min = n-1;
        insertionSort<T>(arr, i, min,f);
    } 

    for (int size = RUN; size < n; size = 2*size) 
    { 

        for (int left = 0; left < n; left += 2*size) 
        { 

            int mid = left + size - 1; 
            int min = (left + 2*size - 1);
			if(min > n-1)
				min = n-1;
            int right = min; 

            merge<T>(arr, left, mid, right,f); 
        } 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << "\t"; 
	cout << endl; 
} 
  

int main() 
{ 
    int arr[] = {5, 21, 7, 23, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Given Array is" << endl; 
    printArray(arr, n); 
  	func f;
  	f = cmp;
    timSort<int>(arr, n,f); 
  
    cout << "After Sorting Array is" << endl; 
    printArray(arr, n); 
    
    /*func f;
    f = cmp;
    int i =1,j =2;
    cout << f(&i,&j) << endl;*/
    return 0; 
}


