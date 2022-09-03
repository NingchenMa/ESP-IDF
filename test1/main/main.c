#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include <math.h>

#define TAG "DICE"

//Generate a random number in the range of 1-6 (inclusive)
int dice_roll(){
    int random_num = abs(esp_random()) % 6 + 1;
    return random_num;
}

void app_main(void)
{
    printf("Hello from Ningchen!\n");
    //int i = 0;
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        ESP_LOGI(TAG, "random number %d",dice_roll());
    }
}