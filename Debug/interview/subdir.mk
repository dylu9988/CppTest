################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../interview/ListReverse.cpp \
../interview/in_a_not_in_b.cpp \
../interview/more_half.cpp \
../interview/reverse_list.cpp \
../interview/weixin_1.cpp \
../interview/weixin_2.cpp \
../interview/weixin_3.cpp \
../interview/weixin_4.cpp \
../interview/weixin_5.cpp 

OBJS += \
./interview/ListReverse.o \
./interview/in_a_not_in_b.o \
./interview/more_half.o \
./interview/reverse_list.o \
./interview/weixin_1.o \
./interview/weixin_2.o \
./interview/weixin_3.o \
./interview/weixin_4.o \
./interview/weixin_5.o 

CPP_DEPS += \
./interview/ListReverse.d \
./interview/in_a_not_in_b.d \
./interview/more_half.d \
./interview/reverse_list.d \
./interview/weixin_1.d \
./interview/weixin_2.d \
./interview/weixin_3.d \
./interview/weixin_4.d \
./interview/weixin_5.d 


# Each subdirectory must supply rules for building sources it contributes
interview/%.o: ../interview/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


