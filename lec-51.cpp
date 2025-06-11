#include<iostream>
using namespace std;

//                          Add two numbers represented by linked list

//                                         Approach 1
/*
class Node {

    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};
Node* reverse(Node* head) {
        
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
        
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAtTail(struct Node* &head,struct Node* &tail, int val) {
        
    Node* temp = new Node(val);
    // Empty list
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
Node* add(Node* first, Node* second) {
    
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while(first != NULL && second != NULL) {    
        int sum = carry + first -> data + second -> data;   
        int digit = sum % 10;
        // Create Node and Add in Answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }
    while(first != NULL){
        int sum = carry + first -> data;
        int digit = sum % 10;
        // Create Node and Add in Answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        first = first->next;
    }
    while(second != NULL){
        int sum = carry + second -> data;
        int digit = sum % 10;
        // Create Node and Add in Answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
        second = second->next;
    }
    while(carry != 0){
        int sum = carry;
        int digit = sum % 10;
        // Create Node and Add in Answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum/10;
    }
    return ansHead;
}
Node* addTwoLists(Node* num1, Node* num2){

    // Step 1
    num1 = reverse(num1);
    num2 = reverse(num2);
        
    // Step 2 -> Add 2 LL
    Node* ans = add(num1, num2);
        
    // Step 3
    ans = reverse(ans);
    while (ans->data == 0 && ans->next != NULL){
        ans = ans->next;
    }
    return ans;
}
void printList(Node* head) {

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    // 342
    Node* num1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(num1, tail1, 3);
    insertAtTail(num1, tail1, 4);
    insertAtTail(num1, tail1, 2);

    // 465
    Node* num2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(num2, tail2, 4);
    insertAtTail(num2, tail2, 6);
    insertAtTail(num2, tail2, 5);

    // Adding the two lists
    Node* result = addTwoLists(num1, num2);

    // Printing the result (Expected: 807)
    cout << "Result: ";
    printList(result);

    return 0;
}
*/

//                                Approach 1(optimized)
/*
class Node {

    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};
Node* reverse(Node* head) {
        
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
        
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void insertAtTail(struct Node* &head,struct Node* &tail, int val) {
        
    Node* temp = new Node(val);
    // Empty list
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}
Node* add(Node* first, Node* second) {
    
    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while(first != NULL || second != NULL || carry != 0) {     
        int val1 = 0;
        if(first != NULL){
            val1 = first -> data;
        }
        int val2 = 0;
        if(second !=NULL){
            val2 = second -> data;
        }    

        int sum = carry + val1 + val2;
        int digit = sum % 10;    
        // Create Node and Add in Answer Linked List
        insertAtTail(ansHead, ansTail, digit);    
        carry = sum/10;

        if(first != NULL){
            first = first -> next;
        }
        if(second != NULL){
            second = second -> next;
        }
    }
    return ansHead;
}
Node* addTwoLists(Node* num1, Node* num2){

    // Step 1
    num1 = reverse(num1);
    num2 = reverse(num2);
        
    // Step 2 -> Add 2 LL
    Node* ans = add(num1, num2);
        
    // Step 3
    ans = reverse(ans);
    while (ans->data == 0 && ans->next != NULL){
        ans = ans->next;
    }
    return ans;
}
void printList(Node* head) {

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    // 342
    Node* num1 = NULL;
    Node* tail1 = NULL;
    insertAtTail(num1, tail1, 3);
    insertAtTail(num1, tail1, 4);
    insertAtTail(num1, tail1, 2);

    // 465
    Node* num2 = NULL;
    Node* tail2 = NULL;
    insertAtTail(num2, tail2, 4);
    insertAtTail(num2, tail2, 6);
    insertAtTail(num2, tail2, 5);

    // Adding the two lists
    Node* result = addTwoLists(num1, num2);

    // Printing the result (Expected: 807)
    cout << "Result: ";
    printList(result);

    return 0;
}
*/