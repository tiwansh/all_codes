#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> a, int l, int m, int r){
    
}

void mergeSort(vector<int> a, int l, int r){
    int middle = l + (r - l) / 2;
    mergeSort(a, l, middle);
    mergeSort(a, middle + 1, r);
    merge(a, l, middle, r);
}

int main(){


return 0;
}