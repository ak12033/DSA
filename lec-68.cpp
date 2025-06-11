#include <iostream>
#include <vector>
using namespace std;

//                                   Morris Traversal
//                                      (Inorder)
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
vector<int> getInorder(TreeNode* root) {

    vector<int> inorder;
        
    TreeNode* cur = root;
    while(cur) {
        if(!cur->left) {
            inorder.push_back(cur->val);
            cur = cur->right;
        } 
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if(!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } 
            else {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> inorder = getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for(int i = 0; i < inorder.size(); i++){
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                   Morris Traversal
//                                      (Preorder)
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
vector<int> getPreorder(TreeNode* root) {

    vector<int> Preorder;
        
    TreeNode* cur = root;
    while(cur) {
        if(!cur->left) {
            Preorder.push_back(cur->val);
            cur = cur->right;
        } 
        else {
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if(!prev->right) {
                prev->right = cur;
                Preorder.push_back(cur->val);
                cur = cur->left;
            } 
            else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return Preorder;
}
int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> preorder = getPreorder(root);

    cout << "Binary Tree Morris Preorder Traversal: ";
    for(int i = 0; i < preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                          Flatten Binary Tree to Linked List
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
void flatten(TreeNode* root) {

    TreeNode* curr = root;
    while(curr) {
        if(curr->left) {
            TreeNode* pred = curr->left;
            while(pred->right) {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
void inorder(TreeNode* root) {
    
    // Base Case
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main() {

    //       1
    //     /   \
    //    2     5
    //   / \     \
    //  3   4     6 

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);
    cout << "The Inorder traversal after flattening binary tree ";
    inorder(root);

    return 0;
}
*/