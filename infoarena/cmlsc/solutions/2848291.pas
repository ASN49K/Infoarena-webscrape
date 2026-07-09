Program lcs;

const MAX = 1024;

type intarr = array of integer;

var m, n, i : integer;
    a, b, r : array of integer;
    fout, fin : text;

function solve(a : array of integer; b : array of integer; m : integer; n : integer): intarr;
var t, d : array of integer;

begin

    if (m = 0) or (n = 0) then
    begin
        SetLength(solve, 0);
        Exit;
    end
    else if a[m-1] = b[n-1] then
    begin
        solve:= solve(a, b, m-1, n-1);

        SetLength(solve, Length(solve) + 1);
        solve[Length(solve)-1] := a[m-1];

        Exit();

    end
    else begin
        t:= solve(a, b, m-1, n);
        d:= solve(a, b, m, n-1);

        if length(t) > Length(d) then solve:= t
        else solve:= d;

        Exit();

    end;

end;


begin
    Assign(fin, 'cmlsc.in');
    Assign(fout, 'cmlsc.out');
    Reset(fin);
    Rewrite(fout);

    Readln(fin, m, n);

    SetLength(a, m);
    SetLength(b, n);

    for i:= 0 to m-1 do Read(fin, a[i]);
    for i:= 0 to n-1 do Read(fin, b[i]);

    r:= solve(a, b, m, n);

    Writeln(fout, Length(r));

    for i:=0 to Length(r)-1 do Write(fout, r[i], ' ');

    Close(fin);
    Close(fout);
end.