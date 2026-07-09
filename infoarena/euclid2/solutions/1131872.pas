
var
i,n,a,b,aux:longint;
f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
readln(f,n);
assign(g,'euclid2.out');
rewrite(g);
for i:=1 to n do
               begin
                read(f,a,b);
                while a mod b<>0 do
                           begin
                           aux:=a;
                           a:=b;
                           b:=aux mod b;
                           end;
                writeln(g,b);
                end;
close(g);
close(f);
end.