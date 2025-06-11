#include<iostream>
#include<vector>
#include <climits>
using namespace std;

//                               Two Sum IV - Input is a BST
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
void inorder(TreeNode* root, vector<int>& inorderVal) {

    if(root == NULL) {
        return;
    }

    inorder(root->left, inorderVal);
    inorderVal.push_back(root->val);
    inorder(root->right, inorderVal);
}
bool findTarget(TreeNode* root, int k) {

    vector<int> inorderVal;
    inorder(root, inorderVal);
    int i = 0;
    int j = inorderVal.size()-1;
    while(i<j) {
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == k) {
            return true;
        }
        else if(sum > k) {
            j--;
        }
        else {
            i++;
        }
    }
    return false;
}
int main() {

    //       5
    //     /   \
    //    3     6
    //   / \     \
    //  2   4     7

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int target = 9;
    if (findTarget(root, target)) {
        cout << "Yes, there are two numbers in the BST that sum up to " << target << "." << endl;
    } 
    else {
        cout << "No, there are no two numbers in the BST that sum up to " << target << "." << endl;
    }

    return 0;
}
*/

//                             Flatten BST To A Sorted List
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
void inorder(TreeNode* root, vector<int>& inorderVal) {

    if(root == NULL) {
        return;
    }

    inorder(root->left, inorderVal);
    inorderVal.push_back(root->val);
    inorder(root->right, inorderVal);
}
TreeNode* flatten(TreeNode* root) {

    vector<int> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    TreeNode* newRoot = new TreeNode(inorderVal[0]);
    TreeNode* curr = newRoot;
    for(int i=1; i<n;i++) {
        TreeNode* temp = new TreeNode(inorderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}
void printFlattened(TreeNode* root) {

    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}
int main() {

    //       4
    //     /   \
    //    2     6
    //   / \     \
    //  1   3     7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    // Flatten the tree
    TreeNode* flattened = flatten(root);

    // Print the flattened tree
    printFlattened(flattened);

    return 0;
}
*/

//                              Balance a Binary Search Tree
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
void inorder(TreeNode* root, vector<int>& inorderVal) {

    if(root == NULL) {
        return;
    }

    inorder(root->left, inorderVal);
    inorderVal.push_back(root->val);
    inorder(root->right, inorderVal); 
}
TreeNode* inorderToBst(int s, int e, vector<int>& in) {
    
    // Base Case
    if(s>e) {
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(in[mid]);
    root->left = inorderToBst(s, mid-1, in);
    root->right = inorderToBst(mid+1, e, in);
    
    return root;
}
TreeNode* balanceBST(TreeNode* root) {

    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderToBst(0, inorderVal.size()-1, inorderVal);
}
void printInorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main() {
    
    //       4
    //     /   \
    //    2     6
    //   / \     \
    //  1   3     7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    cout << "Original BST (in-order): ";
    printInorder(root);
    cout << endl;

    // Balance the tree
    TreeNode* balancedRoot = balanceBST(root);

    cout << "Balanced BST (in-order): ";
    printInorder(balancedRoot);
    cout << endl;

    return 0;
}
*/

//               Construct Binary Search Tree from Preorder Traversal
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
TreeNode* solve(vector<int>& preorder, int maxi, int& i) {

    if(i == preorder.size() || preorder[i] > maxi){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = solve(preorder,root->val,i);
    root->right = solve(preorder,maxi,i);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {

    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder,maxi,i);
}
void printInorder(TreeNode* root) {

    if(root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}
int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    
    // Construct BST from preorder traversal
    TreeNode* root = bstFromPreorder(preorder);

    // Print in-order traversal of the constructed BST
    cout << "In-order traversal of the constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
*/