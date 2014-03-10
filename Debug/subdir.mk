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
../stldemo.cpp 

OBJS += \
./dijkstra.o \
./geometry.o \
./main.o \
./math.o \
./point.o \
./stldemo.o 

CPP_DEPS += \
./dijkstra.d \
./geometry.d \
./main.d \
./math.d \
./point.d \
./stldemo.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


