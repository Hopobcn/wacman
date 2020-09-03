add_library(imgui-bindings
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_impl_glfw.h
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_impl_opengl3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui_impl_opengl3.cpp
)
add_library(imgui::imgui-bindings ALIAS imgui-bindings)
target_compile_definitions(imgui-bindings PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLAD)
target_include_directories(imgui-bindings PUBLIC ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(imgui-bindings PUBLIC
    imgui::imgui
    glfw::glfw
    glad::glad
)