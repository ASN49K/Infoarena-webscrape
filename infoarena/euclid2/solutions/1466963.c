#include<stdio.h>

#define swap(a,b) { \
        x=x+y; \
        y=x-y; \
        x=x-y; \
} 

long euclid(long a, long b) {
	while(a%b) {
            if(a<b) swap(a,b)
            long aux = a%b;
             a=b;
             b=aux;
	}

    return b;

}

int main(int argc, char ** argv) {
   int T;
   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);
   scanf("%d",&T);

   for(i=1;i<=T;i++)
   {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
   }
   return 0;
}
