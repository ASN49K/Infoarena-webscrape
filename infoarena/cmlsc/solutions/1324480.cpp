#include<iostream>
#include<fstream>
using namespace std;
ifstream f("cmslc.in");
ofstream g("cmslc.out");
short b[1025],a[1025],c[1025],r=0,n1,n2,o;
void citire()
{
    f >> n1 >> n2;
    for(int i=1;i<=n1;i++)
        f >> a[i];
    for(int i=1;i<=n2;i++)
        f >> b[i];
}
void prelucrare()
{
    o=1;
    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++)
            if(a[i]==b[j])
            {
                c[o]=b[j];
                o++;
                j=n2+1;
            }
}
int main()
{
    citire();
    prelucrare();
    g << o << "\n";
    for(int i=1;i<o;i++)
        g << c[i] << " ";
    return 0;
}
