

#include <fstream>

using namespace std;

int cmmdc(int a, int b){
    while(b!=0){
        if(a>b) a=a-b;
        else b=b-a;
    }
    return a;
}


int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int a,b,t;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
    fin>>a>>b;
    fout<<cmmdc(a,b)<<endl;
    }

    return 0;
}
