var a,b,cmmdc,t,i:integer;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
for i:=1 to t do  begin
 readln(f,a,b);
  while a<>b do begin
 if a>b then a:=a-b
    else b:=b-a;
end;
cmmdc:=a;
writeln(g,cmmdc);
end;
close(f);
close(g);
end.