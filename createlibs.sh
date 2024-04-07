g++-13 -o DerivedShape.o -c DerivedShapeRed.cpp
g++-13 -o Point.o -c Point.cpp
mkdir dependencies/red
mkdir dependencies/blue
g++-13 -shared -o dependencies/red/libDerivedShape.dylib DerivedShape.o Point.o 
#move red
g++-13 -o DerivedShape.o -c DerivedShapeBlue.cpp
g++-13 -shared -o dependencies/blue/libDerivedShape.dylib DerivedShape.o Point.o
g++-13 Tests.o -c Tests.cpp -I. -I./include/CppUnitLite -std=c++20 -Wall -Werror
g++-13 Main.o -c Main.cpp -I. -I./include/CppUnitLite -std=c++20 -Wall -Werror
g++-13 -o LoadTimeLinkedLibraries.exe Main.o Tests.o -lDerivedShape -L./dependencies/red

rm DerivedShape.o
rm Point.o
rm Main.o