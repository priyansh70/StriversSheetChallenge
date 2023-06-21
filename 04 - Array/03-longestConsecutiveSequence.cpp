// Time Complexity - O(n)
// Space complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    // If array is empty
    // if(nums.size() == 0){
    //     return 0;
    // }

    // create set
    unordered_set<int> st;

    // Initialize ans as 1
    int ans = 1;

    // Run Loop -> 0 to n
    for (int i = 0; i < nums.size(); i++)
    {
        st.insert(nums[i]);
    }

    // Now Iterate Set
    for (int it : st)
    {
        // if element previous not exist that mean it is possibile start element of longest consecutive sequence
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;

            // now check for next element
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}