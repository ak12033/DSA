#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//                                  Creating a Tree
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
int main(){

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);

    return 0;
}
*/

//                                  Level Order Traversal
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void levelOrderTraversal(node* root) {

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            // Previous level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                // Queue still has some child nodes
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
int main() {

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);
    
    // Level Order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    return 0;
}
*/

//                             Reverse Level Order Traversal
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void ReverseLevelOrderTraversal(node* root){

    queue<node*> Q;
    stack<node*> S;

    S.push(NULL);
    Q.push(root);
    Q.push(NULL);

    node* temp;
    while(!Q.empty()) {
        temp = Q.front();
        Q.pop();
        if(temp) {
            S.push(temp);
            if(temp->right) {
                Q.push(temp->right);
            }
            if(temp->left) {
                Q.push(temp->left);
            }
        }
        else {
            S.push(NULL);
            if(!Q.empty()){
                Q.push(NULL);
            }
        }
    }
    S.pop();
    while(!S.empty()) {
        temp = S.top();
        S.pop();
        if(temp) {
            cout << temp->data << " ";
        }
        else {
            cout << endl;
        }
    }
    return;
}
int main() {

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);
    
    // Reverse Level Order
    cout << "Printing the reverse level order tracersal output " << endl;
    ReverseLevelOrderTraversal(root);

    return 0;
}
*/

//                                  In-Order Traversal
//                                        (LNR)
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    
    return root;
}
void inorder(node* root) {

    // Base Case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}
int main() {

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);
    
    // In-Order
    cout << "inorder traversal is:  ";
    inorder(root); 

    return 0;
}
*/

//                                  Pre-Order Traversal
//                                        (NLR)
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void preorder(node* root) {

    // Base Case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);
    
    // Pre-Order
    cout << endl << "preorder traversal is:  ";
    preorder(root);  

    return 0;
}
*/

//                                  Post-Order Traversal
//                                         (LRN)
/*
class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    
    return root;
}
void postorder(node* root) {
    
    // Base Case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}
int main() {

    // Creating a Tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node* root = NULL;
    root = buildTree(root);
    
    // Post-Order
    cout << endl << "postorder traversal is:  ";
    postorder(root);  

    return 0;
}
*/

//                              Building a Tree from Level Order
/*
class node {

    public:
        int data;
        node* left;
        node* right;

        node(int d) {

            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
        }
};
void buildFromLevelOrder(node* &root) {

    queue<node*> q;
    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        // Left Node
        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }
        // Right Node
        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(node* root) {

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            // Previous level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                // Queue still has some child nodes
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
int main() {

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    node* root = NULL;    
    
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    
    return 0;
}
*/

//                                   Count leaf nodes
/*
class BinaryTreeNode {

    public :
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(int data) {

                this -> data = data;
                left = NULL;
                right = NULL;
        }
};
void inorder(BinaryTreeNode* root, int &count) {

    // Base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);    
    // Leaf Node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    inorder(root->right, count);
}
int noOfLeafNodes(BinaryTreeNode* root){

    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}
int main() {

    // Create a binary tree
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);
    root->right->right = new BinaryTreeNode(7);
    
    // Result
    cout << "Number of leaf nodes: " << noOfLeafNodes(root) << endl;
    
    return 0;
}
*/