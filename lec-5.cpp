#include <iostream>
using namespace std;

/*
int main(){
*/
    /*
    int a = 4;
    int b = 6;

    cout<<" a&b "<<(a&b)<< endl;
    cout<<" a|b "<<(a|b)<< endl;
    cout<<" ~a "<<(~a)<< endl;
    cout<<" a^b "<<(a^b)<< endl;

    cout << (17>>1)<<endl;
    cout << (17>>2)<<endl;
    cout << (19<<1)<<endl;
    cout << (21<<2)<<endl;

    int i=7;
    cout << (++i)<<endl;
    cout << (i++)<<endl;
    cout << (i--)<<endl;
    cout << (--i)<<endl;
    */

//                                       Checking output
    /*
    int a,b=1;
    a=10;
    if(++a){
        cout<<b;
    }
    else{
        cout<<++b;
    }
    */

    /*
    int a=1;
    int b=2;
    if(a-- > 0 && ++b > 2){
        cout<<"Stage1 - Inside If ";
    }
    else{
        cout<< " Stage2 - Inside else ";
    }
    cout << a << " " << b << endl;
    */

    /*
    int a=1;
    int b=2;
    if(a-- > 0 || ++b > 2){
        cout<<"Stage1 - Inside If ";
    }
    else{
        cout<< " Stage2 - Inside else ";
    }
    cout << a << " " << b << endl;
    */

    /*
    int number = 3;
    cout << (25 * (++number));
    */

    /*
    int a = 1;
    int b = a++;
    int c = ++a;
    cout << b;
    cout << c;
    */
    
//                                        for loop
    /*
    int n;
    cout<< "enter the value Of n" <<endl;
    cin>>n;
    cout<<"printing count from 1 to n" << endl;
    for(int i=1;i<=n;i++){
        cout<< i << endl;
    }
    */

    /*
    int n;
    cout<< "enter the value Of n" <<endl;
    cin>>n;
    cout<<"printing count from 1 to n" << endl;
    int i=1;
    for(;;){
        if(i<=n){
            cout<< i << endl;
        }
        else{
            break;
        }
        i++;
    }
    */

    /*
    for(int a=0,b=1,c=2;a>=0 && b>=1 && c>=2; a--,b--,c--){
        cout<<a <<" "<<b << " "<<c << endl;
    }
    */

    /*
    int n;
    cout<< "enter the value Of n" <<endl;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<< sum << endl;
    */

//                                     Fibonacci series
    /*int n;
    cout<< "enter the value Of n" <<endl;
    cin>>n;
    int a=0;
    int b=1;
    cout<<a <<" "<<b<<" ";
    for(int i=1;i<=n;i++){
        int nextnumber=a+b;
        cout<<nextnumber<<" ";
        a=b;
        b=nextnumber;
    }
    */

//                                         Prime number
    /*
    int n;
    cout<< "enter the value Of n" <<endl;
    cin>>n;
    bool isPrime =1;
    for(int i=2;i<n;i++){
        if(n%i==0){
            isPrime=0;
            break;
        }
    }
    if(isPrime==0){
        cout<<"Not a prime number"<<endl;
    }
    else{
        cout<<"is a prime number"<<endl;
    }*/

//                                        Break statement
    /*
    for (int i=0;i<5;i++){
        cout<< "hi" << endl;
        cout<< "hey" << endl;
        break;
        cout<< "hi" << endl;
    }
    */

//                                       Continue statement
    /*
    for (int i=0;i<5;i++){
        cout<< "hi" << endl;
        cout<< "hey" << endl;
        continue;
        cout<< "hi" << endl;
    }
    */

//                                         Checking output
    /*
    for (int i=0;i<=5;i++){
        cout<< i << " ";
        i++;
    }
    */

    /*
    for (int i=0;i<=5;i--){
        cout<< i << " ";
        i++;
    }
    */

    /*
    for (int i=0;i<=15;i+=2){
        cout<< i << " ";
        if(i&1){
            continue;
        }
        i++;
    }
    */

    /*
    for (int i=0;i<=5;i++){
        for (int j=i;j<=5;j++){
            cout<< i << " "<< j<<endl;
        }
    }
    */

    /*
    for (int i=0;i<5;i++){
        for (int j=i;j<=5;j++){
            if(i+j==10){
                break;
            }
            cout<< i << " "<< j<<endl;
        }
    }
    */
/*
}
*/

//                  Subtract the Product and Sum of Digits of an Integer
/*
int subtractProductAndSum(int n) {
    int prod=1;
    int sum=0;
    while(n!=0){
        int digit=n%10;
        prod=prod*digit;
        sum+=digit;
        n=n/10;
    }
    int answer=prod-sum;
    return answer;
        
}
int main() {
    // Test cases to check the function
    int n1 = 234;
    int n2 = 4421;

    cout << "Result for n = " << n1 << " : " << subtractProductAndSum(n1) << endl;
    cout << "Result for n = " << n2 << " : " << subtractProductAndSum(n2) << endl;

    // You can add more test cases as needed
    return 0;
}
*/

//                                   Number of 1 Bits
/*
int hammingWeight(int n) {
    int count=0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count;
}
int main() {
    int n1 = 11;  // Binary: 1011
    int n2 = 8;   // Binary: 1000
    int n3 = 31;  // Binary: 11111

    cout << "Hamming Weight of " << n1 << " is: " << hammingWeight(n1) << endl;
    cout << "Hamming Weight of " << n2 << " is: " << hammingWeight(n2) << endl;
    cout << "Hamming Weight of " << n3 << " is: " << hammingWeight(n3) << endl;

    return 0;
}
*/
