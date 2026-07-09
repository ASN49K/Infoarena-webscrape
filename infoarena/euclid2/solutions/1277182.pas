Program euclid;


Var
        input, output   : Text;
        n, i, a, b: integer;

function euclid(a, b: integer): integer;
begin
        if b = 0
        then euclid := 0
        else euclid := euclid(b, a mod b);
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
