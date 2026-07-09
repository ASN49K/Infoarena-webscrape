#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

long long T,R,A,B,i;
int v[1000];

int main()
{
    fin >> T;
    for (i=1;i<=T;i++)
    {
        fin >> A >> B;
        while (B)
        {
            R=A%B;
            A=B;
            B=R;
        }
        v[i]=A;
    }
    for (i=1;i<=T;i++)
    {
        fout << v[i] << '\n';
    }
}
