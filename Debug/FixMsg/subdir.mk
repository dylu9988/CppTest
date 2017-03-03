################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FixMsg/CppRegex.cpp \
../FixMsg/FixMsgOp.cpp \
../FixMsg/FixTest.cpp 

OBJS += \
./FixMsg/CppRegex.o \
./FixMsg/FixMsgOp.o \
./FixMsg/FixTest.o 

CPP_DEPS += \
./FixMsg/CppRegex.d \
./FixMsg/FixMsgOp.d \
./FixMsg/FixTest.d 


# Each subdirectory must supply rules for building sources it contributes
FixMsg/%.o: ../FixMsg/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


