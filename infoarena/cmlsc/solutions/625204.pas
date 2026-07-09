program clmsc;
var a,b,k:array[1..1024] of integer;
    c:array[0..1024,0..1024] of integer;
    m,n:integer;
    fi,fo:text;
    i,j:integer;
function max(y,u:integer):integer;
begin
if y>u then max:=y else max:=u;
end;
begin
assign(fi,'clmsc.in');
reset(fi);
assign(fo,'clmsc.out');
rewrite(fo);
read(fi,m,n);
 for i:=1 to m do read(fi,a[i]);
 for i:=1 to n do read(fi,a[j]);
 for i:=1 to m do
  for j:=1 to n do c[i,j]:=0;
 for i:=1 to m do
 for j:=1 to n do
  if a[i]=b[j] then c[i,j]:=c[i-1,j-1]+1
               else c[i,j]:=max(c[i-1,j],c[i,j-1]);
 i:=m;j:=n;
 while c[i,j]<>0 do
  if a[i]=b[j] then begin
                      k[c[i,j]]:=k[i];
                      i:=i-1;j:=j-1;
                    end
               else if c[i-1,j]>c[i,j-1] then
                       i:=i-1
                                         else
                       j:=j-1;
 writeln(fo,c[m,n]);
 for i:=1 to c[m,n] do write(fo,k[i],' ');
 end.



