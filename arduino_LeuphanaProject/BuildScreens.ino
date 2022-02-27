//############################################
void buildStartScreen(){
  tft.fillScreen(WHITE);
  tft.drawRoundRect(1, 1, 238, 159, 5, BLACK);
  tft.drawRoundRect(2, 2, 236, 157, 5, BLACK);
  PrintText("Scan", 95, 50, BLACK, 2);
  tft.drawRoundRect(1, 161, 238, 158, 5, BLACK);
  tft.drawRoundRect(2, 162, 236, 156, 5, BLACK);
  PrintText("Bibliothek", 62, 210, BLACK, 2);
}
//############################################

//############################################
void buildRFIDScreen(){
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  PrintText("Bluray auflegen:", 11, 12, BLACK, 2);
  tft.drawRect(4, 40, 232, 40, BLACK); //eingabeanzeige
  tft.drawRect(5, 41, 230, 38, BLACK); //eingabeanzeige
  tft.drawRect(225, 4, 10, 10, BLACK);
  PrintChar('x', 227, 5, BLACK, 1);
}
//############################################

//############################################
void buildAnlegenScreen(){
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  tft.drawRect(4, 40, 232, 40, BLACK); //eingabeanzeige
  tft.drawRect(5, 41, 230, 38, BLACK); //eingabeanzeige
  PrintLong(code_toWrite, 11, 52, BLACK, 2);
  PrintText("Neu anlegen?", 11, 12, BLACK, 2);
  tft.drawRoundRect(4, 81, 80, 40, 5, BLACK); //Ja
  tft.drawRoundRect(5, 82, 78, 38, 5, BLACK); //Ja
  PrintText("Ja", 31, 92, BLACK, 2);
  tft.drawRoundRect(85, 81, 80, 40, 5, BLACK); //Nein
  tft.drawRoundRect(86, 82, 78, 38, 5, BLACK); //Nein
  PrintText("Nein", 101, 92, BLACK, 2);
}
//############################################

//############################################
void buildVZLScreen(){
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  tft.drawRect(225, 4, 10, 10, BLACK);
  PrintChar('x', 227, 5, BLACK, 1);
  if(blurayVerliehen[index]){
    PrintText(blurayNameVerlAn[index][0], 5, 5, BLACK, 2);
    PrintText("wurde verliehen an", 5, 25, BLACK, 2);
    PrintText(blurayNameVerlAn[index][1], 5, 45, BLACK, 2);
    tft.drawRoundRect(4, 81, 80, 40, 5, BLACK); //Zurück
    tft.drawRoundRect(5, 82, 78, 38, 5, BLACK); //Zurück
    PrintText("wieder-", 24, 92, BLACK, 1);
    PrintText("bekommen", 21, 102, BLACK, 1);
    tft.drawRoundRect(85, 81, 80, 40, 5, BLACK); //Löschen
    tft.drawRoundRect(86, 82, 78, 38, 5, BLACK); //Löschen
    PrintText("Entfernen", 98, 97, BLACK, 1);
  }else{
    PrintText(blurayNameVerlAn[index][0], 5, 5, BLACK, 2);
    PrintText("ist vor Ort.", 5, 25, BLACK, 2);
    tft.drawRoundRect(4, 81, 80, 40, 5, BLACK); //Verleihen
    tft.drawRoundRect(5, 82, 78, 38, 5, BLACK); //Verleihen
    PrintText("Verleihen", 18, 98, BLACK, 1);
    tft.drawRoundRect(85, 81, 80, 40, 5, BLACK); //Löschen
    tft.drawRoundRect(86, 82, 78, 38, 5, BLACK); //Löschen
    PrintText("Entfernen", 98, 98, BLACK, 1);
  }
}
//############################################

//############################################
void buildBlurayAngelegtScreen(){
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  PrintText(blurayNameVerlAn[blurayCount][0], 5, 5, BLACK, 2);
  PrintText("wurde neu angelegt.", 5, 45, BLACK, 2);
  PrintText("ID:", 5, 85, BLACK, 2);
  PrintLong(blurayID[blurayCount], 45, 85, BLACK, 2);
  delay(1000);
}
//############################################

//############################################
void buildBibVollScreen(){
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  PrintText("Bibliothek voll", 10, 10, BLACK, 2);
  delay(1000);
}
//############################################

//############################################
void buildEingabeScreen(){
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  tft.drawRect(4, 40, 232, 40, BLACK); //eingabeanzeige
  tft.drawRect(5, 41, 230, 38, BLACK); //eingabeanzeige
  PrintText("Name eingeben:", 11, 12, BLACK, 2);
  tft.drawRoundRect(4, 81, 80, 40, 5, BLACK); //Annehmen
  tft.drawRoundRect(5, 82, 78, 38, 5, BLACK); //Annehmen
  PrintText("Annehmen", 18, 96, BLACK, 1);
  tft.drawRoundRect(85, 81, 80, 40, 5, BLACK); //Abbrechen
  tft.drawRoundRect(86, 82, 78, 38, 5, BLACK); //Abbrechen
  PrintText("Abbrechen", 98, 96, BLACK, 1);
}
//############################################

//############################################
void BibInitScreen(){
  index = 0;
  eingabeActive = true;
  tft.fillScreen(WHITE);
  tft.drawRect(1, 1, 238, 318, BLACK);
  tft.drawRect(2, 2, 236, 316, BLACK);
  PrintText("Bibliothek", 5, 5, BLACK, 2);
  tft.drawRect(225, 4, 10, 10, BLACK);
  tft.drawLine(1, 29, 238, 29, BLACK);
  PrintChar('x', 227, 5, BLACK, 1);
  for(int i = 0; i <= 8; i++){tft.drawLine(1, 30 + i * 41, 238, 30 + i * 41, BLACK);}
  BibAnzeige();
}
//############################################

//############################################
void BibRunScreen(){
  while(eingabeActive){
    EasyGetPoint;
    if (pos.z > 0){
      pos.x = x_calc; pos.y = y_calc;
      if (pos.x >= 225 && pos.x <= 235 && pos.y >= 4 && pos.y <= 14){
        reset(); delay(200); return;
      }else if (pos.x >= 0 && pos.x <= 240 && pos.y >= 30 && pos.y <= 173){
        if(index > 0){index -= 1; BibAnzeige();}
      }else if (pos.x >= 0 && pos.x <= 240 && pos.y >= 174 && pos.y <= 320){
        if(blurayCount > 7 && index < blurayCount - 7){index += 1; BibAnzeige();}
      }
    }
  delay(50);
  }
}
//############################################

//############################################
void BibAnzeige(){
  for(int i = 0; i < 7; i++){tft.fillRect(3, 31 + i * 41, 228, 38, WHITE);}
  for(int i = 0; i < 7; i++){
    if(blurayID[index + i] != 0){
      if(blurayVerliehen[index + i]){
        PrintText(blurayNameVerlAn[index + i][0], 5, 33 + i * 41, BRIGHTRED, 2);
        PrintText("verl. ", 5, 33 + i * 41 + 20, BLACK, 2);
        PrintText(blurayNameVerlAn[index + i][1], 75, 33 + i * 41 + 20, BLACK, 2);
      }else{
        PrintText(blurayNameVerlAn[index + i][0], 5, 33 + i * 41, BLACK, 2);
      }
    }
  }
}
//############################################

//############################################
void ScanButtonAnim(){
  for(int i = 0; i < 10; i++){tft.drawRect(3 + i, 3 + i, 234 - 2 * i, 154 - 2 * i, PETROL);   delay(20);}
  for(int i = 9; i >= 0; i--){tft.drawRect(3 + i, 3 + i, 234 - 2 * i, 154 - 2 * i, WHITE);    delay(20);}  
}

void BibButtonAnim(){
  for(int i = 0; i < 10; i++){tft.drawRect(3 + i, 163 + i, 234 - 2 * i, 154 - 2 * i, PETROL); delay(20);}
  for(int i = 9; i >= 0; i--){tft.drawRect(3 + i, 163 + i, 234 - 2 * i, 154 - 2 * i, WHITE);  delay(20);}  
}

void AnlegenJaButtonAnim(){
  for(int i = 0; i <  5; i++){tft.drawRect(6 + i, 83 + i, 76 - 2 * i, 36 - 2 * i, PETROL);    delay(20);}
  for(int i = 4; i >= 0; i--){tft.drawRect(6 + i, 83 + i, 76 - 2 * i, 36 - 2 * i, WHITE);     delay(20);}  
}

void AnlegenNeinButtonAnim(){
  for(int i = 0; i <  5; i++){tft.drawRect(87 + i, 83 + i, 76 - 2 * i, 36 - 2 * i, PETROL);   delay(20);}
  for(int i = 4; i >= 0; i--){tft.drawRect(87 + i, 83 + i, 76 - 2 * i, 36 - 2 * i, WHITE);    delay(20);}
}
//############################################
