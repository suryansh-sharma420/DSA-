/*
Permutation in String
You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.

Example 1:

Input: s1 = "abc", s2 = "lecabee"

Output: true
Explanation: The substring "cab" is a permutation of "abc" and is present in "lecabee".

Example 2:

Input: s1 = "abc", s2 = "lecaabee"

Output: false
Constraints:

1 <= s1.length, s2.length <= 1000


*/
#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

class Solution{
    public:
        bool checkInclusion(string s1, string s2){
            /*
            1. store s1, store s2 in unordered array, compare each character with a window size of s1. 

            */
            // int s1[26];// this is integer array for string which is wrong
            // int s2[26];
            int n = s1.size();
            int m = s2.size();
            if(n > m) return false;
            sort(s2.begin(), s2.end());
            sort(s1.begin(), s1.end());
            for(int i=0; i<= m-n; i++){ //check every substring of s2 by sorting s1 and s2
                string temp = s2.substr(i, s1.length());//substr(position, length) and returns new string
                sort(temp.begin(), temp.end());
                if(temp==s1) return true;

            }
            return false;
        }
};





#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

class Solution{
    public:
        bool checkInclusion(string s1, string s2){
           /*
           hint 2: return false if length of s1>s2. to cover freq of each character, we use array of size 26.

           hint 3: sliding window, with size s1. to track window, we maintain freq count of characters in s2. freq count represents characters in current window.

           */
          //sliding window approach
          if(s1.length() > s2.length()) return false;

          vector<int> s1frequency(26, 0), s2frequency(26,0);
          for(char c : s1){
            s1frequency[c - 'a']++; //character c iterates through s1 fully, and s1frequency stores the character - a (assume character is b --> b-a = 1)
          }
          for(int i = 0; i < s2.length(); i++){
            s2frequency[s2[i]-'a']++;
            if( i >= s1.length()){
                s2frequency[s2[i - s1.length()] - 'a']--; //removes character left outside the window
              }
            if(s1frequency == s2frequency) return true;
          }
          return false;

        }
};




//best code by neetcode yt
class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if (s1.length() > s2.length()) return false;
    
            vector<int> s1Count(26, 0), s2Count(26, 0);
            
            for (int i = 0; i < s1.length(); i++) {
                s1Count[s1[i] - 'a']++;
                s2Count[s2[i] - 'a']++;
            }
    
            int matches = 0;
            for (int i = 0; i < 26; i++) {
                if (s1Count[i] == s2Count[i]) matches++;
            }
    
            int l = 0;
            for (int r = s1.length(); r < s2.length(); r++) {
                if (matches == 26) return true;
    
                // Add the current character to the window
                int index = s2[r] - 'a';
                s2Count[index]++;
                if (s1Count[index] == s2Count[index]) matches++;
                else if (s1Count[index] + 1 == s2Count[index]) matches--;
    
                // Remove the leftmost character from the window
                index = s2[l] - 'a';
                s2Count[index]--;
                if (s1Count[index] == s2Count[index]) matches++;
                else if (s1Count[index] - 1 == s2Count[index]) matches--;
                
                l++;
            }
    
            return matches == 26;
        }
    };
    