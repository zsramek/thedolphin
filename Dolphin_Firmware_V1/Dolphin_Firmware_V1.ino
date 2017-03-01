//LEDS
const int row[4] = {
  24, 25, 26, 27};
const int col[4] = {
  28, 29, 30, 31};
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
boolean clicked8 = false;
boolean clicked9 = false;
boolean clicked10 = false;
boolean clicked11 = false;
boolean clicked12 = false;
boolean clicked13 = false;
boolean clicked14 = false;
boolean clicked15 = false;

int buttonIn0 = 40;
int buttonIn1 = 41;
int buttonIn2 = 42;
int buttonIn3 = 43;
int buttonOut0 = 44;
int buttonOut1 = 45;
int buttonOut2 = 46;
int buttonOut3 = 47;

//SEQUENCE
boolean run = true;
int count = 0;
int maxCount = 400;
int trigCount = 20;
int currentStep = 0;
int maxStep = 15;
int currentRow = 0;
int currentCol = 3;

//TRIGGERING
boolean steps[4][4];
//temp
int triggerOut = 8;
//temp

/////////////////////////

void setup()
{
  buttonSetup();
  ledSetup();
  seqSetup();
}

void loop()
{ 
  runSeq();
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
  lights[0][3] = LOW; //To account for seq logic
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

void seqSetup()
{
  //For now just reset the steps on powerup
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      steps[i][j] = false;
    }
  }
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
        steps[0][0] = !steps[0][0];
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
        steps[0][1] = !steps[0][1];
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
        steps[0][2] = !steps[0][2];
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
        steps[0][3] = !steps[0][3];
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

    if (digitalRead(buttonIn0) == HIGH)
    {
      if (clicked4 == false)
      {
        button = 5;
        steps[1][0] = !steps[1][0];
        clicked4 = true;
      }
    }
    else if (digitalRead(buttonIn0) == LOW)
    {
      if (clicked4 == true)
      {
        clicked4 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn1) == HIGH)
    {
      if (clicked5 == false)
      {
        button = 6;
        steps[1][1] = !steps[1][1];
        clicked5 = true;
      }
    }
    else if (digitalRead(buttonIn1) == LOW)
    {
      if (clicked5 == true)
      {
        clicked5 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn2) == HIGH)
    {
      if (clicked6 == false)
      {
        button = 7;
        steps[1][2] = !steps[1][2];
        clicked6 = true;
      }
    }
    else if (digitalRead(buttonIn2) == LOW)
    {
      if (clicked6 == true)
      {
        clicked6 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn3) == HIGH)
    {
      if (clicked7 == false)
      {
        button = 8;
        steps[1][3] = !steps[1][3];
        clicked7 = true;
      }
    }
    else if (digitalRead(buttonIn3) == LOW)
    {
      if (clicked7 == true)
      {
        clicked7 = false;
      }
    }
    buttonRow = 3; 
  }

  //~~~~~~~~~~~~~~3~~~~~~~~~~~~~~~
  if (buttonRow == 3)
  {
    digitalWrite(buttonOut2, HIGH);
    digitalWrite(buttonOut0, LOW);
    digitalWrite(buttonOut1, LOW);
    digitalWrite(buttonOut3, LOW);

    if (digitalRead(buttonIn0) == HIGH)
    {
      if (clicked8 == false)
      {
        button = 9;
        steps[2][0] = !steps[2][0];
        clicked8 = true;
      }
    }
    else if (digitalRead(buttonIn0) == LOW)
    {
      if (clicked8 == true)
      {
        clicked8 = false;
      }
    }

    //~~~~

    if (digitalRead(buttonIn1) == HIGH)
    {
      if (clicked9 == false)
      {
        button = 10;
        steps[2][1] = !steps[2][1];
        clicked9 = true;
      }
    }
    else if (digitalRead(buttonIn1) == LOW)
    {
      if (clicked9 == true)
      {
        clicked9 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn2) == HIGH)
    {
      if (clicked10 == false)
      {
        button = 11;
        steps[2][2] = !steps[2][2];
        clicked10 = true;
      }
    }
    else if (digitalRead(buttonIn2) == LOW)
    {
      if (clicked10 == true)
      {
        clicked10 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn3) == HIGH)
    {
      if (clicked11 == false)
      {
        button = 12;
        steps[2][3] = !steps[2][3];
        clicked11 = true;
      }
    }
    else if (digitalRead(buttonIn3) == LOW)
    {
      if (clicked11 == true)
      {
        clicked11 = false;
      }
    }
    buttonRow = 4; 
  }

  //~~~~~~~~~~~~~~4~~~~~~~~~~~~~~~
  if (buttonRow == 4)
  {
    digitalWrite(buttonOut3, HIGH);
    digitalWrite(buttonOut0, LOW);
    digitalWrite(buttonOut1, LOW);
    digitalWrite(buttonOut2, LOW);

    if (digitalRead(buttonIn0) == HIGH)
    {
      if (clicked12 == false)
      {
        button = 13;
        steps[3][0] = !steps[3][0];
        clicked12 = true;
      }
    }
    else if (digitalRead(buttonIn0) == LOW)
    {
      if (clicked12 == true)
      {
        clicked12 = false;
      }
    }

    //~~~~

    if (digitalRead(buttonIn1) == HIGH)
    {
      if (clicked13 == false)
      {
        button = 14;
        steps[3][1] = !steps[3][1];
        clicked13 = true;
      }
    }
    else if (digitalRead(buttonIn1) == LOW)
    {
      if (clicked13 == true)
      {
        clicked13 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn2) == HIGH)
    {
      if (clicked14 == false)
      {
        button = 15;
        steps[3][2] = !steps[3][2];
        clicked14 = true;
      }
    }
    else if (digitalRead(buttonIn2) == LOW)
    {
      if (clicked14 == true)
      {
        clicked14 = false;
      }
    }

    //~~~

    if (digitalRead(buttonIn3) == HIGH)
    {
      if (clicked15 == false)
      {
        button = 16;
        steps[3][3] = !steps[3][3];
        clicked15 = true;
      }
    }
    else if (digitalRead(buttonIn3) == LOW)
    {
      if (clicked15 == true)
      {
        clicked15 = false;
      }
    }
    buttonRow = 1; 
  }
  //Serial.println(button);
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

void runSeq()
{
  if (run)
  {
    if (count >= maxCount)
    {
      count = 0;
      //flip the old one back
      //lights[currentRow][currentCol] = !lights[currentRow][currentCol];
      alignSteps();
      if (currentStep < maxStep)
      {
        currentStep++;
      }
      else
      {
        currentStep = 0;
      }
      
      //Serial.println(currentStep);
      //flip the new one
      decodeStep();
      //lights[currentRow][currentCol] = !lights[currentRow][currentCol];
    }
    else
    {
      count++;
      if (steps[currentRow][currentCol] == true)
      {
        //Triggers
        if (count < trigCount)
        {
          digitalWrite(triggerOut, HIGH);
        }
        else
        {
          digitalWrite(triggerOut, LOW);
        }
        //LEDs
        lights[currentRow][currentCol] = HIGH;
      }
      else
      {
        digitalWrite(triggerOut, LOW);
        lights[currentRow][currentCol] = LOW;
      }
      //alignSteps();
      //lights[currentRow][currentCol] = !lights[currentRow][currentCol];
    }
  
  }
}

//////////////////////SUBROUTINES////////////////////

//This subroutine looks at the current step and sets the column and row correctly
void decodeStep()
{
  if (currentStep == 0)
  {
    currentRow = 0;
    currentCol = 3;
  }
  else if (currentStep == 1)
  {
    currentRow = 1;
    currentCol = 3;
  }
  else if (currentStep == 2)
  {
    currentRow = 2;
    currentCol = 3;
  }
  else if (currentStep == 3)
  {
    currentRow = 3;
    currentCol = 3;
  }
  else if (currentStep == 4)
  {
    currentRow = 0;
    currentCol = 2;
  }
  else if (currentStep == 5)
  {
    currentRow = 1;
    currentCol = 2;
  }
  else if (currentStep == 6)
  {
    currentRow = 2;
    currentCol = 2;
  }
  else if (currentStep == 7)
  {
    currentRow = 3;
    currentCol = 2;
  }
  else if (currentStep == 8)
  {
    currentRow = 0;
    currentCol = 1;
  }
  else if (currentStep == 9)
  {
    currentRow = 1;
    currentCol = 1;
  }
  else if (currentStep == 10)
  {
    currentRow = 2;
    currentCol = 1;
  }
  else if (currentStep == 11)
  {
    currentRow = 3;
    currentCol = 1;
  }
  else if (currentStep == 12)
  {
    currentRow = 0;
    currentCol = 0;
  }
  else if (currentStep == 13)
  {
    currentRow = 1;
    currentCol = 0;
  }
  else if (currentStep == 14)
  {
    currentRow = 2;
    currentCol = 0;
  }
  else if (currentStep == 15)
  {
    currentRow = 3;
    currentCol = 0;
  }
}

//This subroutine iterates through the step and led matrices and aligns them
void alignSteps()
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (steps[i][j] == true)
      {
        lights[i][j] = LOW;
      }
      else
      {
        lights[i][j] = HIGH;
      }
    }
  }
}


