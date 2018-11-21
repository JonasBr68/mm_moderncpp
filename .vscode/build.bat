@echo on
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64     
set compilerflags=/Od /Zi /EHsc
set linkerflags=/OUT:ModernCPP.exe
cd ModernCPP
dir
cl.exe %compilerflags% ModernCPP.cpp /link %linkerflags%