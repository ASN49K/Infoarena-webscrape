Program euclid;
var f,q:text;
t,a,b,i:integer;
begin
assign(f,'euclid.in');
reset(f);
assign(q,'euclid.out');
rewrite(q);
read(f,t);
i:=1;
        while i<=t do begin
        read (f,a,b);
                while a<>b do begin
                if a>b then a:=a-b
                        else b:=b-a;
                end;
                writeln(q,a);
        writeln;
        i:=i+1;
        end;
close(f);
close(q);
end.