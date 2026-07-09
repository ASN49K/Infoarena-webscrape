#include<cstdio>
int t, a, b, r;

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--) { scanf("%d %d", &a, &b);
	             while(b) { r=a%b;
                            a=b;
						    b=r;
				          }
	             printf("%d\n", a);
               }
	fclose(stdin);
	fclose(stdout);
	return 0;
}