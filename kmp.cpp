#include <bits/stdc++.h>
using namespace std;

// Knuth-Morris-Pratt String Matching Algorithm. Runs in O(n + m) time.

#define MAX 500000

int b[MAX];  // contains the longest prefix that is also a proper suffix of the pattern
             // For example, if the pattern is "ABAAABAB", b = [-1, 0, 0, 1, 1, 1, 2, 3, 2]

void compute_prefix(string pat) {
    int m = pat.length(), k = -1;
    b[0] = -1;
  
    for(int q = 0; q < m; q++) {
        while(k >= 0 && pat[k] != pat[q])
            k = b[k];
      
        k++;
        b[q + 1] = k;
    }    
}    

// Search for a pattern in the text string. If found, print the index where the pattern was found.
void kmp(string text, string pat) {
    int n = text.length(), m = pat.length();
    compute_prefix(pat);
    int q = 0;
  
    for(int i = 0; i < n; i++) {
        while(q >= 0 && pat[q] != text[i])
            q = b[q];
      
        q++;
      
        if(q == m) {    
            cout << "Found pattern at " << i - q + 1 << endl;
            q = b[q];
        }
    }    
}    

int main() {   
    string text = "ABAAABAABBBABABABBB";
    string pat = "ABAB";
    kmp(text, pat);     /* output: "Found pattern at 11"
                                   "Found pattern at 13"  */
    return 0;
}
