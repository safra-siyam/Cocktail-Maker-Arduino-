//YouTube | Tech at Home

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,16,2);

const char number_of_rows = 4;
const char number_of_columns = 4;

char row_pins[number_of_rows] = {2, 3, 4, 5};
char column_pins[number_of_columns] = {6, 7, 8, 9};

char key_array[number_of_rows][number_of_columns] = {  
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
  };

Keypad k = Keypad(makeKeymap(key_array),row_pins , column_pins, number_of_rows, number_of_columns);

       #define moter1 12
       #define moter2 11
       #define moter3 13

void setup()
{
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();
  lcd.setBacklight(HIGH);

          pinMode(moter1,OUTPUT);
          pinMode(moter2,OUTPUT);
          pinMode(moter3,OUTPUT);
          digitalWrite(moter2,1);
          digitalWrite(moter3,1);
          digitalWrite(moter1,1);
}

void loop()
{
  
  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print("Enter Your Drink Number");
  
  char key_pressed = k.getKey();
  if(key_pressed)
  {
    lcd.clear();
    Serial.println(key_pressed);
    lcd.setCursor(0,0);
    lcd.print(key_pressed);
    delay(2000);
            if(key_pressed == '*' || key_pressed == '#' || key_pressed == 'A' || key_pressed == 'B' || key_pressed == 'C' || key_pressed == 'D'){

                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("  Invalid Key!");
                  delay(2000);
                  lcd.clear();
          }
        else{
                  

                   lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print(" Processing!");
                  delay(2000);

                  lcd.clear();
                  lcd.setCursor(0, 0);
                  Serial.print(key_pressed);
                  printpro(key_pressed);
                  delay(2000);


                  delay(2000);

                  lcd.clear();
                  lcd.setCursor(0, 0);
                  lcd.print("Thank You!!");

                  delay(2000);
                  lcd.clear();

        }

  }
}



      void printpro(char number){
            Serial.print(number);

            if(number=='1')  //RED
            {

              lcd.print("Cranberry margarita");

                 digitalWrite(moter1,0);
                delay(15000);
                digitalWrite(moter1,1);
 
            }


            else if(number=='2')  //Yellow
            {
                lcd.print("Yellow Smash"); 
              
                digitalWrite(moter2,0);
                delay(10000);
                digitalWrite(moter2,1);

            }


            else if(number=='3')  //Blue
            {
                lcd.print("Sapphire Martini"); 

                digitalWrite(moter3,0);
                delay(16000);
                digitalWrite(moter3,1);
 
            }



            else if(number=='4')    //Orange
            {
                lcd.print("The Countess"); 

                digitalWrite(moter1,0);
                delay(8000);
                digitalWrite(moter1,1);

                digitalWrite(moter2,0);
                delay(5000);
                digitalWrite(moter2,1);

                
            }



            else if(number=='5')  //Violet
            {
                lcd.print("Violet Fizz"); 

                digitalWrite(moter1,0);
                delay(8000);
                digitalWrite(moter1,1);

                digitalWrite(moter3,0);
                delay(8000);
                digitalWrite(moter3,1);

              
            }




              else if(number=='6') //Green
            {
                lcd.print("Irish Margarita"); 

                digitalWrite(moter2,0);
                delay(5000);
                digitalWrite(moter2,1);

                digitalWrite(moter3,0);
                delay(8000);
                digitalWrite(moter3,1);
 
            }


            else if(number=='7')
            {
                lcd.print("Espresso martini"); 

                digitalWrite(moter1,0);
                delay(5000);
                digitalWrite(moter1,1);

                digitalWrite(moter2,0);
                delay(5000);
                digitalWrite(moter2,1);

                digitalWrite(moter3,0);
                delay(4000);
                digitalWrite(moter3,1);

            }
            
          }
         