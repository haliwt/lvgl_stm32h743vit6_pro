#include "bsp.h"


#define SYS_SUPPORT_OS    0

static uint32_t g_fac_us = 0;  /* us延时倍乘数 */

/**
 * @brief     初始化延迟函数
 * @param     sysclk: 系统时钟频率, 即CPU频率(rcc_c_ck), 480Mhz
 * @retval    无
 */  
void delay_init(uint16_t sysclk)
{
#if SYS_SUPPORT_OS                                      /* 如果需要支持OS */
    uint32_t reload;
#endif
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);/* SYSTICK使用内核时钟源,同CPU同频率 */
    g_fac_us = sysclk;                                  /* 不论是否使用OS,g_fac_us都需要使用 */
#if SYS_SUPPORT_OS                                      /* 如果需要支持OS. */
    reload = sysclk;                                    /* 每秒钟的计数次数 单位为M */
    reload *= 1000000 / configTICK_RATE_HZ;             /* 根据configTICK_RATE_HZ设定溢出时间,reload为24位
                                                           寄存器,最大值:16777216,在480M下,约合0.035s左右 */
    SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;          /* 开启SYSTICK中断 */
    SysTick->LOAD = reload;                             /* 每1/configTICK_RATE_HZ秒中断一次 */
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;           /* 开启SYSTICK */
#endif 
}
 
#if SYS_SUPPORT_OS   /* 如果需要支持OS, 用以下代码 */

/**
 * @brief     延时nus
 * @param     nus: 要延时的us数
 * @note      nus取值范围: 0~8947848(最大值即2^32 / g_fac_us @g_fac_us = 480)
 * @retval    无
 */ 
void delay_us(uint32_t nus)
{
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD;    /* LOAD的值 */
    
    ticks = nus * g_fac_us;             /* 需要的节拍数 */
    told = SysTick->VAL;                /* 刚进入时的计数器值 */
    while (1)
    {
        tnow = SysTick->VAL;
        if (tnow != told)
        {
            if (tnow < told)
            {
                tcnt += told - tnow;   /* 这里注意一下SYSTICK是一个递减的计数器就可以了 */
            }
            else
            {
                tcnt += reload - tnow + told;
            }
            told = tnow;
            if (tcnt >= ticks) 
            {
                break;               /* 时间超过/等于要延迟的时间,则退出 */
            }
        }
    }
} 

/**
 * @brief     延时nms
 * @param     nms: 要延时的ms数 (0< nms <= 65535) 
 * @retval    无
 */
void delay_ms(uint16_t nms)
{
    uint32_t i;

    for (i=0; i<nms; i++)
    {
        delay_us(1000);
    }
}

#else  /* 不使用OS时, 用以下代码 */

/**
 * @brief       延时nus
 * @param       nus: 要延时的us数.
 * @note        注意: nus的值,不要大于34952us(最大值即2^24 / g_fac_us @g_fac_us = 480)
 * @retval      无
 */
void delay_us(uint32_t nus)
{
    uint32_t ticks;
    uint32_t told, tnow, tcnt = 0;
    uint32_t reload = SysTick->LOAD;  /* LOAD的值 */
    ticks = nus * g_fac_us;           /* 需要的节拍数 */
    told = SysTick->VAL;              /* 刚进入时的计数器值 */
    while (1)
    {
        tnow = SysTick->VAL;
        if (tnow != told)
        {
            if (tnow < told)
            {
                tcnt += told - tnow;  /* 这里注意一下SYSTICK是一个递减的计数器就可以了 */
            }
            else 
            {
                tcnt += reload - tnow + told;
            }
            told = tnow;
            if (tcnt >= ticks)
            {
                break;                /* 时间超过/等于要延迟的时间,则退出 */
            }
        }
    }
}

/**
 * @brief       延时nms
 * @param       nms: 要延时的ms数 (0< nms <= 65535)
 * @retval      无
 */
void delay_ms(uint16_t nms)
{
    uint32_t repeat = nms / 30;     /*  这里用30,是考虑到可能有超频应用,
                                     *  比如500Mhz的时候, delay_us最大只能延时33554us左右了
                                     */
    uint32_t remain = nms % 30;

    while (repeat)
    {
        delay_us(30 * 1000);        /* 利用delay_us 实现 1000ms 延时 */
        repeat--;
    }

    if (remain)
    {
        delay_us(remain * 1000);    /* 利用delay_us, 把尾数延时(remain ms)给做了 */
    }
}

#endif

/**
 * @brief HAL 库延时函数重定义
 * @param Delay 要延时的毫秒数
 * @retval None
 */
void HAL_Delay(uint32_t Delay)
{
    delay_ms(Delay);
}

