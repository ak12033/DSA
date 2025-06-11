#include <iostream>
#include <vector>
using namespace std;

//                      Letter Combinations of a Phone Number
/*
void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
    // Base Case
    if(index >= digit.length()) {
        ans.push_back(output);
        return;
    }  
    int number = digit[index] - '0';
    string value = mapping[number];
        
    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index+1, ans, mapping);
        output.pop_back();
    }        
}
vector<string> letterCombinations(string digits) {

    vector<string> ans;

    if(digits.length()==0){
        return ans;
    }
    string output;
    int index = 0;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};

    solve(digits, output, index, ans, mapping);

    return ans;
}
int main() {

    string digits = "23";
    
    vector<string> result = letterCombinations(digits);

    // Print the result
    cout << "Letter Combinations: " << endl;
    for (const auto& combination : result) {
        cout << combination << endl;
    }
    return 0;
}
*/