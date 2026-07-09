Program Subsir;
uses crt;
type Matrix= array[1..100,1..100] of integer;
     MatrixB= array[1..100,1..100] of boolean;
     Vector= array[1..1000] of integer;
var D,B:Matrix;
    T,S,C:Vector;
    k,n,m,i,j,x,y,z:integer;
    f1,f2:text;

Procedure Afisare(k,h:integer ) ;
 begin
 if B[k,h]=1 then begin Afisare(k-1,h-1); write(f2,T[k],' '); end
             else
                 if B[k,h]=2 then Afisare(k-1,h)
                             else
                                 if B[k,h]=3 then Afisare(k,h-1);
 end;

begin
clrscr;
assign(f1,'cmlsc.in'); reset(f1);
assign(f2,'cmlsc.out'); rewrite(f2);
readln(f1,n,m);
for i:=0 to n+1 do
 for j:=0 to m+1 do
  D[i,j]:=0;

for i:=1 to n do
 read(f1,T[i]);
for i:=1 to m do
 read(f1,S[i]);

for i:=1 to n do
 for j:=1 to m do
  if T[i]=S[j] then begin D[i,j]:=D[i-1,j-1]+1; B[i,j]:=1; end
               else
                   if D[i-1,j]>D[i,j-1] then
                                             begin
                                                  D[i,j]:=D[i-1,j];
                                                  B[i,j]:=2;
                                             end
                                         else
                                             begin
                                                  D[i,j]:=D[i,j-1];
                                                  B[i,j]:=3;
                                             end;
z:=D[1,1];
for i:=1 to n do
 for j:=1 to m do
    if D[i,j]>=z then begin z:=D[i,j]; x:=i; y:=j; end;

writeln(f2,z);

Afisare(n,m);

close(f1); close(f2);
end.
