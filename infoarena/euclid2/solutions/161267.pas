var a,b,cmmdc,t:integer;
    f,g:text;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out');rewrite(g);
readln(f,t);
readln(f,a,b);
while a<>b do begin
 if a>b then a:=a-b
    else b:=b-a;
end;
cmmdc:=a;
  if (a=1) and (b=1) then
  writeln(g,0)
   else writeln(g,cmmdc);
close(f);
close(g);
end.