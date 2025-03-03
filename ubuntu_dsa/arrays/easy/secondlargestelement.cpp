/*
finding the second largest and the second smallest elements an array

approaches 
1. brute force = sorting 
2. 
*/

/*
brute force (works without duplicates else nope)
time - O(NlogN)
*/

#include<bits/stdc++.h>
using namespace std;
// void getelements(int arr[], int n){
//     if(n==0 || n==1){
//         cout << -1 << " " << -1 << endl;
//     }
//     sort(arr, arr+n);
//     int small=arr[1];
//     int large=arr[n-2];
//     cout<<"Second smallest is "<<small<<endl;
//     cout<<"Second largest is "<<large<<endl;
// }
// int main()
// {
//     int arr[]={1,2,4,6,7,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     getelements(arr,n);
//     return 0;
// }


/*
better approach
- find smallest and largest in a single traversal
- again traverse, find element just greater than smallest and smaller than largest
- complexity = O(N)
*/


void getelements(int arr[], int n){
    int small= INT_MAX;
    int secondsmall=INT_MAX;
    int largest=INT_MIN;
    int secondlargest=INT_MIN;
    //why?
    int i;
    for(i=0;i<n;i++)
    {
        small=min(small, arr[i]);
        largest=max(largest,arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]<secondsmall && arr[i]!=small){
            secondsmall=arr[i];
        }
        if(arr[i]>secondlargest && arr[i]!=largest){
            secondlargest=arr[i];
        }
    }
    cout << "second smallest is: " << secondsmall << endl;
    cout << "second largest is : " << secondlargest << endl;

}

int main()
{
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getelements(arr,n);
    return 0;
}


/*
optimal approach


*/

#include<bits/stdc++.h>
using namespace std;
int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
        int sS=secondSmallest(arr,n);
        int sL=secondLargest(arr,n);
    cout<<"Second smallest is "<<sS<<endl;
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}