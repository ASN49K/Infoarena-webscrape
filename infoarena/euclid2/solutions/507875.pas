 program cmmdc;
  var a,b,c,t,i:longint;
     f,f1:text;
  begin
 assign(f,'euclid2.in');
 assign(f1,'euclid2.out');
 reset(f);
 rewrite(f1);
 readln(f,t);
 repeat
 readln(f,a,b);
 repeat
 c:=a mod b;
 a:=b;
 b:=c;
 until c=0;
 if a<>1 then writeln(f1,a,'')else write(f1,'0');
 until i=t;
 close(f);
 close(f1);
 end.
