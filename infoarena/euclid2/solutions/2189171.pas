program euclid2;
 var a,b,d:2..2000000000;
     i,t:1..100000;
     m,n:text;
 begin
 assign(n,'euclid2.in');
 reset(n);
 readln(t);
 for i:=1 to t do readln(n,a,b);
 close(n);
 for i:=1 to t do begin
                  while a=b do
                  if a>b then a:=a-b
                     else  b:=b-a;
                  d:=a;
                  end;

 assign(m,'euclid2.out');
 rewrite(m);
 for i:=1 to t do writeln(m,d);
 close(m);
 end.


