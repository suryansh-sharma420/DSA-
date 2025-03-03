/*
given an integer array, find a contiguous subarray which has largest sum

*/

//method 1 brute force: get every subarray sum using 3 loops

//better method: sum of current subarray is current element+previous subarray so we can use 2 loops, 

#include<bits/stdc++.h>
using namespace std;

int maxsubarraysum(int arr[], int n){
    int maxim=INT_MIN;
    for(int i=0; i<n;i++){
        int sum=0;
        for(int j=i;j<n; j++){
            sum +=arr[j];
            maxim=max(maxim, sum);
        }
    }
    return maxim;
}

int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxsum=maxsubarraysum(arr, n);
    cout << maxsum << endl;
    return 0;
}