var n,i,a,b,r:longint;
begin
 assign(input,'euclid2.in');
 reset(input);
 assign(output,'euclid2.out');
 rewrite(output);
 readln(n);
 for i:=1 to n do
 begin
 readln(a,b);
 while a<>b do begin
 if a>b then a:=a-b
        else b:=b-a;
 end;
 writeln(a);
 end;
 close(input);
 close(output);
end.