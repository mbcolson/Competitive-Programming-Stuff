#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));   
}

// Returns true if n is prime and false otherwise
bool isPrime(ll n) {
    if(n <= 1)
        return false;
    
    if(n <= 3)
        return true;
    
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0)
            return false;
    }
    
    return true;
}    

// Returns a vector that contains the prime factors of n
vector<ll> getPrimeFactors(ll n) {
    vector<ll> primeFactors;
    
    while(n % 2 == 0) { 
        primeFactors.push_back(2); 
        n >>= 1;
    }
    
    for(ll i = 3; i <= sqrt(n); i += 2) {
        while(n % i == 0) {  
            primeFactors.push_back(i);
            n = n / i;
        }
    }
    
    if(n > 2)
        primeFactors.push_back(n);
    
    return primeFactors;
}

// Returns a vector that contains the factors of x
// Note: the factors are not sorted
vector<ll> getFactors(ll x) {
    vector<ll> factors;

    for(ll i = 1; i * i <= x; i++) {
        if ((x % i) == 0) {
            if ((x / i) != i)
                factors.push_back(x / i);
            
            factors.push_back(i);
        }
    }

    return factors;
}

// Returns n to the power b mod m (n^b mod m)
ll modPower(ll n, ll b, ll m) {
    ll res = 1;
    n = n % m;
    
    for(; b > 0; b = b >> 1) {
        if(b & 1)
            res = (res * n) % m;
        
        n = (n * n) % m;
    }
    
    return res;
} 

// Returns the modular inverse of n mod m
// a * a^-1 ≡ 1 (mod m)
// Precondition: m is a prime number
ll modInv(ll n, ll m) {
    return modPower(n, m - 2, m);
}

// Euler's Totient function "phi"
// Returns the number of positive integers up to n that are relatively prime to n
ll phi(ll n) {
    ll res = n, i;
    
    for(i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            res -= res / i;
            
            while(n % i == 0)
                n = n / i;
        }    
    }
    
    if(n != 1)
       res -= res / n;
    
    return res;
}

// Returns the modular inverse of a mod m
// a * a^-1 ≡ 1 (mod m)
// Precondition: a and m are relatively prime
ll modInv2(ll a, ll m) {
    return modPower(a, phi(m) - 1, m);
}

// Extended Euclidean Algorithm
// Solves Bezout's identity: a*x + b*y = gcd(a,b)
// All solutions are of the form x + ((k * b) / gcd(a, b)), y - ((k * a) / gcd(a, b)) for some integer k
void extgcd(ll a, ll b, ll &gcd, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        gcd = a;
    } else {    
        extgcd(b, a % b, gcd, y, x);
        y -= (a / b) * x;
    }
} 

// Returns the modular inverse of a mod m
// a * a^-1 ≡ 1 (mod m)
// Precondition: a and m are relatively prime
ll modInv3(ll a, ll m) {
    ll x, y, gcd;
    extgcd(a, m, gcd, x, y);
    return ((x % m) + m) % m;
}
