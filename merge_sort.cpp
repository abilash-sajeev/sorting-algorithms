// Merge sort
// Time complexity: O(nlogn)
// Space complexity: O(n)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi arr;

// Merge two sorted arrays.
void merge(int l, int m, int h) {
	int i, j;
	vi merged;

	for(i=l, j=m+1; i <= m && j <= h;) {
		if(arr[i] <= arr[j]) merged.push_back(arr[i++]);
		else merged.push_back(arr[j++]);
	}

	while(i <= m) merged.push_back(arr[i++]);
	while(j <= h) merged.push_back(arr[j++]);

	for(int i=l; i <= h; i++) arr[i] = merged[i - l];
}

// Divide and conquer
void mergeSort(int l, int h) {
	if(l >= h) return;

	int m = l + (h - l)/2;

	mergeSort(l, m);
	mergeSort(m+1, h);
	merge(l, m, h);
}

int main() {
	int n, x;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	mergeSort(0, arr.size()-1);

	for(int i=0; i<n; i++) cout << arr[i] << " ";
	cout << endl;

	return 0;
}
