Comskip - a free MPEG commercial detector

Upstream project:
  http://www.kaashoek.com/comskip/
  svn://svn.kaashoek.com/

This application depends on three 3rd party libraries:

  x264: https://www.videolan.org/developers/x264.html (optional)
  ffmpeg: http://www.ffmpeg.org/download.html
  argtable2: http://argtable.sourceforge.net/

To build Comskip, a MinGW compiler is required.  Grab the build script from here:

http://ffmpeg.zeranoe.com/blog/

Open it in a text editor; near the top, change the GCC version to 4.8.1 and the GMP version to 5.1.2.  Search for "svn checkout" to locate where MinGW is downloaded and add "-r 6155" to both lines. Now run the script and build at least the 32-bit toolchain.

Once the toolchain is built, add the binaries to your PATH then download the dependent libraries listed above.  Configure each as below, copy the installed static libraries and headers into the toolchain's sysroot, then run make in this directory to build Comskip.

== x264 ==

./configure --host=i686-w64-mingw32 --cross-prefix=i686-w64-mingw32- --enable-static --enable-win32thread 

== ffmpeg ==

Comskip uses interfaces which were removed as of FFmpeg 2.  You'll first need to download the latest release in the 1.2 tree and apply the patch in the contrib directory before proceeding.

git clone git://source.ffmpeg.org/ffmpeg.git ffmpeg
cd ffmpeg
git checkout -b comskip n1.2.3
patch -p1 < ../ffmpeg-unicode.patch
./configure --arch=x86 --target-os=mingw32 --cross-prefix=i686-w64-mingw32- --enable-gpl --enable-version3 --disable-stripping --enable-libx264 --disable-shared --enable-static

== argtable2 ==

./configure --prefix=/usr --sysconfdir=/etc --build=x86_64-unknown-linux-gnu --host=i686-w64-mingw32 --enable-static --disable-shared
