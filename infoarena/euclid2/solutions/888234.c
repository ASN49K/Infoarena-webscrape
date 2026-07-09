#include<stdio.h>

int euclid(int a, int b){
int aux;
while(b!=0){
aux = b;
b = a%aux;
a = aux;
}
return a;
}

int main(){
int n,a,b,i;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%d", &n);
for(i=0;i<n;i++){
scanf("%d %d", &a, &b);
printf("%d\n", euclid(a,b));
}
return 0;
}
