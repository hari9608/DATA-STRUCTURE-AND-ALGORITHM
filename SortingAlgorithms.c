#include<stdio.h>
void InsertionSort(int[], int);
void BinaryInsertionSort(int[], int);
void SelectionSort(int[], int);
void BubbleSort(int[], int);
void MergeSortPartition(int[], int, int);
void MergeSort(int[], int, int, int);
void QuickSort(int[], int, int);
void RadixSort(int[], int);
void CountSort(int[], int, int);
void display(int[], int);
int GetMax(int[], int);

int main(){
	int array[10] = {1,9,2,8,3,7,4,6,5,0};
	InsertionSort(array, 10);
	display(array, 10);

	int array1[10] = {1,9,2,8,3,7,4,6,5,0};
	BinaryInsertionSort(array1, 10);
	display(array1, 10);

	int array2[10] = {1,9,2,8,3,7,4,6,5,0};
	SelectionSort(array2, 10);
	display(array2, 10);

	int array3[10] = {1,9,2,8,3,7,4,6,5,0};
	BubbleSort(array3, 10);
	display(array3, 10);

	int array4[10] = {1,9,2,8,3,7,4,6,5,0};
	MergeSortPartition(array4, 0, 9);
	display(array4, 10);

	int array5[10] = {1,9,2,8,3,7,4,6,5,0};
	QuickSort(array5, 0, 9);
	display(array5, 10);

	int array6[10] = {1,9,2,8,3,7,4,6,5,0};
	RadixSort(array6, 10);
	display(array6, 10);
	
	return 0;
}


void InsertionSort(int arr[],int size){
	int i,j,temp;
	for(i=1; i<size; i++){
		temp=arr[i];
		for(j=i-1; (j>=0) && temp<arr[j]; j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}
	display(arr,size);
}	

int BinarySearch(int a[], int item, int low, int high){
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (item == a[mid])
		return mid + 1;
	if (item > a[mid])
		return BinarySearch(a, item, mid + 1, high);
	return BinarySearch(a, item, low, mid - 1);
}
void BinaryInsertionSort(int a[], int n){
	int i, loc, j, k, selected;
	for (i = 1; i < n; ++i){
		j = i - 1;
		selected = a[i];
		loc = BinarySearch(a, selected, 0, j);
		while (j >= loc){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(int arr[], int n){
	int i, j, min_idx;
	for (i = 0; i < n-1; i++){
		min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		if(min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}	
}

void BubbleSort(int a[], int n){
	int i = 0, j = 0, tmp;
	for (i = 0; i < n-1; i++){
		for (j = 0; j < n - i - 1; j++){
			if (a[j] > a[j + 1]){
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	display(a,n);
}

void MergeSortPartition(int arr[], int low, int high){
	if (low < high){
		int mid = (low+high)/2;
		MergeSortPartition(arr, low, mid);
		MergeSortPartition(arr, mid+1, high);
		MergeSort(arr, low, mid, high);
	}
}
void MergeSort(int a[], int low, int mid, int high){
	int i,k,m,l,temp[50];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid) && (m<=high)){
		if(a[l]<=a[m])
		temp[i++]=a[l++];
		else
		temp[i++]=a[m++];
	}
	while(l<=mid)
	temp[i++]=a[l++];
	while(m<=high)
	temp[i++]=a[m++];
	for(k=low;k<=high;k++)
	a[k]=temp[k];
}
void QuickSort(int list[], int low, int high){
	int pivot, i, j, temp;
	if (low < high)	{
		pivot = low;
		i = low;
		j = high;
		while (i < j){
			while (list[i] <= list[pivot] && i <= high)
				i++;
			while (list[j] > list[pivot] && j >= low)
				j--;
			if (i < j){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
		temp = list[j];
		list[j] = list[pivot];
		list[pivot] = temp;
		QuickSort(list, low, j - 1);
		QuickSort(list, j + 1, high);
	}
}
	
int GetMax(int arr[], int n){
	int max = arr[0];
	int i;
		for (i = 1; i < n; i++)
			if (arr[i] > max)
				max = arr[i];
	return max;
}
void CountSort(int arr[], int n, int exp){
	int output[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void RadixSort(int arr[], int n){
	int m = GetMax(arr, n);
	int exp;
	for (exp = 1; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}

void display(int a[], int n){
	int i;
	for (i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
