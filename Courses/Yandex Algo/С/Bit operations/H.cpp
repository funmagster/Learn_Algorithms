#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main(){
    int n, w;
    cin >> n >> w;
    vector<int> weight(n);
    for (int i = 0; i < n; i++){
        cin >> weight[i];
    }
    bitset<625001> get; 
    get[0] = 1;

    for (int i = 0; i < n; i++){
        get |= (get << weight[i]);
    }

    if (get[w]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
