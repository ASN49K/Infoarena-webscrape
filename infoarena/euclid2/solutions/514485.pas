program cmmdc;
var a,b:qword;
    t,i:longword;
    f,g:text;
function cmmdc(a,b:qword):qword;
begin
if a=b then cmmdc:=a
       else if a>b then
                   if a mod b=0 then cmmdc:=b
                                else cmmdc:=cmmdc(a mod b,b)
                   else
                   if b mod a=0 then cmmdc:=a
                                else cmmdc:=cmmdc(a,b mod a);
end;
begin
assign(f,'euclid2.in');reset(f);
assign(g,'euclid2.out'); rewrite(g);
readln(f,t);
for i:=1 to t do begin
readln(f,a,b);
writeln(g,cmmdc(a,b));
end;
close(g);
end.