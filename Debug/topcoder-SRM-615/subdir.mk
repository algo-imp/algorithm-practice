################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../topcoder-SRM-615/problem1.cpp \
../topcoder-SRM-615/problem2-sample1.cpp \
../topcoder-SRM-615/problem2.cpp 

OBJS += \
./topcoder-SRM-615/problem1.o \
./topcoder-SRM-615/problem2-sample1.o \
./topcoder-SRM-615/problem2.o 

CPP_DEPS += \
./topcoder-SRM-615/problem1.d \
./topcoder-SRM-615/problem2-sample1.d \
./topcoder-SRM-615/problem2.d 


# Each subdirectory must supply rules for building sources it contributes
topcoder-SRM-615/%.o: ../topcoder-SRM-615/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


