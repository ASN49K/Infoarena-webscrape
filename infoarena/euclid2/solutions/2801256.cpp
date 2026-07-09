#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid.out");

int main()
{
int x;
int a, b, rest;
fin >> x;
for(int i = 1; i <= x; i++)
{
fin >> a >> b;
    while(b != 0)
{
    rest = a % b;
    a = b;
    b = rest;
}
    fout << a << "\n";
}
   return 0;
}
