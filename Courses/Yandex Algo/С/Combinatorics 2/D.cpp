#include <iostream>
#include <vector>
#include <set>

using namespace std;

void generated(int n, vector<int> curr, set<int> unused){
    if (curr.size() == n){
        for (int i = 0; i < n; i++){
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (unused.find(i) != unused.end()){
            curr.push_back(i);
            unused.erase(i);
            generated(n, curr, unused);
            unused.insert(i);
            curr.pop_back();
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> curr;
    set<int> unused;
    for (int i = 1; i <= n; i++){
        unused.insert(i);
    }
    generated(n, curr, unused);
    return 0;
}