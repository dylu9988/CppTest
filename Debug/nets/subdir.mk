################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../nets/aio_file.cpp \
../nets/aio_server.cpp \
../nets/big_little_endian.cpp \
../nets/socket_op.cpp 

OBJS += \
./nets/aio_file.o \
./nets/aio_server.o \
./nets/big_little_endian.o \
./nets/socket_op.o 

CPP_DEPS += \
./nets/aio_file.d \
./nets/aio_server.d \
./nets/big_little_endian.d \
./nets/socket_op.d 


# Each subdirectory must supply rules for building sources it contributes
nets/%.o: ../nets/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


