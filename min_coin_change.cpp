#include <bits/stdc++.h>
using namespace std;

// This function returns the minimum number of coins to make change for a given amount.
// Note: If it's impossible to make change for the amount, it will return -1 
int minCoins(vector<int>& den, int amount)
{
    int dp[amount + 1];
    for(int i = 0; i < amount + 1; i++)
        dp[i] = INT_MAX - 1;
    dp[0] = 0;
    for(int i = 1; i <= amount; i++)
        for(int j = 0; j < den.size(); j++) 
            if(i - den[j] >= 0)
                dp[i] = min(dp[i], 1 + dp[i - den[j]]);

    if(dp[amount] == (INT_MAX - 1))
        return -1;
    return dp[amount];
}    

int main() 
{
    vector<int> den = {1, 5, 10, 21, 25};   // coin denominations 
    cout << minCoins(den, 63);              // output: 3 
    
    return 0;
}
