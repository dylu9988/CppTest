################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../threads/pthreadt_test.cpp \
../threads/thread_cond.cpp \
../threads/thread_stacksize.cpp 

OBJS += \
./threads/pthreadt_test.o \
./threads/thread_cond.o \
./threads/thread_stacksize.o 

CPP_DEPS += \
./threads/pthreadt_test.d \
./threads/thread_cond.d \
./threads/thread_stacksize.d 


# Each subdirectory must supply rules for building sources it contributes
threads/%.o: ../threads/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


