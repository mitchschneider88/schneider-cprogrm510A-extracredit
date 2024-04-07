CC=/opt/homebrew/bin/g++-13
CFLAGS=-I. -I./include/CppUnitLite -lDerivedShape -L./dependencies/red
CXXFLAGS += -std=c++20 -Wall -Werror
# -std=c++20: valid for g++ 10 and greater.
# -Wall: reports all warnings
# -Werror: warnings reported as errors

LINK_TARGET = LoadTimeLinkedLibraries.exe

OBJ = CppUnitLite/Failure.o CppUnitLite/Test.o CppUnitLite/TestRegistry.o CppUnitLite/TestResult.o CppUnitLite/WFailure.o \
      Main.o Tests.o
      
all: ${LINK_TARGET}
	rm $(OBJ)
	./$(LINK_TARGET)

${LINK_TARGET}: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(CXXFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(CXXFLAGS)

clean:
	rm ${LINK_TARGET}