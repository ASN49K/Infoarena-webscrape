var f,g:text;
    m,n,i,j:integer;
    s:array[0..1024,0..1024]of integer;
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
writeln(g,s[m,n]); i:=0;
for j:=n-1 downto 1 do
  if s[m,j]<s[m,j+1] then begin i:=i+1; c[i]:=a[j+1]; end;
for j:=i downto 1 do write(g,c[j],' ');
close(f);close(g);
end.