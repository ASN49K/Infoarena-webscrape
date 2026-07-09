type matrice=array[0..100,0..100] of word;
     vector=array[1..100000] of word;
var f,f1:text; s,s1,sir:string; i,j,x,y,k,k1:longint;  a:matrice; v,v1,v2:vector;
procedure citire(var v,v1:vector; var x,y:longint);
var i:word;
begin
assign(f,'cmlsc.in'); reset(f);
readln(f,x,y);
for i:=1 to x do read(f,v[i]);
readln(f);
for i:=1 to y do read(f,v1[i]); close(f);
end;
function max(a,b:word):word;
begin
if a>b then max:=a else max:=b; end;
procedure construire(i,j:integer);
begin
if a[i,j]>=1 then begin
  if v[i]=v1[j] then begin v2[k]:=v[i]; k:=k-1; construire(i-1,j-1); end
                else if a[i-1,j]=a[i,j] then construire(i-1,j)
                                 else if a[i,j-1] = a[i,j] then construire(i,j-1); end;

end;
begin
assign(f1,'cmlsc.out'); rewrite(f1);
citire(v,v1,x,y);
for i:=1 to x do
for j:=1 to y do
if v[i]=v1[j] then a[i,j]:=a[i-1,j-1]+1 else a[i,j]:=max(a[i-1,j],a[i,j-1]);
k:=a[x,y];
construire(x,y);
for i:=1 to a[x,y] do
write(f1,v2[i],' ');
close(f1);
end.

