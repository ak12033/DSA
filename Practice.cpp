#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>
#include <cstring>
#include <vector>
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

    for(int candy : candies) {
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

//                              Apply Operations to Maximize Score
/*
const int MOD = 1e9 + 7;

long long findPower(long long a, long long b)
{

    if (b == 0)
        return 1;
    long long half = findPower(a, b / 2);
    long long result = (half * half) % MOD;
    if (b % 2 == 1)
    {
        result = (result * a) % MOD;
    }
    return result;
}

vector<int> getPrimes(int limit)
{
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> findPrimeScores(vector<int> &nums)
{
    int n = nums.size();
    vector<int> primeScores(n, 0);

    int maxElement = *max_element(begin(nums), end(nums));
    vector<int> primes = getPrimes(maxElement); // O(mloglogm)

    for (int i = 0; i < n; i++)
    { // O(n * log(m))
        int num = nums[i];

        for (int prime : primes)
        {
            if (prime * prime > num)
            {
                break;
            }

            if (num % prime != 0)
            {
                continue;
            }

            primeScores[i]++;
            while (num % prime == 0)
            {
                num /= prime;
            }
        }
        if (num > 1)
        { // example : 15 : 3, 5
            primeScores[i]++;
        }
    }

    return primeScores;
}

vector<int> findNextGreater(vector<int> &primeScores)
{
    int n = primeScores.size();
    vector<int> nextGreator(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && primeScores[st.top()] <= primeScores[i])
        {
            st.pop();
        }

        nextGreator[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nextGreator;
}

vector<int> findPrevGreater(vector<int> &primeScores)
{
    int n = primeScores.size();
    vector<int> prevGreator(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && primeScores[st.top()] < primeScores[i])
        {
            st.pop();
        }

        prevGreator[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return prevGreator;
}

int maximumScore(vector<int> &nums, int k)
{
    vector<int> primeScores = findPrimeScores(nums);        // O(mloglogm + n*log(m))
    vector<int> nextGreater = findNextGreater(primeScores); // O(n)
    vector<int> prevGreater = findPrevGreater(primeScores); // O(n)

    int n = nums.size();
    vector<long long> subarrays(n, 0);

    for (int i = 0; i < n; i++)
    { // O(n)
        subarrays[i] = (long long)(nextGreater[i] - i) * (i - prevGreater[i]);
    }

    vector<pair<int, int>> sortedNums(n);
    for (int i = 0; i < n; i++)
    {
        sortedNums[i] = {nums[i], i};
    }

    sort(begin(sortedNums), end(sortedNums), greater<>()); // O(nlogn)

    long long score = 1;

    int idx = 0; // start from largest element greedily
    while (k > 0)
    { // O(k * log(operations))
        auto [num, i] = sortedNums[idx];

        long long operations = min((long long)k, subarrays[i]);

        score = (score * findPower(num, operations)) % MOD;

        k = (k - operations);
        idx++;
    }

    return score;
}
int main() {

    vector<int> nums = {5, 3, 2, 8, 6, 4};
    int k = 3;
        
    cout << "Maximum Score: " << maximumScore(nums, k) << endl;

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
/**/

/**/

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