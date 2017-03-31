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
int livePlayIn0 = 14;
int livePlayIn1 = 15;
int livePlayIn2 = 16;
int livePlayIn3 = 17;
int livePlayOut0 = 9;
int livePlayOut1 = 10;
int livePlayOut2 = 11;
int livePlayOut3 = 12;

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

boolean trigger0 = false;
boolean trigger1 = false;
boolean trigger2 = false;
boolean trigger3 = false;
boolean trigger4 = false;
boolean trigger5 = false;
boolean trigger6 = false;
boolean trigger7 = false;
boolean trigger8 = false;
boolean trigger9 = false;
boolean trigger10 = false;
boolean trigger11 = false;
boolean trigger12 = false;
boolean trigger13 = false;
boolean trigger14 = false;
boolean trigger15 = false;

int liveTrigCount0 = 0;
int liveTrigCount1 = 0;
int liveTrigCount2 = 0;
int liveTrigCount3 = 0;
int liveTrigCount4 = 0;
int liveTrigCount5 = 0;
int liveTrigCount6 = 0;
int liveTrigCount7 = 0;
int liveTrigCount8 = 0;
int liveTrigCount9 = 0;
int liveTrigCount10 = 0;
int liveTrigCount11 = 0;
int liveTrigCount12 = 0;
int liveTrigCount13 = 0;
int liveTrigCount14 = 0;
int liveTrigCount15 = 0;

int trigCount = 20;
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
  liveTrigger();
}

void scanButtons()
{
  //~~~~~~~~~~~~~~1~~~~~~~~~~~~~~~
  if (livePlayRow == 1)
  {
    //Serial.println("Row1");
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
        button = 15;
        Serial.println("15");
        trigger14 = true;
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
        button = 13;
        Serial.println("13");
        trigger12 = true;
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
        button = 11;
        Serial.println("11");
        trigger10 = true;
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

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount3 == 0)
    {
      livePlayCounting3 = true;
    }
    if (livePlayCounting3 == true)
    {
      if (livePlayCount3 < livePlayMax)
      {
        livePlayCount3++;
      }
      else
      {
        livePlayCount3 = 0;
        livePlayCounting3 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount3 >= livePlayMax)
    {
      if (livePlayClicked3 == false)
      {
        button = 9;
        Serial.println("9");
        trigger8 = true;
        livePlayClicked3 = true;
        livePlayCounting3 = false;
        livePlayCount3 = 0;
      }
    }
    else if (digitalRead(livePlayIn3) == LOW)
    {
      if (livePlayClicked3 == true)
      {
        livePlayClicked3 = false;
      }
    }
    livePlayRow = 2;
  }
  //~~~~~~~~~~~~~~2~~~~~~~~~~~~~~~
  if (livePlayRow == 2)
  {
    //Serial.println("Row2");
    digitalWrite(livePlayOut1, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut2, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount4 == 0)
    {
      livePlayCounting4 = true;
    }
    if (livePlayCounting4 == true)
    {
      if (livePlayCount4 < livePlayMax)
      {
        livePlayCount4++;
      }
      else
      {
        livePlayCount4 = 0;
        livePlayCounting4 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount4 >= livePlayMax)
    {
      if (livePlayClicked4 == false)
      {
        button = 7;
        Serial.println("7");
        trigger6 = true;
        livePlayClicked4 = true;
        livePlayCounting4 = false;
        livePlayCount4 = 0;
      }
    }
    else if (digitalRead(livePlayIn0) == LOW)
    {
      if (livePlayClicked4 == true)
      {
        livePlayClicked4 = false;
      }
    }

    //~~~~

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount5 == 0)
    {
      livePlayCounting5 = true;
    }
    if (livePlayCounting5 == true)
    {
      if (livePlayCount5 < livePlayMax)
      {
        livePlayCount5++;
      }
      else
      {
        livePlayCount5 = 0;
        livePlayCounting5 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount5 >= livePlayMax)
    {
      if (livePlayClicked5 == false)
      {
        button = 5;
        Serial.println("5");
        trigger4 = true;
        livePlayClicked5 = true;
        livePlayCounting5 = false;
        livePlayCount5 = 0;
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

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount6 == 0)
    {
      livePlayCounting6 = true;
    }
    if (livePlayCounting6 == true)
    {
      if (livePlayCount6 < livePlayMax)
      {
        livePlayCount6++;
      }
      else
      {
        livePlayCount6 = 0;
        livePlayCounting6 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount6 >= livePlayMax)
    {
      if (livePlayClicked6 == false)
      {
        button = 3;
        Serial.println("3");
        trigger2 = true;
        livePlayClicked6 = true;
        livePlayCounting6 = false;
        livePlayCount6 = 0;
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

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount7 == 0)
    {
      livePlayCounting7 = true;
    }
    if (livePlayCounting7 == true)
    {
      if (livePlayCount7 < livePlayMax)
      {
        livePlayCount7++;
      }
      else
      {
        livePlayCount7 = 0;
        livePlayCounting7 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount7 >= livePlayMax)
    {
      if (livePlayClicked7 == false)
      {
        button = 1;
        Serial.println("1");
        trigger0 = true;
        livePlayClicked7 = true;
        livePlayCounting7 = false;
        livePlayCount7 = 0;
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
    //Serial.println("Row3");
    digitalWrite(livePlayOut2, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut3, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount8 == 0)
    {
      livePlayCounting8 = true;
    }
    if (livePlayCounting8 == true)
    {
      if (livePlayCount8 < livePlayMax)
      {
        livePlayCount8++;
      }
      else
      {
        livePlayCount8 = 0;
        livePlayCounting8 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount8 >= livePlayMax)
    {
      if (livePlayClicked8 == false)
      {
        button = 16;
        Serial.println("16");
        trigger15 = true;
        livePlayClicked8 = true;
        livePlayCounting8 = false;
        livePlayCount8 = 0;
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

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount9 == 0)
    {
      livePlayCounting9 = true;
    }
    if (livePlayCounting9 == true)
    {
      if (livePlayCount9 < livePlayMax)
      {
        livePlayCount9++;
      }
      else
      {
        livePlayCount9 = 0;
        livePlayCounting9 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount9 >= livePlayMax)
    {
      if (livePlayClicked9 == false)
      {
        button = 14;
        Serial.println("14");
        trigger13 = true;
        livePlayClicked9 = true;
        livePlayCounting9 = false;
        livePlayCount9 = 0;
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

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount10 == 0)
    {
      livePlayCounting10 = true;
    }
    if (livePlayCounting10 == true)
    {
      if (livePlayCount10 < livePlayMax)
      {
        livePlayCount10++;
      }
      else
      {
        livePlayCount10 = 0;
        livePlayCounting10 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount10 >= livePlayMax)
    {
      if (livePlayClicked10 == false)
      {
        button = 12;
        Serial.println("12");
        trigger11 = true;
        livePlayClicked10 = true;
        livePlayCounting10 = false;
        livePlayCount10 = 0;
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

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount11 == 0)
    {
      livePlayCounting11 = true;
    }
    if (livePlayCounting11 == true)
    {
      if (livePlayCount11 < livePlayMax)
      {
        livePlayCount11++;
      }
      else
      {
        livePlayCount11 = 0;
        livePlayCounting11 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount11 >= livePlayMax)
    {
      if (livePlayClicked11 == false)
      {
        button = 10;
        Serial.println("10");
        trigger9 = true;
        livePlayClicked11 = true;
        livePlayCounting11 = false;
        livePlayCount11 = 0;
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
    //Serial.println("Row4");
    digitalWrite(livePlayOut3, HIGH);
    digitalWrite(livePlayOut0, LOW);
    digitalWrite(livePlayOut1, LOW);
    digitalWrite(livePlayOut2, LOW);

    if (digitalRead(livePlayIn0) == HIGH && livePlayCount12 == 0)
    {
      livePlayCounting12 = true;
    }
    if (livePlayCounting12 == true)
    {
      if (livePlayCount12 < livePlayMax)
      {
        livePlayCount12++;
      }
      else
      {
        livePlayCount12 = 0;
        livePlayCounting12 = false;
      }
    }
    if (digitalRead(livePlayIn0) == HIGH && livePlayCount12 >= livePlayMax)
    {
      if (livePlayClicked12 == false)
      {
        button = 8;
        Serial.println("8");
        trigger7 = true;
        livePlayClicked12 = true;
        livePlayCounting12 = false;
        livePlayCount12 = 0;
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

    if (digitalRead(livePlayIn1) == HIGH && livePlayCount13 == 0)
    {
      livePlayCounting13 = true;
    }
    if (livePlayCounting13 == true)
    {
      if (livePlayCount13 < livePlayMax)
      {
        livePlayCount13++;
      }
      else
      {
        livePlayCount13 = 0;
        livePlayCounting13 = false;
      }
    }
    if (digitalRead(livePlayIn1) == HIGH && livePlayCount13 >= livePlayMax)
    {
      if (livePlayClicked13 == false)
      {
        button = 6;
        Serial.println("6");
        trigger5 = true;
        livePlayClicked13 = true;
        livePlayCounting13 = false;
        livePlayCount13 = 0;
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

    if (digitalRead(livePlayIn2) == HIGH && livePlayCount14 == 0)
    {
      livePlayCounting14 = true;
    }
    if (livePlayCounting14 == true)
    {
      if (livePlayCount14 < livePlayMax)
      {
        livePlayCount14++;
      }
      else
      {
        livePlayCount14 = 0;
        livePlayCounting14 = false;
      }
    }
    if (digitalRead(livePlayIn2) == HIGH && livePlayCount14 >= livePlayMax)
    {
      if (livePlayClicked14 == false)
      {
        button = 4;
        Serial.println("4");
        trigger3 = true;
        livePlayClicked14 = true;
        livePlayCounting14 = false;
        livePlayCount14 = 0;
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

    if (digitalRead(livePlayIn3) == HIGH && livePlayCount15 == 0)
    {
      livePlayCounting15 = true;
    }
    if (livePlayCounting15 == true)
    {
      if (livePlayCount15 < livePlayMax)
      {
        livePlayCount15++;
      }
      else
      {
        livePlayCount15 = 0;
        livePlayCounting15 = false;
      }
    }
    if (digitalRead(livePlayIn3) == HIGH && livePlayCount15 >= livePlayMax)
    {
      if (livePlayClicked15 == false)
      {
        button = 2;
        Serial.println("2");
        trigger1 = true;
        livePlayClicked15 = true;
        livePlayCounting15 = false;
        livePlayCount15 = 0;
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

void liveTrigger()
{
  if (trigger0 == true)
  {
    //Triggers
    if (liveTrigCount0 < trigCount)
    {
      digitalWrite(triggerOut0, HIGH);
      liveTrigCount0++;
    }
    else
    {
      digitalWrite(triggerOut0, LOW);
      liveTrigCount0 = 0;
      trigger0 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut0, LOW);
    liveTrigCount0 = 0;
  }

  //~~~

  if (trigger1 == true)
  {
    //Triggers
    if (liveTrigCount1 < trigCount)
    {
      digitalWrite(triggerOut1, HIGH);
      liveTrigCount1++;
    }
    else
    {
      digitalWrite(triggerOut1, LOW);
      liveTrigCount1 = 0;
      trigger1 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut1, LOW);
    liveTrigCount1 = 0;
  }

  //~~~

  if (trigger2 == true)
  {
    //Triggers
    if (liveTrigCount2 < trigCount)
    {
      digitalWrite(triggerOut2, HIGH);
      liveTrigCount2++;
    }
    else
    {
      digitalWrite(triggerOut2, LOW);
      liveTrigCount2 = 0;
      trigger2 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut2, LOW);
    liveTrigCount2 = 0;
  }

  //~~~

  if (trigger3 == true)
  {
    //Triggers
    if (liveTrigCount3 < trigCount)
    {
      digitalWrite(triggerOut3, HIGH);
      liveTrigCount3++;
    }
    else
    {
      digitalWrite(triggerOut3, LOW);
      liveTrigCount3 = 0;
      trigger3 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut3, LOW);
    liveTrigCount3 = 0;
  }

  //~~~

  if (trigger4 == true)
  {
    //Triggers
    if (liveTrigCount4 < trigCount)
    {
      digitalWrite(triggerOut4, HIGH);
      liveTrigCount4++;
    }
    else
    {
      digitalWrite(triggerOut4, LOW);
      liveTrigCount4 = 0;
      trigger4 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut4, LOW);
    liveTrigCount4 = 0;
  }

  //~~~

  if (trigger5 == true)
  {
    //Triggers
    if (liveTrigCount5 < trigCount)
    {
      digitalWrite(triggerOut5, HIGH);
      liveTrigCount5++;
    }
    else
    {
      digitalWrite(triggerOut5, LOW);
      liveTrigCount5 = 0;
      trigger5 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut5, LOW);
    liveTrigCount5 = 0;
  }

  //~~~

  if (trigger6 == true)
  {
    //Triggers
    if (liveTrigCount6 < trigCount)
    {
      digitalWrite(triggerOut6, HIGH);
      liveTrigCount6++;
    }
    else
    {
      digitalWrite(triggerOut6, LOW);
      liveTrigCount6 = 0;
      trigger6 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut6, LOW);
    liveTrigCount6 = 0;
  }

  //~~~

  if (trigger7 == true)
  {
    //Triggers
    if (liveTrigCount7 < trigCount)
    {
      digitalWrite(triggerOut7, HIGH);
      liveTrigCount7++;
    }
    else
    {
      digitalWrite(triggerOut7, LOW);
      liveTrigCount7 = 0;
      trigger7 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut7, LOW);
    liveTrigCount7 = 0;
  }

  //~~~

  if (trigger8 == true)
  {
    //Triggers
    if (liveTrigCount8 < trigCount)
    {
      digitalWrite(triggerOut8, HIGH);
      liveTrigCount8++;
    }
    else
    {
      digitalWrite(triggerOut8, LOW);
      liveTrigCount8 = 0;
      trigger8 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut8, LOW);
    liveTrigCount8 = 0;
  }

  //~~~

  if (trigger9 == true)
  {
    //Triggers
    if (liveTrigCount9 < trigCount)
    {
      digitalWrite(triggerOut9, HIGH);
      liveTrigCount9++;
    }
    else
    {
      digitalWrite(triggerOut9, LOW);
      liveTrigCount9 = 0;
      trigger9 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut9, LOW);
    liveTrigCount9 = 0;
  }

  //~~~

  if (trigger10 == true)
  {
    //Triggers
    if (liveTrigCount10 < trigCount)
    {
      digitalWrite(triggerOut10, HIGH);
      liveTrigCount10++;
    }
    else
    {
      digitalWrite(triggerOut10, LOW);
      liveTrigCount10 = 0;
      trigger10 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut10, LOW);
    liveTrigCount10 = 0;
  }

  //~~~

  if (trigger11 == true)
  {
    //Triggers
    if (liveTrigCount11 < trigCount)
    {
      digitalWrite(triggerOut11, HIGH);
      liveTrigCount11++;
    }
    else
    {
      digitalWrite(triggerOut11, LOW);
      liveTrigCount11 = 0;
      trigger11 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut11, LOW);
    liveTrigCount11 = 0;
  }

  //~~~

  if (trigger12 == true)
  {
    //Triggers
    if (liveTrigCount12 < trigCount)
    {
      digitalWrite(triggerOut12, HIGH);
      liveTrigCount12++;
    }
    else
    {
      digitalWrite(triggerOut12, LOW);
      liveTrigCount12 = 0;
      trigger12 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut12, LOW);
    liveTrigCount12 = 0;
  }

  //~~~

  if (trigger13 == true)
  {
    //Triggers
    if (liveTrigCount13 < trigCount)
    {
      digitalWrite(triggerOut13, HIGH);
      liveTrigCount13++;
    }
    else
    {
      digitalWrite(triggerOut13, LOW);
      liveTrigCount13 = 0;
      trigger13 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut13, LOW);
    liveTrigCount13 = 0;
  }

  //~~~

  if (trigger14 == true)
  {
    //Triggers
    if (liveTrigCount14 < trigCount)
    {
      digitalWrite(triggerOut14, HIGH);
      liveTrigCount14++;
    }
    else
    {
      digitalWrite(triggerOut14, LOW);
      liveTrigCount14 = 0;
      trigger14 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut14, LOW);
    liveTrigCount14 = 0;
  }

  //~~~

  if (trigger15 == true)
  {
    //Serial.println("FUCK");
    //Triggers
    if (liveTrigCount15 < trigCount)
    {
      digitalWrite(triggerOut15, HIGH);
      liveTrigCount15++;
    }
    else
    {
      digitalWrite(triggerOut15, LOW);
      liveTrigCount15 = 0;
      trigger15 = false;
    }
  }
  else
  {
    digitalWrite(triggerOut15, LOW);
    liveTrigCount15 = 0;
  }
}


