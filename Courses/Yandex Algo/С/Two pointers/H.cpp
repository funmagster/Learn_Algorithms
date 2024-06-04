#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    int n, k, a_ij;
    int cnt = 0;
    cin >> n >> k;
    vector<vector<int>> satellite(k);
    unordered_map<int, int> count_map;
    vector<int> all_satellite;

    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> a_ij;
            satellite[i].push_back(a_ij);
            count_map[a_ij] = 0;
            all_satellite.push_back(a_ij);
        }
    }
    sort(all_satellite.begin(), all_satellite.end());
    for (int i = 1; i < n * k; i++){
        if (all_satellite[i] > all_satellite[i - 1])
            cnt++;
        count_map[all_satellite[i]] = cnt;
    }
    for (int i = 0; i < k; i++){
        cnt = 0;
        for (int j = 0; j < n; j++){
            cnt += count_map[satellite[i][j]];
        }
        cnt -= n*(n-1) / 2;
        cout << cnt << ' ';
    }
    return 0;
}