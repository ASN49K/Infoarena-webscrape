#include <iostream>
#include <fstream>

using namespace std;
ifstream r("cmlsc.in");
ofstream w("cmlsc.out");
int dinamica[1025], v[1025], fin[1025];
int main()
{
    int m, n, x, lungime=0, cnt;
    r>>m>>n;
    for(int i=0;i<m;i++){
        r>>v[i];
    }
    for(int i=0;i<n;i++){
        r>>x;
        int maxim=0;
        cnt=0;
        while(cnt<m && x!=v[cnt]){
            maxim=max(dinamica[cnt], maxim);
            cnt++;
        }
        if(cnt!=m){
            dinamica[cnt]=maxim+1;
            lungime=max(lungime, dinamica[cnt]);
        }
    }
    w<<lungime<<"\n";
    cnt=0;
    for(int i=m-1;i>=0;i--){
        if(dinamica[i]==lungime){
            lungime--;
            fin[cnt]=v[i];
            cnt++;
        }
        if(lungime==0){
            break;
        }
    }
    for(int i=cnt-1;i>=0;i--){
        w<<fin[i]<<" ";
    }
    return 0;
}
