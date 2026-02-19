#include "LowLevelCoding.h"

void low_level_coding()
{
    nrf_gpio_cfg_output(COL1);
    nrf_gpio_cfg_output(ROW1);

    // we need no pull-up, since there is one soldered to the board
    nrf_gpio_cfg_input(BUTTON_A, NRF_GPIO_PIN_NOPULL);

    // this pin will be always low, we'll control the ROW1 only
    nrf_gpio_pin_write(COL1, 0);

    // now, let's light the LED if the button A is pressed, clearing the LED otherwise
    while (true)
    {
        uint32_t isButtonUp = nrf_gpio_pin_read(BUTTON_A);
        nrf_gpio_pin_write(ROW1, !isButtonUp);
    }
}