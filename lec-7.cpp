#include <iostream>
#include<limits.h>
using namespace std;

//                                        Reverse Integer
/*
int reverse(int x) {
    int ans=0;
    while(x!=0){
        int digit=x%10;
        if((ans>INT_MAX/10)||(ans <INT_MIN/10)){
            return 0;
        }
        x=x/10;
        ans=(ans*10)+digit;
    }
    return ans;
}
int main() {
    int x1 = 123;
    int x2 = -123;
    int x3 = 1534236469;  // This should overflow
    int x4 = 0;           // Edge case

    cout << "Reversed " << x1 << ": " << reverse(x1) << endl;
    cout << "Reversed " << x2 << ": " << reverse(x2) << endl;
    cout << "Reversed " << x3 << ": " << reverse(x3) << endl;
    cout << "Reversed " << x4 << ": " << reverse(x4) << endl;

    return 0;
}
*/

//                             Complement of Base 10 Integer
/*
int bitwiseComplement(int n) {
    int m=n;
    int mask=0;
    if(n==0){
        return 1;
    }
    while(m!=0){
        mask = (mask<<1)|1;
        m=m>>1;
    }
    int ans = (~n) & mask;
    return ans;
}
int main() {

    cout << bitwiseComplement(5) << endl;  // Output: 2
    cout << bitwiseComplement(7) << endl;  // Output: 0
    cout << bitwiseComplement(0) << endl;  // Output: 1
    cout << bitwiseComplement(10) << endl; // Output: 5

    return 0;
}
*/

//                                       Power of 2
/*
bool isPowerOfTwoFirst(int n) {

    for(int i=0;i<=30;i++){
        int ans=pow(2,i);
        if(ans==n){
            return true;
        }
    }
    return false;
} 
bool isPowerOfTwo(int n) {
    if (n <= 0){
        return 0;
    }
    int count = 0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count == 1;
}
int main() {
    int n;

    cout<<"Enter the number : ";
    cin>>n;

    if(isPowerOfTwo(n)) {
        cout<<n<<" is a power of two!"<<endl;
    } else {
        cout<<n<<" is not a power of two!"<<endl;
    }

    return 0;
}
*/

