#include <fstream>
using namespace std;
fstream fin("euclid2.in",ios::in);
fstream fout("euclid2.out",ios::out);
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    float a,b;
    int t,i;
    fin>>t;
    for(i=1;i<=t;i++){fin>>a>>b;fout<<euclid(a,b)<<'\n';}
    return 0;}

