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
FINAL_IMAGE=${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=init.c main.c LCD_Driver/LCD_Driver.c DAC_Driver/DAC_Driver.c TIMER_Driver/TIMER_Driver.c UART_Driver/UART_Driver.c ADC_Driver/ADC_Driver.c TOUCH_Driver/TOUCH_Driver.c OSZI_Driver/OSZI_Driver.c SD_Driver/drv_spi_16bit.c SD_Driver/sd_spi.c SD_Driver/system.c SD_Driver/rtcc.c SD_Driver/fileio.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o ${OBJECTDIR}/UART_Driver/UART_Driver.o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o ${OBJECTDIR}/SD_Driver/sd_spi.o ${OBJECTDIR}/SD_Driver/system.o ${OBJECTDIR}/SD_Driver/rtcc.o ${OBJECTDIR}/SD_Driver/fileio.o
POSSIBLE_DEPFILES=${OBJECTDIR}/init.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d ${OBJECTDIR}/UART_Driver/UART_Driver.o.d ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o.d ${OBJECTDIR}/SD_Driver/sd_spi.o.d ${OBJECTDIR}/SD_Driver/system.o.d ${OBJECTDIR}/SD_Driver/rtcc.o.d ${OBJECTDIR}/SD_Driver/fileio.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/init.o ${OBJECTDIR}/main.o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o ${OBJECTDIR}/UART_Driver/UART_Driver.o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o ${OBJECTDIR}/SD_Driver/sd_spi.o ${OBJECTDIR}/SD_Driver/system.o ${OBJECTDIR}/SD_Driver/rtcc.o ${OBJECTDIR}/SD_Driver/fileio.o

# Source Files
SOURCEFILES=init.c main.c LCD_Driver/LCD_Driver.c DAC_Driver/DAC_Driver.c TIMER_Driver/TIMER_Driver.c UART_Driver/UART_Driver.c ADC_Driver/ADC_Driver.c TOUCH_Driver/TOUCH_Driver.c OSZI_Driver/OSZI_Driver.c SD_Driver/drv_spi_16bit.c SD_Driver/sd_spi.c SD_Driver/system.c SD_Driver/rtcc.c SD_Driver/fileio.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GC006
MP_LINKER_FILE_OPTION=,--script=p24FJ128GC006.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/init.o: init.c  .generated_files/flags/default/5d1bb8b507d14073746d32da067aed838336360e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/d3bba225384b5a0d44e19c572b7cbabaf8fc7095 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_Driver/LCD_Driver.o: LCD_Driver/LCD_Driver.c  .generated_files/flags/default/c9a0c345888e3d47779081ef783e735241c126b1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/LCD_Driver" 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_Driver/LCD_Driver.c  -o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/DAC_Driver/DAC_Driver.o: DAC_Driver/DAC_Driver.c  .generated_files/flags/default/66e659ef9a39bdd4f925cdfbf43bd3c03748be37 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/DAC_Driver" 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  DAC_Driver/DAC_Driver.c  -o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o: TIMER_Driver/TIMER_Driver.c  .generated_files/flags/default/d60c90c7af20c4dde353591efd4f87b8a20bd66e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TIMER_Driver" 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER_Driver/TIMER_Driver.c  -o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART_Driver/UART_Driver.o: UART_Driver/UART_Driver.c  .generated_files/flags/default/951d5374b5ea9153bccb5d90dea8d2977a83a40a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/UART_Driver" 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o.d 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART_Driver/UART_Driver.c  -o ${OBJECTDIR}/UART_Driver/UART_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART_Driver/UART_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC_Driver/ADC_Driver.o: ADC_Driver/ADC_Driver.c  .generated_files/flags/default/b84de863e30b9273d25e3e1dd11a3921dee5dddd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ADC_Driver" 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_Driver/ADC_Driver.c  -o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o: TOUCH_Driver/TOUCH_Driver.c  .generated_files/flags/default/6a2971dbd942f4c6888a36e818df5249781947a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TOUCH_Driver" 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TOUCH_Driver/TOUCH_Driver.c  -o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o: OSZI_Driver/OSZI_Driver.c  .generated_files/flags/default/179a8f02964d287c61918cdc413c2cc3f3f6e811 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OSZI_Driver" 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OSZI_Driver/OSZI_Driver.c  -o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/drv_spi_16bit.o: SD_Driver/drv_spi_16bit.c  .generated_files/flags/default/bd8d5fdf8eace56591aa8872e5feb402c4e9b15 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/drv_spi_16bit.c  -o ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/drv_spi_16bit.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/sd_spi.o: SD_Driver/sd_spi.c  .generated_files/flags/default/2d1928ada2722ec3984f7fcef41261103815e31f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/sd_spi.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/sd_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/sd_spi.c  -o ${OBJECTDIR}/SD_Driver/sd_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/sd_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/system.o: SD_Driver/system.c  .generated_files/flags/default/37b82f915b064b64138adfa757ccc71e7ec89d06 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/system.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/system.c  -o ${OBJECTDIR}/SD_Driver/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/rtcc.o: SD_Driver/rtcc.c  .generated_files/flags/default/ef99d1efe967366623fab9876f845233ad31eb77 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/rtcc.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/rtcc.c  -o ${OBJECTDIR}/SD_Driver/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/rtcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/fileio.o: SD_Driver/fileio.c  .generated_files/flags/default/4c8b3265840018a3641790df562b856dad261992 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/fileio.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/fileio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/fileio.c  -o ${OBJECTDIR}/SD_Driver/fileio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/fileio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/init.o: init.c  .generated_files/flags/default/2cfde71d613f311d8f13eca5bb6ef72175044536 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/init.o.d 
	@${RM} ${OBJECTDIR}/init.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  init.c  -o ${OBJECTDIR}/init.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/init.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/a0f68544896add4effa34eab517e4a84d278c426 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/LCD_Driver/LCD_Driver.o: LCD_Driver/LCD_Driver.c  .generated_files/flags/default/4740fde727f7d8419636b0a8acdd81947a4a92b8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/LCD_Driver" 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d 
	@${RM} ${OBJECTDIR}/LCD_Driver/LCD_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  LCD_Driver/LCD_Driver.c  -o ${OBJECTDIR}/LCD_Driver/LCD_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/LCD_Driver/LCD_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/DAC_Driver/DAC_Driver.o: DAC_Driver/DAC_Driver.c  .generated_files/flags/default/535a9a0b3247ccb6d1fae08aab9c14e184dd6548 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/DAC_Driver" 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d 
	@${RM} ${OBJECTDIR}/DAC_Driver/DAC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  DAC_Driver/DAC_Driver.c  -o ${OBJECTDIR}/DAC_Driver/DAC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/DAC_Driver/DAC_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o: TIMER_Driver/TIMER_Driver.c  .generated_files/flags/default/962b57422214978c089a4833553c7f2f8adb0b4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TIMER_Driver" 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d 
	@${RM} ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TIMER_Driver/TIMER_Driver.c  -o ${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TIMER_Driver/TIMER_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/UART_Driver/UART_Driver.o: UART_Driver/UART_Driver.c  .generated_files/flags/default/7dd8c3e1215ce300d78244aead3f8bde439b958 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/UART_Driver" 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o.d 
	@${RM} ${OBJECTDIR}/UART_Driver/UART_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  UART_Driver/UART_Driver.c  -o ${OBJECTDIR}/UART_Driver/UART_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/UART_Driver/UART_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ADC_Driver/ADC_Driver.o: ADC_Driver/ADC_Driver.c  .generated_files/flags/default/a5a6e117660ad643d3399c2a586aaefd365afb0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/ADC_Driver" 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d 
	@${RM} ${OBJECTDIR}/ADC_Driver/ADC_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ADC_Driver/ADC_Driver.c  -o ${OBJECTDIR}/ADC_Driver/ADC_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ADC_Driver/ADC_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o: TOUCH_Driver/TOUCH_Driver.c  .generated_files/flags/default/f26f5b9a03471e5a7aac987e2faaba6e96ef460d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/TOUCH_Driver" 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d 
	@${RM} ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  TOUCH_Driver/TOUCH_Driver.c  -o ${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/TOUCH_Driver/TOUCH_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o: OSZI_Driver/OSZI_Driver.c  .generated_files/flags/default/38040127013e1c32539d733557f01e6e1bd18255 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/OSZI_Driver" 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d 
	@${RM} ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  OSZI_Driver/OSZI_Driver.c  -o ${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/OSZI_Driver/OSZI_Driver.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/drv_spi_16bit.o: SD_Driver/drv_spi_16bit.c  .generated_files/flags/default/559c1a7db4f2fc797683fff3d285214c9e5db00a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/drv_spi_16bit.c  -o ${OBJECTDIR}/SD_Driver/drv_spi_16bit.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/drv_spi_16bit.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/sd_spi.o: SD_Driver/sd_spi.c  .generated_files/flags/default/3ed30f19e0f2fdfec4159e55c90283f47b5e6dae .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/sd_spi.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/sd_spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/sd_spi.c  -o ${OBJECTDIR}/SD_Driver/sd_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/sd_spi.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/system.o: SD_Driver/system.c  .generated_files/flags/default/999bfe4be8c39aa2c163f3eee1b272ed7d584040 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/system.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/system.c  -o ${OBJECTDIR}/SD_Driver/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/rtcc.o: SD_Driver/rtcc.c  .generated_files/flags/default/560c87b52c9209a78b3673bb35bd79d77b237a5d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/rtcc.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/rtcc.c  -o ${OBJECTDIR}/SD_Driver/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/rtcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/SD_Driver/fileio.o: SD_Driver/fileio.c  .generated_files/flags/default/743a519fc57b716e6c57fd46d2e0153a38609f69 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/SD_Driver" 
	@${RM} ${OBJECTDIR}/SD_Driver/fileio.o.d 
	@${RM} ${OBJECTDIR}/SD_Driver/fileio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  SD_Driver/fileio.c  -o ${OBJECTDIR}/SD_Driver/fileio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/SD_Driver/fileio.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--heap=50,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/SD.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/SD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=50,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/SD.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
