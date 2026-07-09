#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int lungime[1040][1040];
int sirf[1040];
int m,n;
int sir1[1040],sir2[1040];
void citire();
int main()
{
    int i,j;
    int k=0;
    citire();
    for(i = 1;i < m;i++)
        for(j = 1;j < n;j++)
            if(sir1[i] == sir2[j])
                lungime[i][j] = 1 + lungime[i-1][j-1];
            else
                lungime[i][j] = max(lungime[i][j-1],lungime[i-1][j]);
    i = m;
    j = n;
    for(;i;)
    {
        if(sir1[i] == sir2[j])
        {
            sirf[k] = sir1[i];
            k++;i--;j--;
        }
        else
            if(lungime[i-1][j] < lungime[i][j-1])
                j--;
            else
                i--;
    }
    out << k << '\n';
    for(i = k-1;i >= 0; i--)
        out << sirf[i] << ' ';
    return 0;
}
void citire()
{
    in >> m >> n;
    int i;
    for(i = 1;i <= m;i++)
    {
        in >> sir1[i];
    }
    for(i = 1;i <= n;i++)
        in >> sir2[i];
}
