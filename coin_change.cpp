#include <bits/stdc++.h>
using namespace std;

// n = amount to make change for
// m = number of types of coins (each type is available in infinite supply)
// den = array of coin denominations

// This function uses the dynamic programming technique to compute the number of ways to make change for n 
long long count(int n, int m, int den[])
{
    long long dp[n + 1];
    for(int i = 0; i < n + 1; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < m; i++)
        for(int j = den[i]; j < n + 1; j++)
            dp[j] += dp[j - den[i]];
    return dp[n];
}    

int main()
{
    int n = 10, m = 4;
    int den[m] = {2, 4, 5, 6};      
    cout << count(n, m, den);      // 6 ways: {2, 2, 2, 2, 2}, {2, 2, 2, 4}, {2, 2, 6}, {2, 4, 4}, {4, 6}, {5, 5}
}
