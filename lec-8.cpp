#include<iostream>
using namespace std;

/*
int main(){
*/
        /*
        char ch='1';
        int num = 1;

        cout << endl;

        switch(ch){

                case 1: cout<<"First"<< endl;
                        cout<<"First again"<<endl;
                        break;
                case '1':   cout<<"character one"<< endl;
                        break;
                default: cout<<"it is default case"<<endl;

        }
        cout<<endl;
        */

//                                 Switch Case In Infinite Loop
/*
        int num = 2;
        while(1) {
                switch(num) {
                case 1 : cout<<"First"<<endl;
                        break;
                
                case 2 :
                        cout<<"Second"<<endl;
                        exit(0);
                        break;
                
                default :
                        cout<<"Default case"<<endl;
                }
        }
        return 0;
*/

//                                          Calculator
/*
        int a, b;

        cout <<" Enter the value of a "<<endl;
        cin >> a;

        cout<<" Enter the value of b " <<endl;
        cin >> b;

        char op;
        cout<<" Enter the Operation you want to perform" <<endl;
        cin >> op;

        switch( op ) {

                case '+':  cout << (a+b) <<endl; 
                        break;

                case '-': cout<< (a-b) <<endl;
                        break;  

                case '*': cout<< (a*b) <<endl;
                        break;

                case '/': cout<< (a/b) <<endl;
                        break;

                case '%': cout<< (a%b) <<endl;
                        break;

                default: cout << "Please enter a valid Operation " << endl;

        }
*/

//                           Currency Notes Distribution
/*
        int amount;
        cout<<"Enter the amount"<<endl;
        cin>>amount;
        int Rs100 , Rs50 , Rs20 , Rs1;

        switch(1){
                case 1: Rs100=amount/100;
                        amount=amount%100;
                        cout<<"No of 100 Rupee notes required are="<<Rs100<<endl;
                
                
                case 2: Rs50=amount/50;
                        amount=amount%50;
                        cout<<"No of 50 Rupee notes required are="<<Rs50<<endl;
                

                case 3: Rs20=amount/20;
                        amount=amount%20;
                        cout<<"No of 20 Rupee notes required are="<<Rs20<<endl;
                

                case 4: Rs1=amount/1;
                        amount=amount%1;
                        cout<<"No of 1 Rupee notes required are="<<Rs1<<endl; 
        }
*/

//                                Power of a raise to the power b
/*
    int a,b;
    cin>> a >> b;
    int ans=1;
    for(int i=1;i<=b;i++){
        ans=ans*a;
    }
    cout<<"answer is"<<ans<<endl;
*/
/*
}
*/

//                                   Even or Odd function
/*
//1 -> Even
// 0 -> odd
bool isEven(int a) {
    //odd
    if(a&1) {
        return 0;
    }
    else { //Even
        return 1;
    }

}

int main() {
    
    int num;
    cin >> num;

    if(isEven(num)) {
        cout <<" Number is Even" <<endl;
    }
    else {
        cout<< " Number is Odd" <<endl;
    }


    return 0;
}
*/

//                                       Power function
/*
int power() {

    int a,b;
    cout<<"enter the number ";
    cin>>a;
    cout<<"enter the power ";
    cin>>b;

    int ans = 1;

    for(int i = 1; i <= b; i++) {
        ans = ans * a;
    }
    return ans;
}
int main()
{

    int answer = power();
    cout << "answer is " << answer << endl;

    return 0;
}
*/

//                                       nCr Program
/*
int factorial(int n) {

    int fact = 1;

    for(int i = 1; i<=n; i++ ) {
        fact = fact * i;
    }

    return fact;
}

int nCr(int n, int r) {

    int num = factorial(n);

    int denom = factorial(r) * factorial(n-r);

    return num/denom;
}


int main( ) {

    int n, r;

    cin>> n >> r ;

    cout <<" Answer is " << nCr(n,r) << endl;

    return 0;
}
*/

//                                   Counting function
/*
void printCounting(int num) {

    for(int i=1; i<=num; i++) {
        cout<< i << " ";
    }
    cout<<endl;
}

int main() {

    int n;
    cin >> n;

    //function Call
    printCounting(n);


    return 0;
}
*/

//                                      Prime number or not
// 0 -> Not a Prime no.
// 1 -> Prime no.

/*
bool isPrime(int n ) {
    for(int i = 2; i < n; i++){
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
   
   int n ;
   cin >> n;
   if(isPrime(n)) {
        cout <<" is a Prime number " <<endl;
   }
   else{
       cout<< "Not a prime number "<<endl;

   }
}
*/

//AP
/*
int AP(int n){

    int ap=3*n+7;
    return ap;
}

int main(){

    int n;
    cin>>n;
    int ans=AP(n);
    cout<<"Answer is="<<ans<<endl;

    return 0;
}
*/

/*
int setBits(int n){
    int count = 0;
    while(n!=0){
        if(n&1){
            count++;
        }
        n=n>>1;
    }
    return count; 
}
int main(){

    int a,b;
    cin>>a>>b;
    int ans1=setBits(a);
    int ans2=setBits(b);
    cout<<"Set bits of A="<<ans1<<endl;
    cout<<"Set bits of B="<<ans2<<endl;
    int ans=ans1+ans2;

    cout<<"Total set bits of A and B are ="<<ans<<endl;

    return 0;
}
*/

//fibonacci
/*
int fibonacci(int n){
    int a = 0;
    int b = 1;
    if(n==1){
        return a;
    }
    for (int i = 2; i < n; i++)
    {
        int next = a + b;
        a = b;
        b = next;
    } 
    return b;
}

int main(){

    int n;
    cin >> n;
    
    cout << "The " <<n<<"th term of the series is = "<< fibonacci(n) << endl;

    return 0;
}
*/

//                                  Pass by Value
/*
void dummy(int n) {

    n++;
    cout << " n is " << n <<endl;

}
int main() {

    int n;
    cin >> n;

    dummy(n);

    cout<<"number n is "<< n << endl;

    return 0;
}
*/

//                                      Checking Output
/*
void update(int a){
    a=a/2;
}
int main(){
    int a=10;
    update(a);
    cout<<a<<endl;
}
*/

/*
int update(int a){
    a-=5;
    return a ;
}
int main(){
    int a=15;
    update(a);
    cout<<a<<endl;
}
*/

/*
int update(int a){
    int ans=a*a;
    return ans ;
}
int main(){
    int a=14;
    a=update(a);
    cout<<a<<endl;
}
*/