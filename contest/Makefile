WORKSPACE_DIR := $(abspath $(addprefix $(dir $(lastword ${MAKEFILE_LIST})), /..))
LIB_DIR := ${WORKSPACE_DIR}/lib
BUILD_DIR := ${WORKSPACE_DIR}/build
$(shell mkdir -p ${BUILD_DIR})
#====================================================================================
# Target files
SRC ?= main.cpp
BASE := $(basename $(notdir ${SRC}))
DEBUG_EXE := ${BUILD_DIR}/${BASE}_debug.exe
RELEASE_EXE := ${BUILD_DIR}/${BASE}_release.exe
BUNDLED := ${BUILD_DIR}/${BASE}_bundled.cpp
CASEDIR := ${BUILD_DIR}/${BASE}_case
#====================================================================================
# Command config
CXX := clang++
FLAGS := -std=gnu++20 -Wall -Wextra -I${LIB_DIR}/algolib/src -I${LIB_DIR}/ac-library -DHOGEPACHI=1
DEBUG_FLAGS := -g3 -fsanitize=undefined,address
RELEASE_FLAGS := -O2
CPT := cpt
BUNDLE := cpp_bundle
#====================================================================================
# Input
VERBOSE ?= 
TL ?= 3000
#====================================================================================

.PHONY: help
help:
	@echo "Usage:"
	@echo "    make bd SRC=main.cpp -- Build(Debug) main.cpp into ${BUILD_DIR}/main_debug.exe"
	@echo "    make br SRC=main.cpp -- Build(Relase) main.cpp into ${BUILD_DIR}/main_release.exe"
	@echo "    make e  SRC=main.cpp -- Bundle main.cpp into ${BUILD_DIR}/main_bundled.cpp"
	@echo "Default SRC is main.cpp if not specified"

.PHONY: clean_cases
clean_cases:
	${RM} ${CASEDIR}/*.txt
	${RM} ${CASEDIR}/*hack*

.PHONY: clean
clean: clean_cases
	${RM} ${DEBUG_EXE} ${RELEASE_EXE} ${BUNDLED}
	
${DEBUG_EXE}: ${SRC}
	${CXX} $< -o $@ ${FLAGS} ${DEBUG_FLAGS}
${RELEASE_EXE}: ${SRC}
	${CXX} $< -o $@ ${FLAGS} ${RELEASE_FLAGS}
${BUNDLED}: ${SRC}
	${BUNDLE} $< -o $@ -- ${FLAGS}
${CASEDIR}: ${SRC}
	mkdir -p ${CASEDIR}

.PHONY: bd
bd: ${DEBUG_EXE}
.PHONY: br
br: ${RELEASE_EXE}

.PHONY: rd
rd: ${DEBUG_EXE}
	${DEBUG_EXE}
.PHONY: rr
rr: ${RELEASE_EXE}
	${RELEASE_EXE}

.PHONY: tbd
tbd: ${CASEDIR} ${DEBUG_EXE} clean_cases
	${CPT} tb -c "${DEBUG_EXE}" -d ${CASEDIR} ${VERBOSE}
.PHONY: tbr
tbr: ${CASEDIR} ${RELEASE_EXE} clean_cases
	${CPT} tb -c "${RELEASE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: e
e: ${BUNDLED}

