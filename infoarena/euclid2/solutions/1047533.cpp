#include <fstream>

using namespace std;

ifstream in("schi.in");
ofstream out("schi.out");

const int N = 30001;
int v[N], t[1<<15], sum;

void initialize(int p, int st, int dr){
    if(st == dr){
         t[p] = 1;
         return;
    }
    int m = (st+dr)/2;
    initialize(2*p, st, m);
    initialize(2*p+1, m+1, dr);
    t[p] = t[2*p] + t[2*p+1];
}

void update(int p, int st, int dr){
    if(st == dr){
         t[p]--;
         return;
    }
    int m = (st+dr)/2;
    if(sum <= m){
        update(2*p, st, m);
    } else {
        update(2*p+1, m+1, dr);
    }
    //t[p] = t[2*p] + t[2*p+1];
}

int main()
{
    int n, i;
    in >> n;
    for(i = 1; i <= n; i++){
        in >> v[i];
    }
    initialize(1, 1, n);
    for(i = n ; i >= 1; i--){
        sum =  v[i];
        update(1, 1, n);
    }
    for(i = 1; i <= (1<<10); i++){
        out << t[i] << "\n";
    }
    return 0;
}
