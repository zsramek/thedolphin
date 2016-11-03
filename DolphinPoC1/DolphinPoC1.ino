//Dolphin Proof of Concept
//Zefan Sramek
//ZRcubed
//Oct. 2016

//Pins
const int startStop = 52;
const int triggerOut = 53;

//currentStep Booleans
boolean S0 = false;
boolean S1 = false;
boolean S2 = false;
boolean S3 = false;
boolean S4 = false;
boolean S5 = false;
boolean S6 = false;
boolean S7 = false;
boolean currentSteps[8] = {
  S0, S1, S2, S3, S4, S5, S6, S7};

boolean runClicked = false;
boolean clicked0 = false;
boolean clicked1 = false;
boolean clicked2 = false;
boolean clicked3 = false;
boolean clicked4 = false;
boolean clicked5 = false;
boolean clicked6 = false;
boolean clicked7 = false;

//Run/Stop Boolean
boolean run = false;

//Current currentStep
int currentStep = 0;

//Delay Counter & Max
int count = 0;
const int maxCount = 1000; //16MHz clock -> 16 Million

void setup()
{
  //Start/Stop Button
  pinMode(52, INPUT);

  //Trigger Output
  pinMode(53, OUTPUT);

  //Inputs for currentStep buttons
  pinMode(23, INPUT);
  pinMode(25, INPUT);
  pinMode(27, INPUT);
  pinMode(29, INPUT);
  pinMode(31, INPUT);
  pinMode(33, INPUT);
  pinMode(35, INPUT);
  pinMode(37, INPUT);

  //Outputs for currentStep LEDs
  pinMode(22, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(36, OUTPUT);

  digitalWrite(22, LOW);
  digitalWrite(24, LOW);
  digitalWrite(26, LOW);
  digitalWrite(28, LOW);
  digitalWrite(30, LOW);
  digitalWrite(32, LOW);
  digitalWrite(34, LOW);
  digitalWrite(36, LOW);

  run = false;

  //For debugging
  Serial.begin(9600);
}

void loop()
{
  //What pin are we writing to or reading from?
  int pin = 0;

  //Check for button clicks
  pollButtons();

  //Debugging:
  //  Serial.print("step: ");
  //  Serial.println(currentStep);
  //  Serial.print("run ");
  //  Serial.println(run);
  //  Serial.print("count: ");
  //  Serial.println(count);

  //Set the LEDs based on the status of the currentStep
  setLEDs();

  //Reset the trigger output to low
  digitalWrite(triggerOut, LOW);

  //Check whether we should start or stop running
  runOrStop();

  //Do we run?
  run();

}

//This functions polls all buttons to see if they're being pressed
void pollButtons()
{  
  if (digitalRead(23) == HIGH && clicked0 == false)
  {
    currentSteps[0] = !currentSteps[0];
    clicked0 = true;
  }
  else if (digitalRead(23) == LOW && clicked0 == true)
  {
    clicked0 = false;
  }

  if (digitalRead(25) == HIGH && clicked1 == false)
  {
    currentSteps[1] = !currentSteps[1];
    clicked1 = true;
  }
  else if (digitalRead(25) == LOW && clicked1 == true)
  {
    clicked1 = false;
  }

  if (digitalRead(27) == HIGH && clicked2 == false)
  {
    currentSteps[2] = !currentSteps[2];
    clicked2 = true;
  }
  else if (digitalRead(27) == LOW && clicked2 == true)
  {
    clicked2 = false;
  }

  if (digitalRead(29) == HIGH && clicked3 == false)
  {
    currentSteps[3] = !currentSteps[3];
    clicked3 = true;
  }
  else if (digitalRead(29) == LOW && clicked3 == true)
  {
    clicked3 = false;
  }

  if (digitalRead(31) == HIGH && clicked4 == false)
  {
    currentSteps[4] = !currentSteps[4];
    clicked4 = true;
  }
  else if (digitalRead(31) == LOW && clicked4 == true)
  {
    clicked4 = false;
  }

  if (digitalRead(33) == HIGH && clicked5 == false)
  {
    currentSteps[5] = !currentSteps[5];
    clicked5 = true;
  }
  else if (digitalRead(33) == LOW && clicked5 == true)
  {
    clicked5 = false;
  }

  if (digitalRead(35) == HIGH && clicked6 == false)
  {
    currentSteps[6] = !currentSteps[6];
    clicked6 = true;
  }
  else if (digitalRead(35) == LOW && clicked6 == true)
  {
    clicked6 = false;
  }

  if (digitalRead(37) == HIGH && clicked7 == false)
  {
    currentSteps[7] = !currentSteps[7];
    clicked7 = true;
  }
  else if (digitalRead(37) == HIGH && clicked7 == true)
  {
    clicked7 = false;
  }
}

//This function updates all the LED states based on their associated booleans
void setLEDs()
{
  for (int i = 0; i < 7; i++)
  {
    pin = i * 2 + 22; 
    if (currentSteps[i] == true)
    {
      digitalWrite(pin, HIGH);
    }
    else
    {
      digitalWrite(pin, LOW);
    }
  }
}

//This function checks the polls the run/stop button and updates the run status accordingly
void runOrStop()
{
  if (digitalRead(startStop) == HIGH && runClicked == false)
  {
    run = !run;
    runClicked = true;
  }
  else if (digitalRead(startStop) == LOW && runClicked == true)
  {
    runClicked = false;
    count = 0;
    currentStep = 0;
  }
}


void run()
{
  if (run)
  {
    if (count >= maxCount)
    {
      count = 0;
      //Go to the next currentStep
      if (currentStep < 7)
      {
        currentStep++;
      }
      else
      {
        currentStep = 0;
      }
    }
    else
    {
      count++;

      //Set the output based on the currentStep's value
      //Flip the LED for the current currentStep
      pin = currentStep * 2 + 22;
      if (currentSteps[currentStep] == true)
      {
        if (count < maxCount / 2)
        {
          digitalWrite(triggerOut, HIGH);
        }
        else
        {
          digitalWrite(triggerOut, LOW);
        }
        digitalWrite(pin, LOW);
      }
      else
      {
        digitalWrite(triggerOut, LOW);
        digitalWrite(pin, HIGH);
      }
    } 
  }
}


