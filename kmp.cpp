#include<bits/stdc++.h>
using namespace std;

// Knuth-Morris-Pratt String Searching Algorithm
// Searches for occurrences of a string (pattern) in text

// n = length of text
// m = length of pattern
// b = back table

#define MAX 500100
string text, pat;
int b[MAX], n, m;

void KMP()
{
    int i = 0, j = -1;
    b[0] = -1;
    while(i < m)
    {
        while(j >= 0 && pat[i] != pat[j])
            j = b[j];
        i++; j++;
        b[i] = j;
    }    
    i = 0, j = 0;
    while(i < n)
    {
        while(j >= 0 && text[i] != pat[j])
            j = b[j];
        i++; j++;
        if(j == m)
        {
            cout << "Found pattern at " << i - j << endl;
            j = b[j];
        }
    }    
}   

int main()
{
    text = "Hello world, how are you doing today?";
    pat = "world";
    n = text.length();
    m = pat.length();
    KMP();  // output: "Found pattern at 6"
    return 0;
}
