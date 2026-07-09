var f,g:text;
    a,b,d:array[0..1024] of longint;
    c:array[0..1024,0..1024] of integer;
    i,j,nr,n,m,h:longint;
function max(x,y:longint):longint;
 begin
 if x>y then max:=x else max:=y;
 end;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
for i:=1 to n do
 for j:=1 to m do
  if a[i]=b[j] then begin
   c[i,j]:=c[i-1,j-1]+1;
  end
   else c[i,j]:=max(c[i,j-1],c[i-1,j]);
i:=n;
j:=m;
nr:=0;
while c[i,j]<>0 do begin
 if a[i]=b[j] then begin
  inc(nr);
  d[nr]:=a[i];
  dec(i);
  dec(j);
 end
  else
 if c[i,j-1]<=c[i-1,j] then dec(i)
  else
 dec(j);
end;
writeln(g,nr);
for i:=nr downto 1 do write(g,d[i],' ');
close(f);
close(g);
end.
