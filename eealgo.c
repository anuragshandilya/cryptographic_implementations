/*	TEST IMPLEMENTAION OF EXTENDED EUCLIDEAN ALGORITHM.
 *	IS COMPLETELY BASED AS MENTIONED IN "CRYPTOGRAPHY By D. STINSON"
 *
 *	Author: ANURAG SHANDILYA
 */


/*
	DO UNCOMMENT main() IF USING THIS STANDALONE.
*/

#include <stdio.h>
#include <math.h>

#define MOD %

int gcd(int a, int b, int prime)
{
	int a0, b0, t0, t, s0, s, q, r, temp;

	if (a < 0) {
		a = prime + a;
	} 
	if (b < 0) {
		b = prime + b;
	}
	a0 = a;
	b0 = b;

	t0 = 0;
	t = 1;
	s0 = 1;
	s = 0;

	q = floor(a/b);
	r = a0 - (q * b0);

	while (r > 0) {
		temp = t0 - (q * t);
		t0 = t;
		t = temp;
		temp = s0 - (q * s);
		s0 = s;
		s = temp;
		a0 = b0;
		b0 = r;
		q = floor(a0/b0);
		r = a0 - (q * b0);
	}

	r = b0;

	if (t > prime) {
		t = t MOD prime;
	}
	if (t < 0) {
		t = prime + t;
	}
	return t;
}

/*
int main()
{
	int inverse;

	inverse = gcd(75, 28, 75);

	printf("\nInverse is :%d:", inverse);

	return 0;
}
*/
