#include <cstdio>
#define file_in "euclid2.in"
#define file_out "euclid2.out"
int Q,a,b;
int cmmdc(int a, int b){ 
int r;  
while(b){      
r=a%b; a=b; b=r;}  
return a; 
}
int main(){     
freopen(file_in,"r",stdin);   
freopen(file_out,"w",stdout);  
scanf("%d", &Q);
while(Q--){     
scanf("%d %d", &a, &b); 
printf("%d\n", cmmdc(a,b));
} 
return 0;
}
