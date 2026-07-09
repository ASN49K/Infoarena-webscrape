program divizori; uses crt;
   var f, g : text;
       a, c : longint;
       i, t : longint;
Begin
   Assign(g,'euclid2.in.txt');
    reset(G);
    Assign(f,'euclid2.out.txt');
     rewrite(F);
    readln(g,t);
     For i:=1 to t do
       Begin
        Readln(g,a,c);
          While a<>c do
             if a>c then
                      a:=a-c
                    else
                      c:=c-a;
             Writeln(f,A);
       End;
       Close(G);
       Close(F);
  Readln;
End.
