#define max(a,b) (a>b) ? a : b

#include <fstream>
#include <iostream>
using namespace std;

fstream f("cmlsc.in",ios::in),
        g("cmlsc.out",ios::out);

  short a[1025],b[1025];
  short m,n;
  short mat[1025][1025];
  short s[1025],poz[1025],ct;


void citeste(short a[],short b[], short &n, short &m);

int main()
{

    citeste(a,b,n,m);

    for(short i=1;i<=n;i++)
        for(short j=1;j<=m;j++)
        if(a[i]==b[j]){
            mat[i][j] = mat[i-1][j-1]+1;
            if(mat[i][j]>ct)
                ct=mat[i][j],s[ct]=b[j],poz[ct]=j;
                else
                if(mat[i][j]==ct && poz[ct]>j)
                    poz[ct]=j,s[ct]=b[j];

        }
        else{
            mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            if(mat[i][j]>ct)
                ct=mat[i][j],s[ct]=b[j],poz[ct]=j;
                else
                if(mat[i][j]==ct && poz[ct]>j)
                    poz[ct]=j,s[ct]=b[j];
        }

    g<<mat[n][m]<<'\n';

    for(int i=1;i<=ct;i++)
        g<<s[i]<<' ';

    g<<'\n';

    f.close();
    g.close();


    return 0;

}

void citeste(short a[],short b[], short &n, short &m)
{
    f>>n>>m;

    for(short i=1;i<=n;i++)
    f>>a[i];

    for(short i=1;i<=m;i++)
    f>>b[i];

    return;
}




