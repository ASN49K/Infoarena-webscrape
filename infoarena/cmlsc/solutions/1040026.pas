program scmax;
var  a,b,k:array[0..2000] of byte;
     c:array[0..2000,0..2000] of byte;
    n,m,i,j:integer;

function max(w,q:integer):integer;
begin
if w>q then max:=w else max:=q;
end;

begin
assign(input,'cmlsc.in'); reset(input);
readln(n,m);
for i:=1 to n do read(a[i]);
readln;
for i:=1 to m do read(b[i]);
close(input);
assign(output,'cmlsc.out'); rewrite(output);
for i:=0 to n+1 do c[i,0]:=0;
for i:=0 to m+1 do c[0,i]:=0;
for i:=1 to n do
  for j:=1 to m do
     if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
        else c[i,j]:=max(c[i-1,j],c[i,j-1]);
writeln(c[n,m]);
j:=m; i:=n;
while c[i,j]<>0 do
  if a[i]=b[j] then  begin k[c[i,j]]:=a[i]; dec(i); dec(j); end
    else if c[i-1,j]>c[i,j-1] then dec(i) else dec(j);
for i:=1 to c[n,m] do write(k[i], ' ');
close(output);
end.

