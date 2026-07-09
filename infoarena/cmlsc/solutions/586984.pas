Program Subsir;
uses crt;
type Matrix= array[1..100,1..100] of integer;
     MatrixB= array[1..100,1..100] of boolean;
     Vector= array[1..1000] of integer;
var D:Matrix; B:MatrixB;
    T,S,C:Vector;
    k,n,m,i,j,x,y,z:integer;
    f1,f2:text;

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
  if T[i]=S[j] then begin D[i,j]:=D[i-1,j-1]+1; B[i,j]:=True; end
               else
                   if D[i-1,j]>D[i,j-1] then
                                             D[i,j]:=D[i-1,j]
                                         else
                                             D[i,j]:=D[i,j-1];
z:=D[1,1];
for i:=1 to n do
 for j:=1 to m do
    if D[i,j]>=z then begin z:=D[i,j]; x:=i; y:=j; end;

k:=z;
write(f2,z,' ');
while D[x,y]<>0 do
 begin
  if B[x,y] then C[k]:=S[Y];
  dec(x); dec(y); dec(k);
 end;

for i:=1 to z do
 write(f2,C[i],' ');

for i:=1 to n do
 begin
  for j:=1 to m do
   write(f2,D[i,j],' ');
  writeln(f2);
 end;


 close(f1); close(f2);
end.
