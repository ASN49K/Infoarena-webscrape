var a,b,n,i:longint;f,g:text;
Function c(a,b:longint):longint;
begin
If b<=0 then
c:=a
else
c:=c(b,a mod b);
end;
Begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,n);
For i:=1 to n do
Begin
readln(f,a,b);
writeln(g,c(a,b));
end;
close(f);
close(g);
end.
