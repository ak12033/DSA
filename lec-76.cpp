#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

//                                   K-th Largest Sum Subarray

//                                           Approach 1
/*
int getKthLargest(vector<int>& arr, int k) {

	priority_queue<int, vector<int>, greater<int>> mini;

	int n = arr.size();
	for(int i = 0; i<n; i++) {
		int sum = 0;
		for(int j=i; j<n; j++) {
			sum += arr[j];
			if(mini.size() < k) {
				mini.push(sum);
			}
			else {
				if(sum > mini.top()) {
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}
int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3; 
    
    // Result
    cout << "The " << k << "-th largest subarray sum is: " << getKthLargest(arr, k) << endl;
    
    return 0;
}
*/
//                                      Approach 2
/*
int getKthLargest(vector<int>& arr, int k) {

	vector<int> sumStore;
	int n = arr.size();
	for(int i=0; i<n; i++) {
		int sum = 0;
		for(int j=i; j<n; j++) {
			sum += arr[j];
            sumStore.push_back(sum);
		}         
    }
	sort(sumStore.begin(), sumStore.end());
	return sumStore[sumStore.size()-k];
}
int main() {

    vector<int> arr = {1, 2, 3, 4, 5}; 
    int k = 3;
    
    cout << "The " << k << "-th largest subarray sum is: " << getKthLargest(arr, k) << endl;
    
    return 0;
}
*/

//                                  Merge k sorted arrays
/*
class node {

    public:
        int data;
        int i;
        int j;
    
        node(int data, int row, int col) {
            this->data = data;
            i = row;
            j = col;
        }
};
class compare {

    public:
        bool operator()(node* a, node* b) {

            return a->data > b->data;
        }
};
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {

    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Saare arrays k first element insert h
    for(int i=0; i<k; i++) {
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    // Step 2:
    vector<int> ans;
    while(minHeap.size() > 0) {
        node* temp = minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();

        int i = temp->i;
        int j = temp->j;
        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }  
    return ans;
}
int main() {

    int k;
    cout << "Enter the number of sorted arrays: ";
    cin >> k;

    vector<vector<int>> kArrays(k);

    for (int i = 0; i<k; ++i) {
        int n;
        cout << "Enter the number of elements in array " << i + 1 << ": ";
        cin >> n;

        kArrays[i].resize(n);
        cout << "Enter the elements of array " << i + 1 << ": ";
        for (int j = 0; j<n; ++j) {
            cin >> kArrays[i][j];
        }
    }
    vector<int> mergedArray = mergeKSortedArrays(kArrays, k);
    cout << "Merged sorted array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                     Merge k Sorted Lists
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
class compare {

    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

    int k = lists.size();
    if(k == 0) {
        return NULL;
    }

    // Step 1:
    for(int i=0; i<k; i++) {
        if(lists[i] != NULL) {
          minHeap.push(lists[i]);
        }
    }
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(minHeap.size() > 0) {
        ListNode* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL) {
            minHeap.push(top->next);
        }
        // Answer LL is empty
        if(head == NULL) {
            head = top;
            tail = top;
        }
        // Insert at Linked list
        else {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
void printList(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main() {

    // First list: 1 -> 4 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    // Second list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // Third list: 2 -> 6 -> 8
    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);
    list3->next->next = new ListNode(8);

    // Put all lists in a vector
    vector<ListNode*> lists = {list1, list2, list3};

    // Merge the k sorted linked lists
    ListNode* mergedList = mergeKLists(lists);

    // Print the merged linked list
    cout << "Merged Sorted List: ";
    printList(mergedList);

    return 0;
}
*/