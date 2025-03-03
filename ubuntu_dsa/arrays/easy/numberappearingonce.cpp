//to find a number that appears once
/*
my approach would be to use map, and then just choose the one with value =1
O(N*logM) + O(M) --> N elements added into map(insertion into map=logM) and O(M) to search for element w value 1
*/

#include <bits/stdc++.h>
using namespace std;

int findNumberOnce(int arr[], int n) {
    map<int, int> freq;

    // Counting the frequency of each element
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Checking for elements that occur only once
    for(auto & it: freq) {
        if(it.second == 1) {
            return it.first;  // Return the number that appears only once
        }
    }

    // If no number occurs once, return -1
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);  // Get the number of elements in the array

    int result = findNumberOnce(arr, n);

    if(result != -1) {
        cout << "Number appearing once is: " << result << endl;
    } else {
        cout << "No number appears exactly once in the array" << endl;
    }

    return 0;
}


// Optimal Approach(Using XOR): 
// Intuition:
// Two important properties of XOR are the following:

// XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
// XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

// Here all the numbers except the single number appear twice and so will form a pair. Now, if we perform XOR of all elements of the array, the XOR of each pair will result in 0 according to the XOR property 1. The result will be = 0 ^ (single number) = single number (according to property 2).
// time = O(N)


#include <bits/stdc++.h>
using namespace std;
int getsingleelement(vector <int> & arr){
    int n=arr.size();
    int xorr=0;
    for(int i=0; i< n; i++){
        xorr=xorr ^ arr[i];
    }
    return xorr;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getsingleelement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}
