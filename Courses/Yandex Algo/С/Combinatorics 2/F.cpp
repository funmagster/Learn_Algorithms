#include <iostream>
#include <vector>

using namespace std;

void generated(int n, vector<int> curr){
    if (n == 0){
        for (int i = 0; i < curr.size(); i++){
            cout << curr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++){
        if (curr.size() == 0 || curr.back() >= i){
            curr.push_back(i);
            generated(n - i, curr);
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
    generated(n, curr);
    return 0;
}