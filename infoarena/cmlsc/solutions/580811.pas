var a,b,sir:array[1..1024] of byte;
    sol:array[0..1024,0..1024]of integer;
    n,m:integer;
    f,g:text;
procedure citire;
var i,j:integer;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
end;

function max(a,b:integer):integer;
begin
if a>b then max:=a
                         else max:=b;
end;

procedure cmlsc;
var i,j,k:integer;
begin
for i:=0 to n do
 for j:=0 to m do sol[i,j]:=0;
for i:=1 to n do
 for j:=1 to m do
   if a[i]=b[j] then sol[i,j]:=sol[i-1,j-1]+1
                else sol[i,j]:=max(sol[i-1,j],sol[i,j-1]);
writeln(g,sol[n,m]);
i:=n;
j:=m;
k:=0;
while (i>0) and (j>0) do
   if a[i]=b[j] then begin
                     k:=k+1;
                     sir[k]:=a[i];
                     i:=i-1;
                     j:=j-1;
                     end
   else if sol[i,j]=sol[i-1,j] then i:=i-1
   else if sol[i,j]=sol[i,j-1] then j:=j-1;

for i:=k downto 1 do write(g,sir[i],' ');
end;

begin
citire;
cmlsc;
close(g);
end.
