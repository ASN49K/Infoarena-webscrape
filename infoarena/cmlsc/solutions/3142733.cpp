#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int N, M;
    int a[256], b[256], r[256];
    in >> N >> M;
    for(int i = 0; i<N; i++)
        in >> a[i];
    for(int i = 0; i<M; i++)
        in >> b[i];

    int cnt = 0;
    int index = 1000;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(a[i] == b[j]){
                if(j < index){
                    cnt = 0;
                    r[cnt] = b[j];
                }
                r[cnt] = b[j];
                cnt++;
                index = j;
            }
        }
    }   
    out << cnt << endl;
    for(int i = 0; i<cnt; i++)
        out << r[i] << " ";
}