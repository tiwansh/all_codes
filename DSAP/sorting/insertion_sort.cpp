#include<bits/stdc++.h>
using namespace std;

vector<int> insertion_sort(vector<int> a){
    //Insertion sort algo here
    for(int I = 1;I < a.size();I++){
        int J = I - 1;
        int key = a[I];
        while(J >= 0 && a[J] > key){
            a[J + 1] = a[J];
            J--; 
        }
        a[J+1] = key;
    }
    return a;
}

int main(){
    vector<int> my_vector;

    for(int I = 10;I > 0;I--){
        my_vector.push_back(I);
    }

    vector<int> sorted_vector;
    sorted_vector = insertion_sort(my_vector);

    for(int I = 0;I < sorted_vector.size();I++){
        cout<<sorted_vector[I]<<endl;
    }

    return 0;
}