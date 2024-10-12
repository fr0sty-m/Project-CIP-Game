find_package(SDL2 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/cbq_fw)

add_library(cbq_fw SHARED cbq.h loop/loop.cpp)

target_link_libraries(cbq_fw ${SDL2_LIBRARIES})
