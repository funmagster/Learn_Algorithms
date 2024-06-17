#include <iostream>
#include <vector>

using namespace std;

void generated(int n, int k, vector<int>& curr, int start) {
    if (k - curr.size() > start){
        return;
    }
    if (curr.size() == k) {
        for (int i = 0; i < k; i++){
            cout << curr[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= start; i++){
        curr.push_back(i);
        generated(n, k, curr, i - 1);
        curr.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> curr;
    generated(n, k, curr, n);
}