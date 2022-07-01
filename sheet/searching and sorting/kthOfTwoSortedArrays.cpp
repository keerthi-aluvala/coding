// Program to find k-th element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
	if (arr1 == end1)
		return arr2[k];
	if (arr2 == end2)
		return arr1[k];
	int mid1 = (end1 - arr1) / 2;
	int mid2 = (end2 - arr2) / 2;
	cout<<mid1<<" "<<mid2<<endl;
}

int main()
{
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int k = 5;
	cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
	return 0;
}

