//
//  pol_roa.cpp
//  
//
//  Created by Cavell on 10/25/18.
//
//

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;


long long int modexp(long long int base, long long int exponent, long long int mod)
{
    long long int x = 1;
    long long int y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/* method to return prime divisor for n */
long long int pollardrho(long long int n)
{
    srand (time(NULL));
    
    //No prime divisor for 1
    if (n==1) return n;
    
    //No prime divisor for 2
    if (n==2) return 1;
    
    //Divisor is 2 for all even numbers
    if (n % 2 == 0) return 2;
    
    //Randomly chosen number from the range [2, N)
    long long int x = (rand()%(n-2))+2;
    long long int y = x;
    
    //Constant
    long long int c = (rand()%(n-1))+1;
    
    //Candidate divisor
    long long int d = 1;
    
    while (d==1)
    {
        x = (modexp(x, 2, n) + c + n)%n;
        
        y = (modexp(y, 2, n) + c + n)%n;
        y = (modexp(y, 2, n) + c + n)%n;
        
        d = __gcd(abs(x-y), n);
        
        if( d == 1) return d;
        
        //Retry with new number
        if (d==n) return pollardrho(n);
    }
    
    return d;
}

/* driver function */
int main()
{
    cout << "Enter the number to be tested:" << endl;
    long long int n;
    cin >> n;
    long long int r = pollardrho(n);
    if(r == 1){
        cout << n << " is prime" << endl;
    }
    else{
        cout << r << " is not prime" << endl;
        cout << "A divisor for this is: " << r << endl;
    }
        return 0;
}
