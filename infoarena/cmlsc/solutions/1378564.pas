program infoarena_cemls;
type vector=array[1..1024]of integer;
var n,m,k,p,k1,k2,j,i:integer; ams,ev:boolean; a,b,c:vector; st:vector; f,g:text;
begin
assign(f,'cmlsc.in');
assign(g,'cmlsc.out');
reset(f); rewrite(g);
readln(f,n,m);k:=1;
for i:= 1 to n do read(f,a[i]); readln(f);
for i:= 1 to m do read(f,b[i]);
k1:=0; k2:=0;
for i:= 1 to n do
 for j:= 1 to m do
  if a[i]=b[j] then
   if (i>k1)and(j>k2) then begin
   k1:=i; k2:=j; c[k]:=a[i]; k:=k+1;
   end;
  writeln(g,k-1);
  for i:= 1 to k-1 do write(g,c[i],' ');
  close(f); close(g);
end.