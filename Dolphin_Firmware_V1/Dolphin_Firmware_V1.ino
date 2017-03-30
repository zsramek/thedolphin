//TODO
//Triggering code for all channels - To Test
//Live-play scanning and triggering
//I2C interfacing
//Tempo - To Test
//Start/Stop Button - To Test

//LEDS
int ledRow0 = 22;
int ledRow1 = 23;
int ledRow2 = 24;
int ledRow3 = 25;
int ledCol0 = 26;
int ledCol1 = 27;
int ledCol2 = 28;
int ledCol3 = 29;

const int row[4] = {
  ledRow0, ledRow1, ledRow2, ledRow3
};
const int col[4] = {
  ledCol0, ledCol1, ledCol2, ledCol3
};
boolean lights[4][4];


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

int buttonIn0 = 30;
int buttonIn1 = 31;
int buttonIn2 = 32;
int buttonIn3 = 33;
int buttonOut0 = 34;
int buttonOut1 = 35;
int buttonOut2 = 36;
int buttonOut3 = 37;

//Start-Stop
int startStopButton = 8;
boolean startStopClicked = false;
boolean run = true;
int startStopCount = 0;
int startStopMax = 1000;
boolean startStopCounting = false;

//SEQUENCE
int count = 0;
int maxCount = 400;
int trigCount = 20;
int currentStep = 0;
int maxStep = 15;
int currentRow = 0;
int currentCol = 3;
int rawTempoData = 0;
int maxTempo = 20;
int tempoThreshold = 5;

//CHANNEL SELECT
int channel = 0;
int bank = 0;

//TRIGGERING
boolean steps[4][4];
boolean steps0[4][4];
boolean steps1[4][4];
boolean steps2[4][4];
boolean steps3[4][4];
boolean steps4[4][4];
boolean steps5[4][4];
boolean steps6[4][4];
boolean steps7[4][4];
boolean steps8[4][4];
boolean steps9[4][4];
boolean steps10[4][4];
boolean steps11[4][4];
boolean steps12[4][4];
boolean steps13[4][4];
boolean steps14[4][4];
boolean steps15[4][4];

//Trigger Output Pins
int triggerOut0 = 38;
int triggerOut1 = 39;
int triggerOut2 = 40;
int triggerOut3 = 41;
int triggerOut4 = 42;
int triggerOut5 = 43;
int triggerOut6 = 44;
int triggerOut7 = 45;
int triggerOut8 = 46;
int triggerOut9 = 47;
int triggerOut10 = 48;
int triggerOut11 = 49;
int triggerOut12 = 50;
int triggerOut13 = 51;
int triggerOut14 = 52;
int triggerOut15 = 53;

//temp
int triggerOut = 38;
//temp

/////////////////////////

void setup()
{
  rotarySetup();
  buttonSetup();
  ledSetup();
  triggerSetup();
  seqSetup();
  startStopSetup();
}

void loop()
{
  //Serial.println(run);
  if (run == true)
  {
    runSeq();
    scanButtons();
    refreshLEDs();
    updateChannelData();
    scanRotary();
  }
  startStop();
  //tempo();
}

////////////////////////

void rotarySetup()
{
  //Rotary Switch
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  //Flip Switch
  pinMode(A8, INPUT);
}

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

void startStopSetup()
{
  pinMode(startStopButton, INPUT);
  //attachInterrupt(digitalPinToInterrupt(startStopButton), startStop, RISING);
  //noInterrupts();
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

void triggerSetup()
{
  pinMode(triggerOut0, OUTPUT);
  pinMode(triggerOut1, OUTPUT);
  pinMode(triggerOut2, OUTPUT);
  pinMode(triggerOut3, OUTPUT);
  pinMode(triggerOut4, OUTPUT);
  pinMode(triggerOut5, OUTPUT);
  pinMode(triggerOut6, OUTPUT);
  pinMode(triggerOut7, OUTPUT);
  pinMode(triggerOut8, OUTPUT);
  pinMode(triggerOut9, OUTPUT);
  pinMode(triggerOut10, OUTPUT);
  pinMode(triggerOut11, OUTPUT);
  pinMode(triggerOut12, OUTPUT);
  pinMode(triggerOut13, OUTPUT);
  pinMode(triggerOut14, OUTPUT);
  pinMode(triggerOut15, OUTPUT);
}

void seqSetup()
{
  //For now just reset the steps on powerup
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      steps[i][j] = false;
      steps0[i][j] = false;
      steps1[i][j] = false;
      steps2[i][j] = false;
      steps3[i][j] = false;
      steps4[i][j] = false;
      steps5[i][j] = false;
      steps6[i][j] = false;
      steps7[i][j] = false;
      steps8[i][j] = false;
      steps9[i][j] = false;
      steps10[i][j] = false;
      steps11[i][j] = false;
      steps12[i][j] = false;
      steps13[i][j] = false;
      steps14[i][j] = false;
      steps15[i][j] = false;
    }
  }
}

//TEMPO
void tempo()
{
  if ((analogRead(A9) - rawTempoData) > tempoThreshold || (analogRead(A9) - rawTempoData) < -tempoThreshold)
  {
    rawTempoData = analogRead(A9);
    rawTempoData = 1024 - rawTempoData;
    rawTempoData = rawTempoData / 1024;
    maxCount = maxTempo * rawTempoData;
  }

}

//BUTTONS
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
}

//CHANNEL SELECT
void scanRotary()
{
  if (digitalRead(A8) == LOW)
  {
    bank = 0;
  }
  else if (digitalRead(A8) == HIGH)
  {
    bank = 1;
  }

  if (bank == 0)
  {
    if (digitalRead(A0) == HIGH)
    {
      channel = 0;
      memcpy(steps, steps0, sizeof steps0);
    }
    else if (digitalRead(A1) == HIGH)
    {
      channel = 1;
      memcpy(steps, steps1, sizeof steps1);
    }
    else if (digitalRead(A2) == HIGH)
    {
      channel = 2;
      memcpy(steps, steps2, sizeof steps2);
    }
    else if (digitalRead(A3) == HIGH)
    {
      channel = 3;
      memcpy(steps, steps3, sizeof steps3);
    }
    else if (digitalRead(A4) == HIGH)
    {
      channel = 4;
      memcpy(steps, steps4, sizeof steps4);
    }
    else if (digitalRead(A5) == HIGH)
    {
      channel = 5;
      memcpy(steps, steps5, sizeof steps5);
    }
    else if (digitalRead(A6) == HIGH)
    {
      channel = 6;
      memcpy(steps, steps6, sizeof steps6);
    }
    else if (digitalRead(A7) == HIGH)
    {
      channel = 7;
      memcpy(steps, steps7, sizeof steps7);
    }
  }
  else if (bank == 1)
  {
    if (digitalRead(A0) == HIGH)
    {
      channel = 8;
      memcpy(steps, steps8, sizeof steps8);
    }
    else if (digitalRead(A1) == HIGH)
    {
      channel = 9;
      memcpy(steps, steps9, sizeof steps9);
    }
    else if (digitalRead(A2) == HIGH)
    {
      channel = 10;
      memcpy(steps, steps10, sizeof steps10);
    }
    else if (digitalRead(A3) == HIGH)
    {
      channel = 11;
      memcpy(steps, steps11, sizeof steps11);
    }
    else if (digitalRead(A4) == HIGH)
    {
      channel = 12;
      memcpy(steps, steps12, sizeof steps12);
    }
    else if (digitalRead(A5) == HIGH)
    {
      channel = 13;
      memcpy(steps, steps13, sizeof steps13);
    }
    else if (digitalRead(A6) == HIGH)
    {
      channel = 14;
      memcpy(steps, steps14, sizeof steps14);
    }
    else if (digitalRead(A7) == HIGH)
    {
      channel = 15;
      memcpy(steps, steps15, sizeof steps15);
    }
  }
}

void updateChannelData()
{
  if (channel == 0)
  {
    memcpy(steps0, steps, sizeof steps);
  }
  else if (channel == 1)
  {
    memcpy(steps1, steps, sizeof steps);
  }
  else if (channel == 2)
  {
    memcpy(steps2, steps, sizeof steps);
  }
  else if (channel == 3)
  {
    memcpy(steps3, steps, sizeof steps);
  }
  else if (channel == 4)
  {
    memcpy(steps4, steps, sizeof steps);
  }
  else if (channel == 5)
  {
    memcpy(steps5, steps, sizeof steps);
  }
  else if (channel == 6)
  {
    memcpy(steps6, steps, sizeof steps);
  }
  else if (channel == 7)
  {
    memcpy(steps7, steps, sizeof steps);
  }
  else if (channel == 8)
  {
    memcpy(steps8, steps, sizeof steps);
  }
  else if (channel == 9)
  {
    memcpy(steps9, steps, sizeof steps);
  }
  else if (channel == 10)
  {
    memcpy(steps10, steps, sizeof steps);
  }
  else if (channel == 11)
  {
    memcpy(steps11, steps, sizeof steps);
  }
  else if (channel == 12)
  {
    memcpy(steps12, steps, sizeof steps);
  }
  else if (channel == 13)
  {
    memcpy(steps13, steps, sizeof steps);
  }
  else if (channel == 14)
  {
    memcpy(steps14, steps, sizeof steps);
  }
  else if (channel == 15)
  {
    memcpy(steps15, steps, sizeof steps);
  }
}

//START STOP
void startStop()
{
  if (digitalRead(startStopButton) == HIGH)
  {
    if (startStopClicked == false)
    {
      startStopClicked = true;
      Serial.println("FUCK");
      run = !run;
      turnOffLEDs();
      currentStep = maxStep;
      count = maxCount;
    }
  }

  else if (digitalRead(startStopButton) == LOW)
  {
    if (startStopClicked == true)
    {
      Serial.println("YOU");
      startStopClicked = false;
    }
  }
}

//LEDs
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

//SEQUENCER
void runSeq()
{
  if (count >= maxCount)
  {
    count = 0;
    alignSteps();
    if (currentStep < maxStep)
    {
      currentStep++;
    }
    else
    {
      currentStep = 0;
    }
    decodeStep();
  }
  else
  {
    count++;
    if (steps[currentRow][currentCol] == true)
    {
      //LEDs
      lights[currentRow][currentCol] = HIGH;
    }
    else
    {
      lights[currentRow][currentCol] = LOW;
    }
    sendTriggers();
  }
}

//////////////////////SUBROUTINES////////////////////

void turnOffLEDs()
{
  for (int thisRow = 0; thisRow < 4; thisRow++)
  {
    digitalWrite(row[thisRow], LOW);
  }
}

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

//This subroutine checks for and sends the correct trigger signals
void sendTriggers()
{
  //Step 0
  if (steps0[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut0, HIGH);
    }
    else
    {
      digitalWrite(triggerOut0, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut0, LOW);
  }

  //Step 1
  if (steps1[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut1, HIGH);
    }
    else
    {
      digitalWrite(triggerOut1, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut1, LOW);
  }

  //Step 2
  if (steps2[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut2, HIGH);
    }
    else
    {
      digitalWrite(triggerOut2, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut2, LOW);
  }

  //Step 3
  if (steps3[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut3, HIGH);
    }
    else
    {
      digitalWrite(triggerOut3, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut3, LOW);
  }

  //Step 4
  if (steps4[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut4, HIGH);
    }
    else
    {
      digitalWrite(triggerOut4, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut4, LOW);
  }

  //Step 5
  if (steps5[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut5, HIGH);
    }
    else
    {
      digitalWrite(triggerOut5, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut5, LOW);
  }

  //Step 6
  if (steps6[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut6, HIGH);
    }
    else
    {
      digitalWrite(triggerOut6, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut6, LOW);
  }

  //Step 7
  if (steps7[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut7, HIGH);
    }
    else
    {
      digitalWrite(triggerOut7, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut7, LOW);
  }

  //Step 8
  if (steps8[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut8, HIGH);
    }
    else
    {
      digitalWrite(triggerOut8, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut8, LOW);
  }

  //Step 9
  if (steps9[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut9, HIGH);
    }
    else
    {
      digitalWrite(triggerOut9, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut9, LOW);
  }

  //Step 10
  if (steps10[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut10, HIGH);
    }
    else
    {
      digitalWrite(triggerOut10, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut10, LOW);
  }

  //Step 11
  if (steps11[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut11, HIGH);
    }
    else
    {
      digitalWrite(triggerOut11, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut11, LOW);
  }

  //Step 12
  if (steps12[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut12, HIGH);
    }
    else
    {
      digitalWrite(triggerOut12, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut12, LOW);
  }

  //Step 13
  if (steps13[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut13, HIGH);
    }
    else
    {
      digitalWrite(triggerOut13, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut13, LOW);
  }

  //Step 14
  if (steps14[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut14, HIGH);
    }
    else
    {
      digitalWrite(triggerOut14, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut14, LOW);
  }

  //Step 15
  if (steps15[currentRow][currentCol] == true)
  {
    //Triggers
    if (count < trigCount)
    {
      digitalWrite(triggerOut15, HIGH);
    }
    else
    {
      digitalWrite(triggerOut15, LOW);
    }
  }
  else
  {
    digitalWrite(triggerOut15, LOW);
  }
}


