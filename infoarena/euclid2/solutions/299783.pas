program cmmdc;
var f,g:text;
    n,i:integer;
    a,b:integer;
begin
assign(f,'euclid2.in'); reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,n);
for i:=1 to n do
    begin
    read(f,a);
    readln(f,b);
    while a<>b do
          begin
          if a>b then
             a:=a-b
          else
              b:=b-a;
          writeln(g,a);
          end;
    end;
close(f); close(g);
end.