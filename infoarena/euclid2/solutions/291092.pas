var i,a,b,n:word;
f,g:text; aa,bb:array[1..10000] of word;
begin
assign(f,'euclid2.in');reset(f);
readln(f,n);
assign(g,'euclid2.out');rewrite(g);
for i:=1 to n do begin
    read(f,a); readln(f,b);
while a<>b do
      if a>b then a:=a-b
             else b:=b-a;
writeln(g,a) end; close(g); end.

