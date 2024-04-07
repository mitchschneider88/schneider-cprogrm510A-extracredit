CC=/opt/homebrew/bin/g++-13
INCLUDEFLAGS=-I. -I./include/CppUnitLite
LIBFLAGS=-lDerivedShape -L./dependencies/red
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

DerivedShapeRed: DerivedShapeRed.cpp Point.cpp
	$(CC) -o DerivedShapeRed.o -c DerivedShapeRed.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	$(CC) -o PointRed.o -c Point.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	@mkdir -p dependencies/red
	$(CC) -shared -o dependencies/red/libDerivedShape.dylib DerivedShapeRed.o PointRed.o
	rm DerivedShapeRed.o PointRed.o

DerivedShapeBlue: DerivedShapeBlue.cpp Point.cpp
	$(CC) -o DerivedShapeBlue.o -c DerivedShapeBlue.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	$(CC) -o PointBlue.o -c Point.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	@mkdir -p dependencies/blue
	$(CC) -shared -o dependencies/blue/libDerivedShape.dylib DerivedShapeBlue.o PointBlue.o
	rm DerivedShapeBlue.o PointBlue.o

LINK_TARGET = LoadTimeLinkedLibraries.exe

OBJ = CppUnitLite/Failure.o CppUnitLite/Test.o CppUnitLite/TestRegistry.o CppUnitLite/TestResult.o CppUnitLite/WFailure.o \
      Main.o Tests.o
      
all: DerivedShapeRed DerivedShapeBlue ${LINK_TARGET}
	rm $(OBJ)
	./$(LINK_TARGET)

${LINK_TARGET}: $(OBJ)
	$(CC) -o $@ $^ $(INCLUDEFLAGS) $(LIBFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(INCLUDEFLAGS) $(LIBFLAGS) $(CXXFLAGS)

clean:
	rm ${LINK_TARGET}
	rm $(OBJ)