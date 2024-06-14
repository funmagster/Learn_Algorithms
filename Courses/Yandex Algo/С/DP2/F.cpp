#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    vector<int> costs(n);

    for (int i = 0; i < n; i++){
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++){
        cin >> costs[i];
    }

    vector<int> dp(w + 1, 0);
    vector<vector<bool>> taken(n, vector<bool>(w + 1, false));

    for (int i = 0; i < n; i++){
        for (int j = w; j >= weight[i]; j--){
            if (dp[j] < dp[j - weight[i]] + costs[i]){
                dp[j] = dp[j - weight[i]] + costs[i];
                taken[i][j] = true;
            }
        }
    }

    int max_value = dp[w];
    int remaining_weight = w;
    vector<int> selected_items;

    for (int i = n - 1; i >= 0; i--){
        if (taken[i][remaining_weight]){
            selected_items.push_back(i + 1);
            remaining_weight -= weight[i];
        }
    }

    cout << selected_items.size() << endl;
    for (int i = selected_items.size() - 1; i >= 0; i--){
        cout << selected_items[i] << ' ';
    }

    return 0;
}
