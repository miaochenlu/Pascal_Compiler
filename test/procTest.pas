PROGRAM procTest;
{routine head}

{var part}
VAR	
	k : INTEGER;

{routine part}

FUNCTION inner1(a , b : INTEGER) : INTEGER;
BEGIN
	WRITELN('IN inner1: (a,b)');
	inner1 := a + b;
	WRITELN('return (a+b)');
END;

PROCEDURE inner2(aa : INTEGER; b :INTEGER);
BEGIN
	WRITELN('IN inner2: (a,b)');
	WRITELN('a = call inner1: (a,b)');
	aa := inner1(aa , b);
	k := k + 5;
	WRITE('a: shoule be a+b = k+2');
	WRITELN(aa);
	WRITELN('global k:');
	WRITE('k+5: shoule be k+5');
	WRITE(k);
END;

PROCEDURE outer;
{subroutine var part}
VAR 
	added : INTEGER;
{subroutine routine part}
BEGIN
	WRITELN('IN outer: define added = 1; read k');
	added := 1;
	READ(k);
	WRITELN('call inner2: (k+1, added)');
	inner2(k+1 , added);
END;
{routine body}
BEGIN
	WRITELN('main: define k;');
	WRITELN('call outer');
	outer;
END.
