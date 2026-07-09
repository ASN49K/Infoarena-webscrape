#include<bits/stdc++.h>
#define DIM 100001

using namespace std;

ifstream fin("sirbun.in");
ofstream fout("sirbun.out");

struct nod{
    int answer = 0, lazy_propagation = 0;
};

vector <nod> aint(8 * DIM);

int v[DIM];

int n, i, k, st, dr;

long long sol;

nod Combine(nod st, nod dr){
    nod answer;
    answer.answer = min(st.answer, dr.answer);
    answer.lazy_propagation = 0;
    return answer;
}

void Build(int node, int st, int dr){
    if(st == dr)
        aint[node].answer = st;
    else {
        int mij = (st + dr) >> 1;
        Build(node << 1, st, mij);
        Build(node << 1 | 1, mij + 1, dr);
        aint[node] = Combine(aint[node << 1], aint[node << 1 | 1]);
    }
}

void Propagate(int node){
    aint[node << 1].answer += aint[node].lazy_propagation;
    aint[node << 1 | 1].answer += aint[node].lazy_propagation;
    aint[node << 1].lazy_propagation += aint[node].lazy_propagation;
    aint[node << 1 | 1].lazy_propagation += aint[node].lazy_propagation;
    aint[node].lazy_propagation = 0;
}

void Update(int node, int st, int dr, int a, int b, int val){
    if(st >= a && dr <= b){
        aint[node].answer += val;
        aint[node].lazy_propagation += val;
        Propagate(node);
    }
    else {
        if(aint[node].lazy_propagation)
            Propagate(node);
        int mij = (st + dr) >> 1;
        if(a <= mij)
            Update(node << 1, st, mij, a, b, val);
        if(b > mij)
            Update(node << 1 | 1, mij + 1, dr, a, b, val);
        aint[node] = Combine(aint[node << 1], aint[node << 1 | 1]);
    }
}

int main(){

    ios :: sync_with_stdio(false);
    fin.tie(0);
    fout.tie(0);

    fin >> n;

    sol = 0;
    st = 1;

    for(i=1;i<=n;i++)
        fin >> v[i];

    Build(1, 1, n);

    for(i=1;i<=n;i++){
        Update(1, 1, n, v[i], n, -1);
        while(aint[1].answer < 0)
            Update(1, 1, n, v[st++], n, 1);
        sol += (i - st + 1);
    }

    fout << sol;

    fin.close();
    fout.close();
}

