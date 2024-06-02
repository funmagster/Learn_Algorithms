#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool compareBySecond(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main(){
    int n, l, r;
    vector<pair<int, int>> segments;

    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> l >> r;
        segments.push_back(make_pair(l, r));
    }

    sort(segments.begin(), segments.end(), compareBySecond);

    int start;
    return 0;
}