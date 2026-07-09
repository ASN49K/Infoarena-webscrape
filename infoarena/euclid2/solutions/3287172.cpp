#include <stdio.h>
#include <fstream>
using namespace std;

int t,a,b;
int cmmdc(int a,int b){
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}

int main(void){
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.in","w",stdout);

    scanf("%d",&t);
    for(;t;--t){
        scanf("%d%d",&a,&b);
        printf("%d \n",cmmdc(a,b));
    }
}