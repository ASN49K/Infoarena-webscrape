var f,g:text;
    a,b,d:array[0..1024] of longint;
    c:array[0..1024,0..1024] of longint;
    i,j,nr,n,m:longint;
function max(x,y:longint):longint;
 begin
 if x>y then max:=x else max:=y;
 end;
begin
assign(f,'cmlsc.in');reset(f);
assign(g,'cmlsc.out');rewrite(g);
read(f,n,m);
for i:=1 to n do read(f,a[i]);
for i:=1 to m do read(f,b[i]);
nr:=0;
for i:=1 to n do
 for j:=1 to m do
  if a[i]=b[j] then begin
   c[i,j]:=c[i-1,j-1]+1;
   inc(nr);
   d[nr]:=i;
  end
   else c[i,j]:=max(c[i,j-1],c[i-1,j]);
writeln(g,nr);
for i:=1 to nr do write(g,a[d[i]],' ');
close(f);
close(g);
end.
