#include <cstdio>

using namespace std;

int main()
{
    FILE *fin=fopen ("nim.in","r");
    FILE *fout=fopen ("nim.out","w");
    int t,n,x,sx,i;
    fscanf (fin,"%d",&t);
    for (;t;t--){
        fscanf (fin,"%d",&n);
        sx=0;
        for (i=1;i<=n;i++){
            fscanf (fin,"%d",&x);
            sx=(sx^x);
        }
        if (!sx)
            fprintf (fout,"NU\n");
        else fprintf (fout,"DA\n");
    }
    return 0;
}
