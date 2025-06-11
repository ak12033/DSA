#include<iostream>
#include<vector>
using namespace std;

//                                 Reversing The Array
/*
vector<int> reverse(vector<int> v) {

    int s = 0;
    int e = v.size()-1;
    while(s<=e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}
void print(vector<int> v) {

    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {

    vector<int> v ;

    v.push_back(11);
    v.push_back(7);
    v.push_back(3);
    v.push_back(12);
    v.push_back(4);

    vector<int> ans = reverse(v);

    cout << "Printing reverse Array" <<endl;
    print(ans);

    return 0;
}
*/

//                          Reverse the Array after Mth position
/*
void reverseArray(vector<int> &arr , int m){

    int s = m+1;
    int e =arr.size()-1;

    while(s<=e) {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }      	
}
int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int m = 2;  // Reverse elements after index 2 (i.e., from 4 to 6)
    
    reverseArray(arr, m);

    // Output the result
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
*/

//                                  Merge Sorted Array
/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=0, j=0, k=0;
    vector<int> nums3;
    while(i<m && j<n){
        if(nums1[i]<=nums2[j]){
            nums3.push_back(nums1[i]);
            i++;
        }
        else{
            nums3.push_back(nums2[j]);
            j++;
        }
        k++;
    }        
    while(i<m){
        nums3.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        nums3.push_back(nums2[j]);
        j++;
    }
    nums1 = nums3;
}
int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};  // The first 3 elements are valid
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    // Print the merged result
    for (int num : nums1) {
        cout << num << " ";
    }

    return 0;
}
*/

//                                      Move Zeroes
/*
void moveZeroes(vector<int>& nums) {
    int left = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[left]);
            left++;
        }
    } 
}
int main() {

    // Test case 1: General case
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Before moving zeros: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    moveZeroes(nums1);

    cout << "After moving zeros: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    // Test case 2: All zeros
    vector<int> nums2 = {0, 0, 0, 0};
    cout << "Before moving zeros: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    moveZeroes(nums2);

    cout << "After moving zeros: ";
    for (int num : nums2) cout << num << " ";
    cout << endl;

    // Test case 3: No zeros
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Before moving zeros: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    moveZeroes(nums3);

    cout << "After moving zeros: ";
    for (int num : nums3) cout << num << " ";
    cout << endl;

    // Test case 4: Single element (zero)
    vector<int> nums4 = {0};
    cout << "Before moving zeros: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;

    moveZeroes(nums4);

    cout << "After moving zeros: ";
    for (int num : nums4) cout << num << " ";
    cout << endl;

    // Test case 5: Single element (non-zero)
    vector<int> nums5 = {5};
    cout << "Before moving zeros: ";
    for (int num : nums5) cout << num << " ";
    cout << endl;

    moveZeroes(nums5);

    cout << "After moving zeros: ";
    for (int num : nums5) cout << num << " ";
    cout << endl;

    return 0;
}
*/