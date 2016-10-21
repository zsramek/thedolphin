//Dolphin Proof of Concept
//Zefan Sramek
//ZRcubed
//Oct. 2016

//Pins
const int startStop = 52;
const int triggerOut = 53;

//Step Booleans
boolean S0 = false;
boolean S1 = false;
boolean S2 = false;
boolean S3 = false;
boolean S4 = false;
boolean S5 = false;
boolean S6 = false;
boolean S7 = false;
boolean steps[8] = {S0, S1, S2, S3, S4, S5, S6, S7};

//Run/Stop Boolean
boolean run = false;

//Current Step
int step = 0;

//Delay Counter & Max
int count = 0;
const int maxCount = 800000; //16MHz clock -> 16 Million

void setup()
{
  //Start/Stop Button
  pinMode(52, INPUT);

  //Trigger Output
  pinMode(53, OUTPUT);
  
  //Inputs for step buttons
  pinMode(23, INPUT);
  pinMode(25, INPUT);
  pinMode(27, INPUT);
  pinMode(29, INPUT);
  pinMode(31, INPUT);
  pinMode(33, INPUT);
  pinMode(35, INPUT);
  pinMode(37, INPUT);
  
  //Outputs for step LEDs
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
  
  Serial.begin(9600);
}

void loop()
{
  //What pin are we writing to or reading from?
  int pin = 0;
  
  //Check for button clicks
  if (digitalRead(23) == HIGH)
  {
    steps[0] = !steps[0];
  }
  if (digitalRead(25) == HIGH)
  {
    steps[1] = !steps[1];
  }
  if (digitalRead(27) == HIGH)
  {
    steps[2] = !steps[2];
  }
  if (digitalRead(29) == HIGH)
  {
    steps[3] = !steps[3];
  }
  if (digitalRead(31) == HIGH)
  {
    steps[4] = !steps[4];
  }
  if (digitalRead(33) == HIGH)
  {
    steps[5] = !steps[5];
  }
  if (digitalRead(35) == HIGH)
  {
    steps[6] = !steps[6];
  }
  if (digitalRead(37) == HIGH)
  {
    steps[7] = !steps[7];
  }
  
  Serial.println(run);
  
//  //Set the LEDs based on the status of the step
//   for (int i = 0; i < 7; i++)
//   {
//     pin = i * 2 + 22; 
//     if (steps[i] == true)
//     {
//       digitalWrite(pin, HIGH);
//     }
//     else
//     {
//       digitalWrite(pin, LOW);
//     }
//   }
  
  //Check whether we should start or stop running
  if (digitalRead(startStop) == HIGH)
  {
    run = !run;
  }
  
  if (run)
  {
    if (count >= maxCount)
    {
      count = 0;
      //Go to the next step
      if (step < 7)
      {
        step++;
      }
      else
      {
        step = 0;
      }
      
      //Set the output based on the step's value
      //Flip the LED for the current step
      pin = step * 2 + 22;
      if (steps[step] == true)
      {
        digitalWrite(triggerOut, HIGH);
        digitalWrite(pin, LOW);
      }
      else
      {
        digitalWrite(triggerOut, LOW);
        digitalWrite(pin, HIGH);
      }
      
    }
    else
    {
      count++;
    }
    
  }
//  else
//  {
    //  //Set the LEDs based on the status of the step
//   for (int i = 0; i < 7; i++)
//   {
//     if (i != step)
//     {
//       pin = i * 2 + 22; 
//       if (steps[i] == true)
//       {
//         digitalWrite(pin, HIGH);
//       }
//       else
//       {
//         digitalWrite(pin, LOW);
//       }
//     }
//   }
//  }
}


