var
        f, g : text;
        n, i, a, b : longint;

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
        for i := 1 to n-1 do
                begin
                readln(f,a,b);
                write(g,lnko(a,b),#10#13);
                end;
        readln(f,a,b);
        write(g,lnko(a,b));
        close(g);
end.