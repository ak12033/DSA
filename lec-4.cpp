#include <iostream>
using namespace std;

//                                          Pattern 3
/*
int main(){
    
        // 1 2 3 4
        // 1 2 3 4
        // 1 2 3 4
        // 1 2 3 4
    
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<j<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                     Pattern 4
/* 
int main(){

        // 4 4 4 4
        // 3 3 3 3
        // 2 2 2 2
        // 1 1 1 1
    
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<n-i+1<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                        Pattern 5
/*
int main(){

        // 4 3 2 1
        // 4 3 2 1
        // 4 3 2 1
        // 4 3 2 1

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<n-j+1<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                       Pattern 6
/*
int main(){

        // 1 2 3 4
        // 5 6 7 8
        // 9 10 11 12
        // 13 14 15 16

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    int count=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<count<<" ";
            count=count+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 7
/*
int main(){

        // *
        // * *
        // * * *
        // * * * *

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                     Pattern 8
/*
int main(){

        // 1
        // 2 2
        // 3 3 3
        // 4 4 4 4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                       Pattern 9
/*
int main(){

        // 1
        // 1 2
        // 1 2 3
        // 1 2 3 4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                        Pattern 10
/*
int main(){

        // 1
        // 2 3
        // 4 5 6
        // 7 8 9 10

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    int count=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<count<<" ";
            count=count+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                     Pattern 11
/*
int main(){

        // 1
        // 2 3
        // 3 4 5
        // 4 5 6 7

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        int count = i;
        while(j<=i){
            cout<<count<<" ";
            count = count + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 12
/*
int main(){

        // 1
        // 2 1
        // 3 2 1
        // 4 3 2 1

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        int count = i;
        while(j<=i){
            cout<<count<<" ";
            count = count-1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                        Pattern 13
/*
int main(){

        // A A A
        // B B B
        // C C C

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 64 + i;
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                     Pattern 14
/*
int main(){

        // A B C
        // A B C
        // A B C

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 64+j;
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 15
/*
int main(){

        // A B C
        // D E F
        // G H I

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    char ch = 65;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<ch<<" ";
            j=j+1;
            ch = ch + 1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 16
/*
int main(){

        // A B C
        // B C D
        // C D E

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        char ch = 64 + i;
        int j=1;
        while(j<=n){
            cout<<ch<<" ";
            ch = ch + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 17
/*
int main(){
    
        // A
        // B B
        // C C C

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        char ch = 64 + i;
        while(j<=i){
            cout<<ch<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 18
/*
int main(){

        // A
        // B C
        // D E F
        // G H I J

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    char ch = 65;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<ch<<" ";
            ch=ch+1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 19
/*
int main(){

        // A
        // B C
        // C D E
        // D E F G

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        char ch = 64 + i;
        while(j<=i){
            cout<<ch<<" ";
            ch = ch + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 20
/*
int main(){

        // D
        // C D
        // B C D
        // A B C D

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        char ch = n + 64 - i + 1;
        while(j<=i){
            cout<<ch<<" ";
            ch = ch + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 21
/*
int main(){

        //       *
        //     * *
        //   * * *
        // * * * *

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space = n-i;
        while(space){
            cout<<"  ";
            space = space-1;
        }
        int j=1;
        while(j<=i){
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 22
/*
int main(){

        //       *
        //     * * *
        //   * * * * *
        // * * * * * * *

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=n-i;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        int j=1;
        while(j<i*2){
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 23
/*
int main(){

        // * * * * 
        // * * * 
        // * * 
        // * 

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 24
/*
int main(){

        // * * * *
        //   * * *
        //     * *
        //       *
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=i-1;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        int j=1;
        while(j<=n-i+1){
            cout<<"*"<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 25
/*
int main(){

        // 1 1 1 1
        //   2 2 2
        //     3 3
        //       4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=i-1;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        int j=1;
        while(j<=n-i+1){
            cout<<i<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 26
/*
int main(){

    //         1
    //       2 2
    //     3 3 3
    //   4 4 4 4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=n-i;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        int j=1;
        while(j<=i){
            cout<<i<<" ";
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 27
/*
int main(){

        // 1 2 3 4
        //   2 3 4
        //     3 4
        //       4

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=i-1;
        while(space){
            cout<<"  ";
            space=space-1;
        }
        int count = i;
        int j=1;
        while(j<=n-i+1){
            cout<<count<<" ";
            count = count + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }   
}
*/

//                                      Pattern 28
/*
int main(){

        //       1
        //     2 3
        //   4 5 6
        // 7 8 9 10
    
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    int count = 1;
    while(i<=n){
        int space=n-i;
        while(space){
            cout<<"  ";
            space = space-1;
        }
        
        int j=1;
        while(j<=i){
            cout<<count<<" ";
            count = count + 1;
            j=j+1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 29
/*
int main(){

        //       1
        //     1 2 1
        //   1 2 3 2 1
        // 1 2 3 4 3 2 1 
    
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int space=n-i;
        while(space){
            cout<<"  ";
            space = space-1;
        }
        
        int j=1;
        while(j<=i){
            cout<<j<<" ";
            j=j+1;
        }
        int k = i-1;
        while(k){
            cout<<k<<" ";
            k = k - 1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

//                                      Pattern 30
/*
int main(){

        // 1 2 3 4 5 5 4 3 2 1
        // 1 2 3 4 * * 4 3 2 1
        // 1 2 3 * * * * 3 2 1
        // 1 2 * * * * * * 2 1
        // 1 * * * * * * * * 1

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        int value=n-i+1;
        while(j<=value){
            cout<<j<<" ";
            j=j+1;
        }
        int star=2*(i-1);
        while(star){
            cout<<"*"<<" ";
            star=star-1;
        }
        int count=n-i+1;
        while(count){
            cout<<count<<" ";
            count=count-1;
        }
        cout<<endl;
        i=i+1;
    }
}
*/

   
    
