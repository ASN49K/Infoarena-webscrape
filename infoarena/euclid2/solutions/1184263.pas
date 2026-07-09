program cmmdc;
var a,b:longint; i,n:word; f,g:text;

function cm(a,b:longint):longint;
begin
if b=0 then cm:=a
else cm:=cm(b,a mod b);
end;

begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
        begin
        readln(f,a,b);
        writeln(g,cm(a,b));
        end;
close(f); close(g);
end.