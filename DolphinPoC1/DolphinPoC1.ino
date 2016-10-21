//Dolphin Proof of Concept
//Zefan Sramek
//ZRcubed
//Oct. 2016

//Step Booleans
boolean S0 = false;
boolean S1 = false;
boolean S2 = false;
boolean S3 = false;
boolean S4 = false;
boolean S5 = false;
boolean S6 = false;
boolean S7 = false;
boolean[8] steps = [S0, S1, S2, S3, S4, S5, S6, S7];

//Run/Stop Boolean
boolean run = false;

void setup()
{
  //Start/Stop Button
  pinMode(52, INPUT)

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
}

void loop()
{
  
  if (run)
  {
  }
  else
  {
    
  }
  
}


