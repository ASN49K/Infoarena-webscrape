 Program Euclid01 ;
  var a,b,n,i:longword  ; f,t:text ;
 BEGIN
  assign(f,'euclid2.in') ; reset(f) ; readln(f,n) ;
  assign(t,'euclid2.out') ; rewrite(t) ;
   for i:=1 to n do begin readln(f,a,b) ;
    while a<>b do if b>a then b:=b-a else a:=a-b ; writeln(a) ; end ;
   close(f) ; close(t) ; readln ;
      end .