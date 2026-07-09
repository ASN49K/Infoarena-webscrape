var f,g:text;
    a,b,r,n,i:longint;

function cmmdc(a,b:longint):longint;
begin
 if a=b then cmmdc:=a
        else if a>b then cmmdc:=cmmdc(a-b,b)
                    else cmmdc:=cmmdc(a,b-a)
end;

Begin
 assign(f,'euclid2.in');
 assign(g,'euclid2.out');
 reset(f);
 rewrite(g);
 readln(f,n);
 for i:=1 to n do begin
                   readln(f,a,b);
                   r:=cmmdc(a,b);
                   writeln(g,r);
                  end;
 close(f);
 close(g);
End.

