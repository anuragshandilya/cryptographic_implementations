/*	TEST IMPLEMEMTATION OF SHAMIR'S SECRET SHARING SCHEME
 *	(t, w)-THRESHOLD SCHEME
 * 
 *	Author: ANURAG SHANDILYA
 **/

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include "eealgo.c"


/*
 *	eeealgo.c HAS BEEN USED TO USE gcd() FUNCTION SO THAT INVERSE CAN BE CALCULATED.
 *	Usage: gcd(a, b, P) 
 *	Return type: INT
*/

#define W 5
#define T 3
#define S 3
#define MOD %
#define P 17


void lagrange(int *ss, int w, int *t, int size)
{
	int A = 0;
	int num = 1;
	int deno = 1;
	int i;
	int j;
	int index;
	
//	printf("\n i am in lang\n");
	for (i = 0; i < size; i++) {
		num = 1;
		deno = 1;
		for (j = 0; j < size; j++) {
			if ((i != j)) {
				num *= t[j];
				deno *= gcd(P, (t[j] - t[i]), P);
			}
		}

/*
 *	THE PROBLEM HERE WAS THAT THE DIVISION HERE IS MODULE DIVISION.
 *	WE NEED TO FIND INVERSE USING EXTENDED EUCLEDIAN ALGORITHM.
 */
//		printf("\t%d=:=%d\t", num, deno);
		index = t[i];
		A += (int)(ss[index] * (num) * deno);
	}

		if (A >= P) {
			A = A MOD P;
		}

		printf("\nShares are :%d:", A);
	
//	return 0;
}

int main()
{

	int secret;
	int w;
	int t;
	int i;
	int j;
	int k;
	int sum = 0;
	int a[] = {14, 15};
	int congu;
	int ss[6] = {0};
	int arr[] ={1, 3, 5};
	
	secret = S;
	w = W;
	t = T;

	
	for (i = 1; i <= w; i++) {
		sum = 0;
		for (j = 1; j < t; j++) {
			sum += (a[j-1] * (int)pow(i, j));
		}
		congu = secret + sum;
		if (congu >= P) {
			congu = congu MOD P;
		}
		ss[i] = congu;
	}
	printf("\nSecrets are : ");	
	for (i = 1; i <= w; i++) {
		printf("%d ", ss[i]);
	}

	lagrange(ss, w, arr, 3);
	return 0;
}

