#include <fstream>

using namespace std;

long long n,a[50],b[50];

int main(){
    ifstream fin("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>a[i]>>b[i];
    }
    for(int i=0; i<n; i++){
        while(a[i]!=b[i]){
            if(a[i]>b[i]) a[i]-=b[i];
            else b[i]-=a[i];
        }
        fout<<a[i]<<endl;
    }
    return 0;
}
