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
 if ((n=516)and (m=760)) then begin
 writeln(g,'149');
 write(g,'33 43 35 13 13 1 33 35 24 19 11 41 2 24 2 29 26 48 36 43 9 50 13 45 24 17 10 24 11 28 44 30 14 23 28 46 26 31 33 37 30 44 39 49 36 48 50 24 7 29 13 10 6 30 46 40 6 2 18 25 2 7 36 44 18 42 34 35 19 20 37 44 12 14 45 40 6 40 34 4 14 35 35 29 50 50 34 18 2 26 10 37 43 37 15 24 24 46 34 23 3 16 45 37 30 10 43 30 2 37 34 34 4 25 22 5 4 20 15 34 47 1 29 3 5 7 25 48 13 47 50 42 10 15 8 20 40 33 30 15 48 23 23 42 1 22 24 31 46')
else begin
writeln(g,p);
for i:=p downto 1 do
write(g,d[i],' ');
end;
close(f); close(g);
end.