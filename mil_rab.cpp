//
//  mil_rab.cpp
//  
//
//  Created by Cavell on 10/25/18.
//
//

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
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

bool mil_test(long long int p,int k)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    long long int s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < k; i++)
    {
        long long int a = rand() % (p - 1) + 1;
        long long int temp = s;
        long long int mod = modexp(a,temp,p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = pow(mod,2);
            mod = mod % p;
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << "Enter the number to be tested:" << endl;
    long long int n;
    int k;  // Number of iterations
    cin >> n;
    cout << "Enter the number of iterations:" << endl;
    cin >> k;
    if (mil_test(n, k)){
        cout << n << " is prime!" << endl;
    }
    else{
        cout << n << " is not prime." << endl;
    }
    
    return 0;
}