var max2,l,max,i,j,m,n:integer;
    rst,st,a,b,p:array[1..1024] of integer;
    f,g:text;
procedure load;
begin
assign(f,'cmlsc.in');
reset(f);
readln(f,m,n);
max:=n;
if max<m then max:=m;
for i:=1 to m do
read(f,a[i]);
readln(f);
for i:=1 to n do
read(f,b[i]);
close(f);
assign(g,'cmlsc.out');
rewrite(g);
end;
procedure init_p;
var i:integer;
begin
for i:=1 to max do
p[i]:=0;
end;
function valid(x:integer):boolean;
var ok:boolean;
    i:integer;
begin
ok:=true;
for i:=1 to l do
if x<p[i] then ok:=false;
valid:=ok;
end;

BEGIN
load;
init_p;
l:=1;max2:=-1;
for i:=1 to m do
begin
j:=1;
while (a[i]<>b[j]) and (j<=n) do
j:=j+1;
if (a[i]=b[j]) and (valid(i)) then
begin
st[l]:=a[i];
p[l]:=i;
l:=l+1;

if max2<l-1 then
begin
 max2:=l-1;
 rst:=st;
end;

end;

end;
writeln(g,max2);
for i:=1 to max2 do
writE(g,rst[i],' ');
close(g);
END.