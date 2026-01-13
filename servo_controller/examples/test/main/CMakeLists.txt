idf_component_register(SRCS "main.c"
                    INCLUDE_DIRS "."
                    REQUIRES esp_driver_rmt
                    REQUIRES esp_timer
                    REQUIRES servo_controller)
set(EXTRA_COMPONENT_DIRS components)