#include <fstream>

using namespace std;
int Divizor(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}


int main()
{
    int i,t,a[101];

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>t;

    for(i=0;i<t;i++)
        fin>>a[i];

    int r;
    for (i=0;i<t+1;i=i+2)
    {
        r=Divizor(a[i],a[i+1]);
        fout<<r<<"\n";
    }

    fin.close();
    fout.close();




    return 0;
}
