#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

FILE *f,*g;
int v[1050],v2[1050];

#define first Z
#define second W


void solve(string a, string b , int line[])
{
    int lines[2][1050];
    int ok = 1;
    int i,j;

    lines[0][0] = 0;
    for (i=0;i<=b.size();i++) lines[0][i] = 0;
    lines[1][0] = 0;

    for (i=1;i<=a.size();i++,ok=1-ok)
    {
        for (j=1;j<=b.size();j++)
        {
            if (a[i-1] == b[j-1])
                lines[ok][j] = lines[1-ok][j-1] +1;
            else
                lines[ok][j] = max(lines[1-ok][j],lines[ok][j-1]);
        }
    }

    ok = 1-ok;
    for (j=0;j<=b.size();j++)
        line[j] = lines[ok][j];
}

string lcs(string a, string b , string res)
{


    if (b.size() == 0)
    {
        res = "";
        return res;
    }
    else
        if (a.size() == 1)
        {
            int found = b.find_first_of(a[0]);
            if (found != string::npos)
                res = a[0];
            else
                res = "";
            return res;
        }

    int l1[b.size() + 1] ,l2[b.size() + 1];
    int i = a.size() / 2;


    solve(a.substr(0,i), b, l1);

    string ra,rb;

    for (int k=a.size()-1;k>=0;k--)
        ra += a[k];
    for (int k=b.size()-1;k>=0;k--)
        rb += b[k];

    solve( ra.substr(0,ra.size()-i), rb, l2);

    int max = 0, k = 0;

    for ( int j = 0 ; j < ( b.size() + 1 ) ; j++ )
	{
		if ( ( l1[ j ] + l2[ b.size() - j ] ) > max )
		{
			max = l1[ j ] + l2[ b.size() - j ] ;
			k = j ;
		}
	}
	string lcs1, lcs2 ;

    if (i == 0) i++;

    return lcs( a.substr( 0, i ), b.substr( 0, k ), lcs1 ).append( lcs( a.substr( i, a.size() ), b.substr( k, b.size() ), lcs2 ) ) ;
}


int main()
{
    f = fopen("cmlsc.in","r");
    g = fopen("cmlsc.out","w");

    string a,b;
    int n,m,i,j,x;
    fscanf(f,"%d%d",&n,&m);

    for (i=1;i<=n;i++)
    {

       fscanf(f,"%d",&x);
       a += char(x);
    }
    for (i=1;i<=m;i++)
    {
       fscanf(f,"%d",&x);
       b += char(x);
    }

    string ax;
    string res = lcs(a,b,ax);

    fprintf(g,"%d\n",res.size());
    for (int i=0;i<res.size();i++)
        fprintf(g,"%d ",res[i]<=0?res[i]+256:res[i]);


    return 0;
}
