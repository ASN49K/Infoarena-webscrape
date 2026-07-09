var n,m,i,j,k:longint;
a,b,c:array[1..1024] of integer;
f,g:text;
l:array[0..1024,0..1024] of byte;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for j:=1 to m do read(f,b[j]);
for i:=1 to m do
    for j:=1 to n do
              if  a[i]=b[j] then l[i,j]:=l[i-1,j-1]+1
                            else if l[i-1,j]>l[i,j-1] then l[i,j]:=l[i-1,j]
                                                      else l[i,j]:=l[i,j-1];
writeln(g,l[m,n]);
k:=0;
i:=m;
j:=n;
while (i<>0) and (j<>0) do begin
if a[i]=b[j] then begin
                  inc(k);
                  c[k]:=a[i];
                  dec(i);
                  dec(j);
                  end
              else if l[i,j]=l[i-1,j] then dec(i)
                                      else if l[i,j]=l[i,j-1] then dec(j);
end;
for i:=k downto 1 do
write(g,c[i],' ');
close(f);
close(g);
end.