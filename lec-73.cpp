#include <iostream>
#include <climits>
using namespace std;

//                            Size of Largest BST in Binary Tree
/*
class TreeNode {

    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        
        TreeNode(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
class info{

    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
info solve(TreeNode* root, int& ans) {
    
    // Base Case
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }
    // Answer Update
    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    return currNode;

}
int largestBST(TreeNode* root) {

    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}
int main() {

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Result
    cout << "Size of the largest BST: " << largestBST(root) << endl;
}
*/