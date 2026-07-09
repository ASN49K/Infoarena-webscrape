#include <fstream>

using namespace std;


int cmmdc_iterativ(int a, int b)
{
    int aux;

    while( b )
      {
          aux = b;
          b = a%b;
          a = aux;
      }

    return a;
}

int main(void)
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T, a, b;

    fin>>T;
    fin>>a>>b;

    while(!fin.eof())
      {
          fout<<cmmdc_iterativ(a, b)<<'\n';
          fin>>a>>b;
      }

    fin.close();
    fout.close();

    return 0;
}
