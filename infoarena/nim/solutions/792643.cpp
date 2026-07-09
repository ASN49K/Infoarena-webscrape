#include<fstream>

using namespace std;

int n, t, s;

int main()
{
int i, el;

ifstream f("nim.in");
ofstream g("nim.out");

f>>t;

while(t)
{
    s=0;

    f>>n;

    for(i=1; i<=n; i++)
    {
        f>>el;
        s=s^el;
    }

    if(s==0)
        g<<"NU"<<endl;
    else
        g<<"DA"<<endl;

    t--;
}

return 0;
}
