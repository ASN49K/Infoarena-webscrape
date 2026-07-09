#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

int n, i, m, t[200001], cost, b, c, sol1[400001], sol2[400001], nr = 1;
pair<int, pair<int, int> > v[400001];

int rad(int nod){
    while(t[nod] > 0)
        nod = t[nod];
    return nod;
}

int main(){
    fin>>n>>m;
    for(i=1;i<=m;i++){
        fin>>v[i].second.first>>v[i].second.second>>v[i].first;
    }
    for(i=1;i<=n;i++)
        t[i] = -1;
    sort(v+1, v+m+1);
    cost = v[1].first;
    t[v[1].second.second] = v[1].second.first;
    sol1[1] = v[1].second.first;
    sol2[1] = v[1].second.second;
    for(i=2;i<=n;i++){
        b = rad(v[i].second.first);
        c = rad(v[i].second.second);
        if(b != c){
            cost += v[i].first;
            sol1[++nr] = v[i].second.first;
            sol2[nr] = v[i].second.second;
            if(t[c] < t[b]){
                t[c] += t[b];
                t[b] = c;
            }
            else{
                t[b] += t[c];
                t[c] = b;
            }
        }
    }
    fout<<cost<<"\n";
    for(i=1;i<=n-1;i++)
        fout<<sol1[i]<<" "<<sol2[i]<<"\n";
    return 0;
}
