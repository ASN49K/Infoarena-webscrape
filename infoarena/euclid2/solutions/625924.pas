var
        f, g : text;
        i, a, b : longint;
        n : 1..100000;

function lnko(a, b : longint) : longint;
var
        mar : longint;
begin
        mar := a mod b;
        while mar > 0 do
                begin
                a := b;
                b := mar;
                mar := a mod b;
                end;
        lnko := b;
end;

begin
        assign(f,'euclid2.in');
        reset(f);
        assign(g,'euclid2.out');
        rewrite(g);
        readln(f,n);
        for i := 1 to n do
                begin
                readln(f,a,b);
                writeln(g,lnko(a,b));
                end;
        close(g);
end.