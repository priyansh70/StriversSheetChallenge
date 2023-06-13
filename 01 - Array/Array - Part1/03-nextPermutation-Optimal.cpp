// Time Complexity - O(3N)
// Space Complexity - O(1)
#include <bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // #1 - Find the Break Point 
    int index = -1;
    for(int i = n-2;i>=0;i--){
        if(permutation[i] < permutation[i+1])
        {
            index = i;
            break;
        }
    }

    // #2 - If Break Point not Exist 
    if(index == -1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }

    // #3 - If Break Point Exist 
    // -> Find Next Greater Element of arr[index]
    for(int i=n-1;i>index;i--){
        if(permutation[i] > permutation[index]){
            swap(permutation[i],permutation[index]);
            break;
        }
    }

    // #4 - Reverse Right Of The array from (index + 1 to n - 1)
    reverse(permutation.begin() + index+1,permutation.end());
    return permutation;
}