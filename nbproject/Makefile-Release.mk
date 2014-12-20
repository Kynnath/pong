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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
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
	${OBJECTDIR}/src/Components/TextureId.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector -std=c++1y
CXXFLAGS=-m64 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector -std=c++1y

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../../../lib/freetype-2.5.3/lib -L../../../../../lib/glew-1.11.0/lib -L../../../../../lib/SFML-2.1/lib -L../libconf/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libcsv/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libfont/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libgltools/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libgui/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libmatrix/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libmessenger/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libobj/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libtga/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libtools/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -L../libvector/${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM} -llibgui -llibfont -lsfml-window -lsfml-system -llibgltools -lfreetype -lglew32 -llibtga -lopengl32 -lz -llibconf -llibcsv -llibmatrix -llibmessenger -llibobj -llibtools -llibvector

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone ${OBJECTFILES} ${LDLIBSOPTIONS} -DGLEW_STATIC -s

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Components/AIComponent.o: src/Components/AIComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/AIComponent.o src/Components/AIComponent.cpp

${OBJECTDIR}/src/Components/CollisionDetection.o: src/Components/CollisionDetection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionDetection.o src/Components/CollisionDetection.cpp

${OBJECTDIR}/src/Components/CollisionResolution.o: src/Components/CollisionResolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionResolution.o src/Components/CollisionResolution.cpp

${OBJECTDIR}/src/Components/EntityId.o: src/Components/EntityId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/EntityId.o src/Components/EntityId.cpp

${OBJECTDIR}/src/Components/GameLogicComponent.o: src/Components/GameLogicComponent.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/GameLogicComponent.o src/Components/GameLogicComponent.cpp

${OBJECTDIR}/src/Components/Graphics.o: src/Components/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Graphics.o src/Components/Graphics.cpp

${OBJECTDIR}/src/Components/ModelId.o: src/Components/ModelId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/ModelId.o src/Components/ModelId.cpp

${OBJECTDIR}/src/Components/Movement.o: src/Components/Movement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Movement.o src/Components/Movement.cpp

${OBJECTDIR}/src/Components/RNGSystem.o: src/Components/RNGSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/RNGSystem.o src/Components/RNGSystem.cpp

${OBJECTDIR}/src/Components/ShaderId.o: src/Components/ShaderId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/ShaderId.o src/Components/ShaderId.cpp

${OBJECTDIR}/src/Components/TextureId.o: src/Components/TextureId.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/TextureId.o src/Components/TextureId.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Wall -s -DGLEW_STATIC -I../../../../../lib/freetype-2.5.3/include -I../../../../../lib/glew-1.11.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -I../libfont/src -I../libgltools/src -I../libgui/src -I../libmatrix/src -I../libmessenger/src -I../libobj/src -I../libtga/src -I../libtools/src -I../libvector/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

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
