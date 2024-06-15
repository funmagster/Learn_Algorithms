#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long C(int n, int k){
    long long res = 1;
    for (int i = 0; i < k; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    if (n < 3){
        cout << 0;
        return 0;
    }
    int i = 0;
    int j = 2;
    long long ans = 0;
    while (j < n){
        if (x[j] - x[i] > d){
            i++;
        }
        else{
            ans += C(j - i, 2);
            j++;
        }
    }
    cout << ans;
    return 0;
}