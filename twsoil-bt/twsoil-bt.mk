##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=twsoil-bt
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace
ProjectPath            :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/twsoil-bt
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chadwick
Date                   :=10/03/2020
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
Preprocessors          :=$(PreprocessorSwitch)WIN32_LEAN_AND_MEAN $(PreprocessorSwitch)FMT_HEADER_ONLY $(PreprocessorSwitch)BOOST_THREAD_USE_LIB $(PreprocessorSwitch)_WIN32_WINNT_WIN7 $(PreprocessorSwitch)BOOST_ASIO_DISABLE_STD_FUTURE 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="twsoil-bt.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64-810/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(BoostIncludes) $(IncludeSwitch)$(WorkspaceCodeLib) $(IncludeSwitch)$(WorkspaceCodeLib)/date/include $(IncludeSwitch)$(WorkspaceCodeLib)/strtk $(IncludeSwitch)$(WorkspaceCodeLib)/IB-Codes $(IncludeSwitch)$(WorkspaceCodeLib)/spdlog 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mswsock $(LibrarySwitch)ws2_32 $(LibrarySwitch)boost_system-$(blibsuffix) $(LibrarySwitch)boost_date_time-$(blibsuffix) $(LibrarySwitch)boost_thread-$(blibsuffix) $(LibrarySwitch)boost_filesystem-$(blibsuffix) $(LibrarySwitch)boost_thread-$(blibsuffix) $(LibrarySwitch)boost_chrono-$(blibsuffix) $(LibrarySwitch)boost_coroutine-$(blibsuffix) $(LibrarySwitch)boost_context-$(blibsuffix) $(LibrarySwitch)boost_regex-$(blibsuffix) $(LibrarySwitch)boost_program_options-$(blibsuffix) $(LibrarySwitch)boost_random-$(blibsuffix) 
ArLibs                 :=  "mswsock" "ws2_32" "boost_system-$(blibsuffix)" "boost_date_time-$(blibsuffix)" "boost_thread-$(blibsuffix)" "boost_filesystem-$(blibsuffix)" "boost_thread-$(blibsuffix)" "boost_chrono-$(blibsuffix)" "boost_coroutine-$(blibsuffix)" "boost_context-$(blibsuffix)" "boost_regex-$(blibsuffix)" "boost_program_options-$(blibsuffix)" "boost_random-$(blibsuffix)" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(BoostLibraries) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/mingw64-810/bin/ar.exe" rcu
CXX      := C:/mingw64-810/bin/g++.exe
CC       := C:/mingw64-810/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
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
Objects0=$(IntermediateDirectory)/indicator-utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) $(IntermediateDirectory)/idobos-trigger-agent.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/indicator-utils.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/indicator-utils.cpp $(IntermediateDirectory)/indicator-utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/IB-codes/indicator-utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/indicator-utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/indicator-utils.cpp$(DependSuffix): ../../Code-Library/IB-codes/indicator-utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/indicator-utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/indicator-utils.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/indicator-utils.cpp

$(IntermediateDirectory)/indicator-utils.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/indicator-utils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/indicator-utils.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/indicator-utils.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/twsoil-bt/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix): ../../Code-Library/hi-res-time2.cpp $(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/hi-res-time2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix): ../../Code-Library/hi-res-time2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix) -MM ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/hi-res-time2.cpp$(PreprocessSuffix): ../../Code-Library/hi-res-time2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hi-res-time2.cpp$(PreprocessSuffix) ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/idobos-trigger-agent.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/idobos-trigger-agent.cpp $(IntermediateDirectory)/idobos-trigger-agent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/IB-codes/idobos-trigger-agent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/idobos-trigger-agent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/idobos-trigger-agent.cpp$(DependSuffix): ../../Code-Library/IB-codes/idobos-trigger-agent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/idobos-trigger-agent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/idobos-trigger-agent.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/idobos-trigger-agent.cpp

$(IntermediateDirectory)/idobos-trigger-agent.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/idobos-trigger-agent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/idobos-trigger-agent.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/idobos-trigger-agent.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


