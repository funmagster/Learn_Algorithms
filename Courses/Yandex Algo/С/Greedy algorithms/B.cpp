#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> times(k);
    for (int i = 0; i < k; i++){
        cin >> times[i];
    }
    sort(times.begin(), times.end());

    while (n > 0 and cnt < k){
        if (times[cnt] > n)
            break;
        n -= times[cnt];
        cnt++;
    }
    cout << cnt;
    return 0;
}