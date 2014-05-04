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
	${OBJECTDIR}/src/Components/CollisionDetection.o \
	${OBJECTDIR}/src/Components/CollisionResolution.o \
	${OBJECTDIR}/src/Components/EntityID.o \
	${OBJECTDIR}/src/Components/Graphics.o \
	${OBJECTDIR}/src/Components/Movement.o \
	${OBJECTDIR}/src/Utils/Strings.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector
CXXFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/E/lib/glew-1.10.0/lib -L/E/lib/SFML-2.1/lib -L../../../../../lib/glew-1.10.0/lib -L../../../../../lib/SFML-2.1/lib -lsfml-window-d -lsfml-system-d ../libgltools/lib/liblibgltools-d.a ../libmatrix/dist/Debug/MinGW-Windows/liblibmatrix.a ../libvector/dist/Debug/MinGW-Windows/liblibvector.a ../libobj/dist/Debug/MinGW-Windows/liblibobj.a -lglew32.dll -lopengl32 ../libconf/dist/Debug/MinGW-Windows/liblibconf.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ../libgltools/lib/liblibgltools-d.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ../libmatrix/dist/Debug/MinGW-Windows/liblibmatrix.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ../libvector/dist/Debug/MinGW-Windows/liblibvector.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ../libobj/dist/Debug/MinGW-Windows/liblibobj.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ../libconf/dist/Debug/MinGW-Windows/liblibconf.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/src/Application.o: src/Application.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Application.o src/Application.cpp

${OBJECTDIR}/src/Components/CollisionDetection.o: src/Components/CollisionDetection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionDetection.o src/Components/CollisionDetection.cpp

${OBJECTDIR}/src/Components/CollisionResolution.o: src/Components/CollisionResolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/CollisionResolution.o src/Components/CollisionResolution.cpp

${OBJECTDIR}/src/Components/EntityID.o: src/Components/EntityID.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/EntityID.o src/Components/EntityID.cpp

${OBJECTDIR}/src/Components/Graphics.o: src/Components/Graphics.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Graphics.o src/Components/Graphics.cpp

${OBJECTDIR}/src/Components/Movement.o: src/Components/Movement.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Components
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Components/Movement.o src/Components/Movement.cpp

${OBJECTDIR}/src/Utils/Strings.o: src/Utils/Strings.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/E/lib/SFML-2.1/include -I/E/lib/glew-1.10.0/include -I../libgltools/include -I../libmatrix/include -I../libvector/include -I../libobj/include -I../../../../../lib/glew-1.10.0/include -I../../../../../lib/SFML-2.1/include -I../libconf/src -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Utils/Strings.o src/Utils/Strings.cpp

# Subprojects
.build-subprojects:
	cd ../libgltools && ${MAKE}  -f Makefile CONF=Debug
	cd ../libmatrix && ${MAKE}  -f Makefile CONF=Debug
	cd ../libvector && ${MAKE}  -f Makefile CONF=Debug
	cd ../libobj && ${MAKE}  -f Makefile CONF=Debug
	cd ../libconf && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pongclone.exe

# Subprojects
.clean-subprojects:
	cd ../libgltools && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../libmatrix && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../libvector && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../libobj && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../libconf && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
