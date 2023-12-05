
#include <vector>
#include <stack>
vector<vector<int>> getNearLessNoRepeat(vector<int> arr){
    vector<vector<int>> res(arr.size(), vector<int>(2));
    stack<int> stk;
    for (int i = 0; i < arr.size(); ++i){
        while (!stk.empty() && arr[stk.top()] > arr[i]){
            int popIndex = stk.top();
            stk.pop();
            int leftLessIndex = stk.empty() ? -1 : stk.top();
            res[popIndex][0] = leftLessIndex;
            res[popIndex][1] = i;
        }
        stk.push(i);
    }

    while (!stk.empty()){
        int popIndex = stk.top();
        stk.pop();
        int leftLessIndex = stk.empty() ? -1 : stk.top();
        res[popIndex][0] = leftLessIndex;
        res[popIndex][1] = -1;
    }
}


vector<vector<int>> getNearLess(vector<int> arr){
    vector<vector<int>> res(arr.size(), vector<int>(2));
    stack<vector<int>> stk;
    for (int i = 0; i < arr.size(); ++i){
        while (!stk.empty() && arr[stk.top()[0]] > arr[i]){
            vector<int> popIdxes = stk.top();
            stk.pop();
            int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size() - 1];
            for (int popidx : popIdxes){
                res[popidx][0] = leftLessIndex;
                res[popidx][1] = i;
            }
            if (!stk.empty() && arr[stk.top()[0]] == arr[i]){
                stk.top().push_back(i);
            }
            else{
                vector<int> newList;
                newList.push_back(i);
                stk.push(newList);
            }
        }
    }
    while (!stk.empty()){
        vector<int> popIdxes = stk.top();
        stk.pop();
        int leftLessIndex = stk.empty() ? -1 : stk.top()[stk.top().size() - 1];
        for (int popIdx : popIdxes){
            res[popIdx][0] = leftLessIndex;
            res[popIdx][1] = -1;
        }
    }
    return res;
}