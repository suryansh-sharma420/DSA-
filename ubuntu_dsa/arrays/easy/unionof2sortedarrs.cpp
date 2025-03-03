/*
given arr1 and arr2 of size n and m
union finding

how i would approach it
1. union means common elements, so id try taking only 1 of each common element present, so if arr1[i]= arr2[i] then take only one of them 


actual solutions
*/

/*
solution1 : using map
use a single map to find frequencies of elements in arr1 and arr2

unordered map NOT USED AS: keys stored in random non sorted order

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findunion(int arr1[], int arr2[], int n, int m){
    map <int, int> freq;
    vector<int> Union;
    for(int i=0; i<n; i++){
        freq[arr1[i]]++;
    }
    for(int i=0; i< m;i++){
        freq[arr2[i]]++;
    }
    for(auto & it: freq){ // auto deduces type of it
    // & ensures that it is a reference, not the element
    //it.first= key, it.second= value
        Union.push_back(it.first);

    }
    return Union;
}

int main(){
    int n=10, m=7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector <int> Union= findunion(arr1,arr2,n,m);
    cout << "union of arr1 and arr2 is: " << endl;
    for(auto & val: Union)
    {cout << val << " ";}
    return 0;
}




/*
solution 2 = using set
time = O((m+n)log(m+n))
NOTE : we dont use unordered set as elements are stored in random order

*/


#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}



/*
two pointer algo

*/

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0; // pointers
    vector < int > Union; // Uninon vector
    while(i<n && j<m){
        if(arr1[i]<=arr2[j])
        {
            if(Union.size()==0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }else
        {
            if(Union.size()==0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n) //if any element is left in arr1
    {
        if(Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}


int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}