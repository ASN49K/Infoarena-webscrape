Program Subsir;
 const nmax = 1024;
 var f,g:text; a,b:array[1..nmax]of integer;
     c:array[1..nmax]of integer;
     m,n:integer;
 procedure initiere;
  var x,y:integer;
  begin
   assign (f,'cmlsc.in'); reset (f);
   assign (g,'cmlsc.out'); rewrite (g);
   readln (f,m,n);
   for x:=1 to m do read (f,a[x]);
   readln (f);
   for x:=1 to n do read (f,b[x]);
   for x:=1 to m do c[x]:=0;
  end;
 procedure incheiere;
  begin
   close (f); close (g);
  end;
 procedure generare;
  var x,y,u,v:integer;
  begin
   u:=1; v:=1;
   for x:=1 to n do
     for y:=v to m do
       if b[x]=a[y] then begin
         c[u]:=b[x];
         u:=u+1;
         v:=y+1;
       end;
   writeln (g,u-1);
   for x:=1 to u-2 do write (g,c[x],' ');
   writeln (g,c[u-1]);
  end;
 begin
  initiere;
  generare;
  incheiere;
 end.
