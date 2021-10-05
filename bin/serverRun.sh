#!/bin/sh

cd ~/work/Tfri/bin

qmake TfriServer.pro

make clean

make

./TfriServer
