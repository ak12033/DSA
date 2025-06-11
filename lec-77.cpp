#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

//                        Smallest Range Covering Elements from K Lists
/*
class node {

    public:
        int data;
        int row;
        int col;
        
        node(int d, int r, int c) {
            data = d;
            row = r;
            col = c;
        }
};
class compare {

    public:
        bool operator()(node* a, node* b) {
            return a->data > b->data;
        }
};
vector<int> smallestRange(vector<vector<int>>& nums) {

    priority_queue <node*, vector<node*>, compare> minHeap;

    int mini = INT_MAX;
    int maxi = INT_MIN;
    int k = nums.size();

    // Step 1: Create a min heap for starting element of each list and tracking mini/maxi value 
    for(int i=0; i<k; i++) {
        int element = nums[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(nums[i][0], i, 0));
    }

    int start = mini;
    int end = maxi;

    // Process ranges
    while(!minHeap.empty()) {
        // Mini fetch
        node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        // Range or Answer Updation
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // Next element exists
        if(temp->col + 1 < nums[temp->row].size()) {
            maxi = max(maxi, nums[temp->row][temp->col + 1]);
            minHeap.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }
        else {
            break;
        }
    }
    return {start, end};
}
int main() {

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    // Result
    vector<int> result = smallestRange(nums);
    cout << "Smallest Range: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
*/

//                              Find Median from Data Stream
/*
class MedianFinder {

    public:
        priority_queue <int> maxi;
        priority_queue <int, vector<int>, greater<int>> mini;
        double median = 0;

        MedianFinder() {

        }
        int signum(int a, int b) {

            if(a == b) {
                return 0;
            }
            else if(a > b) {
                return 1;
            }
            else {
                return -1;
            }
        }
        void addNum(int num) {

            switch(signum(maxi.size(), mini.size())) {

                case 0: if(num > median) {
                            mini.push(num);
                            median = mini.top();
                        }
                        else {
                            maxi.push(num);
                            median = maxi.top();
                        }
                        break;

                case 1: if(num > median) {
                            mini.push(num);
                            median = ((double)mini.top() + (double)maxi.top())/2;
                        }
                        else {
                            mini.push(maxi.top());
                            maxi.pop();
                            maxi.push(num);
                            median = ((double)mini.top() + (double)maxi.top())/2;
                        }
                        break;

                case -1: if(num > median) {
                            maxi.push(mini.top());
                            mini.pop();
                            mini.push(num);
                            median = ((double)mini.top() + (double)maxi.top())/2;
                        }
                        else {
                            maxi.push(num);
                            median = ((double)mini.top() + (double)maxi.top())/2;
                        }
                        break;   
            }   
        }
        double getMedian() {

            return median;
        }
};
int main() {

    MedianFinder medianFinder;

    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << "Median after adding 2: " << medianFinder.getMedian() << endl;

    medianFinder.addNum(3);
    cout << "Median after adding 3: " << medianFinder.getMedian() << endl;

    return 0;
}
*/

//                                 Reorganize String
/*
class Node{

    public:
        char data;
        int count;

        Node(char c, int n) {
            data = c;
            count = n;
        }
};
class compare {

    public:
        bool operator()(Node* a, Node* b) {
            if(a->count == b->count) {
                return a->data > b->data;
            }
            return a->count < b->count;
        }
};
string reorganizeString(string s) {

    int freq[26] = {0};
    for(int i=0; i<s.size(); i++) {
        freq[s[i]-'a']++;
    }
    priority_queue <Node*, vector<Node*>, compare> maxheap;
    for(int i=0; i<26; i++) {
        if(freq[i] != 0) {
            Node* temp = new Node(i + 'a', freq[i]);
            maxheap.push(temp);
        }
    }
    string ans = "";
    while(maxheap.size() > 1) {
        Node* first = maxheap.top();
        maxheap.pop();
        Node* second = maxheap.top();
        maxheap.pop();
        ans += first->data;
        ans += second->data;
        first->count--;
        second->count--;
        if(first->count != 0) {
            maxheap.push(first);
        }
        if(second->count != 0) {
            maxheap.push(second);
        }
    }
    if(maxheap.size() == 1) {
        Node* temp = maxheap.top();
        maxheap.pop();
        if(temp->count == 1) {
            ans += temp->data;
        }
        else {
            return "";
        }
    }
    return ans;
}
int main() {

    string s = "aaabbc";
    string result = reorganizeString(s);
    
    if(result.empty()) {
        cout << "Not possible to reorganize the string" << endl;
    } 
    else {
        cout << "Reorganized string: " << result << endl;
    }
    
    return 0;
}
*/