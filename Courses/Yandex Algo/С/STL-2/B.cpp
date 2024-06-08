#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string a, b;
    cin >> n;
    map<string, string> dict;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        dict[a] = b;
        dict[b] = a;
    }
    cin >> a;
    cout << dict[a];
    return 0;
}