#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_system.h"

static const char *TAG = "MAIN";

// Nutze das IDF-Enum statt nackter 5
static constexpr gpio_num_t BLINK_GPIO = GPIO_NUM_5;

extern "C" void app_main(void)
{
    ESP_LOGI(TAG, "ESP32-P4 starter project booting");

    gpio_config_t io_conf = {};
    io_conf.pin_bit_mask = 1ULL << static_cast<uint32_t>(BLINK_GPIO);
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = GPIO_PULLUP_DISABLE;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    gpio_config(&io_conf);

    while (true) {
        gpio_set_level(BLINK_GPIO, 1);
        ESP_LOGI(TAG, "LED ON");
        vTaskDelay(pdMS_TO_TICKS(500));

        gpio_set_level(BLINK_GPIO, 0);
        ESP_LOGI(TAG, "LED OFF");
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
