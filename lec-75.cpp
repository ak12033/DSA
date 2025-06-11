#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//                               Kth smallest element
/*
int kthSmallest(vector<int>& arr, int k) {

    priority_queue<int> pq;
        
    for(int i=0; i<k; i++) {
        pq.push(arr[i]);
    }
    for(int i=k; i<arr.size(); i++) {
        if(arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main() {

    vector<int> arr = {12, 3, 5, 7, 19, 8};
    int k = 4;

    // Result
    cout << "The " << k << "th smallest element is: " << kthSmallest(arr, k) << endl;

    return 0;
}
*/

//                                  Kth largest element
/*
int kthLargest(vector<int>& arr, int k) {

    priority_queue<int, vector<int>, greater<int> > minheap;
        
    for(int i=0; i<k; i++) {
        minheap.push(arr[i]);
    }
    for(int i=k; i<arr.size(); i++) {
        if(arr[i] > minheap.top()) {
            minheap.pop();
            minheap.push(arr[i]);
        }
    }
    return minheap.top();
}
int main() {

    vector<int> arr = {12, 3, 5, 7, 19, 8};
    int k = 4;

    // Result
    cout << "The " << k << "th largest element is: " << kthLargest(arr, k) << endl;

    return 0;
}
*/

//                                     Is tree a heap
/*
class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(NULL), right(NULL) {

        }
};
int countNodes(Node* root) {

    // Base Case
    if(root == NULL) {
        return 0;
    }
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}
bool isCBT(Node* root, int index, int cnt) {

    if(root == NULL) {
        return true;
    }
    if(index >= cnt) {
        return false;
    }
    else {
        bool left = isCBT(root->left, 2*index + 1, cnt);
        bool right = isCBT(root->right, 2*index + 2, cnt);
        return (left && right);
    }
}
bool isMaxOrder(Node* root) {
        
    // Leaf node
    if(root->left == NULL && root->right == NULL) {
        return true;
    }
    if(root->right == NULL) {
        return(root->data > root->left->data);
    }
    else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }
}
bool isHeap(Node* tree) {

    int index = 0;
    int totalCount = countNodes(tree);
    if(isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
        return true;
    }
    else {
        return false;
    }
}
int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);

    if(isHeap(root)) {
        cout << "The tree is a heap!" << endl;
    } else {
        cout << "The tree is NOT a heap!" << endl;
    }
    
    // Cleanup Memory
    delete root->left->left;  
    delete root->left->right;
    delete root->left;     
    delete root->right;   
    delete root;        

    return 0;
}
*/

//                               Merge Two Binary Max Heaps
/*
void heapify(vector<int>& arr, int n, int i) {

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }  
}
vector<int> mergeHeaps(vector<int>& a, vector<int>& b, int n, int m) {

    // Step 1: Merge both arrays into one
    vector<int> ans;
    for(auto i : a) {
        ans.push_back(i);
    }
    for(auto i : b) {
        ans.push_back(i);
    }
    // Step 2: Heap creation
    int size = ans.size();
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }
    return ans;
}
int main() {

    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> mergedHeap = mergeHeaps(a, b, a.size(), b.size());

    // Result
    cout << "Merged Heap: ";
    for (int num : mergedHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                               Minimum Cost of ropes
/*
int minCost(vector<int>& arr) {
        
    priority_queue <int, vector<int>, greater<int>> pq;

    for(int i=0; i<arr.size(); i++) {
        pq.push(arr[i]);
    }
        
    int cost = 0;
    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
            
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}
int main() {

    vector<int> arr = {4, 3, 2, 6};
    cout << "Minimum cost to combine all ropes: " << minCost(arr) << endl;

    return 0;
}
*/

//                                Convert BST to Min Heap
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {
            
        }
};
void inorder(TreeNode* root, vector<int>& ans) {

	// Base Case
	if(root == NULL) {
		return;
	}
	inorder(root->left, ans);
	ans.push_back(root->data);
	inorder(root->right, ans);
}
void preorderFill(TreeNode* root, int& index, vector<int>& ans) {
	
    // Base Case
    if(root == NULL) {
		return;
	}
	root->data = ans[index++];
	preorderFill(root->left, index, ans);
	preorderFill(root->right, index, ans);
}
TreeNode* convertBST(TreeNode* root) {

	vector<int> ans;
	inorder(root, ans);

	int index = 0;
	preorderFill(root, index, ans);

	return root;
}
void LevelOrderTraversal(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    cout << endl;
}
int main() {
  
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    TreeNode* ans = convertBST(root);
    LevelOrderTraversal(ans);

    return 0;
}
*/