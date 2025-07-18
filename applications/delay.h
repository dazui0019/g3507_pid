#pragma once

/**
 * @brief ms延时函数
 * @param x 延时时间(ms)
 * @note 大概的原理是 delay_cycles(CPUCLK_FREQ) 执行完大约是1s钟
 * 那么delay_cycles(CPUCLK_FREQ/1000)大约是1ms
 */
#define delay_ms(x) delay_cycles((CPUCLK_FREQ / 1000)*x)
#define delay_us(x) delay_cycles((CPUCLK_FREQ / 1000000)*x)
