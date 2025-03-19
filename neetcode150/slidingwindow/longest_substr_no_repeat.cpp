/*
given string, find length of longest sub str without any repeating characters

idea: find repeating characters, also find longest sub str --> can use a tracking character that keeps the longest substring, and update when longer is found. 

can have any character out of 256 characters that exist.

brute force: traverse entire string, with one loop, and another loop nested to find diff substrings, by keeping on adding until a repeated character is found




*/

#include<bits/stdc++.h>
using namespace std;

// //o/p = str
// int lengthlongestsubstr(string s){
//     int n = s.length();
//     //below code is to print all sub arrays, but none get stored, so only last one gets printed. we also need non repeating
//     // for(int i=0; i<n; i++){
//     //     string sub = ""; //empty string?
//     //     for(int j=i; j<n; j++){
//     //         sub= sub + s[j];
//     //     }
//     // }
//     //using hashing below
//     int maxlen =0;
//     for(int i=0; i<n; i++){
//         int hash[256]= {0};
        
//         for(int j=i; j<n;j++){
//             if(hash[s[j]]==1){//hash[s[j]] is automatically converted to integer format, and if it already exists, break out
//                 break;
//             }
//             hash[s[j]]=1; //to remember the j
//             int len = j-i+1;
//             maxlen = max(len, maxlen);
            
//         }
        
//     }
//     return maxlen;    

// }


//above takes n*n 
/*NOTE: two pointer and sliding window whenever you see the substring
in sliding window we take L and R, and the characters between them are substring. 
take a hashmap and update characters and their indexes, also see if repeated.

*/

int maxsubstring(string s){
    //hash map to store character and index
    //2 pointers L and R, starting from 0
    //update maxlen after checking map, then update the map
    // increase R every cycle,
    // increase L to character matched in map+1 which would be mpp[s[R]]+1, and update the hash index to the current index 
    //note: when you update L, make sure the character is after L 
    int L = 0;
    unordered_map<char, int> mpp;
    // int len = 0;
    int maxlen =0;
    int n = s.length();
    for(int R=0; R <n; R++){
        if(mpp.find(s[R]) != mpp.end()){
            L = max(mpp[s[R]]+1, L);
        }
        mpp[s[R]] = R;//key value pair
        maxlen = max(maxlen, R-L+1);

        
    }
    return maxlen;

}


int main() {
    string s = "takeUforward";
    cout << "The length of the longest substring without repeating characters is: " << maxsubstring(s) << endl;
    return 0;
}