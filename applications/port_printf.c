#include "ti_msp_dl_config.h"
#include "ti/driverlib/dl_uart.h"

UART_Regs *debug_uart = NULL;

void port_printf_init(UART_Regs *uart)
{
    debug_uart = uart;
}

void _putchar(char character)
{
    // ->TXDATA = character;
    // DL_UART_transmitData(UART_DEBUG_INST, character);
    debug_uart->TXDATA = character;

    while(0 == ((debug_uart->STAT & UART_STAT_TXFE_MASK) == UART_STAT_TXFE_SET));
}
