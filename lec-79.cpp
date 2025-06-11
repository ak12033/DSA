#include<iostream>
using namespace std;

//                                      Trie
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
        TrieNode* root;

        Trie() {

            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root, string word) {
            
            // Base Case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }

            // Assumption, word will be in CAPS
            int index = word[0] - 'A';
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
        bool searchUtil(TrieNode* root, string word) {

            // Base Case    
            if(word.length() == 0) {
                return root->isTerminal;
            }
            
            int index = word[0] - 'A';
            TrieNode *child;

            // Present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            // Absent
            else {
                return false;
            }

            // Recursion    
            return searchUtil(child, word.substr(1));
        }
        bool searchWord(string word) {

            return searchUtil(root, word);
        }
        void removeUtil(TrieNode* root, string word) {

            // Base Case
            if(word.length() == 0) {
                root->isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // Present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            // Absent
            else {
                return;
            }

            // Recursion
            removeUtil(child, word.substr(1));
        }
        void removeWord(string word) {

            removeUtil(root, word);
        }
        bool prefixUtil(TrieNode* root, string word){

            // Base Case
            if(word.length() == 0) {
                return true;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            // Present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            // Absent
            else {
                return false;
            }

            // Recursion
            return prefixUtil(child, word.substr(1));
        }
        bool prefixWith(string prefix) {

            return prefixUtil(root, prefix);
        }
};
int main() {

    Trie* t = new Trie();

    // Insertion
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIMER");

    // Searching
    cout << "Searching for ARM: " << (t->searchWord("ARM") ? "Found" : "Not Found") << endl;
    cout << "Searching for ARMY: " << (t->searchWord("ARMY") ? "Found" : "Not Found") << endl;

    // Deletion
    t->removeWord("ARM");
    cout << "Searching for ARM after removal: " << (t->searchWord("ARM") ? "Found" : "Not Found") << endl;

    // Search for prefixes
    cout << "Checking prefix TI: " << (t->prefixWith("TI") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix TIM: " << (t->prefixWith("TIM") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix TIME: " << (t->prefixWith("TIME") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix TIMER: " << (t->prefixWith("TIMER") ? "Exists" : "Does not exist") << endl;
    cout << "Checking prefix TIMERS: " << (t->prefixWith("TIMERS") ? "Exists" : "Does not exist") << endl;

    delete t;

    return 0;
}
*/

