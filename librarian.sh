class="$1";
if [ "$class" = "" ]; then class="$(cat ./defaultClass)"; else echo "$class" > ./defaultClass; fi;
echo "Building $class...";
rm ./build/main.cpp;
cp $class ./build/main.cpp;
cd build || exit 1;
make;
./csnuts
exit 0;
