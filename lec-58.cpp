#include <iostream>
#include <cstring>
using namespace std;

//                          Implementing N-Stacks in an Array
/*
class NStack{

    int *arr;
    int *top;
    int *next;

    int n; 
    int s;
    int freespot;

    public:
        NStack(int N, int S){
            
            n = N;
            s = S;
            arr = new int[s];
            top = new int[n];
            next = new int[s];
            
            // Initialize Top
            for(int i=0; i<n; i++) {
                top[i] = -1;
            }
            // Or
            // memset(top, -1, n * sizeof(int));
            
            // Initialize Next 
            for(int i=0; i<s; i++) {
                next[i] = i+1;
            }
            // Update last index value to -1
            next[s-1] = -1;
            
            // Initialize Freespot
            freespot = 0;
        }

        // Pushes 'X' into the Mth stack. Returns true if it 
        // gets pushed into the stack, and false otherwise.
        bool push(int x, int m){

            // Check for Overflow
            if(freespot == -1) {
                return false;
            }
            // Find Index
            int index = freespot;
            
            // Insert element into array
            arr[index] = x;
            
            // Update freespot
            freespot = next[index];
        
            // Update next;
            next[index] = top[m-1];
            
            // Update top
            top[m-1] = index;
            
            return true;
        }

        // Pops top element from Mth Stack. Returns -1 if the 
        // stack is empty, otherwise returns the popped element.
        int pop(int m){

            // Check for Underflow
            if(top[m-1] == -1) {
                return -1;
            }
            // Reverse push method
            int index = top[m-1];
            
            top[m-1] = next[index];
            
            next[index] = freespot;
            
            freespot = index;
            
            return arr[index];
        }
};
int main() {

    // Create an instance of NStack with 3 stacks and total size of 10
    NStack nStack(3, 6);

    // Push elements onto different stacks
    // Push 1 onto stack 1
    cout << (nStack.push(1, 1) ? "Pushed" : "Overflow") << endl; 
    // Push 2 onto stack 1
    cout << (nStack.push(2, 1) ? "Pushed" : "Overflow") << endl; 
    // Push 3 onto stack 2
    cout << (nStack.push(3, 2) ? "Pushed" : "Overflow") << endl; 
    // Push 4 onto stack 3
    cout << (nStack.push(4, 3) ? "Pushed" : "Overflow") << endl; 
    // Push 5 onto stack 1
    cout << (nStack.push(5, 1) ? "Pushed" : "Overflow") << endl; 
    // Push 6 onto stack 2
    cout << (nStack.push(6, 2) ? "Pushed" : "Overflow") << endl; 

    // Push elements onto filled stacks
    // Push 7 onto stack 1
    cout << (nStack.push(7, 1) ? "Pushed" : "Overflow") << endl;
    // Push 8 onto stack 2
    cout << (nStack.push(8, 2) ? "Pushed" : "Overflow") << endl;
    // Push 9 onto stack 3
    cout << (nStack.push(9, 3) ? "Pushed" : "Overflow") << endl; 

    // Pop elements from stacks
    // Pop from stack 1
    cout << "Popped from stack 1: " << nStack.pop(1) << endl; 
    cout << "Popped from stack 1: " << nStack.pop(1) << endl; 
    cout << "Popped from stack 1: " << nStack.pop(1) << endl; 
    // Pop from stack 2
    cout << "Popped from stack 2: " << nStack.pop(2) << endl;
    cout << "Popped from stack 2: " << nStack.pop(2) << endl; 
    // Pop from stack 3
    cout << "Popped from stack 3: " << nStack.pop(3) << endl;

    // Pop from an empty stack (should return -1)
    // Pop from stack 1
    cout << "Popped from stack 1: " << nStack.pop(1) << endl; 
    // Pop from stack 2
    cout << "Popped from stack 2: " << nStack.pop(2) << endl; 
    // Pop from stack 3
    cout << "Popped from stack 3: " << nStack.pop(3) << endl; 

    return 0;
}
*/
