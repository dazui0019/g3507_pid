#include "ti_msp_dl_config.h"
#include "bsp_led.h"
#include "delay.h"

int main(void)
{
    SYSCFG_DL_init();

    bsp_led_on();

    while (1) {
        bsp_led_toggle();
        delay_ms(250);
    }
}
