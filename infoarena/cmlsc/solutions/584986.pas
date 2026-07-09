var f,g:text;
    a,b,c:array[1..20] of integer;
    i,j,m,n,t:integer;
begin
assign(f,'nr.in');reset(f);
assign(g,'nr.out');rewrite(g);
read(f,m,m);
for i:=1 to m do
read(f,a[i]);
readln(f);
for i:=1 to n do
read(f,b[i]);
for i:=1 to n do begin
for j:=1 to m do
if a[i]=a[j] then begin
                   t:=t+1;
                   c[t]:=a[i];
                   end;
                   end;
writeln(g,t);
for i:=1 to t do
write(g,c[i],' ');
close(f);
close(g);
end.