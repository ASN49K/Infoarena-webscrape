Program euclid;
var m, i, a, b, r, n : longint;
    fout, fin : text;

function solve(a : integer; b : integer) : longint;

begin

    while a <> b do begin
        if a > b then a:= a - b
        else if a < b then b:= b - a;
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
