#include <iostream>
#include <vector>

using namespace std;

bool check(int x1, int y1, int x2, int y2){
    if (x1 == x2 || y1 == y2){
        return true;
    }
    if (y1 - x1 == y2 - x2 || y1 + x1 == y2 + x2){
        return true;
    }
    return false;
}
void arrange(int n, vector<int> curr, int& cnt){
    if (curr.size() == n){
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++){
        bool flag = true;
        for (int j = 0; j < curr.size(); j++){
            if (check(curr.size(), i, j, curr[j])){
                flag = false;
                break;
            }
        }
        if (flag){
            curr.push_back(i);
            arrange(n, curr, cnt);
            curr.pop_back();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, cnt = 0;
    vector<int> curr;
    cin >> n;
    arrange(n, curr, cnt);
    cout << cnt;
    return 0;
}