#!bin/bash
if command -v conan > /dev/null 2>&1;
    then conan create
else
    cd build
    cmake -S ..
    make
    sudo make install
fi