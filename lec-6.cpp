#include <iostream>
#include<math.h>
using namespace std;
int main(){
//                                         Deimal to Binary
    /*
    int n;
    cin>> n;
    int ans = 0;
    int i = 0;
    while(n != 0 ){
        int bit = (n & 1);
        ans = (bit*pow(10, i) )+ans;
        n= n >> 1;
        i++;
    }
    cout<<"Answer is "<< ans <<endl;
    */
    

//                                     Reversing the number
    /*
    int n;
    cin>> n;
    int ans=0;
    while(n!=0){
        int digit=n%10;
        n=n/10;
        ans=(ans*10)+digit;
    }
    cout<<ans;
    */
    
//                                      Binary to Decimal
    /*
    int n;
    cin>>n;
    int ans=0,i=0;
    while(n!=0){
        int bit=n%10;
        if(bit==1){
            ans=ans+(pow(2,i));
        }
        n=n/10;
        i++;
    }
    cout<<ans<<endl;
    */
}