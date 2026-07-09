Program euclid2;
var a,b,r : int64;
    t,i : longint;
begin
       assign(input,'euclid2.in'); reset(input);
       assign(output,'euclid2.out'); rewrite(output);
       readln(t);
       for i:=1 to t do begin
                              readln(a,b);
       if a>b then begin
                              while a mod b <> 0 do begin
                                                       r:=a mod b;
                                                       a:=b;
                                                       b:=r;
                                                   end;
                              writeln(b);
                       end
                       else begin
                              while b mod a <> 0 do begin
                                                       r:=b mod a;
                                                       b:=a;
                                                       a:=r;
                                                   end;
                              writeln(a);
                       end;
                       end;
       close(input); close(output);
end.
