CFLAGS = -std=c++11 -Wno-deprecated-register -Wno-writable-strings

OBJS = parser.o scanner.o main.o ast/ast.o

pascal: $(OBJS)
	g++ -o $@ $(OBJS) $(CFLAGS)

ast.o: ast/ast.cpp ast/ast.h
	g++ -c $(CXXFLAGS) -g -o $@ $< 

%.o: %.cpp 
	g++ -c $(CXXFLAGS) -g -o $@ $< 

scanner.cpp: pascal.l
	flex -o scanner.cpp pascal.l

parser.cpp: pascal.y
	bison -d -o parser.cpp pascal.y

parser.hpp: parser.cpp 


clean:
	@rm -f parser.output *.o parser.cpp parser.hpp scanner.cpp ast/ast.o