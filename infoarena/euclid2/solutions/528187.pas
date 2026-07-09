var
    t,a,b,i:longint;


function cmmdc(a,b:longint):longint;
    begin
        if b=0 then begin cmmdc:=a; end
        else
            cmmdc:=cmmdc(b,a mod b)
    end;

begin
    assign(input,'euclid2.in');reset(input);
    assign(output,'euclid2.out');rewrite(output);
    readln(t);
    for i:=1 to t do
        begin
            readln(a,b);
            writeln(cmmdc(a,b));
        end;
    close(input);
    close(output);
end.