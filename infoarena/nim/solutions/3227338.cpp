#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main()
{
    int t,n;
    fin>>t;
    while(t--){
        fin>>n;
        int s=0,x;
        while(n--){
            fin>>x;
            s^=x;
        }
        if(s!=0) fout<<"DA"<<endl;
        else fout<<"NU"<<endl;
    }
    return 0;
}
