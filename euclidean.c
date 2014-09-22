/*
 *      Implementation of Euclidean Algorithm
 *      to find gcd of two long integers.
 */
 
#include <stdio.h>
#define MOD %

int gcd (long int p, long int q)
{
        long int x;
        x = p MOD q;

        while (x != 0) {
                p = q;
                q = x;
                x = p MOD q;
        }

        return q;
}

int main()
{
        long long int i;
        long long int p;
        long long int q;
        printf ("Enter two numbers to calculate GDC :");
        scanf ("%lld %lld", &p, &q);
        i = gcd(p, q);
        printf ("The GCD of %lld and %lld is %lld ", p, q, i);
        return 0;
}
