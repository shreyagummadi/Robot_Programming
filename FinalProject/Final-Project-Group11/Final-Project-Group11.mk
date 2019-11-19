##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Final-Project-Group11
ConfigurationName      :=Debug
WorkspacePath          :=/home/ts/UMD/Cu_Ag_Au/FinalProject
ProjectPath            :=/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=TS
Date                   :=18/11/19
CodeLitePath           :=/home/ts/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Final-Project-Group11.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)src/LandBasedRobot $(IncludeSwitch)src/LandBasedTracked $(IncludeSwitch)src/LandBasedWheeled 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -Wmain -std=c++14 -Wall -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Maze_maze.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_API_api.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(ObjectSuffix): src/Algorithm/algorithm.cpp $(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/Algorithm/algorithm.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(DependSuffix): src/Algorithm/algorithm.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(DependSuffix) -MM src/Algorithm/algorithm.cpp

$(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(PreprocessSuffix): src/Algorithm/algorithm.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Algorithm_algorithm.cpp$(PreprocessSuffix) src/Algorithm/algorithm.cpp

$(IntermediateDirectory)/src_Maze_maze.cpp$(ObjectSuffix): src/Maze/maze.cpp $(IntermediateDirectory)/src_Maze_maze.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/Maze/maze.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Maze_maze.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Maze_maze.cpp$(DependSuffix): src/Maze/maze.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Maze_maze.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Maze_maze.cpp$(DependSuffix) -MM src/Maze/maze.cpp

$(IntermediateDirectory)/src_Maze_maze.cpp$(PreprocessSuffix): src/Maze/maze.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Maze_maze.cpp$(PreprocessSuffix) src/Maze/maze.cpp

$(IntermediateDirectory)/src_API_api.cpp$(ObjectSuffix): src/API/api.cpp $(IntermediateDirectory)/src_API_api.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/API/api.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_API_api.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_API_api.cpp$(DependSuffix): src/API/api.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_API_api.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_API_api.cpp$(DependSuffix) -MM src/API/api.cpp

$(IntermediateDirectory)/src_API_api.cpp$(PreprocessSuffix): src/API/api.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_API_api.cpp$(PreprocessSuffix) src/API/api.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix): src/LandBasedWheeled/landbasedwheeled.cpp $(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/LandBasedWheeled/landbasedwheeled.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix): src/LandBasedWheeled/landbasedwheeled.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(DependSuffix) -MM src/LandBasedWheeled/landbasedwheeled.cpp

$(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(PreprocessSuffix): src/LandBasedWheeled/landbasedwheeled.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedWheeled_landbasedwheeled.cpp$(PreprocessSuffix) src/LandBasedWheeled/landbasedwheeled.cpp

$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix): src/LandBasedTracked/landbasedtracked.cpp $(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/LandBasedTracked/landbasedtracked.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix): src/LandBasedTracked/landbasedtracked.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(DependSuffix) -MM src/LandBasedTracked/landbasedtracked.cpp

$(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(PreprocessSuffix): src/LandBasedTracked/landbasedtracked.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedTracked_landbasedtracked.cpp$(PreprocessSuffix) src/LandBasedTracked/landbasedtracked.cpp

$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix): src/LandBasedRobot/landbasedrobot.cpp $(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ts/UMD/Cu_Ag_Au/FinalProject/Final-Project-Group11/src/LandBasedRobot/landbasedrobot.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix): src/LandBasedRobot/landbasedrobot.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(DependSuffix) -MM src/LandBasedRobot/landbasedrobot.cpp

$(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(PreprocessSuffix): src/LandBasedRobot/landbasedrobot.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_LandBasedRobot_landbasedrobot.cpp$(PreprocessSuffix) src/LandBasedRobot/landbasedrobot.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


