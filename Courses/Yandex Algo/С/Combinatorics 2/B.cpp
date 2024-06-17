#include <iostream>
#include <vector>

using namespace std;

void generated(int n, int k, vector<int>& curr){
    if (curr.size() == n){
        for (int i = 0; i < n; i++){
            cout << curr[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < k; i++){
        curr.push_back(i);
        generated(n, k, curr);
        curr.pop_back();
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> curr;
    generated(n, k, curr);
    return 0;
}