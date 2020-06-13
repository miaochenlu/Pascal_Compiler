PROGRAM readwriteTest;
VAR
	in : INTEGER;
	st : STRING;
	re : REAL;
	ch : CHAR;
BEGIN
	WRITE('Const Test : 1 + 2 = ');
	WRITELN(1+2);

	WRITE('Read Char: ');
	READ(ch);
	WRITELN(ch);
	WRITE('Read Integer:i; Write i+1 ');
	READ(in);
	WRITELN(in+1);
	WRITE('Read String:  ');
	READ(st);
	WRITELN(st);
	WRITE('Read Real: ');
	READ(re);
	WRITELN(re);
END.
