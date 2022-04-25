project(SnaKe8D)

set(CMAKE_CXX_STANDARD 20)

add_executable(SnaKe8D src/main.cpp)

include_directories(headers src /usr/include c:/SFML/include)

add_library(Snake headers/Snake.h src/Snake.cpp)
add_library(BodyShape headers/BodyShape.h src/BodyShape.cpp)
add_library(Map headers/Map.h src/Map.cpp)
add_library(Apple headers/Apple.h src/Apple.cpp)


target_link_libraries(SnaKe8D Snake BodyShape Map Apple)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SnaKe8D ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()