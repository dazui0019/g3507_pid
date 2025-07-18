#include "ti_msp_dl_config.h"
#include "bsp_led.h"
#include "delay.h"
#include "printf.h"
#include "port_printf.h"

int main(void)
{
    SYSCFG_DL_init();

    bsp_led_on();

    port_printf_init(UART_DEBUG_INST);
    
    printf("Hello, G3507.\r\n");

    while (1) {
        bsp_led_toggle();
        delay_ms(250);
    }
}
