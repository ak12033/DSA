#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

//                                      Unordered Map
/*
int main() {

    // Creation
    unordered_map <string, int> m;

    // Insertion

    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // Updation
    m["mera"] = 2;

    // Search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // Will give an error
    // cout << m.at("unknownKey") << endl;
    
    // To avoid error
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;

    // Size
    cout << m.size() << endl;

    // To check presence
    cout << m.count("love") << endl;

    // Erase
    m.erase("love");
    cout << m.size() << endl;

    // Traversing a map

    // 1
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    // 2 using iterator
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
*/

//                                          Map
/*
int main() {

    // Creation
    map<string, int> m;

    // Insertion

    // 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // 3
    m["mera"] = 1;

    // Updation
    m["mera"] = 2;

    // Search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;

    // Will give an error
    // cout << m.at("unknownKey") << endl;
    
    // To avoid error
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;

    // Size
    cout << m.size() << endl;

    // To check presence
    cout << m.count("love") << endl;

    // Erase
    m.erase("love");
    cout << m.size() << endl;

    // Traversing a map

    // 1
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    // 2 using iterator
    map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}
*/

//                              Maximum Frequency Number
/*
int maximumFrequency(vector<int>& arr, int n) {

    unordered_map<int, int> count;

    int maxFreq = 0;
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<n; i++) {
        if(maxFreq == count[arr[i]]) {
            return arr[i];
        }
    }
}
int main() {

    vector<int> arr = {1, 2, 3, 1, 2};
    cout << maximumFrequency(arr, arr.size()) << endl;

    return 0;
}
*/