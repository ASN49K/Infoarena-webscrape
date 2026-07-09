#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int m,n;
string lcs[3][1025];
string x[1025];
string y[1025];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

string longest(string a, string b)
{
    if(a.length() > b.length())
    {
        return a;
    }

    return b;
}

int getLength()
{
    int ii = (n - 1) % 2 + 1;
    if(lcs[ii][m].length() == 0)
    {
        return 0;
    }

    int getNr = 1;
    for(int i = 0; i < lcs[ii][m].length(); i++)
    {
        if(lcs[ii][m].at(i) == ' ')
        {
            getNr ++ ;
        }
    }
    return getNr;
}

void getSeq()
{
    int ii;
    int previous;
    for(int i = 1; i <= n; i++)
    {
        ii = (i - 1) % 2 + 1;
        if(ii == 2)previous = 1;
        else previous = 2;
        for(int j = 1; j <= m; j++)
        {
            if(x[i].compare(y[j]) == 0)
            {
                if(lcs[ii][j-1].length() > 0)
                {
                    lcs[ii][j] = lcs[previous][j-1];
                    lcs[ii][j].append(" ");
                }
                lcs[ii][j].append(x[i]);
            }
            else
            {
                lcs[ii][j] = longest(lcs[previous][j],lcs[ii][j-1]);
            }
        }
    }
}

void read()
{
    in>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        in>>x[i];
    }
    for(int i = 1; i <= m; i++)
    {
        in>>y[i];
    }
}

void write()
{
   out<<getLength()<<"\n"<<lcs[(n - 1) % 2 + 1][m];
}
int main()
{
    read();
    getSeq();
    write();
    return 0;
}
