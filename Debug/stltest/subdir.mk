################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../stltest/Allocator.cpp \
../stltest/New.cpp \
../stltest/stl_deque.cpp \
../stltest/stl_hash.cpp \
../stltest/stl_map.cpp \
../stltest/stl_sort.cpp \
../stltest/stl_stack.cpp \
../stltest/stl_string.cpp \
../stltest/time_date.cpp 

OBJS += \
./stltest/Allocator.o \
./stltest/New.o \
./stltest/stl_deque.o \
./stltest/stl_hash.o \
./stltest/stl_map.o \
./stltest/stl_sort.o \
./stltest/stl_stack.o \
./stltest/stl_string.o \
./stltest/time_date.o 

CPP_DEPS += \
./stltest/Allocator.d \
./stltest/New.d \
./stltest/stl_deque.d \
./stltest/stl_hash.d \
./stltest/stl_map.d \
./stltest/stl_sort.d \
./stltest/stl_stack.d \
./stltest/stl_string.d \
./stltest/time_date.d 


# Each subdirectory must supply rules for building sources it contributes
stltest/%.o: ../stltest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


