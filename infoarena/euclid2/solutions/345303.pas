PROGRAM EUCLID;
VAR r,d,i,q,aux,t: longint; F,G:TEXT;
BEGIN
    ASSIGN(F,'euclid2.IN');RESET(F);
    ASSIGN(G,'euclid2.OUT');REWRITE(G); readln(f,t); writeln(g);
    for q:=1 to t do begin
     READ (F,d);readln(f,i);
     if d<i then begin
     aux:=d;d:=i;i:=aux;end;
     r:=d mod i;
     WHILE R <>0 DO BEGIN
      d:=i;
      i:=R;
      R:= d MOD i;
      END;
      WRITEln (G,i);end;
      CLOSE(F);
      CLOSE(G);
END.
