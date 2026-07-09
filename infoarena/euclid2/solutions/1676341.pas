program euclid;
        var fi,fo:text;
            t,a,b:longint;
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
        while t>0 do begin
                             readln(fi,a,b);
                             writeln(fo,euclid(a,b));
                             dec(t);
                     end;
        close(fi);
        close(fo);
end.
