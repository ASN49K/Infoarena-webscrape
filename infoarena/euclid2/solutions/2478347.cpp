#include <fstream>

using namespace std;

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    unsigned T,a,b,i;
    fin>>T;
    for(i=1;i<=T;i++)
        {
            fin>>a>>b;
            while(a!=b)
            if(a>b)
                    a-=b;
                else
                    b-=a;
                fout<<a<<endl;

        }
        return 0;

}
