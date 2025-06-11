#include <iostream>
#include <queue>
#include <map>
using namespace std;

//                      Amount of Time for Binary Tree to be Infected
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
TreeNode* createParentMapping(TreeNode* root, int target, map<TreeNode*, TreeNode*>& nodeToParent) {
    
    // To store the result
    TreeNode* res = NULL; 

    queue<TreeNode*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        if(front->val == target) {
            res = front;
        }
        if(front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(TreeNode* root, map<TreeNode*, TreeNode*>& nodeToParent) {

    map<TreeNode*, bool> visited;
    queue<TreeNode*> q;

    q.push(root);
    visited[root] = true;
    int ans = 0;

    while(!q.empty()) {
        bool flag = 0;
        int size = q.size();
        for(int i=0; i<size; i++) {
            // Process neighbours
            TreeNode* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]) {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right]) {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1) {
            ans++;
        }
    }
    return ans;
}
int amountOfTime(TreeNode* root, int start) {

    // Step 1: Create nodeToParent mapping
    // Step 2: Find target node
    // Step 3: Burn the tree in minimum time
        
    map<TreeNode*, TreeNode*> nodeToParent;
    TreeNode* targetNode = createParentMapping(root, start, nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
int main() {

    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    //       / \   \
    //      7   8   9
    //               \
    //                10
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(9);
    root->right->right->right->right = new TreeNode(10);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    // Starting the fire at node 8
    int start = 8; 
    cout << "Time to burn the tree: " << amountOfTime(root, start) << endl;

    return 0;
}
*/