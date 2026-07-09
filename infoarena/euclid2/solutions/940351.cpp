/* #include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int gcd(int a, int b){
			 if(a == 0) return b;
			 if(b == 0) return a;
			 if(a > b) return gcd(b, a%b);
			 else return gcd(a, b%a);
}

int main(){ 
	if(1){
		freopen("euclid2.in","r",stdin);
		freopen("euclid2.out","w",stdout);
	}

	int t = 0, a = 0, b = 0;
	cin>>t;

	for (int i = 0; i < t; i++)
	{
		cin>>a>>b;
		int ans = gcd(a,b);
		 printf("%d\n", ans);

	}
	return 0;
} */

#include <stdio.h>
 
int T, A, B;
 
int gcd(int a, int b){
			 if(a == 0) return b;
			 if(b == 0) return a;
			 if(a > b) return gcd(b, a%b);
			 else return gcd(a, b%a);
}
 
int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
 
    scanf("%d", &T);
    for (; T; --T)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", gcd(A, B));
    }        
 
    return 0;
}