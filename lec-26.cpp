#include<iostream>
using namespace std;

//                                More about Pointers
/*
int main () {

    int arr[10] = {23, 122, 41, 67};

    cout <<" address of first memory block is " << arr << endl;
    cout << arr[0] << endl;
    cout <<" address of first memory block is " << &arr[0] << endl;

    cout << "4th " << *arr << endl;
    cout << "5th " << *arr + 1 << endl;
    cout << "6th " << *(arr + 1) << endl;
    cout << "7th " << *(arr) + 1 << endl;

    // Formula -> arr[i] = *(arr + i) or i[arr] = *(i + arr)
    cout << "8th " << arr[2] << endl;
    cout << "9th " << *(arr+2) << endl;

    int i = 3;
    cout << i[arr] << endl;

    return 0;
}
*/

/*
int main(){

    int temp[10] = {1,2};
    cout << sizeof(temp) << endl;
    cout << "1st " <<  sizeof(*temp) << endl;
    cout << "2nd " <<  sizeof(&temp) << endl;

    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl ;
    cout << sizeof(*ptr) << endl ;
    cout << sizeof(&ptr) << endl ;

    return 0;
}
*/

/*
int main(){

    int a[20] = {1,2,3,5};
    //cout << " ->" << &a[0] << endl;
    // cout << &a << endl;
    //cout << a << endl;

    int *p = &a[0];
    //cout << p << endl;
    //cout << *p << endl;
    cout << "-> " << &p << endl;

    return 0;
}
*/

/*
int main(){

    int arr[10];

    //ERROR
    //arr = arr+1;

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;

    return  0;
}
*/

/*
int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout << arr << endl;
    //attention here
    cout << ch << endl;
    
    char *c = &ch[0];
    // Prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;

    return 0;
}
*/

//                                 Pointers in Functions
/*
void print(int *p) {

    cout << *p << endl; 

}
void update(int *p) {

    // p = p + 1;
    // cout << "inside "<< p <<endl;
    *p = *p + 1;

}
int main() {

    int value = 5;
    int *p = &value;

    // print(p);
    cout <<" Before " << *p << endl;
    update(p);
    cout <<" After " << *p << endl;

    return 0;
}
*/

/*
int getSum(int *arr, int n) {

    cout << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {

    int arr[6] = {1,2,3,4,5,8};

    cout << "Sum is " << getSum(arr+3 ,3) << endl ;  

    return 0;
}
*/
