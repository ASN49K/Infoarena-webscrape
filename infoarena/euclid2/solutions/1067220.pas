Program euclid2;
var i,T :longint;
    a : array[1..100000] of int64;

  function cmmdc(k,b :int64):int64;
  begin
         if k mod b=0 then cmmdc:=b
                else cmmdc:=cmmdc(b,k mod b);
        end;
begin
       assign(input,'euclid2.in'); reset(input);
       assign(output,'euclid2.out'); rewrite(output);
       readln(T);
       t:=t*2;
       for i:=1 to T do read (a[i]);
       for i:=1 to T do
                         if i mod 2<>0 then
                                             writeln(cmmdc(a[i],a[i+1]));
       close(input); close(output);
   end.


