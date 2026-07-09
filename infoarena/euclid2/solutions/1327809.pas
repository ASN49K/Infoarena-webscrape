var i,j,m,n,max,c,min,k,p,o,aux,aux1:integer;
    a,b,v:array[1..20] of integer;
    f,g:text;
begin
aux:=0;
aux1:=0;
min:=maxint;
max:=-maxint;
o:=1;
assign(f,'date.in');reset(f);
assign(g,'date.out');rewrite(g);
readln(f,n,m);
for i:=1 to n do
read(f,a[i]);
for i:=1 to m do
read(f,b[i]);

for i:=1 to n-1 do
for j:=i+1 to n do
if a[i]>a[j] then begin aux:=a[i];
                        a[i]:=a[j];
                        a[j]:=aux;
                        end;
for i:=1 to m-1 do
for j:=i+1 to m do
if b[i]>b[j] then begin aux:=b[i];
                        b[i]:=b[j];
                        b[j]:=aux;
                        end;
for i:=1 to n do
for j:=1 to m do begin
if a[i]=b[j] then if a[i]<min then min:=a[i];
end;
for i:=n downto 1 do
for j:=m downto 1 do begin
if a[i]=b[j] then if a[i]>max then max:=a[i];
end;
for i:=1 to n do
if (a[i]>=min)and(a[i]<=max) then inc(o);
for j:=1 to m do
if (b[j]>=min)and(b[j]<=max) then inc(p);
if n-p=m-o then c:=0;
if n-p>m-o then c:=1
           else c:=2;
write(g,min,' ',max,' ',c);
close(g);
close(f);
readln;
end.