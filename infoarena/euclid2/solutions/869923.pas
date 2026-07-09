var a,b:longint;f,g:text;
Function c(a,b:longint):longint;
begin
If b<=0 then
c:=a
else
If (a>b) then
c:=c(b,a mod b)
else
c:=c(a,b mod a);
end;
Begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,a);
repeat
readln(f,a,b);
writeln(g,c(a,b));
until eof(f);
close(f);
close(g);
end.
