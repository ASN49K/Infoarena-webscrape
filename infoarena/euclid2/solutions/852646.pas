type tip=1..100000;
var t,i:tip;
    a,b:longint;
    f,g:text;
    function fu(a,b:longint):longint;
    begin
              if a=b then fu:=a
                 else if a>b then fu:=fu(a-b,b);
                   if b>a then fu:=fu(a,b-a);

     end;
begin
        assign(f,'euclid2.in');
        reset(f);
        readln(f,t);
        assign(g,'euclid2.out');
        rewrite(g);
        close(g);
       for i:=1 to t do
          begin
     readln(f,a,b);
     assign(g,'euclid2.out');
     append(g);
     writeln(g,fu(a,b));
     close(g);
         end;
      close(f);
end.


