WORKSPACE_DIR := $(abspath $(addprefix $(dir $(lastword ${MAKEFILE_LIST})), /..))
LIB_DIR := ${WORKSPACE_DIR}/lib
BUILD_DIR := ${WORKSPACE_DIR}/build
$(shell mkdir -p ${BUILD_DIR})
#====================================================================================
# Source files
SRC ?= main.cpp
BASE := $(basename $(notdir ${SRC}))
SRC_GI ?= ${BASE}_gi.cpp
SRC_GO ?= ${BASE}_go.cpp
SRC_JUDGE ?= ${BASE}_judge.cpp
# Exe
DEBUG_EXE := ${BUILD_DIR}/${BASE}_debug.exe
RELEASE_EXE := ${BUILD_DIR}/${BASE}_release.exe
GI_EXE := ${BUILD_DIR}/${BASE}_gi.exe
GO_EXE := ${BUILD_DIR}/${BASE}_go.exe
JUDGE_EXE := ${BUILD_DIR}/${BASE}_judge.exe
# Bundle
BUNDLED := ${BUILD_DIR}/${BASE}_bundled.cpp
# Testcase
CASEDIR := ${BUILD_DIR}/${BASE}_case
#====================================================================================
# Command config
CXX := clang++
FLAGS := -std=gnu++20 -Wall -Wextra -I${LIB_DIR}/algolib/src -I${LIB_DIR}/ac-library
DEBUG_FLAGS := -g3 -fsanitize=undefined,address -fno-omit-frame-pointer -DHOGEPACHI
RELEASE_FLAGS := -O2 -DHOGEPACHI
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
	@echo "    [Clean]"
	@echo "    make c                                                                    -- Clean all"
	@echo "    make ct                                                                   -- Clean testcases(only generated)"
	@echo "    make cta                                                                  -- Clean testcases(all)"
	@echo "    [Build]"
	@echo "    make bd  SRC=main.cpp                                                     -- Build(Debug)                main.cpp"
	@echo "    make br  SRC=main.cpp                                                     -- Build(Relase)               main.cpp"

	@echo "    [Run]"
	@echo "    make rd  SRC=main.cpp                                                     -- Run(Debug)                  main.exe"
	@echo "    make rr  SRC=main.cpp                                                     -- Run(Relase)                 main.exe"

	@echo "    [Test(Batch)]"
	@echo "    make tbd SRC=main.cpp                                             TL=3000 -- Batch    Test(Debug)        main.cpp"
	@echo "    make tbr SRC=main.cpp                                             TL=3000 -- Batch    Test(Relase)       main.cpp"
	@echo "    [Test(Special)]"
	@echo "    make tsd SRC=main.cpp                    SRC_JUDGE=main_judge.cpp TL=3000 -- Special  Test(Debug)        main.cpp w/ main_judge.cpp"
	@echo "    make tsr SRC=main.cpp                    SRC_JUDGE=main_judge.cpp TL=3000 -- Special  Test(Relase)       main.cpp w/ main_judge.cpp"
	@echo "    [Test(Reactive)]"
	@echo "    make trd SRC=main.cpp                    SRC_JUDGE=main_judge.cpp TL=3000 -- Reactive Test(Debug)        main.cpp w/ main_judge.cpp"
	@echo "    make trr SRC=main.cpp                    SRC_JUDGE=main_judge.cpp TL=3000 -- Reactive Test(Relase)       main.cpp w/ main_judge.cpp"

	@echo "    [Hack(Batch)]"
	@echo "    make hbw SRC=main.cpp SRC_GI=main_gi.cpp SRC_GO=main_go.cpp       TL=3000 -- Generate Batch    Hack(WA)  main.cpp"
	@echo "    make hbr SRC=main.cpp SRC_GI=main_gi.cpp                          TL=3000 -- Generate Batch    Hack(RE)  main.cpp"
	@echo "    make hbt SRC=main.cpp SRC_GI=main_gi.cpp                          TL=3000 -- Generate Batch    Hack(TLE) main.cpp"
	@echo "    [Hack(Special)]"
	@echo "    make hsw SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Special  Hack(WA)  main.cpp w/ main_judge.cpp"
	@echo "    make hsr SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Special  Hack(RE)  main.cpp w/ main_judge.cpp"
	@echo "    make hst SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Special  Hack(TLE) main.cpp w/ main_judge.cpp"
	@echo "    [Hack(Reactive)]"
	@echo "    make hrw SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Reactive Hack(WA)  main.cpp w/ main_judge.cpp"
	@echo "    make hrr SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Reactive Hack(RE)  main.cpp w/ main_judge.cpp"
	@echo "    make hrt SRC=main.cpp SRC_GI=main_gi.cpp SRC_JUDGE=main_judge.cpp TL=3000 -- Generate Reactive Hack(TLE) main.cpp w/ main_judge.cpp"

	@echo "    [Expand]"
	@echo "    make e   SRC=main.cpp                                                     -- Bundle                      main.cpp -> main_bundled.cpp"

	@echo "    [Open Testcase]"
	@echo "    make i{index}                                                             -- Open {index}.in"
	@echo "    make o{index}                                                             -- Open {index}.out"

	@echo "Variable:"
	@echo "    SRC       -- Program file          (default: main.cpp)"
	@echo "    SRC_GI    -- Input generator file  (default: ${BASE}_gi.cpp)"
	@echo "    SRC_GO    -- Output generator file (default: ${BASE}_go.cpp)"
	@echo "    SRC_JUDGE -- Special judge file    (default: ${BASE}_judge.cpp)"
	@echo "    TL        -- Timelimit for program (default: 3000[ms])"
	@echo "    VERBOSE   -- Verbosity like \"-v\" or \"-vv\" (default: )"

.PHONY: ct
ct:
	${RM} ${CASEDIR}/*.txt
	${RM} ${CASEDIR}/Generated_*

.PHONY: cta
cta: ct
	${RM} ${CASEDIR}/*.in
	${RM} ${CASEDIR}/*.out

.PHONY: c
clean: cta
	${RM} ${DEBUG_EXE} ${RELEASE_EXE} ${GI_EXE} ${GO_EXE} ${JUDGE_EXE} ${BUNDLED}
	
${DEBUG_EXE}: ${SRC}
	${CXX} $< -o $@ ${FLAGS} ${DEBUG_FLAGS}
${RELEASE_EXE}: ${SRC}
	${CXX} $< -o $@ ${FLAGS} ${RELEASE_FLAGS}
${GI_EXE}: ${SRC_GI}
	${CXX} $< -o $@ ${FLAGS} ${RELEASE_FLAGS}
${GO_EXE}: ${SRC_GO}
	${CXX} $< -o $@ ${FLAGS} ${RELEASE_FLAGS}
${JUDGE_EXE}: ${SRC_JUDGE}
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
tbd: ${CASEDIR} ${DEBUG_EXE}
	${CPT} t b -c "${DEBUG_EXE}"   -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: tbr
tbr: ${CASEDIR} ${RELEASE_EXE}
	${CPT} t b -c "${RELEASE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: tsd
tsd: ${CASEDIR} ${DEBUG_EXE} ${JUDGE_EXE}
	${CPT} t s -c "${DEBUG_EXE}"   -j "${JUDGE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: tsr
tsr: ${CASEDIR} ${RELEASE_EXE} ${JUDGE_EXE}
	${CPT} t s -c "${RELEASE_EXE}" -j "${JUDGE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: trd
trd: ${CASEDIR} ${DEBUG_EXE} ${JUDGE_EXE}
	${CPT} t r -c "${DEBUG_EXE}"   -j "${JUDGE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: trr
trr: ${CASEDIR} ${RELEASE_EXE} ${JUDGE_EXE}
	${CPT} t r -c "${RELEASE_EXE}" -j "${JUDGE_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: hbw
hbw: ${CASEDIR} ${DEBUG_EXE} ${GI_EXE} ${GO_EXE}
	${CPT} h b -c "${DEBUG_EXE}"   -i "${GI_EXE}" -o "${GO_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: hbr
hbr: ${CASEDIR} ${DEBUG_EXE} ${GI_EXE}
	${CPT} h b -c "${DEBUG_EXE}"   -i "${GI_EXE}"                -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: hbt
hbt: ${CASEDIR} ${RELEASE_EXE} ${GI_EXE}
	${CPT} h b -c "${RELEASE_EXE}" -i "${GI_EXE}"                -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: hsw
hsw: ${CASEDIR} ${DEBUG_EXE} ${GI_EXE} ${JUDGE_EXE}
	${CPT} h s -c "${DEBUG_EXE}"   -j "${JUDGE_EXE}" -i "${GI_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: hsr
hsr: hsw
.PHONY: hst
hst: ${CASEDIR} ${RELEASE_EXE} ${GI_EXE} ${JUDGE_EXE}
	${CPT} h s -c "${RELEASE_EXE}" -j "${JUDGE_EXE}" -i "${GI_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: hrw
hrw: ${CASEDIR} ${DEBUG_EXE} ${GI_EXE} ${JUDGE_EXE}
	${CPT} h r -c "${DEBUG_EXE}"   -j "${JUDGE_EXE}" -i "${GI_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}
.PHONY: hrr
hrr: hrw
.PHONY: hrt
hrt: ${CASEDIR} ${RELEASE_EXE} ${GI_EXE} ${JUDGE_EXE}
	${CPT} h r -c "${RELEASE_EXE}" -j "${JUDGE_EXE}" -i "${GI_EXE}" -d ${CASEDIR} -t ${TL} ${VERBOSE}

.PHONY: e
e: ${BUNDLED}

.PHONY: i%
i%:
	hx ${CASEDIR}/${@:i%=%}.in

.PHONY: o%
o%:
	hx ${CASEDIR}/${@:o%=%}.out
