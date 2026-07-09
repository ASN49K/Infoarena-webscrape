const
    VMAX=1024;

var
    a,b,rez:array[0..VMAX]of longint;
    c:array[0..VMAX,0..VMAX]of longint;
    m,n:longint;


procedure citire;
    var
        i:longint;
    begin
        assign(input,'cmlsc.in');reset(input);
        readln(n,m);
            for i:=1 to n do
                read(a[i]);
            readln;
            for i:=1 to m do
                read(b[i]);
        close(input);
    end;

function max(x,y:longint):longint;
    begin
        if x>=y then
            max:=x
        else max:=y;
    end;

procedure cmlsc;
    var
        i,j:longint;
    begin
        c[0,0]:=0;
        for i:=1 to n do
            for j:=1 to m do
                if a[i]=b[j] then
                    begin
                        c[i,j]:=c[i-1,j-1]+1;
                        rez[c[i,j]]:=a[i];
                    end
                else
                    c[i,j]:=max(c[i-1,j],c[i,j-1]);
    end;

procedure afisare;
    var
        i:longint;
    begin
        assign(output,'cmlsc.out');rewrite(output);
        writeln(c[n,m]);
        for i:=1 to c[n,m] do
            write(rez[i],' ');
        close(output);
    end;

begin
    citire;
    cmlsc;
    afisare;
end.
