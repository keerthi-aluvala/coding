// C++ program to find a pair with the given difference
#include <bits/stdc++.h>
using namespace std;
bool findPair(int arr[], int size, int n)
{
	// Step-1 Sort the array
	sort(arr, arr + size);

	// Initialize positions of two elements
	int l = 0;
	int r = 1;

	// take absolute value of difference
	// this does not affect the pair as A-B=diff is same as
	// B-A= -diff
	n = abs(n);

	// Search for a pair

	// These roop running conditions are sufficient
	while (l <= r and r < size) {
		int diff = arr[r] - arr[l];
		if (diff == n
			and l != r) // we need distinct elements in pair
						// so l!=r
		{
			cout << "Pair Found: (" << arr[l] << ", "
				<< arr[r] << ")";
			return true;
		}
		else if (diff > n) // try to reduce the diff
			l++;
		else // Note if l==r then r will be advanced thus no
			// pair will be missed
			r++;
	}
	cout << "No such pair";
	return false;
}

// Driver program to test above function
int main()
{
	int arr[] = { 1, 8, 30, 40, 100 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int n = -60;
	findPair(arr, size, n);
	cout << endl;
	n = 20;
	findPair(arr, size, n);
	return 0;
}

// This code is contributed by Nakshatra Chhillar

