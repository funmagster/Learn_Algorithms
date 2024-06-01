#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(){
    string s;
    vector<int> a(26, 0);

    getline(cin, s);
    for (char c: s){
        a[c - 'a']++;
    }
    for (int i = 0; i < 26; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}