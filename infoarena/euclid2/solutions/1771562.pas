var dc,t,a,b,i:integer;
f,fout:text;

begin
        assign(f,'euclid2.in') ;
        assign(fout,'euclid2.out');
        reset(f);
        rewrite(fout);
        readln(f,t);
        for i:=1 to t do begin
        readln(f,a,b);
        while a<>b do
        if a>b then a:=a-b else b:=b-a; dc:=a;
        writeln(fout,dc);end;
        close(f);
        close(fout);

end.