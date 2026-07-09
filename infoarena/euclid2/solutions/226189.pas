{Algoritmul lui Euclid binar

Acest algoritm mai este cunoscut sub numele de
algoritmul lui Stein. Pasii algoritmului sunt:

P1. gcd(0,b)=b, pentru ca orice numar divide pe 0
iar b divide pe b. Similar gcd(a,0)=a, iar
gcd(0,0) nu este definit.


P2. Daca a si b sunt ambele pare, atunci
gcd(a,b)=2*(gcd(a div 2,b div 2)), pentru
ca 2 divide atat pe a cat si pe b.

P3. Daca a este par si b impar avem:
gcd(a,b)=gcd(a div 2,b), pentru ca 2 nu este
divizor comun. Similar daca a e impar si b par
gcd(a,b)=gcd(a,b div 2).
Daca ambele numere sunt impare, atunci daca a>b
avem gcd(a,b)=gcd((a-b) div 2,b) sau
     gcd(a,b)=gcd((b-a) div 2,a), daca a<b

P4. Repetam pasii P2, P3 pana cand a=b sau a=0
}

var a,b,i,t: longint;

function gcd(a,b:longint):longint;
begin
  if (a=0)or(a=b) then gcd:=b
  else
    if (a mod 2=0) then
       if (b mod 2=0)
          then gcd:=2*gcd(a shr 1,b shr 1)
       else gcd:=gcd(a div 2,b)
    else
       if (b mod 2=0)
          then gcd:=gcd(a,b shr 1)
       else
       if a>b then gcd:=gcd((a-b)shr 1,b)
       else gcd:=gcd((b-a) shr 1,a)

end;

begin
  assign(input,'euclid2.in');
  reset(input);
  assign(output,'euclid2.out');
  rewrite(output);
  readln(t);
  for i:=1 to t do
  begin
    readln(a,b);
    writeln(gcd(a,b));
  end;
  close(input);
  close(output);
end.