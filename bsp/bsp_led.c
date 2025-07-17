#include "bsp_led.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti_msp_dl_config.h"

void bsp_led_off()
{
    DL_GPIO_clearPins(GPIO_GRP_LED_PORT, GPIO_GRP_LED_PIN_LED_PIN);
}

void bsp_led_on()
{
    DL_GPIO_writePins(GPIO_GRP_LED_PORT, GPIO_GRP_LED_PIN_LED_PIN);
}

void bsp_led_toggle()
{
    DL_GPIO_togglePins(GPIO_GRP_LED_PORT, GPIO_GRP_LED_PIN_LED_PIN);
}
