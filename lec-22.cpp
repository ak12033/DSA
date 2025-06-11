#include<iostream> 
#include<vector>
#include <bits/stdc++.h>
using namespace std;

//                                     Char Array

//                                  Length of a String
/*
int getLength(char name[]) {

    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}
int main( ) {

    char name[20];

    cout << "Enter your name " << endl;
    cin >> name;

    // name[2] = '\0';

    cout << "Your name is ";
    cout << name << endl;

    cout << " Length: " << getLength(name) << endl;

    return 0;
}
*/

//                                   Reverse String
/*
void reverseString(vector<char>& s) {

    int st = 0;
    int e = s.size()-1;
    while(st<e) {
        swap(s[st++], s[e--]);
    }  
}
int main() {

    // Sample input string as a vector of characters
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    // Display the original string
    cout << "Original string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    
    // Call the reverseString function
    reverseString(s);
    
    // Display the reversed string
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    
    return 0;
}
*/

//                     Check If The String Is A Palindrome(Case Sensitive)
/*
bool checkPalindrome(char a[], int n) {

    int s = 0;
    int e = n-1;
    while(s<=e) {
        if( a[s]  !=  a[e] ) 
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int getLength(char name[]) {

    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }
    return count;
}
int main(){

    char name[20];

    cout << "Enter your name " << endl;
    cin >> name;

    cout << "Your name is ";
    cout << name << endl;

    int len = getLength(name);
    cout << " Length: " << len << endl;

    cout <<" Palindrome or Not: " << checkPalindrome(name, len) << endl;

    return 0;
}
*/

//                    Check If The String Is A Palindrome(Not Case Sensitive)
/*
char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string s){

    int st = 0;
    int e = s.length()-1;
    while(st<e) {
        if (!isalnum(s[st])) {
            st++;
        }
        else if (!isalnum(s[e])) {
            e--;
        }
        else if(toLowerCase(s[st]) != toLowerCase(s[e])) {
            return 0;
        } 
        else {
            st++;
            e--;
        }
    }
    return 1;
}
int main(){

    string s1 = "c1 O$d@eeD o1c";
    string s2 = "N2 i&nJA?a& jnI2n";
    string s3 = "A1b22Ba";
    string s4 = "codingninjassajNiNgNidoc";
    string s5 = "5?36@6?35";
    string s6 = "aaBBa@";

    cout<<s1<<" -> "<<checkPalindrome(s1)<<endl;

    return 0;
}
*/

//                                   Valid Palindrome
/*
bool valid(char ch) {

    if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }    
    return 0;
}
char toLowerCase(char ch) {

    if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string a) {

    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
bool isPalindrome(string s) {

    //faltu character hatado
    string temp = "";
        
    for(int j=0; j<s.length(); j++) {   
        if(valid(s[j])) {
            temp.push_back(s[j]);
        }
    }    
    //lowercase me kardo
    for(int j=0; j<temp.length(); j++) { 
        temp[j] = toLowerCase(temp[j]);
    }    
    //check palindrome
    return checkPalindrome(temp);
}
int main(){

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout<<s1<<" -> "<<isPalindrome(s1)<<endl;

    return 0;
}
*/

//                             Reverse Words in a String
/*
void reverse(string s){

    int start = 0;
    int p = 0;
    for (int i = 0; i <= s.length(); i++){
        if (s[p] == ' ' || s[p] == '\0'){
            int end = p - 1;
            while (start <= end){
                swap(s[start++],s[end--]);
            }
            start=p+1;
        }
        p++;
    }
    cout<<s;
}
int main(){

    string s;
    getline(cin, s);
    reverse(s);
}
*/

//                          Max Occurrence of a Character
/*
char getMaxOccCharacter(string s) {

    int arr[52] = {0};

    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        int number = 0;
        //Lowercase
        if(ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
        }
        //Uppercase
        else{
            number = ch - 'A' + 26;
        }
        arr[number]++;
    }
    //find maximum occ character
    int maxi = -1; 
    int ans = 0;
    for(int i=0;i<52; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    if(ans < 26){
        return 'a' + ans;
    }
    else{
        return 'A' + ans - 26;
    } 
}
int main(){

    string s;
    cin >> s;

    cout << getMaxOccCharacter(s) << endl;

    return 0;
}
*/

//                                     Replace Spaces
/*
string replaceSpaces(string &str){
	// Write your code here.
	string temp = "";
    
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            temp.push_back(str[i]);
        }
    }
	return temp;
}
int main() {

    // Example usage
    string input;
    
    // Get user input
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Call replaceSpaces to replace spaces with "@40"
    string result = replaceSpaces(input);
    
    // Output the result
    cout << "Modified string: " << result << endl;
    
    return 0;
}
*/

//                      Remove All Occurrences of a Substring
/*
string removeOccurrences(string s, string part) {

    while(s.length()!=0 && s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int main() {
    string s = "daabcbaabcbc";
    string part = "abc";
    
    cout << "Original string: " << s << endl;
    cout << "Modified string: " << removeOccurrences(s, part) << endl;
    
    return 0;
}
*/

//                              Permutation in String
/*
bool checkEqual(int a[26],int b[26]){
    for(int i=0;i<26;i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
bool checkInclusion(string s1, string s2) {
    
    //character count array    
    int count1[26]={0};
    for(int i=0;i<s1.length();i++){
        int index = s1[i]-'a';
        count1[index]++;
    }
    //traverse s2 string in window of size s1 length and compare
    int i=0;
    int windowSize=s1.length();
    int count2[26]={0};

    //running for first window
    while(i<windowSize && i<s2.length()){
        int index =s2[i]-'a';
        count2[index]++;
        i++;
    }
    if(checkEqual(count1,count2)){
        return 1;
    }
    //aage Window process karo
    while(i<s2.length()){
        char newChar =s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--; 

        if(checkEqual(count1,count2)){
            return 1; 
        }
        i++;
    }
    return 0;
}
int main() {

    string s1, s2;
    
    // Input strings
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;
    
    // Check if any permutation of s1 is a substring of s2
    if (checkInclusion(s1, s2)) {
        cout << "Yes, a permutation of s1 is a substring of s2!" << endl;
    } else {
        cout << "No, a permutation of s1 is not a substring of s2." << endl;
    }

    return 0;
}
*/

//                    Remove All Adjacent Duplicates In String
/*
string removeDuplicates(string s) {

    string temp = "";
    int i = 0;
    while (i < s.length()) {
        if (temp.empty() || s[i] != temp.back()) {
            temp.push_back(s[i]);
        } 
        else {
            temp.pop_back();
        }
        i++;
    }
    return temp;
}
int main() {

    string s = "abbaca";
    cout << "Original string: " << s << endl;
    cout << "String after removing duplicates: " << removeDuplicates(s) << endl;

    return 0;
}
*/

//                                  String Compression
/*
int compress(vector<char>& chars) {

    int i=0;
    int ansIndex=0;
    int n = chars.size();

    while(i<n){
        int j=i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }
        //yaha kab aaoge
        //ya toh vector poora traverse krdia
        //ya phir new character encounter kia hai

        //oldchar store karlo
        chars[ansIndex++]=chars[i];

        int count = j-i;
        if(count>1){
            //converting counting into single digit and saving in answer
            string cnt = to_string(count);
            for(char ch : cnt){
                chars[ansIndex++]=ch;
            }
        }
        //moving to new character
        i=j;
    }
    return ansIndex;
}
int main() {

    vector<char> chars1 = {'a', 'a', 'b', 'b', 'b', 'c', 'c'};
    vector<char> chars2 = {'a'};
    vector<char> chars3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};

    int length = compress(chars1);

    cout << "Compressed characters: ";
    for (int i = 0; i < length; i++) {
        cout << chars1[i];
    }
    cout << "\nLength of compressed string: " << length << endl;

    return 0;
}
*/
