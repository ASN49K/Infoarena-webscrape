Program euclid2;
var a,b,r : int64;
    t : longint;
begin
       assign(input,'euclid2.in'); reset(input);
       assign(output,'euclid2.out'); rewrite(output);
       readln(t);
       while not eof do begin readln(a,b);
                              while a mod b<>0 do begin
                                                       r:=b;
                                                       b:=a;
                                                       a:=r mod a;
                                                   end;
                              writeln(b);
                       end;
       close(input); close(output);
   end.
