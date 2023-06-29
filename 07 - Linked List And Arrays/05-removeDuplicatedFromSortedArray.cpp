// Time Complexity - O(N)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& arr) {
        int ans = 0;
        for(int i=1;i<arr.size();i++){
            if(arr[ans] != arr[i])arr[++ans]=arr[i];
        }
        return ans+1;
    }