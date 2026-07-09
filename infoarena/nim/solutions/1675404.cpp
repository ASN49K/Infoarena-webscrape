#include <fstream>
using namespace std;
FILE * fin = fopen("nim.in", "r");
FILE * fout = fopen("nim.out", "w");

int main()
{
    int i, j, t, n, x, suma;
    
    fscanf(fin, "%lld", &t);
    for (i=1; i<=t; i++)
    {
        fscanf(fin, "%lld", &n);
        
        suma=0;
        for (j=1; j<=n; j++)
        {
            fscanf(fin, "%lld", &x);
            suma=suma^x;
        }
        
        if (suma) fprintf(fout, "DA\n");
        else fprintf(fout, "NU\n");
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}
