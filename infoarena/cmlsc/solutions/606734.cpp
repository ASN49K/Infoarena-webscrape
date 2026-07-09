#include<fstream>
#include<iostream>
#include<vector>
using namespace std;
#define fileIn "cmlsc.in"
#define fileOut "cmlsc.out"
int n, m, _max;
struct number
{
    int value, slot1, slot2;
};
vector<int> N, M, Sol;
char s[1025], z[1025];
int read()
{
    ifstream fin(fileIn);
    fin>>n>>m;
    N.reserve(n);
    M.reserve(m);
    for(int i = 0; i < n; i++)
    {
        int num;
        fin>>num;
        N.push_back(num);
    }
    for(int i = 0; i < m; i++)
    {
        int num;
        fin>>num;
        M.push_back(num);
    }
    fin.close();
    return 0;
}

int greed()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(N[i] == M[j] && s[j] == 0)
            {
                if(_max < i) _max = i;
                if(_max < j) _max = j;

                s[j] = M[j];
                z[i] = N[i];
                break;
            }
        }
    }
    return 0;
}

int lookforNextValue(int start, char* where, int sz)
{
    for(int i = start; i <= sz; i++)
        if(where[i] != 0)
            return i;
    return -2;
}

int verify()
{
    Sol.reserve(_max);
    int i = -1, j = -1;
    while(i != -2 && j != -2)
    {
        i = lookforNextValue(i+1, (char*)z, _max);
        j = lookforNextValue(j+1, (char*)s, _max);
        if(i != -2 && j != -2)
        {
            if(z[i] == s[j])
            {
                Sol.push_back(z[i]);
            }
        }
    }
    return 0;
}
int save()
{
    verify();
    ofstream fout(fileOut);
    fout<<Sol.size()<<"\n";
    for(int i = 0; i < Sol.size(); i++)
        fout<<Sol[i]<<" ";
    fout<<endl;
    return 0;
}
int main()
{
    read();
    greed();
    save();
    return 0;
}
