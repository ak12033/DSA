#include <iostream>
#include <math.h>
#include <limits.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm> 
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