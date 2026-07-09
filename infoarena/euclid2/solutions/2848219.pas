Program euclid;
var m, i, a, b, r, n : longint;
    fout, fin : text;

function solve(a : integer; b : integer) : longint;
var c : longint;
begin

    while b <> 0 do begin
        c:= a;
        a:= b;
        b:= c mod b;
    end;

    solve:= a;
end;


begin

    Assign(fin, 'euclid2.in');
    Assign(fout, 'euclid2.out');
    Reset(fin);
    Rewrite(fout);

    Readln(fin, n);

    for i:=1 to n do begin

        Readln(fin, a, b);

        r:= solve(a, b);

        Writeln(fout, r);

    end;

    Close(fin);
    Close(fout);

end.
