add_executable(hchat-cli
    main.cpp
)

target_link_libraries(hchat-cli
  PRIVATE
    hchat
)