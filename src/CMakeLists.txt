# cmake_minimum_required(VERSION <specify CMake version here>)
project(sw_engineering_hw3)

set(CMAKE_CXX_STANDARD 11)

add_executable(sw_engineering_hw3 main.cpp Member.h Member.cpp Accommodation.h Collection.h MemberCollection.cpp MemberCollection.h Session.cpp Session.h SessionCollection.cpp SessionCollection.h OutputWriter.cpp OutputWriter.h controls/AbstractControl.cpp controls/AbstractControl.h boundaries/AbstractBoundary.cpp boundaries/AbstractBoundary.h boundaries/SessionBoundary.cpp boundaries/SessionBoundary.h controls/SessionControl.cpp controls/SessionControl.h SingletonMacro.h Time.h)