Program euclid2;
var a,b,r : int64;
    t : longint;
begin
       assign(input,'euclid2.in'); reset(input);
       assign(output,'euclid2.out'); rewrite(output);
       readln(t);
       while not eof do begin readln(a,b);
                              if a>b then begin
                                               while b<>0 do begin
                                                              r:=a mod b;
                                                              a:=b;
                                                              b:=r;
                                                        end;
                                               writeln(a);
                                         end
                                     else begin while a<>0 do begin
                                                              r:=b mod a;
                                                              b:=a;
                                                              a:=r;
                                                         end;
                                     writeln(b);
                              end;

       end;
       close(input); close(output);
   end.
