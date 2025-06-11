#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_HEIGHT 100000

//                         Binary Tree Zigzag Level Order Traversal
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

    vector<vector<int>> result;
	if(root == NULL) {
    	return result;
    }
    queue<TreeNode*> q;
    q.push(root);
    	
    bool leftToRight = true;
	while(!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
    	    
        // Level Process
        for(int i=0; i<size; i++) {        
            TreeNode* frontNode = q.front();
            q.pop();
                    
            // Normal insert or Reverse insert 
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> val;
                    
            if(frontNode->left) {
                q.push(frontNode -> left);
            }
            if(frontNode->right) {
                q.push(frontNode -> right);
            }
        }
    	// Direction change karni h
    	leftToRight = !leftToRight;
        result.push_back(ans);  
	}
    return result;
}
void printZigzagOrder(const vector<vector<int>>& result) {

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {

    // Example : 
    //        3
    //       / \
    //      9  20
    //         /  \
    //        15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagLevelOrder(root);
    
    // Result
    printZigzagOrder(result);
    
    // Clean up dynamically allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
*/

//                                  Boundary traversal
/*
class Node {

    public: 
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
void traverseLeft(Node* root, vector<int> &ans) {
    
    // Base Case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ) {
        return ;
    }
            
    ans.push_back(root->data);
    if(root->left) {
        traverseLeft(root->left, ans);
    }
    else {
        traverseLeft(root->right, ans);
    }  
}    
void traverseLeaf(Node* root, vector<int> &ans) {
        
    // Base Case
    if(root == NULL) {
        return ;
    }
            
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
        
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);        
}
void traverseRight(Node* root, vector<int> &ans) {

    // Base Case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) ) {
            return ;
    }

    if(root->right) {
        traverseRight(root->right, ans);
    }
    else {
        traverseRight(root->left, ans);
    }    
    // Wapas Aagye
    ans.push_back(root->data);            
}    
vector <int> boundary(Node *root) {

    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    ans.push_back(root->data);
        
    // Left part print/store
    traverseLeft(root->left, ans);
        
    // Traverse Leaf Nodes
    // Left Subtree
    traverseLeaf(root->left, ans);
    // Right Subtree
    traverseLeaf(root->right, ans);
        
    // Traverse right part
    traverseRight(root->right, ans);
        
    return ans;      
}
void printBoundaryTraversal(vector<int>& boundary) {

    for (int node : boundary) {
        cout << node << " ";
    }
    cout << endl;
}
int main() {

    // Example :
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //         \   \
    //          7   8

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->right = new Node(7);
    root->right->right->right = new Node(8);
    
    vector<int> boundaryTraversal = boundary(root);
    
    // Result
    printBoundaryTraversal(boundaryTraversal);
    
    return 0;
}
*/

//                        Vertical Order Traversal of a Binary Tree
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
vector<vector<int>> verticalTraversal(TreeNode* root) {

    vector<vector<int>> ans;
    // Map of horizontal distance - levelwise nodes
    map<int, map<int, vector<int> > > nodes;
    // Queue of nodes with hd and level
    queue< pair<TreeNode*, pair<int, int> > > q;
        
    if(root == NULL) {
        return ans;
    }
    q.push(make_pair(root, make_pair(0,0)));
        
    while(!q.empty()) {
        pair<TreeNode*, pair<int,int> > temp = q.front();
        q.pop();
        TreeNode* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->val);
            
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
    }
    for(auto i : nodes) {
        vector<int> v;
        for(auto j : i.second) {
            sort(j.second.begin(), j.second.end());
            for(auto k : j.second) {
                v.push_back(k);
            }
        }
        ans.push_back(v);
    }
    return ans;
}
void printVerticalTraversal(const vector<vector<int>>& ans) {

    for(const auto& col : ans) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main() {

    // Example :
    //         3
    //        / \
    //       9   20
    //          /  \
    //         15   7

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<vector<int>> result = verticalTraversal(root);
    
    // Result
    printVerticalTraversal(result);
    
    return 0;
}
*/

//                                     Top view
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
vector<int> topView(Node *root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }
    
    // Map of hd - node value
    map<int,int> topNode;
    // Queue of node - hd
    queue<pair<Node*, int> > q;
        
    q.push(make_pair(root, 0));
        
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
            
        // If one value is present for a HD, then do nothing
        if(topNode.find(hd) == topNode.end()) {
            topNode[hd] = frontNode -> data;
        }
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
        
    for(auto i : topNode) {
        ans.push_back(i.second);
    }
    return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Get the top view of the tree
    vector<int> result = topView(root);

    // Print the result
    cout << "Top view of the tree: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                    Bottom view
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
vector <int> bottomView(Node *root) {

    vector<int> ans;

    if(root == NULL) {
        return ans;
    }
        
    map<int,int> topNode;
    queue<pair<Node*, int> > q;
        
    q.push(make_pair(root, 0));
        
    while(!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
            
        topNode[hd] = frontNode -> data;
                
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
        
    for(auto i : topNode) {
        ans.push_back(i.second);
    }
    return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Get the bottom view of the tree
    vector<int> result = bottomView(root);

    // Print the result
    cout << "Top view of the tree: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                       Left view
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
void solve(Node* root, vector<int> &ans, int level) {
    
    // Base Case
    if(root == NULL)
        return ;
       
    // We entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
vector<int> leftView(Node* root) {

   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get the left view of the tree
    vector<int> result = leftView(root);

    // Result
    cout << "Left view of the tree: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                       Right view
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
void solve(Node* root, vector<int> &ans, int level) {
    
    // Base Case
    if(root == NULL)
        return ;
       
    // We entered into a new level    
    if(level == ans.size())
        ans.push_back(root->data);
        
    solve(root->right, ans, level+1);
    solve(root->left, ans, level+1);
}
vector<int> rightView(Node* root) {

   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Get the right view of the tree
    vector<int> result = rightView(root);

    // Result
    cout << "Right view of the tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                   Diagonal Traversal
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int x) : data(x), left(nullptr), right(nullptr) {

        }
};
vector<int> diagonal(Node* root) {
    
    vector<int> diagonal;

    if(root == NULL) {
        return diagonal;
    }
   
    queue<Node*> q;
    q.push(root);
   
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        while(temp != NULL) {
            diagonal.push_back(temp->data);
            if(temp->left) {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return diagonal;
}
void printList(vector<int> v) {

    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {

    // Create a hard coded tree
    //         8
    //       /   \
    //      3     10
    //     /     /  \
    //    1     6    14
    //         / \   /
    //        4   7 13

    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);

    // Result
    vector<int> ans = diagonal(root);
    printList(ans);
}
*/