program euclid;
var f,g:text;
    n,i:byte;
    a,b,d:longint;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do begin
readln(f,a,b);
while a mod b<>0 do begin
d:=a mod b;
a:=b;
b:=d;
                     end;
writeln(g,b);
                 end;
close(f);
close(g);
end.