MF 		= mkdir -p
RF      = rd /s /q
CC = cl
LibCreator = lib
LK = link
CFlags = /c /std:c++17 /MT /utf-8
LibCFlags = /Fo$(IntDir) 
ExampleCFlags = /Fo$(ExampleIntDir)
Defines = /DPLATFORM=Windows /DWINDOWS_IGNORE_PACKING_MISMATCH /DFJASTP_USE_PCH /DFJASTP_PCH_DIR="\"fjastp/pch.h\""
IncludeDirs = /I"$(HBUFFER_LIB_SRC)/include/" /I"include/" /I"include/fjastp/"
LibDirs = 
Libs = GDI32.lib Shell32.lib kernel32.lib User32.lib
LFlags = /NODEFAULTLIB:msvcrt.lib /DEFAULTLIB:libcmt.lib
LibFlags = $(IntDir)*.obj /out:$(OutputDir)$(TargetName).lib
ProgramArgs = 

#Debugging
#Configuration Only
ifeq ($(Configuration), Debug)
CFlags += /Od /Z7
Defines += /DDEBUG
LFlags += /DEBUG
else
Defines += /DNDEBUG

ifeq ($(Configuration), Release)
Defines += /DWEB_RELEASE
CFlags += /Ot /Oi
LFlags += /LTCG /INCREMENTAL:NO /NODEFAULTLIB
else
CFlags += /Ot /Oi /O2 /GL /Gw
Defines += /DWEB_DIST
LFlags += /LTCG /INCREMENTAL:NO /NODEFAULTLIB /OPT:REF /OPT:ICF
endif
endif

CORE_DIR = $(SRC_DIR)Core/

#Libs
#Files += $(SRC_DIR)libs/HBuffer.cpp
#Files += $(SRC_DIR)libs/HBufferJoin.cpp

Files+= $(SRC_DIR)Parser.cpp
Files+= $(SRC_DIR)Tokenizer.cpp

ExampleFiles = examples/test/Main.cpp
ExampleLibs+=fjastp.lib
ExampleLibDirs+= /LIBPATH:"$(OutputDir)"
ExampleLFlags += $(ExampleIntDir)*.obj /out:$(ExampleOutputDir)Example.exe

ifneq (${VCPKG_ROOT},)
IncludeDirs += /I"${VCPKG_ROOT}\installed\$(Architecture)-windows\include" /I"${VCPKG_ROOT}\installed\$(Architecture)-windows-static\include"
LibDirs += /LIBPATH:"${VCPKG_LIB_DIR}" /LIBPATH:"${VCPKG_ROOT}\installed\$(Architecture)-windows-static\lib"

endif