#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//                                       Heaps

//                              Insertion and Deletion
/*
class heap {

    public:
        int arr[100];
        int size;

        heap() {

            arr[0] = -1;
            size = 0;
        }
        void insert(int val) {

            size = size + 1;
            int index = size;
            arr[index] = val;
            while(index > 1) {
                int parent = index/2; 
                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }
        void print() {

            for(int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        void deletefromheap() {

            if(size == 0) {
                cout << "nothing to delete" << endl;
                return;
            }
            // Step 1: Put last element into first index
            arr[1] = arr[size];

            // Step 2: Remove last element
            size--;

            // Step 3: Take root node to its correct position
            int i = 1;
            while(i<size) {
                int leftIndex = 2*i;
                int rightIndex = 2*i+1;
                if(leftIndex < size && arr[i] < arr[leftIndex]) {
                    swap(arr[i], arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                    swap(arr[i], arr[rightIndex]);
                    i = rightIndex;
                }
                else {
                    return;
                }
            }
        }
};
int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deletefromheap();
    h.print();

    return 0;
}
*/

//                                 Build Max Heap 
/*
void heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }  
}
vector<int> buildMaxHeap(vector<int>& arr) {

    int n = arr.size();
    for(int i = n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}
int main() {

    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "Original Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> maxHeap = buildMaxHeap(arr);
    cout << "Max-Heap: ";
    for (int i : maxHeap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                  Build Min Heap
/*
void heapify(vector<int>& arr, int n, int i) {

    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }  
}
vector<int> buildMinHeap(vector<int>& arr) {

    int n = arr.size();
    for(int i = n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}
int main() {

    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "Original Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    vector<int> minHeap = buildMinHeap(arr);
    cout << "Min-Heap: ";
    for (int i : minHeap) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                      Heap Sort

//                             Max heap in ascending order
/*
void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }  
}
void heapSort(int arr[], int n) {

    int size = n;
    while(size > 1) {
        // Step 1: Swap
        swap(arr[size], arr[1]);
        size--;

        // Step 2: Place the root element to the correct position
        heapify(arr, size, 1);
    }
}
int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Heap Creation
    for(int i = n/2; i>0; i--) {
        heapify(arr, n, i);
    }
    cout << "printing the max heap array" << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //  Heap Sort
    heapSort(arr, n);

    cout << "printing sorted array in increasing order" << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
*/

//                              Min heap in descending order
/*
void heapify(int arr[], int n, int i) {

    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    if(right <= n && arr[smallest] > arr[right]) {
        smallest = right;
    }
    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }  
}
void heapSort(int arr[], int n) {

    int size = n;
    while(size > 1) {
        // Step 1: Swap
        swap(arr[size], arr[1]);
        size--;

        // Step 2: place the root element to the correct position
        heapify(arr, size, 1);
    }
}
int main(){

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Heap Creation
    for(int i = n/2; i>0; i--) {
        heapify(arr, n, i);
    }
    cout << "printing the min heap array" << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap Sort
    heapSort(arr, n);

    cout << "printing sorted array in decreasing order" << endl;
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                     Implementation of Max Heap using Priority Queue
/*
int main() {

    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Element at Top " << pq.top() << endl;
    pq.pop();
    cout << "Element at Top " << pq.top() << endl;
    cout << "Size is " << pq.size() << endl;

    if(pq.empty()) {
        cout << "pq is empty" << endl;
    }
    else {
        cout << "pq is not empty" << endl;
    }
}
*/

//                     Implementation of Min Heap using Priority Queue
/*
int main() {

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout << "Element at Top " << minheap.top() << endl;
    minheap.pop();
    cout << "Element at Top " << minheap.top() << endl;
    cout << "Size is " << minheap.size() << endl;

    if(minheap.empty()) {
        cout << "minheap is empty" << endl;
    }
    else {
        cout << "minheap is not empty" << endl;
    }
}
*/