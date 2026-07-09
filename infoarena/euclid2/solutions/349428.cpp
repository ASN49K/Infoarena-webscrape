#include <cstdio>
int aux;
int main(){
    freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
    int n;
    scanf("%d", &n); //citire :D
    int a,b;
	for(int i=1;i<=n;++i)
	{
        scanf("%d%d", &a, &b);
        if(a<b) 
		{
		aux=a;
		a=b;
		b=aux;
		}
        while(b){
            a=a%b;
            aux=a;
			a=b;
			b=aux;
        }
        printf("%d\n",a);
    }
	return 0;
}

