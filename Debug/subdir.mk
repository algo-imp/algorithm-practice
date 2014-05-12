################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MinCostMaxFlow.cpp \
../backtrack_permutation.cpp \
../backtrack_subsets.cpp \
../codeforces-round225-div1-A.cpp \
../dijkstra.cpp \
../fft.cpp \
../geometry.cpp \
../kmp.cpp \
../main.cpp \
../math.cpp \
../point.cpp \
../srm156-div1-lev3.cpp \
../srm166-div2-lev3.cpp \
../srm181-div1-lev3.cpp \
../srm184-div2-lev3.cpp \
../srm200-div1-lev3-graduation.cpp \
../srm211-div1-lev2.cpp \
../stldemo.cpp \
../tccc2003-semifinal3-zigzag.cpp \
../tco2003-semifinal4-avoidroads.cpp \
../tco2003-semifinal4-rookattack.cpp 

OBJS += \
./MinCostMaxFlow.o \
./backtrack_permutation.o \
./backtrack_subsets.o \
./codeforces-round225-div1-A.o \
./dijkstra.o \
./fft.o \
./geometry.o \
./kmp.o \
./main.o \
./math.o \
./point.o \
./srm156-div1-lev3.o \
./srm166-div2-lev3.o \
./srm181-div1-lev3.o \
./srm184-div2-lev3.o \
./srm200-div1-lev3-graduation.o \
./srm211-div1-lev2.o \
./stldemo.o \
./tccc2003-semifinal3-zigzag.o \
./tco2003-semifinal4-avoidroads.o \
./tco2003-semifinal4-rookattack.o 

CPP_DEPS += \
./MinCostMaxFlow.d \
./backtrack_permutation.d \
./backtrack_subsets.d \
./codeforces-round225-div1-A.d \
./dijkstra.d \
./fft.d \
./geometry.d \
./kmp.d \
./main.d \
./math.d \
./point.d \
./srm156-div1-lev3.d \
./srm166-div2-lev3.d \
./srm181-div1-lev3.d \
./srm184-div2-lev3.d \
./srm200-div1-lev3-graduation.d \
./srm211-div1-lev2.d \
./stldemo.d \
./tccc2003-semifinal3-zigzag.d \
./tco2003-semifinal4-avoidroads.d \
./tco2003-semifinal4-rookattack.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


