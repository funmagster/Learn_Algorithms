#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ans;
    unordered_set<int> used;
    vector<int> seq(n);
    for (int i = 0; i < n; i++){
        cin >> seq[i];
    }
    for (int i = n - 1; i >= 0; i--){
        if (used.find(seq[i]) == used.end()){
            used.insert(seq[i]);
            ans.push_back(seq[i]);
        }
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << ' ';
    }
    return 0;
}