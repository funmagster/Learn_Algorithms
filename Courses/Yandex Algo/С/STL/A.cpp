#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string seq;
    bool flag = true;
    vector<char> stack;
    getline(cin, seq);
    for (char sym: seq){
        if (sym == '(' or sym == '[' or sym == '{')
            stack.push_back(sym);
        else {
            if (sym == ')'){
                if (stack.size() > 0 and stack.back() == '(')
                    stack.pop_back();
                else{
                    cout << "no";
                    flag = false;
                    break;
                }
            }
            else if (sym == ']'){
                if (stack.size() > 0 and stack.back() == '[')
                    stack.pop_back();
                else{
                    cout << "no";
                    flag = false;
                    break;
                }
            }
            else if (sym == '}'){
                if (stack.size() > 0 and stack.back() == '{')
                    stack.pop_back();
                else{
                    cout << "no";
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag){
        if (stack.size() == 0)
            cout << "yes";
        else
            cout << "no";
    }
    return 0;
}