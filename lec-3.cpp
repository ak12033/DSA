#include <iostream>
using namespace std;

//                             Check Positive or Negative or Zero
/*
int main() {
    int n;
    cout<<"Enter the value of number : ";
    cin>>n;

    if(n<0) {
        cout<<"number is negative !"<<endl;
    } else if(n>0) {
        cout<<"number is positive !"<<endl;
    } else {
        cout<<"number is zero !"<<endl;
    }
}
*/

//                                 Greater of Two Numbers
/*
int main() {
    int a, b;

    cout<<"Enter the value of a : ";
    cin>>a;

    cout<<"Enter the value of b : ";
    cin>>b;

    if(a>b) {
        cout<<"a is greater"<<endl;
    } else {
        cout<<"b is greater"<<endl;
    }
}
*/

//                                     Checking output
/*
int main(){
    int a = 9;
    if(a==9){
        cout<<"NINEY";
    }
    if(a>0){
        cout<<"POSITIVE";
    }
    else{
        cout<<"NEGATIVE";
    }
}
*/

/*
int main(){
    int a = 2;
    int b = a+1;
    if(a==9){
        cout<<"NINEY";
    }
    if((a=3)==b){
        cout<<a;
    }
    else{
        cout<<a+1;
    }
}
*/

/*
int main(){
    int a = 24;
    if(a>20){
        cout<<"LOVE ";
    }
    else if(a==24){
        cout<<"LOVELY";
    }
    else{
        cout<<"BABBAR";
    }
    cout<<a;
}
*/

//                           Lowercase or Uppercase or Number
/*
int main() {
    char ch;

    cout<<"Enter the character : ";
    cin>>ch;

    if(ch>='A' && ch<='Z') {
        cout<<"Uppercase Character !"<<endl;
    } 
    else if(ch>='a' && ch<='z') {
        cout<<"Lowercase Character !"<<endl;
    } 
    else if(ch>= '0' && ch<= '9') {
        cout<<"Numeric Character !"<<endl;
    }
    else {
        cout<<"not a valid character !"<<endl;
    }
}
*/

//                                        Counting Numbers
/*
int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 1;

    while(i <= n) {
        cout<<i<<" ";
        i = i+1;
    }
}
*/

//                                Sum of Numbers 1 to N
/*
int main() {
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 1;
    int sum = 0;

    while(i <= n) {
        sum = sum + i;
        i = i + 1;
    }

    cout<<"Sum of n numbers = "<<sum<<endl;
}
*/

//                              Sum of Even Numbers 1 to N
/*
int main() {
    int n;

    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 2;
    int sum = 0;

    while(i <= n) {
        sum = sum + i;
        i = i + 2;
    }

    cout<<"Sum of even numbers upto n = "<<sum<<endl;
}
*/

//                                    Fahrenheit to Celsius
/*
int main() {
    float f;

    cout<<"Enter the temperature in fahrenheit : ";
    cin>>f;

    float c = ((f-32) * 5) / 9;

    cout<<"Temperature in celsius : "<<c<<endl;
}
*/

//                                    Celsius to Fahrenheit
/*
int main() {
    float c;

    cout<<"Enter the temperature in celsius : ";
    cin>>c;

    float f = ((c*9)/5) + 32;

    cout<<"Temperature in fahrenheit : "<<f<<endl;
}
*/

//                                     Pattern 1
/*
int main() {
    
        // * * * *
        // * * * *
        // * * * *
        // * * * *

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 1;
    while(i <= n) {
        int j = 1;
        while(j<=n) {
            cout<<"* ";
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;
    }
}
*/

//                                      Pattern 2
/*
int main() {

        // 1 1 1 1
        // 2 2 2 2
        // 3 3 3 3
        // 4 4 4 4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i = 1;
    while(i <= n) {
        int j = 1;
        while(j<=n) {
            cout<<i<<" ";
            j = j + 1;
        }
        cout<<endl;
        i = i + 1;
    }
}
*/