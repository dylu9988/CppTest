################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/StackQueue.cpp \
../algorithms/horner.cpp 

OBJS += \
./algorithms/StackQueue.o \
./algorithms/horner.o 

CPP_DEPS += \
./algorithms/StackQueue.d \
./algorithms/horner.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/%.o: ../algorithms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


