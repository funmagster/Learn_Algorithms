#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, cnt = 0, cnt2 = 0;
    char elem;
    cin >> n;
    vector<vector<char>> town(n);
    vector<vector<int>> ans(n, vector<int>(n, 2));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> elem;
            town[i].push_back(elem);
            if (elem == 'C')
                cnt++;
        }
    }
    int i = 0, j;
    bool go = true;
    while (i < n and go){
        j = 0;
        while (j < n){
            if (town[i][j] == 'C'){
                cnt2++;
                if (cnt2 == cnt / 2){
                    ans[i][j] = 1;
                    go = false;
                    break;
                }
            }
            ans[i][j] = 1;
            j++;
        }
        i++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}