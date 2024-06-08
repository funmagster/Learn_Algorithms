#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, N, cnt;
    cin >> n;
    N = n;

    vector<string> a;

    for (int i = 2; i*i <= N; i++){
        cnt = 0;
        while (n % i == 0){
            n /= i;
            cnt++;
        }
        if (cnt == 1)
            a.push_back(to_string(i));
        else if (cnt > 1)
            a.push_back(to_string(i) + "^" + to_string(cnt));
    }
    if (n > 1)
        a.push_back(to_string(n));
    cout << a[0];
    for (int i = 1; i < a.size(); i++){
        cout << '*' << a[i];
    }
    return 0;
}