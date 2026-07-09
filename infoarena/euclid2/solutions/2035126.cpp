#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

    int eclid(int a,int b)
{
        if(b==0){
            return a;
        }
        return eclid(b,a%b);

}

int main()
{
    int T,A,B;
    f>>T;
    for(int i=1;i<=T;i=i+1){
        f>>A>>B;
        g<<eclid(A,B)<<"\n";
    }
    return 0;
}
