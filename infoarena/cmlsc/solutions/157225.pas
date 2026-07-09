var i,j,m,n,p:longint;
a,b,d:array[1..1025] of longint;
c:array[1..1025,1..1025] of longint;
f,g:text;
procedure citire(var m,n:longint);
var i,j:longint;
begin
readln(f,m,n);
for i:=1 to m do
read(f,a[i]);
for j:=1 to n do
read(f,b[j]);
readln(f);
end;
function max(n,m:longint):longint;
begin
if n>m then max:=n
else max:=m;
end;
begin
assign(f,'cmlsc.in'); reset(f);
assign(g,'cmlsc.out'); rewrite(g);
citire(m,n);
for i:=1 to m do
  for j:=1 to n do
     if a[i]=b[j]
      then c[i,j]:=1+c[i-1,j-1]
      else c[i,j]:=max(c[i-1,j],c[i,j-1]);
i:=m; j:=n; p:=0;
 while (i*j>0) do
 if a[i]=b[j]then begin
                     inc(p);
                     d[p]:=a[i];
                     dec(i);
                     dec(j);
                  end
 else if c[i-1,j]<c[i,j-1] then dec(j)
 else dec(i);
writeln(g,p);
for i:=p downto 1 do
write(g,d[i],' ');
close(f); close(g);
end.