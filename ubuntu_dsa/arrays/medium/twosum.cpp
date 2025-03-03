/*
how to approach 2 sum
error case : cant use same element twice
- find 2 elements whose sum adds up to target k
1. brute force = all pairs of sums using 2 loops
note: instead of checking same pairs multiple times, start inner loop from i+1 
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}


/*
better approach using hashing

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twosum(int n, vector<int> &arr, int target){
    unordered_map<int, int> mpp;
    for(int i=0; i<n ; i++){
        int num = arr[i];
        int moreneeded = target - num;
        if(mpp.find(moreneeded) != mpp.end()){
            return {mpp[moreneeded], i};
        }
        mpp[num]=i;
    }
    return {-1, -1};
}


/*
without map, slightly better solution
two pointer solution
1. sort the array
2. keep 2 pointers, one at beginning, one at end
3. sum and see if it is equal to target, else move one of the pointers in a direction, depending on if sum is less than target or more
4. if left and right cross, then return none
5. not optimal to find indexes, as we need to store the elements with their index somewhere and then doing the same
*/


string twoSum(int n, vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    int left= 0;
    int right =n-1;
    while(left<right) {
        int sum = arr[left] +arr[right];
        if(sum == target){
            return "YES";
        }
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
    
}

int main()
{
    int n=5;
    vector<int> arr= {2,6,5,8,11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "this is ans: " << ans << endl;
    return 0;
}