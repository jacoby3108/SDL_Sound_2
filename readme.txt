Notes SDL

test1.c:  This file is intented to test if SDL is properly installed 
if every is ok it will run and compile withour any error 

gcc test1.c -I/usr/local/include -L/usr/local/lib -lSDL -o test1

test2.c:  This file is intented to test if SDL sound is properly installed 
if every is ok it will run and compile withour any error 

test3.c:  This file is intented to test if SDL sound is properly installed 
if every is ok it will run and compile withour any error (it uses SDL2)

Installation on pi wheezy
Eso anda

https://solarianprogrammer.com/2015/01/22/raspberry-pi-raspbian-getting-started-sdl-2/ 

Resumen

1 cd ~
2 wget http://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.0.tar.gz
3 tar zxvf SDL2_image-2.0.0.tar.gz
4 cd SDL2_image-2.0.0 && mkdir build && cd build
5 ../configure
6 make -j 4
7 sudo make install


8 export LD_LIBRARY_PATH="/usr/local/lib"

gcc -o test2 test2.c -I/usr/local/include -L/usr/local/lib -lSDL2 


neew ideas
http://stackoverflow.com/questions/28128242/c-read-file-in-the-background
http://elinux.org/Omxplayer

===================================================================================================
ultimo intento exitoso !!!!!!!!!!!!!!!!!!!!!!!!!!!!

articulo 
http://jonmacey.blogspot.com.ar/2012/09/getting-started-with-sdl-part-1.html    sdl1.2

bajar desde aca https://www.libsdl.org/download-1.2.php

File SDL-1.2.15.tar.gz - GPG signed



Installing from Source
The source code for SDL is available from this link http://www.libsdl.org/download-1.2.php. This is the easiest way to get SDL working on Linux system without apt as well as for Mac OSX.  To build from the .tgz version do the following

tar vfxz SDL-1.2.15.tar.gz
cd SDL-1.2.15
./configure
make
sudo make install


MUY BUENO ver 3.5. Installing and Using a Shared Library

http://tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html#AEN70





