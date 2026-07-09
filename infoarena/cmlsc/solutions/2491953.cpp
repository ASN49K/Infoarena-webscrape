#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, a[1025], b[1025], c[1025], i, j, k;

int main()
{
  fin >> n >> m;
  for (i = 1; i <= n; i++)
    fin >> a[i];
  for (j = 1; j <= m; j++)
    fin >> b[j];
  for (i = 1; i <= n; i++){
    for (j = 1; j <= m; j++){
      if (n > m)
      if (a[i] == b[j] and i >= j){
        c[k] = a[i];
        k++;
      }
      if (n < m)
        if (a[i] == b[j] and i <= j){
        c[k] = a[i];
        k++;
      }
    }
  }
  fout << k << endl;
  for (i = 0; i < k; i++)
    fout << c[i] << ' ';
    return 0;
}
