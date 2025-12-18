#include <iostream>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <limits.h>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <algorithm> 
#include <numeric>
using namespace std;

//                         Longest substring consisting of only zeroes
/*
int pairpro(string s){
    int count = 0;
    int maxi = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0'){
            count++;
            maxi = max(count, maxi);
        }
        else{
            count = 0;
        }
    }
    return maxi;
}
int main() {
    string s;
    cin>>s;
    int answer = pairpro(s);
    cout<<answer<<endl;
}
*/

//                                Maximize Pair Product
/*
vector<int> maxpairsum(int n,int arr[]){
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int prod = INT_MIN;
    vector<int> answer;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==18){
                int cmaxi=max(arr[i],arr[j]);
                int cmini=min(arr[i],arr[j]);
                int currprod = cmaxi*cmini;
                if(currprod>prod){
                    prod = currprod;
                    maxi=cmaxi;
                    mini=cmini;
                    answer={maxi,mini};
                }
            }
        }
    }
    return {maxi,mini};
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> result = maxpairsum(n, arr);
    cout<<"{";
    for(int i=0;i<2;i++){
        cout<<result[i];
        if(i<1){
            cout<<",";
        }
    }
    cout<<"}";
    cout<<endl;   
}
*/

//       Check whether the product of all elements in an array is a perfect 8th power or not
/*
bool check(vector<int> &arr){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i]==2){
            count++;
        }
    }
    return (count == 0 || count % 8 == 0);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    arr.resize(n);
    cout<<"Enter 1s and 2s"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(check(arr)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
*/

//                      Print leftmost and rightmost nodes of a Binary Tree
/*
struct Node{
    int data;
    Node *left, *right;
 
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    }
};
void print(Node* root){
    // return if the tree is empty
    if (root == nullptr) {
        return;
    }
    // create an empty queue to store tree nodes
    queue<Node*> q;
    // enqueue root node
    q.push(root);
    // loop till queue is empty
    while (!q.empty()){
        // get the size of the current level
        int size = q.size();
        int n = size ;
 
        // process all nodes present in the current level
        while (n--){
            Node* node = q.front();
            q.pop(); 
            // if the corner node is found, print it
            if (n == size - 1 || n == 0) {
                cout << node->data << " ";
            }
            // enqueue left and right child of the current node
            if (node->left != nullptr) {
                q.push(node->left);
            } 
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
        // terminate level by printing an empty line
        cout << endl;
    }
}
int main(){

    // Construct the following tree
    //           1
    //          / \
    //         2   3
    //        /   / \
    //       4   5   6
    //      /   / \   \
    //     7   8   9   10
    
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(7);
    root->right->left->left = new Node(8);
    root->right->left->right = new Node(9);
    root->right->right->right = new Node(10);
 
    print(root);
 
    return 0;
}
*/

//                      Square of a number with bit manipulation 
/*
int main(){
    int n;
    cin>>n;
    n = abs(n);
    int temp_n = n;
    int pos = 0;
    int res = 0;
    while(temp_n != 0){
        if(temp_n & 1){
            res += n<<pos;
        }
        pos++;
        temp_n = temp_n>>1;
    }
    cout << res <<endl;
}
*/

//                          Adding Spaces to a String
/*
string addSpaces(string s, vector<int>& spaces) {

    string ans = "";
    int spaceIndex = 0;
    int n = spaces.size();
    for(int i=0; i<s.length(); i++){
        if(spaceIndex < n && i == spaces[spaceIndex]){
            ans.push_back(' ');
            spaceIndex++;
        }
        ans.push_back(s[i]);
    }
    return ans;
}
int main() {

    string s = "spacing";
    vector<int> spaces = {0 , 1, 2, 3, 4, 5, 6};

    string result = addSpaces(s, spaces);
    cout << "Resulting string ->" << result << endl;

    return 0;
}
*/

//                                 Unique Email Addresses
//                                      Approach 1
/*
string normalizeEmail(const string& email) {

    int at_pos = email.find('@');
    string local = email.substr(0, at_pos);
    string domain = email.substr(at_pos);

    // Remove '.' characters from the local part
    local.erase(remove(local.begin(), local.end(), '.'), local.end());

    // Remove the part after '+' in the local part (if any)
    int plus_pos = local.find('+');
    if (plus_pos != string::npos) {
        local = local.substr(0, plus_pos);
    }

    return local + domain;
}
int numUniqueEmails(const vector<string>& emails) {

    set<string> uniqueEmails;

    for (const string& email : emails) {
        string normalizedEmail = normalizeEmail(email);
        uniqueEmails.insert(normalizedEmail);
    }
    return uniqueEmails.size();
}
int main() {

    int n;
    cin >> n;  
    // Ignore newline character
    cin.ignore();  

    vector<string> emails(n);
    for (int i = 0; i < n; ++i) {
        // Read each email address
        getline(cin, emails[i]);  
    }
    cout << numUniqueEmails(emails) << endl;  // Output number of unique mailboxes

    return 0;
}
*/
//                                      Approach 2
/*
string normalizeEmail(const string& email) {

    int c = 0;
    for(int i=0; i<email.length(); i++){
        if(email[i]=='@'){
            c = i;
            break;
        }
    }
    string domain;
    for(int i=c;i<email.length();i++){
        domain.push_back(email[i]);
    }
    string local;
    for(int i=0;i<c;i++){
        if(email[i]=='+'){
            break;
        }
        else if(email[i] == '.'){
            continue;
        }
        else{
            local.push_back(email[i]);
        }
    }
    return local + domain;
}
int numUniqueEmails(const vector<string>& emails) {

    set<string> uniqueEmails;

    for (const string& email : emails) {
        string normalizedEmail = normalizeEmail(email);
        uniqueEmails.insert(normalizedEmail);
    }
    return uniqueEmails.size();
}
int main() {

    int n;
    cin >> n;  
    // Ignore newline character
    cin.ignore();  

    vector<string> emails(n);
    for (int i = 0; i < n; ++i) {
        // Read each email address
        getline(cin, emails[i]);  
    }
    cout << numUniqueEmails(emails) << endl;  // Output number of unique mailboxes

    return 0;
}
*/

//             Rearrange an array such that ‘arr[j]’ becomes ‘i’ if ‘arr[i]’ is ‘j’
/*
int main() {

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    vector<int> result(N, 0);
    for (int i=0; i<N; i++) {
        result[arr[i]] = i;
    }

    // Print the modified array
    for (int i=0; i<N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                     Number of Islands
/*
void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
      
    // Mark it visited
    vis[row][col] = 1; 

    queue <pair<int, int>> q;
    // Push the node in queue
    q.push({row, col}); 

    int n = grid.size(); 
    int m = grid[0].size(); 
    while(!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        // Traverse in the neighbours and mark them if its a land
        for(int delrow = -1; delrow <= 1; delrow++) {
            for(int delcol = -1; delcol <= 1; delcol++) {
                // Not considering diagonals
                if((delrow == -1 && delcol == 0) || (delrow == 0 && delcol == -1) || (delrow == 1 && delcol == 0) || (delrow == 0 && delcol == 1)) {
                    int nrow = row + delrow; 
                    int ncol = col + delcol;
                    // Neighbour row and column is valid, and is an unvisited land
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1; 
                        q.push({nrow, ncol}); 
                    }
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {

    int n = grid.size(); 
    int m = grid[0].size(); 

    // Create visited array and initialise to 0
    vector<vector<int>> vis(n, vector<int>(m, 0)); 

    int cnt = 0; 
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            // if not visited and is a land
            if(!vis[row][col] && grid[row][col] == '1') {
                cnt++; 
                bfs(row, col, vis, grid); 
            }
        }
    }
    return cnt;
}
int main() {

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Result
    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
*/

//                                     Rotate String
/*
bool rotateString(string s, string goal) {

    if(s.length() != goal.length()) {
        return false;
    }

    int len = goal.length();
    string temp = s + s; 
    for(int i=0; i<=temp.length() - len; i++) {
        if(temp.substr(i, len) == goal) {  
            return true;
        }
    }
    return false;
}
int main() {

    string s, goal;
    cout << "Enter the original string: ";
    cin >> s;
    cout << "Enter the rotated string to check: ";
    cin >> goal;

    if (rotateString(s, goal)) {
        cout << "true" << endl;
    } 
    else {
        cout << "false" << endl;
    }

    return 0;
}
*/

//                             Count Total Number of Colored Cells
/*
long long coloredCells(int n) {

    return 1LL + 2LL * (n - 1) * n;
}
int main() {

    int n = 5;
    cout << "Number of colored cells : " << coloredCells(n) << endl;

    return 0;
}
*/
//                                 Find Missing and Repeated Values
/*
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
    int n = grid.size();

    int total = n*n;
    vector<int> seen(total+1, 0);

    int sum = 0;
    int dupli = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n;j++) {
            if(seen[grid[i][j]]) {
                dupli = grid[i][j];
            }
            else {
                seen[grid[i][j]] = 1;
                sum += grid[i][j];
            }
        }
    }
    int miss = (total*(total+1))/2 - sum;
    return {dupli, miss};
}
int main() {

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 8}  
    };

    vector<int> result = findMissingAndRepeatedValues(grid);
    cout << "Duplicate: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
*/

//                              Apply Operations to an Array
/*
vector<int> applyOperations(vector<int>& nums) {
        
    int n = nums.size();
    for(int i=0; i < n-1; i++) {
        if(nums[i] == nums[i+1] && nums[i] != 0) {
            nums[i] <<= 1;
            nums[i+1] = 0;
            // 0 needs no operation
            i++;
        }
    }
    int j = 0;
    for(int i=0; i<n; i++) {
        if (nums[i] > 0) {
            nums[j++] = nums[i];
        }
    }
    while(j < n) {
        nums[j++] = 0;
    }
    return nums;
}
int main() {

    vector<int> nums = {2, 2, 0, 4, 4, 8};
    vector<int> result = applyOperations(nums);

    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}
*/

//                             Merge Two 2D Arrays by Summing Values
/*
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
    vector<vector<int>> result;
    
    int i = 0, j = 0;
    // Traverse both arrays with two pointers
    while(i < nums1.size() && j < nums2.size()) {
        int id1 = nums1[i][0], val1 = nums1[i][1];
        int id2 = nums2[j][0], val2 = nums2[j][1];
        // Id1 is smaller, add it to result
        if(id1 < id2) {
            result.push_back({id1, val1});
            i++;
        } 
        // Id2 is smaller, add it to result
        else if(id2 < id1) {
            result.push_back({id2, val2});
            j++;
        } 
        // Ids are equal, sum the values
        else {   
            result.push_back({id1, val1 + val2});
            i++;
            j++;
        }
    }
    // Add remaining elements from nums1, if any
    while(i < nums1.size()) {
        result.push_back(nums1[i]);
        i++;
    }
    // Add remaining elements from nums2, if any
    while(j < nums2.size()) {
        result.push_back(nums2[j]);
        j++;
    }
    return result;
}
int main() {

    vector<vector<int>> nums1 = {{1, 2}, {3, 5}, {6, 7}};
    vector<vector<int>> nums2 = {{2, 4}, {3, 6}, {6, 1}, {8, 9}};

    vector<vector<int>> merged = mergeArrays(nums1, nums2);
    for (auto& row : merged) {
        cout << "{" << row[0] << ", " << row[1] << "} ";
    }

    return 0;
}
*/

//                      Check if Number is a Sum of Powers of Three

//                                      Approach 1
/*
bool checkPowersOfThree(int n) {

    while(n > 0) {
        if(n % 3 == 2) {
            return false;
        }
        n /= 3;
    }
    return true;
}
int main() {

    int n = 10;

    if(checkPowersOfThree(n)) {
        cout<< "Yes" <<endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
*/
//                                             Approach 2
/*
bool checkPowersOfThree(int n) {

    vector<int> powers;
        
    int power = 1;
    while(power <= n) {
        powers.push_back(power);
        power *= 3;
    }

    for(int i = powers.size() - 1; i >= 0; i--) {
        if(n >= powers[i]) {
            n -= powers[i];
        }
        if(n == 0) {
            return true;
        }
    }
    return false; 
}
int main() {

    int n = 10;
    
    if(checkPowersOfThree(n)) {
        cout<< "Yes" <<endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
*/

//                             Partition Array According to Given Pivot
/*
vector<int> pivotArray(vector<int>& nums, int pivot) {

    vector<int> result;

    for(int num : nums) {
        if(num < pivot) {
            result.push_back(num);
        }
    }
    for(int num : nums) {
        if (num == pivot) {
            result.push_back(num);
        }
    }
    for(int num : nums) {
        if (num > pivot) {
            result.push_back(num);
        }
    }
    return result;
}
int main() {

    vector<int> nums = {9, 12, 5, 10, 14, 3, 10}; 
    int pivot = 10;

    vector<int> result = pivotArray(nums, pivot);
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                  Closest Prime Numbers in Range

//                                              Approach 1
/*
bool isprime(int n) {
        
    if(n == 2) {
        return true;
    }

    if(n < 2 || n % 2 == 0) {
        return false;
    }
    
    for(int i=3; i*i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}
vector<int> closestPrimes(int left, int right) {

    vector<int> primes;
    for(int i = left; i <= right; i++) {
        if(isprime(i)) {
            primes.push_back(i);
        }
    }
    if(primes.size() < 2) {
        return {-1,-1};
    }

    int mini = INT_MAX;
    int leftmini = -1;
    int rightmini = -1;
    for(int i=1; i < primes.size(); i++) {
        if(primes[i] - primes[i-1] < mini) {
            mini = primes[i] - primes[i-1];
            leftmini = primes[i-1];
            rightmini = primes[i];
        }
    }
    return{leftmini, rightmini};
}
int main() {

    int left = 10, right = 50;

    vector<int> result = closestPrimes(left, right);
    cout << "Closest prime pair between " << left << " and " << right << ": ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
*/
//                                              Approach 2
/*
vector<int> closestPrimes(int left, int right) {

    vector<bool> sieve(right + 1, true);
    sieve[0] = sieve[1] = false;
    
    for(int i = 2; i * i <= right; ++i) {
        if(sieve[i]) {
            for(int j = i * i; j <= right; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    vector<int> primes;
    for(int i = left; i <= right; i++) {
        if(sieve[i]) {
            primes.push_back(i);
        }
    }
    if(primes.size() < 2) {
        return {-1,-1};
    }

    int mini = INT_MAX;
    int leftmini = -1;
    int rightmini = -1;
    for(int i=1; i < primes.size(); i++) {
        if(primes[i] - primes[i-1] < mini) {
            mini = primes[i] - primes[i-1];
            leftmini = primes[i-1];
            rightmini = primes[i];
        }
    }
    return{leftmini, rightmini};
}
int main() {

    int left = 10, right = 50;

    vector<int> result = closestPrimes(left, right);
    cout << "Closest prime pair between " << left << " and " << right << ": ";
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
*/

//                  Minimum Recolors to Get K Consecutive Black Blocks
/*
int minimumRecolors(string blocks, int k) {

    int cnt = 0;
    int ans = INT_MAX;
    for(int i=0; i<k; i++) {
        if(blocks[i] == 'W') {
            cnt++;
        }
    }
    ans = min(ans, cnt);

    for(int i = k; i < blocks.size(); i++) {
        // Remove count of the outgoing character
        if (blocks[i - k] == 'W') {
            cnt--;
        }
        // Add count of the new incoming character
        if(blocks[i] == 'W') {
            cnt++;
        }
        ans = min(ans, cnt);
    }
    return ans;
}
int main() {

    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout << minimumRecolors(blocks, k) << endl;

    return 0;
}
*/

//                                    Alternating Groups II
/*
int numberOfAlternatingGroups(vector<int>& colors, int k) {

    int n = colors.size();

    int cnt = 1;
    int ans = 0;
    for(int i=1; i<k; i++) {
        if(colors[i] != colors[i-1]) {
            cnt++;
        }
    }
    if(cnt == k) {
        ans++;
    }

    for(int i = k; i <= n-1 + k-1; i++) {
        // Remove count of the outgoing character
        if(colors[(i - k) % n] != colors[(i-k+1) % n]) {
            cnt--;
        }
        // Add count of the new incoming character
        if(colors[i % n] != colors[(i-1) % n]) {
            cnt++;
        }
        if(cnt == k) {
            ans++;
        }
    }
    return ans;
}
int main() {

    vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    int k = 6;

    int result = numberOfAlternatingGroups(colors, k);
    cout << "Number of alternating groups of size " << k << " is: " << result << endl;

    return 0;
}
*/

//                     Count of Substrings Containing Every Vowel and K Consonants II
/*
bool isVowel(char& ch) {

    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
long long countOfSubstrings(string word, int k) {

    int n = word.length();
    unordered_map<char, int> mp;
    
    // Preprocessing to be able to find index of just next consonant
    vector<int> nextCons(n);
    int lastConsIdx = n;
    for(int i = n-1; i >= 0; i--) {
        nextCons[i] = lastConsIdx;
        if(!isVowel(word[i])) { 
            lastConsIdx = i;
        }
    }

    int left = 0;
    int right = 0;
    long long count = 0;
    int cons = 0;
    while(right < n) {
        char ch = word[right];
        if(isVowel(ch)) {
            mp[ch]++;
        } 
        else {
            cons++;
        }
        // Cons must be always == k
        while(cons > k) {
            char ch = word[left];
            if(isVowel(ch)) {
                mp[ch]--;
                if(mp[ch] == 0) {
                    mp.erase(ch);
                }
            } 
            else {
                cons--;
            }
            left++;
        }
        // Valid substring
        while(mp.size() == 5 && cons == k) {
            int idx = nextCons[right];
            count += idx - right;
            char ch = word[left];
            if(isVowel(ch)) {
                mp[ch]--;
                if(mp[ch] == 0) {
                    mp.erase(ch);
                }
            } 
            else {
                cons--;
            }
            left++;
        }
        right++;
    }
    return count;
}
int main() {

    string word = "iieaouqiieaouqq";
    int k = 1;
    cout << "Output: " << countOfSubstrings(word, k) << endl;

    return 0;
}
*/

//                  Number of Substrings Containing All Three Characters

//                                        Approach 1
/*
int numberOfSubstrings(string s) {

    unordered_map <char, int> charmap;

    int i = 0;
    int j = 0;
    int ans = 0;
    while(j<s.length()) {
        char ch = s[j];
        charmap[ch]++;
        while(charmap.size() == 3) {
            ans += s.length() - j;
            charmap[s[i]]--;
            if(charmap[s[i]] == 0) {
                charmap.erase(s[i]);
            }
            i++;
        }
        j++;
    }
    return ans;
}
int main() {

    string s = "aaaacbaac";

    int result = numberOfSubstrings(s);
    cout << "Number of substrings with at least 3 distinct characters: " << result << endl;

    return 0;
}
*/
//                                        Approach 2
/*
int numberOfSubstrings(string s) {
    
    int lastseen[3] = {-1, -1, -1};

    int n = s.length();
    int ans = 0;
    for(int i=0; i<n; i++) {
        lastseen[s[i] - 'a'] = i;
        if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
            ans += 1 + min(lastseen[0], min(lastseen[1], lastseen[2]));
        }
    }
    return ans;
}
int main() {

    string s = "aaaacbaac";

    int result = numberOfSubstrings(s);
    cout << "Number of substrings with at least 3 distinct characters: " << result << endl;

    return 0;
}
*/

//                      Maximum Count of Positive Integer and Negative Integer

//                                             Approach 1
/*
int maximumCount(vector<int>& nums) {

    int n = nums.size();

    int pos = 0;
    int neg = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] < 0) {
            neg++;
        }
        else if(nums[i] == 0) {
            continue;
        }
        else {
            pos ++;
        }
    }
    int ans = max(neg, pos);
    return ans;
}
int main() {

    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};

    int result = maximumCount(nums);
    cout << "Maximum count of positives or negatives: " << result << endl;

    return 0;
}
*/
//                                             Approach 2
/*
int maximumCount(vector<int>& nums) {

    int n = nums.size();

    int pos = 0;
    int neg = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] < 0) {
            neg++;
        }
        else if(nums[i] == 0) {
            continue;
        }
        else {
            pos += n-i;
            break;
        }
    }
    int ans = max(neg, pos);
    return ans;
}
int main() {

    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};

    int result = maximumCount(nums);
    cout << "Maximum count of positives or negatives: " << result << endl;

    return 0;
}
*/
//                                          Approach 3
/*
int maximumCount(vector<int>& nums) {

    int n = nums.size();

    // Find first positive number (index)
    int left = 0, right = n - 1;
    int firstPos = n;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] > 0) {
            firstPos = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    // Find last negative number (index)
    left = 0; right = n - 1;
    int lastNeg = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] < 0) {
            lastNeg = mid;
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    int neg = lastNeg + 1;
    int pos = n - firstPos;
    return max(neg, pos);
}
int main() {

    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};

    int result = maximumCount(nums);
    cout << "Maximum count of positives or negatives: " << result << endl;

    return 0;
}
*/

//                                        Transpose Matrix
/*
vector<vector<int>> transpose(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans(m, vector<int>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            ans[i][j] = matrix[j][i];
        }
    }
    return ans;
}
int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    cout << "Original matrix:" << endl;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose the matrix
    vector<vector<int>> transposedMatrix = transpose(matrix);
    cout << "\nTransposed matrix:" << endl;
    for (int i = 0; i < transposedMatrix.size(); i++) {
        for (int j = 0; j < transposedMatrix[0].size(); j++) {
            cout << transposedMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

//                                       Rotating the Box
/*
vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

    int n = boxGrid.size();
    int m = boxGrid[0].size();

    for(int i=0; i<n; i++) {
        // Start from the last column
        int emptySpot = m - 1; 
        for(int j = m-1; j >= 0; j--) {
            // Obstacle resets the emptySpot
            if(boxGrid[i][j] == '*') {
                emptySpot = j-1;
            } 
            else if(boxGrid[i][j] == '#') {
                if(boxGrid[i][emptySpot] == '.') {
                    swap(boxGrid[i][emptySpot], boxGrid[i][j]); 
                }
                // Move left to find the next empty spot
                emptySpot--; 
            }
        }
    }
    vector<vector<char>> ans(m, vector<char>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            ans[i][j] = boxGrid[j][i]; 
        }
        reverse(ans[i].begin(), ans[i].end());
        // Or
        // for(int j=0; j<n; j++) {
        //     ans[i][j] = boxGrid[n-1-j][i]; 
        // }  
    }
    return ans;
}
int main() {

    vector<vector<char>> boxGrid = {
        {'#', '.', '#'},
        {'#', '*', '.'},
        {'#', '.', '.'}
    };

    cout << "Original Box:\n";
    for(int i = 0; i < boxGrid.size(); i++) {
        for(int j = 0; j < boxGrid[0].size(); j++) {
            cout << boxGrid[i][j] << ' ';
        }
        cout << endl;
    }

    // Call rotateTheBox function
    vector<vector<char>> rotatedBox = rotateTheBox(boxGrid);
    cout << "\nRotated Box:\n";
    for (int i = 0; i < rotatedBox.size(); i++) {
        for (int j = 0; j < rotatedBox[0].size(); j++) {
            cout << rotatedBox[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
*/

//                                  Zero Array Transformation II

//                                         Approach 1 
//                                            (TLE)
/*
bool check(vector<int>& nums) {

    for(int num : nums) {
        if(num != 0) {
            return false;
        }
    }
    return true;
}
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

    if(check(nums)) {
        return 0;
    }

    int cnt = 0;
    for(int i=0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        int decre = queries[i][2];
        for(int j = left; j <= right; j++) {
            nums[j] = max(0, nums[j] - decre);
        }
        cnt++;
        if(check(nums)) {
            return cnt;
        }
    }
    return -1;
}
int main() {
  
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {
        {0, 2, 1}, 
        {0, 2, 1},  
        {1, 1, 3}  
    };

    int result = minZeroArray(nums, queries);
    if(result != -1) {
        cout << "Minimum number of queries to zero the array: " << result << endl;
    } 
    else {
        cout << "It's not possible to zero the array with the given queries." << endl;
    }
    return 0;
}
*/
//                                           Approach 2
//                                  (Difference Array Technique)
/*
bool check(vector<int>& nums) {

    for(int num : nums) {
        if(num != 0) {
            return false;
        }
    }
    return true;
}
bool checkWithDifferenceArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {

    int n = nums.size();
    vector<int> diff(n, 0);

    for(int i=0; i <= k; i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        int decre = queries[i][2];

        diff[left] += decre;
        if(right + 1 < n) {
            diff[right + 1] -= decre;
        }
    }
    int cumSum = 0;
    for(int i=0; i<n; i++) {
        cumSum += diff[i];
        diff[i] = cumSum;
        // nums[i] -> 0 nahi ban paya
        if(nums[i] - diff[i] > 0) { 
            return false;
        }
    }
    return true;
}
int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

    if(check(nums)) {
        return 0;
    }

    int l = 0;
    int r = queries.size()-1;
    int k = -1;
    while(l <= r) {
        int mid = l + (r-l) / 2;
        // Possible answer
        if(checkWithDifferenceArrayTeq(nums, queries, mid)) {
            k = mid+1; 
            r = mid-1;
        } 
        else {
            l = mid+1;
        }
    }
    return k;
}
int main() {
  
    vector<int> nums = {2, 0, 2};
    vector<vector<int>> queries = {
        {0, 2, 1}, 
        {0, 2, 1},  
        {1, 1, 3}  
    };

    int result = minZeroArray(nums, queries);
    if(result != -1) {
        cout << "Minimum number of queries to zero the array: " << result << endl;
    } 
    else {
        cout << "It's not possible to zero the array with the given queries." << endl;
    }
    return 0;
}
*/

//                             Maximum Candies Allocated to K Children
/*
bool possible(vector<int>& candies, long long k, int mid) {

    for(int candy : candies) 
        k -= candy / mid;
        if(k <= 0) {
            return true;
        }
    }
    return false;
}
int maximumCandies(vector<int>& candies, long long k) {

    int left = 1;
    int right = 0;
    for(int i=0; i < candies.size(); i++) {
        right = max(right, candies[i]);
    }

    int result = 0;
    while(left <= right) {
        int mid = left + (right-left) / 2;
        if(possible(candies, k, mid)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}
int main() {

    vector<int> candies = {5, 8, 6}; 
    long long k = 3;     

    int result = maximumCandies(candies, k);
    cout << "Maximum candies per child: " << result << endl;

    return 0;
}
*/

//                                    Making Triplets Equal
/*
int solve(int P, int Q, int R) {

    vector<int> arr = {P, Q, R};
    sort(arr.begin(), arr.end());

    if(arr[0] == arr [1] && arr[1] == arr[2]) {
        return 0;
    }

    int steps = 0;
    while(true) {
        arr[0]++;
        arr[1]++;
        arr[2]--;
        steps++;

        sort(arr.begin(), arr.end());

        // Possible
        if(arr[0] == arr[1] && arr[1] == arr[2]) {
            return steps;
        }
        // Not Possible
        if(((arr[0] == arr[1]) && (arr[1] + 1 == arr[2])) || ((arr[1] == arr[2]) && (arr[0] + 1 == arr[1]))){
            return -1;
        }
    }
}
int main() {

    int P, Q, R;
    cin >> P >> Q >> R;
    cout << solve(P, Q, R) << endl;

    return 0;
}
*/

//                                      House Robber IV

//                                         Recursive
/*
int solve(vector<int>& nums, int i, int k) {

    if(k == 0) {
        return 0;
    }

    // Invalid path
    if(i >= nums.size()) {
        return INT_MAX;
    }

    // Include
    int Take = max(nums[i], solve(nums, i+2, k-1));
    // Exclude
    int notTake = solve(nums, i+1, k);

    return min(Take, notTake);
}
int minCapability(vector<int>& nums, int k) {

    return solve(nums, 0, k);
}
int main() {
 
    vector<int> nums = {2, 3, 5, 9, 6};
    int k = 2;

    cout << "Test case 1: " << minCapability(nums, k) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(vector<int>& nums, int i, int k, vector<vector<int>>& dp) {

    if(k == 0) {
        return 0;
    }

    // Invalid path
    if(i >= nums.size()) {
        return INT_MAX;
    }

    if(dp[i][k] != -1){
        return dp[i][k];
    }

    // Include
    int Take = max(nums[i], solve(nums, i+2, k-1, dp));
    // Exclude
    int notTake = solve(nums, i+1, k, dp);

    dp[i][k] = min(Take, notTake);
    return dp[i][k];
}
int minCapability(vector<int>& nums, int k) {

    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    return solve(nums, 0, k, dp);
}
int main() {
 
    vector<int> nums = {2, 3, 5, 9, 6};
    int k = 2;

    cout << "Test case 1: " << minCapability(nums, k) << endl;

    return 0;
}
*/
//                                    Binary Search Approach
/*
bool isPossible(vector<int>& nums, int mid, int k) {

    int house = 0;
    for(int i=0; i < nums.size(); i++) {
        if(nums[i] <= mid) {
            house++;
            // Skip the next house
            if(house == k) {
                return true;
            }
            i++; 
        }
    }
    return false;
}
int minCapability(vector<int>& nums, int k) {

    int left = *min_element(nums.begin(), nums.end()); 
    int right = *max_element(nums.begin(), nums.end());
    
    int result  = right;
 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(isPossible(nums, mid, k)) { 
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}
int main() {
 
    vector<int> nums = {2, 3, 5, 9, 6};
    int k = 2;

    cout << "Test case 1: " << minCapability(nums, k) << endl;

    return 0;
}
*/

//                                 Minimum Time to Repair Cars
/*
bool isPossible(vector<int>& ranks, long long mid, int k) {

    long long carsFixed = 0;
    for(int i=0; i < ranks.size(); i++) {
        carsFixed += sqrt(mid/ranks[i]);
    }
    return carsFixed >= k;
}
long long repairCars(vector<int>& ranks, int cars) {
    
    long long left = 1;
    long long maxR = *max_element(ranks.begin(), ranks.end());
    long long right = maxR * cars * cars;

    long long result = -1;
    while(left <= right) {
        long long mid = left + (right - left) / 2;
        if(isPossible(ranks, mid, cars)) { 
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}
int main() {

    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;

    cout << "Minimum time needed: " << repairCars(ranks, cars) << endl;

    return 0;
}
*/

//                                Divide Array Into Equal Pairs

//                                         Approach 1
/*
bool divideArray(vector<int>& nums) {
        
    unordered_map <int, int> mp;
    for(int i=0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    for(int i=0; i < nums.size(); i++) {
        if(mp[nums[i]] % 2 != 0){
            return false;
        }
    }
    return true;
}
int main() {

    vector<int> nums1 = {3, 2, 3, 2, 2, 2};

    if(divideArray(nums1)) {
        cout << "Array can be divided into pairs of equal integers." << endl;
    } 
    else {
        cout << "Array cannot be divided into pairs of equal integers." << endl;
    }

    return 0;
}
*/
//                                         Approach 2
/*
bool divideArray(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    for(int i=1; i < nums.size(); i += 2) {
        if(nums[i] != nums[i-1]) {
            return false;
        }
    }
    return true;
}
int main() {

    vector<int> nums1 = {3, 2, 3, 2, 2, 2};

    if(divideArray(nums1)) {
        cout << "Array can be divided into pairs of equal integers." << endl;
    } 
    else {
        cout << "Array cannot be divided into pairs of equal integers." << endl;
    }

    return 0;
}
*/
//                                         Approach 3
/*
bool divideArray(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    for(int i=1; i < nums.size(); i += 2) {
        if((nums[i] ^ nums[i-1]) != 0) {
            return false;
        }
    }
    return true;
}
int main() {

    vector<int> nums1 = {3, 2, 3, 2, 2, 2};

    if(divideArray(nums1)) {
        cout << "Array can be divided into pairs of equal integers." << endl;
    } 
    else {
        cout << "Array cannot be divided into pairs of equal integers." << endl;
    }

    return 0;
}
*/

//                                     Longest Nice Subarray

//                                           Approach 1
/*
int longestNiceSubarray(vector<int>& nums) {

    int n = nums.size();

    int result = 0;
    for(int i=0; i<n; i++) {
        int mask = 0;
        for(int j=i; j<n; j++) {
            if((mask & nums[j]) != 0) {
                break;
            }
            result = max(result, j-i+1);
            mask = (mask | nums[j]);
        }
    }
    return result;
}
int main() {

    vector<int> nums = {1, 3, 8, 48, 10};

    int result = longestNiceSubarray(nums);
    cout << "The length of the longest nice subarray is: " << result << endl;

    return 0;
}
*/
//                                           Approach 2
/*
int longestNiceSubarray(vector<int>& nums) {

    int n = nums.size();

    int i = 0;
    int j = 0;

    int result = 1;
    int mask = 0;
    while(j < n) { 
        while((mask & nums[j]) != 0) { 
            mask ^= nums[i];
            i++;
        }
        result = max(result, j-i+1);
        mask |= nums[j];
        j++; 
    }
    return result;
}
int main() {

    vector<int> nums = {1, 3, 8, 48, 10};

    int result = longestNiceSubarray(nums);
    cout << "The length of the longest nice subarray is: " << result << endl;

    return 0;
}
*/

//                                    Merge Strings Alternately
/*
string mergeAlternately(string word1, string word2) {

    string ans;
    
    int i = 0;
    int j = 0;
    while(i < word1.length() && j < word2.length()) {
        ans.push_back(word1[i++]);
        ans.push_back(word2[j++]);
    }
    while(i < word1.length()){
        ans.push_back(word1[i++]);
    }
    while(j < word2.length()){
        ans.push_back(word2[j++]);
    }
    return ans;
}
int main() {

    string word1 = "abc";
    string word2 = "pqrstu";

    string result = mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;

    return 0;
}
*/

//                                       Majority Element

//                                          Approach 1
/*
int majorityElement(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());

    int n = nums.size();
    return nums[n/2];
}
int main() {

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int majority = majorityElement(nums);
    cout << "Majority element is: " << majority << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int majorityElement(vector<int>& nums) {
        
    int n = nums.size();

    unordered_map <int, int> mp;
    for(int i=0; i<n; i++) {
        mp[nums[i]]++;
    }

    for(int i=0; i<n; i++) {
        if(mp[nums[i]] > n/2){
            return nums[i];
        }
    }
    return -1;
}
int main() {

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int majority = majorityElement(nums);
    cout << "Majority element is: " << majority << endl;

    return 0;
}
*/
//                                          Approach 3
//                                    Moore Voting Algorithm
/*
int majorityElement(vector<int>& nums) {
        
    int count = 0;
    int candidate = nums[0];
    for(int num : nums) {
        if(count == 0) {
            candidate = num;
        }
        if(num == candidate) {
            count++;
        } 
        else {
            count--;
        }
    }
    return candidate;
}
int main() {

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    int majority = majorityElement(nums);
    cout << "Majority element is: " << majority << endl;

    return 0;
}
*/
//                                        Majority Element II

//                                             Approach 1
/*
vector<int> majorityElement(vector<int>& nums) {

    int n = nums.size();

    unordered_map <int, int> count;
    for(int i=0; i<n; i++) {
        count[nums[i]]++;
    }

    vector<int> result;
    for(auto num : count) {
        if(num.second > n/3) {
            result.push_back(num.first);
        }
    }
    return result;
}
int main() {

    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElement(nums);

    cout << "Majority elements (> n/3 times) are: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                             Approach 2
/*
vector<int> majorityElement(vector<int>& nums) {

    int n = nums.size();
        
    int maj1 = -1;
    int count1 = 0;
    int maj2 = -1;
    int count2 = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == maj1) {
            count1++;
        }
        else if(nums[i] == maj2) {
            count2++;
        }
        else if(count1 == 0) {
            maj1 = nums[i];
            count1 = 1;
        } 
        else if(count2 == 0) {
            maj2 = nums[i];
            count2 = 1;
        } 
        else {
            count1--;
            count2--;
        }
    }
        
    count1 = 0;
    count2 = 0;
    for(int num : nums) {
        if(num == maj1) {
            count1++;
        }
        else if(num == maj2) {
            count2++;
        }
    }
        
    vector<int> result; 
    if(count1 > n/3) {
        result.push_back(maj1);
    }
    if(count2 > n/3) {
        result.push_back(maj2);
    }
    return result;
}
int main() {

    vector<int> nums = {3, 2, 3};
    vector<int> result = majorityElement(nums);

    cout << "Majority elements (> n/3 times) are: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                          Jump Game

//                                          Recursive
/*
bool solve(vector<int>& nums, int idx) {

    // Base Case
    if(idx >= nums.size()-1) {
        return true;
    }
    for(int i=1; i <= nums[idx]; i++) {
        if(solve(nums, idx+i)) {
            return true;
        }
    }
    return false;
}
bool canJump(vector<int>& nums) {

    return solve(nums, 0);
}
int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};  
    vector<int> nums2 = {3, 2, 1, 0, 4}; 

    cout << "Can jump in nums1: " << (canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump in nums2: " << (canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
*/
//                                         Top-Down
/*
bool solve(vector<int>& nums, int idx, vector<int>& dp) {

    // Base Case
    if(idx >= nums.size()-1) {
        return true;
    }

    if(dp[idx] != -1) {
        return dp[idx];
    }

    for(int i=1; i <= nums[idx]; i++) {
        if(solve(nums, idx+i, dp)) {
            dp[idx] = true;
            return dp[idx];
        }
    }
    dp[idx] = false;
    return dp[idx];
}
bool canJump(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n, -1);

    return solve(nums, 0, dp);
}
int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};  
    vector<int> nums2 = {3, 2, 1, 0, 4}; 

    cout << "Can jump in nums1: " << (canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump in nums2: " << (canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
*/
//                                         Bottom-Up
/*
bool solve(vector<int>& nums) {

    int n = nums.size();
    vector<int> dp(n, 0);

    dp[n-1] = true;

    for(int idx = n-1; idx >= 0; idx--) {
        for(int i=1; i <= nums[idx]; i++) {
            if(idx + i < n && dp[idx+i]) {
                dp[idx] = true;
                break;
            }
        }
    }
    return dp[0];
}
bool canJump(vector<int>& nums) {

    return solve(nums);
}
int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};  
    vector<int> nums2 = {3, 2, 1, 0, 4}; 

    cout << "Can jump in nums1: " << (canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump in nums2: " << (canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
*/
//                                     Greedy Approach
/*
bool canJump(vector<int>& nums) {

    int n = nums.size();

    int finalPosition = n-1;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i] + i >= finalPosition) {
            finalPosition = i;
        }
    }
    return finalPosition == 0;
}
int main() {

    vector<int> nums1 = {2, 3, 1, 1, 4};  
    vector<int> nums2 = {3, 2, 1, 0, 4}; 

    cout << "Can jump in nums1: " << (canJump(nums1) ? "true" : "false") << endl;
    cout << "Can jump in nums2: " << (canJump(nums2) ? "true" : "false") << endl;

    return 0;
}
*/

//                                     Length of Last Word

//                                          Approach 1 
/*
int lengthOfLastWord(string s) {
    
    int start = s.length()-1;
    while(s[start] == ' ') {
        start--;
    }

    int cnt = 0;
    for(int i = start; i >= 0; i--) {
        if(s[i] != ' '){
            cnt++;
        }
        else {
            break;
        }
    }
    return cnt;
}
int main() {
   
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "singleword";
    string s5 = "      "; 
    string s6 = "";    
    
    cout << "Length of last word in: \"" << s1 << "\" is " << lengthOfLastWord(s1) << endl;
    cout << "Length of last word in: \"" << s2 << "\" is " << lengthOfLastWord(s2) << endl;
    cout << "Length of last word in: \"" << s3 << "\" is " << lengthOfLastWord(s3) << endl;
    cout << "Length of last word in: \"" << s4 << "\" is " << lengthOfLastWord(s4) << endl;
    cout << "Length of last word in: \"" << s5 << "\" is " << lengthOfLastWord(s5) << endl;
    cout << "Length of last word in: \"" << s6 << "\" is " << lengthOfLastWord(s6) << endl;

    return 0;
}
*/
//                                          Approach 2 
/*
int lengthOfLastWord(string s) {

    int cnt = 0;
    bool word = false;
    for(int i = s.length()-1; i >= 0; i--) {
        if(s[i] != ' '){
            cnt++;
            word = true;
        }
        else if(word) {
            break;
        }
    }
    return cnt;
}
int main() {
   
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "singleword";
    string s5 = "      "; 
    string s6 = "";    
    
    cout << "Length of last word in: \"" << s1 << "\" is " << lengthOfLastWord(s1) << endl;
    cout << "Length of last word in: \"" << s2 << "\" is " << lengthOfLastWord(s2) << endl;
    cout << "Length of last word in: \"" << s3 << "\" is " << lengthOfLastWord(s3) << endl;
    cout << "Length of last word in: \"" << s4 << "\" is " << lengthOfLastWord(s4) << endl;
    cout << "Length of last word in: \"" << s5 << "\" is " << lengthOfLastWord(s5) << endl;
    cout << "Length of last word in: \"" << s6 << "\" is " << lengthOfLastWord(s6) << endl;

    return 0;
}
*/

//                 Minimum Operations to Make Binary Array Elements Equal to One I

//                                          Approach 1
/*
int minOperations(vector<int>& nums) {
    
    int n = nums.size();
    
    int count = 0;
    for(int i=0; i < n-2; i++) {
        if(nums[i] == 0) {
            nums[i] ^= 1;
            nums[i+1] ^= 1;
            nums[i+2] ^= 1;
            count++;
        }
    }
    if(nums[n-2] == 1 && nums[n-1] == 1) {
        return count;
    }
    else {
        return -1;
    }
}
int main() {

    vector<int> nums = {0, 1, 1, 1, 0, 0};

    int result = minOperations(nums);
    cout << "Test case 1 result: " << result << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int minOperations(vector<int>& nums) {
    
    int flipCount = 0; 
    int result = 0; 
    for(int i=0; i < nums.size(); i++) {
        if(i >= 3 && nums[i-3] == -1) {
            flipCount--;
        }
        if(flipCount % 2 == nums[i]) {
            if(i + 3 > nums.size()) {
                return -1;
            }
            nums[i] = -1;
            flipCount++;
            result++;
        }
    }
    return result;
}
int main() {

    vector<int> nums = {0, 1, 1, 1, 0, 0};

    int result = minOperations(nums);
    cout << "Test case 1 result: " << result << endl;

    return 0;
}
*/

//                          Minimum Number of K Consecutive Bit Flips

//                                          Approach 1
/*
int minKBitFlips(vector<int>& nums, int k) {

    int flipCount = 0; 
    int result = 0; 
    for(int i=0; i < nums.size(); i++) {
        if(i >= k && nums[i-k] == -1) {
            flipCount--;
        }
        if(flipCount % 2 == nums[i]) {
            if(i + k > nums.size()) {
                return -1;
            }
            nums[i] = -1;
            flipCount++;
            result++;
        }
    }
    return result;    
}
int main() {

    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    int k = 3;
    int res = minKBitFlips(nums, k);
    cout << "Result: " << res << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int minKBitFlips(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> isFlipped(n, 0);

    int flipCount = 0; 
    int result = 0; 
    for(int i=0; i < nums.size(); i++) {
        if(i >= k && isFlipped[i-k]) {
            flipCount--;
        }
        if(flipCount % 2 == nums[i]) {
            if(i + k > nums.size()) {
                return -1;
            }
            isFlipped[i] = 1;
            flipCount++;
            result++;
        }
    }
    return result;  
}
int main() {

    vector<int> nums = {0, 0, 0, 1, 0, 1, 1, 0};
    int k = 3;
    int res = minKBitFlips(nums, k);
    cout << "Result: " << res << endl;

    return 0;
}
*/

//                             Minimum Cost Walk in Weighted Graph

//                                         Approach 1
/*
void makeSet(vector<int>& parent, vector<int>& rank, vector<int>& cost, int n) {

    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
        cost[i] = -1;
    }
}
int findParent(vector<int>& parent, int node) {

    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}
vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

    vector<int> parent(n);
    vector<int> cost(n);
    vector<int> rank(n);

    makeSet(parent, rank, cost, n);

    for (int i=0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if(u != v) {
            unionSet(u, v, parent, rank);
            cost[findParent(parent, u)] = cost[u] & cost[v];
        }
        cost[findParent(parent, u)] &= wt;
    }

    vector<int> result;
    for(int i=0; i < query.size(); i++) {
        int src = query[i][0];
        int des = query[i][1];

        if(src == des) {
            result.push_back(0);
        }
        else if(findParent(parent, src) != findParent(parent, des)) {
            result.push_back(-1);
        }
        else {
            result.push_back(cost[findParent(parent, src)]);
        }
    }
    return result;
}
int main() {

    int n = 5;  
    vector<vector<int>> edges = {
        {0, 1, 7},
        {1, 3, 7},
        {1, 2, 1}
    };
    vector<vector<int>> queries = {
        {0, 3}, 
        {3, 4}
    };

    vector<int> results = minimumCost(n, edges, queries);
    cout << "Query results:" << endl;
    for(int res : results) {
        cout << res << " ";
    }
    return 0;
}
*/
//                                         Approach 2
/*
void makeSet(vector<int>& parent, vector<int>& cost, int n) {

    for(int i=0; i<n; i++) {
        parent[i] = i;
        cost[i] = -1;
    }
}
int findParent(vector<int>& parent, int node) {

    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int>& parent) {

    parent[v] = u;
}
vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

    vector<int> parent(n);
    vector<int> cost(n);

    makeSet(parent, cost, n);

    for (int i=0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if(u != v) {
            unionSet(u, v, parent);
            cost[u] &= cost[v];
        }
        cost[u] &= wt;
    }

    vector<int> result;
    for(int i=0; i < query.size(); i++) {
        int src = query[i][0];
        int des = query[i][1];

        if(src == des) {
            result.push_back(0);
        }
        else if(findParent(parent, src) != findParent(parent, des)) {
            result.push_back(-1);
        }
        else {
            result.push_back(cost[findParent(parent, src)]);
        }
    }
    return result;
}
int main() {

    int n = 5;  
    vector<vector<int>> edges = {
        {0, 1, 7},
        {1, 3, 7},
        {1, 2, 1}
    };
    vector<vector<int>> queries = {
        {0, 3}, 
        {3, 4}
    };

    vector<int> results = minimumCost(n, edges, queries);
    cout << "Query results:" << endl;
    for(int res : results) {
        cout << res << " ";
    }
    return 0;
}
*/

//                          Find All Possible Recipes from Given Supplies

//                                             Approach 1
/*
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
    vector<string> ans;

    unordered_map <string, bool> main;
    unordered_map <string, bool> avai;

    for(int i=0; i < supplies.size(); i++) {
        avai[supplies[i]] = true;
    }

    int n = recipes.size();
    bool progress = true;

    while(progress) {
        progress = false;
        for(int i=0; i<n; i++) {
            if(main[recipes[i]]) {
                continue;
            }
            bool can_make = true;
            for(int j=0; j < ingredients[i].size(); j++) {
                if(!avai[ingredients[i][j]]) {
                    can_make = false;
                    break;
                }
            }
            if(can_make) {
                main[recipes[i]] = true;
                avai[recipes[i]] = true;
                ans.push_back(recipes[i]);
                progress = true;
            }
        }
    }
    return ans;
}
int main() {

    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {
        {"yeast", "flour"},
        {"bread", "meat"},
        {"sandwich", "meat", "bread"}
    };
    vector<string> supplies = {"yeast", "flour", "meat"};

    vector<string> result = findAllRecipes(recipes, ingredients, supplies);
    cout << "Recipes you can make:" << endl;
    for(const auto& recipe : result) {
        cout << recipe << endl;
    }
    return 0;
}
*/
//                                             Approach 2
/*
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

    int n = recipes.size();

    unordered_map <string, bool> avai;
    for(int i=0; i < supplies.size(); i++) {
        avai[supplies[i]] = true;
    }

    unordered_map <string, vector<int>> adj;
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++) {
        for(string ingr : ingredients[i]) {
            if(!avai[ingr]) {
                adj[ingr].push_back(i);
                indegree[i]++;
            }
        }
    }

    queue<int> que;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }

    vector<string> result;
    while(!que.empty()) {
        int i = que.front();
        que.pop();
        string recipe = recipes[i];
        result.push_back(recipe);
        for(auto nbr : adj[recipe]) {
            indegree[nbr]--;
            if(indegree[nbr] == 0) {
                que.push(nbr);
            }
        }
    }
    return result;
}
int main() {

    vector<string> recipes = {"bread", "sandwich", "burger"};
    vector<vector<string>> ingredients = {
        {"yeast", "flour"},
        {"bread", "meat"},
        {"sandwich", "meat", "bread"}
    };
    vector<string> supplies = {"yeast", "flour", "meat"};

    vector<string> result = findAllRecipes(recipes, ingredients, supplies);
    cout << "Recipes you can make:" << endl;
    for(const auto& recipe : result) {
        cout << recipe << endl;
    }
    return 0;
}
*/

//                               Count the Number of Complete Components

//                                             Approach 1
/*
void dfs(int i, unordered_map <int, vector<int>>& adj, vector<bool>& visited, int& v, int& e) {

    visited[i] = true;
    v++;
    e += adj[i].size();

    for(auto nbr : adj[i]) {
        if(!visited[nbr]) {
            dfs(nbr, adj, visited, v, e);
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {

    unordered_map<int, vector<int>> adj;
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    
    int result = 0;
    for(int i=0; i<n; i++) {
        if(visited[i] == true) {
            continue;
        }
        int v = 0;
        int e = 0;
        dfs(i, adj, visited, v, e);
        if((v*(v-1)) == e) {
            result++;
        }
    }
    return result;
}
int main() {
   
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4}
    };

    int result = countCompleteComponents(n, edges);
    cout << "Number of complete components: " << result << endl; 

    return 0;
}
*/
//                                             Approach 2
/*
void bfs(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& v, int &e) {

    visited[i] = true;

    queue<int> que;
    que.push(i);
    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        v++;
        e += adj[curr].size();
        for(int &nbr : adj[curr]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                que.push(nbr);
            }
        }
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {

    unordered_map<int, vector<int>> adj;
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    
    int result = 0;
    for(int i=0; i<n; i++) {
        if(visited[i] == true) {
            continue;
        }
        int v = 0;
        int e = 0;
        bfs(i, adj, visited, v, e);
        if((v*(v-1)) == e) {
            result++;
        }
    }
    return result;
}
int main() {
   
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4}
    };

    int result = countCompleteComponents(n, edges);
    cout << "Number of complete components: " << result << endl; 

    return 0;
}
*/
//                                             Approach 3
/*
int findParent(vector<int>& parent, int node) {

    if(parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int>& parent, vector<int>& size) {

    u = findParent(parent, u);
    v = findParent(parent, v);

    if(u == v) {
        return;
    }
    if(size[u] < size[v]) {
        parent[u] = v;
        size[v] += size[u];
    }
    else if(size[u] > size[v]) {
        parent[v] = u;
        size[u] += size[v];
    }
    else {
        parent[v] = u;
        size[u] += size[v];
    }
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {

    vector<int> parent(n);
    vector<int> size(n);
    for(int i=0; i<n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    unordered_map <int, int> mp;
    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        unionSet(u, v, parent, size);
    }

    // Count the edges for each root
    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int root = findParent(parent, u);
        mp[root]++; 
    }

    int result = 0;
    for(int i=0; i<n; i++) {
        if(findParent(parent, i) == i) {
            int v = size[i];
            int e = mp[i];
            if((v * (v-1)) / 2 == e) {
                result++;
            }
        }
    }
    return result;
}
int main() {
   
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {3, 4}
    };

    int result = countCompleteComponents(n, edges);
    cout << "Number of complete components: " << result << endl; 

    return 0;
}
*/

//                             Number of Ways to Arrive at Destination

//                                            Approach 1
/*
struct Compare {
    bool operator()(pair<long long, int>& a, pair<long long, int>& b) {

        return a.first > b.first; 
    }
};
int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>>& roads) {

    unordered_map <int, vector<pair<int, long long>>> adj;
    for(int i=0; i < roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int time = roads[i][2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    priority_queue <pair<long long, int>, vector<pair<long long, int>>, Compare> pq;
    vector<long long> result(n, LLONG_MAX);
    vector<int> pathCount(n, 0);
    result[0] = 0;
    pathCount[0] = 1;

    pq.push({0, 0});
    while(!pq.empty()) {
        long long currTime = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        if(currTime > result[currNode]) {
            continue;
        }
        for(auto neighbour : adj[currNode]) {
            int nbr = neighbour.first;
            int roadTime = neighbour.second;
            if(currTime + roadTime < result[nbr]) {
                result[nbr] = currTime + roadTime;
                pathCount[nbr] = pathCount[currNode];
                pq.push({result[nbr], nbr});
            } 
            else if(currTime + roadTime == result[nbr]) {
                pathCount[nbr] = (pathCount[nbr] + pathCount[currNode]) % mod;
            }
        }
    }
    return pathCount[n-1];
}
int main() {
    
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    int result = countPaths(n, roads);
    cout << "Number of shortest paths from node 0 to node " << n - 1 << " is: " << result << endl;

    return 0;
}
*/
//                                            Approach 2
/*
int mod = 1e9 + 7;
int countPaths(int n, vector<vector<int>>& roads) {
    
    unordered_map <int, vector<pair<int, long long>>> adj;
    for(int i=0; i < roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int time = roads[i][2];
        adj[u].push_back({v, time});
        adj[v].push_back({u, time});
    }

    vector<long long> dist(n, LLONG_MAX);
    vector<int> pathCount(n, 0);
    dist[0] = 0;
    pathCount[0] = 1;

    set <pair<long long, int>> st;

    st.insert(make_pair(0, 0));
    while(!st.empty()) {   
        // Fetch top record
        auto top = *(st.begin());
        long long currTime = top.first;
        int currNode = top.second;
        st.erase(st.begin());
        for(auto neighbour : adj[currNode]) {
            if(currTime + neighbour.second < dist[neighbour.first]) {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // If record found, then erase it
                if(record != st.end()) {
                    st.erase(record);
                }
                // Distance update
                dist[neighbour.first] = currTime + neighbour.second;
                pathCount[neighbour.first] = pathCount[currNode];
                // Record push in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));      
            }
            else if(currTime + neighbour.second == dist[neighbour.first]) {
                pathCount[neighbour.first] = (pathCount[neighbour.first] + pathCount[currNode]) % mod;
        }
        }
    }
    return pathCount[n-1];
}
int main() {
    
    int n = 7;
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    int result = countPaths(n, roads);
    cout << "Number of shortest paths from node 0 to node " << n - 1 << " is: " << result << endl;

    return 0;
}
*/

//                                  Count Days Without Meetings
/*
int countDays(int days, vector<vector<int>>& meetings) {

    sort(meetings.begin(), meetings.end());

    int result = 0;
    int start = 0;
    int end = 0;
    for(int i=0; i < meetings.size(); i++) {
        if(meetings[i][0] > end) {
            result += meetings[i][0] - end - 1;
        }
        end = max(end, meetings[i][1]);
    }
    if(days > end) {
        result += days-end;
    }
    return result;
}
int main() {

    int days = 10;
    vector<vector<int>> meetings = {
        {5, 7},
        {1, 3},
        {9, 10}
    };

    int freeDays = countDays(days, meetings);
    cout << "Number of free days: " << freeDays << endl;

    return 0;
}
*/

//                                       Merge Intervals
/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(begin(intervals), end(intervals));
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for(int i=1; i < intervals.size(); i++) {
        // Overlap
        if(intervals[i][0] <= result.back()[1]) {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } 
        // No Overlap
        else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main() {

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    cout << "Original Intervals:" << endl;
    for(auto interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> mergedIntervals = merge(intervals);
    cout << "Merged Intervals:" << endl;
    for(auto interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
*/

//                         Check if Grid can be Cut into Sections
/*
vector<vector<int>> merge(vector<vector<int>>& intervals) {

    sort(begin(intervals), end(intervals));
    
    vector<vector<int>> result;
    result.push_back(intervals[0]);

    for(int i=1; i < intervals.size(); i++) {
        // Overlap
        if(intervals[i][0] < result.back()[1]) {
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        } 
        // No Overlap
        else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
    // X-axis
    vector<vector<int>> hor;
    // Y-aixs
    vector<vector<int>> vert;

    for(int i=0; i < rectangles.size(); i++) {
        int x1 = rectangles[i][0];
        int y1 = rectangles[i][1];
        int x2 = rectangles[i][2];
        int y2 = rectangles[i][3];

        hor.push_back({x1, x2});
        vert.push_back({y1, y2});
    }

    vector<vector<int>> result1 = merge(hor);
    if(result1.size() >= 3) {
        return true;
    }
    vector<vector<int>> result2 = merge(vert);
    return result2.size() >= 3;
}
int main() {

    vector<vector<int>> rectangles = {
        {1, 0, 5, 2},
        {0, 2, 2, 4},
        {3, 2, 5, 3},
        {0, 4, 4, 5} 
    };
    int n = 5;

    if(checkValidCuts(n, rectangles)) {
        cout << "There are at least 3 valid non-overlapping cuts." << endl;
    } 
    else {
        cout << "Not enough valid cuts." << endl;
    }
    return 0;
}
*/

//                          Minimum Operations to Make a Uni-Value Grid
/*
int minOperations(vector<vector<int>>& grid, int x) {

    vector<int> arr;

    int m = grid.size();
    int n = grid[0].size();
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++){
            arr.push_back(grid[i][j]);
        }
    }
    
    sort(arr.begin(), arr.end());
    int target = arr[arr.size() / 2];

    int result = 0;
    for(int i=0; i < arr.size(); i++){
        int diff = abs(target - arr[i]);
        if(diff % x != 0) {
            return -1;
        }
        result += diff / x;
    }
    return result;
}
int main() {

    vector<vector<int>> grid = {
        {2, 4}, 
        {6, 8}
    };
    int x = 2;
    
    int result = minOperations(grid, x);
    cout << "Minimum operations: " << result << endl;
    
    return 0;
}
*/

//                                    Trapping Rain Water
/*
int trap(vector<int>& height) {

    int i = 0;
    int j = height.size()-1;
    int left_max = height[0];
    int right_max = height[j];
    
    int sum = 0;
    while(i < j) {
        if(left_max <= right_max) {
            i++;
            left_max = max(left_max, height[i]);
            sum += left_max - height[i];
        }
        else {
            j--;
            right_max = max(right_max, height[j]);
            sum += right_max - height[j];
        }
    }
    return sum;   
}
int main() {

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Rain Water: " << trap(height) << endl;

    return 0;
}
*/

//                 Minimum Difference Between Largest and Smallest Value in Three Moves
/*
int minDifference(vector<int>& nums) {

    int n = nums.size();
    if(n < 5) {
        return 0;
    }
    
    sort(nums.begin(),nums.end());

    int first = nums[n-1] - nums[3];
    int second = nums[n-2] - nums[2];
    int third = nums[n-3] - nums[1];
    int fourth = nums[n-4] - nums[0];
    
    int result = min(first, min(second, min(third, fourth)));
    return result;
}
int main() {

    vector<int> nums = {1, 5, 0, 10, 14};
    cout << "Min Difference: " << minDifference(nums) << endl;

    return 0;
}
*/

//                          Maximum Difference Between Increasing Elements
/*
int maximumDifference(vector<int>& nums) {

    int mini = nums[0];
    int ans = -1;
    for(int i=1; i < nums.size(); i++) {
        if(nums[i] > mini) {
            ans = max(ans, nums[i] - mini);
        }
        else {
            mini = nums[i];
        }
    }
    return ans;
}
int main() {

    vector<int> nums = {7, 1, 5, 4}; 
    cout << "Maximum Difference: " << maximumDifference(nums) << endl;
    
    return 0;
}
*/

//                      Find the Index of the First Occurrence in a String

//                                         Approach 1
/*
int strStr(string haystack, string needle) {

    if(needle.length() > haystack.length()) {
        return -1;
    }

    for(int i=0; i <= haystack.length() - needle.length(); i++) {
        if(haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }
    return -1;
}
int main() {

    string haystack = "hello", needle = "ll";
    cout << "First Occurrence is at : " << strStr(haystack, needle) << endl;

    return 0;
}
*/
//                                         Approach 2
/*
int strStr(string haystack, string needle) {

    if(needle.length() > haystack.length()) {
        return -1;
    }

    for(int i=0; i <= haystack.length() - needle.length(); i++) {
        int j = 0;
        while(j < needle.length() && haystack[i + j] == needle[j]) {
            j++;
        }
        // Found match at position i
        if(j == needle.length()) {
            return i; 
        }
    }
    return -1;
}
int main() {

    string haystack = "hello", needle = "ll";
    cout << "First Occurrence is at : " << strStr(haystack, needle) << endl;

    return 0;
}
*/

//                                    Minimum Index of a Valid Split

//                                              Approach 1
/*
int minimumIndex(vector<int>& nums) {

    int n = nums.size();

    unordered_map <int, int> mp1;
    unordered_map <int, int> mp2; 
    for(int num : nums) {
        mp2[num]++;
    }

    for(int i=0; i<n; i++) {
        int num = nums[i];
        mp1[num]++;
        mp2[num]--;

        int n1 = i+1;
        int n2 = n-i-1;
        if(mp1[num] > n1/2 && mp2[num] > n2/2) {
            return i;
        }
    }
    return -1;
}
int main() {

    vector<int> nums = {1, 2, 2, 2, 3, 2, 2};
    cout << "Index is : " << minimumIndex(nums) << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int minimumIndex(vector<int>& nums) {

    int n = nums.size();

    // Step 1: Find the dominant element using Boyer-Moore Majority Vote
    int candidate = -1;
    int count = 0;
    for(int num : nums) {
        if(count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Step 2: Check if it is actually the dominant element
    int total_count = 0;
    for(int num : nums) {
        if(num == candidate) {
            total_count++;
        }
    }

    // No dominant element
    if(total_count <= n/2) {
        return -1; 
    }

    // Step 3: Find the minimum index where it is dominant on both sides
    int left_count = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == candidate) {
            left_count++;
        }
        int right_count = total_count - left_count;
        if(left_count > (i+1)/2 && right_count > (n-i-1)/2) {
            return i;
        }
    }
    return -1;
}
int main() {

    vector<int> nums = {1, 2, 2, 2, 3, 2, 2};
    cout << "Index is : " << minimumIndex(nums) << endl;

    return 0;
}
*/

//                             Maximum Number of Points From Grid Queries

//                                             Approach 1
/*
int solve(int x, int y, vector<vector<int>>& grid, int num, int m, int n, vector<vector<bool>>& visited) {

    if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || grid[x][y] >= num) {
        return 0;
    }

    visited[x][y] = true; 
    int cnt = 1;

    // Left
    cnt += solve(x, y-1, grid, num, m, n, visited); 
    // Right
    cnt += solve(x, y+1, grid, num, m, n, visited); 
    // Up
    cnt += solve(x-1, y, grid, num, m, n, visited); 
    // Down
    cnt += solve(x+1, y, grid, num, m, n, visited); 

    return cnt;
}
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

    int m = grid.size();
    int n = grid[0].size();

    vector<int> result;
    for(int i=0; i < queries.size(); i++) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = solve(0, 0, grid, queries[i], m, n, visited);
        result.push_back(ans);
    }
    return result;
}
int main() {

    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 5, 7},
        {3, 5, 1}
    };
    vector<int> queries = {5, 6, 2};

    vector<int> result = maxPoints(grid, queries);
    cout << "Results for queries: ";
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                             Approach 2
/*
vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int m = grid.size();
    int n = grid[0].size();

    int Q = queries.size();
    vector<int> result(Q, 0);

    vector<pair<int, int>> sortedQ;
    for(int i=0; i<Q; i++) {
        sortedQ.push_back({queries[i], i});
    }
    sort(begin(sortedQ), end(sortedQ));

    priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    pq.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    int points = 0;
    for(int i=0; i<Q; i++) {
        int queryValue = sortedQ[i].first;
        int idx = sortedQ[i].second;
        while(!pq.empty() && pq.top()[0] < queryValue) {
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            points++;
            for(auto dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_]) {
                    pq.push({grid[i_][j_], i_, j_});
                    visited[i_][j_] = true;
                }
            }
        }
        result[idx] = points;
    }    
    return result;
}
int main() {

    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 5, 7},
        {3, 5, 1}
    };
    vector<int> queries = {5, 6, 2};

    vector<int> result = maxPoints(grid, queries);
    cout << "Results for queries: ";
    for(int res : result) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                        Partition Labels

//                                           Approach 1
/*
vector<int> partitionLabels(string s) {

    vector<int> result;

    vector<int> mp(26, -1);
    for(int i=0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        mp[idx] = i;
    }

    int i = 0;
    while(i < s.length()) {
        int end = mp[s[i] - 'a'];
        int j = i;
        while(j < end) {
            end = max(end, mp[s[j] - 'a']);
            j++;
        }
        result.push_back(j - i + 1);
        i = j + 1;
    }
    return result;
}
int main() {

    string s = "ababcbacadefegdehijhklij";

    vector<int> partitions = partitionLabels(s);
    cout << "Partition sizes: ";
    for(int size : partitions) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                           Approach 2
/*
vector<int> partitionLabels(string s) {

    vector<int> result;

    vector<int> mp(26, -1);
    for(int i=0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        mp[idx] = i;
    }

    int i = 0;
    int start = 0;
    int end = 0;
    while(i < s.length()) {
        end = max(end, mp[s[i] - 'a']);
        if(i == end) {
            result.push_back(end - start + 1);
            start = end + 1;
        }
        i++;
    }
    return result;
}
int main() {

    string s = "ababcbacadefegdehijhklij";

    vector<int> partitions = partitionLabels(s);
    cout << "Partition sizes: ";
    for(int size : partitions) {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                      Put Marbles in Bags
/*
long long putMarbles(vector<int>& weights, int k) {

    int n = weights.size();
    
    vector<int> pairSum(n-1, 0);
    for(int i=0; i < n-1; i++) {
        pairSum[i] = weights[i] + weights[i+1];
    }
    
    sort(begin(pairSum), end(pairSum));

    long long maxSum = 0;
    long long minSum = 0;
    for(int i=0; i < k-1; i++) {
        minSum += pairSum[i];
        maxSum += pairSum[n-i-2];
    }
    return maxSum - minSum;
}
int main() {

    vector<int> weights = {1, 3, 5, 1};
    int k = 2;

    long long result = putMarbles(weights, k);
    cout << "Result: " << result << endl;

    return 0;
}
*/

//                                        Array Partition
/*
int arrayPairSum(vector<int>& nums) {

    sort(begin(nums), end(nums));

    int sum = 0;
    for(int i=0; i<nums.size(); i=i+2) {
        sum += nums[i];
    }
    return sum;
}
int main() {

    vector<int> nums = {1, 4, 3, 2};
    cout << "Maximized Sum: " << arrayPairSum(nums) << endl;

    return 0;
}
*/

//                               Minimize Maximum Pair Sum in Array
/*
int minPairSum(vector<int>& nums) {
        
    sort(begin(nums), end(nums));

    int result = 0;
    
    int i = 0;
    int j = nums.size() - 1;
    while(i < j) {
        int sum = nums[i] + nums[j];
        result = max(result, sum);
        i++;
        j--;
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 3};
    cout << "Minimized Maximum Pair Sum: " << minPairSum(nums) << endl;

    return 0;
}
*/

//                                     Boats to Save People
/*
int numRescueBoats(vector<int>& people, int limit) {

    sort(people.begin(),people.end());
    
    int i = 0;
    int j = people.size() - 1;

    int boats = 0;
    while(i <= j) {
        if(people[i] + people[j] <= limit) {
            i++;
        }
        j--;
        boats++;
    }
    return boats;
}
int main() {

    vector<int> people = {3, 2, 2, 1};
    int limit = 3;

    cout << "Minimum boats required: " << numRescueBoats(people, limit) << endl;

    return 0;
}
*/

//                                 Find the Value of the Partition
/*
int findValueOfPartition(vector<int>& nums) {

    sort(begin(nums), end(nums));

    int mini = INT_MAX;
    for(int i=1; i < nums.size(); i++) {
        mini = min(mini, nums[i] - nums[i-1]); 
    }
    return mini;
}
int main() {

    vector<int> nums = {1, 5, 3, 19, 18, 25};
    cout << "Minimum Partition Value: " << findValueOfPartition(nums) << endl;

    return 0;
}
*/

//                              Solving Questions With Brainpower

//                                          Recursive
/*
long long solve(int i, vector<vector<int>>& questions) {
        
    // Base Case
    if(i >= questions.size()) {
        return 0;
    }
    
    long long taken = questions[i][0] + solve(i + questions[i][1] + 1, questions);
    long long not_taken = solve(i+1, questions);
    
    return max(taken, not_taken);
    
}
long long mostPoints(vector<vector<int>>& questions) {

    return solve(0, questions);
}
int main() {

    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << "Maximum points that can be obtained: " << mostPoints(questions) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
long long solve(int i, vector<vector<int>>& questions, vector<long long>& dp) {
        
    // Base Case
    if(i >= questions.size()) {
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }
    
    long long taken = questions[i][0] + solve(i + questions[i][1] + 1, questions, dp);
    long long not_taken = solve(i+1, questions, dp);
    
    return dp[i] = max(taken, not_taken);
    
}
long long mostPoints(vector<vector<int>>& questions) {

    int n = questions.size();
    vector<long long> dp(n, -1);

    return solve(0, questions, dp);
}
int main() {

    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << "Maximum points that can be obtained: " << mostPoints(questions) << endl;

    return 0;
}
*/
//                                          Bottom-Up
/*
long long solve(vector<vector<int>>& questions) {

    int n = questions.size();
    vector<long long> dp(n+1, 0);

    for(int i = n-1; i >= 0; i--) {
        long long taken = questions[i][0];
        if(i + questions[i][1] + 1 < n){
            taken += dp[i + questions[i][1] + 1];
        }
        long long not_taken = dp[i+1];
    
        dp[i] = max(taken, not_taken);
    }
    return dp[0];
}
long long mostPoints(vector<vector<int>>& questions) {

    return solve(questions);
}
int main() {

    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << "Maximum points that can be obtained: " << mostPoints(questions) << endl;

    return 0;
}
*/

//                           Maximum Value of an Ordered Triplet I

//                                         Approach 1
/*
long long maximumTripletValue(vector<int>& nums) {

    int n = nums.size();

    long long result = 0;
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            for(int k = j+1; k<n; k++) {
                result = max(result, (long long)(nums[i] - nums[j]) * nums[k]);
            }
        }
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 8, 7}; 
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}
*/
//                                         Approach 2
/*
long long maximumTripletValue(vector<int>& nums) {

    int n = nums.size();

    vector<int> leftMax(n);
    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], nums[i-1]);
    }

    vector<int> rightMax(n);
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], nums[i+1]);
    }

    long long result = 0;
    for(int j=1; j < n-1; j++) {
        result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 8, 7}; 
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}
*/
//                                         Approach 3
/*
long long maximumTripletValue(vector<int>& nums) {

    int n = nums.size();

    long long result = 0;
    long long maxDiff = 0;
    long long maxi = 0;
    for(int k=0; k<n; k++) {
        result = max(result, maxDiff * nums[k]);
        maxDiff = max(maxDiff, maxi - nums[k]);
        maxi = max(maxi, (long long)nums[k]);
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 8, 7}; 
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}
*/

//                           Maximum Value of an Ordered Triplet II

//                                         Approach 1
/*
long long maximumTripletValue(vector<int>& nums) {

    int n = nums.size();

    vector<int> leftMax(n);
    for(int i=1; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], nums[i-1]);
    }

    vector<int> rightMax(n);
    for(int i = n-2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i+1], nums[i+1]);
    }

    long long result = 0;
    for(int j=1; j < n-1; j++) {
        result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 8, 7}; 
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}
*/
//                                         Approach 2
/*
long long maximumTripletValue(vector<int>& nums) {

    int n = nums.size();

    long long result = 0;
    long long maxDiff = 0;
    long long maxi = 0;
    for(int k=0; k<n; k++) {
        result = max(result, maxDiff * nums[k]);
        maxDiff = max(maxDiff, maxi - nums[k]);
        maxi = max(maxi, (long long)nums[k]);
    }
    return result;
}
int main() {

    vector<int> nums = {3, 5, 2, 8, 7}; 
    cout << "Maximum Triplet Value: " << maximumTripletValue(nums) << endl;

    return 0;
}
*/

//                                      Zigzag Conversion
/*
string convert(string s, int numRows) {

    if(numRows == 1 || numRows >= s.length()) {
        return s;
    }
    
    vector<vector<char>> grid(numRows);

    int idx = 0;
    int d = 1;
    for(char c : s) {
        grid[idx].push_back(c);
        if(idx == 0) {
            d = 1;
        } 
        else if(idx == numRows - 1) {
            d = -1;
        }
        idx += d;
    }

    string result;
    for(auto row : grid) {
        for(char c : row) {
            result += c;
        }
    }
    return result;        
}
int main() {

    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << convert(s, numRows) << endl; 

    return 0;
}
*/

//                            Lowest Common Ancestor of Deepest Leaves

//                                             Approach 1
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
TreeNode* LCA(TreeNode* root, unordered_map <int, int>& mp, int maxDepth) {

    if(root == NULL || mp[root->val] == maxDepth) {
        return root;
    }

    TreeNode* left = LCA(root->left, mp, maxDepth);
    TreeNode* right = LCA(root->right, mp, maxDepth);

    if(left && right) {
        return root;
    }

    return left != NULL ? left : right;
}
void depth(TreeNode* root, int d, unordered_map <int, int>& mp, int& maxDepth) {

    if(!root) {
        return;
    }

    maxDepth = max(maxDepth, d);
    mp[root->val] = d;

    depth(root->left, d+1, mp, maxDepth);
    depth(root->right, d+1, mp, maxDepth);
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {

    unordered_map<int, int> mp;
    int maxDepth = 0;

    depth(root, 0, mp, maxDepth);
    return LCA(root, mp, maxDepth);
}
int main() {
    
    //       3
    //     /   \
    //    5     1
    //   / \   / \
    //  6   2 0   8
    //     / \
    //    7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* lca = lcaDeepestLeaves(root);
    if(lca) {
        cout << "LCA of deepest leaves: " << lca->val << endl;
    } 
    else {
        cout << "Tree is empty or has no deepest leaves." << endl;
    }
    return 0;
}
*/
//                                             Approach 2
/*
class TreeNode {

    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int x) : val(x), left(NULL), right(NULL) {

        }
};
pair<int, TreeNode*> solve(TreeNode* root) {

    if(root == NULL) {
        return {0, NULL};
    }

    auto left = solve(root->left);
    auto right = solve(root->right);

    if(left.first == right.first) {
        return {left.first + 1, root};
    } 
    else if(left.first > right.first) {
        return {left.first + 1, left.second};
    } 
    else {
        return {right.first + 1, right.second};
    }
}
TreeNode* lcaDeepestLeaves(TreeNode* root) {

    return solve(root).second; 
}
int main() {
    
    //       3
    //     /   \
    //    5     1
    //   / \   / \
    //  6   2 0   8
    //     / \
    //    7   4

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* lca = lcaDeepestLeaves(root);
    if(lca) {
        cout << "LCA of deepest leaves: " << lca->val << endl;
    } 
    else {
        cout << "Tree is empty or has no deepest leaves." << endl;
    }
    return 0;
}
*/

//                                Sum of All Subset XOR Totals

//                                         Approach 1
/*
void solve(vector<int>& nums, int i, vector<int>& currSubset, vector<vector<int>>& subsets) {

    if(i == nums.size()) {
        subsets.push_back(currSubset);
        return;
    }

    currSubset.push_back(nums[i]);
    solve(nums, i + 1, currSubset, subsets);
    currSubset.pop_back();
    solve(nums, i + 1, currSubset, subsets);
}
int subsetXORSum(vector<int>& nums) {

    vector<vector<int>> subsets;
    vector<int> currSubset;
    solve(nums, 0, currSubset, subsets);

    int result = 0;
    for(auto currSubset : subsets) {
        int Xor = 0;
        for(int num : currSubset) {
            Xor ^= num;
        }
        result += Xor;
    }
    return result;
}
int main() {

    vector<int> nums = {1, 3};

    int result = subsetXORSum(nums);
    cout << "Sum of XOR of all subsets: " << result << endl;

    return 0;
}
*/
//                                         Approach 2
/*
int solve(int i, vector<int>& nums, int Xor) {

    if(i == nums.size()) {
        return Xor;
    }

    int include = solve(i+1, nums, nums[i] ^ Xor);
    int exclude = solve(i+1, nums, Xor);

    return include + exclude;
}
int subsetXORSum(vector<int>& nums) {

    return solve(0, nums, 0);
}
int main() {

    vector<int> nums = {1, 3};

    int result = subsetXORSum(nums);
    cout << "Sum of XOR of all subsets: " << result << endl;

    return 0;
}
*/
//                                         Approach 3
/*
int subsetXORSum(vector<int>& nums) {

    int n = nums.size();

    int result = 0;
    for(int num : nums) {
        result |= num;
    }
    return result << (n-1);
}
int main() {

    vector<int> nums = {1, 3};

    int result = subsetXORSum(nums);
    cout << "Sum of XOR of all subsets: " << result << endl;

    return 0;
}
*/

//                                  Largest Divisible Subset

//                                          Recursive
/*
void solve(int idx, vector<int>& nums, vector<int>& result, vector<int>& temp, int prev) {

    if(idx >= nums.size()) {
        if(temp.size() > result.size()) {
            result = temp;
        }
        return;
    }
    
    if(prev == -1 || nums[idx] % prev == 0) {
        temp.push_back(nums[idx]);
        solve(idx+1, nums, result, temp, nums[idx]);
        temp.pop_back();
    }
    solve(idx+1, nums, result, temp, prev);
}
vector<int> largestDivisibleSubset(vector<int>& nums) {

    sort(begin(nums), end(nums));
    
    vector<int> result;
    vector<int> temp;
    solve(0, nums, result, temp, -1);

    return result;
}
int main() {

    vector<int> nums = {1, 2, 4, 8};
    vector<int> result = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                         Approach-2
/*
vector<int> largestDivisibleSubset(vector<int>& nums) {

    sort(begin(nums), end(nums));

    int n = nums.size();
    vector<int> t(n, 1);

    vector<int> prev_idx(n, -1);
    int last_chosen_index = 0;
    int maxL = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] % nums[j] == 0) {
                if(t[i] < t[j] + 1) {
                    t[i] = t[j] + 1;
                    prev_idx[i] = j;
                }
                if(t[i] > maxL) {
                    maxL = t[i];
                    last_chosen_index = i;
                }
            }
        }
    }
    vector<int> result;
    while(last_chosen_index >= 0) {
        result.push_back(nums[last_chosen_index]);
        last_chosen_index = prev_idx[last_chosen_index];
    }
    return result;
}
int main() {

    vector<int> nums = {1, 2, 4, 8};
    vector<int> result = largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                Minimum Number of Operations to Make Elements in Array Distinct

//                                          Approach 1
/*
bool check(vector<int>& nums, int start) {

    unordered_set<int> st;
    for(int j = start; j < nums.size(); j++) {
        if(st.count(nums[j])) {
            return false;
        }
        st.insert(nums[j]);
    }
    return true;
}
int minimumOperations(vector<int>& nums) {

    int ops = 0;
    for(int i=0; i < nums.size(); i += 3) {
        if(check(nums, i)) {
            return ops;
        }
        ops++;
    }
    return ops;
}
int main() {

    vector<int> nums = {1, 2, 3, 1, 4, 5};

    int result = minimumOperations(nums);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int minimumOperations(vector<int>& nums) {

    unordered_set<int> st;
    for(int i = nums.size()-1; i >= 0; i--) {
        if(st.count(nums[i])) {
            return ceil((i+1)/3.0);
        }
        st.insert(nums[i]);
    }
    return 0;
}
int main() {

    vector<int> nums = {1, 2, 3, 1, 4, 5};

    int result = minimumOperations(nums);
    cout << "Minimum operations: " << result << endl;

    return 0;
}
*/

//                  Minimum Operations to Make Array Values Equal to K
/*
int minOperations(vector<int>& nums, int k) {

    unordered_set<int> st;
    for(int x : nums) {
        if(x < k) {
            return -1;
        } 
        else if(x > k) {
            st.insert(x);  
        }
    }
    return st.size();
}
int main() {

    vector<int> nums = {5, 7, 10, 6};
    int k = 6;

    int result = minOperations(nums, k);    
    cout << "Number of operations : " << result << endl;

    return 0;
}
*/

//                                Count the Number of Powerful Integers
/*
long long solve(string& str, string& inputSuffix, int limit) {

    if(str.length() < inputSuffix.length()) {
        return 0;
    }
    
    int remainL = str.length() - inputSuffix.length();
    long long count = 0;
    for(int i=0; i < remainL; i++) {
        int digit = str[i] - '0';
        if(digit <= limit) {
            count += digit * pow(limit + 1, remainL - i - 1);
        } 
        else {
            count += pow(limit + 1, remainL - i);
            return count;
        }
    }

    string trailString = str.substr(str.length() - inputSuffix.length());
    if(trailString >= inputSuffix) {
        count += 1;
    }
    return count;
}
long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {

    string startStr = to_string(start-1);
    string finishStr = to_string(finish);

    return solve(finishStr, s, limit) - solve(startStr, s, limit);
}
int main() {

    long long start = 1;
    long long finish = 6000;
    int limit = 4;
    string suffix = "124";

    long long result = numberOfPowerfulInt(start, finish, limit, suffix);
    cout << "Number of powerful integers: " << result << endl;

    return 0;
}
*/

//                                  Count Symmetric Integers

//                                         Approach 1
/*
int countSymmetricIntegers(int low, int high) {

    int count = 0;
    for(int num = low; num <= high; num++) {
        string s = to_string(num);
        int l = s.length();
        if(l%2 != 0) {
            continue;
        }

        int leftSum = 0;
        for(int i=0; i < l/2; i++) {
            leftSum += s[i] - '0';
        }

        int rightSum = 0;
        for(int i = l/2; i < l; i++) {
            rightSum += s[i] - '0';
        }

        if(leftSum == rightSum) {
            count++;
        }
    }
    return count;
}
int main() {

    int low = 1; 
    int high = 100;

    int result = countSymmetricIntegers(low, high);
    cout << "Count of symmetric integers between " << low << " and " << high << ": " << result << endl;

    return 0;
}
*/
//                                         Approach 2
/*
int countSymmetricIntegers(int low, int high) {

    int count = 0;
    for(int num = low; num <= high; num++) {
        if(num >= 10 && num <= 99 && num % 11 == 0) {
            count++;
        } 
        else if(num >= 1000 && num <= 9999) {
            int first  = num/1000;
            int second = (num/100) % 10;
            int third  = (num / 10) % 10;
            int fourth = (num % 10);
            if(first + second == third + fourth) {
                count++;
            }
        }
    }
    return count;
}
int main() {

    int low = 1; 
    int high = 100;

    int result = countSymmetricIntegers(low, high);
    cout << "Count of symmetric integers between " << low << " and " << high << ": " << result << endl;

    return 0;
}
*/

//                                    Find the Count of Good Integers
/*
long long countGoodIntegers(int n, int k) {

    unordered_set<string> st;

    int d = (n+1)/2;
    int start = pow(10, d-1);
    int end = pow(10, d) - 1;
    for(int num = start; num <= end; num++) {
        string leftHalf = to_string(num);
        string full = "";
        if(n%2 == 0) {
            string rightHalf = leftHalf;
            reverse(rightHalf.begin(), rightHalf.end());
            full = leftHalf + rightHalf;
        } 
        else {
            string rightHalf = leftHalf.substr(0, d-1);
            reverse(rightHalf.begin(), rightHalf.end());
            full = leftHalf + rightHalf;
        }
        long long number = stoll(full);
        if(number % k != 0) {
            continue;
        }
        sort(full.begin(), full.end());
        st.insert(full);
    }

    vector<long long> factorial(11, 1);
    for(int i=1; i < 11; i++) {
        factorial[i] = factorial[i-1] * i;
    }

    long long result = 0;
    for(string s : st) {
        vector<int> count(10, 0);
        for(char ch : s) {
            count[ch - '0']++; 
        }
        int totalDigits = s.length();
        int zeroDigits = count[0];
        int nonZeroDigits = totalDigits - zeroDigits;

        long long perm = (nonZeroDigits * factorial[totalDigits-1]);
        for(int i=0; i < 10; i++) {
            perm /= factorial[count[i]];
        }
        result += perm;
    }
    return result;
}
int main() {

    int n = 5;  
    int k = 6;

    long long answer = countGoodIntegers(n, k);
    cout << "Count of good integers: " << answer << endl;

    return 0;
}
*/

//                                         Count Good Numbers
/*
const int M = 1e9 + 7;
int findPower(long long a, long long b) {

    if(b == 0) {
        return 1;
    }   

    long long half = findPower(a, b/2);
    long long result = (half * half) % M;

    if(b % 2 == 1) {
        result = (result * a) % M;
    }
    return result;
}
int countGoodNumbers(long long n) {

    return (long long)findPower(5, (n+1)/2) * findPower(4, n/2) % M;
}
int main() {

    long long n = 50; 

    int result = countGoodNumbers(n);
    cout << "Number of good numbers of length " << n << " is: " << result << endl;

    return 0;
}
*/

//                                   Count Good Triplets
/*
int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

    int n = arr.size();
    int count = 0;
    for(int i=0; i <= n-3; i++) {
        for(int j = i+1; j <= n-2; j++) {
            if(abs(arr[i] - arr[j]) <= a) {
                for(int k = j+1; k <= n-1; k++) {
                    if(abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}
int main() {

    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7, b = 2, c = 3;

    int result = countGoodTriplets(arr, a, b, c);
    cout << "Number of good triplets: " << result << endl;

    return 0;
}
*/

//                               Count Good Triplets in an Array
/*
void updateSegmentTree(int i, int l, int r, int updateIndex, vector<long long>& segmentTree) {

    if(l == r) {
        segmentTree[i] = 1;
        return;
    }

    int mid = l + (r-l) / 2;
    if(updateIndex <= mid) {
        updateSegmentTree(2*i+1, l, mid, updateIndex, segmentTree);
    } 
    else {
        updateSegmentTree(2*i+2, mid + 1, r, updateIndex, segmentTree);
    }
    segmentTree[i] = segmentTree[2*i+1] + segmentTree[2*i+2];
}
long long querySegmentTree(int queryStart, int queryEnd, int i, int l, int r, vector<long long>& segmentTree) {

    if(r < queryStart || l > queryEnd) {
        return 0;
    }

    if(l >= queryStart && r <= queryEnd) {
        return segmentTree[i];
    }

    int mid = l + (r-l)/2;
    long long left = querySegmentTree(queryStart, queryEnd, 2*i+1, l, mid, segmentTree);
    long long right = querySegmentTree(queryStart, queryEnd, 2*i+2, mid + 1, r, segmentTree);
    return left + right;
}
long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

    int n = nums1.size();
        
    unordered_map <int, int> mp;
    for(int i=0; i<n; i++) {
        mp[nums2[i]] = i;
    }

    // Update with first element's mapped index from nums2
    vector<long long> segmentTree(4*n);  
    updateSegmentTree(0, 0, n-1, mp[nums1[0]], segmentTree);

    long long result = 0;
    for(int i=1; i<n; i++) {
        int idx = mp[nums1[i]];
        long long leftCommonCount = querySegmentTree(0, idx, 0, 0, n-1, segmentTree);
        long long leftNotCommonCount = i - leftCommonCount;
        long long elementsAfterIdxNums2 = (n-1) - idx;
        long long rightCommonCount = elementsAfterIdxNums2 - leftNotCommonCount;
        result += leftCommonCount * rightCommonCount;
        updateSegmentTree(0, 0, n-1, idx, segmentTree);
    }
    return result;
}
int main() {

    vector<int> nums1 = {4, 0, 1, 3, 2};
    vector<int> nums2 = {4, 1, 0, 2, 3};

    long long result = goodTriplets(nums1, nums2);
    cout << "Number of good triplets: " << result << endl;

    return 0;
}
*/

//                             Count the Number of Good Subarrays
/*
long long countGood(vector<int>& nums, int k) {

    unordered_map<int, int> mp;
    long long result = 0;
    long long pairs = 0;

    int n = nums.size();
    int i = 0;
    int j = 0;
    while(j < n) {
        pairs += mp[nums[j]]; 
        mp[nums[j]]++;
        while(pairs >= k) {
            result += (n-j);
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
        }
        j++;
    }
    return result;
}
int main() {

    vector<int> nums = {3, 1, 4, 3, 2, 2, 4};
    int k = 2;

    long long result = countGood(nums, k);
    cout << "Number of good subarrays: " << result << endl;

    return 0;
}
*/

//                      Count Equal and Divisible Pairs in an Array
/*
int countPairs(vector<int>& nums, int k) {

    int n = nums.size();
    int result = 0;

    for(int i=0; i < n-1; i++) {
        for(int j = i+1; j<n; j++) {
            if((i * j) % k == 0 && nums[i] == nums[j]) {
                result++;
            }
        }
    }
    return result;
}
int main() {

    vector<int> nums = {3, 1, 2, 2, 2, 1, 3};
    int k = 2;

    int result = countPairs(nums, k);
    cout << "Number of valid pairs: " << result << endl;

    return 0;
}
*/

//                                         Count and Say
/*
string countAndSay(int n) {

    // Base Case
    if(n == 1) {
        return "1";
    }
    
    // Recursive Call
    string say = countAndSay(n-1); 

    string result = "";
    for(int i=0; i < say.length(); i++) {
        int count = 1;
        char ch = say[i];
        while(i < say.length()-1 && say[i] == say[i+1]) {
            count++;
            i++;
        }
        result += to_string(count) + string(1, say[i]);
    }
    return result;  
}
int main() {

    int n = 4;
    string result = countAndSay(n);
    cout << "The " << n << "th term of the count-and-say sequence is: " << result << endl;

    return 0;
}
*/

//                                  Count the Number of Fair Pairs
/*
long long countFairPairs(vector<int>& nums, int lower, int upper) {

    int n = nums.size();
    sort(begin(nums), end(nums)); 

    long long result = 0;
    for(int i=0; i<n; i++) { 
        // Gives the firstc element NOT LESS than (lower - nums[i]) //log(n)
        int idx = lower_bound(begin(nums) + i + 1, end(nums), lower-nums[i]) - begin(nums); 
        int x = idx - 1 - i;

        // Gives the firstc element GREATER than (upper - nums[i]) //log(n)
        idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i]) - begin(nums); 
        int y = idx - 1 - i;

        result += (y-x);
    }
    return result;
}
int main() {

    vector<int> nums = {0, 1, 7, 4, 4, 5}; 
    int lower = 3;
    int upper = 6;

    long long result = countFairPairs(nums, lower, upper);
    cout << "Number of fair pairs: " << result << endl;

    return 0;
}
*/

//                                        Rabbits in Forest
/*
int numRabbits(vector<int>& answers) {

    unordered_map <int, int> mp;
    for(int& x : answers) {
        mp[x]++;
    }

    int total = 0;
    for(auto& it : mp) {
        int x = it.first; 
        int count = it.second;

        int groupSize = x + 1;
        int groups = ceil((double)count / groupSize);
        total += groups * groupSize;
    }
    return total;
}
int main() {

    vector<int> answers = {1, 1, 2};

    int result = numRabbits(answers);
    cout << "Minimum number of rabbits in the forest: " << result << endl;

    return 0;
}
*/

//                                    Count the Hidden Sequences
/*
int numberOfArrays(vector<int>& differences, int lower, int upper) {

    int curr = 0; 
    int minVal = 0;
    int maxVal = 0;

    for(int d : differences) {
        curr = curr + d;
        minVal = min(minVal, curr);
        maxVal = max(maxVal, curr);

        if((upper - maxVal) - (lower - minVal) + 1 <= 0) {
            return 0;
        }
    }
    return (upper - maxVal) - (lower - minVal) + 1;
}
int main() {

    vector<int> differences = {1, -3, 4};
    int lower = 1;
    int upper = 6;

    int result = numberOfArrays(differences, lower, upper);
    cout << "Number of valid arrays: " << result << endl;

    return 0;
}
*/

//                              Count the Number of Ideal Arrays
/*
int M = 1e9+7;
void findSets(int m, vector<int>& count, vector<vector<int>>& dp) {

    if (dp[m][1] != 0) {
        return;
    }

    dp[m][1] = 1;
    count[1]++;
    for(int div = 2; div <= m; div++) {
        if(m % div == 0) {
            findSets(m / div, count, dp);
            for(int len = 1; len < 15; len++) {
                if(dp[m / div][len] != 0) {
                    dp[m][len + 1] += dp[m / div][len];
                    count[len + 1] += dp[m / div][len];
                }
            }
        }
    }
}
int findPower(long long a, long long b) {

    if (b == 0) {
        return 1;
    }

    long long half = findPower(a, b / 2);
    long long result = (half * half) % M;
    if(b % 2 == 1) {
        result = (result * a) % M;
    }
    return result;
}
int modularnCr(int n, int r, vector<long long>& fact) {

    if(r < 0 || r > n) {
        return 0;
    }

    long long b = (fact[r] * fact[n - r]) % M;
    return (fact[n] * findPower(b, M - 2)) % M;
}
int idealArrays(int n, int maxVal) {

    vector<vector<int>> dp(maxVal + 1, vector<int>(15, 0));
    vector<int> count(15, 0);
    // Find sets count
    for(int val = 1; val <= maxVal; val++) {
        findSets(val, count, dp);
    }

    // Precompute factorials
    vector<long long> fact(n + 1, 1);
    for(int i=2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }

    long long result = 0;
    for(int len = 1; len < 15; len++) {
        if(n < len) {
            break;
        }
        if(count[len] != 0) {
            long long possibilities = modularnCr(n - 1, len - 1, fact);
            result = (result + (count[len] * possibilities) % M) % M;
        }
    }
    return (int)result;
}
int main() {

    int n = 2;       
    int maxVal = 5;

    int result = idealArrays(n, maxVal);
    cout << "Number of ideal arrays of length " << n << " with max value " << maxVal << " is: " << result << endl;

    return 0;
}
*/

//                                      Count Largest Group
/*
int findDigitsSum(int num) {

    int sum = 0;
    while(num) {
        sum += num%10;
        num /= 10;
    }
    return sum;
}
int countLargestGroup(int n) {

    unordered_map <int, int> mp;

    int maxSize = 0;
    int count = 0;
    for(int num = 1; num <= n; num++) {
        int digitsSum = findDigitsSum(num);
        mp[digitsSum]++;
        if(mp[digitsSum] == maxSize) {
            count++;
        } 
        else if(mp[digitsSum] > maxSize) {
            maxSize = mp[digitsSum];
            count = 1;
        }
    }
    return count;
}
int main() {

    int n = 13;
    cout << "Number of largest groups for n = " << n << " is: " << countLargestGroup(n) << endl;

    return 0;
}
*/

//                                 Count Complete Subarrays in an Array
/*
int countCompleteSubarrays(vector<int>& nums) {

    int n = nums.size();
    unordered_set <int> st(begin(nums), end(nums));
    int c = st.size();

    unordered_map <int, int> mp;
    int i = 0;
    int j = 0;
    int res = 0;
    while(j < n) {
        mp[nums[j]]++;
        while(mp.size() == c) {
            res += (n-j);
            mp[nums[i]]--;
            if(mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
            i++;
        }
        j++;
    }
    return res;
}
int main() {

    vector<int> nums = {1, 3, 1, 2, 2};

    int result = countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl;

    return 0;
}
*/

//                                    Subarray Sums Divisible by K

//                                              Approach 1
/*
int subarraysDivByK(vector<int>& nums, int k) {

    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = accumulate(begin(nums)+i, begin(nums)+j+1, 0);
            if(sum%k == 0) {
                count++;
            }
        }
    }
    return count;
}
int main() {

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
*/
//                                              Approach 2
/*
int subarraysDivByK(vector<int>& nums, int k) {

    int n = nums.size();
    int count = 0;
    for(int i=1; i<n; i++) {
        nums[i] += nums[i-1];
    }

    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = (i==0) ? nums[j] : nums[j] - nums[i-1];
            if(sum%k == 0) {
                count++;
            }
        }
    }
    return count;
}
int main() {

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
*/
//                                              Approach 3
/*
int subarraysDivByK(vector<int>& nums, int k) {

    int n = nums.size();
    
    unordered_map <int, int> mp;    
    mp[0] = 1;

    int result = 0;
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += nums[i];
        int rem = sum % k;
        if(rem < 0) {
            rem += k;
        }
        if(mp.find(rem) != mp.end()) {
            result += mp[rem];
        }
        mp[rem]++;   
    }
    return result;   
}
int main() {

    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
*/

//                                 Count of Interesting Subarrays
/*
long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        
    int n = nums.size();

    // Remainder -> Count
    unordered_map<int, long long> mp; 
    mp[0] = 1;

    // Sum will be equal to cnt of those elements % m == k
    long long sum = 0; 

    long long result = 0;    
    for(int i=0; i<n; i++) {
        if(nums[i] % m == k) {
            sum += 1;
        }
        int r1 = sum % m;
        int r2 = (r1 - k + m) % m;
        result += mp[r2];
        mp[r1]++;
    }
    return result;
}
int main() {

    vector<int> nums = {3, 1, 9, 6};  
    int m = 3;
    int k = 0;

    long long result = countInterestingSubarrays(nums, m, k);
    cout << "Number of interesting subarrays: " << result << endl;

    return 0;
}
*/

//                                     Minimum Window Substring
/*
string minWindow(string s, string t) {

    int n = s.length();
    unordered_map <char, int> mp;
    
    for(char ch : t) {
        mp[ch]++;
    }
    
    int requiredCount = t.length();
    int i = 0, j  = 0;
    int minStart  = 0;
    int minWindow = INT_MAX;
    while(j < n) {
        char ch_j = s[j];
        if(mp[ch_j] > 0) {
            requiredCount--;
        }
        mp[ch_j]--;
        
        // Try to shrink the window
        while(requiredCount == 0) { 
            if(minWindow > j-i+1) {
                minWindow = j-i+1;
                minStart = i;
            }
            char ch_i = s[i];
            mp[ch_i]++;
            if(mp[ch_i] > 0)
                requiredCount++;
            i++;
        }
        j++;
    }
    return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
}
int main() {

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";

    cout << "Result : " << minWindow(s1, t1) << endl;

    return 0;
}
*/

//                                Count Subarrays With Fixed Bounds

//                                             Approach 1
/*
long long countSubarrays(vector<int>& nums, int minK, int maxK) {

    int n = nums.size();
    long long count = 0;

    for(int start = 0; start < n; ++start) {
        int currentMin = nums[start];
        int currentMax = nums[start];
        for(int end = start; end < n; ++end) {
            currentMin = min(currentMin, nums[end]);
            currentMax = max(currentMax, nums[end]);
            if(currentMin == minK && currentMax == maxK) {
                count++;
            }
        }
    }
    return count;
}
int main() {

    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;

    long long result = countSubarrays(nums, minK, maxK);
    cout << "Number of subarrays with min = " << minK << " and max = " << maxK << " is: " << result << endl;

    return 0;
}
*/
//                                             Approach 2
/*
long long countSubarrays(vector<int>& nums, int minK, int maxK) {

    int minPosition = -1;
    int maxPosition = -1;
    int leftBound = -1;
    
    long long ans = 0;
    for(int i=0; i < nums.size(); i++) {
        if(nums[i] < minK || nums[i] > maxK) {
            leftBound = i;
        }
        if(nums[i] == minK) {
            minPosition = i;
        }
        if(nums[i] == maxK) {
            maxPosition = i;
        }
        int count = min(maxPosition, minPosition) - leftBound;
        ans += (count <= 0) ? 0 : count;   
    }
    return ans;
}
int main() {

    vector<int> nums = {1, 3, 5, 2, 7, 5};
    int minK = 1;
    int maxK = 5;

    long long result = countSubarrays(nums, minK, maxK);
    cout << "Number of subarrays with min = " << minK << " and max = " << maxK << " is: " << result << endl;

    return 0;
}
*/

//                      Count Subarrays of Length Three With a Condition
/*
int countSubarrays(vector<int>& nums) {

    int n = nums.size();

    int result = 0;
    for(int i=1; i < n-1; i++) {
        if(nums[i] == (nums[i-1] + nums[i+1]) * 2) {
            result++;
        }
    }
    return result;
}
int main() {

    vector<int> nums = {1, 2, 1, 4, 1};

    int result = countSubarrays(nums);
    cout << "Number of subarrays where middle element is average of neighbors: " << result << endl;

    return 0;
}
*/

//                              Count Subarrays With Score Less Than K
/*
long long countSubarrays(vector<int>& nums, long long k) {

    int n = nums.size();

    long long result = 0;
    long long sum = 0;

    int i = 0;
    int j = 0;
    while(j < n) {
        sum += nums[j];
        // Shrink the window
        while(i <= j && sum * (j-i+1) >= k) { 
            sum -= nums[i];
            i++;
        }
        result += (j-i+1);
        j++;
    }
    return result;
}
int main() {

    vector<int> nums = {2, 1, 4, 3, 5};
    long long k = 10;

    long long result = countSubarrays(nums, k);
    cout << "Number of valid subarrays: " << result << endl;

    return 0;
}
*/

//              Count Subarrays Where Max Element Appears at Least K Times

//                                       Approach 1
/*
long long countSubarrays(vector<int>& nums, int k) {

    int maxE = *max_element(begin(nums), end(nums));
    
    int n = nums.size();
    int i = 0, j = 0;
    
    long long result = 0;
    int countMax = 0;
    while(j < n) {
        if(nums[j] == maxE) {
            countMax++;
        }
        while(countMax >= k) {
            result += n-j;
            if(nums[i] == maxE) {
                countMax--;
            }
            i++;
        }
        j++;
    }
    return result;
}
int main() {

    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    long long result = countSubarrays(nums, k);
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
*/
//                                       Approach 2
/*
long long countSubarrays(vector<int>& nums, int k) {

    int maxE = *max_element(begin(nums), end(nums));
    
    int n = nums.size();

    vector<int> maxIndices;
    
    long long result = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == maxE) {
            maxIndices.push_back(i);
        }
        int size = maxIndices.size();
        if(size >= k) {
            int last_i = maxIndices[size-k];
            result += last_i+1;
        }
    }
    return result;
}
int main() {

    vector<int> nums = {1, 3, 2, 3, 3};
    int k = 2;

    long long result = countSubarrays(nums, k);
    cout << "Number of subarrays: " << result << endl;

    return 0;
}
*/

//                             Find Numbers with Even Number of Digits

//                                           Approach 1
/*
int findNumbers(vector<int>& nums) {

    int count = 0;
    for(int num : nums) {
        string s = to_string(num);
        if (s.size() % 2 == 0) {
            count++;
        }
    }
    return count;
}
int main() {

    vector<int> nums = {12, 345, 2, 6, 7896};

    int evenDigitCount = findNumbers(nums);
    cout << "Count of numbers with even number of digits: " << evenDigitCount << endl;

    return 0;
}
*/
//                                           Approach 2
/*
bool hasEvenDigits(int num) {

    int digitCount = 0;
    while(num) {
        digitCount++;
        num /= 10;
    }
    return (digitCount % 2) == 0;
}
int findNumbers(vector<int>& nums) {

    int result = 0;
    for(int num : nums) {
        if(hasEvenDigits(num)) {
            result++;
        }
    }
    return result;
}
int main() {

    vector<int> nums = {12, 345, 2, 6, 7896};

    int evenDigitCount = findNumbers(nums);
    cout << "Count of numbers with even number of digits: " << evenDigitCount << endl;

    return 0;
}
*/
//                                           Approach 3
/*
int findNumbers(vector<int>& nums) {

    int count = 0;
    for(int num : nums) {
        if ((num >= 10 && num < 100) || (num >= 1000 && num < 10000) || num == 100000)
            ++count;
    }
    return count;
}
int main() {

    vector<int> nums = {12, 345, 2, 6, 7896};

    int evenDigitCount = findNumbers(nums);
    cout << "Count of numbers with even number of digits: " << evenDigitCount << endl;

    return 0;
}
*/

//                            Maximum Number of Tasks You Can Assign
/*
bool canAssignTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength, int taskCount) {

    vector<int> availableWorkers(workers.begin(), workers.begin() + taskCount);
    sort(availableWorkers.begin(), availableWorkers.end());

    // Index for hardest task
    int i = taskCount - 1; 
    // Index for strongest worker
    int j = taskCount - 1; 

    int pillsUsed = 0;
    while(i >= 0) {
        // Assign task to worker
        if(availableWorkers[j] >= tasks[i]) {
            j--;
            i--;
        }
        // Use pill on weakest worker to do this task
        else if(pillsUsed < pills) {
            auto weakestWorkerIt = lower_bound(availableWorkers.begin(), availableWorkers.end(), tasks[i] - strength);
            if(weakestWorkerIt == availableWorkers.end()) {
                return false;
            }
            availableWorkers.erase(weakestWorkerIt);
            pillsUsed++;
            i--;
            j--;
        }
        // Not possible to assign this task
        else {
            return false;
        }
    }
    return true;
}
int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {

    int m = tasks.size();
    int n = workers.size();

    int l = 0;
    int r = min(m, n);

    sort(begin(tasks), end(tasks));
    sort(begin(workers), end(workers), greater<int>());

    int result = 0;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(canAssignTasks(tasks, workers, pills, strength, mid)) {
            result = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return result;
}
int main() {

    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    int pills = 1;
    int strength = 1;

    cout << "Maximum tasks that can be assigned: " << maxTaskAssign(tasks, workers, pills, strength) << endl;
    return 0;
}
*/

//                                      Push Dominoes
/*
string pushDominoes(string dominoes) {

    int n = dominoes.length();
    
    vector<int> rightClosestL(n);
    vector<int> leftClosestR(n);
    
    // Moving right to left to find rightClosestL
    for(int i = n-1; i >= 0; i--) {
        // L starts from me
        if(dominoes[i] == 'L') {
            rightClosestL[i] = i;
        } 
        else if(dominoes[i] == '.') {
            rightClosestL[i] = i < n-1 ? rightClosestL[i+1] : -1;
        }
        else {
            rightClosestL[i] = -1;
        }
    }
    
    // Moving left to right to find leftClosestR
    for(int i=0; i<n; i++) {
        // R starts from me
        if(dominoes[i] == 'R') {
            leftClosestR[i] = i; 
        }
        else if(dominoes[i] == '.') {
            leftClosestR[i] = i > 0 ? leftClosestR[i-1] : -1;
        }
        else {
            leftClosestR[i] = -1;
        }
    }
    
    string result(n, ' ');
    for(int i=0; i<n; i++) {
        // Distance from 'R' towards my left direction
        int distRightL = abs(i-rightClosestL[i]); 
        // Distance from 'L' towards my right direction
        int distLeftR  = abs(i-leftClosestR[i]);  
        
        if(rightClosestL[i] == leftClosestR[i]) {
            result[i] = '.';
        }
        // No force from right direction towards left, so move R
        else if(rightClosestL[i] == -1) {
            result[i] = 'R';
        }
        // No force from left direction towards right, so move L
        else if(leftClosestR[i] == -1) {
            result[i] = 'L';
        }
        // Equal force from left and right
        else if(distLeftR == distRightL) {
            result[i] = '.';
        }
        // Whichever force is greater (either from left by 'R' or from right by 'L')
        else {
            result[i] = distRightL < distLeftR ? 'L': 'R'; 
        }
    }
    return result;
}
int main() {

    string dominoes = ".L.R...LR..L..";
    cout << pushDominoes(dominoes) << endl;

    return 0;
}
*/

//                                Minimum Domino Rotations For Equal Row
/*
int find(vector<int>& tops, vector<int>& bottoms, int val) {

    int swapTop = 0;
    int swapBottom = 0;
    for(int i=0; i < tops.size(); i++) {
        if(tops[i] != val && bottoms[i] != val) {
            return -1;
        } 
        else if(tops[i] != val) {
            swapTop++;
        } 
        else if(bottoms[i] != val) {
            swapBottom++;
        }
    }
    return min(swapTop, swapBottom);
}
int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

    int result = find(tops, bottoms, tops[0]);
    if(result != -1) {
        return result;
    }
    return find(tops, bottoms, bottoms[0]);
}
int main() {
    
    vector<int> tops = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms = {5, 2, 6, 2, 3, 2};

    int result = minDominoRotations(tops, bottoms);

    cout << "Minimum number of rotations needed: " << result << endl;

    return 0;
}
*/

//                               Number of Equivalent Domino Pairs

//                                          Approach 1
/*
int numEquivDominoPairs(vector<vector<int>>& dominoes) {

    map <pair<int, int>, int> mp;
    for(auto &d : dominoes) {
        if(d[0] > d[1]) {
            swap(d[0], d[1]);
        }
        mp[{d[0], d[1]}]++;
    }

    int result = 0;
    for(auto &it : mp) {
        int freq = it.second;
        // nCr
        result += freq * (freq-1)/2; 
    }
    return result;
}
int main() {

    vector<vector<int>> dominoes = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};

    int result = numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int numEquivDominoPairs(vector<vector<int>>& dominoes) {

    vector<int> vec(100);

    int result = 0;
    for(auto &d : dominoes) {
        if(d[0] > d[1]) {
            swap(d[0], d[1]);
        }

        int num = d[0]*10 + d[1];
        result += vec[num];
        vec[num]++;
    }
    return result;
}
int main() {

    vector<vector<int>> dominoes = {{1, 2}, {1, 2}, {1, 1}, {1, 2}, {2, 2}};

    int result = numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}
*/

//                                     Domino and Tromino Tiling

//                                             Recursive
/*
int M = 1000000007;
int solve(int n) {

    // Base Case
    if(n == 1 || n == 2) {
        return n;
    }
    if(n == 3) {
        return 5;
    }

    return (2 * solve(n-1) % M + solve(n-3) % M) % M;
}
int numTilings(int n) {

    return solve(n);
}
int main() {

    int n = 3;

    int result = numTilings(n);
    cout << "Number of ways to tile a 2x" << n << " board is: " << result << endl;

    return 0;
}
*/
//                                             Top-Down
/*
int M = 1000000007;
int solve(int n, vector<int>& dp) {

    // Base Case
    if(n == 1 || n == 2) {
        return n;
    }
    if(n == 3) {
        return 5;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = (2 * solve(n-1, dp) % M + solve(n-3, dp) % M) % M;
}
int numTilings(int n) {

    vector<int> dp(n+1, -1);
    return solve(n, dp);
}
int main() {

    int n = 3;

    int result = numTilings(n);
    cout << "Number of ways to tile a 2x" << n << " board is: " << result << endl;

    return 0;
}
*/
//                                            Bottom-Up
/*
int M = 1000000007;
int solve(int n) {

    if(n == 1 || n == 2) {
            return n;
    }

    vector<int> dp(n+1, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for(int i=4; i <= n; i++) {
        dp[i] = (2 * dp[i-1] % M + dp[i-3] % M) % M;
    }
    return dp[n];
}
int numTilings(int n) {
    
    return solve(n);
}
int main() {

    int n = 3;

    int result = numTilings(n);
    cout << "Number of ways to tile a 2x" << n << " board is: " << result << endl;

    return 0;
}
*/

//                                  Build Array from Permutation

//                                           Approach 1
/*
vector<int> buildArray(vector<int>& nums) {

    int n = nums.size();

    vector<int> result(n);
    for(int i=0 ; i<n ; i++) {
        result[i] = nums[nums[i]];
    }
    return result;
}
int main() {

    vector<int> nums = {0, 2, 1, 5, 3, 4};

    vector<int> result = buildArray(nums);

    cout << "Resulting array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                           Approach 2
/*
vector<int> buildArray(vector<int>& nums) {

    int n = nums.size();

    for(int i=0; i<n; i++) {
        nums[i] += n * (nums[nums[i]] % n);
    }
    for(int i=0; i<n; i++) {
        nums[i] /= n;
    }
    return nums;
}
int main() {

    vector<int> nums = {0, 2, 1, 5, 3, 4};

    vector<int> result = buildArray(nums);

    cout << "Resulting array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                              Find Minimum Time to Reach Last Room I
/*
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int minTimeToReach(vector<vector<int>>& moveTime) {

    int m = moveTime.size();
    int n = moveTime[0].size();

    // Distance array (same as dist in graph Dijkstra)
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Set to act as a priority queue → {time, {i, j}}
    set <pair<int, pair<int, int>>> st;

    // Initialize source
    dist[0][0] = 0;
    st.insert({0, {0, 0}});

    while(!st.empty()) {
        // Get top record
        auto top = *(st.begin());
        int currTime = top.first;
        int i = top.second.first;
        int j = top.second.second;
        st.erase(st.begin());

        // If reached destination
        if(i == m-1 && j == n-1) {
            return currTime;
        }
        // Explore neighbors
        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                int wait = max(moveTime[i_][j_] - currTime, 0);
                int arrTime = currTime + wait + 1;

                if(arrTime < dist[i_][j_]) {
                    // If record exists, remove it
                    auto record = st.find({dist[i_][j_], {i_, j_}});
                    if(record != st.end()) {
                        st.erase(record);
                    }
                    // Update distance
                    dist[i_][j_] = arrTime;

                    // Insert new record
                    st.insert({arrTime, {i_, j_}});
                }
            }
        }
    }
    return -1;
}
int main() {

    vector<vector<int>> moveTime = {
        {0, 4},
        {4, 4}
    };

    cout << "Minimum time to reach destination: " << minTimeToReach(moveTime) << endl;
    return 0;
}
*/

//                             Find Minimum Time to Reach Last Room II
/*
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int minTimeToReach(vector<vector<int>>& moveTime) {

    int m = moveTime.size();
    int n = moveTime[0].size();

    // Distance array (same as dist in graph Dijkstra)
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

    // Set to act as a priority queue → {time, {i, j}}
    set <pair<int, pair<int, int>>> st;

    // Initialize source
    dist[0][0] = 0;
    st.insert({0, {0, 0}});

    while(!st.empty()) {
        // Get top record
        auto top = *(st.begin());
        int currTime = top.first;
        int i = top.second.first;
        int j = top.second.second;
        st.erase(st.begin());

        // If reached destination
        if(i == m-1 && j == n-1) {
            return currTime;
        }
        // Explore neighbors
        for(auto dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                int moveCost = (i_ + j_) % 2 == 0 ? 2 : 1;
                int wait = max(moveTime[i_][j_] - currTime, 0);
                int arrTime = currTime + wait + moveCost;

                if(arrTime < dist[i_][j_]) {
                    // If record exists, remove it
                    auto record = st.find({dist[i_][j_], {i_, j_}});
                    if(record != st.end()) {
                        st.erase(record);
                    }
                    // Update distance
                    dist[i_][j_] = arrTime;

                    // Insert new record
                    st.insert({arrTime, {i_, j_}});
                }
            }
        }
    }
    return -1;
}
int main() {

    vector<vector<int>> moveTime = {
        {0, 4},
        {4, 4}
    };

    cout << "Minimum time to reach destination: " << minTimeToReach(moveTime) << endl;
    return 0;
}
*/  

//                           Count Number of Balanced Permutations

//                                        Approach 1
/*
int countBalancedPermutations(string num) {

    // Sorting helps next_permutation to find all permutation, so we need to start from smallest (hence sorted)
    sort(num.begin(), num.end()); 
    unordered_set<string> seen;
    int count = 0;

    do {
        if(seen.count(num)) {
            continue;
        }
        seen.insert(num);
        int evenSum = 0, oddSum = 0;
        for(int i=0; i < num.size(); ++i) {
            int digit = num[i] - '0';
            if (i % 2 == 0) {
                evenSum += digit;
            }
            else {
                oddSum += digit;
            }
        }
        if(evenSum == oddSum) {
            count++;
        }
    } 
    while(next_permutation(num.begin(), num.end()));

    return count;
}
int main() {

    string num = "123";

    int result = countBalancedPermutations(num);
    cout << "Number of balanced permutations for " << num << " is: " << result << endl;

    return 0;
}
*/
//                                        Approach 2
/*
int n;
int totalDigitSum;
int M = 1e9 + 7;
long long totalPermPossible = 0;

// Binary exponentian
int findPower(long long a, long long b) {

    if(b == 0) {
        return 1;
    }

    long long half = findPower(a, b/2);
    long long result = (half * half) % M;
    if(b % 2 == 1) {
        result = (result * a) % M;
    }
    return result;
}
int solve(int digit, int evenIndexDigitsCount, int currSum, vector<int> &freq, vector<long long>& fermatFact) {

    if(digit == 10) {
        if(currSum == totalDigitSum / 2 && evenIndexDigitsCount == (n+1) / 2) {
            return totalPermPossible;
        }
        return 0;
    }

    long long ways = 0;
    for(int count = 0; count <= min(freq[digit], (n+1) / 2 - evenIndexDigitsCount); count++) {
        int evenPosCount = count;
        int oddPosCount = freq[digit] - count;

        long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % M;
        long long val = solve(digit + 1, evenIndexDigitsCount + evenPosCount, currSum + digit * count, freq, fermatFact);
        ways = (ways + (val * div) % M) % M;
    }
    return ways;
}
int countBalancedPermutations(string num) {
    n = num.length();
    totalDigitSum = 0;

    vector<int> freq(10, 0);
    for(int i=0; i<n; i++) {
        totalDigitSum += num[i] - '0';
        freq[num[i] - '0']++;
    }

    if(totalDigitSum % 2 != 0) {
        return 0;
    }

    // Precomputing factorial
    vector<long long> fact(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % M;
    }

    // Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
    vector<long long> fermatFact(n+1, 1);
    for (int i=0; i <= n; i++) {
        fermatFact[i] = findPower(fact[i], M-2) % M;
    }

    totalPermPossible = (1LL * fact[(n+1) / 2] * fact[n/2]) % M;

    int digit = 0;
    int evenIndexDigitsCount = 0;
    int currSum = 0;

    return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact);
}
int main() {

    string num = "123";

    int result = countBalancedPermutations(num);
    cout << "Number of balanced permutations for " << num << " is: " << result << endl;

    return 0;
}
*/
//                                        Approach 3
/*
int n;
int totalDigitSum;
int M = 1e9 + 7;
long long totalPermPossible = 0;

// Binary exponentian
int findPower(long long a, long long b) {

    if(b == 0) {
        return 1;
    }

    long long half = findPower(a, b/2);
    long long result = (half * half) % M;
    if(b % 2 == 1) {
        result = (result * a) % M;
    }
    return result;
}
int solve(int digit, int evenIndexDigitsCount, int currSum, vector<int> &freq, vector<long long>& fermatFact, vector<vector<vector<int>>>& t) {

    if(digit == 10) {
        if(currSum == totalDigitSum / 2 && evenIndexDigitsCount == (n+1) / 2) {
            return totalPermPossible;
        }
        return 0;
    }
    if(t[digit][evenIndexDigitsCount][currSum] != -1) {
        return t[digit][evenIndexDigitsCount][currSum];
    }

    long long ways = 0;
    for(int count = 0; count <= min(freq[digit], (n+1) / 2 - evenIndexDigitsCount); count++) {
        int evenPosCount = count;
        int oddPosCount = freq[digit] - count;

        long long div = (fermatFact[evenPosCount] * fermatFact[oddPosCount]) % M;
        long long val = solve(digit + 1, evenIndexDigitsCount + evenPosCount, currSum + digit * count, freq, fermatFact, t);
        ways = (ways + (val * div) % M) % M;
    }
    return t[digit][evenIndexDigitsCount][currSum] = ways;
}
int countBalancedPermutations(string num) {
    n = num.length();
    totalDigitSum = 0;

    vector<int> freq(10, 0);
    for(int i=0; i<n; i++) {
        totalDigitSum += num[i] - '0';
        freq[num[i] - '0']++;
    }

    if(totalDigitSum % 2 != 0) {
        return 0;
    }

    // Precomputing factorial
    vector<long long> fact(n + 1, 1);
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % M;
    }

    // Precomputing FermatFactorial (inverse factorial --- (1/x)%M)
    vector<long long> fermatFact(n+1, 1);
    for(int i=0; i <= n; i++) {
        fermatFact[i] = findPower(fact[i], M-2) % M;
    }

    totalPermPossible = (1LL * fact[(n+1) / 2] * fact[n/2]) % M;

    int digit = 0;
    int evenIndexDigitsCount = 0;
    int currSum = 0;

    vector<vector<vector<int>>> t(10, vector<vector<int>>((n+1)/2 + 1, vector<int>(totalDigitSum + 1, -1)));
    return solve(digit, evenIndexDigitsCount, currSum, freq, fermatFact, t);
}
int main() {

    string num = "123";

    int result = countBalancedPermutations(num);
    cout << "Number of balanced permutations for " << num << " is: " << result << endl;

    return 0;
}
*/

//                       Minimum Equal Sum of Two Arrays After Replacing Zeros
/*
long long minSum(vector<int>& nums1, vector<int>& nums2) {

    long long sum1 = 0;
    long long sum2 = 0;

    long long zero1 = 0;
    long long zero2 = 0;

    for(int &num : nums1) {
        sum1 += num;
        // To get minimum sum, add smallest positive i.e. 1
        if(num == 0) { 
            zero1 += 1;
            sum1 += 1;
        }
    }
    for(int &num : nums2) {
        sum2 += num;
        // To get minimum sum, add smallest positive i.e. 1
        if(num == 0) { 
            zero2 += 1;
            sum2 += 1;
        }
    }
    if((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
        return -1;
    }        
    return max(sum1, sum2);
}
int main() {

    vector<int> nums1 = {3, 2, 0, 1, 0};
    vector<int> nums2 = {6, 5, 0};

    long long result = minSum(nums1, nums2);
    cout << "Minimum possible equal sum: " << result << endl;

    return 0;
}
*/

//                                    Three Consecutive Odds

//                                          Approach 1
/*
bool threeConsecutiveOdds(vector<int>& arr) {

    int n = arr.size();    
    for(int i=0; i < n-2; i++) {
        if(arr[i] % 2 && arr[i+1] % 2 && arr[i+2] % 2) {
            return true;
        }
    }
    return false;
}
int main() {

    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << threeConsecutiveOdds(arr); 

    return 0;
}
*/
//                                          Approach 2
/*
bool threeConsecutiveOdds(vector<int>& arr) {

    int n = arr.size();

    int oddCount = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] % 2 == 1) {
            oddCount++;
        } 
        else {
            oddCount = 0;
        }

        if(oddCount == 3) {
            return true;
        }
    }
    return false;
}
int main() {

    vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};
    cout << threeConsecutiveOdds(arr); 

    return 0;
}
*/

//                                         Dungeon Game

//                                         Recursive-1
/*
int m, n;
bool canSurvive(int i, int j, vector<vector<int>>& dungeon, int currHealth) {

    if(i >= m || j >= n) {
        return false;
    }

    currHealth += dungeon[i][j];
    if(currHealth <= 0) {
        return false;
    }

    if(i == m-1 && j == n-1) {
        return true;
    }

    return canSurvive(i+1, j, dungeon, currHealth) || canSurvive(i, j+1, dungeon, currHealth);
}
int calculateMinimumHP(vector<vector<int>> &dungeon) {

    m = dungeon.size();
    n = dungeon[0].size();

    int left = 1;
    int right = 4 * 1e7;

    int result = right;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(canSurvive(0, 0, dungeon, mid)) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}
int main() {

    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int minHealth = calculateMinimumHP(dungeon);
    cout << "Minimum initial health needed: " << minHealth << endl;

    return 0;
}
*/
//                                         Recursive-2
/*
int m, n;
int solve(int i, int j, vector<vector<int>>& dungeon) {

    if(i >= m || j >= n) {
        return 1e9;
    }
    
    if(i == m - 1 && j == n - 1) {
        return (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
    }

    int down = solve(i+1, j, dungeon);
    int right = solve(i, j+1, dungeon);

    int res = min(down, right) - dungeon[i][j];
    return (res > 0) ? res : 1;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {

    m = dungeon.size();
    n = dungeon[0].size();

    return solve(0, 0, dungeon);
}
int main() {

    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int minHealth = calculateMinimumHP(dungeon);
    cout << "Minimum initial health needed: " << minHealth << endl;

    return 0;
}
*/
//                                         Top-Down
/*
int m, n;
int solve(int i, int j, vector<vector<int>>& dungeon, int t[201][201]) {

    if(i >= m || j >= n) {
        return 1e9;
    }

    if(t[i][j] != -1) {
        return t[i][j];
    }

    if(i == m-1 && j == n-1) {
        return t[i][j] = (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
    }

    int down = solve(i+1, j, dungeon, t);
    int right = solve(i, j+1, dungeon, t);

    int res = min(down, right) - dungeon[i][j];
    return t[i][j] = (res > 0) ? res : 1;
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {

    m = dungeon.size();
    n = dungeon[0].size();

    int t[201][201];
    memset(t, -1, sizeof(t));

    return solve(0, 0, dungeon, t);
}
int main() {

    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int minHealth = calculateMinimumHP(dungeon);
    cout << "Minimum initial health needed: " << minHealth << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int m, n;
int solve(vector<vector<int>> &dungeon) {

    m = dungeon.size();
    n = dungeon[0].size();

    vector<vector<int>> t(m, vector<int>(n, 0));
    for(int i = m-1; i >= 0; --i) {
        for(int j = n-1; j >= 0; --j) {
            if(i == m-1 && j == n-1) {
                t[i][j] = (dungeon[m-1][n-1] > 0 ? 1 : abs(dungeon[m-1][n-1]) + 1);
            }
            else {
                int down = (i+1 >= m) ? 1e9 : t[i+1][j];
                int right = (j+1 >= n) ? 1e9 : t[i][j+1];

                int res = min(down, right) - dungeon[i][j];
                t[i][j] = (res > 0 ? res : 1);
            }
        }
    }
    return t[0][0];
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {

    return solve(dungeon);
}
int main() {

    vector<vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int minHealth = calculateMinimumHP(dungeon);
    cout << "Minimum initial health needed: " << minHealth << endl;

    return 0;
}
*/

//                                  Finding 3-Digit Even Numbers

//                                          Approach 1
/*
vector<int> findEvenNumbers(vector<int>& digits) {

    unordered_set <int> st;
    int n = digits.size();

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(i == j || j == k || i == k) {
                    continue;
                }

                int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                if(num >= 100 && num % 2 == 0) {
                    st.insert(num);
                }
            }
        }
    }
    vector<int> result(begin(st), end(st));
    sort(begin(result), end(result));
    return result;
}
int main() {

    vector<int> digits = {2, 1, 3, 0};

    vector<int> evenNumbers = findEvenNumbers(digits);
    cout << "Even numbers formed: ";
    for(int num : evenNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                          Approach 2
/*
vector<int> findEvenNumbers(vector<int>& digits) {

    vector<int> mp(10, 0);
    for(int &digit : digits) {
        mp[digit]++;
    }

    vector<int> result;
    for(int i=1; i <= 9; i++) {
        if(mp[i] == 0) {
            continue;
        }
        mp[i]--;
        for(int j=0; j <= 9; j++) {
            if(mp[j] == 0) {
                continue;
            }
            mp[j]--;
            for(int k=0; k <= 8; k += 2) {
                if(mp[k] == 0) {
                    continue;
                }
                mp[k]--;

                int num = i*100 + j*10 + k;
                result.push_back(num);
                mp[k]++;
            }
            mp[j]++;
        }
        mp[i]++;
    }
    return result;
}
int main() {

    vector<int> digits = {2, 1, 3, 0};

    vector<int> evenNumbers = findEvenNumbers(digits);
    cout << "Even numbers formed: ";
    for(int num : evenNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                          Water Bottles

//                                           Approach 1
/*
int numWaterBottles(int numBottles, int numExchange) {

    int consumed = 0;
    while(numBottles >= numExchange) {
        consumed += numExchange;
        numBottles -= numExchange;
        numBottles += 1;
    }
    return consumed + numBottles;
}
int main() {

    int numBottles = 15;
    int numExchange = 4;

    int totalConsumed = numWaterBottles(numBottles, numExchange);
    cout << "Total bottles you can drink: " << totalConsumed << endl;

    return 0;
}
*/
//                                           Approach 2
/*
int numWaterBottles(int numBottles, int numExchange) {

    int tot = numBottles;
    while (numBottles >= numExchange){
        tot += numBottles / numExchange;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange);
    }
    return tot;
}
int main() {

    int numBottles = 15;
    int numExchange = 4;

    int totalConsumed = numWaterBottles(numBottles, numExchange);
    cout << "Total bottles you can drink: " << totalConsumed << endl;

    return 0;
}
*/
//                                           Approach 3
/*
int numWaterBottles(int numBottles, int numExchange) {

    return numBottles + (numBottles - 1) / (numExchange - 1);
}
int main() {

    int numBottles = 15;
    int numExchange = 4;

    int totalConsumed = numWaterBottles(numBottles, numExchange);
    cout << "Total bottles you can drink: " << totalConsumed << endl;

    return 0;
}
*/

//                                      Crawler Log Folder

//                                         Approach 1
/*
int minOperations(vector<string>& logs) {

    int depth = 0;
    for(string &s : logs) {
        if(s == "../") {
            depth = max(0, depth-1);
        } 
        else if(s == "./") {
            continue;
        } 
        else {
            depth++;
        }
    }
    return depth;
}
int main() {

    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};

    int result = minOperations(logs);
    cout << "Minimum operations to reach main folder: " << result << endl;

    return 0;
}
*/
//                                         Approach 2
/*
int minOperations(vector<string>& logs) {

    stack <string> st;
    for(string& currentOperation : logs) {
        if(currentOperation == "../") {
            if(!st.empty()) {
                st.pop();
            }
        } 
        else if (currentOperation != "./") {
            st.push(currentOperation);
        }
    }
    return st.size();
}
int main() {

    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};

    int result = minOperations(logs);
    cout << "Minimum operations to reach main folder: " << result << endl;

    return 0;
}
*/

//                         Total Characters in String After Transformations I
/*
int M = 1e9 + 7;
int lengthAfterTransformations(string s, int t) {

    vector<int> mp(26, 0);
    for(char &ch : s) {
        mp[ch - 'a']++;
    }

    for(int count = 1; count <= t; count++) {
        vector<int> temp(26, 0);
        for(int i=0; i < 26; i++) {            
            char ch = i + 'a';
            int freq = mp[i];
            if(ch != 'z') {
                temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + freq) % M;
            }
            else {
                temp['a' - 'a'] = (temp['a' - 'a'] + freq) % M;
                temp['b' - 'a'] = (temp['b' - 'a'] + freq) % M;
            }
        }
        mp = move(temp);
    }

    int result = 0;
    for(int i=0; i < 26; i++) {
        result = (result + mp[i]) % M;
    }
    return result;
}
int main() {

    string s = "abcyy";
    int t = 2;

    cout << "Result for (\"abcyy\", 2): " << lengthAfterTransformations(s, t) << endl;

    return 0;
}
*/

//                   Total Characters in String After Transformations II
/*
typedef vector<vector<int>> Matrix;
int MOD = 1e9 + 7;
Matrix matrixMultiplication(const Matrix& A, const Matrix& B) {

    Matrix result(26, vector<int>(26, 0));
    for(int i=0; i < 26; ++i) {
        for(int j=0; j < 26; ++j) {
            for(int k=0; k < 26; ++k) {
                result[i][j] = (result[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return result;
}
Matrix matrixExponentiation(const Matrix& base, int exponent) {

    if(exponent == 0) {
        Matrix identity(26, vector<int>(26, 0));
        for(int i=0; i < 26; ++i) {
            identity[i][i] = 1;
        }
        return identity;
    }

    Matrix half = matrixExponentiation(base, exponent / 2);
    Matrix result = matrixMultiplication(half, half);

    if(exponent % 2 == 1) {
        result = matrixMultiplication(result, base);
    }
    return result;
}
int lengthAfterTransformations(string s, int t, vector<int>& nums) {

    vector<int> freq(26, 0);
    for(char &ch : s) {
        freq[ch - 'a']++;
    }

    Matrix T(26, vector<int>(26, 0));
    for(int i=0; i < 26; ++i) {
        for(int add = 1; add <= nums[i]; ++add)
            T[(i + add) % 26][i]++;
    }

    Matrix result = matrixExponentiation(T, t);

    vector<int> updated_freq(26, 0);
    for(int i=0; i < 26; ++i) {
        for(int j=0; j < 26; ++j) {
            updated_freq[i] = (updated_freq[i] + (1LL * result[i][j] * freq[j]) % MOD) % MOD;
        }
    }

    int resultLength = 0;
    for(int i=0; i < 26; ++i) {
        resultLength = (resultLength + updated_freq[i]) % MOD;
    }
    return resultLength;
}
int main() {
    
    string s = "abcyy";
    int t = 2;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2};

    int resultLength = lengthAfterTransformations(s, t, nums);
    cout << "Length after " << t << " transformations: " << resultLength << endl;

    return 0;
}
*/

//                          Longest Unequal Adjacent Groups Subsequence I
/*
vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

    int n = words.size();

    vector<string> result;
    for(int i=0; i<n; i++) {
        if(i == 0 || groups[i] != groups[i-1]) { 
            result.push_back(words[i]);
        }
    }
    return result;
}
int main() {

    vector<string> words = {"e", "a", "b"};
    vector<int> groups = {0, 0, 1};

    vector<string> result = getLongestSubsequence(words, groups);

    cout << "Longest subsequence by group changes:\n";
    for(const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
*/

//                              Longest Unequal Adjacent Groups Subsequence II
/*
bool check(string& s1, string& s2) {

    if(s1.size() != s2.size()) {
        return false;
    }

    int diff = 0;
    for(int i=0; i < s1.size(); i++) {
        diff += s1[i] != s2[i];
        if(diff > 1) {
            return false;
        }
    }
    return diff == 1;
}
vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

    int n = groups.size();

    vector<int> dp(n, 1);
    vector<int> prev(n, -1);

    int maxIndex = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(check(words[i], words[j]) && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if(dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    vector<string> ans;
    for(int i = maxIndex; i >= 0; i = prev[i]) {
        ans.push_back(words[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {

    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 2, 3, 4};

    vector<string> result = getWordsInLongestSubsequence(words, groups);
    cout << "Longest valid subsequence:" << endl;
    for(const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                  Single Element in a Sorted Array
/*
int singleNonDuplicate(vector<int>& nums) {

    int n = nums.size();

    int l = 0;
    int h = n-1;

    while(l < h) {
        int mid = l + (h-l) / 2;

        bool isEven = mid % 2 == 0;
        if(nums[mid] == nums[mid + 1]) {
            if(isEven) {
                l = mid + 2;
            }
            else {
                h = mid - 1;
            }
        }
        else {
            if(isEven) {
                h = mid;
            }
            else {
                l = mid + 1;
            }
        }
    }
    return nums[h];
}
int main() {

    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int result = singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << result << endl;

    return 0;
}
*/

//                                          Sort Colors
/*
void sortColors(vector<int>& nums) {

    int n = nums.size();

    int i = 0;
    int j = 0;
    int k = n - 1;
    while(j <= k) {
        if(nums[j] == 1) {
            j++;
        }
        else if(nums[j] == 2) {
            swap(nums[j], nums[k--]);
        }
        else {
            swap(nums[j++], nums[i++]);
        }
    }
}
int main() {

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "After sorting:  ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                  Painting a Grid With Three Different

//                                              Recursive
/*
vector<string> columnStates;
const int MOD = 1e9 + 7;
void generateColumnStates(string currentColumn, int rowsRemaining, char prevColor) {

    if(rowsRemaining == 0) {
        columnStates.push_back(currentColumn);
        return;
    }

    for(char color : {'R', 'G', 'B'}) {
        if(color == prevColor) {
            continue;
        }
        generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
    }
}
int solve(int remainingCols, int prevColumnIdx, int m) {

    if(remainingCols == 0) {
        return 1;
    }

    int totalWays = 0;
    string prevColumn = columnStates[prevColumnIdx];
    for(int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++) {
        string nextColumn = columnStates[nextColumnIdx];
        bool valid = true;
        // Check horizontal adjacency (no adjacent same color in same row)
        for(int r=0; r<m; r++) {
            if(prevColumn[r] == nextColumn[r]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            totalWays = (totalWays + solve(remainingCols - 1, nextColumnIdx, m)) % MOD;
        }
    }
    return totalWays;
}
int colorTheGrid(int m, int n) {

    generateColumnStates("", m, '#');

    int numColumnPatterns = columnStates.size();

    int result = 0;
    for(int i=0; i < numColumnPatterns; i++) {
        result = (result + solve(n-1, i, m)) % MOD;
    }
    return result;
}
int main() {

    int m = 5, n = 5; 
    cout << "Number of ways to color a " << m << "x" << n << " grid: " << colorTheGrid(m, n) << endl;

    return 0;
}
*/
//                                              Top-Down
/*
vector<string> columnStates;
const int MOD = 1e9 + 7;
void generateColumnStates(string currentColumn, int rowsRemaining, char prevColor) {

    if(rowsRemaining == 0) {
        columnStates.push_back(currentColumn);
        return;
    }

    for(char color : {'R', 'G', 'B'}) {
        if(color == prevColor) {
            continue;
        }
        generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
    }
}
int solve(int remainingCols, int prevColumnIdx, int m, vector<vector<int>>& dp) {

    if(remainingCols == 0) {
        return 1;
    }

    if(dp[remainingCols][prevColumnIdx] != -1) {
        return dp[remainingCols][prevColumnIdx];
    }

    int totalWays = 0;
    string prevColumn = columnStates[prevColumnIdx];
    for(int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++) {
        string nextColumn = columnStates[nextColumnIdx];
        bool valid = true;
        // Check horizontal adjacency (no adjacent same color in same row)
        for(int r=0; r<m; r++) {
            if(prevColumn[r] == nextColumn[r]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            totalWays = (totalWays + solve(remainingCols - 1, nextColumnIdx, m, dp)) % MOD;
        }
    }
    return dp[remainingCols][prevColumnIdx] = totalWays;
}
int colorTheGrid(int m, int n) {

    generateColumnStates("", m, '#');
    int numColumnPatterns = columnStates.size();

    vector<vector<int>> dp(n, vector<int>(numColumnPatterns, -1));

    int result = 0;
    for(int i=0; i < numColumnPatterns; i++) {
        result = (result + solve(n-1, i, m, dp)) % MOD;
    }
    return result;
}
int main() {

    int m = 5, n = 5; 
    cout << "Number of ways to color a " << m << "x" << n << " grid: " << colorTheGrid(m, n) << endl;

    return 0;
}
*/

//                                 Number of Ways to Paint N × 3 Grid

//                                              Recursive
/*
vector<string> rowStates;
const int MOD = 1e9 + 7;
void generateRowStates(string currentRow, int columnsRemaining, char prevColor) {

    if(columnsRemaining == 0) {
        rowStates.push_back(currentRow);
        return;
    }

    for(char color : {'R', 'G', 'Y'}) {
        if(color == prevColor) {
            continue;
        }
        generateRowStates(currentRow + color, columnsRemaining - 1, color);
    }
}
int solve(int remainingRows, int prevRowIdx, int m) {

    if(remainingRows == 0) {
        return 1;
    }

    int totalWays = 0;
    string prevRow = rowStates[prevRowIdx];
    for(int nextRowIdx = 0; nextRowIdx < rowStates.size(); nextRowIdx++) {
        string nextRow = rowStates[nextRowIdx];
        bool valid = true;
        // Check horizontal adjacency (no adjacent same color in same column)
        for(int r=0; r<m; r++) {
            if(prevRow[r] == nextRow[r]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            totalWays = (totalWays + solve(remainingRows - 1, nextRowIdx, m)) % MOD;
        }
    }
    return totalWays;
}
int numOfWays(int n) {

    generateRowStates("", 3, '#');
    int numRowPatterns = rowStates.size();

    int result = 0;
    for(int i=0; i < numRowPatterns; i++) {
        result = (result + solve(n-1, i, 3)) % MOD;
    }
    return result;
}
int main() {

    int n = 10;

    int result = numOfWays(n);
    cout << "Number of ways to color " << n << "x3 grid: " << result << endl;

    return 0;
}
*/
//                                              Top-Down
/*
vector<string> rowStates;
const int MOD = 1e9 + 7;
void generateRowStates(string currentRow, int columnsRemaining, char prevColor) {

    if(columnsRemaining == 0) {
        rowStates.push_back(currentRow);
        return;
    }

    for(char color : {'R', 'G', 'Y'}) {
        if(color == prevColor) {
            continue;
        }
        generateRowStates(currentRow + color, columnsRemaining - 1, color);
    }
}
int solve(int remainingRows, int prevRowIdx, int m, vector<vector<int>>& dp) {

    if(remainingRows == 0) {
        return 1;
    }

    if(dp[remainingRows][prevRowIdx] != -1) {
        return dp[remainingRows][prevRowIdx];
    }

    int totalWays = 0;
    string prevRow = rowStates[prevRowIdx];
    for(int nextRowIdx = 0; nextRowIdx < rowStates.size(); nextRowIdx++) {
        string nextRow = rowStates[nextRowIdx];
        bool valid = true;
        // Check horizontal adjacency (no adjacent same color in same row)
        for(int r=0; r<m; r++) {
            if(prevRow[r] == nextRow[r]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            totalWays = (totalWays + solve(remainingRows - 1, nextRowIdx, m, dp)) % MOD;
        }
    }
    return dp[remainingRows][prevRowIdx] = totalWays;
}
int numOfWays(int n) {

    generateRowStates("", 3, '#');
    int numRowPatterns = rowStates.size();

    vector<vector<int>> dp(n, vector<int>(numRowPatterns, -1));

    int result = 0;
    for(int i=0; i < numRowPatterns; i++) {
        result = (result + solve(n-1, i, 3, dp)) % MOD;
    }
    return result;
}
int main() {

    int n = 5000;

    int result = numOfWays(n);
    cout << "Number of ways to color " << n << "x3 grid: " << result << endl;

    return 0;
}
*/

//                                           Type of Triangle
/*
string triangleType(vector<int>& nums) {

    bool valid = (nums[0] + nums[1] > nums[2]) && (nums[0] + nums[2] > nums[1]) && (nums[1] + nums[2] > nums[0]);
    if(!valid) {
        return "none";
    }

    if(nums[0] == nums[1] && nums[1] == nums[2]) {
        return "equilateral";
    }
    else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
        return "scalene";
    }
    return "isosceles";
}
int main() {

    vector<int> sides = {3, 4, 5};
    cout << "Triangle type: " << triangleType(sides) << endl;

    return 0;
}
*/

//                                        Range Addition
/*
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

    vector<int> res(length, 0);
    for(auto& update : updates) {
        int start = update[0];
        int end = update[1];
        int inc = update[2];
        res[start] += inc;
        if(end + 1 < length) {
            res[end + 1] -= inc;
        }
    }

    for(int i=1; i < length; ++i) {
        res[i] += res[i-1];
    }
    return res;
}
int main() {

    int length = 5;
    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };

    vector<int> result = getModifiedArray(length, updates);
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                    Zero Array Transformation I
/*
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

    int n = nums.size();

    // Step 1: Make diff array using query
    vector<int> diff(n, 0);
    for(auto &query : queries) {
        int start = query[0];
        int end = query[1];
        int x = 1;
        diff[start] += x;
        if(end + 1 < n) {
            diff[end + 1] -= x;
        }
    }

    // Step 2: Find cumulative effect on each index
    vector<int> result(n, 0);
    int cumSum = 0;
    for(int i=0; i<n; i++) {
        cumSum += diff[i];
        result[i] = cumSum;
    }

    for(int i=0; i<n; i++) {
        // nums[i] won't become 0 ever
        if(result[i] < nums[i]) { 
            return false;
        }
    }
    return true;
}
int main() {

    vector<int> nums = {4, 3, 2, 1};
    vector<vector<int>> queries = {{1, 3}, {0, 2}};

    if(isZeroArray(nums, queries)) {
        cout << "Yes, it can be reduced to zero." << endl;
    } 
    else {
        cout << "No, it cannot be reduced to zero." << endl;
    }
    return 0;
}
*/

//                                          Set Matrix Zeroes

//                                             Approach 1
/*
void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> temp = matrix;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 0) {
                // Zero out the entire row
                for(int k=0; k<n; k++) {
                    temp[i][k] = 0; 
                }
                // Zero out the entire column
                for(int k=0; k<m; k++) {
                    temp[k][j] = 0; 
                }
            }
        }
    }
    matrix = temp;
}
int main() {

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(matrix);

    cout << "Matrix after applying setZeroes:" << endl;
    for(int i=0; i < matrix.size(); i++) {
        for(int j=0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
//                                             Approach 2
/*
void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();   
    int n = matrix[0].size();

    vector<bool> row(m, false);
    vector<bool> col(n, false);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(matrix[i][j] == 0) {
                // Mark it for zero
                row[i] = true; 
                col[j] = true;
            }
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
int main() {

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(matrix);

    cout << "Matrix after applying setZeroes:" << endl;
    for(int i=0; i < matrix.size(); i++) {
        for(int j=0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
//                                             Approach 3
/*
void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check first row and col separately
    for(int i=0; i<m; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = true;
        }
    }
    for(int j=0; j<n; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = true;
        }
    }

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero) {
        for(int j=0; j<n; j++) {
            matrix[0][j] = 0;
        }
    }
    if(firstColZero) {
        for(int i=0; i<m; i++) {
            matrix[i][0] = 0;
        }
    }
}
int main() {

    vector<vector<int>> matrix = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    setZeroes(matrix);

    cout << "Matrix after applying setZeroes:" << endl;
    for(int i=0; i < matrix.size(); i++) {
        for(int j=0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

//                                     Zero Array Transformation III
/*
int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

    int n = nums.size();

    // Min-heap of used queries' end indices
    priority_queue <int, vector<int>, greater<int>> past;

    // Max-heap of available queries' end indices
    priority_queue <int> maxHeap;

    // Sort queries by start index
    sort(queries.begin(), queries.end());

    // Pointer to queries
    int j = 0;       

    // Number of queries actually used  
    int usedCount = 0; 
    for(int i=0; i<n; ++i) {
        // Push all queries starting at index i into maxHeap
        while(j < queries.size() && queries[j][0] == i) {
            // Push only the end
            maxHeap.push(queries[j][1]); 
            ++j;
        }

        // Apply effect of already-used queries
        nums[i] -= past.size();

        // Apply more queries if needed
        while(nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
            int r = maxHeap.top();
            maxHeap.pop();
            past.push(r);
            usedCount++;
            nums[i]--;
        }

        // If we can't reduce nums[i] to 0
        if(nums[i] > 0) {
            return -1;
        }

        // Remove expired queries
        while(!past.empty() && past.top() == i) {
            past.pop();
        }
    }
    return queries.size() - usedCount;
}
int main() {

    vector<int> nums = {1, 1, 1, 1};
    vector<vector<int>> queries = {{1, 3}, {0, 2}, {1, 3}, {1, 2}};

    int result = maxRemoval(nums, queries);
    cout << "Maximum unused queries: " << result << endl;

    return 0;
}
*/

//                                 Find the Maximum Sum of Node Values

//                                              Approach 1
/*
typedef long long ll;
long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

    ll sum = 0;
    int count = 0;
    int minNukasan = INT_MAX;

    for(ll num : nums) {
        if((num ^ k) > num) {
            count++;
            sum += (num ^ k);
        }
        else {
            sum += num;
        }
        minNukasan = min((ll)minNukasan, abs(num - (num ^ k)));
    }
    if(count % 2 == 0) {
        return sum;
    }
    return sum - minNukasan;
}
int main() {

    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};

    ll result = maximumValueSum(nums, k, edges);
    cout << "Maximum Value Sum: " << result << endl;

    return 0;
}
*/
//                                              Approach 2
/*
typedef long long ll;
ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

    vector<int> fayda;

    ll normalSum = 0;
    for(int i=0; i < nums.size(); i++) {
        fayda.push_back((nums[i] ^ k) - nums[i]);
        normalSum += (ll)nums[i];
    }

    sort(fayda.begin(), fayda.end(), greater<int>());
    for(int i=0; i < fayda.size() - 1; i += 2) {
        ll pairSum = fayda[i] + fayda[i+1];
        if(pairSum > 0) {
            normalSum += pairSum;
        }
    }
    return normalSum;
}
int main() {

    vector<int> nums = {1, 2, 1};
    int k = 3;
    vector<vector<int>> edges = {{0, 1}, {0, 2}};

    ll result = maximumValueSum(nums, k, edges);
    cout << "Maximum Value Sum: " << result << endl;

    return 0;
}
*/

//                                 Find Words Containing Character
/*
vector<int> findWordsContaining(vector<string>& words, char x) {

    vector <int> res;
    for(int i=0 ; i < words.size() ; i++) {
        for(int j=0 ; j < words[i].size() ; j++) {
            if(words[i][j] == x) {
                res.push_back(i);
                break;
            }
        }
    }
    return res;
}
int main() {

    vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
    char x = 'a';
    
    vector<int> indices = findWordsContaining(words, x);
    
    for(int i : indices) {
        cout << i << " ";
    }
    return 0;
}
*/

//                      Longest Palindrome by Concatenating Two Letter Words

//                                          Approach 1
/*
int longestPalindrome(vector<string>& words) {

    unordered_map<string, int> mp;

    int result = 0;
    for(string &word : words) {
        string reversedWord = word;
        swap(reversedWord[0], reversedWord[1]);
        if(mp[reversedWord] > 0) {
            result += 4;
            mp[reversedWord]--;
        } 
        else {
            mp[word]++;
        }
    }
    // Check equal character words. Use only one
    for(auto &it : mp) {
        string word = it.first;
        int count = it.second;

        if(word[0] == word[1] && count > 0) {
            result += 2;
            break;
        }
    }
    return result;
}
int main() {

    vector<string> words = {"lc", "cl", "gg"};

    int maxLength = longestPalindrome(words);
    cout << "Longest palindrome length: " << maxLength << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int longestPalindrome(vector<string>& words) {

        unordered_map<string, int> mp;    
        
    // Update map with frequency
    for(string &word : words) {
        mp[word]++;
    }
        
    // For frequency one waale strings
    bool centerUsed = false; 
        
    int result = 0;  
    for(string &word : words) {
        string rev = word;
        reverse(begin(rev), end(rev));    
        if(rev != word) { 
            if(mp[word] > 0 && mp[rev] > 0) {
                mp[word]--;
                mp[rev]--;
                result += 4;
            }
        } 
        else {
            if(mp[word] >= 2) {
                mp[word] -= 2;
                result += 4;
            } 
            else if(mp[word] == 1 && centerUsed == false) {
                mp[word]--;
                result += 2;
                // Ab use hogaya hai center wala
                centerUsed = true; 
            }
        }
    }
    return result;
}
int main() {

    vector<string> words = {"lc", "cl", "gg"};

    int maxLength = longestPalindrome(words);
    cout << "Longest palindrome length: " << maxLength << endl;

    return 0;
}
*/

//                          Largest Color Value in a Directed Graph
/*
int largestPathValue(string colors, vector<vector<int>>& edges) {

    unordered_map<int, vector<int>> adj;
    int N = colors.size();
        
    vector<int> indegree(N, 0);    
    for(auto &vec : edges) {
        int u = vec[0];
        int v = vec[1];        
        adj[u].push_back(v);
        indegree[v]++;        
    }
        
    queue <int> que;
    vector<vector<int>> t(N, vector<int>(26, 0));    
    for(int i=0; i<N; i++) {
        if(indegree[i] == 0) {
            que.push(i);
            t[i][colors[i] - 'a'] = 1;
        }
    }
    int answer = 0;    
    int countNodes = 0;    
    while(!que.empty()) {        
        int u = que.front();
        que.pop();        
        countNodes++;    
        answer = max(answer, t[u][colors[u] - 'a']);    
        for(int &v : adj[u]) {        
            for(int i=0; i<26; i++) {        
                t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));    
            }    
            indegree[v]--;
            if(indegree[v] == 0) {
                que.push(v);
            }
        }    
    }    
    if(countNodes < N) {
        return -1;
    }
    return answer;
}
int main() {
    
    string colors = "abaca";
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};

    int result = largestPathValue(colors, edges);
    cout << "Largest Color Value: " << result << endl;

    return 0;
}
*/

//                             Divisible and Non-divisible Sums Difference

//                                             Approach 1
/*
int differenceOfSums(int n, int m) {

    int num1 = 0;
    int num2 = 0;
    for(int i=1; i <= n; i++) {
        if(i % m != 0) {
            num1 += i;
        }
        else {
            num2 += i;
        }
    }
    return num1 - num2;
}
int main() {
    
    int result1 = differenceOfSums(10, 3);
    cout << "Difference of sums (n=10, m=3): " << result1 << endl;

    return 0;
}
*/
//                                             Approach 2
/*
int differenceOfSums(int n, int m) {

    int k = n/m;
    return n * (n+1) / 2 - m * k * (k+1);
}
int main() {
    
    int result1 = differenceOfSums(10, 3);
    cout << "Difference of sums (n=10, m=3): " << result1 << endl;

    return 0;
}
*/

//                     Maximize the Number of Target Nodes After Connecting Trees I

//                                          Approach 1 
/*
int bfs(int curr, unordered_map<int, vector<int>>& adj, int d, int N) {

    queue <pair<int, int>> que;
    que.push({curr, 0});
    vector<bool> visited(N, false);
    visited[curr] = true;

    // Count the target nodes
    int count = 0; 
    while(!que.empty()) {
        int currNode = que.front().first;
        int dist = que.front().second;
        que.pop();

        if(dist > d) {
            continue;
        }
        // Include current node in targetNodes count
        count++; 
        // Visit neighbors of currNode
        for(auto &ngbr : adj[currNode]) {
            if(!visited[ngbr]) {
                visited[ngbr] = true;
                que.push({ngbr, dist+1});
            }
        }
    }
    return count;
}
vector<int> findCount(vector<vector<int>>& edges, int d) {

    int N = edges.size()+1;

    // Adjacency list
    unordered_map <int, vector<int>> adj;
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result(N);
    for(int i=0; i<N; i++) {
        result[i] = bfs(i, adj, d, N);
    }
    return result;
}
vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

    // Tree 1 me kitne nodes hain
    int N = edges1.size() + 1;

    // Stores targetnodes count from each node within tree1 within k distance
    vector<int> result1 = findCount(edges1, k); 
    // Stores targetnodes count from each node within tree2 within k-1 distance
    vector<int> result2 = findCount(edges2, k-1); 

    int maxTargetNodesCount = *max_element(begin(result2), end(result2));
    for(int i=0; i < result1.size(); i++) {
        result1[i] += maxTargetNodesCount;
    }
    return result1;
}
int main() {
    
    vector<vector<int>> edges1 = {
        {0, 1}, {0, 2}, {2, 3}, {2, 4}
    };
    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}
    };
    int k = 2;

    vector<int> finalResult = maxTargetNodes(edges1, edges2, k);
    cout << "Final Result: ";
    for (int count : finalResult) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int dfs(int curr, unordered_map<int, vector<int>>& adj, int d, int currNodeKaParent) {

    if(d < 0) {
        return 0;
    }
        
    // Counting current node as 1
    int count = 1; 
    for(int &ngbr : adj[curr]) {
        if(ngbr != currNodeKaParent) {
            count += dfs(ngbr, adj, d-1, curr);
        }
    }
    return count;
}
vector<int> findCount(vector<vector<int>>& edges, int d) {

    int N = edges.size() + 1;

    // Adjacency list
    unordered_map <int, vector<int>> adj;
    for(auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> result(N);
    for(int i=0; i<N; i++) {
        result[i] = dfs(i, adj, d, -1);
    }
    return result;
}
vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

    // Tree 1 me kitne nodes hain
    int N = edges1.size() + 1;

    // Stores targetnodes count from each node within tree1 within k distance
    vector<int> result1 = findCount(edges1, k); 
    // Stores targetnodes count from each node within tree2 within k-1 distance
    vector<int> result2 = findCount(edges2, k-1); 

    int maxTargetNodesCount = *max_element(begin(result2), end(result2));
    for(int i=0; i < result1.size(); i++) {
        result1[i] += maxTargetNodesCount;
    }
    return result1;
}
int main() {
    
    vector<vector<int>> edges1 = {
        {0, 1}, {0, 2}, {2, 3}, {2, 4}
    };
    vector<vector<int>> edges2 = {
        {0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}
    };
    int k = 2;

    vector<int> finalResult = maxTargetNodes(edges1, edges2, k);
    cout << "Final Result: ";
    for (int count : finalResult) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
*/

//                    Maximize the Number of Target Nodes After Connecting Trees II
/*
unordered_map <int, vector<int>> getAdj(vector<vector<int>>& edges) {

    unordered_map <int, vector<int>> adj;
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
void dfs(int curr, unordered_map <int, vector<int>>& adj, int parent, vector<int>& mark, int& zeroMarkedCount, int& oneMarkedCount) {

    if(mark[curr] == 0) {
        zeroMarkedCount++;
    } 
    else {
        oneMarkedCount++;
    }

    for(auto &ngbr : adj[curr]) {
        if(ngbr != parent) {
            mark[ngbr] = (mark[curr] == 0) ? 1 : 0;
            dfs(ngbr, adj, curr, mark, zeroMarkedCount, oneMarkedCount);
        }
    }
}
vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

    // Tree A
    int N = edges1.size() + 1; 
    // Tree B
    int M = edges2.size() + 1; 

    unordered_map <int, vector<int>> adjA = getAdj(edges1); 
    unordered_map <int, vector<int>> adjB = getAdj(edges2);

    vector<int> markA(N, -1);
    // Mark 0th node as 0
    markA[0] = 0; 
    int zeroMarkedCountA = 0;
    int oneMarkedCountA = 0;
    dfs(0, adjA, -1, markA, zeroMarkedCountA, oneMarkedCountA);

    vector<int> markB(M, -1);
    // Mark 0th node as 0
    markB[0] = 0;
    int zeroMarkedCountB = 0;
    int oneMarkedCountB = 0;
    dfs(0, adjB, -1, markB, zeroMarkedCountB, oneMarkedCountB);
    int maxFromTree2 = max(zeroMarkedCountB, oneMarkedCountB);

    vector<int> result(N);
    for(int i=0; i<N; i++) {
        result[i] = (markA[i] == 0 ? zeroMarkedCountA : oneMarkedCountA) + maxFromTree2;
    }
    return result;
}
int main() {

    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0,1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};

    vector<int> result = maxTargetNodes(edges1, edges2);
    cout << "Result: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                              Find Closest Node to Given Two Nodes

//                                           Approach 1
/*
int n;
void bfs(vector<int>& edges, int startNode, vector<int>& dist_node) {

    queue<int> que;
    que.push(startNode);
    
    vector<bool> visited(n, false);
    visited[startNode] = true;

    dist_node[startNode] = 0;
    while(!que.empty()) {
        int u = que.front();
        que.pop();       
        int v = edges[u];
            
        if(v != -1 && !visited[v]) {
            visited[v] = true;
            dist_node[v] = 1 + dist_node[u];
            que.push(v);
        }
    }
} 
int closestMeetingNode(vector<int>& edges, int node1, int node2) {

    n = edges.size();    

    vector<int> dist1(n, INT_MAX);
    bfs(edges, node1, dist1);

    vector<int> dist2(n, INT_MAX);
    bfs(edges, node2, dist2);
        
    int minDistNode = -1;
    int minDistTillNow = INT_MAX;
    for(int i=0; i<n; i++) {
        int maxD = max(dist1[i], dist2[i]);    
        if(minDistTillNow > maxD) {
            minDistNode = i;
            minDistTillNow = maxD;
        }
    }
    return minDistNode;        
}
int main() {

    vector<int> edges = {2, 2, 3, -1};
    int node1 = 0;
    int node2 = 1;

    int result = closestMeetingNode(edges, node1, node2);
    cout << "Closest meeting node: " << result << endl;

    return 0;
}
*/
//                                           Approach 2
/*
int n;
void dfs(vector<int>& edges, int startNode, vector<int>& dist_node, vector<bool>& visited) {

    visited[startNode] = true;
        
    int v = edges[startNode];    
    if(v != -1 && !visited[v]) {
        visited[v] = true;
        dist_node[v] = 1 + dist_node[startNode];
        dfs(edges, v, dist_node, visited);
    }
}    
int closestMeetingNode(vector<int>& edges, int node1, int node2) {

    n = edges.size();    

    vector<bool> visited1(n, false);
    vector<int> dist1(n, INT_MAX);
    dist1[node1] = 0;
    dfs(edges, node1, dist1, visited1);

    vector<bool> visited2(n, false);
    vector<int> dist2(n, INT_MAX);
    dist2[node2] = 0;
    dfs(edges, node2, dist2, visited2);
        
    int minDistNode = -1;
    int minDistTillNow = INT_MAX;
    for(int i=0; i<n; i++) {
        int maxD = max(dist1[i], dist2[i]);    
        if(minDistTillNow > maxD) {
            minDistNode = i;
            minDistTillNow = maxD;
        }
    }
    return minDistNode;        
}
int main() {

    vector<int> edges = {2, 2, 3, -1};
    int node1 = 0;
    int node2 = 1;

    int result = closestMeetingNode(edges, node1, node2);
    cout << "Closest meeting node: " << result << endl;

    return 0;
}
*/

//                                         Snakes and Ladders
/*
int n;
pair<int, int> getCoord(int s) {

    int row = (n-1) - (s-1)/n;
    int col = (s-1) % n;
        
    if((n % 2 == 1 && row % 2 == 1)||(n % 2 == 0 && row % 2 == 0)) {
        col = n-1-col;
    }
    return make_pair(row, col);
}
int snakesAndLadders(vector<vector<int>>& board) {

    n = board.size();
        
    queue<int> que; 
    que.push(1);

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[n-1][0] = true;

    int steps = 0;
    while(!que.empty()) {        
        int N = que.size();
        while(N--) {        
            int x = que.front();
            que.pop();
            if(x == n*n) {
                return steps;
            }
            for(int k=1; k <= 6; k++) {
                if(x+k > n*n) {
                    break;
                }
                pair<int, int> coord = getCoord(x+k);
                int r = coord.first;
                int c = coord.second;
                if(visited[r][c] == true) {
                    continue;
                }
                visited[r][c] = true;
                if(board[r][c] == -1) {
                    que.push(k+x);
                }
                else {
                    que.push(board[r][c]);
                }
            }
        }
        steps++;
    }    
    return -1;
}
int main() {

    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}
    };

    int result = snakesAndLadders(board);
    cout << "Minimum moves to reach the end: " << result << endl;

    return 0;
}
*/

//                                Distribute Candies Among Children I
/*
int distributeCandies(int n, int limit) {

    int count = 0;
    for(int ch1=0; ch1 <= limit; ch1++) {
        for(int ch2=0; ch2 <= limit; ch2++) {
            int ch3 = n - (ch1 + ch2);
            if(ch3 >= 0 && ch3 <= limit) {
                count++;
            }
        }
    }
    return count;
}
int main() {

    int n = 5;
    int limit = 2;

    int result = distributeCandies(n, limit);
    cout << "Number of ways to distribute candies: " << result << endl;

    return 0;
}
*/

//                              Distribute Candies Among Children II
/*
long long distributeCandies(int n, int limit) {

    // Child1
    int minCh1 = max(0, n - 2*limit);
    int maxCh1 = min(n, limit);

    long long ways = 0;
    for(int i = minCh1; i <= maxCh1; i++) { 
        // For ch2 and ch3
        int N = n-i; 
        int minCh2 = max(0, N - limit);
        int maxCh2 = min(N, limit);
        ways += maxCh2 - minCh2 + 1;
    }
    return ways;
}
int main() {

    int n = 5;
    int limit = 2;

    int result = distributeCandies(n, limit);
    cout << "Number of ways to distribute candies: " << result << endl;

    return 0;
}
*/

//                                             Candy

//                                           Approach 1
/*
int candy(vector<int>& ratings) {

    int n = ratings.size();
        
    vector<int> L2R(n, 1);
    vector<int> R2L(n, 1);
        
    // First comparing with only left neighbour
    for(int i=1; i<n; i++) {
        if(ratings[i] > ratings[i-1]) {
            L2R[i] = max(L2R[i], L2R[i-1] + 1);
        }
    }
        
    // Then comparing with only right neighbour
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            R2L[i] = max(R2L[i], R2L[i+1] + 1);
        }
    }
        
    int result = 0;
    for(int i=0; i<n; i++) {
        result += max(L2R[i], R2L[i]);
    }    
    return result;
}
int main() {

    vector<int> ratings = {1, 0, 2};

    int totalCandies = candy(ratings);
    cout << "Minimum candies needed: " << totalCandies << endl;

    return 0;
}
*/
//                                           Approach 2
/*
int candy(vector<int>& ratings) {

    int n = ratings.size();
    vector<int> count(n, 1);
        
    // First comparing with only left neighbour
    for(int i=1; i<n; i++) {
        if(ratings[i] > ratings[i-1]) {
            count[i] = max(count[i], count[i-1] + 1);
        }
    }
        
    // Then comparing with only right neighbour
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            count[i] = max(count[i], count[i+1] + 1);
        }
    }
        
    int result = 0;
    for(int i=0; i<n; i++) {
        result += count[i];
    }    
    return result;
}
int main() {

    vector<int> ratings = {1, 0, 2};

    int totalCandies = candy(ratings);
    cout << "Minimum candies needed: " << totalCandies << endl;

    return 0;
}
*/

//                                 Maximum Candies You Can Get from Boxes

//                                              Approach 1
/*
int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        
    if(visited.count(box)) {
        return 0;
    }

    if(status[box] == 0) {
        foundBoxes.insert(box);
        return 0;
    }

    visited.insert(box);
    int candiesCollected = candies[box];
    for(int &insideBox : containedBoxes[box]) {
        candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
    }

    for(int &boxKey : keys[box]) {
        // Can be opened
        status[boxKey] = 1; 
        if(foundBoxes.count(boxKey)) {
            candiesCollected += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
        }
    }
    return candiesCollected;
}
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
    unordered_set<int> visited;
    unordered_set<int> foundBoxes;
    
    int candiesCollected = 0;
    for(int &box : initialBoxes) {
        candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
    }
    return candiesCollected;
}
int main() {
    
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    int result = maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies collected: " << result << endl;

    return 0;
}
*/
//                                              Approach 2
/*
int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
    unordered_set<int> visited;
    unordered_set<int> foundBoxes;
    
    // Insert those which you have now and you can open it
    queue<int> que; 

    int candiesCollected = 0;
    for(int &box : initialBoxes) {
        foundBoxes.insert(box);
        if(status[box] == 1) {
            que.push(box);
            visited.insert(box);
            candiesCollected += candies[box];
        }
    }

    while(!que.empty()) {
        int box = que.front();
        que.pop();
        for(int &insideBox : containedBoxes[box]) {
            foundBoxes.insert(insideBox);
            if(status[insideBox] == 1 && !visited.count(insideBox)) {
                que.push(insideBox);
                visited.insert(insideBox);
                candiesCollected += candies[insideBox];
            }
        }

        // Can be opened in future if we reach this box
        for(int &boxKey : keys[box]) {
            status[boxKey] = 1; 
            if(foundBoxes.count(boxKey) && !visited.count(boxKey)) {
                que.push(boxKey);
                visited.insert(boxKey);
                candiesCollected += candies[boxKey];
            }
        }
    }
    return candiesCollected;
}
int main() {
    
    vector<int> status = {1, 0, 1, 0};
    vector<int> candies = {7, 5, 4, 100};
    vector<vector<int>> keys = {{}, {}, {1}, {}};
    vector<vector<int>> containedBoxes = {{1, 2}, {3}, {}, {}};
    vector<int> initialBoxes = {0};

    int result = maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << "Maximum candies collected: " << result << endl;

    return 0;
}
*/

//                     Find the Lexicographically Largest String From the Box I

//                                          Approach 1
/*
string answerString(string word, int numFriends) {

    int n = word.length();
    if(numFriends == 1) {
        return word;
    }
    
    int longestPossible = n - (numFriends - 1);

    string result;
    for(int i=0; i<n; i++) {
        int canTakeLength = min(longestPossible, n-i);
        result = max(result, word.substr(i, canTakeLength));
    }
    return result;
}
int main() {

    string word = "dbca";
    int numFriends = 2;

    string result = answerString(word, numFriends);
    cout << "Answer String: " << result << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int bestStartingPoint(string& word, int n) {

    // Best starting point
    int i = 0; 

    // Keep moving to find the best starting point
    int j = 1; 
    while(j < n) {
        int k = 0;
        // Skipping equal characters
        while(j+k < n && word[i+k] == word[j+k]) {
            k++;
        }

        // Updating best starting point
        if(j+k < n && word[j+k] > word[i+k]) {
            i = j; 
            j = j+1;
        } 
        // Skipping already checked characters
        else {
            j = j + k + 1; 
        }
    }
    return i;
}
string answerString(string word, int numFriends) {

    int n = word.length();
    if(numFriends == 1) {
        return word;
    }
        
    int i = bestStartingPoint(word, n);
    int longestPossibleLength = n - (numFriends - 1);
    int canTakePossible = min(longestPossibleLength, n-i);

    return word.substr(i, canTakePossible);
}
int main() {

    string word = "dbca";
    int numFriends = 2;

    string result = answerString(word, numFriends);
    cout << "Answer String: " << result << endl;

    return 0;
}
*/

//                             Lexicographically Smallest Equivalent String
/*
char DFS(unordered_map <char, vector<char>>& adj, char curr, vector<int>& visited) {

    visited[curr - 'a'] = 1;

    char minChar = curr;    
    for(char &v : adj[curr]) {        
        if(visited[v - 'a'] == 0) {
            minChar = min(minChar, DFS(adj, v, visited));
        }
    }    
    return minChar;
}
string smallestEquivalentString(string s1, string s2, string baseStr) {

    int n = s1.length();
    int m = baseStr.length();

    unordered_map<char, vector<char>> adj;
    for(int i=0; i<n; i++) {
        char u = s1[i];
        char v = s2[i];  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
        
    string result; 
    for(int i=0 ; i<m; i++) {
        char ch = baseStr[i];    
        vector<int> visited(26, 0);    
        result.push_back(DFS(adj, ch, visited));
    }    
    return result;
}
int main() {

    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    
    string res = smallestEquivalentString(s1, s2, baseStr);
    cout << "Smallest Equivalent String: " << res << endl;
    
    return 0;
}
*/

//                                          Pascal's Triangle
/*
vector<vector<int>> generate(int numRows) {

    vector<vector<int>> result(numRows);
    for(int i=0; i < numRows; i++) {
        result[i] = vector<int>(i+1, 1);    
        for(int j=1; j<i; j++) {        
            result[i][j] = result[i-1][j] + result[i-1][j-1];    
        }            
    }    
    return result;
}
int main() {

    int numRows = 5; 

    vector<vector<int>> pascalTriangle = generate(numRows);
    for(int i=0; i < pascalTriangle.size(); i++) {
        for (int j=0; j < pascalTriangle[i].size(); j++) {
            cout << pascalTriangle[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

//                                        Next Permutation
/*
void nextPermutation(vector<int>& nums) {

    int n = nums.size();
        
    int i = n-1;
    for(; i>0; i--) {
        if(nums[i] > nums[i-1]) {
            break;
        }
    }
    if(i != 0) {
        for(int j = n-1; j >= i; j--) {
            if(nums[j] > nums[i-1]) {
                swap(nums[i-1], nums[j]);
                break;
            }
        }    
    }
    reverse(nums.begin()+i, nums.end());
}
int main() {

    vector<int> nums = {1, 2, 3};  

    cout << "Original: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    nextPermutation(nums);

    cout << "Next Permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
*/

//                                     String Duplicates Removal
/*
string removeDuplicates(string& s) {

    unordered_map <char, int> visited;

    string result;
    for(int i=0; i < s.length(); i++) {
        if(!visited[s[i]]){
            visited[s[i]] = 1;
            result.push_back(s[i]);
        }
    }
    return result;
}
int main() {

    string s = "geEksforGEeks";
    cout << "String after removing duplicates: " << removeDuplicates(s) << endl;

    return 0;
}
*/

//                                    Remove Duplicate Letters
/*
string removeDuplicateLetters(string s) {

    int n = s.length();
        
    vector<int> lastIndex(26); 
    for(int i=0; i<n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }
        
    vector<bool> visited(26, false);
    string result;
    for(int i=0; i<n; i++) {
        if(!visited[s[i] - 'a']) {
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = 0;
                result.pop_back();
            }
            result.push_back(s[i]);
            visited[s[i] - 'a'] = 1;
        }
    }
    return result;
}
int main() {

    string s = "cbacdcbc";
    cout << "String after removing duplicates: " << removeDuplicateLetters(s) << endl;

    return 0;
}
*/

//                               Smallest Subsequence of Distinct Characters
/*
string smallestSubsequence(string s) {

    int n = s.length();
        
    vector<int> lastIndex(26); 
    for(int i=0; i<n; i++) {
        lastIndex[s[i] - 'a'] = i;
    }
        
    vector<bool> visited(26, false);
    string result;
    for(int i=0; i<n; i++) {
        if(!visited[s[i] - 'a']) {
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
                visited[result.back() - 'a'] = 0;
                result.pop_back();
            }
            result.push_back(s[i]);
            visited[s[i] - 'a'] = 1;
        }
    }
    return result;
}
int main() {

    string s = "cbacdcbc";
    cout << "String after removing duplicates: " << smallestSubsequence(s) << endl;

    return 0;
}
*/

//                                  Delete Node in a Linked List

//                                            Approach 1
/*
class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = NULL;
        }
};
void deleteNode(ListNode* node) {

    ListNode* prev = NULL;
    while(node && node->next) {
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    prev->next = NULL;
    delete(node);
}
int main() {

    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Print original list
    cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete node with value 5 (i.e. second node)
    ListNode* nodeToDelete = head->next;
    deleteNode(nodeToDelete);

    // Print list after deletion
    cout << "List after deleting node with value 5: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    while (head) {
        ListNode* del = head;
        head = head->next;
        delete del;
    }
    return 0;
}
*/
//                                            Approach 2
/*
class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = NULL;
        }
};
void deleteNode(ListNode* node) {

    ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}
int main() {

    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Print original list
    cout << "Original List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Delete node with value 5 (i.e. second node)
    ListNode* nodeToDelete = head->next;
    deleteNode(nodeToDelete);

    // Print list after deletion
    cout << "List after deleting node with value 5: ";
    temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    while (head) {
        ListNode* del = head;
        head = head->next;
        delete del;
    }
    return 0;
}
*/

//                  Using a Robot to Print the Lexicographically Smallest String
/*
string robotWithString(string s) {

    int n = s.length();
    vector<int> minCharToRight(n);

    minCharToRight[n-1] = n-1;
    for(int i = n-2; i >= 0; i--) {
        if(s[i] < s[minCharToRight[i+1]]){ 
            minCharToRight[i] = i;
        }
        else {
            minCharToRight[i] = minCharToRight[i+1];
        }    
    }

    string t = "";
    string paper = "";
    for(int i=0; i<n; i++) {
        t.push_back(s[i]);
        while(!t.empty() && (i == n-1 || t.back() <= s[minCharToRight[i+1]])) {
            paper += t.back();
            t.pop_back();
        }   
    }
    return paper;
}
int main() {

    string s = "bac";

    string result = robotWithString(s);
    cout << "Lexicographically smallest string: " << result << endl;

    return 0;
}
*/

//                     Lexicographically Minimum String After Removing Stars
/*
typedef pair<char, int> P;
struct comp {

    bool operator()(P& p1, P& p2) {

        if(p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    }
};
string clearStars(string s) {

    int n = s.length();

    priority_queue <P, vector<P>, comp> pq;
    for(int i=0; i<n; i++) {
        if(s[i] != '*') {
            pq.push({s[i], i});
        } 
        else {
            int idx = pq.top().second;
            pq.pop();
            s[idx] = '*';
        }
    }

    string result = "";
    for(int i=0; i<n; i++) {
        if(s[i] != '*') {
            result.push_back(s[i]);
        }
    }
    return result;
}
int main() {

    string test = "aaba*";
    cout << "Final string: " << clearStars(test) << endl;

    return 0;
}
*/

//                                         Maximum Subarray
//                                       (Kadane's Algorithm)

//                                            Approach 1
/*
int maxSubArray(vector<int>& nums) {

    int sum = 0;
    int maxi = INT_MIN;
    for(int i=0; i < nums.size(); i++) {
        sum = sum + nums[i];
        maxi = max(maxi, sum);
            
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}
int main() {

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum is: " << result << endl;

    return 0;
}
*/
//                                            Approach 2
/*
int maxSubArray(vector<int>& nums) {

    int currSubSum = 0;
    int maxSubSum = INT_MIN;
    for(int i=0; i < nums.size(); i++) {
        currSubSum = max(currSubSum + nums[i], nums[i]);
        maxSubSum = max(maxSubSum, currSubSum);
    }
    return maxSubSum;
}
int main() {

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);
    cout << "Maximum Subarray Sum is: " << result << endl;

    return 0;
}
*/

//                               Maximum Absolute Sum of Any Subarray

//                                             Approach 1 
/*
int maxAbsoluteSum(vector<int>& nums) {

    int sum = 0;
    int maxi = INT_MIN;
    for(int i=0; i < nums.size(); i++) {
        sum = sum + nums[i];
        maxi = max(maxi, sum);
                
        if(sum < 0) {
            sum = 0;
        }
    }
        
    sum = 0;
    int mini = INT_MAX;
    for(int i=0; i < nums.size(); i++) {
        sum = sum + nums[i];
        mini = min(mini, sum);
                
        if(sum > 0) {
            sum = 0;
        }
    }
    return max(abs(maxi), abs(mini));
}
int main() {
    
    vector<int> nums = {1, -3, 2, 3, -4};

    int result = maxAbsoluteSum(nums);
    cout << "Maximum Absolute Subarray Sum is: " << result << endl;

    return 0;
}
*/
//                                             Approach 2 
/*
int maxAbsoluteSum(vector<int>& nums) {

    int currSubSum = 0;
    int maxSubSum = INT_MIN;
    for(int i=0; i < nums.size(); i++) {
        currSubSum = max(currSubSum + nums[i], nums[i]);
        maxSubSum = max(maxSubSum, currSubSum);
    }
        
    currSubSum = 0;
    int minSubSum = INT_MAX;
    for(int i=0; i < nums.size(); i++) {
        currSubSum = min(currSubSum + nums[i], nums[i]);
        minSubSum = min(minSubSum, currSubSum);
    }
    return max(abs(maxSubSum), abs(minSubSum));
}
int main() {
    
    vector<int> nums = {1, -3, 2, 3, -4};

    int result = maxAbsoluteSum(nums);
    cout << "Maximum Absolute Subarray Sum is: " << result << endl;

    return 0;
}
*/

//                     Floyd’s Tortoise and Hare (Cycle Detection) Algorithm
//                                  Find the Duplicate Number
/*
int findDuplicate(vector<int>& nums) {

    int slow = nums[0];
    int fast = nums[0];
        
    slow = nums[slow];
    fast = nums[nums[fast]]; 
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
        
    slow = nums[0];
    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }    
    return slow;
}
int main() {
    
    vector<int> nums = {1, 3, 4, 2, 2};

    int duplicate = findDuplicate(nums);
    cout << "Duplicate number is: " << duplicate << endl;

    return 0;
}
*/

//                                            Pow(x, n)
/*
double solve(double x, long n) {
        
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return solve(1/x, -n);
    }
        
    if(n%2 == 0) {
        return solve(x*x, n/2);
    } 
    return x * solve(x*x, (n-1)/2);
}
double myPow(double x, int n) {

    return solve(x, (long)n);
}
int main() {

    cout << "2^10 = " << myPow(2, 10) << endl;
    cout << "2.10000^3 = " << myPow(2.10000, 3) << endl;
    cout << "2.00000^-2 = " << myPow(2.00000, -2) << endl;

    return 0;
}
*/

//                                           Unique Paths

//                                            Recursive
/*
int solve(int i, int j, int m, int n) {

    if(i == m-1 && j == n-1) {
        return 1;
    }

    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }

    int right = solve(i, j+1, m, n);
    int down  = solve(i+1, j, m, n);
    return right + down;
}
int uniquePaths(int m, int n) {

    return solve(0, 0, m, n);
}
int main() {

    int m = 3, n = 7;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << result << endl;

    return 0;
}
*/
//                                            Top-Down
/*
int solve(int i, int j, int m, int n, vector<vector<int>>& t) {

    if(i == m-1 && j == n-1) {
        return 1; 
    }

    if(i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }

    if(t[i][j] != -1) {
        return t[i][j];
    }

    int right = solve(i, j+1, m, n, t);
    int down  = solve(i+1, j, m, n, t);
    return t[i][j] = right + down;
}

int uniquePaths(int m, int n) {

    vector<vector<int>> t(m+1, vector<int>(n+1, -1));
    return solve(0, 0, m, n, t);
}
int main() {

    int m = 3, n = 7;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << result << endl;

    return 0;
}
*/

//                                 Longest Consecutive Sequence

//                                          Approach 1
/*
int longestConsecutive(vector<int>& nums) {

    if(nums.size() == 0) {
        return 0;
    }
        
    sort(nums.begin(), nums.end());

    int count = 1;
    int ans = 1;
    for(int i=1; i < nums.size(); i++) {
        // Skip duplicates
        if(nums[i] == nums[i-1]) {
            continue; 
        } 
        else if(nums[i] - nums[i-1] == 1) {
            count++;
        }
        else {
            count = 1;
        }
        ans = max(ans, count);
    }
    return ans;
}
int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int longestConsecutive(vector<int>& nums) {

    unordered_set<int> numSet(nums.begin(), nums.end());

    int longest = 0;
    for(int num : numSet) {
        if(numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int streak = 1;
            while(numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}
int main() {

    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
*/

//                                         Relative Sort Array
/*
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

    map <int, int> mp;
    for(int& num : arr1) {
        mp[num]++;
    }

    int i = 0;
    for(int& num : arr2) {
        while(mp[num] != 0){
            arr1[i++] = num;
            mp[num]--;
        }
    }
        
    for(auto& it : mp){
        while(it.second != 0){
            arr1[i++] = it.first;
            mp[it.first]--;
        }
    }
    return arr1;
}
int main() {

    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> result = relativeSortArray(arr1, arr2);
    cout << "Sorted array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                   Lexicographical Numbers
/*
void solve(int curr, int n, vector<int>& result) {

    if(curr > n) {
        return;
    }
        
    result.push_back(curr);
    for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
        int newNum = curr * 10 + nextDigit;
        if(newNum > n) {
            return;
        }
        solve(newNum, n, result);
    }
}
vector<int> lexicalOrder(int n) {

    vector<int> result;    
    for(int num=1; num <= 9; num++) {
        solve(num, n, result);
    }
    return result;
}
int main() {
    
    int n = 13;  

    vector<int> result = lexicalOrder(n);
    cout << "Lexicographical order from 1 to " << n << ":\n";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
*/

//                          Longest Substring Without Repeating Characters

//                                             Approach 1
/*
int lengthOfLongestSubstring(string s) {

    if(s.length() == 0) {
        return 0;
    }

    int ans = 0;
    for(int i=0; i < s.length(); i++) {
        unordered_map <char, int> mp;
        int count = 0;
        for(int j=i; j < s.length(); j++) {
            if(mp.find(s[j]) != mp.end()) {
                break;
            }
            mp[s[j]] = 1;
            count++;
        }
        ans = max(ans, count);
    }
    return ans;
}
int main() {

    string s = "abcabcbb";

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
*/
//                                             Approach 2
/*
int lengthOfLongestSubstring(string s) {

    unordered_map <char, int> mp;
    
    int left = 0;
    int right = 0;
        
    int maxLen = 0;
    while(right < s.length()){
        if(mp.find(s[right]) != mp.end()) {
            left = max(mp[s[right]] + 1, left);
        }
        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}
int main() {

    string s = "abcabcbb";

    int result = lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
*/

//                                  Remove Nth Node From End of List

//                                              Approach 1
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
int lengthLinkedList(ListNode* head) {

    int l = 0;    
    while(head) {
        l++;
        head = head->next;
    }
    return l;
}    
ListNode* removeNthFromEnd(ListNode* head, int n) {

    int length = lengthLinkedList(head);
        
    if(length == n) { 
        ListNode* temp = head->next;
        delete(head);
        return temp;
    }

    ListNode* temp = head;
    ListNode* prev = NULL;

    int travel = length-n;    
    while(travel--) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;    
    delete(temp);   
    return head;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    int n = 2;
    head = removeNthFromEnd(head, n);

    // Printing list after deletion
    cout << "List after deleting " << n << "th node from end: ";
    for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    // Deleting all remaining nodes
    while(head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
*/
//                                              Approach 2
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;
    ListNode* slow = head;
        
    for(int i=1; i <= n; i++) {
        fast = fast->next;
    }
        
    if(fast == NULL) {
        return head->next;
    }
        
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
        
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete(temp);

    return head;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    int n = 2;
    head = removeNthFromEnd(head, n);

    // Printing list after deletion
    cout << "List after deleting " << n << "th node from end: ";
    for(ListNode* temp = head; temp != nullptr; temp = temp->next) {
        cout << temp->val << " ";
    }
    cout << endl;

    // Deleting all remaining nodes
    while(head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
*/

//                                  Intersection of Two Linked Lists

//                                             Approach 1
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    while(headB != NULL) {
        ListNode* temp = headA;
        while(temp != NULL) {
            // If both nodes are same
            if(temp == headB) {
                return headB;
            }
            temp = temp->next;
        }
        headB = headB->next;
    }
    // Intersection is not present between the lists return null
    return NULL;
}
int main() {

    // Common part: 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    // Find intersection
    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    // Display result
    if(intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (for good practice)
    // Delete unique parts first
    delete headA->next;          // node 1 in List A
    delete headA;                // node 4 in List A
    delete headB->next->next;    // node 1 in List B
    delete headB->next;          // node 6 in List B
    delete headB;                // node 5 in List B

    // Delete common part
    delete intersect->next->next; // node 5
    delete intersect->next;       // node 4
    delete intersect;             // node 8

    return 0;
}
*/
//                                             Approach 2
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

    unordered_set <ListNode*> st;
    while(headA != NULL) {
       st.insert(headA);
       headA = headA->next;
    }
    while(headB != NULL) {
        if(st.find(headB) != st.end()) {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}
int main() {

    // Common part: 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    // Find intersection
    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    // Display result
    if(intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (for good practice)
    // Delete unique parts first
    delete headA->next;          // node 1 in List A
    delete headA;                // node 4 in List A
    delete headB->next->next;    // node 1 in List B
    delete headB->next;          // node 6 in List B
    delete headB;                // node 5 in List B

    // Delete common part
    delete intersect->next->next; // node 5
    delete intersect->next;       // node 4
    delete intersect;             // node 8

    return 0;
}
*/
//                                             Approach 3
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
int getDifference(ListNode* headA, ListNode* headB) {

    int len1 = 0;
    int len2 = 0;
    while(headA != NULL || headB != NULL) {
        if(headA != NULL) {
            len1++; 
            headA = headA->next;
        }
        if(headB != NULL) {
            len2++;
            headB = headB->next;
        }        
    }
    return len1-len2;
}
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB) {

    int diff = getDifference(headA, headB);
    if(diff < 0) {
        while(diff++) {
            headB = headB->next;
        } 
    }
    else {
        while(diff--) {
            headA = headA->next;
        }
    }
    while(headA != NULL) {
        if(headA == headB) {
            return headA;
        }
        headB = headB->next;
        headA = headA->next;
    }
    return headA;
}
int main() {

    // Common part: 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    // Find intersection
    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    // Display result
    if(intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (for good practice)
    // Delete unique parts first
    delete headA->next;          // node 1 in List A
    delete headA;                // node 4 in List A
    delete headB->next->next;    // node 1 in List B
    delete headB->next;          // node 6 in List B
    delete headB;                // node 5 in List B

    // Delete common part
    delete intersect->next->next; // node 5
    delete intersect->next;       // node 4
    delete intersect;             // node 8

    return 0;
}
*/
//                                             Approach 4
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int value) {
            val = value;
            next = nullptr;
        }
};
ListNode* getIntersectionNode(ListNode* headA,ListNode* headB) {

    ListNode* d1 = headA;
    ListNode* d2 = headB;
    
    while(d1 != d2) {
        d1 = d1 == NULL? headB:d1->next;
        d2 = d2 == NULL? headA:d2->next;
    }
    return d1;
}
int main() {

    // Common part: 8 -> 4 -> 5
    ListNode* intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    // List A: 4 -> 1 -> 8 -> 4 -> 5
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    // List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    // Find intersection
    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    // Display result
    if(intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    }
    else {
        cout << "No intersection found." << endl;
    }

    // Clean up memory (for good practice)
    // Delete unique parts first
    delete headA->next;          // node 1 in List A
    delete headA;                // node 4 in List A
    delete headB->next->next;    // node 1 in List B
    delete headB->next;          // node 6 in List B
    delete headB;                // node 5 in List B

    // Delete common part
    delete intersect->next->next; // node 5
    delete intersect->next;       // node 4
    delete intersect;             // node 8

    return 0;
}
*/

//                                   K-th Smallest in Lexicographical Order
/*
int Count(long curr, long next, int n) {

    int countNum = 0;
    while(curr <= n) {
        countNum += (next - curr);
        curr *= 10;
        next *= 10;
        next = min(next, long(n+1));
    }
    return countNum;
}

int findKthNumber(int n, int k) {

    int curr = 1;
    k -= 1;
    while(k > 0) {
        int count = Count(curr, curr+1, n);
        if(count <= k) {
            curr++;
            k -= count;
        } 
        else {
            curr *= 10;
            k -= 1;
        }
    }
    return curr;
}
int main() {

    int n = 13;
    int k = 2;

    int result = findKthNumber(n, k);
    cout << "The " << k << "-th smallest number in lexicographical order is: " << result << endl;

    return 0;
}
*/

//                         Maximum Difference Between Even and Odd Frequency I
/*
int maxDifference(string s) {

    int n = s.length();

    vector<int> vec(26, 0);
    for(char& ch : s) {
        vec[ch - 'a']++;
    }

    int maxOdd = 0;
    int minEven = n+1;
    for(int i=0; i<26; i++) {
        if(vec[i] == 0) {
            continue;
        }

        if(vec[i] % 2 == 0) {
            minEven = min(minEven, vec[i]);
        } 
        else {
            maxOdd = max(maxOdd, vec[i]);
        }
    }
    return maxOdd - minEven;
}
int main() {

    string s = "aaaaabbc";
    cout << "maxDifference = " << maxDifference(s) << endl;

    return 0;
}
*/

//                     Pow(x, n) without using pow() & * operator
/*
int solve(int n, int m) {

    int result = 1;
    for(int i=0; i<m; i++) {
        int value = 0;
        for(int j=0; j<n; j++) {
            value += result;
        }
        result = value;
    }
    return result;
}
int main() {

    int n = 5;
    int m = 4;

    cout << solve(n, m) << endl;

    return 0;
}
*/

//                 Maximum Difference Between Adjacent Elements in a Circular Array
/*
int maxAdjacentDistance(vector<int>& nums) {

    int n = nums.size();

    int maxi = 0;
    for(int i=0; i<n; i++) {
        int diff = abs(nums[i] - nums[(i+1) % n]);
        maxi = max(maxi, diff);
    }
    return maxi;
}
int main() {

    vector<int> nums = {1, 2, 4};

    int result = maxAdjacentDistance(nums);
    cout << "Maximum adjacent distance: " << result << endl;

    return 0;
}
*/

//                                  Maximum Difference by Remapping a Digit
/*
int minMaxDifference(int num) {

    char ch;
    string s = to_string(num);
    for(int i=0; i < s.length(); i++) {
        if(s[i] != '9') {
            ch = s[i];
            break;
        }
    }
    for(int i=0; i < s.length(); i++) {
        if(s[i] == ch) {
            s[i] = '9';
        }
    }
    int maxi = stoi(s);

    string t = to_string(num);
    ch = t[0];
    for(int i=0; i < t.length(); i++){
        if(t[i] == ch) {
            t[i] = '0';
        }
    } 
    int mini = stoi(t);
        
    return maxi - mini;
}
int main() {

    int num = 11891; 
    int result = minMaxDifference(num);
    
    cout << "For number " << num << ", the difference is: " << result << endl;

    return 0;
}
*/

//                          Divide Array Into Arrays With Max Difference
/*
vector<vector<int>> divideArray(vector<int>& nums, int k) {

    int n = nums.size();    
        
    sort(begin(nums), end(nums));
    
    vector<vector<int>> result;
    for(int i=0; i <= n-3; i += 3) {
        if(nums[i+2] - nums[i] > k) {
            return {};
        }    
        result.push_back({nums[i], nums[i+1], nums[i+2]});
    }    
    return result;
}
int main() {

    vector<int> nums = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 3;

    vector<vector<int>> groups = divideArray(nums, k);
    if(groups.empty()) {
        cout << "Cannot divide array into groups satisfying the condition." << endl;
    } 
    else {
        cout << "Divided groups:" << endl;
        for(const auto& group : groups) {
            for(int num : group) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
*/

//                          Partition Array Such That Maximum Difference Is K
/*
int partitionArray(vector<int>& nums, int k) {

    int n = nums.size();
    sort(begin(nums), end(nums));

    int minVal = nums[0];
    int count = 1;
    for(int i=0; i<n; i++) {
        if(nums[i] - minVal > k) {
            count++;
            minVal = nums[i];
        }
    }
    return count;
}
int main() {

    vector<int> nums = {3, 6, 1, 2, 5};
    int k = 2;

    int result = partitionArray(nums, k);
    cout << "Minimum number of groups: " << result << endl;

    return 0;
}
*/

//                              Maximum Matching of Players With Trainers
/*
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

    int m = players.size();
    int n = trainers.size();
    sort(begin(players), end(players));
    sort(begin(trainers), end(trainers));

    int count = 0;
    int i = 0;
    int j = 0;
    while(i < m && j < n) {
        if(players[i] <= trainers[j]) {
            count++;
            i++;
        }
        j++;
    }
    return count;
}
int main() {
    
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};

    int matchedCount = matchPlayersAndTrainers(players, trainers);
    cout << "Number of matched players and trainers: " << matchedCount << endl;

    return 0;
}
*/

//                      Convert Binary Number in a Linked List to Integer
/*
class ListNode {

    public:
        int val;
        ListNode* next;

        ListNode(int x) : val(x), next(nullptr) {

        }
};
int getDecimalValue(ListNode* head) {

    string binaryStr = "";
    while(head) {
        binaryStr += head->val + '0';
        head = head->next;
    }
        
    int result = 0;
    int power = 0;
    for(int i = binaryStr.length() - 1; i >= 0; i--) {
        if(binaryStr[i] == '1') {
            result += pow(2, power);
        }
        power++;
    }
    return result;
}
int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    cout << getDecimalValue(head) << endl; 

    return 0;
}
*/

//                                            Valid Word
/*
bool isValid(string word) {

    if(word.length() < 3) {
        return false;
    }

    bool hasVowel = false;
    bool hasConsonant = false;
    for(char ch : word) {
        if(isalpha(ch)) {
            ch = tolower(ch);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                hasVowel = true;
            } 
            else {
                hasConsonant = true;
            }
        } 
        else if(!isdigit(ch)) {
            return false;
        }
    }
    return hasVowel && hasConsonant;
}
int main() {
    
    cout << isValid("234Adas") << endl;

    return 0;
}
*/

//                                           24 Game
/*
bool solve(vector<double>& cards) {

    // Tolerance for floating-point comparison. To avoid floating point precission errors
    // 0.01, 0.001 etc will work too.
    double epsilon = 0.1; 

    if(cards.size() == 1) {
        return abs(cards[0] - 24) <= epsilon;
    }

    // Pick two possible numbers
    for(int i=0; i < cards.size(); i++) {
        for(int j=0; j < cards.size(); j++) {
            if(i == j) {
                continue;
            }
                
            vector<double> temp;
            for(int k=0; k < cards.size(); k++) {
                if(k != i && k != j) {
                    temp.push_back(cards[k]);
                }
            }

            double a = cards[i];
            double b = cards[j];

            vector<double> possibleVal = {a+b, a-b, b-a, a*b}; 
            if(abs(b) > 0.0) {
                possibleVal.push_back(a/b);
            }

            if(abs(a) > 0.0) {
                possibleVal.push_back(b/a);
            }

            for(double val : possibleVal) {
                // Do
                temp.push_back(val); 
                // Explore
                if(solve(temp) == true) { 
                    return true;
                }
                // Undo
                temp.pop_back(); 
            }
        }
    }
    return false;
}
bool judgePoint24(vector<int>& cards) {

    vector<double> nums;
    for(int i=0; i < cards.size(); i++) {
        nums.push_back(1.0 * cards[i]);
    }
    return solve(nums);
}
int main() {

    vector<int> test1 = {4, 1, 8, 7}; // true: (8 - 4) * (7 - 1) = 24
    vector<int> test2 = {1, 2, 1, 2}; // false
    vector<int> test3 = {3, 3, 8, 8}; // true: (8 / (3 - 8/3)) = 24

    cout << boolalpha; // print "true" or "false" instead of 1/0
    cout << "Test 1: " << judgePoint24(test1) << endl;
    cout << "Test 2: " << judgePoint24(test2) << endl;
    cout << "Test 3: " << judgePoint24(test3) << endl;

    return 0;
}
*/

//                               Number of Zero-Filled Subarrays

//                                          Approach 1
/*
long long zeroFilledSubarray(vector<int>& nums) {

    int n = nums.size();

    long long result = 0;
        
    int i=0;
    while(i < n) {        
        long long zeros = 0;    
        if(nums[i] == 0) {        
            while(i < n && nums[i] == 0) {
                i++;
                zeros++;
            }
        } 
        else {
            i++;
        }
        result += (zeros)*(zeros+1)/2;
    }    
    return result;        
}
int main() {

    vector<int> test1 = {0, 0, 0, 2, 0, 0}; 
    vector<int> test2 = {1, 3, 0, 0, 2, 0, 0, 4};
    vector<int> test3 = {2, 10, 2019};   

    cout << "Test 1: " << zeroFilledSubarray(test1) << endl;
    cout << "Test 2: " << zeroFilledSubarray(test2) << endl;
    cout << "Test 3: " << zeroFilledSubarray(test3) << endl;

    return 0;
}
*/
//                                          Approach 2
/*
long long zeroFilledSubarray(vector<int>& nums) {

    int n = nums.size();

    long long result = 0;
        
    int countSubArray = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == 0) {
            countSubArray += 1;
        }
        else {
            countSubArray = 0;
        }    
        result += countSubArray;        
    }    
    return result;    
}
int main() {

    vector<int> test1 = {0, 0, 0, 2, 0, 0}; 
    vector<int> test2 = {1, 3, 0, 0, 2, 0, 0, 4};
    vector<int> test3 = {2, 10, 2019};   

    cout << "Test 1: " << zeroFilledSubarray(test1) << endl;
    cout << "Test 2: " << zeroFilledSubarray(test2) << endl;
    cout << "Test 3: " << zeroFilledSubarray(test3) << endl;

    return 0;
}
*/

//                            Find the Minimum Area to Cover All Ones I
/*
int minimumArea(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();

    int minRow = m;
    int maxRow = -1;
    int minCol = n;
    int maxCol = -1;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1) {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }       
        }
    }
    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
}
int main() {

    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 1}
    }; 

    cout << "Test: " << minimumArea(grid) << endl;

    return 0;
}
*/

//                                 Alice and Bob Playing Flower Game
/*
long long flowerGame(int n, int m) {

    return 1LL * ((n+1) / 2) * (m/2) + 1LL * (n/2) * ((m+1) / 2);
}
int main() {

    cout << flowerGame(3, 2) << endl;

    return 0;
}
*/

//                           Find the Number of Ways to Place People I

//                                          Approach 1
/*
int numberOfPairs(vector<vector<int>>& points) {

    int n = points.size();
    int result = 0;

    for(int i=0; i<n; i++) {
        // Candidate for upper-left
        int x1 = points[i][0];
        int y1 = points[i][1];   

        for(int j=0; j<n; j++) {
            if(i == j) {
                continue;
            }
            // Candidate for lower-right
            int x2 = points[j][0];
            int y2 = points[j][1];   

            // Condition: (x1, y1) must be upper-left of (x2, y2)
            if(x1 <= x2 && y1 >= y2) {
                bool hasPointInside = false;
                // Check if some point lies inside or on the rectangle
                for(int k=0; k<n; k++) {
                    if(k == i || k == j) {
                        continue;
                    }
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    if(x3 >= x1 && x3 <= x2 && y3 <= y1 && y3 >= y2) {
                        hasPointInside = true;
                        break;
                    }
                }
                if(!hasPointInside) {
                    result++;
                }
            }
        }
    }
    return result;
}
int main() {

    vector<vector<int>> test = {{6, 2}, {4, 4}, {2, 6}}; 
    cout << "Test: " << numberOfPairs(test) << endl;

    return 0;
}
*/
//                                          Approach 2
/*
int numberOfPairs(vector<vector<int>>& points) {

    int n = points.size();

    // Sort: x ascending, if x same then sort as y descending
    auto lambda = [](vector<int>& point1, vector<int>& point2) {
        if(point1[0] == point2[0]) {
            return point1[1] > point2[1];
        }
        return point1[0] < point2[0];
    };

    sort(points.begin(), points.end(), lambda);

    int result = 0;
    for(int i=0; i<n; i++) {
        // Upper left
        int x1 = points[i][0];
        int y1 = points[i][1];   

        int bestY = INT_MIN;
        for(int j = i+1; j<n; j++) {
            // Lower right
            int x2 = points[j][0];
            int y2 = points[j][1];   
            // Condition: (x2, y2) must be above (x1, y1)
            // Not lower right
            if(y2 > y1) { 
                continue;
            }
            if(y2 > bestY) {
                result++;
                bestY = y2;
            }
        }
    }
    return result;
}
int main() {

    vector<vector<int>> test = {{6, 2}, {4, 4}, {2, 6}}; 
    cout << "Test: " << numberOfPairs(test) << endl;

    return 0;
}
*/

//                           Find the Number of Ways to Place People II
/*
int numberOfPairs(vector<vector<int>>& points) {

    int n = points.size();

    // Sort: x ascending, if x same then sort as y descending
    auto lambda = [](vector<int>& point1, vector<int>& point2) {
        if(point1[0] == point2[0]) {
            return point1[1] > point2[1];
        }
        return point1[0] < point2[0];
    };

    sort(points.begin(), points.end(), lambda);

    int result = 0;
    for(int i=0; i<n; i++) {
        // Upper left
        int x1 = points[i][0];
        int y1 = points[i][1];   

        int bestY = INT_MIN;
        for(int j = i+1; j<n; j++) {
            // Lower right
            int x2 = points[j][0];
            int y2 = points[j][1];   
            // Condition: (x2, y2) must be above (x1, y1)
            // Not lower right
            if(y2 > y1) { 
                continue;
            }
            if(y2 > bestY) {
                result++;
                bestY = y2;
            }
        }
    }
    return result;
}
int main() {

    vector<vector<int>> test = {{6, 2}, {4, 4}, {2, 6}}; 
    cout << "Test: " << numberOfPairs(test) << endl;

    return 0;
}
*/

//                              Number of People Aware of a Secret

//                                           Recursive
/*
int MOD = 1e9 + 7;
int solve(int day, int delay, int forget) {

    if(day == 1) {
        return 1;
    }

    int result = 0;
    for(int prev = day-forget+1; prev <= day-delay; prev++) {
        if(prev > 0) {
            result = (result + solve(prev, delay, forget)) % MOD;
        }
    }
    return result;
}
int peopleAwareOfSecret(int n, int delay, int forget) {
        
    int result = 0;
    for(int day = n-forget+1; day <= n; day++) {
        if(day > 0) {
            result = (result + solve(day, delay, forget)) % MOD;
        }
    }
    return result;
}
int main() {

    cout << "Test: " << peopleAwareOfSecret(4, 1, 3) << endl;   

    return 0;
}
*/
//                                           Top-Down
/*
int MOD = 1e9 + 7;
int solve(int day, int delay, int forget, vector<int>& dp) {

    if(day == 1) {
        return 1;
    }

    if(dp[day] != -1) {
        return dp[day];
    }

    int result = 0;
    for(int prev = day-forget+1; prev <= day-delay; prev++) {
        if(prev > 0) {
            result = (result + solve(prev, delay, forget, dp)) % MOD;
        }
    }
    return dp[day] = result;
}
int peopleAwareOfSecret(int n, int delay, int forget) {

    vector<int> dp(n+1, -1);

    int result = 0;
    for(int day = n-forget+1; day <= n; day++) {
        if(day > 0) {
            result = (result + solve(day, delay, forget, dp)) % MOD;
        }
    }
    return result;
}
int main() {

    cout << "Test: " << peopleAwareOfSecret(4, 1, 3) << endl;   

    return 0;
}
*/
//                                       Bottom-Up
/*
int MOD = 1e9 + 7;
vector<int> dp;
void solve(int n, int delay, int forget) {

    dp[1] = 1;

    for(int day = 2; day <= n; day++) {
        int result = 0;
        for(int prev = day-forget+1; prev <= day-delay; prev++) {
            if(prev > 0) {
                result = (result + dp[prev]) % MOD;
            }
        }
        dp[day] = result;
    }
}
int peopleAwareOfSecret(int n, int delay, int forget) {

    dp.assign(n + 1, 0);
    solve(n, delay, forget);

    int result = 0;
    for(int day = n-forget+1; day <= n; day++) {
        if(day > 0) {
            result = (result + dp[day]) % MOD;
        }
    }
    return result;
}
int main() {

    cout << "Test: " << peopleAwareOfSecret(4, 1, 3) << endl;   

    return 0;
}
*/

//                               Minimum Number of People to Teach
/*
int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {

    unordered_set<int> sadUsers;

    for(auto &friends : friendships) {
        int u = friends[0] - 1;
        int v = friends[1] - 1;

        unordered_set<int> langSet(begin(languages[u]), end(languages[u]));
        bool canTalk = false;
        for(int lang : languages[v]) {
            if(langSet.count(lang)) {
                canTalk = true;
                break;
            }
        }

        if(!canTalk) {
            sadUsers.insert(u);
            sadUsers.insert(v);
        }
    }

    // Find max known language among sad users
    vector<int> language(n+1, 0);
    int mostKnownLang = 0;

    for(int user : sadUsers) {
        for(int lang : languages[user]) {
            language[lang]++;
            mostKnownLang = max(mostKnownLang, language[lang]);
        }
    }
    return sadUsers.size() - mostKnownLang;    
}
int main() {

    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}, {3}};

    vector<vector<int>> friendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};

    int result = minimumTeachings(n, languages, friendships);
    cout << "Minimum teachings needed = " << result << endl;

    return 0;
}
*/

//                                     Vowels Game in a String
/*
bool doesAliceWin(string s) {

    for(char ch : s) {
        if(ch == 'a' || ch == 'e' || ch == 'i'|| ch == 'o' || ch == 'u') {
            return true;
        }
    }
    return false;
}
int main() {

    string s = "leetcoder";

    bool result = doesAliceWin(s);
    if(result) {
        cout << "Alice wins";
    }
    else {
        cout << "Alice loses";
    }
    return 0;
}
*/

//                                      Vowel Spellchecker
/*
// Stores original words
unordered_set<string> exactWords;   

// Lowercase : original word       
unordered_map<string, string> caseMap;     

// Masked vowels : original word
unordered_map<string, string> vowelMap;    
    
string toLower(string& s) {

    string res = s;
    for(char& c : res) {
        c = tolower(c);
    }
    return res;
}
string maskVowels(string& s) {
    
    string res = s;
    for(char& c : res) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = '*';
        }
    }
    return res;
}
string checkForMatch(string& query) {

    // Exact match
    if(exactWords.count(query)) {
        return query;
    }

    // Case error match
    string lowerQuery = toLower(query);
    if(caseMap.count(lowerQuery)) {
        return caseMap[lowerQuery];
    }

    // Vowel error match
    string maskedQuery = maskVowels(lowerQuery);
    if(vowelMap.count(maskedQuery)) {
        return vowelMap[maskedQuery];
    }

    // No match
    return "";
}
vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
    exactWords.clear();
    caseMap.clear();
    vowelMap.clear();

    for(string word : wordlist) {
        exactWords.insert(word);

        string lowerWord = toLower(word);
        // Add only 1st occurrence
        if(caseMap.find(lowerWord) == caseMap.end()) { 
            caseMap[lowerWord] = word;
        }

        string maskedWord = maskVowels(lowerWord);
        // Add only 1st occurrence
        if(vowelMap.find(maskedWord) == vowelMap.end()) { 
            vowelMap[maskedWord] = word;
        }
    }

    vector<string> result;
    for(string query : queries) {
        result.push_back(checkForMatch(query));
    }
    return result;
}
int main() {

    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries  = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet"};

    vector<string> result = spellchecker(wordlist, queries);

    cout << "Output:" << endl;
    for(string s : result) {
        cout << s << endl;
    }

    return 0;
}
*/

//                                 Maximum Number of Words You Can Type
/*
int canBeTypedWords(string text, string brokenLetters) {

    bool mp[26] = {false};
    for(char& ch : brokenLetters) {
        mp[ch - 'a'] = true;
    }

    int result = 0;
    bool foundBroken = false;
    for(char& ch : text) {
        if(ch == ' ') {
            if(!foundBroken) {
                result++;
            }
            foundBroken = false;
        } 
        else if(mp[ch - 'a']) {
            foundBroken = true; 
        }
    }
    if(!foundBroken) {
        result++;
    }
    return result;
}
int main() {

    string text = "hello world"; 
    string brokenLetters = "ad"; 

    int ans = canBeTypedWords(text, brokenLetters);
    cout << "Words that can be typed: " << ans << endl;

    return 0;
}
*/

//                                     Design Task Manager
/*
class TaskManager {

    // Tasks sorted by priority, then taskId
    priority_queue<pair<int, int>> maxHeap;         
    
    // TaskId -> current priority
    unordered_map<int, int> taskPriorityMap; 
    
    // TaskId -> userId
    unordered_map<int, int> taskOwnerMap;          

    public:
        // Initialize with a list of [userId, taskId, priority]
        TaskManager(vector<vector<int>>& initialTasks) {

            for(auto& task : initialTasks) {
                add(task[0], task[1], task[2]);
            }
        }

        // Add new task
        void add(int userId, int taskId, int priority) {

            maxHeap.push({priority, taskId});
            taskPriorityMap[taskId] = priority;
            taskOwnerMap[taskId] = userId;
        }

        // Edit existing task priority
        void edit(int taskId, int newPriority) {

            maxHeap.push({newPriority, taskId});
            taskPriorityMap[taskId] = newPriority;
        }

        // Remove a task from the system
        void rmv(int taskId) {

            // Mark as invalid
            taskPriorityMap[taskId] = -1; 
        }

        // Execute the top task and return its userId
        int execTop() {
            
            while(!maxHeap.empty()) {
                auto topPair = maxHeap.top();
                int priority = topPair.first;
                int taskId   = topPair.second;
                maxHeap.pop();
                if(priority == taskPriorityMap[taskId]) {
                    // Mark as executed
                    taskPriorityMap[taskId] = -1; 
                    return taskOwnerMap[taskId];
                }
            }
            // No tasks available
            return -1; 
        }
};
int main() {

    // Initial tasks: {userId, taskId, priority}
    vector<vector<int>> initialTasks = {
        {1, 101, 10},
        {2, 102, 20},
        {3, 103, 15}
    };

    TaskManager tm(initialTasks);

    // Testing methods
    tm.add(4, 104, 5);      // Add a new task
    tm.edit(102, 8);       // Decrease priority of task 102
    cout << "Exec 1 -> User: " << tm.execTop() << endl;
    tm.rmv(101);            // Remove task 101
    tm.add(5, 105, 15);      // Add a new task
    cout << "Exec 2 -> User: " << tm.execTop() << endl;   

    return 0;
}
*/

//                                      Design Spreadsheet
/*
class Spreadsheet {

    public:
        vector<vector<int>> sheet;

        Spreadsheet(int rows) {
            sheet.assign(rows, vector<int>(26, 0));    
        }
        
        void setCell(string cell, int value) {

            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            sheet[row][col] = value;
        }
        
        void resetCell(string cell) {

            int col = cell[0] - 'A';
            int row = stoi(cell.substr(1)) - 1;
            sheet[row][col] = 0;
        }
        
        int solve(string& s) {

            if(isdigit(s[0])) {
                return stoi(s);
            }

            int col = s[0] - 'A';
            int row = stoi(s.substr(1)) - 1;
            return sheet[row][col];
        }

        int getValue(string formula) {
    
            // Remove =
            string s = formula.substr(1);
            int plusIdx = s.find('+');

            string left = s.substr(0, plusIdx);
            string right = s.substr(plusIdx+1);
            return solve(left) + solve(right);
        }
};
int main() {

    Spreadsheet sp(3);

    cout << "Value of formula =5+7: " << sp.getValue("=5+7") << endl;
    sp.setCell("A1", 10);
    cout << "Value of formula =A1+6: " << sp.getValue("=A1+6") << endl;
    sp.setCell("B2", 15);
    cout << "Value of formula =A1+B2: " << sp.getValue("=A1+B2") << endl;
    sp.resetCell("A1");
    cout << "Value of formula =A1+B2: " << sp.getValue("=A1+B2") << endl;
    
    return 0;
}
*/

//                                      Implement Router
/*
class Router {

    private:
        // Memory limit
        int MAX_SIZE;  

        // Key -> packet [source, dest, timestamp]
        unordered_map<string, vector<int>> packetStore; 
        
        // Destination -> sorted timestamps
        unordered_map<int, vector<int>> destTimestamps;  

        // FIFO order
        queue<string> que;  

        string makeKey(int source, int destination, int timestamp) {

            return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
        }

    public:
        Router(int memoryLimit) {

            MAX_SIZE = memoryLimit;
        }

        bool addPacket(int source, int destination, int timestamp) {

            string key = makeKey(source, destination, timestamp);

            // Duplicate
            if(packetStore.find(key) != packetStore.end()) {
                return false;  
            }

            // Remove the oldest packet
            if((int)packetStore.size() >= MAX_SIZE) { 
                forwardPacket();
            }

            packetStore[key] = {source, destination, timestamp};
            que.push(key);
            destTimestamps[destination].push_back(timestamp);

            return true;
        }

        vector<int> forwardPacket() {

            // If there are no packets to forward, return an empty array.
            if(packetStore.empty()) {
                return {}; 
            }

            string key = que.front(); 
            que.pop();

            vector<int> packet = packetStore[key];
            packetStore.erase(key);

            // Remove earliest timestamp
            int dest = packet[1];
            destTimestamps[dest].erase(destTimestamps[dest].begin()); 

            return packet;
        }

        int getCount(int destination, int startTime, int endTime) {

            auto it = destTimestamps.find(destination);
            if(it == destTimestamps.end() || it->second.empty()) {
                return 0;
            }

            int i = lower_bound(begin(it->second), end(it->second), startTime) - begin(it->second);
            int j = upper_bound(begin(it->second), end(it->second), endTime) - begin(it->second);
            return j-i;
        }
};
int main() {

    Router router(3);
    cout << boolalpha;

    // ["addPacket", [1,4,90]]
    cout << router.addPacket(1, 4, 90) << endl;

    // ["addPacket", [2,5,90]]
    cout << router.addPacket(2, 5, 90) << endl;

    // ["addPacket", [1,4,90]]  (duplicate – should return false)
    cout << router.addPacket(1, 4, 90) << endl;

    // ["addPacket", [3,5,95]]
    cout << router.addPacket(3, 5, 95) << endl;

    // ["addPacket", [4,5,105]]  → capacity full → will forward oldest
    cout << router.addPacket(4, 5, 105) << endl;

    // ["forwardPacket", []]
    vector<int> res = router.forwardPacket();
    cout << "[" << res[0] << "," << res[1] << "," << res[2] << "]" << endl;

    // ["addPacket", [5,2,110]]
    cout << router.addPacket(5, 2, 110) << endl;

    // ["getCount", [5,100,110]]
    cout << router.getCount(5, 100, 110) << endl;

    return 0;
}
*/

//                                      Count Collisions on a Road
/*
int countCollisions(string directions) {

    int n = directions.length();

    // Left boundary
    int i = 0; 
    while(i < n && directions[i] == 'L') {
        i++;
    }

    // Right boundary
    int j = n-1;
    while(j >= 0 && directions[j] == 'R') {
        j--;
    }

    int collisions = 0;
    while(i <= j) {
        if(directions[i] != 'S') {
            collisions++;
        }
        i++;
    }
    return collisions;
}
int main() {

    string directions = "RLRSLL";
    cout << "Total Collisions: " << countCollisions(directions) << endl;

    return 0;
}
*/

//                                Maximum Running Time of N Computers
/*
typedef long long ll;
bool possible(vector<int>& batteries, ll mid_time, int n) {
        
    // Each computer will run mid_time minutes
    ll target = n * mid_time;

    ll sum = 0;    
    for(int i=0; i < batteries.size(); i++) {  
        target -= min((ll)batteries[i], mid_time);    
        if(target <= 0) {
            return true;
        }
    }
    return false;
}
long long maxRunTime(int n, vector<int>& batteries) {
        
    ll l = *min_element(begin(batteries), end(batteries));
    
    long long sum_total_minutes = 0; 
    for(auto& mints : batteries) {
        sum_total_minutes += mints;
    }
        
    ll r = sum_total_minutes / n;
    ll result = 0;    
    while(l <= r) {        
        ll mid_time = l + (r-l)/2;    
        if(possible(batteries, mid_time, n)) {
            result = mid_time;
            l = mid_time + 1;
        } 
        else {
            r = mid_time - 1;
        }
    }    
    return result;
}
int main() {

    int n = 3;  
    vector<int> batteries = {3, 3, 3};
    vector<int> batteries1 = {5, 4, 3, 6};

    long long result = maxRunTime(n, batteries1);
    cout << "Maximum Run Time: " << result << " minutes" << endl;

    return 0;
}
*/

//                             Design Movie Rental System
/*
class MovieRentingSystem {

    public:

        typedef pair<int, int> P;

        // Movie -> set<{price, shop}>
        unordered_map <int, set<P>> available; 

        // Movie -> set<shop, price>
        unordered_map <int, set<P>> movieToShopPrice; 

        // {price, shop, movie}
        set <tuple<int, int, int>> rented; 

        MovieRentingSystem(int n, vector<vector<int>>& entries) {

            for(auto& entry : entries) {
                int shop = entry[0];
                int movie = entry[1];
                int price = entry[2];
                available[movie].insert({price, shop}); 
                movieToShopPrice[movie].insert({shop, price});
            }
        }
        
        vector<int> search(int movie) {

            vector<int> result;
            int count = 0;
            if(available.count(movie)) { 
                for(auto& [_, shop] : available[movie]) {
                    result.push_back(shop);
                    count++;
                    if(count >= 5) {
                        break;
                    }
                }
            }
            return result;
        }
        
        void rent(int shop, int movie) {

            auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN}); 
            int price = it->second;

            available[movie].erase({price, shop}); 
            rented.insert({price, shop, movie}); 
        }
        
        void drop(int shop, int movie) {

            auto it = movieToShopPrice[movie].lower_bound({shop, INT_MIN});
            int price = it->second;

            available[movie].insert({price, shop});
            rented.erase({price, shop, movie});
        }
        
        vector<vector<int>> report() {

            vector<vector<int>> result;

            int count = 0;
            for(auto& [price, shop, movie] : rented) { 
                result.push_back({shop, movie});
                count++;
                if(count >= 5) {
                    break;
                }
            }
            return result;
        }
};
int main() {

    // Movie entries: {shop, movie, price}
    vector<vector<int>> entries = {
        {0, 1, 5},
        {0, 2, 6},
        {0, 3, 7},
        {1, 1, 4},
        {1, 2, 7},
        {2, 1, 5}
    };

    // Create system with 3 shops
    MovieRentingSystem mrs(3, entries);

    // Search for movie 1
    auto s = mrs.search(1);
    cout << "Search(1): ";
    for(int shop : s) {
        cout << shop << " ";
    }
    cout << endl;

    // Rent some movies
    mrs.rent(0, 1);  // shop 0 rents movie 1
    mrs.rent(1, 2);  // shop 1 rents movie 2

    // Print rented movies
    auto r = mrs.report();
    cout << "Report: ";
    for(auto &item : r) {
        cout << "(" << item[0] << "," << item[1] << ") ";
    }
    cout << endl;

    // Drop a movie
    mrs.drop(1, 2);

    // Search for movie 2
    auto s2 = mrs.search(2);
    cout << "Search(2): ";
    for(int shop : s2) {
        cout << shop << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                           Triangle

//                                           Recursive
/*
int solve(vector<vector<int>>& triangle, int row, int col) {

    if(row == triangle.size() - 1) {
        return triangle[row][col];
    }
        
    int minPath = triangle[row][col] + min(solve(triangle, row+1, col), solve(triangle, row+1, col+1));
    return minPath;
}
int minimumTotal(vector<vector<int>>& triangle) {

    return solve(triangle, 0, 0);
}
int main() {

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
*/
//                                           Top-Down
/*
int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {

    if(row == triangle.size() - 1) {
        return triangle[row][col];
    }

    if(dp[row][col] != -1) {
        return dp[row][col];
    }
        
    int minPath = triangle[row][col] + min(solve(triangle, row+1, col, dp), solve(triangle, row+1, col+1, dp));
    return dp[row][col] = minPath;
}
int minimumTotal(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(triangle, 0, 0, dp);
}
int main() {

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
*/
//                                           Top-Down
/*
int solve(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& dp) {

    if(row == triangle.size() - 1) {
        return triangle[row][col];
    }

    if(dp[row][col] != -1) {
        return dp[row][col];
    }
        
    int minPath = triangle[row][col] + min(solve(triangle, row+1, col, dp), solve(triangle, row+1, col+1, dp));
    return dp[row][col] = minPath;
}
int minimumTotal(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(triangle, 0, 0, dp);
}
int main() {

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int solve(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i=0; i < triangle[n-1].size(); i++) {
        dp[n-1][i] = triangle[n-1][i];
    }

    for(int row = n-2; row >= 0; row--) {
        for(int col=0; col <= row; col++) {
            dp[row][col] = triangle[row][col] + min(dp[row+1][col], dp[row+1][col+1]);
        }
    } 
    return dp[0][0];
}
int minimumTotal(vector<vector<int>>& triangle) {

    return solve(triangle);
}
int main() {

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
*/
//                                        Space-Optimised
/*
int solve(vector<vector<int>>& triangle) {

    int n = triangle.size();
    vector<int> curr(n, 0);
    vector<int> next(n, 0);

    for(int i=0; i < triangle[n-1].size(); i++) {
        next[i] = triangle[n-1][i];
    }

    for(int row = n-2; row >= 0; row--) {
        for(int col=0; col <= row; col++) {
            curr[col] = triangle[row][col] + min(next[col], next[col+1]);
        }
        next = curr;
    } 
    return next[0];
}
int minimumTotal(vector<vector<int>>& triangle) {

    return solve(triangle);
}
int main() {

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Minimum path sum: " << minimumTotal(triangle) << endl;

    return 0;
}
*/

//                                     Water Bottles II
/*
int maxBottlesDrunk(int numBottles, int numExchange) {

    int empty = numBottles;
    int drank = numBottles;
    while(empty >= numExchange) {
        empty -= numExchange;
        drank++;
        empty++;
        numExchange++;
    }
    return drank;
}
int main() {
   
    int numBottles = 13;
    int numExchange = 6;

    int result = maxBottlesDrunk(numBottles, numExchange);
    cout << "Maximum bottles drunk: " << result << endl;

    return 0;
}
*/

//                                  Pacific Atlantic Water Flow
/*
vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
void DFS(vector<vector<int>>& heights, int i, int j, int prevCellVal, vector<vector<bool>>& visited) {

    if(i<0 || i >= heights.size() || j<0 || j >= heights[0].size()) { 
        return;
    }

    if(heights[i][j] < prevCellVal || visited[i][j]) {
        return;
    }

    visited[i][j] = true;
    for(auto& dir : directions) {
        int i_ = i + dir[0];
        int j_ = j + dir[1];
        DFS(heights, i_, j_, heights[i][j], visited);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

    int m = heights.size();
    int n = heights[0].size(); 

    // PacificVisited[i][j] = true, means [i][j] water can go to Pacific
    vector<vector<bool>> pacificVisited(m, vector<bool>(n, false)); 

    // AtlanticVisited[i][j] = true, means [i][j] water can go to atlantic
    vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false)); 


    // Top Row and Bottom Row
    // Top Row : Pacific connected already
    // Bottom Row : atlantic connected already
    for(int j=0; j<n; j++) {
        DFS(heights, 0, j, INT_MIN, pacificVisited);
        DFS(heights, m-1, j, INT_MIN, atlanticVisited);
    }

    // First col and last column
    // First Column : Pacific connected already
    // Last Column : atlantic connected already
    for(int i=0; i<m; i++) {
        DFS(heights, i, 0, INT_MIN, pacificVisited); 
        DFS(heights, i, n-1, INT_MIN, atlanticVisited); 
    }

    vector<vector<int>> result;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                result.push_back({i, j});
            }
        }
    }
    return result;
}
int main() {

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    vector<vector<int>> ans = pacificAtlantic(heights);
    for(auto& cell : ans) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }
        
    return 0;
}
*/

//                      Count the Number of Computer Unlocking Permutations
/*
int M = 1e9+7;
int countPermutations(vector<int>& complexity) {

    int n = complexity.size();

    long long result = 1;
    for(int i=1; i<n; i++) {
        if(complexity[i] <= complexity[0]) {
            return 0;
        }
        result = (result * i) % M;
    }        
    return result;
}
int main() {

    vector<int> complexity = {1, 2, 3};
    cout << "Result = " << countPermutations(complexity) << endl;

    return 0;
}
*/

//                                  Swim in Rising Water
/*
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[50][50];
bool reachable(vector<vector<int>>& grid, int i, int j, int mid, vector<vector<bool>>& visited) {

    int n = grid.size();

    if(i<0 || i >= n || j<0 || j >= n || visited[i][j] || grid[i][j] > mid) {
        return false;
    }

    if(i == n-1 && j == n-1) {
        return true;
    }

    visited[i][j] = true;
    for(vector<int> &dir : directions) {
        int new_i = i + dir[0];
        int new_j = j + dir[1];    
        if(reachable(grid, new_i, new_j, mid, visited)) {
            return true;
        }
    }
    return false;
}    
int swimInWater(vector<vector<int>>& grid) {

    int n = grid.size();
        
    int l = grid[0][0]; 
    int r = n*n-1;
    
    int result = 0;
    while(l <= r) {
        int mid = l + (r-l) / 2;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if(reachable(grid, 0, 0, mid, visited)) {
            result = mid;
            r = mid-1;
        } 
        else {
            l = mid+1;
        }
    }    
    return result;
}
int main() {

    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };

    cout << "Minimum time: " << swimInWater(grid) << endl;

    return 0;
}
*/

//                                       Avoid Flood in The City
/*
vector<int> avoidFlood(vector<int>& rains) {

    int n = rains.size();

    // Lake -> last day it was filled
    unordered_map<int, int> map;   

    // Indices of dry days (rains[day] == 0)
    set<int> dryDays;      

    // Default all dry days to dry lake 1
    vector<int> ans(n, 1);         
    for(int day = 0; day < n; day++) {
        int lake = rains[day];
        if(lake == 0) {
            // Record this dry day
            dryDays.insert(day);                     
        } 
        else {
            // Raining day — can't dry any lake
            ans[day] = -1;                           
            if(map.count(lake)) {
                // Lake already filled previously
                // Next dry day after it was last filled
                auto it = dryDays.lower_bound(map[lake] + 1);   
                if(it == dryDays.end()) {
                    // No dry day available to empty this lake before raining again → flood
                    return {};
                }
                // Use this dry day to dry the lake
                ans[*it] = lake;                     
                dryDays.erase(it);
            }
            // Record latest day this lake was filled
            map[lake] = day;                         
        }
    }
    return ans;
}
int main() {

    vector<int> rains = {1, 2, 0, 0, 2, 1};

    vector<int> res = avoidFlood(rains);

    if(res.empty()) {
        cout << "Flood occurs, no solution.\n";
        return 0;
    }

    cout << "Result: ";
    for(int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
*/

//                                    Count Covered Buildings
/*
int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

    unordered_map<int, pair<int,int>> yToMinMaxX;
    unordered_map<int, pair<int,int>> xToMinMaxY;

    for(auto& building : buildings) {
        int x = building[0];
        int y = building[1];

        if(!yToMinMaxX.count(y)) {
            yToMinMaxX[y] = {INT_MAX, INT_MIN};
        }
        if(!xToMinMaxY.count(x)) {
            xToMinMaxY[x] = {INT_MAX, INT_MIN};
        }
        yToMinMaxX[y].first  = min(yToMinMaxX[y].first, x);
        yToMinMaxX[y].second = max(yToMinMaxX[y].second, x);

        xToMinMaxY[x].first = min(xToMinMaxY[x].first, y);
        xToMinMaxY[x].second = max(xToMinMaxY[x].second, y);
    }

    int result = 0;
    for(auto& building : buildings) {
        int x = building[0];
        int y = building[1];

        auto& xr = yToMinMaxX[y];
        auto& yr = xToMinMaxY[x];
        if(xr.first < x && x < xr.second && yr.first < y && y < yr.second) {
            result++;
        }
    }
    return result;
}
int main() {

    int n = 3;
    vector<vector<int>> buildings = {{1,2}, {2,2}, {3,2}, {2,1}, {2,3}};

    int result = countCoveredBuildings(n, buildings);
    cout << "Covered buildings = " << result << endl;

    return 0;
}
*/

//                                     Count Mentions Per User
/*
void applyMessageEvent(vector<string> event, vector<int>& mentionCount, vector<int>& offlineTime) {

    int timestamp = stoi(event[1]);

    vector<string> ids;
    string s = event[2];
    string token = "";
    for(char c : s) {
        if(c == ' ') {
            if(!token.empty()) {
                ids.push_back(token);
                token.clear();
            }
        } 
        else {
            token.push_back(c);
        }
    }
    // Last token
    if(!token.empty()) {
        ids.push_back(token);  
    }

    // Process all IDs
    for(string id : ids) {
        if(id == "ALL") {
            for(int i=0; i < mentionCount.size(); i++) {
                mentionCount[i]++;
            }
        } 
        else if(id == "HERE") {
            for(int i=0; i < mentionCount.size(); i++){
                if(offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                    mentionCount[i]++;
                }
            }
        } 
        else {
            // Fetch id value i.e. x from idx (id0, id1 etc)
            mentionCount[stoi(id.substr(2))]++; 
        }
    }
}
vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {

    vector<int> mentionCount(numberOfUsers);
    vector<int> offlineTime(numberOfUsers);

    auto lambda = [] (vector<string>& vec1, vector<string>& vec2) {
        int t1 = stoi(vec1[1]);
        int t2 = stoi(vec2[1]);

        if(t1 == t2) {
            // Comparing 'O' of "OFFLINE" with 'M' of "MESSAGE"
            // OFFLINE should come first
            return vec1[0][1] > vec2[0][1];      
        }
        return t1 < t2;
    };

    sort(events.begin(), events.end(), lambda);

    for(auto& event: events) {
        if(event[0] == "MESSAGE") {
            applyMessageEvent(event, mentionCount, offlineTime);
        }
        else if(event[0] == "OFFLINE") {
            int timestamp = stoi(event[1]);
            int id = stoi(event[2]);
            offlineTime[id] = timestamp;
        }
    }
    return mentionCount;
}
int main() {

    int numberOfUsers = 5;
    vector<vector<string>> events = {
        {"MESSAGE", "10", "ALL"},
        {"OFFLINE", "20", "2"},
        {"MESSAGE", "30", "id1 id3"},
        {"MESSAGE", "40", "HERE"},
        {"OFFLINE", "50", "1"},
        {"MESSAGE", "80", "id2 ALL"}
    };

    vector<int> result = countMentions(numberOfUsers, events);
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                    Trapping Rain Water II
/*
typedef pair<int, pair<int, int>> Cell;
vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int trapRainWater(vector<vector<int>>& heightMap) {

    int rows = heightMap.size();
    int cols = heightMap[0].size();

    // Min-heap to always pick the lowest height cell first
    priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

    // To avoid processing the same cell more than once
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Add leftmost and rightmost columns for all rows
    for(int r=0; r < rows; r++) {
        // Left boundary cell
        minHeap.push({heightMap[r][0], {r, 0}});
        visited[r][0] = true;

        // Right boundary cell
        minHeap.push({heightMap[r][cols - 1], {r, cols - 1}});
        visited[r][cols - 1] = true;
    }

    // Add top and bottom rows for all columns
    for(int c=0; c < cols; c++) {
        // Top boundary
        minHeap.push({heightMap[0][c], {0, c}});
        visited[0][c] = true;

        // Bottom boundary
        minHeap.push({heightMap[rows - 1][c], {rows - 1, c}});
        visited[rows - 1][c] = true;
    }

    int totalWater = 0;
    while(!minHeap.empty()) {
        // Pop the lowest boundary cell
        auto [boundaryHeight, cell] = minHeap.top();
        minHeap.pop();

        int row = cell.first;
        int col = cell.second;
        for(auto& dir : directions) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
                totalWater += max(0, boundaryHeight - heightMap[newRow][newCol]);       
                minHeap.push({max(boundaryHeight, heightMap[newRow][newCol]), {newRow, newCol}});                    
                visited[newRow][newCol] = true;
            }
        }
    }
    return totalWater;
}
int main() {

    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };

    int result = trapRainWater(heightMap);
    cout << "Total trapped rain water: " << result << endl;

    return 0;
}
*/

//                                     Find Closest Person
/*
int findClosest(int x, int y, int z) {

    int dxz = abs(x-z);
    int dyz = abs(y-z);
    if(dxz < dyz) {
        return 1;
    }
    else if(dxz > dyz) {
        return 2;
    }
    return 0;
}
int main() {

    int x = 2;
    int y = 7;
    int z = 4;

    int result = findClosest(x, y, z);
    cout << "Result: " << result << endl;

    return 0;
}
*/

//                                 Minimum Time to Make Rope Colorful
/*
int minCost(string colors, vector<int>& neededTime) {

    int n = colors.size();

    int time = 0;
    int prevMax = 0;
    for(int i=0; i<n; i++) {
        if(i>0 && colors[i] != colors[i-1]) {
            prevMax = 0;
        }
        int curr = neededTime[i];
        time += min(prevMax, curr);
        prevMax = max(prevMax, curr);
    }
    return time;
}
int main() {

    string colors = "abaac";
    vector<int> neededTime = {1, 2, 3, 4, 5};

    int result = minCost(colors, neededTime);
    cout << "Minimum time to remove balloons: " << result << endl;

    return 0;
}
*/

//                                  Design a Food Rating System
/*
class FoodRatings {

    public:
    unordered_map <string, set<pair<int, string>>> cuisine_ratings_food;
    unordered_map <string, string> food_cuisine;
    unordered_map <string, int> food_rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            
        int n = foods.size();    
        for(int i=0; i<n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
                
            cuisine_ratings_food[cuisine].insert({-rating, food});
            food_cuisine[food] = cuisine;
            food_rating[food]  = rating;            
        }
    }  
    void changeRating(string food, int newRating) {
            
        string cuisine = food_cuisine[food];
        int oldRating  = food_rating[food];
            
        cuisine_ratings_food[cuisine].erase({-oldRating, food});
        cuisine_ratings_food[cuisine].insert({-newRating, food});
        food_rating[food] = newRating;        
    }    
    string highestRated(string cuisine) {

        // return cuisine_ratings_food[cuisine].begin()->second;
        // Or
        return (*cuisine_ratings_food[cuisine].begin()).second;
    }
};
int main() {

    vector<string> foods = {
        "kimchi", "miso", "sushi",
        "moussaka", "ramen", "bulgogi"
    };
    vector<string> cuisines = {
        "korean", "japanese", "japanese",
        "greek", "japanese", "korean"
    };
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    // Operation 1: FoodRatings constructor
    FoodRatings fr(foods, cuisines, ratings);

    // Operation 2
    cout << fr.highestRated("korean") << endl;    // kimchi

    // Operation 3
    cout << fr.highestRated("japanese") << endl;  // ramen

    // Operation 4
    fr.changeRating("sushi", 16);

    // Operation 5
    cout << fr.highestRated("japanese") << endl;  // sushi

    // Operation 6
    fr.changeRating("ramen", 16);

    // Operation 7
    cout << fr.highestRated("japanese") << endl;  // ramen

    return 0;
}
*/

//                                    Compare Version Numbers
/*
vector<string> getTokens(string version) {

    stringstream v(version);
    string token_v = "";

    vector<string> version_tokens;
    while(getline(v, token_v, '.')) {
        version_tokens.push_back(token_v);
    }
    return version_tokens;
}
int compareVersion(string version1, string version2) {

    vector<string> v1 = getTokens(version1);
    vector<string> v2 = getTokens(version2);  
        
    int m = v1.size();
    int n = v2.size();
            
    int  i=0;
    while(i<m || i<n) {        
        int a = i<m ? stoi(v1[i]) : 0 ;
        int b = i<n ? stoi(v2[i])  : 0 ;
            
        if(a>b) {        
            return 1;
        }
        else if(b>a) {
            return -1;
        }
        else {
            i++;
        }
    }
    return 0;
}
int main() {

    string version1 = "1.01";
    string version2 = "1.001";

    int result = compareVersion(version1, version2);
    cout << result << endl;

    return 0;
}
*/

//                                     Largest Triangle Area
/*
double largestTriangleArea(vector<vector<int>>& points) {

    int n = points.size();
    double maxArea = 0.0;
    for(int i=0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            for(int k = j+1; k<n; k++) {
                double x1 = points[i][0];
                double y1 = points[i][1];

                double x2 = points[j][0];
                double y2 = points[j][1];

                double x3 = points[k][0];
                double y3 = points[k][1];

                // Heron's Formula
                double a = hypot(x2-x1, y2-y1);
                double b = hypot(x2-x3, y2-y3);
                double c = hypot(x3-x1, y3-y1);
                double s = (a+b+c) * 0.5;
                double heron = sqrt(s * (s-a) * (s-b) * (s-c));

                // Shoelace Formula
                double shoelace = 0.5 * abs(x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2));

                maxArea = max({maxArea, heron, shoelace});
            }
        }
    }
    return maxArea;
}
int main() {

    vector<vector<int>> points = {
        {0, 0},
        {0, 1},
        {1, 0},
        {0, 2},
        {2, 0}
    };

    cout << fixed << setprecision(4) << largestTriangleArea(points) << endl;

    return 0;
}
*/

//                               Find Triangular Sum of an Array
/*
int triangularSum(vector<int>& nums) {

    int n = nums.size();
    for(int size = n-1; size >= 1; size--) {
        for(int i=0; i < size; i++) {
            nums[i] = (nums[i] + nums[i+1]) % 10;
        }    
    }
    return nums[0];
}
int main() {

    vector<int> nums = {1, 2, 3, 4, 5};
    cout << triangularSum(nums) << endl;

    return 0;
}
*/

//                                    Coupon Code Validator
/*
bool checkValidCode(string& code) {

    if(code.empty()) {
        return false;
    }
    for(char& ch : code) {
        if(!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}
vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
    unordered_map<string, int> mp = {
        {"electronics", 0},
        {"grocery", 1},
        {"pharmacy", 2},
        {"restaurant", 3}
    };

    // {BusinessLineIntegerValue, code}
    vector<pair<int, string>> temp; 
    for(int i=0; i < code.size(); i++) {
        if(isActive[i] && mp.count(businessLine[i]) && checkValidCode(code[i])) {
            temp.push_back({mp[businessLine[i]], code[i]});
        }
    }
    sort(begin(temp), end(temp));
        
    vector<string> result;
    for(auto& it : temp) {
        result.push_back(it.second);
    }
    return result;
}
int main() {

    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};

    vector<string> result = validateCoupons(code, businessLine, isActive);
    cout << "Valid Coupons:\n";
    for(string& s : result) {
        cout << s << endl;
    }

    return 0;
}
*/

//                          Find the Minimum Amount of Time to Brew Potions
/*
long long minTime(vector<int>& skill, vector<int>& mana) {

    int n = skill.size();
    int m = mana.size();

    vector<long long> finishTime(n, 0);
    for(int j=0; j<m; j++) {
        finishTime[0] += 1LL * mana[j] * skill[0];

        for(int i=1; i<n; i++) {
            finishTime[i] = max(finishTime[i], finishTime[i-1]) + 1LL * mana[j] * skill[i];
        }
        for(int i = n-1; i>0; i--) {
            finishTime[i-1] = finishTime[i] - 1LL * mana[j] * skill[i];
        }
    }
    return finishTime[n-1];
}
int main() {

    vector<int> skill = {1, 5, 2, 4};
    vector<int> mana  = {5, 1, 4, 2};

    long long result = minTime(skill, mana);
    cout << result << endl;

    return 0;
}
*/

//                             Number of Ways to Divide a Long Corridor
/*
int mod = 1e9 + 7; 
int numberOfWays(string corridor) {

    vector<int> pos_seats;    
    for(int i=0; i < corridor.size(); i++) {
        if(corridor[i] == 'S') {
            pos_seats.push_back(i);
        }
    }
        
    if(pos_seats.size() % 2 || pos_seats.size() == 0) {
        return 0;
    }
        
    // End index of the starting subarray having 2 seats
    int prev = pos_seats[1]; 

    long long result = 1;
    for(int i=2; i < pos_seats.size(); i += 2) {
        int length = pos_seats[i] - prev;
        result = (result * length) % mod;    
        prev = pos_seats[i+1];
    }    
    return result;
}
int main() {

    string corridor = "SSPPSPS";
    cout << numberOfWays(corridor) << endl;

    return 0;
}
*/

//                          Taking Maximum Energy From the Mystic Dungeon

//                                          Recursive
/*
int solve(vector<int>& energy, int k, int i) {

    if(i >= energy.size()) { 
        return 0;
    }

    // Take energy at i and then best from (i + k) onwards - Recursion leap of faith
    return energy[i] + solve(energy, k, i+k);
}
int maximumEnergy(vector<int>& energy, int k) {
    
    int n = energy.size();

    int maxEnergy = INT_MIN;
    for(int i=0; i<n; i++) {
        maxEnergy = max(maxEnergy, solve(energy, k, i));
    }
    return maxEnergy;
}
int main() {

    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    int result = maximumEnergy(energy, k);
    cout << result << endl;

    return 0;
}
*/
//                                          Top-Down
/*
int solve(vector<int>& energy, int k, int i, vector<int>& t) {

    if(i >= energy.size()) { 
        return 0;
    }

    if(t[i] != INT_MIN) {
        return t[i];
    }

    // Take energy at i and then best from (i + k) onwards - Recursion leap of faith
    return t[i] = energy[i] + solve(energy, k, i+k, t);
}
int maximumEnergy(vector<int>& energy, int k) {
    
    int n = energy.size();
    vector<int> t(n, INT_MIN);

    int maxEnergy = INT_MIN;
    for(int i=0; i<n; i++) {
        maxEnergy = max(maxEnergy, solve(energy, k, i, t));
    }
    return maxEnergy;
}
int main() {

    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    int result = maximumEnergy(energy, k);
    cout << result << endl;

    return 0;
}
*/
//                                        Bottom-Up
/*
int solve(vector<int>& energy, int k) {

    int n = energy.size();

    vector<int> t(n, 0);
    for(int i = n-1; i >= 0; i--) {
        if(i+k < n) {
            t[i] = energy[i] + t[i+k];
        }
        else {
            t[i] = energy[i];
        }
    }
    int maxEnergy = INT_MIN;
    for(int i=0; i<n; i++) {
        maxEnergy = max(maxEnergy, t[i]);
    }
    return maxEnergy;
}
int maximumEnergy(vector<int>& energy, int k) {
    
    return solve(energy, k);
}
int main() {

    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    int result = maximumEnergy(energy, k);
    cout << result << endl;

    return 0;
}
*/

//                        Find Resultant Array After Removing Anagrams

//                                         Approach 1
/*
bool checkAnagram(string& s1, string& s2) {

    int arr[26] = {0};
    for(char& ch : s1) {
        arr[ch-'a']++;
    }

    for(char& ch : s2) {
        arr[ch-'a']--;
    }
        
    for(int i=0; i<26; i++) {
        if(arr[i] != 0) {
            return false;
        }
    }
    return true;
}
vector<string> removeAnagrams(vector<string>& words) {

    int n = words.size();

    vector<string> result;
    result.push_back(words[0]);
    for(int i=1; i<n; i++) {
        if(!checkAnagram(words[i], result.back())) {
            result.push_back(words[i]);
        }
    }
    return result;
}
int main() {

    vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> ans = removeAnagrams(words);
    for(auto& w : ans) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
*/
//                                         Approach 2
/*
bool checkAnagram(string s1, string s2) {

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}
vector<string> removeAnagrams(vector<string>& words) {

    int n = words.size();

    vector<string> result;
    result.push_back(words[0]);
    for(int i=1; i<n; i++) {
        if(!checkAnagram(words[i], result.back())) {
            result.push_back(words[i]);
        }
    }
    return result;
}
int main() {

    vector<string> words = {"abba","baba","bbaa","cd","cd"};

    vector<string> ans = removeAnagrams(words);
    for(auto& w : ans) {
        cout << w << " ";
    }
    cout << endl;

    return 0;
}
*/

//                          Adjacent Increasing Subarrays Detection I

//                                         Approach 1
/*
bool isIncreasing(vector<int>& nums, int start, int end) {

    for(int i = start + 1; i < end; i++) {
        if(nums[i] <= nums[i-1]) {
            return false;
        }
    }
    return true;
}
bool hasIncreasingSubarrays(vector<int>& nums, int k) {

    int n = nums.size();
    for(int start = 0; start + 2*k <= n; start++) {
        bool firstInc = isIncreasing(nums, start, start + k);
        bool secondInc = isIncreasing(nums, start + k, start + 2*k);
        if(firstInc && secondInc) {
            return true;
        }
    }
    return false;
}
int main() {

    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int k = 3;

    if(hasIncreasingSubarrays(nums, k)) {
        cout << "True";
    } 
    else {
        cout << "False";
    }

    return 0;
}
*/
//                                         Approach 2
/*
bool hasIncreasingSubarrays(vector<int>& nums, int k) {

    int n = nums.size();

    int currRun = 1;
    int prevRun = 0;
    for(int i=1; i<n; i++) {
        if(nums[i] > nums[i-1]) {
            currRun++;
        } 
        // Increaseing order break hogaya yaha par
        else { 
            prevRun = currRun;
            currRun = 1;
        }

        // We can accomodate two subarrays in it length. >= k
        if(currRun >= 2*k) { 
            return true;
        }

        if(min(currRun, prevRun) >= k) {
            return true;
        }
    }
    return false;
}
int main() {

    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    int k = 3;

    if(hasIncreasingSubarrays(nums, k)) {
        cout << "True";
    } 
    else {
        cout << "False";
    }

    return 0;
}
*/

//                             Adjacent Increasing Subarrays Detection II
/*
int maxIncreasingSubarrays(vector<int>& nums) {

    int n = nums.size();

    int currRun = 1;
    int prevRun = 0;

    int maxResult = 0;
    for(int i=1; i<n; i++) {
        if(nums[i] > nums[i-1]) {
            currRun++;
        } 
        // Increasing order breaks here
        else { 
            prevRun = currRun;
            currRun = 1;
        }

        maxResult = max(maxResult, currRun/2);
        maxResult = max(maxResult, min(prevRun, currRun));
    }
    return maxResult;
}
int main() {

    vector<int> nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    cout << maxIncreasingSubarrays(nums);

    return 0;
}
*/

//                              Calculate Money in Leetcode Bank

//                                         Approach 1
/*
int totalMoney(int n) {

    int result = 0;
        
    int monday_money = 1;    
    while(n>0) {      
        int money = monday_money;
        for(int day = 1; day <= min(n, 7); day++) {
            result += money++;
        }    
        n -= 7;
        monday_money += 1;
    }    
    return result;    
}
int main() {

    int n = 10; 
    cout << totalMoney(n);

    return 0;
}
*/
//                                         Approach 2
/*
int totalMoney(int n) {

    int weeks  = n/7;

    int weeksmoney = 0;
    int money = 28;
    for(int week = 1; week <= weeks; week++) { 
        weeksmoney += money;
        money += 7;
    }   
    
    int days  = n%7;
    int daysmoney = 0;
    money = weeks + 1;
    for(int day = 1; day <= days; day++) { 
        daysmoney += money;
        money++;
    }
        
    return daysmoney + weeksmoney;
}
int main() {

    int n = 10; 
    cout << totalMoney(n);

    return 0;
}
*/

//                                        Simple Bank System
/*
class Bank {

    public:
        vector<long long> balance;
        int n;

        Bank(vector<long long>& balance) {

            n = balance.size();
            this->balance = balance;
            cout << "null" << endl;
        }
        bool transfer(int account1, int account2, long long money) {

            if(account1 > n || account2 > n || balance[account1-1] < money) {
                return false;
            }
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        bool deposit(int account, long long money) {

            if(account > n) {
                return false;
            }
            balance[account-1] += money;
            return true;
        }
        bool withdraw(int account, long long money) {

            if(account > n || balance[account-1] < money) {
                return false;
            }
            balance[account-1] -= money;
            return true;
        }
};
int main() {

    cout << boolalpha;

    // ["Bank"]
    vector<long long> balances = {10, 100, 20, 50, 30};
    Bank bank(balances);

    // ["withdraw", 3, 10]
    cout << bank.withdraw(3, 10) << endl;

    // ["transfer", 5, 1, 20]
    cout << bank.transfer(5, 1, 20) << endl;

    // ["deposit", 5, 20]
    cout << bank.deposit(5, 20) << endl;

    // ["transfer", 3, 4, 15]
    cout << bank.transfer(3, 4, 15) << endl;

    // ["withdraw", 10, 50]
    cout << bank.withdraw(10, 50) << endl;

    return 0;
}
*/

//                           Number of Smooth Descent Periods of a Stock
/*
long long getDescentPeriods(vector<int>& prices) {

    long long result = 1;
    long long count = 1;
    for(int i=1; i < prices.size(); i++) {
        if(prices[i-1] - prices[i] == 1) {
            count++;
        }
        else {
            count = 1;
        }
        result += count;
    }
    return result;
}
int main() {

    vector<int> prices = {3, 2, 1, 4};
    cout << getDescentPeriods(prices);

    return 0;
}
*/

//                              Smallest Number With All Set Bits

//                                         Approach 1
/*
bool isAllBitsSet(int x) {

    return (x & (x+1)) == 0;
}
int smallestNumber(int n) {
        
    int result = n;
    while(!isAllBitsSet(result)) {
        result++;
    }
    return result;
}
int main() {
    
    int n = 10;
    cout << smallestNumber(n);

    return 0;
}
*/
//                                         Approach 2
/*
int smallestNumber(int n) {

    int result = 1;
    while(result < n) {
        result = 2*result + 1;
    }
    return result;
}
int main() {
    
    int n = 10;
    cout << smallestNumber(n);

    return 0;
}
*/

//                                        Bag of Tokens
/*
int bagOfTokensScore(vector<int>& tokens, int P) {

    int n = tokens.size();
    sort(tokens.begin(), tokens.end());
        
    // While losing power, I will choose the smallest token
    // While gaining power, I will choose the largest token
    int currScore = 0;
    int maxScore = 0;
    int l = 0;
    int r = n-1;
    while(l <= r) {
        if(P >= tokens[l]) {
            currScore++;
            maxScore = max(maxScore, currScore); 
            P -= tokens[l];
            l++;    
        } 
        else if(currScore >= 1) {
            currScore--;
            P += tokens[r]; //choose largest token
            r--;            
        } 
        else {
            return maxScore;
        }
    }
    return maxScore;
}
int main() {

    vector<int> tokens = {100, 200, 300, 400};
    int P = 200;

    int result = bagOfTokensScore(tokens, P);
    cout << "Maximum Score: " << result << endl;

    return 0;
}
*/

//                            Maximum Total Damage With Spell Casting

//                                         Recursive
/*
typedef long long ll;                                          
long long solve(vector<ll>& nums, int i, unordered_map<ll, ll>& mp) {

    if(i >= nums.size()) { 
        return 0;
    }
        
    // Skip current damage
    ll skip = solve(nums, i+1, mp);

    // Take current damage
    int j = lower_bound(begin(nums), end(nums), nums[i] + 3) - begin(nums);
    ll take = nums[i] * mp[nums[i]] + solve(nums, j, mp);

    return max(skip, take);
}
long long maximumTotalDamage(vector<int>& power) {

    unordered_map<ll, ll> mp;
    for(int& x : power) {
        mp[x]++;
    }

    vector<ll> nums;
    for(auto& it : mp) {
        nums.push_back(it.first);
    }

    sort(begin(nums), end(nums));
    return solve(nums, 0, mp);
}
int main() {

    vector<int> power = {1, 1, 3, 4};
    cout << "Maximum Total Damage: " << maximumTotalDamage(power) << endl;

    return 0;
}
*/
//                                         Top-Down
/*
typedef long long ll;                                          
long long solve(vector<ll>& nums, int i, unordered_map<ll, ll>& mp, vector<ll>& dp) {

    if(i >= nums.size()) { 
        return 0;
    }
    
    if(dp[i] != -1) {
        return dp[i];
    }

    // Skip current damage
    ll skip = solve(nums, i+1, mp, dp);

    // Take current damage
    int j = lower_bound(begin(nums), end(nums), nums[i] + 3) - begin(nums);
    ll take = nums[i] * mp[nums[i]] + solve(nums, j, mp, dp);

    return dp[i] = max(skip, take);
}
long long maximumTotalDamage(vector<int>& power) {

    unordered_map<ll, ll> mp;
    for(int& x : power) {
        mp[x]++;
    }

    vector<ll> nums;
    for(auto& it : mp) {
        nums.push_back(it.first);
    }

    vector<ll> dp(nums.size() + 1, -1);

    sort(begin(nums), end(nums));
    return solve(nums, 0, mp, dp);
}
int main() {

    vector<int> power = {1, 1, 3, 4};
    cout << "Maximum Total Damage: " << maximumTotalDamage(power) << endl;

    return 0;
}
*/
//                                         Bottom-Up
/*
typedef long long ll;                                          
long long solve(vector<ll>& nums, unordered_map<ll, ll>& mp) {

    vector<ll> dp(nums.size(), 0);

    for(int i = nums.size()-1; i >= 0; i--) {
        // Skip current damage
        ll skip = 0;
        if(i+1 < nums.size()) {
            skip = dp[i+1];
        }
        // Take current damage
        int j = lower_bound(begin(nums), end(nums), nums[i] + 3) - begin(nums);
        ll take = nums[i] * mp[nums[i]];
        if(j < nums.size()) {
            take += dp[j];
        }
        dp[i] = max(skip, take);
    }
    return dp[0];
}
long long maximumTotalDamage(vector<int>& power) {

    unordered_map<ll, ll> mp;
    for(int& x : power) {
        mp[x]++;
    }

    vector<ll> nums;
    for(auto& it : mp) {
        nums.push_back(it.first);
    }

    sort(begin(nums), end(nums));
    return solve(nums, mp);
}
int main() {

    vector<int> power = {1, 1, 3, 4};
    cout << "Maximum Total Damage: " << maximumTotalDamage(power) << endl;

    return 0;
}
*/

//                             Best Time to Buy and Sell Stock V

//                                          Recursive
/*
// CASE:
// 0 -> You have not bought anything and you have not short-sold anything.
// 1 -> Normal transaction - you had bought, now you will sell normally
// 2 -> Short selling transaction - you had sold, now you will buy back
long long solve(int i, int k, int CASE, vector<int>& prices) {

    if(i == prices.size()) {
        if(CASE == 0) {
            return 0;
        }
        // An unfinished transaction is invalid.
        return INT_MIN; 
    }

    long long take = INT_MIN;
    long long dontTake;

    // Do nothing today
    dontTake = solve(i+1, k, CASE, prices);
    // Take action
    if(k>0) {
        if(CASE == 1) {
            // Sell today (complete normal transaction)
            take = prices[i] + solve(i+1, k-1, 0, prices);
        }
        else if(CASE == 2) {
            // Buy back today (complete short transaction)
            take = -prices[i] + solve(i+1, k-1, 0, prices);
        }
        else {
            // CASE == 0: Start a transaction
            take = max(-prices[i] + solve(i+1, k, 1, prices), prices[i] + solve(i+1, k, 2, prices));
        }
    }
    return max(take, dontTake);
}
long long maximumProfit(vector<int>& prices, int k) {

    return solve(0, k, 0, prices);
}
int main() {

    vector<int> prices = {1, 7, 9, 8, 2};
    int k = 2;

    cout << "Maximum Profit: " << maximumProfit(prices, k) << endl;

    return 0;
}
*/
//                                          Top-Down
/*
// CASE:
// 0 -> You have not bought anything and you have not short-sold anything.
// 1 -> Normal transaction - you had bought, now you will sell normally
// 2 -> Short selling transaction - you had sold, now you will buy back
long long solve(int i, int k, int CASE, vector<int>& prices, vector<vector<vector<long long>>>& dp) {

    if(i == prices.size()) {
        if(CASE == 0) {
            return 0;
        }
        // An unfinished transaction is invalid.
        return INT_MIN; 
    }

    if(dp[i][k][CASE] != -1) {
        return dp[i][k][CASE];
    }

    long long take = INT_MIN;
    long long dontTake;

    // Do nothing today
    dontTake = solve(i+1, k, CASE, prices, dp);
    // Take action
    if(k>0) {
        if(CASE == 1) {
            // Sell today (complete normal transaction)
            take = prices[i] + solve(i+1, k-1, 0, prices, dp);
        }
        else if(CASE == 2) {
            // Buy back today (complete short transaction)
            take = -prices[i] + solve(i+1, k-1, 0, prices, dp);
        }
        else {
            // CASE == 0: Start a transaction
            take = max(-prices[i] + solve(i+1, k, 1, prices, dp), prices[i] + solve(i+1, k, 2, prices, dp));
        }
    }
    return dp[i][k][CASE] = max(take, dontTake);
}
long long maximumProfit(vector<int>& prices, int k) {

    int n = prices.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));

    return solve(0, k, 0, prices, dp);
}
int main() {

    vector<int> prices = {1, 7, 9, 8, 2};
    int k = 2;

    cout << "Maximum Profit: " << maximumProfit(prices, k) << endl;

    return 0;
}
*/
//                                          Bottom-Up
/*
// CASE:
// 0 -> You have not bought anything and you have not short-sold anything.
// 1 -> Normal transaction - you had bought, now you will sell normally
// 2 -> Short selling transaction - you had sold, now you will buy back
long long solve(vector<int>& prices, int K) {

    int n = prices.size();

    vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(K+1, vector<long long>(3, 0)));

    for(int k=0; k <= K; k++) {
        dp[n][k][0] = 0;
        dp[n][k][1] = INT_MIN;
        dp[n][k][2] = INT_MIN;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int k=0; k <= K; k++) {
            for(int CASE = 0; CASE <=2; CASE++) {
                long long take = INT_MIN;
                long long dontTake;
                // Do nothing today
                dontTake = dp[i+1][k][CASE];
                // Take action
                if(k>0) {
                    if(CASE == 1) {
                        // Sell today (complete normal transaction)
                        take = prices[i] + dp[i+1][k-1][0];
                    }
                    else if(CASE == 2) {
                        // Buy back today (complete short transaction)
                        take = -prices[i] + dp[i+1][k-1][0];
                    }
                    else {
                        // CASE == 0: Start a transaction
                        take = max(-prices[i] + dp[i+1][k][1], prices[i] + dp[i+1][k][2]);
                    }
                }
                dp[i][k][CASE] = max(take, dontTake);
            }
        }
    }
    return dp[0][K][0];
}
long long maximumProfit(vector<int>& prices, int k) {

    return solve(prices, k);
}
int main() {

    vector<int> prices = {1, 7, 9, 8, 2};
    int k = 2;

    cout << "Maximum Profit: " << maximumProfit(prices, k) << endl;

    return 0;
}
*/