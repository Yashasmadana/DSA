#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
        swap(arr[i], arr[largest]), heapify(arr, n, largest);
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main()
{
    int arr[] = {10, 15, 21, 30, 18, 19}, n = sizeof(arr) / sizeof(arr[0]);
    buildHeap(arr, n);
    cout << "The max heap is: " << arr[0];
    return 0;
}
