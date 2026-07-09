program cel_mai_lung_subsir_comun;
var f,g:text;
    a,b:array[1..1024] of integer;
{    sol,}s,c:array[1..1024] of record
                          x,y:integer;
                          end;
    n,m,nr,lmax,i,j,p1,p2,nrr:integer;
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
p1:=0;
p2:=0;
for i:=1 to n do
  for j:=1 to m do
    if a[i]=b[j] then begin
      x[i,j]:=x[i-1,j-1]+1;
      if x[i,j]>lmax then begin
        lmax:=x[i,j];
        p1:=i;
        p2:=j;
        end;
      if x[i,j]=x[i-1,j-1]+1 then begin
      inc(nr);
      c[nr].x:=i; c[nr].y:=j;
      end;
      end
    else
      x[i,j]:=max(x[i-1,j],x[i,j-1]);
end;

{procedure subsir(k:integer);
var i,j:integer;
begin
if k>lmax then s:=sol
else
  for i:=sol[k-1].x downto 1 do
    for j:=sol[k-1].y downto 1 do
      if (x[i,j]=nrr) and (x[i-1,j-1]=nrr-1) and (x[i-1,j]=nrr-1) and (x[i,j-1]=nrr-1) then begin
        sol[k].x:=i;
        sol[k].y:=j;
        nrr:=nrr-1;
        subsir(k+1);
        nrr:=nrr+1;
        end;
end; }

procedure scriere;
var i:integer;
begin
writeln(g,lmax);
s[lmax].x:=p1;
s[lmax].y:=p2;
nrr:=lmax-1;
for i:=nr-1 downto 1 do
  if (x[c[i].x,c[i].y]=nrr) and (c[i].x<s[nrr+1].x) and (c[i].y<s[nrr+1].y) then begin
    s[nrr].x:=c[i].x;
    s[nrr].y:=c[i].y;
    dec(nrr);
    end;
for i:=1 to lmax do write(g,a[s[i].x],' ');
end;

begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f);
rewrite(g);
citire;
solve;
{sol[1].x:=p1;
sol[1].y:=p2;
nrr:=lmax-1;
subsir(2);
for i:=1 to n do begin
  for j:=1 to m do write(g,x[i,j],' ');
  writeln(g);
  end;}
scriere;
close(f);
close(g);
end.
