#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int c1[1030],c2[1030];
int c[1030][1030],L,C;

void Citire()
{
    ifstream f("cmlsc.in");
    f>>L>>C;
	int i;
	for (i=1; i<=L; i++)
		f>>c1[i];
	for (i=1; i<=C; i++)
		f>>c2[i];
    f.close();
}

void Solve()
{
    int i,j;
    for(i=1;i<=L;i++)
        for(j=1;j<=C;j++)
        {
            if(c1[i] == c2[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    //cout<<"Subsirul comun are lungimea maxima "<<c[L][C]<<"\n";
	ofstream g("cmlsc.out");
	g<<c[L][C]<<"\n";
    /*for(i=1;i<=L;i++)
    {
        for(j=1;j<=C;j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    */

    int x=1;
    i=1;
    while(x<=c[L][C] && i<=C)
    {
        if(c[L][i] == x)
        {
            g<<c2[i]<<" ";
            x++;
        }
        i++;
    }
	g<<"\n";
	g.close();
}

int main()
{
    Citire();
    Solve();
    return 0;
}
