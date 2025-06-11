#include<stack>
#include<iostream>
using namespace std;

//                                      Min Stack
//                              (Special Stack Problem)
/*
class MinStack {
    public:
        stack<long long> s;
        long long mini;

        MinStack() {   
            
        }
        void push(int val) {

            if(s.empty()) {
                s.push(val);
                mini = val;
            }
            else{
                if(val < mini) {
                    s.push((long long)2*val - mini);
                    mini = val;
                }   
                else{
                    s.push(val);
                }
            }
        }
        void pop() {

            if(s.top() < mini) {
                mini = (long long)2*mini - s.top();
                s.pop();
            }
            else{
                s.pop();
            }
        }
        int top() {

            if(s.top() < mini) {
                return mini;
            }
            else{
                return s.top();
            }
        }
        int getMin() {

            return mini;
        }
        bool isEmpty() {

            return s.empty();
        }
};
int main() {

    MinStack minStack;

    // Push elements onto the stack
    minStack.push(3);
    cout << "Pushed 3" << endl;
    cout << "Current min: " << minStack.getMin() << endl;

    minStack.push(4);
    cout << "Pushed 4" << endl;
    cout << "Current min: " << minStack.getMin() << endl;

    minStack.push(2);
    cout << "Pushed 2" << endl;
    cout << "Current min: " << minStack.getMin() << endl;

    minStack.push(5);
    cout << "Pushed 5" << endl;
    cout << "Current min: " << minStack.getMin() << endl;

    // Pop elements from the stack
    cout << "Popped " << minStack.top() << endl;
    minStack.pop();
    cout << "Current min: " << minStack.getMin() << endl;

    cout << "Popped " << minStack.top() << endl;
    minStack.pop();
    cout << "Current min: " << minStack.getMin() << endl;

    cout << "Popped " << minStack.top() << endl;
    minStack.pop();
    cout << "Current min: " << minStack.getMin() << endl;

    cout << "Popped " << minStack.top() << endl;
    minStack.pop();
    cout << "Current min: " << minStack.getMin() << endl;

    // Attempt to pop from an empty stack
    if (!minStack.isEmpty()) {
        cout << "Stack is not empty. Current min: " << minStack.getMin() << endl;
    } 
    else {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
*/