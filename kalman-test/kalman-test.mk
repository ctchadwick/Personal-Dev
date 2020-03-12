##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=kalman-test
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace
ProjectPath            :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/kalman-test
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chadwick
Date                   :=11/03/2020
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/mingw64-810/bin/g++.exe
SharedObjectLinkerName :="C:/mingw64-810/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(BinRepo)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)_WIN32_WINNT_WIN7 $(PreprocessorSwitch)_WINDOWS $(PreprocessorSwitch)FMT_HEADER_ONLY $(PreprocessorSwitch)RAPIDJSON_HAS_STDSTRING $(PreprocessorSwitch)HAVE_SNPRINTF 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="kalman-test.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64-810/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)$(BoostIncludes) $(IncludeSwitch)$(WorkspaceCodeLib) $(IncludeSwitch)$(WorkspaceCodeLib)/strtk $(IncludeSwitch)$(WorkspaceCodeLib)/rapidjson $(IncludeSwitch)$(WorkspaceCodeLib)/spdlog $(IncludeSwitch)$(WorkspaceCodeLib)/date/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(BoostLibraries) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/mingw64-810/bin/ar.exe" rcu
CXX      := C:/mingw64-810/bin/g++.exe
CC       := C:/mingw64-810/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -std=c++11 -Wall -Wa,-mbig-obj $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw64-810/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:/Program Files/CodeLite
WorkspaceCodeLib:=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library
BinRepo:=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/bin
WorkBinRepo:=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Work-Codelite-Workspace/bin
BoostIncludes:=C:/Boost/include/boost-1_71
BoostLibraries:=C:/Boost/lib
blibsuffix:=mgw81-mt-x64-1_71
blibsuffix-dll:=mgw81-mt-x64-1_71.dll
blibsuffix32:=mgw81-mt-x32-1_71
blibsuffix32-dll:=mgw81-mt-x32-1_71.dll
OpenSSLIncludes:=C:/Program Files/OpenSSL-Win64/include
OpenSSLLibraries:=C:/Program Files/OpenSSL-Win64/lib
npcap-includes:=C:/npcap-sdk/Include
npcap-libraries:=C:/npcap-sdk/Lib/x64
Objects0=$(IntermediateDirectory)/amain.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/amain.cpp$(ObjectSuffix): amain.cpp $(IntermediateDirectory)/amain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/kalman-test/amain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/amain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/amain.cpp$(DependSuffix): amain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/amain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/amain.cpp$(DependSuffix) -MM amain.cpp

$(IntermediateDirectory)/amain.cpp$(PreprocessSuffix): amain.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/amain.cpp$(PreprocessSuffix) amain.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


