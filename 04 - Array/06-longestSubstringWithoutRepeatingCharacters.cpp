// Time Complexity - O(n)
// Space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(!n)return n;
        int left = 0;
        int right = 0;
        int maxLen = 1;
        unordered_map<char,int>mpp;

        while(right < n){
            if(mpp.find(s[right]) != mpp.end()){
                left = max(left,mpp[s[right]] + 1);
            }

            maxLen = max(maxLen,right-left+1);
            mpp[s[right]] = right;
            right++;
        }
        return maxLen;
    }