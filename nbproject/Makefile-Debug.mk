#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/src/Application.o \
	${OBJECTDIR}/src/Components/AIComponent.o \
	${OBJECTDIR}/src/Components/CollisionDetection.o \
	${OBJECTDIR}/src/Components/CollisionResolution.o \
	${OBJECTDIR}/src/Components/EntityId.o \
	${OBJECTDIR}/src/Components/GameLogicComponent.o \
	${OBJECTDIR}/src/Components/Graphics.o \
	${OBJECTDIR}/src/Components/ModelId.o \
	${OBJECTDIR}/src/Components/Movement.o \
	${OBJECTDIR}/src/Components/RNGSystem.o \
	${OBJECTDIR}/src/Components/ShaderId.o \
	${OBJECTDIR}/src/Components/TextureId.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector
CXXFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/lib/glew-1.10.0/lib -L/E/lib/SFML-2.1/lib -L../../../../../lib/glew-1.10.0/lib -L../../../../../lib/SFML-2.1/lib -L/E/lib/glew-1.10.0/lib -L../libtga/dist/Debug/MinGW-Windows -L../libtools/dist/Debug/MinGW-Windows -L../libmatrix/dist/Debug/MinGW-Windows -L../libconf/dist/Debug/MinGW-Windows -L../libgltools/dist/Debug/MinGW-Windows -L../libobj/dist/Debug/MinGW-Windows -L../libvector/dist/Debug/MinGW-Windows -llibobj -llibgltools -llibconf -llibvector -llibmatrix -llibtga -llibtools -lsfml-window-d -lsfml-system-d -lglew32.dll -lopengl32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Components/AIComponent.o: src/Components/AIComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/AIComponent.o src/Components/AIComponent.cpp

${OBJECTDIR}/src/Components/CollisionDetection.o: src/Components/CollisionDetection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionDetection.o src/Components/CollisionDetection.cpp

${OBJECTDIR}/src/Components/CollisionResolution.o: src/Components/CollisionResolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionResolution.o src/Components/CollisionResolution.cpp

${OBJECTDIR}/src/Components/EntityId.o: src/Components/EntityId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/EntityId.o src/Components/EntityId.cpp

${OBJECTDIR}/src/Components/GameLogicComponent.o: src/Components/GameLogicComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/GameLogicComponent.o src/Components/GameLogicComponent.cpp

${OBJECTDIR}/src/Components/Graphics.o: src/Components/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Graphics.o src/Components/Graphics.cpp

${OBJECTDIR}/src/Components/ModelId.o: src/Components/ModelId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/ModelId.o src/Components/ModelId.cpp

${OBJECTDIR}/src/Components/Movement.o: src/Components/Movement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Movement.o src/Components/Movement.cpp

${OBJECTDIR}/src/Components/RNGSystem.o: src/Components/RNGSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/RNGSystem.o src/Components/RNGSystem.cpp

${OBJECTDIR}/src/Components/ShaderId.o: src/Components/ShaderId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/ShaderId.o src/Components/ShaderId.cpp

${OBJECTDIR}/src/Components/TextureId.o: src/Components/TextureId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/src -I../libmatrix/include -I../libvector/src -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libtga/src -I../libtools/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/TextureId.o src/Components/TextureId.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
