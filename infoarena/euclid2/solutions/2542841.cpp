#include <iostream>

#include <fstream>

using namespace std;

int n,a,b,r;
int eucl(int a,int b)
{
    if(!b)
    return a;
    return eucl(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>n;

    for(int i=n;i>0;i--)
    {

        fin>>a>>b;
        fout<<eucl(a,b)<<endl;

    }
    fin.close();
    fout.close();


    return 0;
}
