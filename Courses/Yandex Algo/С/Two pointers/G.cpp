#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

bool compareByFirst(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int countUniqueElements(const vector<int>& array) {
    set<int> uniqueElements(array.begin(), array.end());
    return uniqueElements.size();
}

int main(){
    int n, x, c;
    cin >> n;
    vector<pair<int, int>> coords(n);
    vector<int> color(n);
    for (int i = 0; i < n; i++){
        cin >> x >> c;
        coords[i] = make_pair(x, c);
        color[i] = c;
    }
    sort(coords.begin(), coords.end(), compareByFirst);
    int k = countUniqueElements(color);
    unordered_map<int, int> count_map;
    int l = 0, r = 0;
    int unique_count = 0;
    int min_length = INT_MAX;

    while (r < coords.size()) {
    if (count_map[coords[r].second] == 0) {
        unique_count++;
    }
    count_map[coords[r].second]++;
    r++;

    while (unique_count == k) {
        if (coords[r - 1].first - coords[l].first < min_length) {
            min_length = coords[r - 1].first - coords[l].first;
        }
        count_map[coords[l].second]--;
        if (count_map[coords[l].second] == 0) {
            unique_count--;
        }
        l++;
    }
    }

    cout << min_length;

    
    return 0;
}
