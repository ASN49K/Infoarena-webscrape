#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    int t, n, nr, xs, i, j;
    fin=fopen("nim.in", "r");
    fscanf(fin, "%d", &t);
    fout=fopen("nim.out", "w");
    for(i=0; i<t; i++){
      fscanf(fin, "%d%d", &n, &xs);
      for(j=1; j<n; j++){
        fscanf(fin, "%d", &nr);
        xs^=nr;
      }
      if(xs)
        fprintf(fout, "DA\n");
      else
        fprintf(fout, "NU\n");
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
