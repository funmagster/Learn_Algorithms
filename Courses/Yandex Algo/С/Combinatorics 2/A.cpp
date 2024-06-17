#include <iostream>
#include <vector>
using namespace std;

void genetated(int n, vector<int>& curr){
    if (curr.size() == n){
        for (int i = 0; i < n; i++){
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    curr.push_back(0);
    genetated(n, curr);
    curr.pop_back();

    curr.push_back(1);
    genetated(n, curr);
    curr.pop_back();
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> curr;
    genetated(n, curr);
    return 0;
}