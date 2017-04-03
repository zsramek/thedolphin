// Dolphin
// Ryan Corkery
// ZRcubed
// February 2017

#include <Wire.h>

int tempo;
int instrument;
int ch1_0;
int ch1_4;
int ch1_8;
int ch1_12;

// Save and load settings arrays
char new_settings[263];
char current_settings[263]; 

// UI buttons
int loop_up = 7;
int loop_down = 8;

int loop_number = 0;
int max_loop_number = 99;

// Button de-bounce
boolean clicked8 = false;
boolean clicked9 = false;

// Loop change
boolean loop_change_up =  false;
boolean loop_change_down = false;
char change_cstr = '\0';

void setup() 
{
  pinMode(loop_up,INPUT);
  pinMode(loop_down,INPUT);
  
  digitalWrite(loop_up,LOW);
  digitalWrite(loop_down,LOW);

  // join i2c bus 
  Wire.begin();             
}

void loop() 
{  
  // Slow for testing
  delay(1000);
  
  // Determine if loop changes and load settings
  loop_change();

  poll_buttons();

  // Settings from loop: poll buttons, tempo, intrument #
  int tempo = 120;
  int instrument = 8;
  int ch1_1 = 1000;
  int ch1_4 = 1000;
  int ch1_8 = 1000;
  int ch1_12 = 1000;

  // Move send_settings to poll_buttons after each poll
  // To increase the update rate of the LCD
  send_settings();
}

void loop_change()
{
  if ( loop_change_up == true)
  {
  loop_number ++;
  load_settings();
  loop_change_up = false;
  }

  if ( loop_change_down == true)
  {
  loop_number --;
  load_settings();
  loop_change_down = false;
  }
}

void poll_buttons()
{
  // Loop up
  if (digitalRead(loop_up) == HIGH && loop_number < max_loop_number && clicked8 == false)
  {
    loop_change_up = true;
    change_cstr = '0';
    clicked8 = true;
  }

  else if (digitalRead(loop_up) == LOW && clicked8 == true)
  clicked8 = false;

  // loop down  
  if (digitalRead(loop_down) == HIGH && loop_number > 0 && clicked9 == false)
  {
    loop_change_down = true;
    change_cstr = '1';
    clicked9 = true;
  }
  
  else if (digitalRead(loop_down) == LOW && clicked9 == true)
  clicked9 = false;
}

void send_settings()
{ 
  // Create a string of all settings
  
  // Zero padding for loop_number
  char loop_padding = '\0';
  if (loop_number < 10)
  loop_padding = '0';

  // Zero padding for tempo. Combine into one array
  char tempo_padding_0 = '\0';
  char tempo_padding_1 = '\0';
  if (tempo < 100)
  {
    tempo_padding_0 = '0';

    if (tempo < 10)
    tempo_padding_1 = '0';
  }

  // Zero padding for instrument
  char instrument_padding = '\0';
  if (instrument < 10)
  instrument_padding = '0';

  // Get string of steps
  String all_steps = steps_string();
  
  // Combined settings string
  String combine =String(loop_padding)+String(loop_number)+String(tempo_padding_0)+String(tempo_padding_1)+String(tempo)+String(instrument_padding)+String(instrument)+String(change_cstr)+all_steps+String('\0');
  // Convert string to char array
  combine.toCharArray(current_settings,263); 

  // Send settings to slave
  Wire.beginTransmission(8);     // transmit to device #8
  Wire.write(current_settings);              
  Wire.endTransmission();        // stop transmitting
}

void load_settings ()
{
  // Read settings from slave
  Wire.requestFrom(8, 263); 
  
  while (Wire.available()) 
  { 
  for (byte i = 0; i < 263 ; i ++)
    {
      char c = Wire.read();
      new_settings[i] = c;
    }
  }
}

String steps_string ()
{
  String str;

  for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps0[i][n]);
    }
  }

  for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps1[i][n]);
    }
  }

  for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps2[i][n]);
    }
  }
  
    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps3[i][n]);
    }
  }
  
    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps4[i][n]);
    }
  }
  
    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps5[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps6[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps7[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps8[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps9[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps10[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps11[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps12[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps13[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps14[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps15[i][n]);
    }
  }

    for (int i = 0; i < 4; i++)
  {
    for (int n = 0; n < 4; n++)
    {
      str += String (steps16[i][n]);
    }
  }

  return str;
}

