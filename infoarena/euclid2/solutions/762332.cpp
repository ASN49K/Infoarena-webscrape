#include <cstdio>

void euclid(int a,int b,int &c){
     if (b==0)
     {
              c=a;
              return;
              }
     else euclid(b,a%b,c);
}

int main(){
    int a,b,c,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
          scanf("%d %d",&a,&b);
          euclid(a,b,c);
          printf("%d\n",c);
      }
      return 0;
}
