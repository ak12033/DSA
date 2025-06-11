#include<iostream>
#include <vector>
using namespace std;

//                                  Palindrome Linked List

//                                         Approach 1
/*
class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int data) {
            this->val = data;
            this->next = NULL;
        }
};
bool checkPalindrome(vector<int> arr){

    int n = arr.size();

    int s = 0;
    int e = n-1;
    while(s<=e){
        if(arr[s] != arr[e]){
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
bool isPalindrome(ListNode* head) {

    vector<int> arr;
    ListNode* temp = head;
    while(temp!=NULL){
        arr.push_back(temp -> val);
        temp = temp -> next;
    }
    return checkPalindrome(arr);
}
ListNode* createList(vector<int>& values) {

    if (values.empty()){
        return NULL;
    }

    ListNode* head = new ListNode(values[0]);

    ListNode* temp = head;
    for (int i = 1; i < values.size(); ++i) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {

    // Example 1: Palindrome list
    vector<int> values1 = {1, 2, 3, 2, 1};
    ListNode* head1 = createList(values1);
    cout << "List 1: ";
    printList(head1);
    cout << "Is palindrome? " << (isPalindrome(head1) ? "Yes" : "No") << endl;

    // Example 2: Non-palindrome list
    vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(values2);
    cout << "List 2: ";
    printList(head2);
    cout << "Is palindrome? " << (isPalindrome(head2) ? "Yes" : "No") << endl;

    // Example 3: Single element list (palindrome)
    vector<int> values3 = {10};
    ListNode* head3 = createList(values3);
    cout << "List 3: ";
    printList(head3);
    cout << "Is palindrome? " << (isPalindrome(head3) ? "Yes" : "No") << endl;

    // Example 4: Empty list (palindrome)
    vector<int> values4 = {};
    ListNode* head4 = createList(values4);
    cout << "List 4: ";
    printList(head4);
    cout << "Is palindrome? " << (isPalindrome(head4) ? "Yes" : "No") << endl;

    return 0;
}
*/

//                                         Approach 2
/*
class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int data) {
            this->val = data;
            this->next = NULL;
        }
};
ListNode* getMid(ListNode* head ) {

    ListNode* slow = head;
    ListNode* fast = head -> next;
        
    while(fast != NULL && fast-> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
ListNode* reverse(ListNode* head) {
        
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
        
    while(curr != NULL) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(ListNode* head) {

    if(head->next == NULL) {
        return true;
    }
        
    // Step 1 -> Find Middle
    ListNode* middle = getMid(head);
        
    // Step 2 -> Reverse List after Middle
    ListNode* temp = middle -> next;
    middle -> next = reverse(temp);
    
    // Step 3 -> Compare both halves
    ListNode* head1 = head;
    ListNode* head2 = middle -> next;
        
    while(head2 != NULL) {
        if(head2->val != head1->val) {
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // Step 4 -> Repeat Step 2
    temp = middle -> next;
    middle -> next = reverse(temp);
        
    return true;
}
ListNode* createList(vector<int>& values) {

    if (values.empty()){
        return NULL;
    }

    ListNode* head = new ListNode(values[0]);

    ListNode* temp = head;
    for (int i = 1; i < values.size(); ++i) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main() {

    // Example 1: Palindrome list
    vector<int> values1 = {1, 2, 3, 2, 1};
    ListNode* head1 = createList(values1);
    cout << "List 1: ";
    printList(head1);
    cout << "Is palindrome? " << (isPalindrome(head1) ? "Yes" : "No") << endl;

    // Example 2: Non-palindrome list
    vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(values2);
    cout << "List 2: ";
    printList(head2);
    cout << "Is palindrome? " << (isPalindrome(head2) ? "Yes" : "No") << endl;

    // Example 3: Single element list (palindrome)
    vector<int> values3 = {10};
    ListNode* head3 = createList(values3);
    cout << "List 3: ";
    printList(head3);
    cout << "Is palindrome? " << (isPalindrome(head3) ? "Yes" : "No") << endl;

    return 0;
}
*/