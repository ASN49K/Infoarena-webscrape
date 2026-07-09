program euclid2;

var     intrare,iesire:text;
        t:longint;
        a,b:longint;
        r,i,aux:longint;

        x,y:longint;
        d:longint;


BEGIN
        assign(intrare,'euclid2.in');
        reset(intrare);

        assign(iesire,'euclid2.out');
        rewrite(iesire);

        readln(intrare,t);

        for i:=1 to t do
                begin
                        readln(intrare,a,b);
        {                if a<b then
                                begin
                                        aux:=a;
                                        a:=b;
                                        b:=aux;
                                end;}

                        for x:=1 to a do
                                if (a mod x =0) and (b mod x =0) then d:=x;

                        writeln(iesire,d);


                end;

        close(intrare);
        close(iesire);
END.









END.
