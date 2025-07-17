#pragma once

#define delay_ms(x) delay_cycles((CPUCLK_FREQ / 1000)*x)
#define delay_us(x) delay_cycles((CPUCLK_FREQ / 1000000)*x)
