##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=twsoil
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Todd/Desktop/Development/CodeLite-Workspace
ProjectPath            :=C:/Users/Todd/Desktop/Development/CodeLite-Workspace/twsoil
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Todd
Date                   :=30/01/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="twsoil.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)$(BoostIncludes) $(IncludeSwitch)$(WorkspaceCodeLib) $(IncludeSwitch)$(WorkspaceCodeLib)/date/include $(IncludeSwitch)$(WorkspaceCodeLib)/strtk $(IncludeSwitch)$(WorkspaceCodeLib)/IB-Codes $(IncludeSwitch)$(WorkspaceCodeLib)/spdlog 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)mswsock $(LibrarySwitch)ws2_32 $(LibrarySwitch)boost_system-$(blibsuffix) $(LibrarySwitch)boost_date_time-$(blibsuffix) $(LibrarySwitch)boost_thread-$(blibsuffix) $(LibrarySwitch)boost_filesystem-$(blibsuffix) $(LibrarySwitch)boost_thread-$(blibsuffix) $(LibrarySwitch)boost_chrono-$(blibsuffix) $(LibrarySwitch)boost_coroutine-$(blibsuffix) $(LibrarySwitch)boost_context-$(blibsuffix) $(LibrarySwitch)boost_regex-$(blibsuffix) $(LibrarySwitch)boost_program_options-$(blibsuffix) 
ArLibs                 :=  "mswsock" "ws2_32" "boost_system-$(blibsuffix)" "boost_date_time-$(blibsuffix)" "boost_thread-$(blibsuffix)" "boost_filesystem-$(blibsuffix)" "boost_thread-$(blibsuffix)" "boost_chrono-$(blibsuffix)" "boost_coroutine-$(blibsuffix)" "boost_context-$(blibsuffix)" "boost_regex-$(blibsuffix)" "boost_program_options-$(blibsuffix)" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(BoostLibraries) 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS := -std=c++14 -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
BinRepo:=C:\Users\Todd\Desktop\Development\CodeLite-Workspace\bin\
WorkspaceCodeLib:=C:\Users\Todd\Desktop\Development\Code-Library
BoostIncludes:=C:\Boost\include\boost-1_66
BoostLibraries:=C:\Boost\lib
blibsuffix:=mgw72-mt-x32-1_66
Objects0=$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) \
	



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
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/tws-client2.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/tws-client2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(DependSuffix): ../../Code-Library/IB-codes/tws-client2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/tws-client2.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/tws-client2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-client2.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/tws-client2.cpp

$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(ObjectSuffix): ../../Code-Library/hi-res-time2.cpp $(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/hi-res-time2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(DependSuffix): ../../Code-Library/hi-res-time2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(DependSuffix) -MM ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(PreprocessSuffix): ../../Code-Library/hi-res-time2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_hi-res-time2.cpp$(PreprocessSuffix) ../../Code-Library/hi-res-time2.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/vwap-signal-agent.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/vwap-signal-agent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(DependSuffix): ../../Code-Library/IB-codes/vwap-signal-agent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/vwap-signal-agent.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/vwap-signal-agent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_vwap-signal-agent.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/vwap-signal-agent.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/depth-tracker.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/depth-tracker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(DependSuffix): ../../Code-Library/IB-codes/depth-tracker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/depth-tracker.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/depth-tracker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_depth-tracker.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/depth-tracker.cpp

$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(ObjectSuffix): ../../Code-Library/basic-websocket-server2.cpp $(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/basic-websocket-server2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(DependSuffix): ../../Code-Library/basic-websocket-server2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(DependSuffix) -MM ../../Code-Library/basic-websocket-server2.cpp

$(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(PreprocessSuffix): ../../Code-Library/basic-websocket-server2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_basic-websocket-server2.cpp$(PreprocessSuffix) ../../Code-Library/basic-websocket-server2.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/timesales-tracker.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/timesales-tracker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(DependSuffix): ../../Code-Library/IB-codes/timesales-tracker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/timesales-tracker.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/timesales-tracker.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_timesales-tracker.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/timesales-tracker.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/orderflow-utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(DependSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/orderflow-utils.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/orderflow-utils.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_orderflow-utils.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/orderflow-utils.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(ObjectSuffix): ../../Code-Library/IB-codes/tws-tracker-database4.cpp $(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/IB-codes/tws-tracker-database4.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(DependSuffix): ../../Code-Library/IB-codes/tws-tracker-database4.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(DependSuffix) -MM ../../Code-Library/IB-codes/tws-tracker-database4.cpp

$(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(PreprocessSuffix): ../../Code-Library/IB-codes/tws-tracker-database4.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_IB-codes_tws-tracker-database4.cpp$(PreprocessSuffix) ../../Code-Library/IB-codes/tws-tracker-database4.cpp

$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(ObjectSuffix): ../../Code-Library/fast-log2.cpp $(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/Code-Library/fast-log2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(DependSuffix): ../../Code-Library/fast-log2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(DependSuffix) -MM ../../Code-Library/fast-log2.cpp

$(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(PreprocessSuffix): ../../Code-Library/fast-log2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_up_Code-Library_fast-log2.cpp$(PreprocessSuffix) ../../Code-Library/fast-log2.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Todd/Desktop/Development/CodeLite-Workspace/twsoil/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/

