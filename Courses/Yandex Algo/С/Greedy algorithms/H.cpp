// debug needed

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, cnt = 0, j;
    cin >> n;
    vector<int> a(n);
    vector<int> left_min(n, 0);
    vector<int> stack;
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        while (!stack.empty() and a[stack.back()] >= a[i]){
            stack.pop_back();
        }
        if (stack.empty())
            left_min[i] = -1;
        else
            left_min[i] = stack.back();
        stack.push_back(i);
    }
    for (int i = n - 1; i >= 0; i--){
        if (color[i] == 0){
            cnt += 1;
            j = i;
            while (left_min[j] >= 0 and color[j] == 0){
                color[j] = cnt;
                j = left_min[j];
            }
            if (color[j] == 0)
                color[j] = cnt;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++){
        cout << color[i] << ' ';
    }
    return 0;
}