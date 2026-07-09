program cel_mai_lung_subsir_comun;
var f,g:text;
    a,b,c:array[1..1024] of integer;
    n,m,nr,lmax:integer;
    x:array[0..1024,0..1024] of integer;

procedure citire;
var i:integer;
begin
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
for i:=0 to n do x[i,0]:=0;
for i:=0 to m do x[1,i]:=0;
end;

function max(x,y:integer):integer;
begin
if x<y then max:=y else max:=x;
end;

procedure solve;
var i,j:integer;
begin
nr:=0;
lmax:=0;
for i:=1 to n do
  for j:=1 to m do
    if a[i]=b[j] then begin
      x[i,j]:=x[i-1,j-1]+1;
      if x[i,j]>lmax then lmax:=x[i,j];
      if x[i,j]>nr then begin
        inc(nr);
        c[nr]:=a[i];
        end;
      end
    else
      x[i,j]:=max(x[i-1,j],x[i,j-1]);
end;

procedure scriere;
var i:integer;
begin
writeln(g,nr);
for i:=1 to nr do write(g,c[i],' ');
end;

begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
citire;
solve;
scriere;
close(f);
close(g);
end.
