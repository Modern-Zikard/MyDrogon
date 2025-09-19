cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME DrogonProject1)
project(${PROJECT_NAME})

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)





set(Drogon_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/drogon")
find_package(Drogon REQUIRED)




# Указываем исходники
add_executable(${PROJECT_NAME} 
    main.cpp
    controllers/HelloController.cc
)

file(COPY ${CMAKE_SOURCE_DIR}/config.json
     DESTINATION ${CMAKE_BINARY_DIR})


# Линкуем drogon
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

# cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=E:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake


