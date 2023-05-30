cmake_minimum_required(VERSION 3.2)

project(gs2cpp)

include("${PROJECT_SOURCE_DIR}/cmake/Common.cmake")
    
message("PROJECT_SOURCE_DIR:              ${PROJECT_SOURCE_DIR}")
include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/include/flex_bison)
include_directories(${PROJECT_SOURCE_DIR}/include/gs2cpp)

#add_subdirectory(src)
#add_subdirectory(include)
add_executable(gs2cpp)
aux_source_directory(include sources)
aux_source_directory(include/flex_bison sources)
aux_source_directory(src sources)
aux_source_directory(src/gs2cpp sources)
aux_source_directory(. sources)
target_sources(gs2cpp PUBLIC ${sources})
