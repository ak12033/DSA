#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//                  Sum of nodes on the longest path from root to leaf node

//                                        Approach 1
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){

    // Base Case
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;

    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);        
}
int sumOfLongRootToLeafPath(Node *root) {

    int len = 0;
    int maxLen = 0;
        
    int sum = 0;
    int maxSum = INT_MIN;
        
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
int main() {

    // Create tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Get the sum of the longest root-to-leaf path
    int result = sumOfLongRootToLeafPath(root);

    // Result
    cout << "Sum of the longest root-to-leaf path: " << result << endl;

    return 0;
}
*/
//                                        Approach 2
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};
pair<int,int> sum(Node *root){

    // Base Case
    if(root == NULL) {
        return {0,0};
    }
    pair<int,int> p1=sum(root->left);
    pair<int,int> p2=sum(root->right);
        
    if(p1.second > p2.second) {
        return {p1.first + root->data, p1.second+1};
    }
    else if(p2.second>p1.second) {
        return {p2.first + root->data, p2.second+1};
    }
    else {
        return {max(p1.first, p2.first) + root->data, p1.second+1};
    }
}
int sumOfLongRootToLeafPath(Node *root){

    pair<int,int> p = sum(root);
    return p.first;
}
int main() {

    // Create tree nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Get the sum of the longest root-to-leaf path
    int result = sumOfLongRootToLeafPath(root);

    // Result
    cout << "Sum of the longest root-to-leaf path: " << result << endl;

    return 0;
}
*/

//                        Lowest Common Ancestor of a Binary Tree
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {
            
        }
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    // Base Case
    if(root == NULL) {
        return NULL;
    }
        
    if(root->val == p->val || root->val == q->val) {
        return root;
    }
        
    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        
    if(leftAns != NULL && rightAns != NULL) {
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }
    else {
        return NULL;
    }
}
int main() {

    //                  3
    //                /   \
    //               5     1
    //              / \   / \
    //             6   2 0   8
    //                / \
    //               7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    
    // Defining the nodes p and q
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1
    
    // Find LCA of p and q
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    
    // Result
    if(lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } 
    else {
        cout << "No common ancestor found." << endl;
    }
    return 0;
}
*/

//                                   Path Sum III
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {
            
        }
};
void solve(TreeNode* root, int k, int &count, vector<int> &path) {

    // Base Case
    if(root == NULL) {
        return ;
    }
    
    path.push_back(root->val);
        
    // Left
    solve(root->left, k, count, path);
    // Right
    solve(root->right, k, count, path);
        
    // Check for K Sum    
    int size = path.size();
    long int sum = 0;
    for(int i = size-1; i>=0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    } 
    path.pop_back();
}
int pathSum(TreeNode* root, int targetSum) {

    vector<int> path;
    int count = 0;
    solve(root, targetSum, count, path);
    return count;
}
int main() {

    //         10
    //        /  \
    //       5    -3
    //      / \     \
    //     3   2     11
    //    / \   \
    //   3  -2   1

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    int targetSum = 8;
    int result = pathSum(root, targetSum);

    cout << "Number of paths with sum " << targetSum << ": " << result << endl;

    return 0;
}
*/

//                         K-th ancestor of a node in Binary Tree

//                                       Approach 1
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(NULL), right(NULL) {
            
        }
};
Node* solve(Node* root, int &k, int node) {

    // Base Case
    if(root == NULL) {
        return NULL;
    }
        
    if(root->data == node) {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    // Wapas
    if(leftAns != NULL && rightAns == NULL) {
        k--;
        if(k<=0) {
            // Answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k <= 0) {
            // Answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node* root, int k, int node) {

    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node) {
        return -1;
    }
    else {
        return ans->data;
    }
}
int main() {
    
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 5;

    int ancestor = kthAncestor(root, k, node);
    if (ancestor != -1) {
        cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << endl;
    } 
    else {
        cout << "No " << k << "th ancestor found for node " << node << endl;
    }

    return 0;
}
*/
//                                      Approach 2
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(NULL), right(NULL) {
            
        }
};
int solve(Node* root, int k, int node, vector<int>& path) {
        
    // Base Case
    if(root == NULL) {
        return 0;
    }

    path.push_back(root->data);
        
    // Left
    solve(root->left, k, node, path);
    // Right
    solve(root->right, k, node, path);
        
    // Check for K Sum        
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--) {
        if(path[i] == node) {
            int index = i-k;
            if(index < 0) {
                return -1;
            }
            else {
                return path[i-k];
            }
        }
    }    
    path.pop_back();
}
int kthAncestor(Node *root, int k, int node) {

    vector<int> path;
    return solve(root,k,node,path);
}
int main() {
    
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 5;

    int ancestor = kthAncestor(root, k, node);
    if (ancestor != -1) {
        cout << "The " << k << "th ancestor of node " << node << " is: " << ancestor << endl;
    } 
    else {
        cout << "No " << k << "th ancestor found for node " << node << endl;
    }

    return 0;
}
*/

//                              Maximum sum of Non-adjacent nodes
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(NULL), right(NULL) {
            
        }
};
pair<int,int> solve(Node* root) {

    // Base Case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
        
    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);
        
    pair<int,int> res;    
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
        
}
int getMaxSum(Node *root) {

    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main() {

    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int result = getMaxSum(root);
    cout << "Maximum path sum: " << result << endl;

    return 0;
}
*/