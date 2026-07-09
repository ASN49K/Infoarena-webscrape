/*
#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
vector<int>nr,dp,inainte;
//dp-ul este lungimea celui mai mare
//subsir de pe pozitia i,elementul i fiind
//capatul subsirului
int main(){
    int n;
    cin>>n;
    nr.resize(n+1);
    dp.resize(n+1);
    inainte.resize(n+1);
    dp[0]=0;
    nr[0]=0;
    for(int i=1;i<=n;i++){
        cin>>nr[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(nr[j]<nr[i]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    inainte[i]=j;
                }
            }
        }
    }
    /*
--Metoda I-de afisare
    int max1=INT_MIN;
int acum=dp[0];
for(int i=1;i<=n;i++){
if(dp[i]>dp[acum]){
    acum=i;
}
}
vector<int>raspuns;
while(acum>0){
   raspuns.push_back(nr[acum]);
   acum=deUndeVin[acum];
}
cout<<raspuns.size()<<'\n';
reverse(raspuns.begin(),raspuns.end());
for(auto&x:raspuns){
    cout<<x<<" ";
}
----Metoda II -de afisare
int max1=INT_MIN;
int acum;
for(int i=1;i<=n;i++){
   max1=max(max1,dp[i]);
   acum=i;
}
cout<<max1<<'\n';
vector<int>raspuns;
while(acum>1){
    raspuns.push_back(nr[acum]);
    acum=inainte[acum];
}
reverse(raspuns.begin(),raspuns.end());
for(auto&x:raspuns){
    cout<<x<<" ";
}
}
*/
/*
#include <fstream>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
ifstream cin("plopi1.in");
ofstream cout("plopi1.out");
vector<int>nr,dp,inainte;
//dp-ul este lungimea celui mai mare
//subsir de pe pozitia i
//Plopi1-O(n)
//dau reverse la sirul de numere
//pentru a calcula lungimea celui
//mai mare sir crescator care
//este pentru sirul anterior de fapt
//descrescator
int main(){
    int n;
    cin>>n;
    nr.resize(n+1);
    dp.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
    }
    reverse(nr.begin(),nr.end());
    dp[0]=0;
    nr[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(nr[j]<nr[i]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    int max1=INT_MIN;
    for(int i=1;i<=n;i++){
        max1=max(max1,dp[i]);
    }
cout<<n-max1;

}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int>dp,nr;
vector<int>deUndeVin;
int const inf=2e9+1;
//imi retin pozitia celui mai mic capat
//al unui subsir de lungime i
//caut binar cel mai lung subsir de lungime i
//la care pot sa ma lipesc
int pozitiaCeluiMaiMicCapatAlSiruluiI(int i){
    int st=0;
    int dr=i-1;
    int rasp=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(nr[i]>nr[dp[mij]]){
            rasp=mij;
            st=mij+1;
        }else{
        dr=mij-1;
        }
    }
return rasp;
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+2);
    nr.resize(n+2);
    deUndeVin.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
        dp[i]=n+1;
    }

nr[n+1]=inf;
int max1=0;
int ans;
for(int i=1;i<=n;i++){
 ans=pozitiaCeluiMaiMicCapatAlSiruluiI(i);
 dp[ans+1]=i;
 deUndeVin[i]=dp[ans];
 max1=max(max1,ans+1);
}
cout<<max1<<'\n';
int acum=dp[max1];
vector<int>rasp;
while(acum){
   rasp.push_back(nr[acum]);
   acum=deUndeVin[acum];
}
reverse(rasp.begin(),rasp.end());
for(auto&x:rasp){
    cout<<x<<" ";
}
}
-------
//Baloane
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int>dp,nr;
int const inf=2e9+1;
//imi retin pozitia celui mai mic capat
//al unui subsir de lungime i
//caut binar cel mai lung subsir de lungime i
//la care pot sa ma lipesc
int pozitiaCeluiMaiMicCapatAlSiruluiI(int i){
    int st=0;
    int dr=i-1;
    int rasp=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(nr[i]>nr[dp[mij]]){
            rasp=mij;
            st=mij+1;
        }else{
        dr=mij-1;
        }
    }
return rasp;
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+2);
    nr.resize(n+2);
    deUndeVin.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
        dp[i]=n+1;
    }
reverse(nr.begin(),nr.end());
nr[n+1]=inf;
int max1=0;
int ans;
for(int i=1;i<=n;i++){
 ans=pozitiaCeluiMaiMicCapatAlSiruluiI(i);
 dp[ans+1]=i;
 max1=max(max1,ans+1);
}
cout<<n-max1;

}
*/
//Radiera
//Metoda I-O(n^2)
/*
#include <fstream>
#include <vector>
#include <climits>
using namespace std;
vector<int>dp,nr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    dp.resize(n+1);
    nr.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
    }
    dp[0]=0;
    nr[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(nr[i]>=nr[j]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    int max1=INT_MIN;
    for(int i=1;i<=n;i++){
        max1=max(max1,dp[i]);
    }
cout<<n-max1;
}

//Metoda II-O(n*logn)
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
vector<int>nr,dp;
int cautBinPoz(int i){
int st=0;
int dr=i-1;
int rasp=0;
while(st<=dr){
    int mij=(st+dr)/2;
    if(nr[i]>=nr[dp[mij]]){
        rasp=mij;
        st=mij+1;
    }else{
    dr=mij-1;
    }
}
return rasp;

}
const int inf=2e9+1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    dp.resize(n+2);
    nr.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
        dp[i]=n+1;
    }
nr[n+1]=inf;
int ans;
int max1=INT_MIN;
for(int i=1;i<=n;i++){
   ans=cautBinPoz(i);
   dp[ans+1]=i;
   max1=max(max1,ans+1);
}
cout<<max1;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<long long>>nr,dp;
const int inf=1e9+1;
int cautBin(int i,int j){
    int st=0;
    int dr=j-1;
    int rasp=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(nr[i][j]>=nr[i][dp[i][mij]]){
            rasp=mij;
            st=mij+1;
        }else{
        dr=mij-1;
        }
    }
return rasp;
    }
//Joc 6
int main(){
int n;
int S1=0;
int S2=0;
cin>>n;
nr.resize(n+2,vector<long long >(n+2));
dp.resize(n+2,vector<long long>(n+2));
for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>nr[i][j];
            dp[i][j]=n+1;
        }
}
for(int i=1;i<=n;i++){
    nr[i][n+1]=inf;
}
for(int i=1;i<=n;i++){
    if(i%2){
    int ans1;
    int max1=-1;
        for(int j=1;j=n;j++){
            ans1=cautBin(i,j);
    dp[i][ans1+1]=j;
    max1=max(max1,ans1+1);
        }
    S1+=max1;
    }else{
        int ans;
        reverse(nr[i].begin(),nr[i].end());
        nr[i][n+1]=inf;
    int max2=-1;
        for(int j=1;j=n;j++){
            ans=cautBin(i,j);
    dp[i][ans+1]=j;
    max2=max(max2,ans+1);
        }
    S2+=max2;

    }
}
cout<<S1<<" "<<S2;
}
-----
//SCLMprime
#include <iostream>
#include <vector>
using namespace std;
vector<int>nr,dp,inainte;
const long long inf= 1000000+2;
bool estePrim(int n){
    int div=2;
    while(div*div<=n){
        if(n%div==0){
         return false;
        }
    div++;
    }
return true;
}
int cautBin(int i){
int st=0;
int dr=i-1;
int rasp=0;
while(st<=dr){
    int mij=(st+dr)/2;
    if(nr[i]>nr[dp[mij]]){
        if(estePrim(nr[dp[mij]])){
        rasp=mij;
        }
        st=mij+1;
    }else{
    dr=mij-1;
    }
}

}
int main(){
int n;
cin>>n;
nr.resize(n+2);
dp.resize(n+2);
inainte.resize(n+2);
for(int i=1;i<=n;i++){
    cin>>nr[i];
    dp[i]=n+1;
}
nr[n+1]=inf;
int ans;
int max1=-1;
for(int i=1;i<=n;i++){
    if(estePrim(nr[i])){
    cout<<nr[i]<<'\n';
    ans=cautBin(i);
    dp[ans+1]=i;
    inainte[i]=dp[ans];
    max1=max(max1,ans+1);
}
}
cout<<max1<<'\n';

vector<int>rasp;
int acum=dp[max1];
while(acum>0){
    rasp.push_back(nr[acum]);
    acum=inainte[acum];
}
for(auto&x:rasp){
    cout<<x<<" ";
}

}

//Up
#include <fstream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
ifstream cin("up.in");
ofstream cout("up.out");
vector<int>dp,nr,inainte;
const int inf=INT_MAX;
int cautBin(int i){
int st=0;
int dr=i-1;
int ans=0;
while(st<=dr){
    int mij=(st+dr)/2;
    if(nr[i]>nr[dp[mij]]){
        ans=mij;
        st=mij+1;
    }else{
        dr=mij-1;
    }
}
return ans;
}
int main(){
    int n;
    cin>>n;
    dp.resize(n+2);
    nr.resize(n+2);
    inainte.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
        dp[i]=n+1;
    }
    nr[n+1]=inf;
    int max1=-inf;
    for(int i=1;i<=n;i++){
      int rasp=cautBin(i);
      dp[rasp+1]=i;
      inainte[i]=dp[rasp];
      max1=max(max1,rasp+1);
    }
cout<<max1<<'\n';

}

//Cmlsc
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;



vector<int> a, b;
vector<vector<int>> dp; // dp[i][j] = lungimea maxima a unui subsir comun pana la poz i in A si poz j in B

void afisare(int i, int j) {

    // eu sunt la dp[i][j] -> de unde am venit?
    // daca dp[i][j] == dp[i-1][j-1] + 1 si A[i] == B[j] -> A[i] face parte din solutie si eu vin din dp[i-1][j-1]
    // daca dp[i][j] == dp[i-1][j] -> vin din acest dp
    // daca dp[i][j] == dp[i][j-1] -> vin din acest dp

    if (i < 1 || j < 1) { // stare de start -> ma opresc
        return;
    }
    if (dp[i][j] == dp[i-1][j-1] + 1 && a[i] == b[j]) {
        afisare(i - 1, j - 1);
        cout << a[i] << " "; // afisez atunci cand ma intorc
        return;
    }
    if (dp[i][j] == dp[i-1][j]) { // ignor pozitia i
        afisare(i - 1, j);
        return;
    }
    if (dp[i][j] == dp[i][j-1]) { // ignor pozitia j
        afisare(i, j - 1);
        return;
    }
}

int main(){

    int n, m;
    cin>>n>>m;

    a.resize(n+1);
    b.resize(m+1);
    dp.resize(n+1, vector<int>(m+1, 0));

    for (int i=1; i<=n; i++){
        cin>>a[i];
    }
    for (int i=1; i<=m; i++){
        cin>>b[i];
    }

    // starea initiala dp[i][0] = 0 si dp[0][j] = 0 (nu trebuie sa le mai dam valori pentru ca tot dp-ul este 0 din start)

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            // recurenta in spate
            dp[i][j] = max(dp[i-1][j-1] + (a[i] == b[j]) , max(dp[i-1][j] , dp[i][j-1]));
        }
    }


    /*
    dp[1][1] = 0
    A = 1
    B = 7

    dp[1][3] = 0
    A = 1
    B = 7 5 8

    dp[2][3] = 1
    A = 1 7
    B = 7 5 8

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }


    // starea finala dp[n][m]
    cout<<dp[n][m]<<'\n';

    // afisare
    afisare(n, m);
}

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
ifstream cin("joc6.in");
ofstream cout("joc6.out");
vector<vector<int>>nr;
vector<int>dp;
const int inf=1e9;
int cautBin(int i,int j){
    int st=0;
    int dr=j-1;
    int rasp=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(nr[i][j]>=nr[i][dp[mij]]){
           rasp=mij;
           st=mij+1;
        }else{
        dr=mij-1;
        }
    }
return rasp;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
int n;
cin>>n;
nr.resize(n+2,vector<int>(n+2));
for(int i=1;i<=n;i++){
for(int j=1;j<=n;j++){
    cin>>nr[i][j];

}
}


int max1;
int max2;
int S1=0;
int S2=0;
for(int i=1;i<=n;i++){
    if(i%2){
    max1=-1;
    dp.resize(n+2,n+1);
    nr[i][n+1]=inf;
     dp[0]=0;
     int ans;
     for(int j=1;j<=n;j++){
        ans=cautBin(i,j);
        dp[ans+1]=j;
        max1=max(max1,ans+1);
     }
    S1+=max1;
     dp.clear();
    }else{
        max2=-1;
    reverse(nr[i].begin()+1,nr[i].begin()+n+1);
    dp.resize(n+2,n+1);
      nr[i][n+1]=inf;
     dp[0]=0;
     int ans;
     for(int j=1;j<=n;j++){
        ans=cautBin(i,j);
        dp[ans+1]=j;
        max2=max(max2,ans+1);
     }
    S2+=max2;
    dp.clear();
    }
}
cout<<S1<<" "<<S2<<'\n';
if(S1>S2){
    cout<<"UNU";
}else if(S1==S2){
cout<<"REMIZA";
}else{
    cout<<"DOI";
}

}

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;
ifstream cin("sclmprime.in"); ofstream cout("sclmprime.out");
vector<int>dp,nr,inainte;
vector<bool>folosit;
const int inf=1e7+1;
bool nrPrim(int n){//Metoda I-O(n*radical(n)*logn)
if(n<2){
    return false;
}
int div=2;
while(div*div<=n){
    if(n%div==0){
        return false;
    }
div++;
}
return true;
}
const int a=1e7+1;
void ciur(){
      folosit.resize(a+1,true);
      folosit[1]=folosit[0]=false;
    for(int i=2;i<=a;i++){
        if(folosit[i]){
        for(int j=i+i;j<=a;j+=i){
            folosit[j]=false;
        }

        }
    }

}
int cautBin(int i){
    int st=0;
    int dr=i-1;
    int rasp=0;
    while(st<=dr){
        int mij=(st+dr)/2;
        if(nr[i]>=nr[dp[mij]]){
            rasp=mij;
            st=mij+1;
        }else{
        dr=mij-1;
        }
    }
return rasp;
}
int main(){
    ciur();
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    nr.resize(n+2);
    dp.resize(n+2);
    inainte.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>nr[i];
        dp[i]=n+1;
    }
    nr[n+1]=inf;
    int ans;
    int max1=-1;
    for(int i=1;i<=n;i++){
        //if(nrPrim(nr[i])){
        if(folosit[nr[i]]){
        ans=cautBin(i);
        dp[ans+1]=i;
        inainte[i]=dp[ans];
        max1=max(max1,ans+1);
        }
        //}
    }
    int acum=dp[max1];
    vector<int>sir;
    while(acum){
        sir.push_back(nr[acum]);
        acum=inainte[acum];
    }
    cout<<max1<<'\n';
    reverse(sir.begin(),sir.end());
    for(auto&x:sir){
        cout<<x<<" ";
    }
}
*/
#include <fstream>
#include <vector>
//subsir comun pana in i si in j
//fixez litera i si parcurg
//de fiecare date toate litere sirului
//j deoarece imi caut litera comuna cu litera i
//imi actualizez starile si imi retin pentru fiecare
//pozitie lungimea sirului gasit
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
vector<int>A,B;
vector<vector<int>>dp;
void afisare(int i,int j){
if(i<1 || j<1){
    return;
}
if(dp[i][j]==dp[i-1][j-1]+1 && A[i]==B[j]){
    afisare(i-1,j-1);
    cout<<A[i]<<" ";
    return;
}else if(dp[i][j]==dp[i][j-1]){
    afisare(i,j-1);
    return;
}else if(dp[i][j]==dp[i-1][j]){
afisare(i-1,j);
return;
}
}
int main(){
int a,b;
cin>>a>>b;
A.resize(a+1);
B.resize(b+1);
for(int i=1;i<=a;i++){
cin>>A[i];
}
for(int j=1;j<=b;j++){
cin>>B[j];
}
dp.resize(a+1,vector<int>(b+1));
for(int i=1;i<=a;i++){//Complexitate:O(a*b)
    for(int j=1;j<=b;j++){
       dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(A[i]==B[j]));
    }
}
cout<<dp[a][b]<<'\n';
afisare(a,b);
}
