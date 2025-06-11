#include <iostream>
#include <algorithm>
#include <vector>
#include<set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//                                       Swap alternate
/*
void printArray(int arr[], int n) {

    for(int i = 0; i<n; i++ ) {
        cout<< arr[i] <<" ";
    }cout<<endl;

}
void swapAlternate(int arr[], int size) {

    for(int i = 0; i<size; i+=2 ) {
        if(i+1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }
}
int main() {

    int even[8] = {5,2,9,4,7,6,1,0};
    int odd[5] = {11, 33, 9, 76, 43};

    printArray(even, 8);
    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    printArray(odd, 5);
    swapAlternate(odd, 5);
    printArray(odd, 5);

    return 0;
}
*/
/*
void printArray(int arr[], int n) {

    for(int i = 0; i<n; i++ ) {
        cout<< arr[i] <<" ";
    }cout<<endl;

}
void swapAlternate(int arr[], int size) {

    for(int i = 1; i<size; i+=2 ) {
        swap(arr[i], arr[i-1]);
    }
}
int main() {

    int even[8] = {5,2,9,4,7,6,1,0};
    int odd[5] = {11, 33, 9, 76, 43};

    printArray(even, 8);
    swapAlternate(even, 8);
    printArray(even, 8);

    cout << endl;

    printArray(odd, 5);
    swapAlternate(odd, 5);
    printArray(odd, 5);

    return 0;
}
*/

//                                      Find Unique
/*
int findUnique(int *arr, int size){
    //Write your code here
    int ans=0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    return ans;
}
int main() {
    int arr[] = {2, 3, 5, 2, 3, 7, 7};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate array size

    int unique = findUnique(arr, size);
    cout << "The unique element is: " << unique << endl;

    return 0;
}
*/

//                             Unique Number of Occurrences
/*
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    for (auto i : arr) {
        mp[i]++;
    }

    unordered_set<int> s1;
    for (auto i : mp) {
        s1.insert(i.second);
    }
    return s1.size() == mp.size();
}
int main() {
    vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    cout << "Test case 1: " << (uniqueOccurrences(arr1) ? "True" : "False") << endl;

    vector<int> arr2 = {1, 2, 2, 1, 1, 2};
    cout << "Test case 2: " << (uniqueOccurrences(arr2) ? "True" : "False") << endl;

    vector<int> arr3 = {10, 20, 30, 40, 50};
    cout << "Test case 3: " << (uniqueOccurrences(arr3) ? "True" : "False") << endl;

    vector<int> arr4 = {5, 5, 6, 6, 6};
    cout << "Test case 4: " << (uniqueOccurrences(arr4) ? "True" : "False") << endl;

    return 0;
}
*/

//                                 Duplicate in Array
/*
int findDuplicate1(vector<int> &arr) {

    int ans = 0;
    //XOR ing all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}
int findDuplicate(vector<int> &arr) {
    // Write your code here
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(i+1<arr.size()){
            if(arr[i]==arr[i+1]){
                return arr[i];
            }
        }   
    }
}
int main() {

    vector<int> arr = {3, 1, 3, 4, 2};
    cout << "The duplicate is: " << findDuplicate(arr) << endl;
    return 0;
}
*/

//                       Find All Duplicates in an Array
/*
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    sort(nums.begin(),nums.end());
    for (int i=0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1]){
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> duplicates = findDuplicates(nums);

    cout << "Duplicates: ";
    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
*/

//                        Intersection of Two Sorted Arrays
/*
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m){

	int i = 0; 
    int j = 0;
    vector<int> ans;
    while(i<n && j<m) {
		if(arr1[i]==arr2[j]){
			ans.push_back(arr1[i]);
        	i++;
        	j++;
    	}
    	else if (arr1[i] < arr2[j]) {
  			i++;
		}
    	else{
    		j++;
		}
    }
    return ans;
}
int main() {
    // Test Case 1: Arrays with common elements
    vector<int> arr1 = {1, 2, 4, 5, 6};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int n1 = arr1.size();
    int n2 = arr2.size();
    
    vector<int> intersection = findArrayIntersection(arr1, n1, arr2, n2);
    
    cout << "Intersection of arr1 and arr2: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2: Arrays with no common elements
    vector<int> arr3 = {1, 2, 3};
    vector<int> arr4 = {4, 5, 6};
    n1 = arr3.size();
    n2 = arr4.size();
    
    intersection = findArrayIntersection(arr3, n1, arr4, n2);
    
    cout << "Intersection of arr3 and arr4: ";
    if (intersection.empty()) {
        cout << "No common elements";
    } else {
        for (int num : intersection) {
            cout << num << " ";
        }
    }
    cout << endl;

    // Test Case 3: Arrays with some duplicate elements
    vector<int> arr5 = {1, 2, 2, 4, 5};
    vector<int> arr6 = {2, 2, 4, 6};
    n1 = arr5.size();
    n2 = arr6.size();
    
    intersection = findArrayIntersection(arr5, n1, arr6, n2);
    
    cout << "Intersection of arr5 and arr6: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                       Pair Sum
/*
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>> ans;
	for (int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
			if(arr[i]+arr[j]==s){
				vector<int> temp;
				temp.push_back(min(arr[i], arr[j]));
            	temp.push_back(max(arr[i], arr[j]));
				ans.push_back(temp);
			}
		}
	}
	sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    vector<int> arr = {1, 3, 2, 2, 4, 5, 6};
    int targetSum = 6;

    vector<vector<int>> result = pairSum(arr, targetSum);

    cout << "Pairs with sum " << targetSum << " are:\n";
    for (const auto& pair : result) {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}
*/

//                                         3Sum
/*
vector<vector<int>> threeSum(vector<int>& nums) {
    int target = 0;
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    vector<vector<int>> output;
    for (int i = 0; i < nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } 
            else if (sum < target) {
                j++;
            } 
            else {
                k--;
            }
        }
    }
    for(auto triplets : s){
        output.push_back(triplets);
    }
    return output;
}
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    cout << "Triplets that sum to zero are:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if (i != triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
*/

//                                      Sort 0s & 1s
/*
void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortOne(int arr[], int n) {

    int left = 0; 
    int right = n-1;

    while(left < right) {
        if(arr[left] == 0  )  {
            left++;
        }

        else if(arr[right]==1){
            right--;
        }
        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        else{
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}
int main() {

    int arr[8] = {1,1,1,1,1,0,0,0};

    sortOne(arr, 8);
    printArray(arr, 8);

    return 0;
}
*/

//                                 Sort 0s, 1s & 2s
/*
void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main(){
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
*/