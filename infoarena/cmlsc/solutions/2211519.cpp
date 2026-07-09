#include <iostream>
#include <fstream>
#include <vector>
#define len 1024 + 1
#define pb push_back
#define cls clear

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
vector<short> v;
short N, M, cmin, sol[len], var, c[len], car[len];
bool ebun(short k)
{
    return car[c[sol[k]]] == 2;
}
void Append(short k)
{
    if(k > v.size())
    {
        if(!v.empty())
            v.cls();
        for(short i = 1; i <= k; ++i)
            v.pb(c[sol[i]]);
    }
}
void Tipar()
{
    out << v.size() << '\n';
    for(short i = 0; i < v.size(); ++i)
        out << v[i] << ' ';
}
void back(short k)
{
    for(short i = sol[k - 1] + 1; i <= cmin; ++i)
    {
        sol[k] = i;
        if(ebun(k))
        {
            Append(k);
            if(k < cmin)
                back(k + 1);
        }
    }
}
int main()
{
    in >> N >> M;
    if(N <= M)
    {
        cmin = N;
        for(short i = 1; i <= N; ++i)
        {
            in >> c[i];
            car[c[i]] = 1;
        }
        for(short i = 1; i <= M; ++i)
        {
            in >> var;
            if(car[var])
                car[var] = 2;
        }
    }
    else{
        cmin = M;
        for(short i = 1; i <= N; ++i)
        {
            in >> var;
            car[var] = 1;
        }
        for(short i = 1; i <= M; ++i)
        {
            in >> c[i];
            if(car[c[i]])
                car[c[i]] = 2;
        }
    }
    back(1);
    Tipar();
    return 0;
}
