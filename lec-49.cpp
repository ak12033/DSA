#include<iostream>
using namespace std;

//                                  Sort 0s 1s 2s

//                                    Approach 1
/*
class Node{

    public:
        int data;
        Node *next;

        Node(){
            this->data = 0;
            next = NULL;
        }
        Node(int d) {
        this->data = d;
        next = NULL;
    }
};
Node* sortList(Node *head){

    int CountZero = 0;
    int CountOne = 0;
    int CountTwo=0;

    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0){
            CountZero++;
        }
        else if(temp->data == 1){
            CountOne++;
        }
        else if(temp->data == 2){
            CountTwo++;
        }
        temp=temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(CountZero != 0){
            temp->data = 0;
            CountZero--;
        }
        else if(CountOne != 0){
            temp->data = 1;
            CountOne--;
        }
        else if(CountTwo != 0){
            temp->data = 2;
            CountTwo--;
        }
        temp = temp->next;
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
Node* createList(int arr[], int size) {

    if (size == 0) return NULL;
    
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
int main() {

    int arr[] = {2, 1, 0, 1, 2, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    Node* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    // Sort the linked list
    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
*/

//                                     Approach 2
/*
class Node{

    public:
        int data;
        Node *next;

        Node(){
            this->data = 0;
            next = NULL;
        }
        Node(int d) {
        this->data = d;
        next = NULL;
    }
};
void insertAtTail(Node* &tail, Node* curr) {

    tail->next = curr;
    tail = tail->next;
}
Node* sortList(Node *head){
    
    Node* ZeroHead = new Node(-1);
    Node* ZeroTail = ZeroHead;
    Node* OneHead = new Node(-1);
    Node* OneTail = OneHead;
    Node* TwoHead = new Node(-1);
    Node* TwoTail = TwoHead;
    
    Node* curr = head;
    // Create separate list of 0s, 1s and 2s
    while(curr != NULL) {
        int value = curr->data;
        if(value == 0) {
            insertAtTail(ZeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(OneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(TwoTail, curr);
        }       
        curr = curr -> next;
    }

    // Merge 3 sublist

    // 1s list -> Non-Empty
    if(OneHead->next != NULL) {
        ZeroTail->next = OneHead->next;
    }
    else {
        //1s list -> Empty
        ZeroTail->next = TwoHead->next;
    }
    OneTail->next = TwoHead->next;
    TwoTail->next = NULL;
    
	//setup head 
    head = ZeroHead->next;
    
    //delete dummy nodes
    delete ZeroHead;
    delete OneHead;
    delete TwoHead;
    
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
Node* createList(int arr[], int size) {

    if (size == 0) {
        return NULL;
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
int main() {

    int arr[] = {2, 1, 0, 1, 2, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create the linked list
    Node* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    // Sort the linked list
    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
*/

//                              Merge Two Sorted Lists

//                                     Approach 1
/*
class ListNode{

    public:
        int val;
        ListNode *next;

        ListNode(){
            this->val = 0;
            next = NULL;
        }
        ListNode(int d) {
        this->val = d;
        next = NULL;
    }
};
ListNode* solve(ListNode* first, ListNode* second) {

    // If only one elment is present in first list 
    if(first -> next == NULL){
        first -> next = second;
        return first;
    }

    ListNode* curr1 = first;
    ListNode* next1 = curr1 -> next;
    
    ListNode* curr2 = second;
    ListNode* next2 = curr2 -> next;
    
    while(next1 != NULL && curr2 != NULL) {
        
        if( (curr2 -> val >= curr1 -> val ) && ( curr2 -> val <= next1 -> val)) {
            next2 = curr2->next; 
            curr1 -> next = curr2;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1 -> next;
            if(next1 == NULL){
                curr1 -> next = curr2;
                return first;
            }
        }    
    }
    return first;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }
    if(list1->val <= list2->val ){
        return solve(list1, list2);
    }
    else{
        return solve(list2, list1);
    }
}
void printList(ListNode* head) {

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode* createList(int arr[], int size) {

    if (size == 0){
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}
int main() {

    // Create two sorted linked lists
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
*/

//                                 Approach 2
/*
class ListNode{

    public:
        int val;
        ListNode *next;

        ListNode(){
            this->val = 0;
            next = NULL;
        }
        ListNode(int d) {
        this->val = d;
        next = NULL;
    }
};
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    if(!list1){
        return list2;
    }
    if(!list2){
        return list1;
    }
    if((list1 -> val) < (list2 ->val)){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}
void printList(ListNode* head) {

    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode* createList(int arr[], int size) {

    if (size == 0){
        return NULL;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}
int main() {

    // Create two sorted linked lists
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    
    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge the two lists
    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
*/