################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include threads/subdir.mk
-include stltest/subdir.mk
-include process/subdir.mk
-include nets/subdir.mk
-include leetcode/subdir.mk
-include comm/subdir.mk
-include boost/subdir.mk
-include bianry_tree/subdir.mk
-include algorithms/subdir.mk
-include algoTests/subdir.mk
-include ZeroMq/subdir.mk
-include System/subdir.mk
-include Syntax/subdir.mk
-include SpecialFuncs/subdir.mk
-include Math/subdir.mk
-include Graph/subdir.mk
-include FixMsg/subdir.mk
-include Cpp11/subdir.mk
-include Asynchronous/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: CppTest

# Tool invocations
CppTest: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L../ -L/usr/local/protobuf/lib/ -L/usr/local/lib64/ -o "CppTest" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) CppTest
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
