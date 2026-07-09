var a,b,d:array[1..1025] of longint;
c:array[1..1025,1..1025] of integer; {o}
f,g:text;
i,j,nr,n,m,h:longint;
function max(x,y:longint):longint;
begin
if x>y then max:=x
       else max:=y;
end;
procedure scrie;
begin
assign(f,'cmlsc.out');rewrite(f);
writeln(f,nr);
for i:=nr downto 1 do
    write(f,d[i],' ');
close(f);
end;
procedure citire;
begin
assign(f,'cmlsc.in');reset(f);
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
close(f);
end;
begin
citire;
for i:=1 to n do
    for j:=1 to m do
        if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
                     else c[i,j]:=max(c[i,j-1],c[i-1,j]);
i:=n; j:=m;
nr:=0;
while c[i,j]<>0 do
      begin
        if a[i]=b[j] then
           begin
           inc(nr);
           d[nr]:=a[i];
           dec(i); dec(j);
           end
        else
            if c[i,j-1]<=c[i-1,j] then dec(i)
                                  else dec(j);
      end;
scrie;
end.