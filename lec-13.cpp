#include<iostream>
#include<vector>
using namespace std;

//                     Total no. of occurrences of an element in a sorted array
/*
int firstOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else{//left me jao
            e = mid - 1;
        }
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;
        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else{//left me jao
            e = mid - 1;
        }
    }
    return ans;
}
int main(){

    int even[11] = {1,2,3,3,3,3,3,3,3,3,5};
    int first =firstOcc(even,11,3);
    int last =lastOcc(even,11,3);
    int count=(last-first)+1;
    cout<<count<<endl;

}
*/

//                        Peak Index in a Mountain Array
/*
int peakIndexInMountainArray(vector<int>& arr) {

    int s = 0, e = arr.size() - 1;
	
	while (s < e){
        int mid=(s + e) / 2;
		if(arr[mid] < arr[mid+1]){
     		s=mid+1;
        }
    	else{
      		e = mid;
        }
	}
	return s;
}
int main() {
    // Example mountain array
    vector<int> arr = {0, 2, 4, 6, 8, 10, 9, 7, 5, 3, 1};

    // Find and print the peak index
    int peakIndex = peakIndexInMountainArray(arr);
    cout << "The peak index is: " << peakIndex << endl;

    return 0;
}
*/