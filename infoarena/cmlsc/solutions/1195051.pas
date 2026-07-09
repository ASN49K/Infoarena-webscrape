Program ex;
Type vector=array [1..1024] of integer;
var a,b,c,r:vector;
    k,d,max,p2,p,n,m,i,j:integer;
    f,g:text;
procedure regasire(p1,x:integer;var j:integer);
 var i:integer;
 begin
 j:=0;
 i:=p1;
 while (i<=n) and (j=0) do begin
  if b[i]=x then j:=i;
  i:=i+1;
  end;
 end;
begin
assign (f,'cmlsc.in');
reset(f);
readln (f,m,n);
for i:=1 to m do read(f,a[i]);
for i:=1 to n do read(f,b[i]);
for j:=1 to m do begin
d:=0;
p:=1;
for i:=j to m do begin
 regasire(p,a[i],p2);
 if p2>=p then begin
  d:=d+1;
  c[d]:=a[i];
  p:=p2+1;
  end;
 if d>max then begin
  max:=d;
  for k:=1 to d do r[k]:=c[k];
  end;
 end;
end;
assign (g,'cmlsc.out');
rewrite (g);
writeln(g,max);
for i:=1 to max do write (g,r[i],' ');
close(f);
close(g);
readln;
end.

