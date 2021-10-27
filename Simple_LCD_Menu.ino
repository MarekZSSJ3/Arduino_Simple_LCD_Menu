//--------------------------------------------------------------------------------------------- 

#include <LiquidCrystal.h>                    //Library 
LiquidCrystal lcd(13,12,5,4,3,2);             //Data PIN connection

//--------------------------------------------------------------------------------------------- 

// Manu states
const int state_1 = 0;                        // Choose - state OR menu mode
const int state_2 = 1;                        // Sensor working state

// Position counter
int position_s; 
// State counter
int state_s;

//--------------------------------------------------------------------------------------------- 

void setup() 
{

  // 8 and 9 switches - up and down changing position_s
  pinMode(8, INPUT_PULLUP);                   // Up - switch
  pinMode(9, INPUT_PULLUP);                   // Down - switch
  // 10 and 11 switches - select and return changing state_s
  pinMode(10, INPUT_PULLUP);                  // Select - switch
  pinMode(11, INPUT_PULLUP);                  // Return - switch

  Serial.begin(9600);                         // Sets the data rate in bits per second (baud) for serial data transmission. 
  //Serial.println();                           // Prints data to the serial port as human-readable ASCII text
                                              // followed by a carriage return character (ASCII 13, or '\r') and a newline 
                                              // character (ASCII 10, or '\n'). 
                                              // This command takes the same forms as Serial.print().


  // Menu - first display
  lcd.begin(16, 2);                           // Type declaration
  lcd.setCursor(0, 0);                        // Cursor setting
  lcd.print("Choose sensor:  ");              // Text
  lcd.setCursor(0, 1);                        
  lcd.print("1. Sensor       ");                  
  lcd.cursor();  

  // Setting position_s on first sensor
  position_s = 0;
  // Setting state_s on menu mode
  state_s = state_1;
}



 
void loop() 
{
   // Display settigs ******************************************************************
   //-----------------------------------------------------------------------------------
   if (state_s == state_1)
   { 
   // Programowanie Menu - ekran wyboru    
      if (position_s == 0)
      {
        lcd.setCursor(0, 1);                            // Cursor setting
        lcd.print("1. Pressure     ");                  // Text
        lcd.cursor();                                   // Cursor ON
      } 
      else if (position_s == 1)
      {
        lcd.setCursor(0, 1);                        
        lcd.print("2. Sensor       ");                      
        lcd.cursor();                                     
      }
      else if (position_s == 2)
      {
        lcd.setCursor(0, 1);                        
        lcd.print("3. Sensor       ");               
        lcd.cursor();                                         
      }
      else if (position_s == 3)
      {
        lcd.setCursor(0, 1);                        
        lcd.print("4. Sensor       ");                 
        lcd.cursor();     
      }
      else if (position_s == 4)
      {
        lcd.setCursor(0, 1);                        
        lcd.print("5. Sensor       ");              
        lcd.cursor();     
      }
      else if (position_s == 5)
      {
        lcd.setCursor(0, 1);                        
        lcd.print("6. Sensor       ");                
        lcd.cursor();
      }
      else                                        // if state_s is another value
      {
        lcd.setCursor(0, 1);                        
        lcd.print("0. Wrong state  ");                
        lcd.cursor();                                     
      }
   }
   //-----------------------------------------------------------------------------------
   else if(state_s == state_2)
   {
      lcd.setCursor(0, 0);                         
      lcd.print("Sensor working: ");                 
      lcd.setCursor(0, 1);
      if (position_s == 0)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("1.              ");                      
        lcd.cursor();                                
      } 
      else if (position_s == 1)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("2.              ");                          
        lcd.cursor();                                      
      }
      else if (position_s == 2)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("3.              ");                   
        lcd.cursor();                                          
      }
      else if (position_s == 3)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("4.              ");                     
        lcd.cursor();     
      }
      else if (position_s == 4)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("5.              ");                      
        lcd.cursor();     
      }
      else if (position_s == 5)
      {
        lcd.setCursor(0, 1);                         
        lcd.print("6.              ");                    
        lcd.cursor();
      }
      else 
      {
        lcd.setCursor(0, 1);                         
        lcd.print("Error           ");                       
        lcd.cursor();                                    
      }
   }
   //-----------------------------------------------------------------------------------
   // Display settigs ******************************************************************
    
   // PIN settings *********************************************************************
   //-----------------------------------------------------------------------------------

   if (state_s == state_1)                              // You can change position_s only
   {                                                    // In Menu Mode
      // Switch Up
      if (digitalRead(8) == HIGH)                       // If pushed Up
      { 
        delay(250); // Wait 0.25 second
        if(position_s <= 0)
        {
           position_s = 5;                              // change position on last
        }
        else 
        {
          position_s = position_s - 1;                  // decrement position = higher 
        }                                               // position in menu 
      }
      // Switch Down
      if (digitalRead(9) == HIGH)                       // If pushed Down
      { 
        delay(250); // Wait 0.25 second
        if(position_s >= 5)
        {
          position_s = 0;                               // change position on first
        }
        else 
        {
          position_s = position_s + 1;                  // increment position = lower
        }                                               // position in menu
      }
   }   
   // Switch Select
   if (digitalRead(10) == HIGH)                       // If pushed Select
   { 
      delay(250); // Wait 0.25 second
      if(state_s == state_1)
      {
        state_s = state_2;
      }
   }
   // Switch Return
   if (digitalRead(11) == HIGH)                       // If pushed Return
   { 
      delay(250); // Wait 0.25 second
      if(state_s == state_2)
      {
        state_s = state_1;
      }
   }
   //-----------------------------------------------------------------------------------
   // PIN settings *********************************************************************

   // Sensors programms ****************************************************************
   //-----------------------------------------------------------------------------------
   if (state_s == state_2)
   {
     switch(position_s)
     {
        case 0:
          // sensor 1 programm   
          break;
        case 1:
          // sensor 2 programm   
          break;  
        case 2:
          // sensor 3 programm   
          break;    
        case 3:
          // sensor 4 programm   
          break;
        case 4:
          // sensor 5 programm   
          break;
        case 5:
          // sensor 6 programm   
          break;            
     }
   }
   //-----------------------------------------------------------------------------------    
   // Sensors programms ****************************************************************
   
}
