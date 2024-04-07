RED=/Users/mitchschneider_/Desktop/Code/C++/UofW/ExtraCredit/dependencies/red
BLUE=/Users/mitchschneider_/Desktop/Code/C++/UofW/ExtraCredit/dependencies/blue

R='\033[0;31m'
B='\033[0;34m'
NC='\033[0m'

echo -e "${B}Loading Blue Library, Red Tests Should Fail${NC}"

export DYLD_LIBRARY_PATH=$BLUE

./LoadTimeLinkedLibraries.exe

echo -e "${R}Loading Red Library, Blue Tests Should Fail${NC}"

export DYLD_LIBRARY_PATH=$RED

./LoadTimeLinkedLibraries.exe