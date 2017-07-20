################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Syntax/Align.cpp \
../Syntax/MemberOffset.cpp \
../Syntax/MultiInherit.cpp \
../Syntax/NonInheritable.cpp \
../Syntax/VtableImpl.cpp \
../Syntax/VtablePtr.cpp \
../Syntax/array.cpp \
../Syntax/datatype.cpp \
../Syntax/varargs.cpp \
../Syntax/vtable.cpp 

OBJS += \
./Syntax/Align.o \
./Syntax/MemberOffset.o \
./Syntax/MultiInherit.o \
./Syntax/NonInheritable.o \
./Syntax/VtableImpl.o \
./Syntax/VtablePtr.o \
./Syntax/array.o \
./Syntax/datatype.o \
./Syntax/varargs.o \
./Syntax/vtable.o 

CPP_DEPS += \
./Syntax/Align.d \
./Syntax/MemberOffset.d \
./Syntax/MultiInherit.d \
./Syntax/NonInheritable.d \
./Syntax/VtableImpl.d \
./Syntax/VtablePtr.d \
./Syntax/array.d \
./Syntax/datatype.d \
./Syntax/varargs.d \
./Syntax/vtable.d 


# Each subdirectory must supply rules for building sources it contributes
Syntax/%.o: ../Syntax/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


