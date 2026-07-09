program sad;
type vec=array [1..1024] of integer;
var a,b,c:vec;
n,m,i,j,q,p:integer;
f,g:text;
begin
assign(f,'cmlsc.in');
reset (f);
assign (g,'cmlsc.out');
rewrite (g);
readln (f,n,m);
for i:=1 to n do read (f,a[i]);
readln (f);
for j:=1 to m do read (f,b[j]);
p:=0;
for j:=1 to m do begin
for i:=1 to n do if b[j]=a[i] then begin p:=p+1;
                                         c[p]:=a[i];
                                         end;
                                         end;
writeln (g,p);
for i:=1 to p do write (g,c[i],' ');
close (f);
close (g);
end.

