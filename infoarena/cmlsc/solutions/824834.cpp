#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int c1[1030],c2[1030];
int c[1030][1030],L,C;
char sir[100], sir1[100];;

void Citire()
{
    ifstream f("cmlsc.in");
    f>>L>>C;
	int i;
	for (i=1; i<=L; i++)
	{
		f>>c1[i];
		//sir[i] = (char)(c1[i] + 'a' - 1);
	}

	for (i=1; i<=C; i++)
	{
		f>>c2[i];
		//sir1[i] = (char)(c2[i] + 'a' - 1);
	}
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
	
	//g<<(sir+1)<<"\n"<<(sir1+1)<<"\n";
	g<<c[L][C]<<"\n";
    /*for(i=1;i<=L;i++)
    {
        for(j=1;j<=C;j++)
            cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    */

    i=1;
    
	int sir[1030], nsir = 0;
	
	for(i=L, j=C; i; )
	{
		if(c1[i] == c2[j])
        {
            sir[++nsir] = c1[i];
            i--;
            j--;
        }
        else
            if (c[i-1][j] < c[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
	}
	
	for(i=nsir; i; i--)
		g<<sir[i]<<" ";
	
	g<<"\n";
	g.close();
}

int main()
{
    Citire();
    Solve();
    return 0;
}
