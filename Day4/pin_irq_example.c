#include <drv_gpio.h>
#include <rtdevice.h>
#include <rtthread.h>
#define LOG_TAG "pin.irq"
#define LOG_LVL LOG_LVL_DBG
#include <ulog.h>

#define KEY_UP GET_PIN(C, 5)
#define KEY_DOWN GET_PIN(C, 1)
#define KEY_LEFT GET_PIN(C, 0)
#define KEY_RIGHT GET_PIN(C, 4)

void key_up_callback(void *args) 
{ 
    int value = rt_pin_read(KEY_UP);
    LOG_I("key up value: %d\n", value);
}

void key_down_callback(void *args) 
{ 
    int value = rt_pin_read(KEY_DOWN);
    LOG_I("key down value: %d\n", value);
}

void key_left_callback(void *args) 
{ 
    int value = rt_pin_read(KEY_LEFT);
    LOG_I("key left value: %d\n", value);
}

void key_right_callback(void *args) 
{ 
    int value = rt_pin_read(KEY_RIGHT);
    LOG_I("key right value: %d\n", value);
}

static int rt_pin_irq_example(void)
{
    rt_pin_mode(KEY_UP, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_DOWN, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_LEFT, PIN_MODE_INPUT_PULLUP);
    rt_pin_mode(KEY_RIGHT, PIN_MODE_INPUT_PULLUP);

    rt_pin_attach_irq(KEY_UP, PIN_IRQ_MODE_FALLING, key_up_callback, RT_NULL);
    rt_pin_attach_irq(KEY_DOWN, PIN_IRQ_MODE_FALLING, key_down_callback, RT_NULL);
    rt_pin_attach_irq(KEY_LEFT, PIN_IRQ_MODE_FALLING, key_left_callback, RT_NULL);
    rt_pin_attach_irq(KEY_RIGHT, PIN_IRQ_MODE_FALLING, key_right_callback, RT_NULL);

    rt_pin_irq_enable(KEY_UP,PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_DOWN,PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_LEFT,PIN_IRQ_ENABLE);
    rt_pin_irq_enable(KEY_RIGHT,PIN_IRQ_ENABLE);
    
    return RT_EOK;
}
MSH_CMD_EXPORT_ALIAS(rt_pin_irq_example,irq, pin_irq_example);