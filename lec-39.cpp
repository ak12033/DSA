#include <iostream>
#include <vector>
using namespace std;

//                                  Permutations
/*
void solve(vector<int> nums, vector<vector<int>>& ans, int index){

    // Base Case
    if(index>=nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i<nums.size(); i++){
        swap(nums[index],nums[i]);
        solve(nums,ans,index+1);
        // Backtrack
        swap(nums[index],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> ans;
        
    int index=0;
        
    solve(nums,ans,index);

    return ans;
}
int main() {

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations = permute(nums);

    // Print the permutations
    cout << "Permutations: " << endl;
    for (auto& perm : permutations) {
        cout << "[";
        for (int i=0; i<perm.size();i++) {
            cout << perm[i];
            if(i<perm.size()-1){
                cout<<",";
            }
        }
        cout << "]" << endl;
    }
    return 0;
}
*/