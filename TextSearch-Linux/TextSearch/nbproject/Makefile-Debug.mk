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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o \
	${OBJECTDIR}/_ext/75efd69a/FileSystem.o \
	${OBJECTDIR}/TextSearch.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/TestTextSearch.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread
CXXFLAGS=-pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libTextSearch.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libTextSearch.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libTextSearch.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -shared -fPIC

${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o: ../BlockingQueue/Cpp11-BlockingQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ecf73fad
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o ../BlockingQueue/Cpp11-BlockingQueue.cpp

${OBJECTDIR}/_ext/75efd69a/FileSystem.o: ../FileSystem/FileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/75efd69a
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/75efd69a/FileSystem.o ../FileSystem/FileSystem.cpp

${OBJECTDIR}/TextSearch.o: TextSearch.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -fPIC  -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextSearch.o TextSearch.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/TestTextSearch.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -ldl -lpthread 


${TESTDIR}/tests/TestTextSearch.o: tests/TestTextSearch.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -g -I. -std=c++11 -pthread -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/TestTextSearch.o tests/TestTextSearch.cpp


${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue_nomain.o: ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o ../BlockingQueue/Cpp11-BlockingQueue.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/ecf73fad
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue_nomain.o ../BlockingQueue/Cpp11-BlockingQueue.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue.o ${OBJECTDIR}/_ext/ecf73fad/Cpp11-BlockingQueue_nomain.o;\
	fi

${OBJECTDIR}/_ext/75efd69a/FileSystem_nomain.o: ${OBJECTDIR}/_ext/75efd69a/FileSystem.o ../FileSystem/FileSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/75efd69a
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/75efd69a/FileSystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/75efd69a/FileSystem_nomain.o ../FileSystem/FileSystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/75efd69a/FileSystem.o ${OBJECTDIR}/_ext/75efd69a/FileSystem_nomain.o;\
	fi

${OBJECTDIR}/TextSearch_nomain.o: ${OBJECTDIR}/TextSearch.o TextSearch.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/TextSearch.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -std=c++11 -fPIC  -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextSearch_nomain.o TextSearch.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/TextSearch.o ${OBJECTDIR}/TextSearch_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libTextSearch.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
