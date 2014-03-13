################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dijkstra.cpp \
../geometry.cpp \
../main.cpp \
../math.cpp \
../point.cpp \
../srm166-div2-lev3.cpp \
../srm211-div1-lev2.cpp \
../stldemo.cpp 

OBJS += \
./dijkstra.o \
./geometry.o \
./main.o \
./math.o \
./point.o \
./srm166-div2-lev3.o \
./srm211-div1-lev2.o \
./stldemo.o 

CPP_DEPS += \
./dijkstra.d \
./geometry.d \
./main.d \
./math.d \
./point.d \
./srm166-div2-lev3.d \
./srm211-div1-lev2.d \
./stldemo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


