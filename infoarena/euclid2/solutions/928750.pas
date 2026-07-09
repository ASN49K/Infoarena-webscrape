program eficient;
var t,i:longint;
a,b,c:longint;
f,g:text;
begin
 assign(f,'euclid2.in');reset(f);
 assign(g,'euclid2.out');rewrite(g);
 readln(f,t);
 for i:=1 to t do
        begin
        readln(f,a,b);
        c:=a mod b;
        while c<>0 do
                begin
                a:=b;
                b:=c;
                c:=a mod b;
                end;
        writeln(g,b);
        end;
close(f);close(g);
end.
