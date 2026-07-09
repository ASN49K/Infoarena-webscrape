#include <iostream>
#include <fstream>
using namespace std;
long a[1025],b[1025],M,N,i,j,MAX,c[1025],t;
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>M>>N;
    MAX=0;
    for (i=1; i<=M; i++)
        fin>>a[i];
    for (i=1; i<=N; i++)
        fin>>b[i];
    for (i=1; i<=M ;i++)
        for (j=1; j<=N; j++)
            if (a[i]==b[j])
            {
                t++;
                c[t]=a[i];
                MAX++;
                break;
            }
    fout<<MAX<<endl;
    for (i=1;i<=t;i++)
        fout<<c[i]<<" ";
    return 0;
}
