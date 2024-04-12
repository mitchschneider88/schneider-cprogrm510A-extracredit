CC=/opt/homebrew/bin/g++-13
INCLUDEFLAGS=-I. -I../include/CppUnitLite -I../
LIBFLAGS=-lDerivedShape -L./staticdependencies/red
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

DerivedShapeRed: ../DerivedShapeRed.cpp ../Point.cpp
	$(CC) -o DerivedShapeRed.o -c ../DerivedShapeRed.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	$(CC) -o PointRed.o -c ../Point.cpp $(INCLUDEFLAGS) $(CXXFLAGS)
	@mkdir -p staticdependencies/red
	ar rcs staticdependencies/red/libDerivedShape.a DerivedShapeRed.o PointRed.o
	rm DerivedShapeRed.o PointRed.o

Shape: ../Shape.h
	$(CC) -o Shape.o -c ../Shape.h $(INCLUDEFLAGS) $(CXXFLAGS)
	@mkdir -p staticdependencies/shape
	$(CC) -shared -o staticdependencies/shape/libShape.and Shape.o
	rm Shape.o

LINK_TARGET = StaticallyLoadedShapes.exe

OBJ = ../CppUnitLite/Failure.o ../CppUnitLite/Test.o ../CppUnitLite/TestRegistry.o ../CppUnitLite/TestResult.o ../CppUnitLite/WFailure.o \
      ./StaticLibMain.o ./StaticTests.o
      
all: DerivedShapeRed Shape ${LINK_TARGET}
	rm $(OBJ)
	./$(LINK_TARGET)

${LINK_TARGET}: $(OBJ)
	$(CC) -o $@ $^ $(INCLUDEFLAGS) $(LIBFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(INCLUDEFLAGS) $(LIBFLAGS) $(CXXFLAGS)

clean:
	rm ${LINK_TARGET}
	rm $(OBJ)

