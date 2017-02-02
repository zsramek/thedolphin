//TODO: Debounce the buttons

//LEDS
const int row[2] = {24, 25};
const int col[2] = {26, 27};
boolean lights[2][2];

//BUTTONS
int buttonRow = 1;
int button = 0;
boolean clicked1 = false;
boolean clicked2 = false;
boolean clicked3 = false;
boolean clicked4 = false;

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

void buttonSetup()
{
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void ledSetup()
{
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  
  lights[0][0] = HIGH;
  lights[0][1] = HIGH;
  lights[1][0] = HIGH;
  lights[1][1] = HIGH;
}

void scanButtons()
{
  if (buttonRow == 1)
  {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    if (digitalRead(8) == HIGH)
    {
      if (clicked1 == false)
      {
        button = 1;
        lights[0][0] = !lights[0][0];
        clicked1 = true;
      }
    }
    else if (digitalRead(8) == LOW)
    {
      if (clicked1 == true)
      {
        clicked1 = false;
      }
    }
    if (digitalRead(9) == HIGH)
    {
      if (clicked2 == false)
      {
        button = 2;
        lights[0][1] = LOW;
        clicked2 = true;
      }
    }
    else if (digitalRead(9) == LOW)
    {
      if (clicked2 == true)
      {
        clicked2 = false;
      }
    }
    buttonRow = 2; //Must come after
  }
  else if (buttonRow == 2)
  {
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
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
  for (int thisRow = 0; thisRow < 2; thisRow++)
  {
    digitalWrite(row[thisRow], HIGH);
    for (int thisCol = 0; thisCol < 2; thisCol++)
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
