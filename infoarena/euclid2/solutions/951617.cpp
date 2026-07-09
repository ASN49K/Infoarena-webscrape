#include <algorithm>
#include <cstdlib>

using namespace std;
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");

int gcd(int,int);

int main()
{
    int t;
    fscanf(f,"%d",&t);

    while(t--){
        int a,b;
        fscanf(f,"%d%d",&a,&b);
        fprintf(g,"%d\n",gcd(a,b));
    }


    return 0;
}

int gcd(int a,int b)
{
    int r;
    if(b>a)
        swap(a,b);
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
