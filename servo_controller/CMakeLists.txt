#servo_controller/CMakeLists.txt

idf_component_register(
    SRCS "src/servo_controller.c"
    INCLUDE_DIRS "include"
    PRIV_INCLUDE_DIRS "src"
    REQUIRES esp_driver_rmt
)