Program Euclid2;
 var f,g:text; n:longint;
 procedure initiere;
  begin
   assign (f,'euclid2.in'); reset (f);
   assign (g,'euclid2.out'); rewrite (g);
   readln (f,n);
  end;
 procedure incheiere;
  begin
   close (f); close (g);
  end;
 function cmmdc (x,y:longint):longint;
  var u,v,rest:longint;
  begin
   rest:=1;
   u:=x; v:=y;
   while rest<>0 do begin
     rest:=u mod v;
     u:=v;
     v:=rest;
   end;
   cmmdc:=u;
  end;
 procedure calcul;
  var x,y,z:longint;
  begin
   for x:=1 to n do begin
     readln (f,y,z);
     writeln (g,cmmdc (y,z));;
   end;
  end;
 begin
  initiere;
  calcul;
  incheiere;
 end.