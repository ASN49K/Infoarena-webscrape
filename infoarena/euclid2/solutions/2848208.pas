Program euclid;
var m, i, a, b, r, n : integer;
    fout, fin : text;

function solve(a : integer; b : integer) : integer;

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

    Readln(n);

    for i:=1 to n do begin

        Readln(a, b);

        r:= solve(a, b);

        Writeln(fout, r);

    end;

    Close(fin);
    Close(fout);

end.