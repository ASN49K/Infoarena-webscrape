#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int a,b,t;

int gasesteCMMDC(int a,int b){
    if(a == 0){
        return b;
    }

    if(b == 0){
        return a;
    }
    if(a%b == 0)
    {
        return b;
    }
    return gasesteCMMDC(b,a%b);
}

int main()
{


    fin>>t;

    for(int i = 1 ; i <= t ; i++){
        fin>>a>>b;

        fout<<gasesteCMMDC(a,b)<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
