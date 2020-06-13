PROGRAM sysFuncTest;
VAR
	a: REAL;
	c: INTEGER;
	b: CHAR;
BEGIN
	WRITELN('Test sys Function');
	WRITELN('Read b: CHAR, a: REAL, c: INTEGER');
	READ(b);
	WRITE('b:');
	WRITELN(b);
	READ(a);
	WRITE('a:');
	WRITELN(a);
	READ(c);
	WRITE('c:');
	WRITELN(c);
	WRITE('abs(a): ');
	WRITELN(ABS(a));
	WRITE('sqr(a): ');
	WRITELN(SQR(a));
	{WRITE('sqrt(a): ');
	WRITELN(SQRT(a));}
	
	WRITE('ord(b): ');
	WRITELN(ORD(b));
	
	WRITE('chr(ord(b)): ');
	WRITELN(CHR(ORD(b)));
	WRITE('pred(b): ');
	WRITELN(PRED(b));
	WRITE('succ(b): ');
	WRITELN(SUCC(b));

	WRITE('odd(c): ');
	WRITELN(ODD(c));
END.
