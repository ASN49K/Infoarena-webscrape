program p1;
var fIn, fOut : textfile;
    t, a, b, d, i, aux: integer;
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

       while b<>0 do
       begin
          aux := b;
          b := a mod b;
          a := aux;
       end;
       d := a;

       writeln(fout, d);
    end;

    close(fin);
    close(fout);
end.