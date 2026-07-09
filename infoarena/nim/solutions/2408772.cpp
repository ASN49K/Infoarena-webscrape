#include <iostream>
#include <fstream>

using namespace std;

ifstream si("nim.in");
ofstream so("nim.out");

int main()
{
    int n,t,i,s,x;

    si>>t;
    for(int j=0;j<t;j++){
        si>>n;
        s=0;
        for(i=0;i<n;i++){
            si>>x;
            s=s^x;
        }
        if(s!=0){
            so<<"DA"<<"\n";
        }
        else{
            so<<"NU"<<"\n";
        }
    }

    return 0;
}
