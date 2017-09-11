################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithms/BigNumber.cpp \
../algorithms/LCS.cpp \
../algorithms/LCS2.cpp \
../algorithms/LPS.cpp \
../algorithms/ListSort.cpp \
../algorithms/ParenPairs.cpp \
../algorithms/StackQueue.cpp \
../algorithms/Trie.cpp \
../algorithms/horner.cpp 

OBJS += \
./algorithms/BigNumber.o \
./algorithms/LCS.o \
./algorithms/LCS2.o \
./algorithms/LPS.o \
./algorithms/ListSort.o \
./algorithms/ParenPairs.o \
./algorithms/StackQueue.o \
./algorithms/Trie.o \
./algorithms/horner.o 

CPP_DEPS += \
./algorithms/BigNumber.d \
./algorithms/LCS.d \
./algorithms/LCS2.d \
./algorithms/LPS.d \
./algorithms/ListSort.d \
./algorithms/ParenPairs.d \
./algorithms/StackQueue.d \
./algorithms/Trie.d \
./algorithms/horner.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms/%.o: ../algorithms/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


