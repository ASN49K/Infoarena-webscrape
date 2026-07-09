var a,b:integer;
f,g:text;
function cm(a,b:integer):integer;
begin
if a mod b =0 then cm:=b else cm:=cm(b, a mod b);
end;

begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a,b);
writeln(g,cm(a,b));
close(f);close(g);
end.