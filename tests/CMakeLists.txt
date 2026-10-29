set(CMAKE_C_STANDARD 99)

find_path(NVML_INCLUDE_DIR nvml.h
        PATHS
        "$ENV{CUDA_PATH}/include"
        "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.4/include"
        /usr/local/cuda/include
)

find_library(NVML_LIBRARY nvml
        PATHS
        "$ENV{CUDA_PATH}/lib/x64"
        "$ENV{CUDA_PATH}/lib64"
        "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.4/lib/x64"
        /usr/local/cuda/lib64
)

if (NOT NVML_INCLUDE_DIR OR NOT NVML_LIBRARY)
    message(FATAL_ERROR "NVML not found (nvml.h / nvml.lib)")
endif ()

add_executable(vram_project ../test.c)

target_include_directories(vram_project PRIVATE ${NVML_INCLUDE_DIR})
target_link_libraries(vram_project PRIVATE ${NVML_LIBRARY})
