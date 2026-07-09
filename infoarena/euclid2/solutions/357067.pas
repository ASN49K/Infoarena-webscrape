var a,b,r,t,i:integer;
    in,out:text;
begin
assign(in,'euclid2.in'); reset(in);
assign(out,'euclid2.out'); rewrite(out);
readln(in,t);
for i:=1 to t do begin
 readln(in,a,b);
 while b <> 0 do begin
 r:= a mod b;
 a:=b;
 b:=r;
 end;
writeln(out,a);
end;
close(in); close(out);
end.
