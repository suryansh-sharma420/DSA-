/*
SORT AN array consisting only of 0 1 2, no inbuilt sort, pull out one method
*/

//better approach
/*
maintain the count of the 3 values 0 1 and 2. 
travel array once and increment the counter
*/

#include<bits/stdc++.h>
using namespace std;

void sorting(vector<int>& arr,int n){ // note vector<int> arr[] not allowed
    int count0 = 0;
    int count1 = 0; 
    int count2 = 0;
    

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else {count2++;};
    }
    for(int i=0;i<count0;i++) arr[i] = 0;

    for (int i = count0; i < count0 + count1; i++) arr[i] = 1; // replacing 1's

    for (int i = count0 + count1; i < n; i++) arr[i] = 2; // replacing 2's
    
}


int main(){
    int n=6;
    vector<int> arr= {0,2,1,2,0,1};
    sorting(arr, n);
    cout << "after sorting: " << endl;
    for(int i=0; i<n ; i++){
        cout << arr[i] << " ";

    }
    cout << endl;
    return 0;
}



/*
dutch national flag algo variation for this prob, the optimal approach is given below
- 3 pointers low mid high
- arr[0 to low -1] contains 0
low to mid-1 contains 1
high+1 to n-1 contains 2
middle part [mid to high] is unsorted

complexity is O(N)

*/


#include <bits/stdc++.h>
using namespace std;

void sortarray(vector<int>& arr, int n) {
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<= high){
        if(arr[mid]==0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}