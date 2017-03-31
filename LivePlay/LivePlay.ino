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

//Live-Play Pins
int livePlayIn0 = 0;
int livePlayIn1 = 1;
int livePlayIn2 = 2;
int livePlayIn3 = 3;
int livePlayOut0 = 4;
int livePlayOut1 = 5;
int livePlayOut2 = 6;
int livePlayOut3 = 7;

boolean livePlayClicked0 = false;
boolean livePlayClicked1 = false;
boolean livePlayClicked2 = false;
boolean livePlayClicked3 = false;
boolean livePlayClicked4 = false;
boolean livePlayClicked5 = false;
boolean livePlayClicked6 = false;
boolean livePlayClicked7 = false;
boolean livePlayClicked8 = false;
boolean livePlayClicked9 = false;
boolean livePlayClicked10 = false;
boolean livePlayClicked11 = false;
boolean livePlayClicked12 = false;
boolean livePlayClicked13 = false;
boolean livePlayClicked14 = false;
boolean livePlayClicked15 = false;

int livePlayCount0 = 0;
int livePlayCount1 = 0;
int livePlayCount2 = 0;
int livePlayCount3 = 0;
int livePlayCount4 = 0;
int livePlayCount5 = 0;
int livePlayCount6 = 0;
int livePlayCount7 = 0;
int livePlayCount8 = 0;
int livePlayCount9 = 0;
int livePlayCount10 = 0;
int livePlayCount11 = 0;
int livePlayCount12 = 0;
int livePlayCount13 = 0;
int livePlayCount14 = 0;
int livePlayCount15 = 0;

boolean livePlayCounting0 = false;
boolean livePlayCounting1 = false;
boolean livePlayCounting2 = false;
boolean livePlayCounting3 = false;
boolean livePlayCounting4 = false;
boolean livePlayCounting5 = false;
boolean livePlayCounting6 = false;
boolean livePlayCounting7 = false;
boolean livePlayCounting8 = false;
boolean livePlayCounting9 = false;
boolean livePlayCounting10 = false;
boolean livePlayCounting11 = false;
boolean livePlayCounting12 = false;
boolean livePlayCounting13 = false;
boolean livePlayCounting14 = false;
boolean livePlayCounting15 = false;

int livePlayMax = 50;

int livePlayRow = 1;

int button = 0;

void setup()
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

  pinMode(livePlayIn0, INPUT);
  pinMode(livePlayIn1, INPUT);
  pinMode(livePlayIn2, INPUT);
  pinMode(livePlayIn3, INPUT);
  pinMode(livePlayOut0, OUTPUT);
  pinMode(livePlayOut1, OUTPUT);
  pinMode(livePlayOut2, OUTPUT);
  pinMode(livePlayOut3, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  scanButtons();
  Serial.println(button);
}

void scanButtons()
{
  //~~~~~~~~~~~~~~1~~~~~~~~~~~~~~~
  if (livePlayRow == 1)
  {
    digitalWrite(livePlayOut0, HIGH);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut2, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount0 == 0)
    {
      livePlayCounting0 = true;
    }
    if (livePlayCounting0 == true)
    {
      if (livePlayCount0 < livePlayMax)
      {
      livePlayCount0++;
      }
      else
      {
        livePlayCount0 = 0;
        livePlayCounting0 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount0 >= livePlayMax)
    {
      if (livePlayClicked0 == false)
      {
        button = 1;
        //steps[0][0] = !//steps[0][0];
        livePlayClicked0 = true;
        livePlayCounting0 = false;
        livePlayCount0 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked0 == true)
      {
        livePlayClicked0 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount1 == 0)
    {
      livePlayCounting1 = true;
    }
    if (livePlayCounting1 == true)
    {
      if (livePlayCount1 < livePlayMax)
      {
      livePlayCount1++;
      }
      else
      {
        livePlayCount1 = 0;
        livePlayCounting1 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount1 >= livePlayMax)
    {
      if (livePlayClicked1 == false)
      {
        button = 2;
        //steps[0][0] = !//steps[0][0];
        livePlayClicked1 = true;
        livePlayCounting1 = false;
        livePlayCount1 = 0;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked1 == true)
      {
        livePlayClicked1 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount2 == 0)
    {
      livePlayCounting2 = true;
    }
    if (livePlayCounting2 == true)
    {
      if (livePlayCount2 < livePlayMax)
      {
      livePlayCount2++;
      }
      else
      {
        livePlayCount2 = 0;
        livePlayCounting2 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount2 >= livePlayMax)
    {
      if (livePlayClicked2 == false)
      {
        button = 3;
        //steps[0][0] = !//steps[0][0];
        livePlayClicked2 = true;
        livePlayCounting2 = false;
        livePlayCount2 = 0;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked2 == true)
      {
        livePlayClicked2 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH)
    {
      if (livePlayClicked3 == false)
      {
        button = 4;
        //steps[0][3] = !//steps[0][3];
        livePlayClicked3 = true;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked3 == true)
      {
        livePlayClicked3 = false;
      }
    }

    livePlayRow = 2; //Must come after
  }

  //~~~~~~~~~~~~~~2~~~~~~~~~~~~~~~
  else if (livePlayRow == 2)
  {
    digitalWrite(livePlayOut1, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut2, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH)
    {
      if (livePlayClicked4 == false)
      {
        button = 5;
        //steps[1][0] = !//steps[1][0];
        livePlayClicked4 = true;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked4 == true)
      {
        livePlayClicked4 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn1) == HIGH)
    {
      if (livePlayClicked5 == false)
      {
        button = 6;
        //steps[1][1] = !//steps[1][1];
        livePlayClicked5 = true;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked5 == true)
      {
        livePlayClicked5 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH)
    {
      if (livePlayClicked6 == false)
      {
        button = 7;
        //steps[1][2] = !//steps[1][2];
        livePlayClicked6 = true;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked6 == true)
      {
        livePlayClicked6 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH)
    {
      if (livePlayClicked7 == false)
      {
        button = 8;
        //steps[1][3] = !//steps[1][3];
        livePlayClicked7 = true;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked7 == true)
      {
        livePlayClicked7 = false;
      }
    }
    livePlayRow = 3;
  }

  //~~~~~~~~~~~~~~3~~~~~~~~~~~~~~~
  if (livePlayRow == 3)
  {
    digitalWrite(livePlayOut2, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH)
    {
      if (livePlayClicked8 == false)
      {
        button = 9;
        //steps[2][0] = !//steps[2][0];
        livePlayClicked8 = true;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked8 == true)
      {
        livePlayClicked8 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH)
    {
      if (livePlayClicked9 == false)
      {
        button = 10;
        //steps[2][1] = !//steps[2][1];
        livePlayClicked9 = true;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked9 == true)
      {
        livePlayClicked9 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH)
    {
      if (livePlayClicked10 == false)
      {
        button = 11;
        //steps[2][2] = !//steps[2][2];
        livePlayClicked10 = true;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked10 == true)
      {
        livePlayClicked10 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH)
    {
      if (livePlayClicked11 == false)
      {
        button = 12;
        //steps[2][3] = !//steps[2][3];
        livePlayClicked11 = true;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked11 == true)
      {
        livePlayClicked11 = false;
      }
    }
    livePlayRow = 4;
  }

  //~~~~~~~~~~~~~~4~~~~~~~~~~~~~~~
  if (livePlayRow == 4)
  {
    digitalWrite(livePlayOut3, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut2, LOW);

    if (digitalRead(livePlayIn0) == HIGH)
    {
      if (livePlayClicked12 == false)
      {
        button = 13;
        //steps[3][0] = !//steps[3][0];
        livePlayClicked12 = true;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked12 == true)
      {
        livePlayClicked12 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH)
    {
      if (livePlayClicked13 == false)
      {
        button = 14;
        //steps[3][1] = !//steps[3][1];
        livePlayClicked13 = true;
      }
    }
    else if (digitalRead(livePlayIn1) == LOW)
    {
      if (livePlayClicked13 == true)
      {
        livePlayClicked13 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn2) == HIGH)
    {
      if (livePlayClicked14 == false)
      {
        button = 15;
        //steps[3][2] = !//steps[3][2];
        livePlayClicked14 = true;
      }
    }
    else if (digitalRead(livePlayIn2) == LOW)
    {
      if (livePlayClicked14 == true)
      {
        livePlayClicked14 = false;
      }
    }

    //~~~

    if (digitalRead(livePlayIn3) == HIGH)
    {
      if (livePlayClicked15 == false)
      {
        button = 16;
        //steps[3][3] = !//steps[3][3];
        livePlayClicked15 = true;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked15 == true)
      {
        livePlayClicked15 = false;
      }
    }
    livePlayRow = 1;
  }
}
