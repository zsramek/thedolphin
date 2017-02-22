//LEDS
const int row[4] = {24, 25, 26, 27};
const int col[4] = {28, 29, 30, 31};
boolean lights[4][4];

int ledRow0 = 24;
int ledRow1 = 25;
int ledRow2 = 26;
int ledRow3 = 27;
int ledCol0 = 28;
int ledCol1 = 29;
int ledCol2 = 30;
int ledCol3 = 31;

//BUTTONS
int buttonRow = 1;
int button = 0; //for testing purposes

boolean clicked0 = false;
boolean clicked1 = false;
boolean clicked2 = false;
boolean clicked3 = false;
boolean clicked4 = false;
boolean clicked5 = false;
boolean clicked6 = false;
boolean clicked7 = false;

int buttonIn0 = 40;
int buttonIn1 = 41;
int buttonIn2 = 42;
int buttonIn3 = 43;
int buttonOut0 = 44;
int buttonOut1 = 45;
int buttonOut2 = 46;
int buttonOut3 = 47;

/////////////////////////

void setup()
{
  buttonSetup();
  ledSetup();
}

void loop()
{ 
  scanButtons();
  refreshLEDs();
}

////////////////////////

void buttonSetup()
{
  pinMode(buttonIn0, INPUT);
  pinMode(buttonIn1, INPUT);
  pinMode(buttonIn2, INPUT);
  pinMode(buttonIn3, INPUT);
  pinMode(buttonOut0, OUTPUT);
  pinMode(buttonOut1, OUTPUT);
  pinMode(buttonOut2, OUTPUT);
  pinMode(buttonOut3, OUTPUT);
  Serial.begin(9600);//testing
}

void ledSetup()
{
  pinMode(ledRow0, OUTPUT);
  pinMode(ledRow1, OUTPUT);
  pinMode(ledRow2, OUTPUT);
  pinMode(ledRow3, OUTPUT);
  
  pinMode(ledCol0, OUTPUT);
  pinMode(ledCol1, OUTPUT);
  pinMode(ledCol2, OUTPUT);
  pinMode(ledCol3, OUTPUT);
  
  digitalWrite(ledRow0, LOW);
  digitalWrite(ledRow1, LOW);
  digitalWrite(ledRow2, LOW);
  digitalWrite(ledRow3, LOW);
  
  digitalWrite(ledCol0, HIGH);
  digitalWrite(ledCol1, HIGH);
  digitalWrite(ledCol2, HIGH);
  digitalWrite(ledCol3, HIGH);
  
  lights[0][0] = HIGH;
  lights[0][1] = HIGH;
  lights[0][2] = HIGH;
  lights[0][3] = HIGH;
  //~~~~~~~~~~~~~~~~~~
  lights[1][0] = HIGH;
  lights[1][1] = HIGH;
  lights[1][2] = HIGH;
  lights[1][3] = HIGH;
  //~~~~~~~~~~~~~~~~~~
  lights[2][0] = HIGH;
  lights[2][1] = HIGH;
  lights[2][2] = HIGH;
  lights[2][3] = HIGH;
  //~~~~~~~~~~~~~~~~~~
  lights[3][0] = HIGH;
  lights[3][1] = HIGH;
  lights[3][2] = HIGH;
  lights[3][3] = HIGH;
}

void scanButtons()
{
  //~~~~~~~~~~~~~~1~~~~~~~~~~~~~~~
  if (buttonRow == 1)
  {
    digitalWrite(buttonOut0, HIGH);
    digitalWrite(buttonOut1, LOW);
    digitalWrite(buttonOut2, LOW);
    digitalWrite(buttonOut3, LOW);
    
    if (digitalRead(buttonIn0) == HIGH)
    {
      if (clicked0 == false)
      {
        button = 1;
        lights[0][0] = !lights[0][0];
        clicked0 = true;
      }
    }
    else if (digitalRead(buttonIn0) == LOW)
    {
      if (clicked0 == true)
      {
        clicked0 = false;
      }
    }
    
    //~~~~
    
    if (digitalRead(buttonIn1) == HIGH)
    {
      if (clicked1 == false)
      {
        button = 2;
        lights[0][1] = !lights[0][1];
        clicked1 = true;
      }
    }
    else if (digitalRead(buttonIn1) == LOW)
    {
      if (clicked1 == true)
      {
        clicked1 = false;
      }
    }
    
    //~~~
    
    if (digitalRead(buttonIn2) == HIGH)
    {
      if (clicked2 == false)
      {
        button = 3;
        lights[0][2] = !lights[0][2];
        clicked2 = true;
      }
    }
    else if (digitalRead(buttonIn2) == LOW)
    {
      if (clicked2 == true)
      {
        clicked2 = false;
      }
    }

    //~~~
    
    if (digitalRead(buttonIn3) == HIGH)
    {
      if (clicked3 == false)
      {
        button = 4;
        lights[0][3] = !lights[0][3];
        clicked3 = true;
      }
    }
    else if (digitalRead(buttonIn3) == LOW)
    {
      if (clicked3 == true)
      {
        clicked3 = false;
      }
    }    
    
    buttonRow = 2; //Must come after
  }
  
  //~~~~~~~~~~~~~~2~~~~~~~~~~~~~~~
  
  else if (buttonRow == 2)
  {
    digitalWrite(buttonOut1, HIGH);
    digitalWrite(buttonOut0, LOW);
    digitalWrite(buttonOut2, LOW);
    digitalWrite(buttonOut3, LOW);
    
    if (digitalRead(8) == HIGH)
    {
      if (clicked3 == false)
      {
        button = 3;
        lights[1][0] = LOW;
        clicked3 = true;
      }
    }
    else if(digitalRead(8) == LOW)
    {
      if (clicked3 == true)
      {
        clicked3 = false;
      }
    }
    if (digitalRead(9) == HIGH)
    {
      if (clicked4 == false)
      {
        button = 4;
        lights[1][1] = LOW;
        clicked4 = true;
      }
    }
    else if (digitalRead(9) == LOW)
    {
      if (clicked4 == true)
      {
        clicked4 = false;
      }
    }
    buttonRow = 1;
  }
  Serial.println(button);
}

void refreshLEDs()
{
  for (int thisRow = 0; thisRow < 4; thisRow++)
  {
    digitalWrite(row[thisRow], HIGH);
    for (int thisCol = 0; thisCol < 4; thisCol++)
    {
      int thisLight = lights[thisRow][thisCol];
      digitalWrite(col[thisCol], thisLight);
      if (thisLight == LOW)
      {
        digitalWrite(col[thisCol], HIGH);
      }
    }
    digitalWrite(row[thisRow], LOW);
  }
}
