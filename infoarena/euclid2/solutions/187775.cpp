#include<stdio.h>
#define DIM 101
int t,r,a,b;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int i,j;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
    scanf("%d%d", &a,&b);
    while(a%b!=0)
    {
                  r=a%b;
                  a=b;
                  b=r;
                  }
                  printf("%d\n", b);
}
  
    return 0;
}
    
  /*  int k,i,n,m,a;   
    fin>>k;   
    for(i=1;i<=k;i++)   
    {   
                     fin>>n>>m;     
  while(n%m!=0)   
    {   
                 a=n%m;   
                 n=m;   
                 m=a;   
                 }   
                 fout<<m<<"\n";   
                 }   
                 return 0;   
                 }   
                   
*/
