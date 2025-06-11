#include <iostream>
#include <vector>
#include <string>
using namespace std;

//                                 Longest Common Prefix

//                                      Approach 1
/*
string longestCommonPrefix(vector<string>& strs) {

    string ans = "";

    // For traversing all characters of first string
    for(int i=0; i<strs[0].length(); i++) {
        char ch = strs[0][i];
        bool match = true;
        for(int j=1; j<strs.size(); j++) {
            if( strs[j].size() < i || ch != strs[j][i]) {
                match = false;
                break;
            }
        }
        if(match == false) {
            break;
        }
        else {
            ans.push_back(ch);
        }
    }
    return ans;
}
int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    // Result
    string result = longestCommonPrefix(strs);
    
    if (result.empty()) {
        cout << "No common prefix" << endl;
    } else {
        cout << "Longest common prefix: " << result << endl;
    }

    return 0;
}
*/
//                                      Approach 2
/*
class TrieNode {

    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childCount;

        TrieNode(char ch) {

            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            childCount = 0;
            isTerminal = false;
        }
};
class Trie {

    public:
        TrieNode* root;

        Trie(char ch) {

            root = new TrieNode(ch);
        }
        void insert(TrieNode* root, string word) {

            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode* child;

            // Present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            // Absent
            else {
                child = new TrieNode(word[0]);
                root->childCount++;
                root->children[index] = child;
            }

            // Recursion
            insert(child, word.substr(1));
        }
        void insertFast(string word) {

            insert(root, word);
        }
        void lcp(string word, string& ans) {

            for(int i=0; i<word.length(); i++) {
                char ch = word[i];
                if(root->childCount == 1) {
                    ans.push_back(ch);
                    int index = ch - 'a';
                    root = root->children[index];
                }
                // ChildCount > 1 
                else {
                    break;
                }
                if(root->isTerminal == true) {
                    break;
                }
            }
        }
};
string longestCommonPrefix(vector<string>& strs) {

    Trie* t = new Trie('\0');
    for(int i=0; i<strs.size(); i++) {
        if(strs[i] == "") {
            return "";
        }
        t->insertFast(strs[i]);
    }

    string word = strs[0];
    string ans = "";
    t->lcp(word, ans);
    return ans;
}
int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    // Result
    string result = longestCommonPrefix(strs);
    
    if (result.empty()) {
        cout << "No common prefix" << endl;
    } else {
        cout << "Longest common prefix: " << result << endl;
    }

    return 0;
}
*/