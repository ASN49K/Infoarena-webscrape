#include <cstdio>
#include<cstdlib>
#include<cstring>

char L[120000],*p;
int t,gr,nim;
int main()
{
    freopen("nim.in","rb",stdin);
    freopen("nim.out","w",stdout);
    fgets(L,115000,stdin);t=atoi(strtok(L," \n\b\r"));
    for(;t;t--)
    {
        fgets(L,115000,stdin);gr=atoi(strtok(L," \n\b\r"));
        fgets(L,115000,stdin);nim=atoi(strtok(L," \n\b\r"));
        for(gr--;gr;gr--)nim^=atoi(strtok(NULL," \n\b\r"));
        nim?printf("DA\n"):printf("NU\n");
    }
    return 0;
}
