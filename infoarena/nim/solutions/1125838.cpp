#include <fstream>
#include <iostream>
using namespace std;

int main(){
    ifstream f("nim.in");
    ofstream g("nim.out");
    int n,k,s,x;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>k; s=0;
        for(int j=0;j<k;j++)
            f>>x,s=s^x;
        g<<(s?"DA":"NU")<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
