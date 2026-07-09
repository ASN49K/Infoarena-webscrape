#include<stdio.h>
int T,A,B;

int cmmdc(int A, int B)
{
	if (!B) return A;
	  else return cmmdc(B, A%B);
}
 int main(void)
   {
   	freopen("euclid2.in", "r", stdin);
   	freopen("euclid2.out", "w", stdout);
   	
   	scanf("%d", &T);
   	for(; T; --T)	
   	 {
   	 	scanf("%d %d", &A, &B);
   	 	printf("%d\n", cmmdc(A,B));
   	 }
   }
 
     
