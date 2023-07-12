// Time Complexity: O(N) * O(N) = O(N^2)

// Reason: We are placing N numbers in N positions. This will take O(N) time For every number,
// we are reducing the search space by removing the element already placed in the previous step.
//  This takes another O(N) time.

// Space Complexity : O(N)

//    Reason : We are storing the numbers in a data structure(here vector)
#include <bits/stdc++.h>

using namespace std;

string getPermutation(int n, int k)
{
    int fact = 1;
    vector<int> numbers;
    for (int i = 1; i < n; i++)
    {
        fact = fact * i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true)
    {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }

        k = k % fact;
        fact = fact / numbers.size();
    }
    return ans;
}
int main()
{
    int n = 3, k = 3;
    string ans = getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}