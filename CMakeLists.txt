cmake_minimum_required(VERSION 3.22)

project(LeviLauncherDebugMenu LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG 0.2.2
)

FetchContent_MakeAvailable(preloader_android)

add_library(levi_debug_menu SHARED
    src/main.cpp
)

target_compile_features(levi_debug_menu PRIVATE cxx_std_20)

target_link_libraries(
    levi_debug_menu
    PRIVATE preloader
)
