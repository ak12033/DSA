#include <iostream>
#include<vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

//                       Function to reverse a queue using a stack
/*
queue<int> rev(queue<int> q) {

    stack<int> s;
    while (!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    while (!s.empty()) {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q; 
}
int main() {

    queue<int> originalQueue;

    originalQueue.push(1);
    originalQueue.push(2);
    originalQueue.push(3);

    // Display original queue contents
    cout << "Original Queue: ";
    queue<int> tempQueue = originalQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }
    cout << endl;

    // Reverse the queue
    queue<int> reversedQueue = rev(originalQueue);
    cout << "Reversed Queue: ";
    while (!reversedQueue.empty()) {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }
    cout << endl;

    return 0;
}
*/

//                        Function to reverse a queue using recursion
/*
void reverseQueue(queue<int>& q) {

    // Base Case
    if (q.empty()) {
        return;
    }
    // Recursive Call
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}
void displayQueue(queue<int> q) {

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    displayQueue(q);

    reverseQueue(q);
    cout << "Reversed Queue: ";
    displayQueue(q);

    return 0;
}
*/

//                       First negative number in every window of size k
/*
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {

    deque<long long int> dq;
    vector<long long> ans;
         
    // Process first window
    for(int i=0; i<K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    } 
    // Push ans for FIRST window
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }
    else {
        ans.push_back(0);
    } 
    // Now process for remaining windows
    for(int i = K; i<N; i++) {
        // First pop out of window element 
        if(!dq.empty() && (i - dq.front())>=K ) {
            dq.pop_front();
        }
        // Then push current element
        if(A[i] < 0) {
            dq.push_back(i);
        }
        // Put in ans
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
}
int main() {

    long long int n;
    cout << "Enter number of elements " << endl;
    cin >> n;

    long long int arr[n];
    cout << "Enter elements " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long int k;
    cout << "Enter window size" << endl;
    cin >> k;

    vector<long long> ans = printFirstNegativeInteger(arr, n, k);
    for (auto it : ans) cout << it << " ";
    cout << endl;

    return 0;
}
*/

//                      Reverse First K elements of Queue
/*
queue<int> modifyQueue(queue<int> q, int k) {
    
    // Step 1 : Pop first k elements from Queue and push into Stack
    stack<int> s;
    for(int i=0; i<k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    // Step 2 : Fetch from Stack and push into Queue
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    // Step 3 : Fetch first (n-k) elements from Queue and push back to Queue
    int n = q.size()-k;
    while(n--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
int main() {
    
    int n, k;
    cin >> n;
    queue<int> q;
        
    // Read elements into the queue
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }  
    cin >> k;    
    // Modify the queue as per the requirements
    queue<int> ans = modifyQueue(q, k);
        
    // Print the modified queue
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    return 0;
}
*/

//                       First non-repeating character in a stream
/*
string FirstNonRepeating(string A){

	unordered_map<char, int> m;
	string ans = "";
    queue<char> q;
		    
    for(int i = 0; i < A.length(); i++) {
        char ch = A[i];
        q.push(ch);
        m[ch]++;   
        while(!q.empty()) {
            if(m[q.front()] > 1){
                q.pop();
            }
	        else {
		        ans.push_back(q.front());
                break;
		    }
	    }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}
int main() {

	string A;
	cin >> A;
	string ans = FirstNonRepeating(A);
	cout << ans << endl;

	return 0;
}
*/

//                                  Gas Station

//                                   Approach 1
/*
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int deficit = 0;
    int balance = 0;
    int start = 0;   
    for(int i=0; i<gas.size(); i++) {
        balance += gas[i] - cost[i];
        if(balance < 0) {
            start = i+1;
            deficit += balance;
            balance = 0;
        }
    }
    if(balance + deficit >= 0){ 
        return start;
    }
    return -1;
}
int main() {
    
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    int result1 = canCompleteCircuit(gas1, cost1);
    cout << "Start Station = " << result1 << endl; // Expected output: 3
    
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    int result2 = canCompleteCircuit(gas2, cost2);
    cout << "Start Station = " << result2 << endl; // Expected output: -1

    vector<int> gas3 = {5, 8, 2, 8};
    vector<int> cost3 = {6, 5, 3, 4};
    int result3 = canCompleteCircuit(gas3, cost3);
    cout << "Start Station = " << result3 << endl; // Expected output: 1

    return 0;
}
*/
//                                    Approach 2
/*
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

    int total = 0;
    int balance = 0;
    int front = 0;
    int rear = 0;    
    for (int i = 0; i < gas.size(); i++) {
        balance += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (balance < 0) {
            front = (rear + 1) % gas.size();
            rear = front;
            balance = 0;
        } 
        else {
            rear = (rear + 1) % gas.size();
        }
    }
    if (total >= 0) {
        return front;
    } 
    else {
        return -1;
    }
}
int main() {
    
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    int result1 = canCompleteCircuit(gas1, cost1);
    cout << "Start Station = " << result1 << endl; // Expected output: 3
    
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    int result2 = canCompleteCircuit(gas2, cost2);
    cout << "Start Station = " << result2 << endl; // Expected output: -1

    vector<int> gas3 = {5, 8, 2, 8};
    vector<int> cost3 = {6, 5, 3, 4};
    int result3 = canCompleteCircuit(gas3, cost3);
    cout << "Start Station = " << result3 << endl; // Expected output: 1

    return 0;
}
*/

//                   Interleave the First Half of the Queue with Second Half

//                                       Approach 1
/*
vector<int> rearrangeQueue(queue<int> &q){

    queue<int> newQ;
    int n = q.size() / 2;
    // Step-1: Fetch first half elements from input queue and push into newQueue
    for (int i = 0; i < n; i++) {
        int val = q.front();
        q.pop();
        newQ.push(val);
    }
    // Step-2: Push alternative elements in input queue itself
    while (!newQ.empty()) {
        int val = newQ.front();
        newQ.pop();
        q.push(val);

        int val2 = q.front();
        q.pop();
        q.push(val2);
    }
    // Convert queue to vector for returning the rearranged elements
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }
    return result;
}
int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> rearranged = rearrangeQueue(q);

    cout << "Rearranged queue elements: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                      Approach 2
/*
vector<int> rearrangeQueue(queue<int> &q){

    stack<int> s;
    vector<int> result;
    
    int n = q.size()/2;
    
    // Step 1: First half of queue into stack
    for(int i=0;i<n;i++) {
        int val=q.front();
        q.pop();
        s.push(val);
    }
    // Step 2: Stack se firse queue me push kardo
    while(!s.empty()) {
        int val=s.top();
        s.pop();
        q.push(val);
    }
    // Step 3: First half of queue pop and queue me hi push 
    for(int i=0;i<n;i++) {
        int val=q.front();
        q.pop();
        q.push(val);
    }
    // Step 4: Again First half of queue into stack (Repeat step-1)
    for(int i=0;i<n;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    // Step 5: First half of queue into stack
    while(!s.empty()) {
        int val=s.top();
        s.pop();
        q.push(val);

        val=q.front();
        q.pop();
        q.push(val);
    }
    while(!q.empty()) {
        int val = q.front();
        q.pop();
        result.push_back(val);
    }
    return result;
}
int main() {

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    vector<int> rearranged = rearrangeQueue(q);

    cout << "Rearranged queue elements: ";
    for (int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                               K Queues in a Single Array
/*
class kQueue {

    public:
        int n;
        int k;
        int freeSpot;

        int *front;
        int *rear;
        int *arr;
        int *next;

    public:
        kQueue(int n, int k) {

            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    
        void enqueue(int data, int qn) {

            // Overflow
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            // Find first free index
            int index = freeSpot;

            // Update freespot
            freeSpot = next[index];

            // Check whether first element
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                // Link new element to the prev element
                next[rear[qn-1]] = index;
            }

            // Update next
            next[index] = -1;

            // Update rear
            rear[qn-1] = index;

            // Push element
            arr[index] = data;
        }
        int dequeue(int qn) {

            // Underflow 
            if(front[qn-1] == -1) {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }
            // Find index to pop
            int index = front[qn-1];

            // Front ko aage badhao
            front[qn-1] = next[index];

            // FreeSlots ko manage karo
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
};
int main() {

    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}
*/

//                Sum of minimum and maximum elements of all subarrays of size k
/*
int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of first k size window
    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // Remaining windows ko process karlo
    for(int i=k; i<n; i++) {
        // Removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();
        }
        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }
        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}
int main() {

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;

    return 0;
}
*/