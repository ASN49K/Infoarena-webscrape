#include<stdio.h>
//#include<iostream.h>
long a,b;
long euclid(long a,long b){
								if(b==0) return a;
									else return euclid(b,a%b);
										 }
int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%ld %ld",&a,&b);
// cin>>a>>b;
a=euclid(a,b);
printf("%ld",a);
//fclose(stdout);
// cout<<a;
 return 0;
}    
