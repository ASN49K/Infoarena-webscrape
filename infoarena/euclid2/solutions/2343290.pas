program euclid2;

var     intrare,iesire:text;
        t:longint;
        a,b:longint;
        r,i,aux:longint;



BEGIN
        assign(intrare,'euclid2.in');
        reset(intrare);

        assign(iesire,'euclid2.out');
        rewrite(iesire);

        readln(intrare,t);

        for i:=1 to t do
                begin
                        readln(intrare,a,b);
                        repeat
                                if a<b then
                                        begin
                                                aux:=a;
                                                a:=b;
                                                b:=aux;
                                        end;
                                r:=a mod b;
                                a:=b;
                                b:=r;
                        until r=0;

                        writeln(iesire,a);
                end;

        close(intrare);
        close(iesire);
END.









END.
