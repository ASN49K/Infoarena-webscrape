var n,i:word;
        a,b,x,y:longword;
        be,ki:text;


begin
        assign(be,'euclid2.in');
        assign(ki,'euclid2.out');

        reset(be);
        rewrite(ki);

        readln(be,n);

        for i:=1 to n do begin
                readln(be,a,b);
                if a<b then begin x:=a; a:=b; b:=x; end;
                while (a>0) AND (b>0) do begin
                        y:=a MOD b;

                         if y=0 then writeln(ki,b);

                        a:=b;
                        b:=y;



                                                        end;
                        end;

        close(be);
        close(ki);

end.
