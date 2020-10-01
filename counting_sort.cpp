// Counting sort
// Time complexity: O(n + k)
// Space complexity: O(n + k)

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

// Expects elements from 0 to r. Use offset if it is not the case.
vi countingSort(vi arr, int n, int r) {
	vi count(r), sorted(n);

	memset(&count[0], 0, sizeof(count));
	memset(&sorted[0], 0, sizeof(sorted));

	for(auto element: arr) count[element]++;
	for(int i=1; i<n; i++) count[i] += count[i-1];
	for(auto element: arr) sorted[count[element]--] = element;

	return sorted;
}

int main() {
	int n, x, r;
	vi arr;

	cin >> n >> r;
	for(int i=0; i<n; i++) {
		cin >> x;
		arr.push_back(x);
	}

	vi sorted = countingSort(arr, n, r);

	for(auto element: sorted) cout << element << ' ';
	cout << endl;

	return 0;
}
