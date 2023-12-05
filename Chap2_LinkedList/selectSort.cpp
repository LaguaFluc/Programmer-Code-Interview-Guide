#include <iostream>
using namespace std;
#include <vector>
void selectSort(vector<int> arr, int n){
    for (int i = 0; i < n - 1; i ++){
        int min = i;
        for (int j = i; j > i; ++j){
            if (arr[min] > arr[j]){
                min = j;
            }
        }
        if (min != i){
            swap(arr[min], arr[i]);
        }
    }
}

int main(){
    int N = 10;
    vector<int> arr = {1, 4, 6, 3, 0, 2, 5, 9, 8, 7};
    selectSort(arr, 10);
    for (int i = 0; i < N; ++i){
        cout << arr[i] << ", ";
    }
    cout << endl;
    return 0;
}