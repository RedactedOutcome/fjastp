#Architecture can be [x64]
Platform = Windows
Configuration = Release
TargetName = fjastp
Architecture = x64

Config=$(Configuration)/$(Architecture)-$(Platform)/
OutputDir = bin/jfastp/$(Config)/
IntDir = bin-int/jfastp/$(Config)/
ExampleOutputDir=bin/example/$(Config)/
ExampleIntDir=bin-int/example/$(Config)/
Include = include/

MF =
RF = 
CC = 
LK = 
Files =
Defines =
CFlags = 
LFlags = 
Files = 
SRC_DIR = src/

BoostDir = ${BOOST_ROOT}
HBUFFER_LIB_SRC = libs/HBuffer/

ifeq ($(Platform), Windows)
include WindowsMake.mk
else
$(error Invalid Platform)
endif

default: build

clean:
	$(RF) bin-int
make_folders:
	$(MF) $(IntDir)
	$(MF) $(OutputDir)
build_pch: make_folders
	$(CC) $(CFlags) $(LibCFlags) $(Defines) $(IncludeDirs) /Ycpch.h /Fp$(IntDir)pch.pch src/pch.cpp
build: make_folders
	$(CC) $(Files) $(CFlags) $(LibCFlags) $(Defines) $(IncludeDirs) /Yupch.h /Fp$(IntDir)pch.pch 
	$(LibCreator) $(LFlags) $(LibFlags) $(LibDirs) $(Libs)
build_example:
	$(MF) $(ExampleIntDir)
	$(MF) $(ExampleOutputDir)
	$(CC) $(ExampleFiles) $(CFlags) $(ExampleCFlags) $(Defines) $(IncludeDirs) /Yupch.h /Fp$(IntDir)pch.pch 
	$(LK) $(LFlags) $(ExampleLFlags) $(LibDirs) $(Libs) $(ExampleLibs) $(ExampleLibDirs)
run:
	$(ExampleOutputDir)Example.exe
buildnrun: build run
rebuild: make_folders build_pch build
rebuildnrun:make_folders build_pch build run
