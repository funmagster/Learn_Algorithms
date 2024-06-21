#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int num : v) {
            hash ^= hash * 31 + std::hash<int>{}(num);
        }
        return hash;
    }
};

unordered_map<vector<int>, vector<int>, VectorHash> parents;
unordered_set<vector<int>, VectorHash> used;

void bfs(vector<int>& start, vector<int>& end) {
    queue<vector<int>> q;
    q.push(start);
    used.insert(start);
    
    while (!q.empty()) {
        vector<int> curr = q.front();
        q.pop();
        
        if (curr == end) {
            break;
        }
        
        vector<int> next;
        
        if (curr[0] != 9) {
            next = curr;
            next[0] += 1;
            if (used.find(next) == used.end()) {
                parents[next] = curr;
                used.insert(next);
                q.push(next);
            }
        }
        
        if (curr[3] != 1) {
            next = curr;
            next[3] -= 1;
            if (used.find(next) == used.end()) {
                parents[next] = curr;
                used.insert(next);
                q.push(next);
            }
        }
        
        next = {curr[3], curr[0], curr[1], curr[2]};
        if (used.find(next) == used.end()) {
            parents[next] = curr;
            used.insert(next);
            q.push(next);
        }
        next = {curr[1], curr[2], curr[3], curr[0]};
        if (used.find(next) == used.end()) {
            parents[next] = curr;
            used.insert(next);
            q.push(next);
        }
    }
}

vector<vector<int>> reconstruct_path(vector<int>& start, vector<int>& end) {
    vector<vector<int>> path;
    vector<int> step = end;
    while (step != start) {
        path.push_back(step);
        step = parents[step];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num1, num2;
    vector<int> a(4);
    vector<int> b(4);
    cin >> num1 >> num2;
    
    for (int i = 3; i >= 0; i--) {
        a[i] = num1 % 10;
        b[i] = num2 % 10;
        num1 /= 10;
        num2 /= 10;
    }
    
    bfs(a, b);

    vector<vector<int>> path = reconstruct_path(a, b);

    
    for (const auto& step : path) {
        for (int digit : step) {
            cout << digit;
        }
        cout << endl;
    }

    return 0;
}
