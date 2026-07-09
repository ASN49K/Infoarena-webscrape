Program euclid;


Var
        input, output   : Text;
        n, i, a, b: integer;

function euclid(a, b: integer): integer;
var
        c: integer;
begin
        while (b <> 0) do begin
                c := a mod b;
                a := b;
                b := c;
        end;
        euclid := a;
end;

BEGIN
        Assign(input, 'euclid2.in'); Assign(output, 'euclid2.out');
        Reset(input); Rewrite(output);
                Read(input, n);
                for i := 1 to n do
                begin
                        Read(input, a); Read(input, b);
                        Writeln(output, euclid(a, b));
                end;
        Close(input); Close(output);
END.