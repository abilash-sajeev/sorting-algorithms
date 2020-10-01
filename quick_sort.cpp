// Quick Sort
// Time Complexity: O(n2) in worst and O(nlogn) in average and best.
// Space Complexity: O(n) in worst and O(logn) in best case.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

// Function to position the pivot element in the sorted position.
// O(n)
int partition(vi &arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    
    for(int j = l; j <= r; ++j) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[r]);

    return i + 1;
}

// Function to perform quick sort.
// O(n) in worst and O(logn) in best and average cases.
void quickSort(vi &arr, int l, int r) {
    if(l < r) {
        int q = partition(arr, l, r);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, r);
    }
}

int main() {
    int n, x;
    vi arr;

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        arr.push_back(x);
    }

    quickSort(arr, 0, n - 1);

    for(int a: arr)
        cout << a << " ";
    cout << endl;

    return 0;
}
