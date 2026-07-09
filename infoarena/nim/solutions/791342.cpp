

//Vasilut
#include<fstream>
#define NN 10001

using namespace std;
ofstream out("nim.out");

int v[NN],n,T;

int main()
{
    ifstream in("nim.in");
    in>>T;
    for(; T ; --T )
    {
        in>>n;
        int xorsum=0;
        for(int i=1;i<=n;i++)
        {
            in>>v[i];
            xorsum=xorsum^v[i];
        }
        if(xorsum)
        out<<"DA"<<'\n';
        else
        out<<"NU"<<'\n';
    }
    return 0;
}


