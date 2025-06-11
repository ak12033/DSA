#include<iostream>
#include<stack>
using namespace std;

//                                      Stack
/*
int main(){

    // Creation of stack
    stack<int> s;

    // Push operation
    s.push(2);
    s.push(3);

    // Pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    return 0;
}
*/

//                          Implementation of Stack using arrays
/*
class Stack {

    // Properties
    public:
        int *arr;
        int top;
        int size;

        // Behaviour
        Stack(int size) {

            this -> size = size;
            arr = new int[size];
            top = -1;
        }
        void push( int element) {

            if(size - top > 1) {
                top++;
                arr[top] = element;
            }
            else{
                cout << "Stack OverFlow" << endl;
            }
        }
        void pop() {

            if(top >=0 ) {
                top--;
            }
            else{
                cout << "Stack UnderFlow" << endl;
            }
        }
        int peak() {

            if(top >=0 )
                return arr[top];
            else{
                cout << "Stack is Empty" << endl;
                return -1;
            }
        }
        bool isEmpty() {

            if( top == -1) {
                return true;
            }
            else{
                return false;
            }
        }
};
int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    st.pop();

    cout << st.peak() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }
}
*/

//                     Implementation of Stack using Linked List
/*
class Stack{

    public:
        int val;
        Stack* next;

        Stack(int d){

            this -> val = d;
            this -> next = NULL;
        }
        void push(int element, Stack* &head, Stack* &tail){

            Stack *newNode = new Stack(element);
            if( head == NULL) {
                // First Element Push
                head = newNode;
                tail = newNode;
                return;
            }
            else { 
                // Assuming Element is Present
                tail -> next = newNode;
                tail = newNode;
            }
        }
        void pop(Stack* &head, Stack* &tail){

            if( head == NULL){
                //if No Element is Present
                cout << "Stack Underflow "<<endl;
            }
            else{
                // Edge Case for Last Element
                if( head == tail){
                    head = NULL;
                    return;
                }
                Stack* temp = head;
                while( temp -> next != tail){
                    temp = temp -> next;
                }
                temp -> next = NULL;
                tail = temp;
            }
        }
        int peak(Stack* &tail){

            if( tail == NULL){
                cout << "Stack Underflow " << endl;
            }
            else{
                return tail -> val;
            }
        }
        bool isEmpty(Stack* &head){

            if( head == NULL){
                return true;
            }
            else{
                return false;
            }
        }
};
void print( Stack* &head){

    Stack* temp = head;
    if( temp == NULL) {
        cout << "Empty Stack" << endl;
        return;
    }
    while(temp != NULL){
        cout<< temp ->  val << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int main(){

    Stack *head = NULL;
    Stack *tail = NULL;

    Stack st(0);

    st.push(2, head, tail);
    st.push(4, head, tail);
    st.push(8, head, tail);
    st.push(6, head, tail);
    print(head);

    cout << "Peak element is " << st.peak(tail) << endl;
    st.pop(head, tail);
    print(head);
    
    cout<< "Peak element is "<< st.peak(tail) << endl;
    st.pop(head, tail);
    print(head);

    cout<< "Peak element is "<< st.peak(tail) << endl;
    st.pop(head, tail);
    print(head);

    cout<< "Peak element is "<< st.peak(tail) << endl;
    st.pop(head, tail);
    print(head);

    st.pop(head, tail);

    if(st.isEmpty(head)){
        cout << "Stack is empty "<<endl;
    }
    else{
        cout<< "Stack is not empty"<<endl;
    }

    return 0;
}
*/

//                          Implementing two Stacks in an Array
/*
class TwoStack {

    public:
        int *arr;
        int top1;
        int top2;
        int size;

    // Initialize TwoStack.
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    // Push in stack 1.
    void push1(int num) {

        // Atleast an Empty Space is present
        if(top2 - top1 > 1 ) {
            top1++;
            arr[top1] = num;
        } 
        else{
            cout << "stack overflow" <<endl;
        }
    }
    // Push in stack 2.
    void push2(int num) {

        if(top2 - top1 > 1 ) {
            top2--;
            arr[top2] = num;
        }
        else{
            cout << "stack overflow" <<endl;
        }
    }
    // Pop from Stack 1 and Return Popped Element.
    int pop1() {

		if( top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    // Pop from Stack 2 and Return Popped Element.
    int pop2() {

		if( top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};
int main(){

    TwoStack s(5);

    // Pushing in Stack 1
    s.push1(1);
    s.push1(2);

    // Pushing in Stack 2
    s.push2(5);
    s.push2(4);
    s.push2(3);

    // Popping in Stack 1
    cout << s.pop1() << endl;
    cout << s.pop1() << endl;

    // Popping in Stack 2
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;

    // Popping from Empty Stack
    cout << s.pop1() << endl;
    cout << s.pop2() << endl;

    return 0;
}
*/