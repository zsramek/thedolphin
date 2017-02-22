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
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  
  lights[0][0] = HIGH;
  lights[0][1] = LOW;
  lights[1][0] = LOW;
  lights[1][1] = HIGH;
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
        digitalWrite(col[thisCol], LOW);
      }
        delay(1); //Accounts for transistor delays
    }
    delay(8); //Accounts for transistor delays
    digitalWrite(row[thisRow], LOW);
  }

//for (int i=0; i<2; i++)
//{
//  digitalWrite(24+i, HIGH);
//  if (i == 0)
//  {
//  digitalWrite(26,HIGH);
//  digitalWrite(27,LOW);
//  }
//  else
//  {
//   digitalWrite(26, LOW);
//  digitalWrite(27, LOW); 
//  }
//  delay(1);
//  digitalWrite(24+i,LOW);
//  
//}

//digitalWrite(24, HIGH);
//digitalWrite(25, LOW);
//digitalWrite(26,LOW);
//digitalWrite(27,HIGH);
}

