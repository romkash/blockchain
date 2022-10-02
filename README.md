# blockchain

an attempt to implement a semblance of a blockchain

## IDE

Code::Blocks 20.04 with MinGW

## Libraries

- OpenSSL

## Build OpenSSL for Windows platform using MinGW

Requirement details

- MSYS2 shell, from <https://www.msys2.org/>
- Perl, at least version 5.10.0, which usually comes pre-installed with MSYS2
- make, installed using `pacman -S make` into the MSYS2 environment
- MinGW[64] compiler: `mingw-w64-x86_64-gcc`.

In the MSYS2 shell do the configuration depending on the target architecture:

```
$ perl configure mingw64 shared --prefix=/c/openssl
$ make depend
$ make
```
	
Also check gcc path:
	
```
$ which gcc
```
	
And set MSYS gcc:
	
```
$ export PATH="/path to msys/msys2/mingw32/bin:$PATH"
```


Helpful links:
	
- [Compile OpenSSL MinGW on Windows](https://stackoverflow.com/questions/53131723/compile-openssl-mingw-on-windows-make1-makefile2800-crypto-dso-dso-w)
- [OpenSSL GitHub with notes](https://github.com/openssl/openssl/blob/master/NOTES-WINDOWS.md#native-builds-using-mingw)


## Linking to IDE

Build options... -> Linker settings -> Link libraries:

- ssl
- crypto
	

Build options... -> Search directories -> Compiler:

- sources\include
- sources\include\openssl
	

Build options... -> Search directories -> Linker:

- sources\lib
- sources\lib\openssl


## Build and run

![Illustration](https://github.com/yorrdt/blockchain/blob/main/illustrations/screenshot.png)
