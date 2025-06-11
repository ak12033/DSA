#include<iostream>
#include<queue>
#include <climits>
using namespace std;

/*
class TreeNode {

    public:    
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
bool isBST(TreeNode* root, long min, long max) {

    // Base Case
    if(root == NULL) {
        return true;
    }
    if(root->val > min && root->val < max) {
        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);
        return left && right;
    }
    else {
        return false;
    }
}
bool isValidBST(TreeNode* root) {

    return isBST(root, LONG_MIN, LONG_MAX);
}
int main() {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(20);
    
    // Check if the tree is a valid BST
    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } 
    else {
        cout << "The tree is NOT a valid BST." << endl;
    }
    return 0;
}
*/

//                             Kth Smallest Element in a BST

//                                        Approach 1
/*
class TreeNode {

    public:    
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {

            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void solve(TreeNode* root, int k, int& ans, int& i) {

    if(root == NULL || ans != -1) {
        return;
    }
    // Left
    solve(root->left, k, ans, i);

    i++;
    if(i == k) {
        ans = root->val;
    }
    // Right
    solve(root->right, k, ans, i);
}
int kthSmallest(TreeNode* root, int k) {
        
    int i = 0;
    int ans = -1;

    solve(root, k, ans, i);
    return ans;
}
int main() {

    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    int k = 3;
    int result = kthSmallest(root, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/
//                                        Approach 2
/*
class TreeNode {

    public:    
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {

            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void solve(TreeNode* root, vector<int>& ans){

    if(root == NULL) {
        return ;
    }

    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}
int kthSmallest(TreeNode* root, int k) {

    vector<int> ans;
    solve(root, ans);

    if(ans.size() >= k) {
        return ans[k-1];
    }
    return -1;
}
int main() {

    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    int k = 3;
    int result = kthSmallest(root, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/

//                             Kth Largest Element in a BST
/*
class TreeNode {

    public:    
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {

            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void solve(TreeNode* root, int k, int& ans, int& i) {

    if(root == NULL || ans != -1) {
        return;
    }
    // Left
    solve(root->right, k, ans, i);

    i++;
    if(i == k) {
        ans = root->val;
    }
    // Right
    solve(root->left, k, ans, i);
}
int kthLargest(TreeNode* root, int k) {
        
    int i = 0;
    int ans = -1;

    solve(root, k, ans, i);
    return ans;
}
int main() {

    //      5
    //     / \
    //    3   6
    //   / \   \
    //  2   4   7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 3;
    int result = kthLargest(root, k);
    cout << "The " << k << "-th largest element is: " << result << endl;

    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/

//                     Predecessor and Successor element in a BST
/*
class TreeNode {

    public:   
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {

    int predecessor = -1;
    int successor = -1;

    // Initializing temporary node with head.
    TreeNode *temp = root;

    // Traversing in tree.
    while (temp != NULL) {
        if (key > temp->data) {
            // Updating predecessor.
            predecessor = temp->data;
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    temp = root;
    while (temp != NULL) {
        if (key < temp->data) {
            // Updating successor.
            successor = temp->data;
            temp = temp->left;
            
        }
        else {
            temp = temp->right;
        }
    }
    return {predecessor, successor};
}
int main() {
    
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Let's find predecessor and successor of key 15
    int key = 15;
    pair<int, int> result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    // Find predecessor and successor of another key, e.g., 30
    key = 30;
    result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    // Test case when key doesn't exist in the tree
    key = 100;
    result = predecessorSuccessor(root, key);
    cout << "Predecessor: " << result.first << ", Successor: " << result.second << endl;

    return 0;
}
*/

//                    Lowest Common Ancestor of a Binary Search Tree

//                                     Approach 1
/*
class TreeNode {

    public:   
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    // Base Case
    if(root == NULL) {
        return NULL;
    }
    if(root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}
int main() {

    //         20
    //        /  \
    //      10    30
    //     /  \   /  \
    //    5   15 25   35

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Nodes to find the lowest common ancestor for
    TreeNode* p = root->left->left;  // Node 5
    TreeNode* q = root->left->right; // Node 15

    // Find the LCA
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    
    // Output the result
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    // Memory cleanup
    delete root->left->left;    // delete node 5
    delete root->left->right;   // delete node 15
    delete root->right->left;   // delete node 25
    delete root->right->right;  // delete node 35
    delete root->left;          // delete node 10
    delete root->right;         // delete node 30
    delete root;                // delete node 20

    return 0;
}
*/
//                                     Approach 2
/*
class TreeNode {

    public:   
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            this->val = d;
            this->left = NULL;
            this->right = NULL;
        }
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    while(root != NULL) {
        if(root->val < p->val && root->val < q->val) {
            root = root->right;
        }
        else if (root->val > p->val && root->val > q->val) {
            root = root->left;
        }
        else {
            return root;
        } 
    }
    return NULL;
}
int main() {

    //         20
    //        /  \
    //      10    30
    //     /  \   /  \
    //    5   15 25   35

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    // Nodes to find the lowest common ancestor for
    TreeNode* p = root->left->left;  // Node 5
    TreeNode* q = root->left->right; // Node 15

    // Find the LCA
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    
    // Output the result
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    // Memory cleanup
    delete root->left->left;    // delete node 5
    delete root->left->right;   // delete node 15
    delete root->right->left;   // delete node 25
    delete root->right->right;  // delete node 35
    delete root->left;          // delete node 10
    delete root->right;         // delete node 30
    delete root;                // delete node 20

    return 0;
}
*/