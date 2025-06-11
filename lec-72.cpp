#include <iostream>
#include <vector>
using namespace std;

//                                      Merge Two BSTs

//                                        Approach 1
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : data(x), left(NULL), right(NULL) {

        }
};
void convertIntoSortedDLL(TreeNode* root,TreeNode*& head) {

    // Base Case
    if(root == NULL) {
        return;
    }

    // Right
    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if( head != NULL) {
        head->left = root;
    }
    head = root;
    
    // Left
    convertIntoSortedDLL(root->left, head);
}
TreeNode* mergeLinkedList(TreeNode* head1, TreeNode* head2) {

    TreeNode* head = NULL;
    TreeNode* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else {
            if(head == NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int countNodes(TreeNode*& head) {

    int cnt = 0;
    TreeNode* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
TreeNode* sortedLLToBST(TreeNode*& head, int n) {

    // Base Case
    if(n <= 0 || head == NULL) {
        return NULL;
    }
    // Left
    TreeNode* left = sortedLLToBST(head, n/2);

    TreeNode* root = head;
    root->left = left;
    head = head->right;

    // Right
    root->right = sortedLLToBST(head, n-n/2-1);
    return root;
}
TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {

    // Step1: Convert BST into Sorted DLL in-place
    TreeNode* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Step2: Merge sorted Linked List
    TreeNode* head = mergeLinkedList(head1, head2);

    // Step3: Convert SLL into BST
    return sortedLLToBST(head, countNodes(head));
}
void printInorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {

    // Create first BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->right->left = new TreeNode(3);
    
    // Create second BST
    TreeNode* root2 = new TreeNode(6);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(7);
    
    // Merge the two BSTs
    TreeNode* mergedRoot = mergeBST(root1, root2);
    
    // Print inorder traversal of the merged BST
    cout << "Inorder traversal of the merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
*/
//                                          Approach 2
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : data(x), left(NULL), right(NULL) {

        }
};
void inorder(TreeNode* root, vector<int>& in) {

    if (root == NULL) {
        return;
    }

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {

    vector<int> ans(a.size() + b.size());

    int i = 0; 
    int j = 0;
    int k = 0;
    // Traversing in both arrays.
    while (i < a.size() && j < b.size()) {
        // Comparing array elements.
        if (a[i] < b[j]) {
            ans[k++] = a[i];
            i++;
        }
        else {
            ans[k++] = b[j];
            j++;
        }
    }
    // Pushing rest elements.
    while (i < a.size()) {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size()) {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}
TreeNode* inorderToBST(int s, int e, vector<int>& in) {
    
    // Base Case
    if(s>e) {
        return NULL;
    }

    int mid = (s+e)/2;

    TreeNode* root = new TreeNode(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);

    return root;
}
TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
    
    // Step 1: Store inorder 
    vector<int> bst1, bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);

    // Step 2: Merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1,bst2);

    // Step 3: Use merged inorder array to build BST
    int s = 0;
    int e = mergeArray.size()-1;
    return inorderToBST(s, e, mergeArray); 
}
void printInorder(TreeNode* root) {

    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {

    // Create first BST
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->right->left = new TreeNode(3);
    
    // Create second BST
    TreeNode* root2 = new TreeNode(6);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(7);
    
    // Merge the two BSTs
    TreeNode* mergedRoot = mergeBST(root1, root2);
    
    // Print inorder traversal of the merged BST
    cout << "Inorder traversal of the merged BST: ";
    printInorder(mergedRoot);
    cout << endl;

    return 0;
}
*/
