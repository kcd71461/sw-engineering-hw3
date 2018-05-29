# cmake_minimum_required(VERSION <specify CMake version here>)
project(sw_engineering_hw3)

set(CMAKE_CXX_STANDARD 11)

add_executable(sw_engineering_hw3 main.cpp Member.h Member.cpp Host.h Host.cpp Guest.h Guest.cpp Accommodation.h Collection.h MemberCollection.cpp MemberCollection.h Session.cpp Session.h SessionCollection.cpp SessionCollection.h OutputWriter.cpp OutputWriter.h controls/AbstractControl.cpp controls/AbstractControl.h boundaries/AbstractBoundary.cpp boundaries/AbstractBoundary.h boundaries/SessionUI.cpp boundaries/SessionUI.h controls/SessionControl.cpp controls/SessionControl.h SingletonMacro.h Time.h Time.cpp boundaries/RegisterUI.cpp boundaries/RegisterUI.h controls/RegisterControl.cpp controls/RegisterControl.h boundaries/LoginUI.cpp boundaries/LoginUI.h boundaries/LogoutUI.cpp boundaries/LogoutUI.h controls/LoginControl.cpp controls/LoginControl.h controls/LogoutControl.cpp controls/LogoutControl.h boundaries/SearchUI.cpp boundaries/SearchUI.h controls/SearchControl.cpp controls/SearchControl.h AccommodationCollection.cpp boundaries/addAccommodationUI.cpp
        boundaries/addAccommodationUI.h
        controls/addAccommodation.cpp
        controls/SearchReservationControl.cpp controls/SearchReservationControl.h boundaries/SearchReservationUI.cpp boundaries/SearchReservationUI.h
        controls/addAccommodation.h ReservationCollection.cpp Reservation.cpp Reservation.h controls/OpaqueInventoryControl.cpp controls/OpaqueInventoryControl.h boundaries/OpaqueInventoryUI.cpp boundaries/OpaqueInventoryUI.h Time.cpp)