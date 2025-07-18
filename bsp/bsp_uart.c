#include "bsp_uart.h"
#include "ti_msp_dl_config.h"
#include "ti/driverlib/dl_uart.h"

/**
 * @brief  Sends an amount of data in blocking mode.(不带超时检测)
*/
uint8_t UART_Transmit(UART_Regs *uart, const uint8_t *pData, uint16_t Size)
{
    const uint8_t  *pdata8bits = pData;
    uint16_t count = Size;
    if ((pData == NULL) || (Size == 0U))
    {
        return  1;
    }
    while (count > 0U)
    {
        uart->TXDATA = *pdata8bits;

        while(0 == DL_UART_isTXFIFOEmpty(uart));

        pdata8bits++;
        count--;
    }
    
    /* 等待传输完成 */
    while (0 != DL_UART_isBusy(uart)){}

    return 0;
}
