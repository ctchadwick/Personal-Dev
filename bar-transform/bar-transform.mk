##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=bar-transform
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace
ProjectPath            :=C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/bar-transform
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Chadwick
Date                   :=11/10/2019
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
Preprocessors          :=$(PreprocessorSwitch)_WIN32_WINNT_WIN7 $(PreprocessorSwitch)_WINDOWS $(PreprocessorSwitch)FMT_HEADER_ONLY $(PreprocessorSwitch)BOOST_THREAD_USE_LIB $(PreprocessorSwitch)BOOST_THREAD_PROVIDES_FUTURE $(PreprocessorSwitch)BOOST_ASIO_DISABLE_STD_FUTURE $(PreprocessorSwitch)BOOST_COROUTINES_V2 $(PreprocessorSwitch)RAPIDJSON_HAS_STDSTRING $(PreprocessorSwitch)HAVE_SNPRINTF 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="bar-transform.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw64-810/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)$(BoostIncludes) $(IncludeSwitch)$(WorkspaceCodeLib) $(IncludeSwitch)$(WorkspaceCodeLib)/strtk $(IncludeSwitch)$(WorkspaceCodeLib)/rapidjson $(IncludeSwitch)$(WorkspaceCodeLib)/spdlog $(IncludeSwitch)$(WorkspaceCodeLib)/date/include $(IncludeSwitch)$(WorkspaceCodeLib)/IB-Codes 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mswsock $(LibrarySwitch)ws2_32 $(LibrarySwitch)boost_filesystem-${blibsuffix-dll} $(LibrarySwitch)boost_date_time-${blibsuffix-dll} $(LibrarySwitch)boost_thread-${blibsuffix-dll} $(LibrarySwitch)boost_coroutine-${blibsuffix-dll} $(LibrarySwitch)boost_context-${blibsuffix-dll} $(LibrarySwitch)boost_chrono-${blibsuffix-dll} $(LibrarySwitch)boost_random-${blibsuffix-dll} $(LibrarySwitch)boost_program_options-${blibsuffix-dll} $(LibrarySwitch)boost_system-${blibsuffix-dll} 
ArLibs                 :=  "mswsock" "ws2_32" "boost_filesystem-${blibsuffix-dll}" "boost_date_time-${blibsuffix-dll}" "boost_thread-${blibsuffix-dll}" "boost_coroutine-${blibsuffix-dll}" "boost_context-${blibsuffix-dll}" "boost_chrono-${blibsuffix-dll}" "boost_random-${blibsuffix-dll}" "boost_program_options-${blibsuffix-dll}" "boost_system-${blibsuffix-dll}" 
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
CodeLiteDir:=C:\Program Files\CodeLite
WorkspaceCodeLib:="C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library"
BinRepo:=C:\Users\Chadwick\Desktop\MCM-Options-CTC\Codes-Etc\CodeLite-Workspace\bin
WorkBinRepo:=C:\Users\Chadwick\Desktop\MCM-Options-CTC\Codes-Etc\Work-Codelite-Workspace\bin
BoostIncludes:=C:\Boost\include\boost-1_69
BoostLibraries:=C:\Boost\lib
blibsuffix:=mgw81-mt-x64-1_69
blibsuffix-dll:=mgw81-mt-x64-1_69.dll
blibsuffix32:=mgw81-mt-x32-1_69
blibsuffix32-dll:=mgw81-mt-x32-1_69.dll
WXWIN:=C:\wxWidgets\3.1.2
OpenSSLIncludes:="C:\Program Files\OpenSSL-Win64\include"
OpenSSLLibraries:="C:\Program Files\OpenSSL-Win64\lib"
Objects0=$(IntermediateDirectory)/fast-log2.cpp$(ObjectSuffix) $(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) $(IntermediateDirectory)/orderflow-utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/amain.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/fast-log2.cpp$(ObjectSuffix): ../../Code-Library/fast-log2.cpp $(IntermediateDirectory)/fast-log2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/fast-log2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fast-log2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fast-log2.cpp$(DependSuffix): ../../Code-Library/fast-log2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fast-log2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/fast-log2.cpp$(DependSuffix) -MM ../../Code-Library/fast-log2.cpp

$(IntermediateDirectory)/fast-log2.cpp$(PreprocessSuffix): ../../Code-Library/fast-log2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fast-log2.cpp$(PreprocessSuffix) ../../Code-Library/fast-log2.cpp

$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix): ../../Code-Library/hi-res-time2.cpp $(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/hi-res-time2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix): ../../Code-Library/hi-res-time2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/hi-res-time2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/hi-res-time2.cpp$(DependSuffix) -MM ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/hi-res-time2.cpp$(PreprocessSuffix): ../../Code-Library/hi-res-time2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/hi-res-time2.cpp$(PreprocessSuffix) ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/orderflow-utils.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp $(IntermediateDirectory)/orderflow-utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/Code-Library/IB-codes/orderflow-utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/orderflow-utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/orderflow-utils.cpp$(DependSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/orderflow-utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/orderflow-utils.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/orderflow-utils.cpp

$(IntermediateDirectory)/orderflow-utils.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/orderflow-utils.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/orderflow-utils.cpp

$(IntermediateDirectory)/amain.cpp$(ObjectSuffix): amain.cpp $(IntermediateDirectory)/amain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Chadwick/Desktop/MCM-Options-CTC/Codes-Etc/CodeLite-Workspace/bar-transform/amain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/amain.cpp$(ObjectSuffix) $(IncludePath)
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


