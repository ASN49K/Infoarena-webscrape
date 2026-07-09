var a,b:longint;f,g:text;

Function c(a,b:longint):longint;
begin
If a mod b = 0 then
c:=b
else
c:=c(b,a mod b);
end;

Begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a);

repeat
 readln(f,a,b);
 write(g,c(a,b),chr(10));
until eof(f);

close(f);
close(g);
end.
