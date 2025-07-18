#include "bsp_spi.h"
#include "ti_msp_dl_config.h"
#include "ti/driverlib/dl_gpio.h"
#include "ti/driverlib/dl_spi.h"

SPI_Regs *lcd_spi = NULL;

void bsp_spi_init(SPI_Regs *spi)
{
    lcd_spi = spi;
}


uint8_t spi_transmit(SPI_Regs *spi, uint8_t *pData, uint16_t Size)
{
    uint8_t errorcode = 0;
    uint16_t TxXferCount;
    uint8_t* pTxBuffPtr;

    if ((pData == NULL) || (Size == 0U))
    {
        errorcode = 1;
        goto error;
    }

    TxXferCount = Size;
    pTxBuffPtr = (uint8_t*)pData;

    while (TxXferCount > 0U){
        if(0 != DL_SPI_isTXFIFOEmpty(spi)){
            DL_SPI_transmitData8(spi, *pTxBuffPtr);
            TxXferCount--;
            pTxBuffPtr++;
        }
    }

    /* 等待传输完成 */
    while (0 != DL_SPI_isBusy(spi)){}

error :
    return errorcode;
}
