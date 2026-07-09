var n,i,a,b,r:integer;
begin
 assign(input,'euclid2.in');
 reset(input);
 assign(output,'euclid2.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
 begin
 readln(a,b);
 while b<>0 do begin
 r:=b;
 b:=a mod b;
 a:=r;
 end;
 writeln(a);
 end;
 close(input);
 close(output);
end.