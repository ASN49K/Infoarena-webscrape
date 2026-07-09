program subsir;
type vector=array [1..20] of integer;
var f,g:text;
    a,b:vector;
    nr,k,n,m,i,j:integer;
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
assign (f,'cmlsc.in');
reset (f);
assign (g,'cmlsc.out');
rewrite (g);
readln(f,n,m);
for i:=1 to n do read(f,a[i]);
readln(f);
for i:=1 to m do read(f,b[i]);
k:=0;
for i:=1 to n do if este(b,a[i],m)>k then begin
 nr:=nr+1;
 k:=este(b,a[i],m);
 end;
k:=0;
write (g,nr);
for i:=1 to n do if este(b,a[i],m)>k then begin
 write (g,a[i],' ');
 k:=este(b,a[i],m);
 end;
readln;
close(f);
close(g);
end.
