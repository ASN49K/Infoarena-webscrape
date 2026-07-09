var f,g:text;
    n,i:longint;
    a,b:int64;
 begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 reset(f);
 rewrite(g);
 read(f,n);
 for I:=1 to n do
 begin
 read(f,a);
 read(f,b);
while a<>b do
begin
if a>b then a:=a mod b
else b:=b mod a;
end;
writeln(g,a);
end;

 close(f);
 close(g);
 end.