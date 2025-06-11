#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//                                      Rotate Array
/*
void rotate(vector<int>& nums, int k) {
    vector<int> temp(nums.size());
    for(int i=0;i<nums.size();i++){
        temp[(i+k)%nums.size()]=nums[i];
    }
    nums=temp;
}
int main(){

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Before rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    rotate(nums, k);

    cout << "After rotation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                             Check if Array Is Sorted and Rotated
/*
bool check(vector<int>& nums) {
    int cnt = 0;
    for(int i=1;i<nums.size();i++) {
        if(nums[i] < nums[i-1])
            cnt++;
    }
    if(nums[nums.size()-1] > nums[0]){
        cnt++;
    }
    return cnt<=1;
}
int main() {

    // Test case 1: Rotated sorted array
    vector<int> nums1 = {3, 4, 5, 1, 2};
    if (check(nums1)) {
        cout << "nums1 is a rotated sorted array." << endl;
    } 
    else {
        cout << "nums1 is NOT a rotated sorted array." << endl;
    }
    // Test case 2: Not a rotated sorted array
    vector<int> nums2 = {2, 1, 3, 4, 5};
    if (check(nums2)) {
        cout << "nums2 is a rotated sorted array." << endl;
    } 
    else {
        cout << "nums2 is NOT a rotated sorted array." << endl;
    }
    // Test case 3: Already sorted array (no rotation)
    vector<int> nums3 = {1, 2, 3, 4, 5};
    if (check(nums3)) {
        cout << "nums3 is a rotated sorted array." << endl;
    } 
    else {
        cout << "nums3 is NOT a rotated sorted array." << endl;
    }
    // Test case 4: Array with a single element (trivially true)
    vector<int> nums4 = {1,1,1};
    if (check(nums4)) {
        cout << "nums4 is a rotated sorted array." << endl;
    } 
    else {
        cout << "nums4 is NOT a rotated sorted array." << endl;
    }

    return 0;
}
*/

//                                  Sum of Two Arrays
/*
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {

	// Write your code here.
	int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0) {
        int val1 = a[i];
        int val2 = b[j];
            
        int sum = val1 + val2 + carry;   
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    // first case
    while(i>=0) {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
     // second case
    while(j>=0) {
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    
     // second case
    while(carry != 0) {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    //print(ans);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {

    // Example 1: Adding numbers 342 and 465
    vector<int> a1 = {2, 4, 3};  // Represents 342
    vector<int> b1 = {5, 6, 4};  // Represents 465

    vector<int> result1 = findArraySum(a1, a1.size(), b1, b1.size());
    cout << "Sum of 342 and 465 is: ";
    for (int num : result1) {
        cout << num;
    }
    cout << endl;  // Output: 807

    // Example 2: Adding numbers 99 and 1
    vector<int> a2 = {9, 9};      // Represents 99
    vector<int> b2 = {1};         // Represents 1

    vector<int> result2 = findArraySum(a2, a2.size(), b2, b2.size());
    cout << "Sum of 99 and 1 is: ";
    for (int num : result2) {
        cout << num;
    }
    cout << endl;  // Output: 100

    // Example 3: Adding numbers 999 and 1
    vector<int> a3 = {9, 9, 9};   // Represents 999
    vector<int> b3 = {1};         // Represents 1

    vector<int> result3 = findArraySum(a3, a3.size(), b3, b3.size());
    cout << "Sum of 999 and 1 is: ";
    for (int num : result3) {
        cout << num;
    }
    cout << endl;  // Output: 1000

    return 0;
}
*/