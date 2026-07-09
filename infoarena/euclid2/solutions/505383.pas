var cmmdc,n1,n2,t,i:longint;
f,g:text;
begin
assign(f,'euclid2.in');
reset(f);
assign(g,'euclid2.out');
rewrite(g);
readln(f,t);
for i:=1 to t do begin
   readln(f,n1,n2);
while n1<>n2 do if n1>n2 then n1:=n1-n2
else n2:=n2-n1;
cmmdc:=n1;
writeln(g,cmmdc);
n1:=1;
n2:=2;
end;
      close(f);
close(g);

end.