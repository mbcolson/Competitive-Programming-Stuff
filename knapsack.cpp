#include <bits/stdc++.h>
using namespace std;

/* 0-1 Knapsack Problem

   n = number of items
   S = maximum capacity of the knapsack
   v = array of item values
   w = array of item weights 
   
   This function returns the maximum value that can be obtained by selecting a subset of 
   the available items and not exceeding the maximum capacity of the knapsack */

int knapsack(int n, int S, int v[], int w[]) {
    int dp[n + 1][S + 1];
   
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < S + 1; j++)
            dp[i][j] = 0;
   
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= S; j++) {
            if(j >= w[i])
                dp[i + 1][j] = max(dp[i][j], v[i] + dp[i][j - w[i]]);
            else
                dp[i + 1][j] = dp[i][j];
        }    
    }
   
    return dp[n][S];
}    

int main() {
    int n = 5, S = 9;
    int v[n] = {3, 2, 5, 4, 1}, w[n] = {2, 1, 4, 3, 2}; 
    cout << knapsack(n, S, v, w);   // output: 12 (by taking items 1, 3 and 4)
    return 0;
}
