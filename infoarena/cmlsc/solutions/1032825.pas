var a,b,c,d:array[1..1024] of integer;
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
      if a[i]=b[j] then
        begin
          c[j]:=1;
          for k:=1 to j-1 do
            if c[k]>max then max:=c[k];
        end;
     c[j]:=c[j]+max;
     if c[j]>aux then aux:=c[j];
      max:=0;
    end;

if n>m then max:=n else max:=n;

writeln(g,aux);
aux1:=aux;
while aux>0 do
begin
for i:=max downto 1 do
if c[i]=aux then begin d[aux]:=b[i];aux:=aux-1;end;
end;

for i:=1 to aux1 do
write(g,d[i],' ');
close(f);close(g);
end.