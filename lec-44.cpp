#include<iostream>
#include<map>
using namespace std;

//                                 Singly Linked list

//                                 Inserting at Head
/*
class Node {

    public:
        int data;
        Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtHead(Node* &head, int d) {

    // New node creation
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){

    // Created a new node
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
    
    // Head pointed to node1
    Node* head = node1;
    InsertAtHead(head, 12);
    InsertAtHead(head, 15);
    print(head); 

    return 0;
}
*/

//                                 Inserting at Tail
/*
class Node {

    public:
        int data;
        Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtTail(Node* &tail, int d) {

    // New node creation
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;
    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){

    // Created a new node
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
    
    // Head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);
    print(head); 

    return 0;
}
*/

//                             Inserting at any Position
/*
class Node {

    public:
        int data;
        Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};
void InsertAtHead(Node* &head, int d) {

    // New node creation
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertAtTail(Node* &tail, int d) {

    // New node creation
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
void InsertAtPosition(Node* &tail, Node* & head, int position, int d) {

    // Inserting at Starting Position
    if(position == 1) {
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;

    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    // Inserting at Last Position
    if(temp -> next == NULL) {
        InsertAtTail(tail,d);
        return ;
    }
    // Inserting at Particular Position
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    // Head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);

    print(head);

    InsertAtPosition(tail, head, 1, 5);
    InsertAtPosition(tail, head, 4, 14);
    InsertAtPosition(tail, head, 6, 22);

    print(head);    

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    return 0;
}
*/

//                             Deletion by Position
/*
class Node {

    public:
        int data;
        Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    // Destructor
    ~Node() {
        int value = this -> data;
        // Memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void InsertAtHead(Node* &head, int d) {

    // New node creation
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
void InsertAtTail(Node* &tail, int d) {

    // New node creation
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
void InsertAtPosition(Node* &tail, Node* & head, int position, int d) {

    // Inserting at Starting Position
    if(position == 1) {
        InsertAtHead(head, d);
        return;
    }
    Node* temp = head;

    int cnt = 1;
    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    // Inserting at Last Position
    if(temp -> next == NULL) {
        InsertAtTail(tail,d);
        return ;
    }
    // Inserting at Particular Position
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}
void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void deleteNode(Node* & tail,int position, Node* & head) { 

    // Deleting First or Start Node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        // Memory free with Starting Node
        temp -> next = NULL;
        delete temp;
    }
    else{
        // Deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

        if(prev->next == NULL){
            tail = prev;
        }
    }
}
int main() {
    
    // Created a new node
    Node* node1 = new Node(10);
    // Head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    InsertAtTail(tail, 12);
    InsertAtTail(tail, 15);
    print(head);
    InsertAtPosition(tail, head, 1, 5);
    InsertAtPosition(tail, head, 4, 14);
    InsertAtPosition(tail, head, 6, 22);
    print(head);    

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;

    deleteNode(tail, 4, head);
    print(head);
    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    
    return 0;
}
*/

//                                 Doubly Linked List

//                              Traversing a Linked List
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node* head) {

    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    print(head);

    return 0;
}
*/

//                          Gives Length of a Linked List
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
int getLength(Node* head) {

    int len = 0;
    Node* temp  = head ;
    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }
    return len;
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    cout << getLength(head) << endl;

    return 0;
}
*/

//                                Inserting at Head
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void InsertAtHead(Node* &tail, Node* &head, int d) {

    // Empty List
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void print(Node* head) {

    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtHead(tail, head, 9);
    print(head);
    InsertAtHead(tail, head, 8);
    print(head);
    InsertAtHead(tail, head, 7);
    print(head);

    return 0;
}
*/

//                                Inserting at Tail
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void InsertAtTail(Node* &tail,Node* &head, int d) {

    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}
void print(Node* head) {

    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertAtTail(tail, head, 11);
    print(head);
    InsertAtTail(tail, head, 12);
    print(head);
    InsertAtTail(tail, head, 13);
    print(head);

    return 0;
}
*/

//                              Inserting at any Position
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
void insertAtHead(Node* &tail, Node* &head, int d) {

    // Empty List
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}
void insertAtTail(Node* &tail,Node* &head, int d) {

    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    // Insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }
    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // Inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }
    // Creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
void print(Node* head) {

    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(tail,head, 11);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 13);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtHead(tail,head, 8);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail,head, 25);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 1, 101);
    print(head);

    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtPosition(tail, head, 7, 102);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    return 0;
}
*/

//                                      Deletion
/*
class Node {

    public:
        int data;
        Node* prev;
        Node* next;

    // Constructor
    Node(int d ) {
        this-> data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    // Destructor
    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};
void insertAtTail(Node* &tail,Node* &head, int d) {

    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next  = temp;
        temp -> prev = tail;
        tail = temp;
    }

}
void print(Node* head) {

    Node* temp  = head ;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp  = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node* & tail,int position, Node* & head) { 

    // Deleting First or Starting node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        if(curr->next!=NULL){
        curr -> next -> prev = prev;
        }
        curr -> next = NULL;
        delete curr;
        if (prev->next == NULL) {
            tail = prev;
        }
    }
}
int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(tail, head, 1);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 2);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 3);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 4);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 5);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 6);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    insertAtTail(tail, head, 7);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;


    deleteNode(tail, 7, head);
    print(head);
    cout << "head  " << head -> data << endl;
    cout << "tail  " << tail -> data << endl;

    return 0;
}
*/

//                              Circular Linked List

//                             Insertion at any Position
/*
class Node {

    public:
        int data;
        Node* next;

    // Constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};
void insertNode(Node* &tail, int element, int d) {
    
    // Empty List
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // Non-Empty List
        // Assuming that the element is present in the list

        Node* curr = tail;
        while(curr->data != element) {
            curr = curr -> next;
        }
        // Element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void print(Node* tail) {

    Node* temp = tail;
    // Empty List
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }
    // cout << tail -> data << " ";
    // while(tail -> next != temp){
    //   cout << tail -> data << " ";
    //    tail = tail -> next;
    // }
    // cout<<" ";
    //                                         OR                                                       
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}
int main(){
    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);

    return 0;
}
*/

//                                      Deletion
/*
class Node {

    public:
        int data;
        Node* next;

    // Constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
void insertNode(Node* &tail, int element, int d) {
    
    // Empty List
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        // Non-Empty List
        // Assuming that the element is present in the list

        Node* curr = tail;
        while(curr->data != element) {
            curr = curr -> next;
        }
        // Element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}
void deleteNode(Node* &tail, int value) {

    // Empty List
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        // Non-Empty
        // Assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        // 1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }
        // >=2 Node linked list
        if(tail == curr ) {
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
} 
void print(Node* tail) {

    Node* temp = tail;
    // Empty List
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    // cout << tail -> data << " ";
    // while(tail -> next != temp){
    //   cout << tail -> data << " ";
    //    tail = tail -> next;
    // }
    // cout<<" ";
    //                                         OR                                               
    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);
    cout << endl;
}

int main(){

    Node* tail = NULL;
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 5, 7);
    print(tail);

    insertNode(tail, 7, 9);
    print(tail);

    insertNode(tail, 5, 6);
    print(tail);
    
    insertNode(tail, 9, 10);
    print(tail);

    insertNode(tail, 3, 4);
    print(tail);
   
    deleteNode(tail, 5);
    print(tail);

    return 0;
}
*/