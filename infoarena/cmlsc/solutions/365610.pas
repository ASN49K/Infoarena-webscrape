program subsir_maxim;
var j,i,n,m,x:longint;
   a,b:array [1..1025] of longint;
   s:string;
   f,g:text;
   begin
assign(f,'cmlsc.in');
reset(f);
read(n);
readln(m);
for i:= 1 to n do
        read(f,a[i]);
readln(f);
for i:=1 to m do
        read(f,b[i]);
for i:= 1 to n do
  begin
  for  j:= 1 to m do
  if a [i]=b[j]  then s:=s+' '+'a[i]';
  end;
x:=length(s) mod 2+1;
assign(g,'cmlsc.out');
rewrite(g);
writeln(g,x);
write(g,s);
close(G);
end.
