#include <iostream>
#include <utility> // for std::pair
using namespace std;

//                              Height of a Binary Tree
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }
};
int maxDepth(TreeNode* root) {

    // Base Case
    if(root == NULL) {
        return 0;
    }
    int left = maxDepth(root ->left);
    int right = maxDepth(root->right);
        
    int ans = max(left, right) + 1;
    return ans;
}
int main() {

    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // Result
    int depth = maxDepth(root);
    cout << "Max depth of the tree: " << depth << endl;
    
    return 0;
}
*/

//                             Diameter of a Binary Tree
//                                    Approach 1
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        
        }
};
int maxDepth(TreeNode* root) {

    // Base Case
    if(root == NULL) {
        return 0;
    }
    int left = maxDepth(root ->left);
    int right = maxDepth(root->right);
        
    int ans = max(left, right) + 1;
    return ans;
}
int diameter(TreeNode* root) {

    // Base Case
    if(root == NULL) {
        return 0;
    }
    int op1 = diameter(root ->left);
    int op2 = diameter(root->right);
    int op3 = maxDepth(root ->left) + maxDepth(root->right) + 1;

    int ans = max(op1, max(op2, op3));
    return ans;
}
int main() {

    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Result
    int treeDiameter = diameter(root);
    cout << "Diameter of the tree: " << treeDiameter << endl;
    
    return 0;
}
*/
//                                    Approach 2
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }
};
pair<int,int> diameterFast(TreeNode* root) {

    // Base Case
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
        
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
        
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
        
    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int diameter(TreeNode* root) {

    return diameterFast(root).first;
}
int main() {

    // Creating a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Result
    int treeDiameter = diameter(root);
    cout << "Diameter of the tree: " << treeDiameter << endl;
    
    return 0;
}
*/

//                              Balanced Binary Tree

//                                   Approach 1
/*
class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }
};
int height(TreeNode* node){

    // Base Case
    if(node == NULL) {
        return 0;
    }
        
    int left = height(node ->left);
    int right = height(node->right);
        
    int ans = max(left, right) + 1;
    return ans;        
}
bool isBalanced(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return true;
    }
        
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root -> left) - height(root -> right)) <=1;
        
    if(left && right && diff) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {

    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Result
    bool balanced = isBalanced(root);
    cout << "The tree is " << (balanced ? "balanced" : "not balanced") << endl;
    
    return 0;
}
*/
//                                   Approach 2
/*
class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }
};
pair<bool, int> isBalancedFast(TreeNode* root) {

    // Base Case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
        
    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);
        
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs (left.second - right.second ) <=1;
        
    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftAns && rightAns && diff) {
       ans.first = true;
    }
    else {
        ans.first = false;
    }
    return ans;
}
bool isBalanced(TreeNode* root) {

    return isBalancedFast(root).first;
}
int main() {

    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Result
    bool balanced = isBalanced(root);
    cout << "The tree is " << (balanced ? "balanced" : "not balanced") << endl;
    
    return 0;
}
*/

//                                     Same Tree
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
        }
};
bool isSameTree(TreeNode* p, TreeNode* q) {

    // Base Case
    if(p == NULL && q == NULL) {
        return true;
    }
        
    if(p == NULL && q != NULL) {
        return false;
    }
        
    if(p != NULL && q == NULL) {
        return false;
    }
        
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);    
    bool value = p->val == q->val;
        
    if(left && right && value) {
        return true;
    }
    else{
        return false;
    }    
}
int main() {

    // Create the first binary tree
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Create the second binary tree
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    // Compare the trees
    if (isSameTree(tree1, tree2)) {
        cout << "The trees are the same." << endl;
    } 
    else {
        cout << "The trees are different." << endl;
    }

    // Create a third tree that is different
    TreeNode* tree3 = new TreeNode(1);
    tree3->left = new TreeNode(2);
    tree3->right = new TreeNode(4);  // Different value here

    // Compare tree1 with tree3
    if (isSameTree(tree1, tree3)) {
        cout << "The trees are the same." << endl;
    } 
    else {
        cout << "The trees are different." << endl;
    }

    // Clean up dynamically allocated memory (optional but good practice)
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->left;
    delete tree3->right;
    delete tree3;

    return 0;
}
*/

//                                 Sum tree or not
/*
class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int value) : data(value), left(nullptr), right(nullptr) {

        }
};
pair<bool,int> isSumTreeFast(Node* root) {
        
    // Base Case
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
        
    if(root->left == NULL && root->right == NULL ) {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
        
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
        
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;    
    bool condn = root->data == leftAns.second + rightAns.second;
        
    pair<bool, int> ans;    
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = 2 * root->data ;
        // Or
        // ans.second = root->data + leftAns.second + rightAns.second ;
    }
    else {
        ans.first = false;
    }
    return ans;        
}
bool isSumTree(Node* root) {
         
    return isSumTreeFast(root).first;
}
int main() {

    // Constructing the tree
    Node* root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    
    if (isSumTree(root)) {
        cout << "The tree is a Sum Tree.\n";
    } 
    else {
        cout << "The tree is not a Sum Tree.\n";
    }

    return 0;
}
*/