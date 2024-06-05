#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, s, cnt = 0, pos = 0;
    bool flag = true;
    cin >> n >> k >> s;
    vector<int> gas_st(s);
    for (int i = 0; i < s; i++){
        cin >> gas_st[i];
    }
    gas_st.push_back(n);
    for (int i = 0; i < s; i++){
        if (gas_st[i] < n){
            if (gas_st[i + 1] - pos > k){
                if(gas_st[i] - pos > k){
                    cout << -1;
                    flag = false;
                    break;
                }
                else{
                    pos = gas_st[i];
                    cnt++;
                }
            }
        }
        else{
            if (pos + k >= n)
                cout << cnt;
            else
                cout << -1;
                flag = false;
            break;
        }
    }
    if (flag)
        cout << cnt;
    return 0;
}