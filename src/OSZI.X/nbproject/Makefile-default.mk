#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=init.c main.c LCD_Driver/LCD_Driver.c DAC_Driver/DAC_Driver.c TIMER_Driver/TIMER_Driver.c UART_Driver/UART_Driver.c ADC_Driver/ADC_Driver.c TOUCH_Driver/TOUCH_Driver.c OSZI_Driver/OSZI_Driver.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o ${OBJECTDIR}/UART_Driver/UART_Driver.o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o
POSSIBLE_DEPFILES=${OBJECTDIR}/init.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d ${OBJECTDIR}/UART_Driver/UART_Driver.o.d ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o ${OBJECTDIR}/UART_Driver/UART_Driver.o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o

# Source Files
SOURCEFILES=init.c main.c LCD_Driver/LCD_Driver.c DAC_Driver/DAC_Driver.c TIMER_Driver/TIMER_Driver.c UART_Driver/UART_Driver.c ADC_Driver/ADC_Driver.c TOUCH_Driver/TOUCH_Driver.c OSZI_Driver/OSZI_Driver.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GC006
MP_LINKER_FILE_OPTION=,--script=p24FJ128GC006.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/init.o: init.c  .generated_files/flags/default/eac22eaa1646a281a9cc2aa9997f86be39a50b18 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a9716be405c5cd91133aa14f9fb8856b3720473b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_Driver/LCD_Driver.o: LCD_Driver/LCD_Driver.c  .generated_files/flags/default/6179a6c8a4e570bcd90ac8bf64a2fb7847716f55 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/LCD_Driver" 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_Driver/LCD_Driver.c  -o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/DAC_Driver/DAC_Driver.o: DAC_Driver/DAC_Driver.c  .generated_files/flags/default/c0c9a550f761b15134580313ac3f93eb942c054f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/DAC_Driver" 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  DAC_Driver/DAC_Driver.c  -o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o: TIMER_Driver/TIMER_Driver.c  .generated_files/flags/default/21e7e8cdef1fe9bebce63e84d227fdac0c9883a7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TIMER_Driver" 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER_Driver/TIMER_Driver.c  -o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART_Driver/UART_Driver.o: UART_Driver/UART_Driver.c  .generated_files/flags/default/567eacc97c10c881e16037c72a0a161ae2bf9e30 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/UART_Driver" 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o.d 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART_Driver/UART_Driver.c  -o ${OBJECTDIR}/UART_Driver/UART_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART_Driver/UART_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC_Driver/ADC_Driver.o: ADC_Driver/ADC_Driver.c  .generated_files/flags/default/3f81538f84ddef37ebb7e808b1155c26cb0635c1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ADC_Driver" 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_Driver/ADC_Driver.c  -o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o: TOUCH_Driver/TOUCH_Driver.c  .generated_files/flags/default/c8765b3678eac8e1392b0721845e2d060783f80b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TOUCH_Driver" 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TOUCH_Driver/TOUCH_Driver.c  -o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o: OSZI_Driver/OSZI_Driver.c  .generated_files/flags/default/34e3f144b0b561223c1f304ddb652623669d1a4a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OSZI_Driver" 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OSZI_Driver/OSZI_Driver.c  -o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/init.o: init.c  .generated_files/flags/default/734096d51aaf338a5d3769808d156223ecd7eb78 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f6dc29f5dd77d046cc9e9b10f43b1ebea334b22a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_Driver/LCD_Driver.o: LCD_Driver/LCD_Driver.c  .generated_files/flags/default/594d36d56d40166e64bbae72c76029f2e1aa321e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/LCD_Driver" 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_Driver/LCD_Driver.c  -o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/DAC_Driver/DAC_Driver.o: DAC_Driver/DAC_Driver.c  .generated_files/flags/default/a54791e5303d996e3c19682144eff823c3ed58b3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/DAC_Driver" 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  DAC_Driver/DAC_Driver.c  -o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o: TIMER_Driver/TIMER_Driver.c  .generated_files/flags/default/aff2cbe8ce408d77e54e111295ac1b658b5f139f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TIMER_Driver" 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER_Driver/TIMER_Driver.c  -o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART_Driver/UART_Driver.o: UART_Driver/UART_Driver.c  .generated_files/flags/default/2038d7ce424bf22b54a69f2f7980a5eab200b8f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/UART_Driver" 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o.d 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART_Driver/UART_Driver.c  -o ${OBJECTDIR}/UART_Driver/UART_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART_Driver/UART_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC_Driver/ADC_Driver.o: ADC_Driver/ADC_Driver.c  .generated_files/flags/default/79e53508f0fd6aca30d6fc104c6676a15217bbff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ADC_Driver" 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_Driver/ADC_Driver.c  -o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o: TOUCH_Driver/TOUCH_Driver.c  .generated_files/flags/default/bb5c19ba58d67d8c958c345b791d6afa120eba98 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TOUCH_Driver" 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TOUCH_Driver/TOUCH_Driver.c  -o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o: OSZI_Driver/OSZI_Driver.c  .generated_files/flags/default/54fce69d99e20047d6f1aaa84b027d584e1951f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OSZI_Driver" 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OSZI_Driver/OSZI_Driver.c  -o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=50,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=50,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/OSZI.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}
