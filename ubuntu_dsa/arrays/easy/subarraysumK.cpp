/*
given an array and sum k, longest subarray that sums to k
inversely learn how to print shortest subarray also


method 1 brute force
Approach:
The steps are as follows:

First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).
If the sum is equal to k, we will consider its length i.e. (j-i+1). Among all such subarrays, we will consider the maximum length by comparing all the lengths.

complexity = O(N cube)
*/


// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.

//     int len = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             long long s = 0 ;
//             for(int K=i;K<=j;K++){
//                 s+=a[K];
//             }
//             if (s==k){
//                 len=max(len, j-i+1); //s gets reset to 0 for every combination of i and j, and len gets returned only when s=target value
//             }
//         }
//     }
//     return len;
// }

// int main() {
//     vector<int> a={2,3,5,1,9};
//     long long k=10;
//     int len =getLongestSubarray(a,k);
//     cout << "length is: " << len << "\n";
//     return 0;
// }

// /*
// solution 2: 
// using 2 loops instead of 3


// */


// #include <bits/stdc++.h>
// using namespace std;

// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.
//     int len =0;
//     for(int i=0; i<n ; i++){
//         long long s = 0;
//         for(int j=i; j< n;j++){
//             s+=a[j];

//             if (s==k){
//                 len = max(len, j-i+1);
//             }
//         }
//     }return len;

// }

// int main()
// {
//     vector<int> a = {2, 3, 5, 1, 9};
//     long long k = 10;
//     int len = getLongestSubarray(a, k);
//     cout << "The length of the longest subarray is: " << len << "\n";
//     return 0;
// }


/*
better approach using hashing
complexity : O(N) or O(N*logN)
*/


#include <bits/stdc++.h>
using namespace std;


int getLongestSubarray(vector<int>& a, long long k){
    int n = a.size();
    map<long long, int> preSumMap;
    long long sum=0;
    int maxLen = 0;
    for(int i=0; i<n ; i++){
        sum +=a[i];
        if(sum == k){
            maxLen= max(maxLen, i+1);

        }
        long long rem = sum -k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];

        }
        if(preSumMap.find(sum)== preSumMap.end()){
            preSumMap[sum]=i; //adds sum as key, i as value
        }
    }
    return maxLen;

}

int main(){
    vector<int> a= {2,3,5,1,9};
    long long k= 10;
    int len = getLongestSubarray(a,k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}