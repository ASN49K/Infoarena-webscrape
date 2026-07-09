var a,b,x,i:integer;
    f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,x);
for i:=1 to x do
begin
           readln(f,a,b);
           while a<>b do
                 if a>b then
                    a:=a-b
                 else
                     b:=b-a;
           writeln(g,a);
end;
close(f);
close(g);
readln;
end.