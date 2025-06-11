#include <iostream>
#include <vector>
#include <string>
using namespace std;

//                              Implement a phone directory
/*
class TrieNode {

    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char ch) {

            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }    
};
class Trie {

    public:
        TrieNode *root;

        Trie() {

            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root, string word) {
            
            // Base Case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // Assumption, word will be in small
            int index = word[0] - 'a';
            TrieNode* child;

            // Present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }    
            // Absent
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            
            // Recursion
            insertUtil(child, word.substr(1));
        }
        void insertWord(string word) {

            insertUtil(root, word);
        }
        void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {

            if(curr->isTerminal) {
                temp.push_back(prefix);
            }
            for(char ch = 'a'; ch <= 'z'; ch++) {
                TrieNode* next = curr->children[ch-'a'];
                if(next != NULL) {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string str) {

            TrieNode* prev = root;
            vector<vector<string>> output;
            string prefix = "";

            for(int i=0; i<str.length(); i++) {
                char lastch = str[i];
                prefix.push_back(lastch);
                
                // Check for lastch
                TrieNode* curr = prev->children[lastch - 'a'];
                // If not found
                if(curr == NULL) {
                    // Optional
                    // while (i < str.length()) {
                    // output.push_back({"0"});  
                    // i++;
                    // }
                    break;
                }
                // If found
                vector<string> temp;
                printSuggestions(curr, temp, prefix);
                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            return output;
        }
};
vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {

    // Creation of trie
    Trie* t = new Trie();

    // Insert all contacts in trie
    for(int i=0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }
    return t->getSuggestions(queryStr);
}
int main() {

    vector<string> contacts = {"cod", "coding", "codding", "code", "coly"};
    string query = "coding";

    // Result
    vector<vector<string>> result = phoneDirectory(contacts, query);
    for (const auto &suggestionList : result) {
        for (const auto &suggestion : suggestionList) {
            cout << suggestion << " ";
        }
        cout << endl;
    }
    return 0;
}
*/