#!/bin/bash

echo "Rebuild?[y/N]"
read yn
case $yn in
    y|Y)
        rm -r build
        echo "Carpeta build eliminada"
        ;;
esac

if test ! -d build; then
    mkdir build
    cd build
    cmake ..
    cmake --build .
    cd ..
fi

if test -e build/GameOfLife; then
    ./build/GameOfLife
fi
