#include <iostream>
#include <vector>

using namespace std;


bool ok(int n, int k, int len, const vector<int>& a){
    int cnt = 0;
    for (int i = 0; i < n; i++){
        cnt += a[i] / len;
    }
    return k <= cnt;
}

int get_k_max(int n, int k, const vector<int>& a){
    int l = 0, r = 1e7 + 1, mid;
    while (r - l > 1){
        mid = (l + r) / 2;
        if (ok(n, k, mid, a))
            l = mid;
        else
            r = mid;
    }
    return l;

}

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; i++){
        cin >> l[i];
    }

    cout << get_k_max(n, k, l);
    return 0;
}