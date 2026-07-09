#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{int a,b,n,i;
fin>>n;
while(n--)
    {fin>>a>>b;
    fout<<euclid(a,b)<<endl;
    }
}
