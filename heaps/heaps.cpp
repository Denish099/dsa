#include <iostream>
#include <queue>
using namespace std;

class Heap {
public:
    int arr[100];
    int size;

    Heap() {
        size = 0;
        arr[0] = -1;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int par = index / 2;
            if (arr[par] < arr[index]) {
                swap(arr[par], arr[index]);
                index = par;
            } else {
                return;
            }
        }
    }

    void deleteHeap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size) {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            int largest = i;

            if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
                largest = leftIndex;
            }
            if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
                largest = rightIndex;
            }

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    int size = n;

    while (size > 1) {
        swap(arr[1], arr[size]);   // step 1
        size--;                    // step 2
        heapify(arr, size, 1);     // step 3
    }
}

int main() {
    int arr[6] = { -1, 12, 10, 4, 5, 6 }; 
    int n = 5;

    // Step 1: build max heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    cout << "Heap: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    // Step 2: sort using heap_sort
    heap_sort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
