#include <stdio.h>
#include "string.h"
#include "ssd1306.h" // lib que controla el display

SSD1306_t screen; // puntero

void screen_init()
{
    // canal de protocolo y variables de config que estan definidas (variables de entorno)
    i2c_master_init(&screen, CONFIG_SDA_GPIO, CONFIG_SCL_GPIO, CONFIG_RESET_GPIO);
    // pantalla info
    ssd1306_init(&screen, 128, 64);
    // contraste de la pantalla pra ver pixeles
    ssd1306_contrast(&screen, 0xFF);
}

void screen_clear()
{
    ssd1306_clear_screen(&screen, false);
}

void screen_print(char *str, int page)
{
    ssd1306_clear_line(&screen, page, false);                     // clean the line
    ssd1306_display_text(&screen, page, str, strlen(str), false); // show the text
}

void app_main(void)
{
    screen_init();
    screen_clear();
    screen_print("Hola mundo Profesora Zeida, Gustavo y Greg!", 0);
}