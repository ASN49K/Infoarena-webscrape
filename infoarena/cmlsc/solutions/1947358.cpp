#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
ifstream fin("senat.in");
ofstream fout("senat.out");

vector <int > v[1000];
vector <int > sol;
string s;
char c;
int freq[1000],a, b, k, n, m;
int main()
{
    fin>>n>>m;
        getline(fin,s);
    for(int i=1;i<=m;i++)
    {
        getline(fin,s);

        for(int j=0;j<s.size();j++)
        if(s[j]!=' ')
        {
        a=int(s[j])-48;
       v[i].push_back(a);
       }// fin>>a;
       // v[i].push_back(a);
        }
//cout<<endl;
    int OK=1, j=0;
    for(int i=1;i<=m;i++)
      {for( j=0;j<v[i].size();j++)
            if(freq[v[i][j]]==0)
                {
                    sol.push_back(v[i][j]);
                    freq[v[i][j]]=1;
                    //cout<<v[i][j]<<"("<<i<<"-"<<j<<')'<<endl;
                    break;
                }
      //cout<<i<<"-"<<sol.size();
      if(j==v[i].size())
      {
          OK=0;
            break;
      }
      }
      if(OK==1)
    for(int i=0;i<sol.size();i++)
        fout<<sol[i]<<'\n';
        else fout<<0<<'\n';
    return 0;
}
