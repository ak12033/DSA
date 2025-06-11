#include<iostream>
using namespace std;

/*
bool isSorted(int arr[], int size) {

    // Base Case
    if(size == 0 || size == 1 ){
        return true;
    }
    if(arr[0] > arr[1])
        return false;
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }
}
int main() {

    int arr[5] = {2,4,9,8,9};
    int size = 5;

    bool ans = isSorted(arr, size);

    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }
    return 0;
}
*/

/*
int SumOfElements(int arr[], int size) {

    // Base Case
    if(size == 0 ){
        return 0;
    }
    return arr[0] + SumOfElements(arr+1, size-1);
}
int main() {

    int arr[5] = {2};
    int size = 5;

    int ans = SumOfElements(arr, size);
    cout<<ans<<endl;

    return 0;
}
*/

/*
void print(int arr[], int n) {

    cout << "Size of array is " << n << endl;

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
}
bool LinearSearch(int arr[], int size, int k ) {

    print(arr, size);
    // Base Case
    if(size == 0) {
        return false;
    }
    if(arr[0] == k) {
        return true;
    }
    else {
        bool remainingPart = LinearSearch(arr+1, size-1, k );
        return remainingPart;
    }
    return ;
}
int main() {

    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 6;
    bool ans = LinearSearch(arr, size, key);

    if(ans ){
        cout << "Present " << endl;
    }
    else{
        cout << "absent " << endl;
    }
    return 0;
}
*/

/*
void print(int arr[], int s, int e) {

    for(int i=s; i<=e; i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
}
bool BinarySearch(int *arr, int s, int e , int k ) {

    print(arr, s, e);

    // Base Case
    // Element not found
    if(s>e)
        return false;

    int mid = s + (e-s)/2;
    cout << "value of arr mid is " << arr[mid] << endl;

    // Element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return BinarySearch(arr, mid+1, e, k);
    }
    else{
        return BinarySearch(arr, s, mid-1, k);
    }
}
int main() {

    int arr[11] = {2,4,6,10,14,18,22,38,49,55,222};
    int size = 11;
    int key = 222;

    cout << "Present or not " << BinarySearch(arr, 0, size-1, key) << endl;

    return 0;
}
*/