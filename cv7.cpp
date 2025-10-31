#include <iostream>
#include <vector>

using namespace std;

// couting sort

vector<int> countingSort(vector<int>& arr){
    int size = arr.size();

    vector<int> countArr;
    vector<int> finalArr (size, 0);

    for(int i = 0; i < size; i++){
        countArr.push_back(0);    
    }

    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] < arr[j]){
                countArr[j] = countArr[j] + 1;
            }
            else{
                countArr[i] = countArr[i] + 1;
            }
        }
    }

    for(int i = 0; i < size; i++){
        finalArr[countArr[i]] = arr[i];
    }

    return finalArr;
}

int main(){
    int v;
    vector<int> arr;
    vector<int> arr2;
    while(cin >> v){
        arr.push_back(v);
    }
    arr2 = countingSort(arr);

    for(auto &v : arr2){
        cout << v << " ";
    }

    return 0;
}