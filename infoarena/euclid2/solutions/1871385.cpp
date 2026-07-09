#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a,b,c,r,i;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>c;
    for (i=1;i<=c;i++){
        fin>>a>>b;
        while (a%b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fout<<b<<endl;
    }
    return 0;
}
