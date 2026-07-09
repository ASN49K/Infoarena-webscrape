#include <stdio.h>
#define NMAX 1024
using namespace std;

int sa[NMAX + 1] ,sb[NMAX + 1] ,mat[NMAX + 1][NMAX + 1] ,s[NMAX + 1];

int main(){
  FILE *fin, *fout;
  fin = fopen ("cmlsc.in", "r");
  fout = fopen ("cmlsc.out", "w");

  int a, b, i, j, sm;
  fscanf (fin ,"%d", &a);
  fscanf (fin ,"%d", &b);
  for (i = 1; i <= a; i++)
    fscanf(fin ,"%d", &sa[i]);
  for (i = 1; i <= b; i++)
    fscanf(fin, "%d", &sb[i]);
  for (i = 1; i <= a; i++){
    for (j = 1; j <= b; j++){
      if (sa[i] == sb[j])
        mat[i][j] = mat[i - 1][j - 1] + 1;
      else{
        if (mat[i][j - 1] > mat[i - 1][j])
          mat[i][j] = mat[i][j - 1];
        else
          mat[i][j] = mat[i - 1][j];
      }
    }
  }
  sm = mat[a][b];
  i = a;
  j = b;
  while (sm > 0){
    if (mat[i][j - 1] == sm)
      j --;
    else if (mat[i - 1][j] == sm)
      i--;
    else {
      s[sm] = sa[i];
      i --;
      j --;
      sm --;
    }
  }
  fprintf(fout ,"%d\n" ,mat[a][b]);
  for (i = 1; i <= mat[a][b]; i++)
    fprintf(fout ,"%d " ,s[i]);
  return 0;
}
