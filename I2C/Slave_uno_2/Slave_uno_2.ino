// Dolphin
// Ryan Corkery
// ZRcubed
// February 2017

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <avr/pgmspace.h>

File myFile;

const char loop_0[] PROGMEM = "loop0.txt";
const char loop_1[] PROGMEM = "loop1.txt";
const char loop_2[] PROGMEM = "loop2.txt";
const char loop_3[] PROGMEM = "loop3.txt";
const char loop_4[] PROGMEM = "loop4.txt";
const char loop_5[] PROGMEM = "loop5.txt";
const char loop_6[] PROGMEM = "loop6.txt";
const char loop_7[] PROGMEM = "loop7.txt";
const char loop_8[] PROGMEM = "loop8.txt";
const char loop_9[] PROGMEM = "loop9.txt";
const char loop_10[] PROGMEM = "loop10.txt";
const char loop_11[] PROGMEM = "loop11.txt";
const char loop_12[] PROGMEM = "loop12.txt";
const char loop_13[] PROGMEM = "loop13.txt";
const char loop_14[] PROGMEM = "loop14.txt";
const char loop_15[] PROGMEM = "loop15.txt";
const char loop_16[] PROGMEM = "loop16.txt";
const char loop_17[] PROGMEM = "loop17.txt";
const char loop_18[] PROGMEM = "loop18.txt";
const char loop_19[] PROGMEM = "loop19.txt";
const char loop_20[] PROGMEM = "loop20.txt";
const char loop_21[] PROGMEM = "loop21.txt";
const char loop_22[] PROGMEM = "loop22.txt";
const char loop_23[] PROGMEM = "loop23.txt";
const char loop_24[] PROGMEM = "loop24.txt";
const char loop_25[] PROGMEM = "loop25.txt";
const char loop_26[] PROGMEM = "loop26.txt";
const char loop_27[] PROGMEM = "loop27.txt";
const char loop_28[] PROGMEM = "loop28.txt";
const char loop_29[] PROGMEM = "loop29.txt";
const char loop_30[] PROGMEM = "loop30.txt";
const char loop_31[] PROGMEM = "loop31.txt";
const char loop_32[] PROGMEM = "loop32.txt";
const char loop_33[] PROGMEM = "loop33.txt";
const char loop_34[] PROGMEM = "loop34.txt";
const char loop_35[] PROGMEM = "loop35.txt";
const char loop_36[] PROGMEM = "loop36.txt";
const char loop_37[] PROGMEM = "loop37.txt";
const char loop_38[] PROGMEM = "loop38.txt";
const char loop_39[] PROGMEM = "loop39.txt";
const char loop_40[] PROGMEM = "loop40.txt";
const char loop_41[] PROGMEM = "loop41.txt";
const char loop_42[] PROGMEM = "loop42.txt";
const char loop_43[] PROGMEM = "loop43.txt";
const char loop_44[] PROGMEM = "loop44.txt";
const char loop_45[] PROGMEM = "loop45.txt";
const char loop_46[] PROGMEM = "loop46.txt";
const char loop_47[] PROGMEM = "loop47.txt";
const char loop_48[] PROGMEM = "loop48.txt";
const char loop_49[] PROGMEM = "loop49.txt";
const char loop_50[] PROGMEM = "loop50.txt";
const char loop_51[] PROGMEM = "loop51.txt";
const char loop_52[] PROGMEM = "loop52.txt";
const char loop_53[] PROGMEM = "loop53.txt";
const char loop_54[] PROGMEM = "loop54.txt";
const char loop_55[] PROGMEM = "loop55.txt";
const char loop_56[] PROGMEM = "loop56.txt";
const char loop_57[] PROGMEM = "loop57.txt";
const char loop_58[] PROGMEM = "loop58.txt";
const char loop_59[] PROGMEM = "loop59.txt";
const char loop_60[] PROGMEM = "loop60.txt";
const char loop_61[] PROGMEM = "loop61.txt";
const char loop_62[] PROGMEM = "loop62.txt";
const char loop_63[] PROGMEM = "loop63.txt";
const char loop_64[] PROGMEM = "loop64.txt";
const char loop_65[] PROGMEM = "loop65.txt";
const char loop_66[] PROGMEM = "loop66.txt";
const char loop_67[] PROGMEM = "loop67.txt";
const char loop_68[] PROGMEM = "loop68.txt";
const char loop_69[] PROGMEM = "loop69.txt";
const char loop_70[] PROGMEM = "loop70.txt";
const char loop_71[] PROGMEM = "loop71.txt";
const char loop_72[] PROGMEM = "loop72.txt";
const char loop_73[] PROGMEM = "loop73.txt";
const char loop_74[] PROGMEM = "loop74.txt";
const char loop_75[] PROGMEM = "loop75.txt";
const char loop_76[] PROGMEM = "loop76.txt";
const char loop_77[] PROGMEM = "loop77.txt";
const char loop_78[] PROGMEM = "loop78.txt";
const char loop_79[] PROGMEM = "loop79.txt";
const char loop_80[] PROGMEM = "loop80.txt";
const char loop_81[] PROGMEM = "loop81.txt";
const char loop_82[] PROGMEM = "loop82.txt";
const char loop_83[] PROGMEM = "loop83.txt";
const char loop_84[] PROGMEM = "loop84.txt";
const char loop_85[] PROGMEM = "loop85.txt";
const char loop_86[] PROGMEM = "loop86.txt";
const char loop_87[] PROGMEM = "loop87.txt";
const char loop_88[] PROGMEM = "loop88.txt";
const char loop_89[] PROGMEM = "loop89.txt";
const char loop_90[] PROGMEM = "loop90.txt";
const char loop_91[] PROGMEM = "loop91.txt";
const char loop_92[] PROGMEM = "loop92.txt";
const char loop_93[] PROGMEM = "loop93.txt";
const char loop_94[] PROGMEM = "loop94.txt";
const char loop_95[] PROGMEM = "loop95.txt";
const char loop_96[] PROGMEM = "loop96.txt";
const char loop_97[] PROGMEM = "loop97.txt";
const char loop_98[] PROGMEM = "loop98.txt";
const char loop_99[] PROGMEM = "loop99.txt";

// Loop settings
int loop_number;
const char* const loop_array[100] PROGMEM = {loop_0, loop_1, loop_2, loop_3, loop_4, loop_5, loop_6, loop_7, loop_8, loop_9, loop_10, loop_11, loop_12, loop_13, loop_14, loop_15, loop_16, loop_17, loop_18, loop_19, loop_20, loop_21, loop_22, loop_23, loop_24, loop_25, loop_26, loop_27, loop_28, loop_29, loop_30, loop_31, loop_32, loop_33, loop_34, loop_35, loop_36, loop_37, loop_38, loop_39, loop_40, loop_41, loop_42, loop_43, loop_44, loop_45, loop_46, loop_47, loop_48, loop_49, loop_50, loop_51, loop_52, loop_53, loop_54, loop_55, loop_56, loop_57, loop_58, loop_59, loop_60, loop_61, loop_62, loop_63, loop_64, loop_65, loop_66, loop_67, loop_68, loop_69, loop_70, loop_71, loop_72, loop_73, loop_74, loop_75, loop_76, loop_77, loop_78, loop_79, loop_80, loop_81, loop_82, loop_83, loop_84, loop_85, loop_86, loop_87, loop_88, loop_89, loop_90, loop_91, loop_92, loop_93, loop_94, loop_95, loop_96, loop_97, loop_98, loop_99};
char loop_text[10];

// Current tempo
char tempo [3];

// Current instrument
char instrument [2];

// Change loop up / down
char change_cstr;

// UI button
int delete_loop = 8;

// Button de-bounce
boolean clicked0 = false;

void setup() 
{
  pinMode(delete_loop,INPUT);

  digitalWrite(delete_loop,LOW);

  Wire.begin(8);                    // join i2c bus with address #8
  Wire.onReceive(save_settings);    // register event
  Wire.onRequest(load_settings);    // register event

  // Initialize SD card
  while (!Serial) 
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!SD.begin(4)) 
  {
    return;
  }
}

void loop() 
{ 
  // Delete
  if (digitalRead(delete_loop) == HIGH && clicked0 == false)
  {
  delete_settings();
  clicked0 = true;
  }
  else if (digitalRead(delete_loop) == LOW && clicked0 == true)
  clicked0 = false;
}

void save_settings (int howMany)
{   
  // Recieve settings from master
  // Writting funky stuff at the end of array
  char write_settings[263];
  for (byte i = 0; i < 263; i++)
  {
    char c = Wire.read(); 
    write_settings[i] = c;
  }

  // Read loop number from current settings
  char loop_read[2];
  for (int i = 0; i < 2; i ++)
  {
    loop_read[i] = write_settings[i];
  }
  
  loop_number = atoi(loop_read);

  // Read tempo from current settings
  for (int i = 0; i < 3; i ++)
  {
    tempo[i] = write_settings[i+2];
  }

  // Read intrument # from current settings
  for (int i = 0; i < 2; i ++)
  {
    instrument[i] = write_settings[i+5];
  }

  // Read change_cstr from current settings
    change_cstr = write_settings[7];

  // Print to LCD -> Loop_number
  // Print to LCD -> Tempo
  // Print to LCD -> Instrument #

  // Determine file name
  // Access string info from flash memory
  strcpy_P(loop_text, (char*)pgm_read_word(&(loop_array[loop_number]))); 

  // Remove existing file if exist
  if (SD.exists(loop_text)) 
  {
    SD.remove(loop_text);
  }
  
  // Create file
  myFile = SD.open(loop_text, FILE_WRITE);
  myFile.close();
    
  // Open file to write too
  myFile = SD.open(loop_text, FILE_WRITE);
  
  // Write to file
  if (myFile) 
  {
    // Prints an array of setting values 
    myFile.print(write_settings);
    myFile.close();
    // LCD -> Settings saved
  }  

  else 
  {
    // If the file didn't open, print an error
    // LCD -> error saving, try again
  }
}

void load_settings ()
{ 
  // Determine if loop changes up or down
  if (change_cstr == '0')
  loop_number ++;

  if (change_cstr == '1')
  loop_number --;
 
  // Array to obtain settings from SD card
  char read_settings[263];
  
  // Determine file name
  // Access string info from flash memory
  strcpy_P(loop_text, (char*)pgm_read_word(&(loop_array[loop_number]))); 

  // Open file for reading
  myFile = SD.open(loop_text);
  if (myFile) 
  {    
    for (byte i = 0; i < 263 ; i ++)
    {
      char c = myFile.read();
      read_settings[i] = c;
    }
    
    // close the file:
    myFile.close();   
    
    // Send settings to Master
    Wire.write(read_settings); 
  }
  
  else 
  {
    // if the file didn't open, print an error:
    // LCD -> error loading settings, try again
  }
}

void delete_settings ()
{
  String loop_text = loop_array[loop_number];
  
  // delete file
  SD.remove(loop_text);

  // Check file deleted
  if (SD.exists(loop_text)) 
  {
    // LCD -> error deleting settings, try again
  } 
}
