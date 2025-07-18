#include "drivers/st7789/test/driver_st7789_display_test.h"
#include "source/ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"
#include "bsp_led.h"
#include "delay.h"
#include "printf.h"
#include "port_printf.h"
#include "driver_st7789_display_test.h"

int main(void)
{
    SYSCFG_DL_init();

    bsp_led_on();

    port_printf_init(UART_DEBUG_INST);
    
    printf("Hello, G3507.\r\n");
    DL_GPIO_writePinsVal(GPIO_GRP_LCD_PORT, GPIO_GRP_LCD_PIN_BLK_PIN, 0);
    st7789_display_test();

    while (1) {
        bsp_led_toggle();
        delay_ms(250);
    }
}
