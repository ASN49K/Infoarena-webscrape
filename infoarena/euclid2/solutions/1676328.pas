program euclid;
        var fi,fo:text;
            i,t,a,b:longint;
function euclid(a,b:longint):longint;
begin
         if b=0 then exit
                else euclid(b,a mod b);
end;
begin   assign(fi,'euclid2.in');
        assign(fo,'euclid2.out');
        reset(fi);
        rewrite(fo);
        readln(fi,t);
        for i:=1 to t do begin
                                 readln(fi,a,b);
                                 if a>b then writeln(fo,euclid(a,b))
                                        else writeln(fo,euclid(b,a));
                         end;
        close(fi);
        close(fo);
end.