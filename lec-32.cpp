#include<iostream> 
using namespace std;

/*
void reachHome(int src, int dest) {
    
    cout << "source " << src  << " destination " << dest << endl;
    // Base Case
    if(src == dest) {
        cout << " pahuch gya " << endl;
        return ;
    }

    // Processing - ek step aage badhjao
    // src++;
    // Recursive Call
    // reachHome(src, dest);

    // Recursive Call
    reachHome(src+1, dest);
}
int main() {

    int dest = 10;
    int src = 1;
    cout << endl;

    reachHome(src, dest);

    return 0;
}
*/

//                                 Fibonacci Number
/*
int fib(int n) {

    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int ans = fib(n-1) + fib(n-2);
    return ans;
}
int main() {

    int n;
    cout<<"Enter a nth term to find its fibonacci value : ";
    cin>>n;

    cout<<"The number is : "<<fib(n)<<endl;

    return 0;
}
*/

//                          Count Ways To Reach The N-th Stairs
/*
int countDistinctWayToClimbStair(long long nStairs){

    // Base Case
    if(nStairs < 0){
        return 0;
    }
    if(nStairs == 0){
        return 1;
    }
    
    // Recursive Call
    int ans = countDistinctWayToClimbStair(nStairs-1) + countDistinctWayToClimbStair(nStairs-2);
    
    return ans;
}
int main() {

    long long nStairs;
    cout << "Enter number of stairs: ";
    cin >> nStairs;

    int result = countDistinctWayToClimbStair(nStairs);
    cout << "Number of distinct ways to climb " << nStairs << " stairs is: " << result << endl;

    return 0;
}
*/

//                                      Say Digits
/*
void sayDigit(int n, string arr[]) {

    // Base Case
    if(n == 0){
        return ;
    }

    // Processing 
    int digit = n % 10;
    n = n / 10;

    // Recursive Call
    sayDigit(n, arr);
    cout << arr[digit] << " ";
}
int main() {

    string arr[10] = {"zero", "one", "two", "three", "four",
                    "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;

    sayDigit(n, arr);
    cout << endl;

    return 0;
}
*/
