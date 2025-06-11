#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//                                           Array
/*
int main() {

    int basic[3] = {1, 2, 3};

    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for(int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"Size of array = "<<a.size()<<endl;

    cout<<"Element at second index = "<<a.at(2)<<endl;

    cout<<"Empty or not = "<<a.empty()<<endl;

    cout<<"First element = "<<a.front()<<endl;
    cout<<"Last element = "<<a.back()<<endl;

    return 0;
}
*/

//                                              Vector
/*
int main() {

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    int size = v.size();

    for(int i=0; i<size; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"Size of vector = "<<v.size()<<endl;
    cout<<"Capacity of vector = "<<v.capacity()<<endl;

    cout<<"Element at second index = "<<v.at(2)<<endl;

    cout<<"Empty or not = "<<v.empty()<<endl;

    cout<<"First element = "<<v.front()<<endl;
    cout<<"Last element = "<<v.back()<<endl;

    cout<<"\nBefore pop operation : ";
    for(int i:v) {
        cout<<i<<" ";
    }

    v.pop_back();
    
    cout<<"\nAfter pop operation : ";
    for(int i:v) {
        cout<<i<<" ";
    }

    cout<<"\n\nBefore clear operation : Size = "<<v.size()<<endl;

    v.clear();

    cout<<"After clear operation : Size = "<<v.size()<<endl;

    vector<int> v1(5, 1);
    cout<<"\nPrinting new vector : ";
    for(int i:v1) {
        cout<<i<<" ";
    }

    return 0;
}
*/

//                                          Deque
/*
int main() {

    deque<int> d;

    d.push_back(1);
    d.push_back(2);

    d.push_front(3);
    d.push_front(4);

    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    // d.pop_back() ;

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // d.pop_front();

    // for(int i:d) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    cout<<"Size of deque = "<<d.size()<<endl;

    cout<<"Element at second index = "<<d.at(2)<<endl;

    cout<<"First element = "<<d.front()<<endl;
    cout<<"Last element = "<<d.back()<<endl;

    cout<<"Empty or not : "<<d.empty()<<endl;

    d.erase(d.begin(), d.begin()+1);
    
    for(int i:d) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
*/

//                                         List
/*
int main() {

    list<int> l;

    l.push_back(1);
    l.push_back(2);

    l.push_front(3);
    l.push_front(4);

    int size = l.size();

    for(int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    l.erase(l.begin());

    cout<<"After erase operation : ";
    for(int i:l) {
        cout<<i<<" ";
    }
    cout<<endl;

    // l.pop_back() ;

    // for(int i:l) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    // l.pop_front();

    // for(int i:l) {
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    cout<<"Size of list = "<<l.size()<<endl;

    // Copying list content
    list<int> l1(l);

    cout<<"New list : ";
    for(int i:l1) {
        cout<<i<<" ";
    }
    cout<<endl;

    // Initialising new list
    list<int> l2(10, 20);

    cout<<"Newly initialised list : ";
    for(int i:l2) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
*/

//                                      Stack
/*
int main() {

    stack<string> s;

    s.push("Raj");
    s.push("Singh");

    cout<<"First element : "<<s.top()<<endl;

    s.pop();

    cout<<"First element after pop : "<<s.top()<<endl;

    cout<<"Size of stack : "<<s.size()<<endl;
    cout<<"Empty or not : "<<s.empty()<<endl;

    return 0;
}
*/

//                                      Queue
/*
int main() {

    queue<string> q;

    q.push("Raj");
    q.push("Singh");
    q.push("Kumar");

    cout<<"Size before pop "<<q.size()<<endl;

    cout<<"First element "<<q.front()<<endl;
    q.pop();
    cout<<"First element after pop "<<q.front()<<endl;

    cout<<"Size after pop "<<q.size()<<endl;

    return 0;
}
*/

//                                 Priority Queue
/*
int main() {

    // Max heap
    priority_queue<int> maxi;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;

    cout<<"Empty or not "<<maxi.empty()<<endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int> > mini;

    mini.push(5);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for(int i=0; i<m; i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    cout<<"Empty or not "<<mini.empty()<<endl;

    return 0;
}
*/

//                                       Set
/*
int main(){

    set<int> s;
    
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    cout<<"set elements are : ";
    for (auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    cout<<"after erasing, set elements are : ";
    for (auto i : s) {
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"5 is present in set or not : ";
    cout<<s.count(5)<<endl;

    cout<<"-5 is present in set or not : ";
    cout<<s.count(-5)<<endl;

    set<int>::iterator itr = s.find(5);

    for (auto it=itr; it!=s.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;

    return 0;
}
*/

//                                       Map
/*
int main() {

    map<int, string> m;

    m[1] = "krishna";
    m[13] = "arjun";
    m[2] = "nakul";

    m.insert({5,"bheem"});

    cout<<"before erase map elements are : "<<endl;
    for (auto i : m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"finding 13 -> "<<m.count(13)<<endl;
    cout<<"finding -13 -> "<<m.count(-13)<<endl;

    // m.erase(13);

    cout<<"after erase map elements are : "<<endl;
    for (auto i : m) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    auto it = m.find(5);

    for (auto i=it; i!=m.end(); i++) {
        cout<<(*i).first<<" ";
    }
    cout<<endl;

    return 0;
}
*/

//                                      Algorithm
/*
int main(){

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"finding 6 --> "<<binary_search(v.begin(), v.end(), 6)<<endl;
    cout<<"finding 1 --> "<<binary_search(v.begin(), v.end(), 1)<<endl;

    // It returns an iterator pointing to the first element not less than the given value.
    cout<<"lower bound : "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"lower bound : "<<lower_bound(v.begin(), v.end(), 4) - v.begin()<<endl; 

    // It returns an iterator pointing to the first element greater than the given value.
    cout<<"upper bound : "<<upper_bound(v.begin(), v.end(), 6) - v.begin()<<endl; 
    cout<<"upper bound : "<<upper_bound(v.begin(), v.end(), 4) - v.begin()<<endl; 

    int a = 3;
    int b = 5;

    cout<<"max -> "<<max(a, b)<<endl;
    cout<<"mini -> "<<min(a, b)<<endl;

    swap(a, b);

    cout<<"a -> "<<a<<" b -> "<<b<<endl;

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout<<"string ->"<<s<<endl;

    cout<<"before rotate vector v elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    rotate(v.begin(), v.begin()+1, v.end());

    cout<<"after rotate vector v elements are : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());
    cout<<"after sorting : ";
    for (int i:v) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}
*/