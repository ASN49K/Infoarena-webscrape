#include <cstdio>
using namespace std;

int euclid(int a,int b){
if(!b)return a;
return euclid(b,a%b);
}

int main(){int n,x,y;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%i",&n);
for(;n;n--){
    scanf("%i %i",&x,&y);
    printf("%i\n",euclid(x,y));
}

return 0;
}
