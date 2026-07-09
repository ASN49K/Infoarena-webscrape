var f,g:text;
    m,n,i,j,aux:integer;
    s:array[0..1024,0..1024]of int64;
    a,b,c:array[1..1024]of integer;
begin
assign(f,'cmlsc.in');reset(f);assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do
  begin
    read(f,b[i]);
    for j:=1 to n do
        if a[j]=b[i] then s[i,j]:=s[i-1,j-1]+1
                     else if s[i-1,j]>s[i,j-1] then s[i,j]:=s[i-1,j]
                                               else s[i,j]:=s[i,j-1];
  end;
writeln(g,s[m,n]); aux:=s[m,n]; i:=m;j:=n;
while (aux>0)or((j=0)and(i=0)) do
  begin
    while (s[i-1,j]=s[i,j])and(i>0) do i:=i-1;
    c[aux]:=b[i]; i:=i-1; aux:=aux-1;
    while (s[i,j-1]=s[i,j])and(j>0) do j:=j-1;
    c[aux]:=a[j]; j:=j-1; aux:=aux-1;
  end;
for j:=1 to s[m,n] do write(g,c[j],' ');
close(f);close(g);
end.
