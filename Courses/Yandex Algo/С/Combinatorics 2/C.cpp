#include <iostream>
#include <vector>

using namespace std;

void generated(int n, int k, int cnt_1, vector<int>& curr){
    if (curr.size() == n){
        for (int i = 0; i < curr.size(); i++){
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    if ((n - curr.size()) == (k - cnt_1)){
        for (int i = 0; i < curr.size(); i++){
            cout << curr[i];
        }
        for (int i = 0; i < k - cnt_1; i++){
            cout << 1;
        }
        cout << endl;
        return;
    }
    if (k == cnt_1){
        for (int i = 0; i < curr.size(); i++){
            cout << curr[i];
        }
        for (int i = 0; i < n - curr.size(); i++){
            cout << 0;
        }
        cout << endl;
        return;
    }
    curr.push_back(0);
    generated(n, k, cnt_1, curr);
    curr.pop_back();

    curr.push_back(1);
    generated(n, k, cnt_1 + 1, curr);
    curr.pop_back();
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> curr;
    generated(n, k, 0, curr);
    return 0;
}