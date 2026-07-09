#include <fstream>

using namespace std;

const int nmax = (1 << 10);
int sa[nmax + 1];
int sb[nmax + 1];
int mat[nmax + 1][nmax + 1];
int s[nmax + 1];

int main(){

  ifstream fin ("cmlsc.in");
  ofstream fout ("cmlsc.out");

  int a, b, i, j, sm;
  fin >> a >> b;

  for (i = 1; i <= a; i++)
    fin >> sa[i];
  for (i = 1; i <= b; i++)
    fin >> sb[i];

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
      s[sm--] = sa[i--];
      j --;
    }
  }
  fout << mat[a][b] << "\n";
  for (i = 1; i <= mat[a][b]; i++)
    fout << s[i] << " ";
  return 0;
}
