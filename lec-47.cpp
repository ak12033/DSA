#include<iostream>
#include<map>
using namespace std;

//                                 Is Loop Present or Not

//                                       Approach 1
/*
class Node {

    public:
        int data;
        Node* next;

        // Constructor
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
bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;
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

    // Example 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "Is the first list circular? " << (detectLoop(head1) ? "Yes" : "No") << endl;

    // Example 2
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(7);
    // Creating a Cycle
    head2->next->next->next = head2->next;

    cout << "Is the second list circular? " << (detectLoop(head2) ? "Yes" : "No") << endl;

    return 0;
}
*/

//                                    Approach 2
//                       (Floyd's Cycle-Finding Algorithm)
/*
class Node {

    public:
        int data;
        Node* next;

        // Constructor
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
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast->next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            cout << "present at " << slow -> data << endl;
            return slow;
        }
    }
    return NULL;
}
int main() {
    
    // Example 1
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);

    cout << "Is there a cycle in the first list? " 
         << (floydDetectLoop(head1) ? "Yes" : "No") << endl;

    // Example 2
    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(7);
    // Creating a Cycle
    head2->next->next->next = head2; 

    cout << "Is there a cycle in the second list? " 
         << (floydDetectLoop(head2) ? "Yes" : "No") << endl;

    return 0;
}
*/

//                          Beginning of a Loop 
/*
class Node {

    public:
        int data;
        Node* next;

        // Constructor
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
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast->next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  
    return slow;
}
int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Creating a loop for testing

    Node* loopStart = getStartingNode(head);
    if (loopStart != NULL) {
        cout << "Loop starts at node with data: " << loopStart->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}
*/

//                            Detect and Remove Loop
/*
class Node {

    public:
        int data;
        Node* next;

        // Constructor
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
Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL) {
        
        fast = fast->next;
        if(fast != NULL) {
            fast = fast -> next;
        }
        slow = slow -> next;
        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}
Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  
    return slow;
}
Node* removeLoop(Node* head) {

    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop) {
        temp = temp->next;
    } 
    temp -> next = NULL;
    return head;
}
int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Creating a loop: 5 -> 3 (loop starts at node with data 3)
    head->next->next->next->next->next = head->next->next;

    cout << "Before removing the loop:" << endl;
    Node* loopStart = getStartingNode(head);
    if (loopStart) {
        cout << "Loop detected at node with data: " << loopStart->data << endl;
    } 
    else {
        cout << "No loop detected!" << endl;
    }

    // Removing the loop
    head = removeLoop(head);

    // Verifying the loop has been removed
    loopStart = floydDetectLoop(head);
    if (loopStart) {
        cout << "Loop detected at node with data: " << loopStart->data << endl;
    } 
    else {
        cout << "No loop detected!" << endl;
    }
    return 0;
}
*/

