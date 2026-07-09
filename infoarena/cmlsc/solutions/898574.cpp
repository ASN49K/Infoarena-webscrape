#include <cstdio>
#define LMAX 1050
using namespace std;
FILE *fin, *fout;
int l1, l2, s1[LMAX], s2[LMAX], lg[LMAX][LMAX], sir[LMAX];
int mx (int a, int b) { return((a>b)?a:b); }
int main()
{
    int i, j, ll=0;
    fin=fopen("cmlsc.in", "r"); fout=fopen("cmlsc.out", "w");
    fscanf (fin, "%d%d", &l1, &l2);
    for (i=1; i<=l1; ++i) fscanf (fin, "%d", &s1[i]);
    for (i=1; i<=l2; ++i) fscanf (fin, "%d", &s2[i]);
    for (i=1; i<=l1; ++i) for (j=1; j<=l2; ++j) {
        if (s1[i]==s2[j]) lg[i][j]=lg[i-1][j-1]+1; else
        lg[i][j]=mx(lg[i-1][j], lg[i][j-1]);
    }
    fprintf (fout, "%d\n", lg[l1][l2]);
    //for (i=1; i<=l1; ++i) { for (j=1; j<=l2; ++j) fprintf (fout, "%d ", lg[i][j]); fprintf (fout, "\n"); }
    i=l1; j=l2;
    while (i>=1 && j>=1) {
        if (s1[i]==s2[j]) { sir[++ll]=s1[i]; --i; --j; } else
        if (lg[i-1][j]<lg[i][j-1]) --j; else --i;
    }
    for (i=ll; i>=1; --i) fprintf (fout, "%d ", sir[i]); fprintf (fout, "\n");
    fclose(fin); fclose(fout);
    return 0;
}
