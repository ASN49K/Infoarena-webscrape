program euclid2;
        var a,b,i,r,t:longint;
            fi,fo:text;
begin   assign(fi,'euclid2.in');
        assign(fo,'euclid2.out');
        reset(fi);
        rewrite(fo);
        read(f,t);
        for i:=1 to t do begin
                                 readln(fi,a,b);
                                 r:=a mod b;
                                 while r<>0 do begin
                                                       a:=b;
                                                       b:=r;
                                                       r:=a mod b;
                                               end;
                                 writeln(fo,b);
                         end;
        close(fi);
        close(fo);
end.
