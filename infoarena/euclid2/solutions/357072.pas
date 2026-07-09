var a,b,r,t,i:integer;
    inn,outt:text;
begin
assign(inn,'euclid2.in'); reset(inn);
assign(outt,'euclid2.out'); rewrite(outt);
readln(inn,t);
for i:=1 to t do begin
 readln(inn,a,b);
 while b <> 0 do begin
 r:= a mod b;
 a:=b;
 b:=r;
 end;
writeln(outt,a);
end;
close(inn); close(outt);
end.

