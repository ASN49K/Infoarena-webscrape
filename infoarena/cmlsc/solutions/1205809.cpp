#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int m,n;
string lcs[1025][1025];
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
    if(lcs[n + 1][m + 1].length() == 0)
    {
        return 0;
    }

    int getNr = 1;
    for(int i = 0; i < lcs[n + 1][m + 1].length(); i++)
    {
        if(lcs[n+1][m+1].at(i) == ' ')
        {
            getNr ++ ;
        }
    }
    return getNr;
}

void getSeq()
{
    for(int i = 2; i <= n + 1; i++)
    {
        for(int j = 2; j <= m + 1; j++)
        {
            if(lcs[0][j].compare(lcs[i][0]) == 0)
            {
                if(lcs[i-1][j-1].length() > 0)
                {
                    lcs[i][j].append(lcs[i-1][j-1]);
                    lcs[i][j].append(" ");
                }
                lcs[i][j].append(lcs[i][0]);
            }
            else
            {
                lcs[i][j].append(longest(lcs[i-1][j],lcs[i][j-1]));
            }
        }
    }
}

void read()
{
    in>>n>>m;
    for(int i = 2; i <= n + 1; i++)
    {
        in>>lcs[i][0];
    }
    for(int i = 2; i <= m + 1; i++)
    {
        in>>lcs[0][i];
    }
}

void write()
{
    out<<getLength()<<"\n"<<lcs[n + 1][m + 1];
}
int main()
{
    read();
    getSeq();
    write();
    return 0;
}
