// debug needed

#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long n, e, m, k, s;
    string command;
    cin >> n >> m >> k;
    unordered_map<unsigned long long, set<int>> num_to_set(n + 1);
    unordered_map<unsigned long long, set<unsigned long long>> set_to_num(m + 1);
    for (unsigned long long i = 0; i < k; i++){
        cin >> command;
        if (command == "ADD"){
            cin >> e >> s;
            set_to_num[s].insert(e);
            num_to_set[e].insert(s);
        }
        else if(command == "DELETE"){
            cin >> e >> s;
            for (auto set_num : num_to_set[e]) {
                set_to_num[set_num].erase(e);
            }
            num_to_set[e].clear();
        }
        else if(command == "CLEAR"){
            cin >> s;
            for (auto elem : set_to_num[s]){
                num_to_set[elem].erase(s);
            }
            set_to_num[s].clear();
        }
        else if(command == "LISTSET"){
            cin >> s;
            if (!set_to_num[s].empty()){
                for (auto elem : set_to_num[s])
                    cout << elem << ' ';
            }
            else{
                cout << -1;
            }
            cout << endl;
        }
        else if(command == "LISTSETSOF"){
            cin >> e;
            if (!num_to_set[e].empty()){
                for (auto elem : num_to_set[e])
                    cout << elem << ' ';
            }
            else{
                cout << -1;
            }
            cout << endl;
        }
    }
}