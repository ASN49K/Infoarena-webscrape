var f,g:text;
    a,b,v:array[0..1100]of integer;
    p:array[0..1100,0..1100]of integer;
    n,m,i,j,k:longint;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(G);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
for i:=1 to n do
  for j:=1 to m do
    if (a[i]=b[j])then
      p[i,j]:=1+p[i-1,j-1] else
      begin
        if (p[i-1,j]>p[i,j-1])then
          p[i,j]:=p[i-1,j] else
          p[i,j]:=p[i,j-1];
      end;
i:=n;
j:=m;
while (p[i,j]<>0)do
  begin
    if  (a[i]=b[j])then
      begin
        inc(k);
        v[k]:=a[i];
        dec(i);
        dec(j);
      end else
      begin
        if (p[i,j]=p[i-1,j])then
          dec(i) else
          dec(j);
      end;
  end;
writeln(g,p[n,m]);
for i:=k downto 1 do write(G,v[i],' ');
close(f);
close(g);
end.



