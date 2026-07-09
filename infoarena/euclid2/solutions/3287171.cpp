#include <stdio.h>
using namespace std;

int t,a,b;
int cmmdc(int a,int b){
    if(b==0)
        return a;
    else
        return cmmdc(b,a%b);
}

int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    scanf("%d",&t);
    for(;t;--t){
        scanf("%d%d",&a,&b);
        printf("%d \n",cmmdc(a,b));
    }
}