#!/bin/sh

basepath=$(cd `dirname $0`; pwd)

echo "The work directory is $basepath ."

basepath=$basepath/out

if [ ! -d "$basepath/build/Debug" ]; then
    cmake -B$basepath/build/Debug -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$basepath/install/Debug
fi

cmake --build $basepath/build/Debug --config Debug

cmake --install $basepath/build/Debug --config Debug

