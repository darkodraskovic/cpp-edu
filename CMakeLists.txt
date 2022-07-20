cmake_minimum_required(VERSION 3.8)
project (boilerplate)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/bin")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_SOURCE_DIR}/bin")
else()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
endif()

function(add_target TARGET SOURCES)
  foreach(FILE ${SOURCES})
    list(APPEND SOURCES_PREPEND Source/${TARGET}/${FILE})
  endforeach()
  add_executable(${TARGET} ${SOURCES_PREPEND})
  target_include_directories(${TARGET} PUBLIC src/${TARGET})
endfunction()

set(Python_inc "C:/ProgramData/Anaconda3/include")
set(Python_link "C:/ProgramData/Anaconda3/libs/")
set(Python_libs python38)

add_target(bw_11 "Main.cpp")
add_target(bw_12 "Main.cpp")
add_target(bw_14 "Main.cpp")
add_target(bw_15 "Main.cpp;NumWord.cpp")
add_target(bw_22_smart_pointers "main.cpp;strc.cpp;utils.cpp")

add_target(dd_00_xval "main.cpp")
add_target(dd_01_move "main.cpp")
add_target(dd_02 "Main.cpp")
target_include_directories(dd_02 PUBLIC ${Python_inc})
target_link_directories(dd_02 PUBLIC ${Python_link})
target_link_libraries(dd_02 PUBLIC ${Python_libs})

add_target(kk_1d_console_game "Main.cpp")
add_target(kk_17 "Main.cpp")
add_target(kk_19 "Main.cpp")
add_target(kk_21 "Main.cpp;Image.cpp")
add_target(kk_21b "Main.cpp")
add_target(kk_21_templates_operates_overload "Main.cpp")

add_target(hc_00_calloc "Main.c")
