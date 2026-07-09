#include<stdio.h>


int cmmdc(int a, int b){

int aux;
while (a%b!=0){
    aux = a;
    a = b%a;
    b = aux;
}

return b;

}

int main(){


freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);


int n;
int a,b;

scanf("%d",&n);

int i;
for (i = 0; i < n; i ++){
    scanf("%d %d", &a,&b);
    printf("%d", cmmdc(a,b));
}
    return 0;
}
