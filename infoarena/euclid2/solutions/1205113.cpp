//#include "stdafx.h"
#include<iostream>
#include<stdio.h>

#define ll long long
using namespace std;

ll cmmdc(ll a, ll b)
{
	ll d=1;
	while (b)
	{
		d = a%b;
		a = b;
		b = d;
	}
	return a;
}

int main()
{
	ll t;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf("%lld",&t);
	while (t--)
	{
		ll a, b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", cmmdc(a, b));
	}

	return 0;
}

