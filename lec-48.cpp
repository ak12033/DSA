#include<iostream>
#include<math.h>
#include<unordered_map>
using namespace std;

//                      Remove Duplicates from Sorted List
/*
class ListNode{

    public:
        int val;
        ListNode* next;

        // Constrcutor
        ListNode(int d) {
            this->val = d;
            this->next = NULL;
        }
};
ListNode* deleteDuplicates(ListNode* head) {

    // Empty List
    if(head == NULL){
        return NULL;
    }
    // Non-Empty List
    ListNode* curr = head;
    while(curr != NULL) {
        if( (curr -> next != NULL) && curr -> val == curr -> next -> val) {
            ListNode* next_next = curr ->next -> next;
            ListNode* nodeToDelete = curr -> next;
            delete(nodeToDelete);
            curr -> next = next_next;
        }
        else{
            curr = curr -> next;
        }   
    }
    return head;
}
int main() {

    // Creating a linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    // Call deleteDuplicates function
    head = deleteDuplicates(head);

    // Print the modified linked list
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    return 0;
}
*/

//                 Remove Duplicates From an Unsorted Linked List
/*
class Node{

    public:
        int data;
        Node* next;

        // Constrcutor
        Node(int d) {
            this->data = d;
            this->next = NULL;
        }
};
Node *removeDuplicates(Node *head){  
    
    // Empty List
    if(head == NULL){
        return NULL;
    }
    // Non-Empty List
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, bool> visited;
    while(curr != NULL){
        if(!visited[curr->data]){
            visited[curr->data] = true;
            prev = curr;
            curr = curr -> next;
        }
        else{
            prev -> next = curr -> next;
            delete curr;
        }
        curr = prev -> next;
    }
    return head;
}
void printList(Node* head) {

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    // Creating a linked list: 1 -> 2 -> 2 -> 3 -> 4 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);

    cout << "Original list: ";
    printList(head);

    // Remove Duplicates
    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
*/

//                           Dividing Circular Linked List
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
void printList(Node* tail) {

    if(tail == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    Node* temp = tail;
    cout << "Circular List : ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    cout << endl;
}
void insertion(Node* &tail, int data, int target) {

    Node *insertNode = new Node(data);

    if(tail == NULL) {
        tail = insertNode;
        insertNode->next = tail;
        return;
    }
    Node* curr = tail;

    while(curr->data != target) {
        curr = curr->next;
    }
    insertNode->next = curr->next;
    curr->next = insertNode;
}
int getLength(Node* tail) {

    if(tail == NULL) {
        return 0;
    }
    int count = 1;
    Node* temp = tail->next;
    while(temp != tail) {
        count++;
        temp = temp->next;
    }
    return count;
}
pair<Node*, Node*> splitList(Node* tail) {

    Node* tail1 = tail;
    Node* tail2 = NULL;
    int len = (getLength(tail) + 1) / 2;

    Node* temp = tail;
    while(len > 1) {
        temp = temp->next;
        len--;
    }
    tail2 = temp->next;
    temp->next = tail;
    temp = tail2;
    while(temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail2;

    return {tail1, tail2};
}
int main() {

    Node *tail = NULL;

    insertion(tail, pow(2,4), 2);
    insertion(tail, pow(2,3), 16);
    insertion(tail, pow(2,5), 8);
    insertion(tail, pow(2,2), 16);
    insertion(tail, pow(2,0), 8);

    printList(tail);

    pair<Node*, Node*> solution;
    solution = splitList(tail);

    printList(solution.first);
    printList(solution.second);

    return 0;
}
*/
