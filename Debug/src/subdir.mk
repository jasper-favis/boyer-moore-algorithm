################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Boyer-Moore\ Pattern\ Matching\ Algorithm.cpp 

OBJS += \
./src/Boyer-Moore\ Pattern\ Matching\ Algorithm.o 

CPP_DEPS += \
./src/Boyer-Moore\ Pattern\ Matching\ Algorithm.d 


# Each subdirectory must supply rules for building sources it contributes
src/Boyer-Moore\ Pattern\ Matching\ Algorithm.o: ../src/Boyer-Moore\ Pattern\ Matching\ Algorithm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Boyer-Moore Pattern Matching Algorithm.d" -MT"src/Boyer-Moore\ Pattern\ Matching\ Algorithm.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


