#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

//                 Construct Binary Tree from Preorder and Inorder Traversal

//                                       Approach 1
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
int Findposition(vector<int> inorder, int inorderStart, int inorderEnd, int element, int n){

    for(int i = inorderStart; i <= inorderEnd; i++) {
        if(inorder[i] == element) {
            return i; 
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &index, int inorderStart, int inorderEnd, int n) {

    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }
    // At every iteration index is increasing       
    int element = preorder[index++]; 
    TreeNode* root = new TreeNode(element); 
    int position = Findposition(inorder, inorderStart, inorderEnd, element, n);
            
    root->left = solve(inorder, preorder, index, inorderStart, position-1, n);
    root->right = solve(inorder, preorder, index, position+1, inorderEnd, n);
            
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    // Pre order is NLR so first element is root.
    int preorderindex = 0;  
    int n = inorder.size();
    
    TreeNode* ans = solve(inorder, preorder, preorderindex, 0, n-1, n);
    return ans;
}
void postorder(TreeNode* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> val << " ";
}
int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    // Construct the binary tree
    TreeNode* root = buildTree(preorder, inorder);

    // Result
    cout << "Post-order traversal of the constructed tree: ";
    postorder(root);

    return 0;
}
*/
//                                      Approach 2
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
int findPosition(vector<int>& inorder, int n, int element) {

    for(int i=0; i<n; i++) {
        if(inorder[i] == element) { 
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int n, int& preIndex, int startIn, int endIn) {

    if(preIndex>=n || startIn>endIn) {
        return NULL;
    }

    int element = preorder[preIndex++];
    TreeNode *root = new TreeNode(element);
    int pos = findPosition(inorder, n, element);

    root->left = solve(preorder, inorder, n, preIndex, startIn, pos-1);
    root->right = solve(preorder, inorder, n, preIndex, pos+1, endIn);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    int n = preorder.size();
    int preIndex = 0;
    int startIn = 0;
    int endIn = n-1;

    return solve(preorder, inorder, n, preIndex, startIn, endIn);
}
void postorder(TreeNode* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> val << " ";
}
int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    // Construct the binary tree
    TreeNode* root = buildTree(preorder, inorder);

    // Result
    cout << "Post-order traversal of the constructed tree: ";
    postorder(root);

    return 0;
}
*/
//                                       Approach 3
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int n, int& preIndex, int startIn, int endIn, unordered_map<int,int>& mp) {

    if(preIndex >= n || startIn > endIn) {
        return NULL;
    }

    int element = preorder[preIndex++];
    TreeNode*root = new TreeNode(element);
    int pos = mp[element];

    root->left = solve(preorder, inorder, n, preIndex, startIn, pos-1,mp);
    root->right = solve(preorder, inorder, n, preIndex, pos+1, endIn,mp);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    int n = preorder.size();
    int preIndex = 0; 
    int startIn = 0; 
    int endIn = n-1;

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[inorder[i]] = i;
    }
    return solve(preorder, inorder, n, preIndex, startIn, endIn, mp);
}
void postorder(TreeNode* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> val << " ";
}
int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    // Construct the binary tree
    TreeNode* root = buildTree(preorder, inorder);

    // Result
    cout << "Post-order traversal of the constructed tree: ";
    postorder(root);

    return 0;
}
*/

//              Construct Binary Tree from Inorder and Postorder Traversal

//                                     Approach 1
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
int findPosition(vector<int>& inorder, int n, int element) {

    for(int i=0; i<n; i++) {
        if(inorder[i] == element) {
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int n, int& postIndex, int startIn, int endIn) {

    if(postIndex < 0 || startIn > endIn) {
        return NULL;
    }

    int element = postorder[postIndex--];
    TreeNode *root = new TreeNode(element);
    int pos = findPosition(inorder, n, element);

    root->right = solve(postorder, inorder, n, postIndex, pos+1, endIn);
    root->left = solve(postorder, inorder, n, postIndex, startIn, pos-1);
    
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    int n = postorder.size();
    int postIndex = n-1;
    int startIn = 0;
    int endIn = n-1;

    return solve(postorder, inorder, n, postIndex, startIn, endIn);
}
void preorder(TreeNode* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    cout << root-> val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    // Construct the binary tree
    TreeNode* root = buildTree(inorder, postorder);

    // Result
    cout << "Pre-order traversal of the constructed tree: ";
    preorder(root);

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
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int n, int& postIndex, int startIn, int endIn, unordered_map<int, int>& mp) {

    if(postIndex < 0 || startIn > endIn) {
        return NULL;
    }

    int element = postorder[postIndex--];
    TreeNode* root = new TreeNode(element);
    int pos = mp[element];

    root->right = solve(postorder, inorder, n, postIndex, pos+1, endIn, mp);
    root->left = solve(postorder, inorder, n, postIndex, startIn, pos-1, mp);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

    int n = postorder.size();
    int postIndex = n-1;
    int startIn = 0;
    int endIn = n-1;

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[inorder[i]] = i;
    }
    return solve(postorder, inorder, n, postIndex, startIn, endIn, mp);
}
void preorder(TreeNode* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    cout << root-> val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    // Construct the binary tree
    TreeNode* root = buildTree(inorder, postorder);

    // Result
    cout << "Pre-order traversal of the constructed tree: ";
    preorder(root);

    return 0;
}
*/