################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../leetcode/BinarySearch.cpp \
../leetcode/BinaryTreeDepth.cpp \
../leetcode/CountSort.cpp \
../leetcode/Find2LostNumbers.cpp \
../leetcode/FindKthNumber.cpp \
../leetcode/FindMoreThenHalf.cpp \
../leetcode/FindOnlyOneOrTwoDuplicated.cpp \
../leetcode/HappyNumber.cpp \
../leetcode/HeapSort.cpp \
../leetcode/InsertSort.cpp \
../leetcode/IsBinarySearchTree.cpp \
../leetcode/LinerSearch.cpp \
../leetcode/MaxPalindromeSubstr.cpp \
../leetcode/MaxSubarraySum.cpp \
../leetcode/MergeSortedArray.cpp \
../leetcode/NMNumsFindMDuplicated.cpp \
../leetcode/QuickSort.cpp \
../leetcode/RegularIsMatch.cpp \
../leetcode/RemoveZero.cpp \
../leetcode/ReverseInteger.cpp \
../leetcode/SelectSort.cpp 

OBJS += \
./leetcode/BinarySearch.o \
./leetcode/BinaryTreeDepth.o \
./leetcode/CountSort.o \
./leetcode/Find2LostNumbers.o \
./leetcode/FindKthNumber.o \
./leetcode/FindMoreThenHalf.o \
./leetcode/FindOnlyOneOrTwoDuplicated.o \
./leetcode/HappyNumber.o \
./leetcode/HeapSort.o \
./leetcode/InsertSort.o \
./leetcode/IsBinarySearchTree.o \
./leetcode/LinerSearch.o \
./leetcode/MaxPalindromeSubstr.o \
./leetcode/MaxSubarraySum.o \
./leetcode/MergeSortedArray.o \
./leetcode/NMNumsFindMDuplicated.o \
./leetcode/QuickSort.o \
./leetcode/RegularIsMatch.o \
./leetcode/RemoveZero.o \
./leetcode/ReverseInteger.o \
./leetcode/SelectSort.o 

CPP_DEPS += \
./leetcode/BinarySearch.d \
./leetcode/BinaryTreeDepth.d \
./leetcode/CountSort.d \
./leetcode/Find2LostNumbers.d \
./leetcode/FindKthNumber.d \
./leetcode/FindMoreThenHalf.d \
./leetcode/FindOnlyOneOrTwoDuplicated.d \
./leetcode/HappyNumber.d \
./leetcode/HeapSort.d \
./leetcode/InsertSort.d \
./leetcode/IsBinarySearchTree.d \
./leetcode/LinerSearch.d \
./leetcode/MaxPalindromeSubstr.d \
./leetcode/MaxSubarraySum.d \
./leetcode/MergeSortedArray.d \
./leetcode/NMNumsFindMDuplicated.d \
./leetcode/QuickSort.d \
./leetcode/RegularIsMatch.d \
./leetcode/RemoveZero.d \
./leetcode/ReverseInteger.d \
./leetcode/SelectSort.d 


# Each subdirectory must supply rules for building sources it contributes
leetcode/%.o: ../leetcode/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/c++/5.2.0 -I/usr/local/include/c++/5.2.0/x86_64-unknown-linux-gnu -I/usr/local/include/c++/5.2.0/backward -I/usr/include/mysql -I/home/ruanbo/Codes/CppTest -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


