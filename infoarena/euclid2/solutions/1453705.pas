Program p1;  uses crt;
 var a,b,c,max,min,v,i:integer; fo,fi:text; u:boolean;
 begin clrscr;
        assign(fi,'p1.in'); reset(fi);
        assign(fo,'p1.out'); rewrite(fo);
        read(fi,a,b);
        if a>b then max:=a else max:=b;
        if b<a then min:=b else min:=a;
        for i:=max downto 1 do begin
        if min>max then begin v:=max; max:=min; min:=v; end;

        max:=max-min; if max=min then c:=max;
                                 end;

        if c=1 then c:=0;
        writeln(fo,c);  close(fo)

        end.
