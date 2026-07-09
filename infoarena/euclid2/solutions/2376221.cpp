#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int x,i,a,b,r;

    fin>>x;

    for (i=1;i<=x;i++) {

    fin>>a>>b;

    r=max(a,b);
    b=min(a,b);
    a=r;

    do {

        r=a%b;
        a=b;
        b=r;

    }while(r>0);

    fout<<a<<endl;

    }

    fin.close();
    fout.close();

    return 0;
}
