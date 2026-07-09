var a,b,nr,i,x,k:longint;f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,k);
for i:=1 to k do begin
readln(f,a,b);
if a<b then nr:=a else nr:=b;
for i:=1 to nr do
if (a mod i=0) and (b mod i=0) then x:=i;
writeln(g,x);end;
close(g);
end.
