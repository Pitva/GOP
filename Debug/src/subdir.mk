################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Casselli.cpp \
../src/Dice.cpp \
../src/Effect.cpp \
../src/GOP.cpp \
../src/Player.cpp \
../src/Rethrow.cpp \
../src/RethrowTryhard.cpp \
../src/StepBack.cpp \
../src/StepFoward.cpp \
../src/Stop.cpp \
../src/Swap.cpp \
../src/Teleport.cpp 

OBJS += \
./src/Casselli.o \
./src/Dice.o \
./src/Effect.o \
./src/GOP.o \
./src/Player.o \
./src/Rethrow.o \
./src/RethrowTryhard.o \
./src/StepBack.o \
./src/StepFoward.o \
./src/Stop.o \
./src/Swap.o \
./src/Teleport.o 

CPP_DEPS += \
./src/Casselli.d \
./src/Dice.d \
./src/Effect.d \
./src/GOP.d \
./src/Player.d \
./src/Rethrow.d \
./src/RethrowTryhard.d \
./src/StepBack.d \
./src/StepFoward.d \
./src/Stop.d \
./src/Swap.d \
./src/Teleport.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\cygwin64\lib\gcc\i686-pc-cygwin\6.4.0\include" -I"C:\cygwin64\lib\gcc\i686-pc-cygwin\6.4.0\include\c++" -I"C:\cygwin64\usr\include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


