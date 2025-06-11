#include <iostream>
#include <vector>
using namespace std;

//                                         Subsets
/*
void solve(vector<int> nums, vector<int> output, int index,vector<vector<int> >& ans) {

    // Base Case
    if(index >= nums.size()) {
        ans.push_back(output);
        return ;
    }   
    // Exclude
    solve(nums, output, index+1, ans);

    // Include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);    
}
vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;

    solve(nums, output, index, ans);

    return ans;
}
int main() {

    vector<int> nums = {1, 2, 3};
    
    // Get all subsets
    vector<vector<int>> result = subsets(nums);
    
    // Print all subsets
    cout << "Subsets: " << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
*/

//                           Subsequences of String
/*
void solve(string str, string output, int index, vector<string>& ans) {

	if (index >= str.length()) {
		if (output.length() > 0) {
			ans.push_back(output);
		}
		return;
	}
	// Exclude
	solve(str, output, index+1, ans);

	// Include
	output.push_back(str[index]);
	solve(str, output, index+1, ans);
}
vector<string> subsequences(string str){

	int index = 0;
	string output = "";
	vector<string> ans;

	solve(str, output, index, ans);

	return ans;
}
int main() {
    string str = "abc";
    
    // Get all subsequences
    vector<string> result = subsequences(str);
    
    // Print all subsequences
    cout << "Subsequences: " << endl;
    for (const auto& subseq : result) {
        cout << subseq << endl;
    }
    return 0;
}
*/