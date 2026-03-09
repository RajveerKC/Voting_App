cmake_minimum_required (VERSION 3.16)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Voting_App")

include(FetchContent)

# ========================
# Raylib
# ========================

message("Fetching Raylib.")

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

message("Raylib Fetched")

# ========================
# raygui (header-only)
# ========================

message("Fetching Raygui")

FetchContent_Declare(
    raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
)

FetchContent_MakeAvailable(raygui)

message("RayGui Fetched")

# ========================
# Application
# ========================

file(GLOB APP_SOURCES
    ${CMAKE_SOURCE_DIR}/src/core/*.c
    ${CMAKE_SOURCE_DIR}/src/db/*.c
    ${CMAKE_SOURCE_DIR}/src/screens/*.c
)

add_executable(${PROJECT_NAME}
    ${APP_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
    ${raygui_SOURCE_DIR}/src
)


# =======================
# Copy Assets
# =======================

file(COPY ${CMAKE_SOURCE_DIR}/assets
    DESTINATION ${CMAKE_BINARY_DIR})
message("Assets Copied to Build Directory.")