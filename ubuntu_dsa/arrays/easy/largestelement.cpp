// given an array find largest
/*
approaches 
1. sort and find last
2. compare in bubble sort form, adjacent elements, and everytime the larger one gets stored in variable max
3. 
*/

#include<bits/stdc++.h>
using namespace std;


//my code
int findlargest(){
    int max; 
    int n;
    int arr;
    cout << "enter no of elements: \n";
    cin >> n;
    cout << "enter array: ";
    cin >> arr;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            max=arr[i];
        }
        else{
            max=arr[i+1];
        }
        
    }
}


/*
brute force
- time complexity = O(N*logN)

*/
int sortArr(vector<int>& arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}

int main() {
    vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<sortArr(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<sortArr(arr2);
   
    return 0;
}

/*
recursive approach
- using max variable
- O(N) time 

*/

int findlargestelement(int arr[], int n) {
    int max=arr[0];
    for(int i=0; i< n; i++) {
        if (max < arr[i]) {
            max=arr[i];
        }
    }
    return max;
}

int main() {
  int arr1[] = {2,5,1,3,0};
  int n = 5;
  int max = findlargestelement(arr1, n);
  cout << "The largest element in the array is: " << max << endl;
 
  int arr2[] =  {8,10,5,7,9};
  n = 5;
  max = findlargestelement(arr2, n);
  cout << "The largest element in the array is: " << max<<endl;
  return 0;
}