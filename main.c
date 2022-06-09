#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {

    const float conversion_factor = 3.3f / (1 << 12);

    stdio_init_all();
    adc_init();

    adc_select_input(4);

    adc_set_temp_sensor_enabled(true);
    
    while (true) {
        
        uint16_t result = adc_read();
        float voltaje = result * conversion_factor;
        float temp = 27-(voltaje - 0.0706)/0.001721;

        printf("Raw value: 0x%03x, voltage: %.2f V, temp: %.2f\n", result, voltaje, temp);
        sleep_ms(500);

    }

    return 0;
}