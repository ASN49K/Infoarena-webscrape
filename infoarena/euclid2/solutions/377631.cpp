#include<stdio.h>

 

using namespace std;

 

long int T,A,B,i;

 

long int cmmdc(long int a,long int b)



{

if(b==0)

return a;

else

return cmmdc(b,a%b);

 

}

 

int main()

 

{

freopen("euclid2.in","r",stdin);

freopen("euclid2.out","w",stdout);

 

scanf("%ld",&T);

 

for(i=0;i<T;i++)

{

scanf("%ld",&A);

scanf("%ld",&B);

printf("%ld",cmmdc(A,B));

printf("\n");

}

return 0;

}