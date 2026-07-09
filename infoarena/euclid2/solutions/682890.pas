Program euclid;
var f,q:text;
t,a,b,i,r:longint;
begin
assign(f,'euclid2.in');
reset(f);
assign(q,'euclid2.out');
rewrite(q);
read(f,t);
i:=1;
        while i<=t do begin
        read (f,a,b);
        repeat
        r:=a mod b;
        a:=b;
        b:=r;
        until r=0;
                writeln(q,a);
        writeln;
        i:=i+1;
        end;
close(f);
close(q);
end.
