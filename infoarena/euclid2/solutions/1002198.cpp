#include <cstdio>
using namespace std;

int T;

inline int Euclid(int a,int b)
{
    int r;
    while(b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;

}

inline void Read()
{
    int i,a,b,x;
    FILE *f = fopen("euclid2.in","r");
    FILE *g = fopen("euclid2.out","w");
    fscanf(f,"%d", &T);
    for( i = 1; i <= T ;++i)
    {
        fscanf(f,"%d %d",&a,&b);
        x = Euclid(a,b);
        fprintf(g,"%d\n",x);
    }
    fclose(f);
    fclose(g);
}


int main()
{
    Read();
    return 0;
}
