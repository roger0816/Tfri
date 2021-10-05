#!/bin/sh

cd ~/work/Tfri/TfriServer

qmake TfriServer.pro

make clean

make

cd ~/work/Tfri/bin

./TfriServer
