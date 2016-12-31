#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes: finds all primes up to a limit

int main()
{
    vector<bool> prime(100000, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < prime.size(); i++)
    {
        if(prime[i])
        {
            for(int j = i * i; j < prime.size(); j += i)
                prime[j] = false;
        }
    }
    // print the primes in the range (0 - 100)
    for(int i = 0; i <= 100; i++)
    {
        if(prime[i])
            cout << i << endl;
    }    
    return 0;
}
