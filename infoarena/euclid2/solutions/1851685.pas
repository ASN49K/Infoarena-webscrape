Program euclid2;
   var a,b,r:int64;
       i:longint;
       t:word;
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

    writeln(fo,a);
    end;
    close(fo);
    end.


