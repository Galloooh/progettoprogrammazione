################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/character.cpp \
../src/main.cpp \
../src/map.cpp \
../src/stormtrooper.cpp 

CPP_DEPS += \
./src/character.d \
./src/main.d \
./src/map.d \
./src/stormtrooper.d 

OBJS += \
./src/character.o \
./src/main.o \
./src/map.o \
./src/stormtrooper.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/character.d ./src/character.o ./src/main.d ./src/main.o ./src/map.d ./src/map.o ./src/stormtrooper.d ./src/stormtrooper.o

.PHONY: clean-src

