// SPDX-License-Identifier: MIT
/*
 * © 2025 Levi Johanon. All rights reserved.
 * See LICENSE for details.
 */

#include <stdio.h>
#include <stdint.h>
#include "esp_log.h"
#include "servo_controller.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char* TAG = "SERVO";

void app_main(void)
{
    servo_controller_config_t servo_cfg = {
        .clk_gpio = GPIO_NUM_4,
        .pulse_gpio = GPIO_NUM_5,
        .servo1_gpio = GPIO_NUM_6,
        .servo2_gpio = GPIO_NUM_7,
        .serv_pres = SERVO_PRECISION_500
    };

    servo_controller_handle_t handle = NULL;
    servo_initialize_controller(&servo_cfg, &handle);

    servo_set_all(handle, 90);
    servo_start(handle);
    ESP_LOGI(TAG, "Servos should now all be at 90 degrees");
    vTaskDelay(pdMS_TO_TICKS(10000));
    servo_set_all(handle, 180);
    ESP_LOGI(TAG, "Servos should now all be at 180 degrees");
    vTaskDelay(pdMS_TO_TICKS(5000));
    servo_set_servo(handle,0,0);
    ESP_LOGI(TAG, "the first servo should now be at 0 degrees");
    vTaskDelay(pdMS_TO_TICKS(5000));
    servo_stop(handle);
    servo_remove_controller(handle);
    ESP_LOGI(TAG, "The servo controller has been deleted");
}