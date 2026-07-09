#include <fstream>
#include <iostream>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");
int i, j, sir[200], lg[200], maxim, n;

int main(){
    in>>n;
    for(i=0; i<n; i++)
        in>>sir[i];
    for(i=0; i<n; i++)
    {
        maxim = 0;
        for(j=0; j<n; j++)
            if(sir[j]<sir[i] && lg[j]>maxim)
                maxim = lg[j];
            lg[i] = maxim + 1;
    }
    
    maxim = lg[0];
    for(i=0; i<n; i++)
        if(lg[i]>maxim)
            maxim = lg[i];
            
    out<<maxim<<'\n';
    
    for(i=0; i<n; i++)
        cout<<sir[i]<<' ';
        cout<<'\n';
    for(i=0; i<n; i++)
        cout<<lg[i]<<' ';    
}