Program p1;  uses crt;
 var a,b,c,max,min,v,n,i:integer; fo,fi:text; u:boolean;
 begin clrscr;
        assign(fi,'p1.in'); reset(fi);
        assign(fo,'p1.out'); rewrite(fo);
        read(fi,n);

        while n<>0 do begin
        readln(fi,a,b);
        if a>b then max:=a else max:=b;
        if b<a then min:=b else min:=a;
        for i:=max downto 1 do begin
        if min>max then begin v:=max; max:=min; min:=v; end;

        max:=max-min; if max=min then c:=max;
                                 end;

        dec(n);
        writeln(fo,c);
         end;
         close(fo);
        end.
