#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, carr, k = 0, j = 0, elem;
    cin >> n;

    vector<int> way2;
    vector<int> impasse(n + 1, 0);
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++){
        cin >> carr;
        way2.push_back(carr);
        k++;
        if (impasse[j] + 1 == way2.back()){
            ans.push_back(make_pair(1, k));
            k = 0;
            while (!way2.empty() and impasse[j] + 1 == way2.back()){
                j++;
                elem = way2.back();
                impasse[j] = elem;
                way2.pop_back();
                k++;
            }
            ans.push_back(make_pair(2, k));
            k = 0;
        }
    }
    if (way2.empty()){
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }
    else
        cout << 0;
    return 0;
}