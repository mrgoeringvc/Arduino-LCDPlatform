/* LCDPlatform2020
 * Using the 16 character 2 line I2C Display  typically labled 
 * "YwRobot Arduino LCM1602 IIC V1" or  
 * SainSmart LCD2004. Note: Of these LCDs 
 * most used address 0x27, a FEW use 0x3F.
 * 
 * LastMod:1/15/20, Publish, m comm
 * ORIGIONAL LCD Code YourDuino.com, terry@yourduino.com 
*/

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
/*
  Get the LCD I2C Library here: 
  https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
  Move any other LCD libraries to another folder or delete them
  so they don't interfer as a duplicate library.
  See Library "Docs" folder for possible commands etc.
*/

/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 16 chars 2 line display
// A FEW use address 0x3F
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the lcd I2C address
// If you see an error related to "POSITIVE" then the wrong library was used.

/*-----( Declare Variables )-----*/
String splashMsg = "LCD-Platform2020";

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to display and type in characters PC monitor

  lcd.begin(16,2);   // initialize the LCD for 16 chars 2 lines,
                     // then turn on backlight

// ------- Quick 2 blinks to show we are alive  -------------
  for(int i = 0; i< 2; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250); 
  }
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("My Basic LCD Loop");
  delay(100);
  lcd.setCursor(0,1); //for line 2
  // Text 16"XXXXxxxxXXXXxxxx" charactors long.
  lcd.print("Basic Program");
  delay(2000);  

// Wait and then tell user they can start the Serial Monitor and type in characters to
// Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  

  lcd.setCursor(0,0); // top line
  lcd.print("My Basic LCD Loop");
  delay(100);

  }/* --(end main loop )-- */
