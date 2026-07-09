var a,b,t,r,i,aux:longint;
        fin,fout:text;

BEGIN
        assign(fin,'euclid2.in');
        reset(fin);

        assign(fout,'euclid2.out');
        rewrite(fout);

        readln(fin,t);

        writeln(t);
        for i:=1 to t do
                begin
                        readln(fin,a,b);

                        if b>a then
                                begin
                                        aux:=a;
                                        a:=b;
                                        b:=aux;
                                end;

                        repeat
                                r:=a mod b;
                                a:=b;
                                b:=r;
                        until r=0;
                        writeln(a)
                end;


        close(fin);
        close(fout);

END.
