//LED Matrix Test

const int row[2] = {24, 25};
const int col[2] = {26, 27};
boolean lights[2][2];

void setup()
{
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  
  lights[0][0] = LOW;
  lights[0][1] = HIGH;
  lights[1][0] = HIGH;
  lights[1][1] = LOW;
}

void loop()
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

