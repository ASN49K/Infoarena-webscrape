program euclid_pt_cmmdc;
var a,b,c,n,i :longint;
        f,g:text;

BEGIN
assign(f,'euclid2.in');
assign(g,'euclid2.out');
reset(f);
rewrite(g);
readln(f,n);
for i:=1 to n do
        BEGIN
                readln(f,a,b);
                if b>a then
                        begin
                                c:=a;
                                a:=b;
                                b:=c;
                        end;
                c:=1;
                while c<>0 do
                        begin
                                c:= a mod b;
                                a:=b;
                                b:=c;
                        end;
                writeln(g,a);
        END;
close(f);
close(g);
end.