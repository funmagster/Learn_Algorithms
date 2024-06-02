#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, r;
    int right = 0;
    int left = 0;
    long long cnt = 0;

    cin >> n >> r;
    vector<int> d(n);

    for (int i = 0; i < n; i++){
        cin >> d[i];
    }

    while (left < n - 1 and right < n){   
        if((d[right] - d[left]) <= r){
            right++;
        }
        else{
            cnt += n - right;
            left++;
        }
    }

    cout << cnt;
    return 0;
}