#include <bits/stdc++.h>
using namespace std;

// a = first sequence of integers
// b = second sequence of integers
// n = length of the first sequence
// m = length of the second sequence

// This function prints the longest common subsequence of sequences a and b
// Multiple solutions may exist but this function will only output one of them
void printLCS(int a[], int b[], int n, int m)
{
    int dp[n + 1][m + 1];
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < m + 1; j++)
            dp[i][j] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i - 1] == b[j - 1])   
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }    
    }
    int i = n - 1, j = m - 1;
    vector<int> lcs;
    while(i >= 0 && j >= 0)
    {
        if(a[i] == b[j])
        {
            lcs.push_back(a[i]);
            i--; j--;
        }
        else if(dp[i][j + 1] > dp[i + 1][j])
            i--;
        else
            j--;
    }    
    reverse(lcs.begin(), lcs.end());
    for(const int& s : lcs)
        cout << s << ' ';
}

int main() 
{
    int n = 6, m = 7;
    int a[n] = {1, 2, 5, 8, 9, 11};
    int b[m] = {2, 8, 9, 3, 11, 5, 4};
    printLCS(a, b, n, m);  // output: 2 8 9 11
    return 0;
}
