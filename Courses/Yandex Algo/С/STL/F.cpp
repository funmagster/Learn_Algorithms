#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n, goblin;
    char action;
    cin >> n;
    deque<int> first;
    deque<int> second;
    vector<int> ans;

    for (int i = 0; i < n; i++){
        cin >> action;
        if (action == '+'){
            cin >> goblin;
            second.push_back(goblin);
        }
        else if(action == '*'){
            cin >> goblin;
            second.push_front(goblin);
        }
        else{
            goblin = first.front();
            ans.push_back(goblin);
            first.pop_front();
        }
        if (first.size() < second.size()){
            goblin = second.front();
            first.push_back(goblin);
            second.pop_front();
        }
    }
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}