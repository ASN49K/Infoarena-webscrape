var a,b:array[1..1024] of integer;
    c:array[0..100,0..100] of integer;
    m,n,i,j,k,max,aux,aux1:longint;
    f,g:text;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
readln(f,m,n);
for i:=1 to m do
read(f,a[i]);

for j:=1 to n do
read(f,b[j]);

for i:=1 to m do
  for j:=1 to n do
    begin
      if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
      else if c[i-1,j]>c[i,j-1] then c[i,j]:=c[i-1,j] else c[i,j]:=c[i,j-1];
      if c[i,j]>max then max:=c[i,j];
    end;

writeln(g,max);
k:=1;
for i:=1 to m do
for j:=1 to n do
if c[i,j]=k then begin write(g,a[i],' ');k:=k+1;end;



close(f);close(g);
end.