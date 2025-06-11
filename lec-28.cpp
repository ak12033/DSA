#include<iostream>
using namespace std;

//                              Reference Variable
/*
int main() {

    int i = 5;
    // Creating a reference variable 

    int& j = i;
    cout << i << endl; 
    i++;
    cout << i << endl; 
    j++;
    cout << i << endl; 
    cout << j << endl;

    return 0;
}
*/

//                                  Pass by Value
/*
void update1(int n) {
    n++;
}
int main() {

    int n = 5;
    
    cout << "Before " << n << endl;
    update1(n);
    cout << "After " << n << endl;

    return 0;
}
*/

//                                  Pass by Reference
/*
void update2(int& n) {
    n++;
}
int main() {

    int n = 5;
   
    cout << "Before " << n << endl;
    update2(n);
    cout << "After " << n << endl;

    return 0;
}
*/

//                                    Bad Practice
/*
int& func(int a) {

    int num = a;
    int& ans = num;
    return ans;
}
int main() {

    int n = 5;
    func(n);

    return 0;
}
*/

/*
int* fun(int n) {

    int* ptr = &n;
    return ptr;
}
int main() {

    int n = 5;
    fun(n);

    return 0;
}
*/

// Stack - Static Memory Allocation
// Heap - Dynamic Memory Allocation
// new int - returns an address
// int* i = new int; -> pointer which stores address

/*
int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}
int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << "answer is "<< ans << endl;

    return 0;
}
*/

/*
int main(){

    // Case 1 - stack memory free every second automatically
    // while(true) {
    //     int i = 5;
    // }

    // Case 2 - stack memory freed but not dynamic memory
    while(true) {
        int* ptr = new int;
        delete ptr;
    }
    
    return 0;
}
*/