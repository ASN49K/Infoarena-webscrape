var a,b,t:int64;
i,n:longint;
f1,f2:text;
begin
assign(f1,'euclid2.in');
assign(f2,'euclid2.out');
reset(f1);rewrite(f2);
readln(f1,n);

for i:=1 to n do
        begin
        read(f1,a,b);
        t:=a mod b;
        while t>0 do
                begin
                a:=b;
                b:=t;
                t:=a mod b;
                end;
        writeln(f2,b)
        end;

close(f1);close(f2);
end.
