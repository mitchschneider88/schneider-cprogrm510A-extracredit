R='\033[0;31m'
NC='\033[0m'

echo -e "${R}Deleting .lib files to show StaticallyLoadedShapes.exe can be run without them${NC}\n"

rm -r ./staticdependencies

./StaticallyLoadedShapes.exe