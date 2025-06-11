#include<iostream>
#include<stack>
using namespace std;

//                            Reversing a String using Stack
/*
int main () {

    string str = "babbar";

    stack<char> s;
    for (int i = 0; i<str.length(); i++) {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while(!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout << "answer is: "<< ans << endl;

    return 0;
}
*/

//                      Deleting a Middle Element in a Stack
/*
void solve(stack<int>&inputStack, int count, int size) {

    // Base Case
    if(count == size/2) {
        inputStack.pop();
        return ;
    }
    int num = inputStack.top();
    inputStack.pop();
    
	// RECURSIVE CALL
    solve(inputStack, count+1, size);
    
    inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack, count, N);
}
int main() {

    stack<int> inputStack;
    
    // Push elements to the Stack
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);
    
    int N = inputStack.size();
    deleteMiddle(inputStack, N);
    
    // Print the stack after deletion
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    
    return 0;
}
*/

//                                  Valid Parentheses
/*
bool isValid(string s) {

    stack<char> c;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
         
        // If Opening Bracket, Stack Push
        if(ch == '(' || ch == '{' || ch == '['){
             c.push(ch);
        }
        // If Closing Bracket, Check Stack Top and Pop
        else{
            if(!c.empty()) {
                char top = c.top();
                if( (ch == ')' && top == '(') || 
                    ( ch == '}' && top == '{') || 
                    (ch == ']' && top == '[') ) {
                    c.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            } 
        }  
    }
    return c.empty();
}
int main() {

    // Test cases
    string test1 = "()";      // Valid
    string test2 = "([)]";    // Invalid
    string test3 = "{[()]}";  // Valid
    string test4 = "{[(])}";  // Invalid
    string test5 = "{[]()}";  // Valid
    string test6 = "";        // Edge case: empty string, valid

    // Check and print results
    cout << "Test case 1: " << test1 << " -> " << (isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test case 2: " << test2 << " -> " << (isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test case 3: " << test3 << " -> " << (isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test case 4: " << test4 << " -> " << (isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test case 5: " << test5 << " -> " << (isValid(test5) ? "Valid" : "Invalid") << endl;
    cout << "Test case 6: " << test6 << " -> " << (isValid(test6) ? "Valid" : "Invalid") << endl;

    return 0;
}
*/

//                  Inserting an Element at the Bottom of a Stack
/*
void solve(stack<int>& s, int x) {

    // Base Case
    if(s.empty()) {
        s.push(x);
        return ;
    }
    int num = s.top();
    s.pop();
    
    // Recursive Call
    solve(s, x);
    
    s.push(num);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) {

    solve(myStack, x);
    return myStack;
}
int main() {
    stack<int> myStack;
    
    // Push some elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    
    // Print the original stack
    cout << "Original stack: ";
    stack<int> tempStack = myStack;  // Make a temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
    
    // Push element 4 at the bottom
    myStack = pushAtBottom(myStack, 4);
    
    // Print the updated stack
    cout << "Updated stack (after pushing 4 at the bottom): ";
    tempStack = myStack;  // Use a temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
*/

//                      Reversing Stack using Recursion
/*
void insertAtBottom(stack<int> &s, int element) {

    // Base Case
    if(s.empty()) {
        s.push(element);
      	return ;
    }
    int num = s.top();
    s.pop();
    
    // Recursive Call
    insertAtBottom(s, element);
    
    s.push(num);
}
void reverseStack(stack<int> &stack) {

  	// Base Case
    if(stack.empty()) {
        return ;
    }
    int num = stack.top();
    stack.pop();
    
    // Recursive Call
    reverseStack(stack);
    
    insertAtBottom(stack,num);
}
int main() {

    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // Print original stack
    cout << "Original stack: ";
    stack<int> tempStack = myStack;  // Temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Reverse the stack
    reverseStack(myStack);

    // Print reversed stack
    cout << "Reversed stack: ";
    tempStack = myStack;  // Temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
*/

//                                  Sort a Stack
/*
void sortedInsert(stack<int> &stack, int num) {

    // Base Case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    
    // Recusrive Call
    sortedInsert(stack, num);
    
    stack.push(n);
}
void sortStack(stack<int> &stack){

	// Base Case
	if(stack.empty()) {
        return ;
    }
	int num = stack.top();
    stack.pop();
    
    // Recursive Call
	sortStack(stack);
    
	sortedInsert(stack, num);
}
int main() {

    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(3);
    myStack.push(1);
    myStack.push(4);
    myStack.push(2);
    myStack.push(5);

    // Print original stack
    cout << "Original stack: ";
    stack<int> tempStack = myStack;  // Temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    // Sort the stack
    sortStack(myStack);

    // Print the sorted stack
    cout << "Sorted stack: ";
    tempStack = myStack;  // Temporary stack for printing
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    return 0;
}
*/

//                      Redundant Brackets are Present or Not
/*
bool findRedundantBrackets(string &s){
    
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else{
            // ch ya toh ')' hai or lowercase letter
            if(ch == ')') {
                bool isRedundant = true;   
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if (isRedundant == true) {
                    return true;
                }
                st.pop();
            } 
        } 
    }
    return false;
}
int main(){

    string check1 = "(c*(a+b))";
    cout << (findRedundantBrackets(check1) ? "Yes" : "No") << endl;
    string check2 = "(())";
    cout << (findRedundantBrackets(check2) ? "Yes" : "No") << endl;

    return 0;
}
*/

//                                  Bracket Reversals 
//                         (minimum cost to make string valid)
/*
int findMinimumCost(string str) {

    // Odd Condition
    if(str.length()%2 == 1) {
        return -1;
    }
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else{
            // ch is Closed Brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    // Stack Contains Invalid Expression
    int a = 0, b = 0;
    while(!s.empty()) {
        if(s.top() == '{') {
            b++;
        }
        else{
            a++;
        }
        s.pop();
    }    
	int ans = (a+1)/2 + (b+1)/2;
    return ans;
}
int main(){

    string check1 = "{}}{}}";
    cout << findMinimumCost(check1) << endl;

    string check2 = "{{{{";
    cout << findMinimumCost(check2) << endl;

    string check3 = "{{{}}";
    cout << findMinimumCost(check3) << endl;

    string check4 = "}}}{{{";
    cout << findMinimumCost(check4) << endl;

    return 0;
}
*/