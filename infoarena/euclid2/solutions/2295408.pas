program p1;
var fIn, fOut : textfile;
    t, a, b, d, i: integer;
begin
    assign(fin, 'euclid2.in');
    assign(fout, 'euclid2.out');
    reset(fin);
    rewrite(fout);
    readln(fin, t);
    for i := 1 to t do
    begin
       read(fin, a);
       readln(fin, b);

       if (a < 0) then a := -a;
       if (b < 0) then b := -b;
       while not (a = b) do
       begin
          if (a > b) then a := a - b
                     else b := b - a;
       end;
       d := a;
       writeln(fout, d);
    end;

    close(fin);
    close(fout);
end.