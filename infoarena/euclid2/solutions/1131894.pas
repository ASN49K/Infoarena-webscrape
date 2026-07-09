Program euclid2;
var a,b,r : longint;
    t,i : longint;
begin
       assign(input,'euclid2.in'); reset(input);
       assign(output,'euclid2.out'); rewrite(output);
       readln(t);
       for i:=1 to t do begin
                              readln(a,b);

                              while a mod b <> 0 do begin
                                                       r:=a mod b;
                                                       a:=b;
                                                       b:=r;
                                                   end;
                              writeln(b);


                       end;
       close(input); close(output);
end.
