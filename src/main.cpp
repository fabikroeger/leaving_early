#include <Arduino.h>
#include <U8g2lib.h>
#include  "namen.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
void draw_bsi_logo(void);
/*
  U8g2lib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 4, /* data=*/ 5, /* reset=*/ U8X8_PIN_NONE);


// End of constructor list

// XBM file start, paste the content of the XBM file directly into the .ino file
// variable name changed from
// static unsigned char u8g2_logo_97x51_bits[] 
// to
// static const unsigned char u8g2_logo_97x51_bits[] U8X8_PROGMEM


#define u8g2_logo_97x51_width 128
#define u8g2_logo_97x51_height 64


uint8_t draw_state =0;

unsigned char clear_screen[128*64];

// void intrement_liststate(void){

//   list_state = list_state +3;
// }
// uint8_t get_listplace(uint8_t draw_state) {
//   uint8_t list_part =0;
//   switch(draw_state) {
//     case 0: break;
//     case 1: break;
//     case 2: break;
//     case 3:   list_part = 0; break;
//     case 4:   list_part =3; break;
//     case 5:   list_part = 6; break;
//     case 6:   list_part = 9; break;
//     case 7:   list_part = 12; break;
//     case 8:   list_part = 15; break;
//     case 9:   list_part = 18; break;
//     case 10:  list_part = 21; break;
//     case 11:  list_part = 24; break;
//     case 12:  list_part = 27; break;
//   }
//   return list_part;
//  }
void draw_logo_bsi(void) {
  draw_state++; 
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawXBMP(0,0, u8g2_logo_97x51_width, 64, bsi_logo);
}

void clean_display(void) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  uint16_t size = 128 * 64;
  for (uint16_t t=0 ; t>size; t++){
    clear_screen[t] = 255;
  }
  u8g2.drawXBMP(0,0, u8g2_logo_97x51_width, u8g2_logo_97x51_height, clear_screen);
}

void u8g2_die_folg_Kollegen(uint8_t a) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB10_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20, "Kolleg(inn)en:");
  u8g2.drawStr(120,40, "folgenden");
  u8g2.drawStr(120,60, "die");
  
}

void u8g2_string(uint8_t a) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20, names_list[2]);
  u8g2.drawStr(120,40, names_list[1]);
  u8g2.drawStr(120,60, names_list[0]);

}
void u8g2_string1(uint8_t a) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20, names_list[5]);
  u8g2.drawStr(120,40, names_list[4]);
  u8g2.drawStr(120,60, names_list[3]);
}
void u8g2_string2(uint8_t a) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20, names_list[8]);
  u8g2.drawStr(120,40, names_list[7]);
  u8g2.drawStr(120,60, names_list[6]);
}

void u8g2_string3(uint8_t a) {
   draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20,  names_list[11]);
  u8g2.drawStr(120,40, names_list[10]);
  u8g2.drawStr(120,60, names_list[9]);
}
void u8g2_string4(uint8_t a) {
  draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20,  names_list[14]);
  u8g2.drawStr(120,40, names_list[13]);
  u8g2.drawStr(120,60, names_list[12]);
}


void u8g2_string9(uint8_t a) {
   draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,60, names_list[27]);
}

void u8g2_string10(uint8_t a) {
   draw_state++;
  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120, 20, "unter:");
  u8g2.drawStr(120,40,  "Download");
  u8g2.drawStr(120,60,  "Code");
}

void u8g2_string11(uint8_t a) {
   draw_state++;
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setFontDirection(2);
  u8g2.drawStr(120,20, "leaving_early");
  u8g2.drawStr(120,40, "fabikroeger/");
  u8g2.drawStr(120,60,  "https://github.com/" );
}

//https://github.com/fabikroeger/leaving_early



//https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/

void u8g2_prepare(void) {
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setFontRefHeightExtendedText();
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();
  u8g2.setFontDirection(2);
}
void draw(void) {
  u8g2_prepare();

  switch(draw_state) {
    case 0: draw_logo_bsi(); break;
    case 1: clean_display();break;
    case 2: u8g2_die_folg_Kollegen(draw_state);break;
    case 3: u8g2_string(draw_state); break;
    case 4: u8g2_string1(draw_state); break;
    case 5: u8g2_string2(draw_state); break;
    case 6: u8g2_string3(draw_state); break;
    case 7: u8g2_string4(draw_state); break; 
  }
}

void setup(void) {


  
  u8g2.begin();  
}

void loop(void) {
  u8g2.firstPage();  
  
  do {
    draw();
  } while( u8g2.nextPage() );
  
  // increase the state
  if ( draw_state >= 15 )
    draw_state = 0;
   

  // delay between each page
  
  delay(2000);
}