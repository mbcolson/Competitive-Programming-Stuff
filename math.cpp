#include <bits/stdc++.h>
using namespace std;

// Returns true if n is prime and false otherwise
bool is_prime(long long n)
{
    if(n <= 1)
        return false;
    if(n <= 3)
        return true;
    for(long long i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }    
    return true;
}    

// Returns n to the power b mod m (n^b mod m)
long long modpower(long long n, long long b, long long m)
{
    long long res = 1;
    n = n % m;
    for(; b > 0; b = b >> 1)
    {
        if(b & 1)
            res = (res * n) % m;
        n = (n * n) % m;
    }    
    return res;
} 

// Returns the modular inverse of n mod m
// Precondition: m is a prime number
long long modinv(long long n, long long m)
{
    return modpower(n, m - 2, m);
}

// Euler's totient function "phi"
// Returns the number of positive integers up to n that are relatively prime to n
long long phi(long long n)
{
    long long res = n, i;
    for(i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            res -= res / i;
            while(n % i == 0)
                n = n / i;
        }    
    }    
    if(n != 1)
       res -= res / n;
    return res;
}
