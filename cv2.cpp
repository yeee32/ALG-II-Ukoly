#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int partition(int* arr, int left, int right){
    int pivot = arr[right];
    int j = left-1;
    for(int i = left; i < right; i++){
        if(arr[i] < pivot){
            j++;
            // swap
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    j++;
    int mtp = arr[right];
    arr[right] = arr[j];
    arr[j] = mtp;
    return j;
}

void quickSort(int* arr, int left, int right){
    if(left >= right){
        return;    
    }
    int pivotIndex = partition(arr, left,right);
    quickSort(arr, left, pivotIndex -1);
    quickSort(arr, pivotIndex+1, right);
}

bool presortElemUniq(int* arr, int arrSize){
    quickSort(arr, 0, arrSize-1);
    for(int i = 0; i < arrSize-1; i++){
        if(arr[i] == arr[i+1]){
            cout << "nejedinecne" << endl;
            return false;
        }
    }
    cout << "jedinecne" << endl;
    return true;
}

int modus(int* arr, int arrSize){
    int freq = 1;
    int maxFreq = 0;
    int modusValue = 0;
    quickSort(arr, 0, arrSize-1);

    for(int i = 0; i < arrSize-1; i++){
        if(arr[i] == arr[i+1]){
            freq++;
        }
        else{
            if(freq > maxFreq){
                maxFreq = freq;
                modusValue = arr[i];
            }
            freq = 1;
        }
    }
    // cout << maxFreq << endl;
    cout << modusValue << endl;
    return modusValue;
}

int main(){
    int N = 8;
    int data[] = {3, 1, 4, 2, 5, 3, 4, 4};
    // cviceni 1
    presortElemUniq(data, N);

    // cviceni 2
    modus(data, N);

    return 0;
}
