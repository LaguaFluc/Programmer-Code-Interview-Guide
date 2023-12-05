
生成窗口的最大值数组
```C++
#include <deque>
#include <vector>
vector<int> getMaxWindow(vector<int> arr, int w){
    if (nullptr == arr || w < 1 || arr.size() < 1){
        return nullptr;
    }
    deque<int> qmax(arr.size() - w + 1);
    int index = 0;
    vector<int> res(arr.size() - w + 1);
    for (int i = 0; i < arr.size(); ++i){
        while (!qmax.empty() && arr[qmax.back()] <= arr[i]){
            qmax.pop_back();
        }
        qmax.push_back(i);
        if (qmax.front() == i - w){
            qmax.pop_front();
        }
        if (i >= w - 1){
            res[index++] = arr[qmax.front()];
        }
    }
    return res;
}
```

单调栈结构
【题目】给定一个不含有重复值的数组arr，找到每一个i位置左边和右边离i位置最近且值比arr[i]小的位置。返回所有位置相应的信息。
```C++
#include<vector>
#include<stack>
vector<vector<int>> getNearLessNoRepeat(vector<int> arr){
    int n = arr.size()
    vector<vector<int>> res(n, vector<int>(2));
    stack<int> stk;
    for (int i = 0; i < n; ++i){
        while (!stk.empty() && arr[stk.top()] > arr[i]){
            int popIndex = stk.top();
            stk.pop();
            int leftLessIndex = stk.empty() ?  -1 : stk.top();
            res[popIndex][0] = leftLessIndex;
            res[popIndex][1] = i;
        }
        stk.push_back(i);
        while (!stk.empty()){
            int popIndex = stk.top();
            stk.pop();
            int lefLessIndex = stk.empty() ? -1 : stk.top();
            res[popIndex][0] = leftLessIndex;
            res[popIndex][1] = -1;
        }
    }
    return res;
}
```

重复数据
```C++
#include<vector>
#include<stack>

vector<vector<int>> getNearLess(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> res(n, vector<int>(2));
    for (int i = 0; i < n; ++i){
        while (!stk.empty() && arr[stk.top()[0]] > arr[i]){
            vector<int> popIdxes = stk.pop();
        }
    }
}
```