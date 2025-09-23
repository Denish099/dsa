#include <iostream>
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

int main() {

    // Heap h;
    // h.insert(7);
    // h.insert(10);
    // h.insert(12);
    // h.insert(14);
    // h.insert(5);
    // h.print();

    // h.deleteHeap();
    // h.print();

    int arr[6] = { -1, 12, 31, 14, 22, 112 }; 
    int n = 5;

    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    cout << "After heapify: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
