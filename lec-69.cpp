#include<iostream>
#include<queue>
using namespace std;

//                                Binary Search Tree

//                                    Insertion
/*
class TreeNode{

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void inorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    
    // Base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
void levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            // Purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                // Queue still has some child Treenodes
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
} 
TreeNode* insertIntoBst(TreeNode* root, int d) {
    
    // Base case
    if(root == NULL) {
        root = new TreeNode(d);
        return root;
    }
    
    if(d > root->data) {
        // Righ part me insert karna h
        root->right = insertIntoBst(root->right, d);
    }
    else {
        // Left part me insert karna h
        root->left = insertIntoBst(root->left, d);
    }
    return root;
}
void takeInput(TreeNode* &root) {

    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBst(root, data);
        cin >> data;
    }
}
int main() {
    
    TreeNode* root = NULL;
    
    cout<<"Enter data to create BST :- "<<endl;
    takeInput(root);
    
    cout<<"Printing the BST "<<endl;
    levelOrderTraversal(root);
    
    cout<<"Printing Inorder "<<endl;
    inorder(root);

    cout << endl <<"Printing Preorder "<<endl;
    preorder(root);

    cout << endl<<"Printing Postorder "<<endl;
    postorder(root);
    
    return 0;
}
*/

//                          Search in a Binary Search Tree

//                                   Approach 1
//                                   (Iterative)
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
TreeNode* searchBST(TreeNode* root, int val) {

    TreeNode* temp = root;
    while(temp != NULL) {
        if(temp->val == val) {
            return temp;
        }
        if(temp->val > val) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return NULL;
}
int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Searching for a value in the BST
    int searchValue = 2;
    TreeNode* result = searchBST(root, searchValue);

    // Output the result
    if (result != NULL) {
        cout << "TreeNode with value " << searchValue << " found!" << endl;
    } else {
        cout << "TreeNode with value " << searchValue << " not found." << endl;
    }

    // Cleanup the memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/
//                                   Approach 2
//                                   (Recursive)
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
            
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

        }
};
TreeNode* searchBST(TreeNode* root, int val) {

    if(root == NULL) {
        return NULL;
    }
    if(root->val == val) {
        return root;
    }
    if(root->val > val) {
        return searchBST(root->left, val);
    }
    else {
        return searchBST(root->right, val);
    }
}
int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Searching for a value in the BST
    int searchValue = 2;
    TreeNode* result = searchBST(root, searchValue);

    // Output the result
    if (result != NULL) {
        cout << "TreeNode with value " << searchValue << " found!" << endl;
    } else {
        cout << "TreeNode with value " << searchValue << " not found." << endl;
    }

    // Cleanup the memory (optional, but good practice)
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
*/

// Note: Inorder of BST is sorted

//                             Minimum and Maximum value in BST
/*
class TreeNode{

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
TreeNode* minVal(TreeNode* root) {

    TreeNode* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
TreeNode* maxVal(TreeNode* root) {

    TreeNode* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
int main() {

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    // Finding and printing the minimum and maximum values in the BST
    TreeNode* minTreeNode = minVal(root);
    TreeNode* maxTreeNode = maxVal(root);

    cout << "Minimum value in the BST: " << minTreeNode->data << endl;
    cout << "Maximum value in the BST: " << maxTreeNode->data << endl;

    // Cleanup
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
*/

//                         Predecessor And Successor In BST
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
int getSuccessor(TreeNode* root, int key) {

    TreeNode* succ = NULL;
    while(root != NULL) {
        if(root->data > key) {
            succ = root;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    if(succ == NULL || succ->data == key) {
        return -1;
    } 
    else {
        return succ->data;
    }
}
int getPredecessor(TreeNode* root, int key) {

    TreeNode* pre = NULL;
    while(root != NULL) {
        if(root->data < key) {
            pre = root;
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    if(pre == NULL || pre->data == key) {
        return -1;
    } 
    else {
        return pre->data;
    }
}
pair<int, int> predecessorSuccessor(TreeNode *root, int key) {

    int succ = getSuccessor(root, key);
    int pre = getPredecessor(root, key);
    return {pre, succ};
    
}
int main() {

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);

    int key = 40;

    pair<int, int> result = predecessorSuccessor(root, key);

    cout << "Predecessor: " << result.first << endl;
    cout << "Successor: " << result.second << endl;

    return 0;
}
*/

//                                     Deletion

//                                    Approach 1
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void inorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    
    // Base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
void levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            // Purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                // Queue still has some child Treenodes
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
} 
TreeNode* minVal(TreeNode* root) {

    TreeNode* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
TreeNode* deleteFromBST(TreeNode* root, int val) {

    // Base case
    if(root == NULL) {
        return root;
    }
    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child
        if(root->left != NULL && root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Right child
        if(root->left == NULL && root->right != NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val) {
        // Left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        // Right part me jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main(){

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(20);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);
    root->right->right = new TreeNode(90);
    root->right->right->right = new TreeNode(110);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
    cout << "Printing Inorder" << endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl<< "Printing Postorder" << endl;
    postorder(root);

    // Deletion 
    root = deleteFromBST(root, 90);
    cout << endl;

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
    cout << "Printing Inorder" << endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    return 0;
}
*/
//                                    Approach 2
/*
class TreeNode {

    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        
        TreeNode(int d) {
            
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};
void inorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
void preorder(TreeNode* root) {
    
    // Base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(TreeNode* root) {

    // Base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
void levelOrderTraversal(TreeNode* root) {

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            // Purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                // Queue still has some child Treenodes
                q.push(NULL);
            }  
        }
        else {
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
} 
TreeNode* maxVal(TreeNode* root) {

    TreeNode* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
TreeNode* deleteFromBST(TreeNode* root, int val){

    // Base case
    if(root == NULL) {
        return root;
    }
    if(root->data == val) {
        // 0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // Left child
        if(root->left != NULL && root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Right child
        if(root->left == NULL && root->right != NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL) {
            int maxi = maxVal(root->left) -> data;
            root->data = maxi;
            root->left = deleteFromBST(root->left,maxi);
            return root;
        }

    }
    else if(root->data > val) {
        // Left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        // Right part me jao
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main(){

    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(20);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(10);
    root->left->right = new TreeNode(30);
    root->right->right = new TreeNode(90);
    root->right->right->right = new TreeNode(110);

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
    cout << "Printing Inorder" << endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    // Deletion 
    root = deleteFromBST(root, 50);
    cout << endl;

    cout << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
    cout << "Printing Inorder" << endl;
    inorder(root);

    cout << endl << "Printing Preorder" << endl;
    preorder(root);

    cout << endl << "Printing Postorder" << endl;
    postorder(root);

    return 0;
}
*/