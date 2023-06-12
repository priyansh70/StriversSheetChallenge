// In this case, we are given the row number r and the column number c,
// and we need to find out the element at position (r,c).

// Time Complexity - O(c)
// Space Complexity - O(1)

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r)
{
    int ans = 1;
    for (int i = 0; i < r; i++)
    {
        // Instead of find this in factorial function ,
        // we solve it by it
        // We can optimize this calculation by the following observation.
        // Assume, given r = 7, c = 4. Now, n = r - 1 = 7 - 1 = 6 and r = c - 1 = 4 - 1 = 3
        // Let’s calculate 6C3 = 6 ! / (3 !*(6 - 3) !) = (6 * 5 * 4 * 3 * 2 * 1) / ((3 * 2 * 1) * (3 * 2 * 1))
        // This will boil down to(6 * 5 * 4) / (3 * 2 * 1) So, nCr = (n * (n - 1) * (n - 2) * .....*(n - r + 1)) / (r * (r - 1) * (r - 2) * ....1)

        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

// Utilize nCr formula
int pascalTriangle(int r, int c)
{
    return nCr(r - 1, c - 1);
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (" << r << "," << c << ") is: "
         << element;
    return 0;
}
