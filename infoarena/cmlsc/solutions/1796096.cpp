//VREI SA O COPIEZI?????/
//NOPE
//I SEE YOOUUUUU
// SA NU TE PRIND
//COMENTARIU
//
//
//
//
////
//
//
//
//PROBLEMA LUI SEBICA'
//ALTE COMENTARII
//SALZ LA TOATA LUMEA
//
//
//
////
//AM MAI ADAUGAT COMENTARII
// DOAR PT TINE
//
//
//
//
// HAI PWP
//DC NU ZICI NIMIC???
//WEEEEEEEEE
//MOR AICI
//NU MA LASA
//MIHAELA SI ALTII
//ADI TE UITI??
//
//AR TREBUI :)
//AJUNG?
//ADI INCHIDE GURA
//PROFU' MINTE FRUMOS
//MA DUC LA MUNTE
 /*Refren: Ma duc la munti azi, ma duc la munti
Ma duc la munti azi, ma duc pi dealu' Polonic
Ii tot un munti da-i mai mic
Ma duc la munti azi, ma duc la munti
Ma duc la munti azi, sa ma cocot direct pi el
Vedeti voi cini-i barbatel

Hei e weekend iar,
De mic am fost un foarte mare temerar
Orasul asta aglomerat
M-a sufocat, m-a sufocat
Aud o voce cum ma cheama
Natura mama din nou la ea ma cheama, da

Ma cheama mama din balcon
Ca la amiaza tre sa dorm

Mmm, hai bine dorm un ceas,
Apoi iau muntele la pas, apoi iau muntele la pas,
Cu gasca mea, brigada mea,
Baietii mei, golanii mei, prietenii mei, ma bazez pe ei, da

Am doi prieteni nu prea buni,
Sa fac ca ploua cand ii suni

Refren

Hei, da nu's singur, el e Pufi
Poti incerca sa-l atingi da nu fi prost, ca mori fara rost,
Nu e masiv da-i agresiv, mutileaza trupu, protejeaza grupu, baga spaima-n lupu, Pufi
http://Versuri.ro/w/ghdhkf

Pufi-i un fel de pechinez,
Jumate cu bichon maltez

Cand esti la munte tre sa stii, pot aparea intemperii,
Ca asa-i natura vine viitura, esti mancat, esti terminat,
Da poa sa vina si-un taifun cortul meu e cel mai bun, da

Cortu-i bun da ploua-n iel, i-o piscina cu catel

Refren

Pe munte tre sa te hranesti, altfel nu supravietuiesti
Cu mainile goale, vanez animale, cu mainile goale,
Hai ursu vin la tata, iti fac o schema cu karata, kata

Ca eu nu prea ma tem de ursi,
Acasa dorm cu doi de plus

Am o coaja de banana, o pun capcana, o pun capcana,
Sa prind un cerb ca vreau sa-l fierb si-un iepuras sa-l fac gratas,
Ca asa-i la munte, carnea-i cruda, apa-i rece, apa-i... uda

Am un pachet de biscuiti
Si pap incet sa nu sughit

Refren */
#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],sol[1025][1025],v[1025],k;
void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;++i)
        f>>a[i];
    for(int i=1;i<=m;++i)
        f>>b[i];
}
void pd1()
{
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i]==b[j]) sol[i][j]=1+sol[i-1][j-1];
            else
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
}
void pd2()
{
    g<<sol[n][m]<<endl;
    int i=n, j=m;
    k=sol[i][j];
    while(k>0)
    {
        if(a[i]==b[j])
        {
            v[k--]=a[i];
            i--;j--;
        }
        else
            if(sol[i][j-1]>sol[i-1][j]) j--;
                else
                    i--;
    }
    for(int i=1;i<=sol[n][m];++i)
        g<<v[i]<<" ";
}
int main()
{
    citire();
    pd1();
    pd2();
}
