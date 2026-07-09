#include <fstream>

using namespace std;


int Divizor(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return Divizor(b,a%b);
}

int main()
{
    int i,t,a,b;

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>t;

    for (i=0;i<t;i=i+2)
    {
        fin >>a>>b;
        fout<<Divizor(a,b)<<"\n";
    }

    fin.close();
    fout.close();




    return 0;
}
