#include <bits/stdc++.h>
using namespace std;

// This function returns the length of the longest increasing subsequence (LIS) found in sequence 'a'.
// It runs in O(n log k) time where n is the length of the sequence and k is the length of the LIS.
int findLISLen(vector<int> a) {
    vector<int> LIS;
    
    for(int i = 0; i < a.size(); i++) {
        int pos = lower_bound(LIS.begin(), LIS.end(), a[i]) - LIS.begin();
        if(pos == LIS.size())
            LIS.push_back(a[i]);
        else
            LIS[pos] = a[i];
    }
    
    return LIS.size();
}

int main() {
    vector<int> a = {3, 5, 1, 2, 9, 5, 11, 3, 2, 4};   // LIS: {3, 5, 9, 11} or {1, 2, 3, 4}
    cout << findLISLen(a);                             // output: 4                            
    return 0;
}
