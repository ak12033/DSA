#include<iostream>
using namespace std;

//                              Reverse the String
/*
void reverse(string& str, int i, int j ) {

    cout << "call received for " << str << endl;

    // Base Case
    if(i>j){
        return ;
    }
    swap(str[i], str[j]);
    i++;
    j--;

    // Recursive Call
    reverse(str,i,j);
}
int main() {

    string name = "abcde";
    cout << endl;
    reverse(name, 0 , name.length()-1 );
    cout << endl;
    cout << name << endl;

    return 0;
}
*/
//                                        OR
/*
void reverse(string& str, int i){

    if(i==str.length()){
        return;
    }
    reverse(str,i+1);
    cout<<str[i];
}
int main() {

    string name = "babbar";
    cout << endl;
    reverse(name, 0);
    cout << endl;

    return 0;
}
*/
//                                          OR
/*
int reverse(string& str, int i ) {

    cout << "call recieved for " << str << endl;

    //base case
    if(i>str.size()-1-i){
        return false;
    }
    else{
        swap(str[i], str[str.size()-1-i]);
        i++;
    return reverse(str,i);
    }
}
int main() {

    string str;
    cout << "ENTER STRING"<<endl;
    getline(cin,str);
    int i=0;
    reverse(str,i);
    cout << "DESIRED OUTPUT: ";
    cout << str;

    return 0;
}
*/

//                                  Check Palindrome
/*
bool checkPalindrome(string str, int i, int  j) {

    // Base Case
    if(i>j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    //Recursive Call
    else{
        return checkPalindrome(str, i+1,j-1);
    }
}
int main() {

    string name = "BabbaB";
    cout << endl;

    bool isPalindrome = checkPalindrome(name, 0, name.length()-1 );

    if(isPalindrome) {
        cout << "Its a Palindrome " << endl; 
    }
    else {
        cout << "Its not a Palindrome " << endl;
    }
    return 0;
}
*/

//                                  a raise to the power b
/*
int power(int a, int b) {

    // Base Case
    if( b == 0 ){
        return 1;
    }
    if(b == 1){
        return a;
    }
    // Recursive Call
    int ans = power(a, b/2);

    // if b is even
    if(b%2 == 0) {
        return ans * ans;
    }
    // if b is odd
    else {
        return a * ans * ans;
    }
}
int main() {

    int a,b;
    cin >> a >> b;
    cout << endl;

    int ans = power(a,b);
    cout << "Answer is " << ans << endl;

    return 0;
}
*/

//                                     Bubble Sort
/*
void sortArray(int *arr, int n) {

    // Base Case - already sorted
    if(n == 0 || n == 1) {
        return ;
    }
    // 1 case sovle karlia - largest element ko end me rakh dega
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    // Recursive Call
    sortArray(arr, n-1);
}
int main() {

    int arr[5] = {2,5,1,6,9};
    
    sortArray(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                    Selection Sort
/*
void selectionSort_recursion(int* arr, int n){

    // Base Case
    if(n==0 || n==1){
        return;
    }
    // Swap one item correctly
    int min_idx = 0;
    for(int i=1;i<n;i++){
        if(arr[min_idx]>arr[i]){
            min_idx = i;
        }
    }
    swap(arr[min_idx], arr[0]);
    // Arrange other using recursion
    selectionSort_recursion(arr+1, n-1);
}
int main() {

    int arr[5] = {2,5,1,6,9};
    
    selectionSort_recursion(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

//                                 Insertion Sort
/*
void sortArray(int arr[], int n){
    
    // Base case: if n <= 1, the array is trivially sorted
    if (n <= 1) {
        return;
    }

    // Recursively sort the first n-1 elements
    sortArray(arr, n - 1);

    // Insert the nth element into the sorted portion of the array
    int j = n - 1;
    while (j>0 && arr[j-1]>arr[j]) {
        swap(arr[j], arr[j - 1]);
        j--;
    }  
}
int main(){

    int arr[5]={4,7,1,11,5};
    
    sortArray(arr, 5);
    
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
*/

