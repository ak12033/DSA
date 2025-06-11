#include<iostream>
#include <vector>
using namespace std;

//                                   Pivot element
/*
int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    while(s<e) {
        int mid = s + (e-s)/2;
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;
    // return e;
}
int main() {
    int arr[10] = {5,7,7,8,9,10,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    cout << "Pivot is " << getPivot(arr, n) << endl;
}
*/

//                      Search in a Rotated Sorted Array
/*
int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    while(s<e) {
        int mid = s + (e-s)/2;
        if(arr[mid] >= arr[0]){
            s = mid+1;
        }
        else{
            e = mid;
        }
    }
    return s;
}
int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;
    while(start <= end) {
        int mid = start + (end-start)/2;
        if(arr[mid] == key) {
            return mid;
        }
        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = getPivot(nums, n);
    if( target >= nums[pivot] && target <= nums[n-1]){//BS on second line
        return binarySearch(nums, pivot, n, target);
    }
    else{//BS on first line
        return binarySearch(nums, 0, pivot - 1, target);
    }
}
int main() {
    vector<int> arr = {7, 8, 9, 10, 1, 2, 3}; // Example rotated sorted array
    int target = 1;  // Element to search for
    int result = search(arr, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
*/

//                       Square Root upto Decimal Places
/*
long long int sqrtInteger(int n) {
        
    int s = 0;
    int e = n;
    long long int ans = -1;
    while(s<=e) {
        long long int mid = s + (e-s)/2;
        long long int square = mid*mid;
            
        if(square == n){
            return mid;
        }
        if(square < n ){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;
    for(int i=0; i<precision; i++) {
        factor = factor/10;
        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}
int main() {
    int n;
    cout <<"Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<"Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}
*/