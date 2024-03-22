add_library(hchat STATIC
  "include/hchat.h"
  "src/hchat.cpp"
)

target_include_directories(hchat
  PUBLIC
    "include"
  PRIVATE
    "src"
)

target_link_libraries(hchat
  PRIVATE
    common
    llama
)

target_compile_features(hchat
  PRIVATE
    cxx_std_11
)

target_compile_definitions(hchat
  PRIVATE
    DEBUG_MODEL_DIR="${CMAKE_CURRENT_SOURCE_DIR}/../models/"
    MODEL="llama-2-7b-chat.Q5_K_S.gguf"
)
