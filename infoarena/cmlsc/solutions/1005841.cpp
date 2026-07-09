#include <fstream>
#include <cstdint>

using namespace std;

const int MAX_SEQ = 1024;

uint8_t a[MAX_SEQ], b[MAX_SEQ];
uint16_t subprobs[MAX_SEQ + 1][MAX_SEQ + 1];

ofstream out("cmlsc.out");

void printLSC(int i, int j);

int main(int argc, char *argv[])
{
  ifstream in("cmlsc.in");
  int m, n;  in >> m >> n;

  for(int i = 0; i < m; ++i) in >> a[i];
  for(int i = 0; i < n; ++i) in >> b[i];

  for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= n; ++j)
      if(a[i - 1] == b[j - 1]) subprobs[i][j] = subprobs[i - 1][j - 1] + 1;
      else subprobs[i][j] = max(subprobs[i][j - 1], subprobs[i - 1][j]);

  out << subprobs[m][n] << endl;
  printLSC(m, n);
  out << endl;

  return 0;
}

void printLSC(int i, int j)
{
  if(i == 0 || j == 0) return;

  if(subprobs[i][j] == subprobs[i - 1][j]){ printLSC(i - 1, j); return; }
  if(subprobs[i][j] == subprobs[i][j - 1]){ printLSC(i, j - 1); return; }

  printLSC(i - 1, j - 1);
  out << a[i] << ' ';
}
