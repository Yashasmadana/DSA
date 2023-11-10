#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) swap(arr[i], arr[largest]), heapify(arr, n, largest);
}
/// this one u have to go through (swap+delete)
void heapSort(int arr[], int n) {
 
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
      heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {10, 15, 21, 30, 18, 19}, n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
