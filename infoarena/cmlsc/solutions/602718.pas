type vector=array[1..1025] of integer;
     matrice=array[0..1025,0..1025] of integer;
var n,m,i:integer; lcs:matrice; a,b,s:vector;  F:text;
 function max(a,b:integer):integer;
 begin
   if a>b then max:=a else max:=b;
 end;
 procedure Citeste;
 var i:integer;  r:vector;
  begin
   assign(F, 'cmlsc.in');
   reset(F);
   readln(F, n, m);
   for i:=1 to n do
    read(F, a[i]);
   for i:=1 to m do
    read(F, b[i]);
     if n<m then begin
      i:=n;
      n:=m;
      m:=i;
      r:=a;
      a:=b;
      b:=r;
     end;
   close(F);
  end;
 procedure CMLCS;
 var i,j:integer;
  begin
   for i:=0 to n do
    lcs[i,0]:=0;
   for j:=1 to m do
    lcs[0,j]:=0;
   for i:=1 to n do
    for j:=1 to m do
     if a[i]=b[j] then lcs[i,j]:=lcs[i-1,j-1]+1
       else lcs[i,j]:=max(lcs[i-1,j],lcs[i,j-1]);
  end;
 procedure Afis(i,j:integer);
  begin
   if  lcs[i,j]<>0 then
   if lcs[i,j]=lcs[i-1,j-1]+1 then
     begin
      s[lcs[i,j]]:=a[i];
      Afis(i-1,j-1);
     end
   else
     if lcs[i,j-1]>lcs[i-1,j] then Afis(i,j-1)
       else Afis(i-1,j);
  end;
Begin
Citeste;
CMLCS;
Afis(n,m);
assign(F, 'cmlsc.out');
rewrite(F);
writeln(F, lcs[n,m]);
for i:=1 to lcs[n,m] do
 write(F, s[i],' ');
 close(F);
end.

