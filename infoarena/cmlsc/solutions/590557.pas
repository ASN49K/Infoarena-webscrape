uses crt;
type Matrice = array[1..1024,1..1024] of integer;
     Vector = array[1..1024] of integer;
var D,B:Matrice;
    T,S,C:Vector;
    k,n,m,i,j,x,y,z:integer;
    f,g:text;

Procedure Scrie(i,j:integer ) ;
 begin
 if B[i,j]=1 then begin Scrie(i-1,j-1); write(g,T[i],' '); end
             else
                 if B[i,j]=2 then Scrie(i-1,j)
                             else
                                 if B[i,j]=3 then Scrie(i,j-1);
 end;

begin
clrscr;
assign(f,'cmlsc.in'); reset(f);
assign(g,'cmlsc.out'); rewrite(g);
readln(f,n,m);
for i:=0 to n+1 do
 for j:=0 to m+1 do
  D[i,j]:=0;

for i:=1 to n do
 read(f,T[i]);
for i:=1 to m do
 read(f,S[i]);

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
writeln(g,z);
Scrie(n,m);
close(f);
close(g);
end.

