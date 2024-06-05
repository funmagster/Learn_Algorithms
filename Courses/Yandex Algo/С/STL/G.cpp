#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> st1;
    vector<int> st2;
    string command;

    while (true){
        cin >> command;
        if (command == "push"){
            cin >> n;
            st1.push_back(n);
            cout << "ok" << endl;
        }
        else if (command == "pop"){
            if (st2.empty()){  
                while(!st1.empty()){
                    n = st1.back();
                    st2.push_back(n);
                    st1.pop_back();
                }
            }
            n = st2.back();
            cout << n << endl;
            st2.pop_back();
        }
        else if (command == "front"){
            if (!st2.empty()){
                cout << st2.back() << endl;
            }
            else{
                cout << st1.front() << endl;
            }
        }
        else if (command == "size"){
            cout << st1.size() + st2.size() << endl;
        }
        else if (command == "clear"){
            st1.clear();
            st2.clear();
            cout << "ok" << endl;
        }
        else if (command == "exit"){
            cout << "bye" << endl;
            break;
        }
    }
    return 0;
}