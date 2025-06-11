#include<iostream> 
using namespace std;

//                                        Factorial
/*
int factorial(int n) {
    
    // Base case
    if(n==0)
        return 1;

    // int SmallerProblem = factorial(n-1);   
    // int BiggerProblem = n * SmallerProblem;
    // return BiggerProblem;

    return n * factorial(n-1);
}
int main() {

    int n;
    cin >> n;

    int ans = factorial(n);
    cout << ans << endl;

    return 0;
}
*/

//                                       Power of 2
/*
int power(int n) {

    // Base Case 
    if(n == 0)
        return 1;

    // Recursive relation
    // int SmallerProblem = factorial(n-1);   
    // int BiggerProblem = n * SmallerProblem;
    // return BiggerProblem;

    return 2 * power(n-1);    
}
int main() {

    int n;
    cin >> n;

    int ans = power(n);
    cout << ans << endl;

    return 0;
}
*/

//                              Printing 1 to n in reverse order
/*
void print(int n) {

    // Base Case 
    if(n == 0)
        return ;

    // Recursive Relation
    cout << n << endl;
    print(n-1);
}
int main() {

    int n;
    cin >> n;
    cout << endl;
    print(n);

    return 0;
}
*/

//                          Printing 1 to n without using loop
/*
void print(int n) {

    // Base Case 
    if(n == 0)
        return ;

    // Recursive Relation
    print(n-1);
    cout << n << endl;
}
int main() {

    int n;
    cin >> n;
    cout << endl;

    print(n);

    return 0;
}
*/