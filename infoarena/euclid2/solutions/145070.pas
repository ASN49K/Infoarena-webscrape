program cmmdc;
var a,b,r:integer;

 procedure citire;
 begin
 assign(input,'cmmdc.in');
 reset(input);
 read(a,b);
 close(input);
 end;

 procedure cmmdc;
 var w,q:integer;
 begin
 w:=a;
 q:=b;
 repeat
        r:=w mod q;
        w:=q;
        q:=r;
        until q=0;
 if (w=1) and (a<>1) and (b<>1) then
    write(0)
    else write(w);
 end;

 begin
 citire;
 assign(output,'cmmdc.out');
 rewrite(output);
 cmmdc;
 close(output);
 end.
