#include <cstdio>

int euclid(int a,int b){
          if (b==0) return a;
     else return euclid(b,a%b);
}

int main(){
    int a,b,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d %d",&a,&b);
          printf("%d\n",euclid(a,b));
      }
      return 0;
}
