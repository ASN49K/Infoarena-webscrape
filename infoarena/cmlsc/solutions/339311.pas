var n,m,i,j,k:longint;
a,b,c:array[1..1024] of byte;
f,g:text;
v:array[0..1000,0..1000] of integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do
read(f,a[i]);
readln(f);
for j:=1 to m do
read(f,b[j]);
for i:=1 to n do
    for j:=1 to m do
              if  a[i]=b[j] then v[i,j]:=v[i-1,j-1]+1
                            else if v[i-1,j]>v[i,j-1] then v[i,j]:=v[i-1,j]
                                                      else v[i,j]:=v[i,j-1];
writeln(g,v[n,m]);
k:=0;
i:=n;
j:=m;
while (i<>0) and (j<>0) do begin
if a[i]=b[j] then begin
                  inc(k);
                  c[k]:=a[i];
                  dec(i);
                  dec(j);
                  end
              else if v[i,j]=v[i-1,j] then dec(i)
                                      else if v[i,j]=v[i,j-1] then dec(j);
end;
for i:=k downto 1 do
write(g,c[i],' ');
close(f);
close(g);
end.
