program subsir;
var a,b,v:array[1..25] of integer;
t,i,j,n,m,k,l,e,u:integer;
f,g:text;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
readln(f,n,m);
for i:=1 to n do
read(f,a[i]);
readln(f);
for i:=1 to m do
read(f,b[i]);
for i:=1 to n do
for j:=1 to m do
if  a[i]=b[j] then begin k:=i; l:=j;break;break; end;
for i:=n downto 1 do
for j:=m downto 1 do
if a[i]=b[j] then begin e:=i; u:=j; break;break; end;
if (k<>e)and(l<>u) then begin
for i:=k-1 to l do
for j:=e to u+1 do
if a[i]=b[j] then begin t:=t+1; v[t]:=a[i];end;end;
writeln(g,t);
for i:=1 to t do
write(g,v[i],' ');
close(f);
close(g);
end.
