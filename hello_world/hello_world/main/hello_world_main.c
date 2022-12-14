/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#ifdef CONFIG_IDF_TARGET_ESP32
#define CHIP_NAME "ESP32"
#endif

#ifdef CONFIG_IDF_TARGET_ESP32S2BETA
#define CHIP_NAME "ESP32-S2 Beta"
#endif

void app_main(void)
{
    
    printf("Hello world!\n");
    
    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info); // Fill the above datastructure by following the address
    printf("This is %s chip with %d CPU cores, WiFi%s%s, ",
            CHIP_NAME,
            chip_info.cores,
            (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
            (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
            (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    //Print the IDF version
    printf("The IDF version is:%s\n",esp_get_idf_version());

    uint8_t chipId[6];
    esp_efuse_mac_get_default(chipId);

    printf("The MAC address is: %02x %02x %02x %02x %02x %02x\n", chipId[0], chipId[1], chipId[2], chipId[3], chipId[4], chipId[5]);

    //Restart in every 10s
    for (int i = 10; i >= 0; i--) {
        //printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    //printf("Restarting now.\n");
    fflush(stdout);
    //esp_restart();
}
