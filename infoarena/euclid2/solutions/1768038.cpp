#include <cstdio>
using namespace std;
typedef unsigned int uint;

inline uint euclid(uint a,uint b){
if(!b)return a;
return euclid(b,a%b);
}

int main(void){uint n,x,y;
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
scanf("%i",&n);
for(;n;n--){
    scanf("%i %i",&x,&y);
    printf("%i\n",euclid(x,y));
}

return 0;
}
