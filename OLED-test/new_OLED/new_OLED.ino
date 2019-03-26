#include <dht.h> 
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>   
float str1,str2; 
dht DHT;  
//#define OLED_MOSI  D7
//#define OLED_CLK   D5
//#define OLED_DC    D0
//#define OLED_CS    D8
//#define OLED_RESET D3
#define DHT22_PIN A2
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);  

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
void setup()  
{  
  Serial.begin(9600);  
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC);//初始化
  display.display();
  display.clearDisplay();
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
}    
void loop()  
{ 
  Serial.print("DHT22, \t");
  int chk = DHT.read22(DHT22_PIN);  //读取数据
  switch (chk)
  {
    case DHTLIB_OK:  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.print("Time out error,\t"); 
                break;
    default: 
                Serial.print("Unknown error,\t"); 
                break;
  }
  // 显示数据
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  //DHT22.read(PIN_DHT22);  
 // Serial.print("Humidity: ");  
 // Serial.println((float)DHT22.humidity, 2);  //串口显示
  str1=DHT.humidity;
  display.print("Humidity:");
  display.println(str1);
 // Serial.print("Temperature: ");  
 // Serial.println((float)DHT22.temperature, 2);//串口显示
  str2=DHT.temperature;
  display.print("Temperature:");
  display.println(str2); 
  display.display();//显示出来
  delay(300);  
  display.clearDisplay();
} 
