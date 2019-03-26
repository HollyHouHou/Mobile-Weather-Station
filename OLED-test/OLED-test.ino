//显示图片程序 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> 
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET); 
static const unsigned char PROGMEM logo[] ={0x04,0x04,0x7C,0x04,0x04,0x04,//T0,
0x00,0x70,0x68,0x68,0x50,0x00,//e1,
0x78,0x48,0x48,0x70,0x48,0x70,//m2,
0x08,0xF8,0x48,0x48,0x70,0x00,//p3,
0x00,0x70,0x68,0x68,0x50,0x00,//e4,
0x08,0x48,0x70,0x08,0x08,0x00,//r5,
0x00,0x60,0x58,0x58,0x70,0x40,//a6,
0x00,0x08,0x7C,0x48,0x48,0x00,//t7,
0x08,0x78,0x40,0x40,0x78,0x40,//u8,
0x08,0x48,0x70,0x08,0x08,0x00,//r9,
0x00,0x70,0x68,0x68,0x50,0x00,//e10,
0x00,0x00,0x48,0x48,0x00,0x00,//:11,
0x00,0x64,0x62,0x52,0x4C,0x00,//212,
0x00,0x7C,0x42,0x42,0x7C,0x00,//013,
0x00,0x02,0x06,0x02,0x3C,0x42,
0x42,0x42,0x42,0x04,0x00,0x00,//℃14,
};  
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif 
void setup()   {
  Serial.begin(9600);  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);   
  display.clearDisplay();} 
void loop() {  
  display.drawBitmap(0, 0, logo, 128, 64, 1);  //在坐标X0，Y0的位置开始显示图片                                               
  //128是取模软件显示的宽度                                               //64是取模软件显示的高度  
  display.display();                           //把缓存的都显示  
  delay(1);    
  display.clearDisplay();     //清除屏幕}
}