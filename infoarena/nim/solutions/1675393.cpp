#include <fstream>
#define DMAX 20
using namespace std;
FILE * fin = fopen("submultimi.in", "r");
FILE * fout = fopen("submultimi.out", "w");

int n;
int sol[DMAX];

void bkt(int);
void afisare(int);

int main()
{
    fscanf(fin, "%d", &n);
    bkt(1);
    
    fclose(fin);
    fclose(fout);
    return 0;
}

void bkt(int poz)
{
    int i;
    for (i=sol[poz-1]+1; i<=n; i++)
    {
        sol[poz]=i;
        afisare(poz);
        bkt(poz+1);
    }
}

void afisare(int poz)
{
    int i;
    for (i=1; i<=poz; i++)
        fprintf(fout, "%d ", sol[i]);
    fprintf(fout, "\n");
}