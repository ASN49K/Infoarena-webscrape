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

int getLength(string a)
{
    if(a.length() == 0)
    {
        return 0;
    }
    int getNr = 1;
    for(int i = 0; i < a.length(); i++)
    {
        if(a.at(i) == ' ')
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
                lcs[ii][j] ="";
                if(lcs[previous][j-1].length() > 0)
                {
                    lcs[ii][j] = lcs[previous][j-1];
                    lcs[ii][j].append(" ");
                }
                lcs[ii][j].append(x[i]);
            }
            else
            {
                if(getLength(lcs[previous][j]) > getLength(lcs[ii][j-1]))
                {
                    lcs[ii][j] = lcs[previous][j];
                }
                else
                {
                    lcs[ii][j] = lcs[ii][j-1];
                }
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
   out<<getLength(lcs[(n - 1) % 2 + 1][m])<<"\n"<<lcs[(n - 1) % 2 + 1][m];
}
int main()
{
    read();
    getSeq();
    write();
    return 0;
}
