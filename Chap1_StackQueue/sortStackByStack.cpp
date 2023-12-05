#include <queue>
#include <stack>
void sortStackByStack(stack<int> stk){
    stack<int> help;
    while (!stk.empty()){
        int cur = stk.top();
        stk.pop();

        while (!help.empty() && help.top() < cur){
            stk.push(help.top());
            help.pop();
        }
        // help.top() >= cur
        help.push(cur);
    }

    while (!help.empty()){
        stk.push(help.top());
        help.pop();
    }
}