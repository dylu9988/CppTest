################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Cpp11/Emplace.cpp \
../Cpp11/Final.cpp \
../Cpp11/Forward.cpp \
../Cpp11/Move.cpp \
../Cpp11/Move2.cpp \
../Cpp11/Override.cpp \
../Cpp11/Randoms.cpp \
../Cpp11/SharedPtr.cpp \
../Cpp11/SmartPtr.cpp \
../Cpp11/UnorderedMap.cpp \
../Cpp11/cpp_template.cpp \
../Cpp11/loops.cpp 

OBJS += \
./Cpp11/Emplace.o \
./Cpp11/Final.o \
./Cpp11/Forward.o \
./Cpp11/Move.o \
./Cpp11/Move2.o \
./Cpp11/Override.o \
./Cpp11/Randoms.o \
./Cpp11/SharedPtr.o \
./Cpp11/SmartPtr.o \
./Cpp11/UnorderedMap.o \
./Cpp11/cpp_template.o \
./Cpp11/loops.o 

CPP_DEPS += \
./Cpp11/Emplace.d \
./Cpp11/Final.d \
./Cpp11/Forward.d \
./Cpp11/Move.d \
./Cpp11/Move2.d \
./Cpp11/Override.d \
./Cpp11/Randoms.d \
./Cpp11/SharedPtr.d \
./Cpp11/SmartPtr.d \
./Cpp11/UnorderedMap.d \
./Cpp11/cpp_template.d \
./Cpp11/loops.d 


# Each subdirectory must supply rules for building sources it contributes
Cpp11/%.o: ../Cpp11/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


