program subsir_max_comun;
var m,n,i,z,j:word;
    a:array[1..32000] of integer;
    b:array[1..1024] of integer;
    f,g:Text;
    ok:boolean;
begin
assign(f,'cmlsc.in');
reset(f);
assign(g,'cmlsc.out');
rewrite(g);
read(f,m);
readln(f,n);
for i:=1 to m do read(f,a[i]);
i:=0;
z:=0;
readln(f);
repeat
i:=i+1;
z:=z+1;
ok:=false;
  read(f,b[i]);
   for j:=1 to m do
    if b[i]=a[j] then ok:=true;
if ok=false then i:=i-1;
until z=n;
writeln(g,i);
for j:=1 to i do
 write(g,b[j],' ');
close(f);
close(g);
readln;
end.