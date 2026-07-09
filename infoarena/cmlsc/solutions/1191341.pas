program subsir;
type vector=array [1..10] of byte;
var t,g:text;
    a,b,c,f:vector;
    d,max,z,j,nr,k,n,m,i:integer;
function este(v:vector;x,n:integer):integer;
 var i:integer;
 begin
 i:=1;
 este:=0;
 while i<=n do if v[i]=x then begin
  este:=i;
  i:=n+1;
  end
  else i:=i+1;
 end;
begin
assign (t,'cmlsc.in');
reset (t);
assign (g,'cmlsc.out');
rewrite (g);
readln(t,n,m);
for i:=1 to n do read(t,a[i]);
readln(t);
for i:=1 to m do read(t,b[i]);
max:=-maxint;
for j:=1 to n do begin
 k:=0;
 d:=0;
for i:=j to n do if este(b,a[i],m)>k then begin
 d:=d+1;
 c[d]:=a[i];
 k:=este(b,a[i],m);
 end;
if d>max then begin
 for z:=1 to d do f[z]:=c[z];
 max:=d;
 end;
 end;
writeln(g,max);
for i:=1 to max do write (g,f[i]);
readln;
close(t);
close(g);
end.
