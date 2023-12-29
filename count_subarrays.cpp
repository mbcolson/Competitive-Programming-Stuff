#include <bits/stdc++.h>
using namespace std;

// Count the number of subarrays with sum >= k
int main() {
    vector<int> v = {10, 12, 3, 8, 16, 5, 9, 14, 8, 5, 1, 3};
    int n = v.size();
    vector<int> cum(n + 1, 0);

    for(int i = 0; i < n; i++)
        cum[i + 1] = cum[i] + v[i]; 
 
    int t = 0, ans = 0, k = 31;

    for(int i = 0; i < n; i++) {
        while(t < n and cum[t] - cum[i] < k)
            t++;

        if (cum[t] - cum[i] >= k)
            ans += n - t + 1;
    }

    for(int x : v)
        cout << x << " ";

    cout << endl;

    for(int x : cum)
        cout << x << " ";

    cout << endl << "k is: " << k << ", ans is: " << ans << endl;

    return 0;
}
