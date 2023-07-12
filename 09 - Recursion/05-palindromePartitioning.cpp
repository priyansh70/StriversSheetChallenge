// Time Complexity: O( (2^n) *k*(n/2) )

// Reason: O(2^n) to generate every substring and O(n/2)  to check
// if the substring generated is a palindrome. O(k) is for inserting
// the palindromes in another data structure,
// where k  is the average length of the palindrome list.

// Space Complexity: O(k * x)

// Reason: The space complexity can vary depending upon the length of the answer.
// k is the average length of the list of palindromes and
//  if we have x such list of palindromes in our final answer.
//   The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).

#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str, int s, int e)
{
    if (s >= e)
        return true;
    if (str[s] != str[e])
        return false;
    return isPalindrome(str, s + 1, e - 1);
}
void help(int index, string s, vector<string> &path, vector<vector<string>> &ans)
{
    // Base Case
    if (index == s.size())
    {
        ans.push_back(path);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        // if string is palindrome
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            help(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> path;
    help(0, s, path, ans);
    return ans;
}