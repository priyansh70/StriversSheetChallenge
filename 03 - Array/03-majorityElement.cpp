// Time Complexity - O(n)
// Space complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    //  Moore's Voting Algorithm
    // Initialize count as 0
    // Element have no element currenlty
    int count = 0;
    int element;

    for (int i = 0; i < nums.size(); i++)
    {
        // count - 0
        // That Mean Current element may be majority element
        if (count == 0)
        {
            element = nums[i];
            count++;
        }
        // element again encounter then we increment count
        else if (element == nums[i])
        {
            count++;
        }
        // otherwise decrement
        else
        {
            count--;
        }
    }

    // cross verification of element is majority
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (element == nums[i])
        {
            count++;
        }
    }

    return count > nums.size() / 2 ? element : -1;
}