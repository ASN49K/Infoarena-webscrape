Program euclid2;
   var a,b,t,d,r :integer;
       i:word;
       fi,fo:text;
begin
    assign (fi, 'euclid2.in');
    assign (fo, 'euclid2.out');
    reset(fi);
    rewrite(fo);

    readln(fi,t);
    for i:=1 to t do begin
    read (fi,a); readln (fi,b);


    while (b<>0) do begin
    r:=a mod b;
    a:=b;
    b:=r;
    end;
    d:=a;

    writeln(fo,d);
    end;
    close(fo);
    end.


