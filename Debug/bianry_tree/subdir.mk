################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bianry_tree/BinaryTreeTraverse.cpp \
../bianry_tree/LayerTraverse.cpp \
../bianry_tree/binary_sort_tree.cpp 

OBJS += \
./bianry_tree/BinaryTreeTraverse.o \
./bianry_tree/LayerTraverse.o \
./bianry_tree/binary_sort_tree.o 

CPP_DEPS += \
./bianry_tree/BinaryTreeTraverse.d \
./bianry_tree/LayerTraverse.d \
./bianry_tree/binary_sort_tree.d 


# Each subdirectory must supply rules for building sources it contributes
bianry_tree/%.o: ../bianry_tree/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


