//############################################
void setup_keyboard(){
  char row_0[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '<'};
  char row_1[] = {'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P'};
  char row_2[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
  char row_3[] = {'Y', 'X', 'C', 'V', 'B', 'N', 'M'};
  int horPos;
  for (int i = 0; i < 11; i++){
    PrintChar(row_0[i], 6 + i * 21, 212, BLACK, 2);
    horPos = 1 + i * 21;
    tft.drawRect(horPos, 210, 20, 20, BLACK);
  }
  for (int i = 0; i < 10; i++){
    PrintChar(row_1[i], 6 + i * 21, 233, BLACK, 2);
    horPos = 1 + i * 21;
    tft.drawRect(horPos, 231, 20, 20, BLACK);
  }
  for (int i = 0; i < 9; i++){
    PrintChar(row_2[i], 16 + i * 21, 254, BLACK, 2);
    horPos = 11 + i * 21;
    tft.drawRect(horPos, 252, 20, 20, BLACK);
  }
  for (int i = 0; i < 7; i++){
    PrintChar(row_3[i], 26 + i * 21, 275, BLACK, 2);
    horPos = 21 + i * 21;
    tft.drawRect(horPos, 273, 20, 20, BLACK);
  }
  tft.drawRect(63, 294, 104, 20, BLACK);
}
//############################################

//############################################
String keyboardUse(int posx, int posy, String s_toWrite, int maxlen){
  int standard_delay = 50;
  int key = 0;
  for(int i = 1; i < 191; i += 21){
    if(posx > i && posx <= (i + 20) && posy > 210 && posy <= 230){
      key = (i + 20) / 21; delay(standard_delay); break;
    }
  }
  if(key == 0){
    for(int i = 1; i < 191; i += 21){
      if(posx > i && posx <= (i + 20) && posy > 231 && posy <= 251){
        key = ((i + 20) / 21) + 10; delay(standard_delay); break;
      }
    }
  }
  if(key == 0){
    for(int i = 11; i < 180; i += 21){
      if(posx > i && posx <= (i + 20) && posy > 252 && posy <= 272){
        key = ((i + 10) / 21) + 20; delay(standard_delay); break;
      }
    }
  }
  if(key == 0){
    for(int i = 21; i < 168; i += 21){
      if(posx > i && posx < (i + 20) && posy > 273 && posy < 293){
        key = (29 + i / 21); delay(standard_delay); break;
      }
    }
  }
  if(posx > 211 && posx <= 231 && posy > 210 && posy <= 230){key = 99; delay(standard_delay);} //DEL
  if(posx > 63  && posx <= 167 && posy > 294 && posy <= 314){key = 37; delay(standard_delay);} //SPACE

  if(key != 0){
    if (s_toWrite.length() < maxlen && key < 99){
      char Verzeichnis[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'W', 'E', 'R', 'T', 'Z', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Y', 'X', 'C', 'V', 'B', 'N', 'M', ' '};
      s_toWrite.concat(Verzeichnis[key - 1]);
    }
    if(key == 99){s_toWrite.remove(s_toWrite.length() - 1);}
    tft.fillRect(6, 42, 228, 36, WHITE);
    PrintText(s_toWrite, 10, 52, BLACK, 2);
  }
  return s_toWrite;
}
//############################################

//############################################
void startEingabe(){
  tft.fillScreen(WHITE);
  buildEingabeScreen();
  setup_keyboard();
}
//############################################

//############################################
String runEingabe(int maxlen){
  eingabeActive = true;
  String s_toWrite = "";
  while(eingabeActive){
    EasyGetPoint;
    if (pos.z > 0){
      pos.x = x_calc; pos.y = y_calc;
      s_toWrite = keyboardUse(pos.x, pos.y, s_toWrite, maxlen);
      if (pos.x >=  5 && pos.x <=  83 && pos.y >= 82 && pos.y <= 120){
        AnlegenJaButtonAnim(); eingabeActive = false; return s_toWrite;
      }
      else if  (pos.x >= 86 && pos.x <= 164 && pos.y >= 82 && pos.y <= 120){
        AnlegenNeinButtonAnim(); eingabeActive = false; return "";
      }
    }
    delay(50);
  }
}
//############################################
