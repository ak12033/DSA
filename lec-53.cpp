#include<iostream>
using namespace std;

//                                      Merge Sort
/*
class Node{

    public:
        int data;
        Node* next;

        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};
Node* findMid(Node* head) {

    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}
Node* merge(Node* left, Node* right) {
    
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;
    
    // Merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}
Node* mergeSort(Node *head) {

    // Base Case
    if(head == NULL || head -> next == NULL) {
        return head;
    }
    
    // After Finding Mid
    Node* mid = findMid(head);
    
    // Breaking Linked List into 2 halves
    Node* left = head;
    Node* right = mid->next;
    mid -> next = NULL;
    
    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Merge both left and right halves
    Node* result = merge(left, right);
    return result;
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

    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(7);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    // Sorting the list using mergeSort
    Node* sortedHead = mergeSort(head);

    cout << "Sorted List: ";
    printList(sortedHead);

    return 0;
}
*/

//                              Flattening Linked List
/*
class Node {
    public:
		int data;
		Node *next;
  		Node *child;
		
        Node(int d){
            this->data = d;
            this->next = NULL;
            this->child = NULL;
        }
};
Node* Merge(Node* left, Node* right){

	if(left == NULL){
		return right;
	}
	if(right == NULL){
		return left;
	}

	Node* ans = new Node(-1);
	Node* temp = ans;

	while(left != NULL && right != NULL){
		if(left -> data < right -> data){
			temp -> child = left;
			temp = left;
			left = left -> child;
		}
		else{
			temp -> child = right;
			temp = right;
			right = right -> child;
		}
	}
	while(left != NULL){
		temp -> child = left;
		temp = left;
		left = left -> child;
	}
	while(right != NULL){
		    temp -> child = right;
			temp = right;
			right = right -> child;    
	}
	ans = ans -> child;
	return ans;
}
Node* flattenLinkedList(Node* head){
	
	// Base Case
    if(head == NULL || head->next == NULL){
        return head ;
    }
    Node* down = head;
    Node* right = flattenLinkedList(head->next);
    down->next = NULL;
    
    Node* ans2 = Merge(down, right);
    return ans2;
}
void printList(Node* head) {

    Node* temp = head;
    // Traverse through the main list using next pointers
    while (temp != NULL) {
        // Print the current node data
        cout << "Data: " << temp->data;
        
        // Check if the node has a child list
        if (temp->child != NULL) {
            cout << " -> Child: ";
            // Print the child list recursively
            Node* childTemp = temp->child;
            while (childTemp != NULL) {
                cout << childTemp->data << " ";
                childTemp = childTemp->child;
            }
        }
        cout << " | ";
        temp = temp->next;
    }
    cout << endl;
}
int main() {

    // Creating a multi-level linked list
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    // Creating child lists
    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);
    head->next->child->child = new Node(50);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(35);

    head->next->next->next->child = new Node(40);
    head->next->next->next->child->child = new Node(45);

    cout << "Original multi-level linked list:" << endl;
    printList(head);

    // Flattening the multi-level linked list
    Node* flattened = flattenLinkedList(head);

    cout << "Flattened linked list:" << endl;
    printList(flattened);

    return 0;
}
*/