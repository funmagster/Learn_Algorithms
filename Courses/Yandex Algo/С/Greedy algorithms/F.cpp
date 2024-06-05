// debug needed

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
    return a > b;
}
int main(){
    int n, k, types, val;
    float sums = 0;
    cin >> n;

    vector<int> v(n);
    vector<int> cnt;
    vector<int> per(k);
    vector<float> bonus(n, 0);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> types >> val;
        if (types == 1)
            per.push_back(val);
        else
            cnt.push_back(val);
    }
    sort(v.begin(), v.end());
    sort(cnt.begin(), cnt.end(), comp);
    sort(per.begin(), per.end());
    int per_size = per.size();
    if (per_size >= n){
        for (int i = n - 1; i >= 0; i--){
            bonus[i] = (float)(v[i] * per[i]) / 100.0;
        }
    }
    else{
        for (int i = per_size - 1; i >= 0; i--){
            bonus[i] = (float)(v[n - per_size + i] * per[i]) / 100.0;
        }
    }
    int i = 0;
    while (i < n and i < cnt.size() and cnt[i] > bonus[n - i - 1]){
        sums += v[n] + cnt[i];
        i++;
    }
    while (i < n){
        sums += v[i] + bonus[n - i - 1];
        i++;
    }
    cout << sums;
    return 0;
}