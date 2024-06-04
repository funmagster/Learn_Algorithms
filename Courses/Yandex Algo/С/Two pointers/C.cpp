#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compareByFirst(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    int n, l, r;
    vector<pair<int, int>> segments;
    vector<pair<int, int>> ans;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        segments.push_back(make_pair(l, r));
    }

    sort(segments.begin(), segments.end(), compareByFirst);

    int l_now = segments[0].first;
    int r_now = segments[0].second;

    for (int i = 1; i < n; i++){
        if (segments[i].first <= r_now) {
            r_now = max(r_now, segments[i].second);
        } else {
            ans.push_back(make_pair(l_now, r_now));
            l_now = segments[i].first;
            r_now = segments[i].second;
        }
    }
    ans.push_back(make_pair(l_now, r_now));

    cout << ans.size() << endl;
    for (const auto& segment : ans){
        cout << segment.first << ' ' << segment.second << endl;
    }
    return 0;
}
