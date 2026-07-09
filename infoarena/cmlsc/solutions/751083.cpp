#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define max(a,b) (((a) > (b)) ? (a) : (b))

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int a,b,i,j;
    in >> a >> b;

    vector<short unsigned int> x(a,0);
    vector<short unsigned int> y(b,0);

    for(i=0;i<a;++i)
        in >> x[i];

    for(i=0;i<b;++i)
        in >> y[i];

    vector < vector<unsigned int> > c(a+1, vector<unsigned int>(b+1));
    for(i=0;i<a;++i)
        c[i][0] = 0;

    for(i=0;i<b;++i)
        c[0][i] = 0;

    for(i=1;i<=a;++i)
    {
        for(j=1;j<=b;++j)
        {
            if(y[j-1] == x[i-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j],c[i][j-1]);
        }
    }
    i = a;j = b;
    out << c[i][j] << "\n";
    vector <int> sol(c[i][j],0);
    int p = c[i][j];
    if(c[i][j-1] == p)
    {
        while(p)
        {
            while(c[i][j-1] == p)
                --j;
            while(c[i-1][j] == p)
                --i;
            sol[p-1] = x[i-1];
            --p;
            --i;
            --j;
        }
    }
    else
    {
        while(p)
        {
            while(c[i-1][j] == p)
                --i;
            while(c[i][j-1] == p)
                --j;
            sol[p-1] = x[i-1];
            --p;
            --i;
            --j;
        }
    }
    for(i=0;i<c[a][b];++i)
    out << sol[i] << " ";
    return 0;
}
