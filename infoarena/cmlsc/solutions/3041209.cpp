#include <iostream>
#include <fstream>
using namespace std;

ifstream F("cmlsc.in");
ofstream G("cmlsc.out");



int main()
{
    int n,v[1050],m,a[1050],b[1050]; F>>n>>m;
    for (int i=1;i<=n;i++)
        F>>a[i];
    for (int i=1;i<=m;i++)
        F >>b[i];
    int nr=0;
     for (int i=1;i<=n;i++)
     {
          for (int j=1;j<=m;j++)
          {
              if (a[i]==b[j])
              {
                  nr++;
                  v[nr]=b[j];

              }
          }
     }
    G<<nr<<endl;
    for (int i=1;i<=nr;i++)
        G << v[i]<< " ";



}
