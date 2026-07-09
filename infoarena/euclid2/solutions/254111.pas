var a,b,nr,i,x:longint;f,g:text;
begin
assign(f,'cmmdc.in');reset(f);
assign(g,'cmmdc.out');rewrite(g);
readln(f,k);
for i:=1 to k do begin
readln(f,a,b);
if a<b then nr:=a else nr:=b;
for i:=1 to nr do
if (a mod i=0) and (b mod i=0) then x:=i;
writeln(g,x);
close(g);
end.
