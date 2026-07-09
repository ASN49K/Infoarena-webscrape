#include <iostream>
#include <cstdio>

using namespace std;

int euclid(int m, int n){
   if(n==0)
      return m;
   return euclid(n,m%n);
}

void citire(){
   int t, x, y;
   scanf("%d",&t);
   for(int i=0;i<t;i++){
      scanf("%d %d", &x, &y);
      printf("%d\n", euclid(x,y));
   }
}

int main()
{
   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);
   citire();
   return 0;
}
