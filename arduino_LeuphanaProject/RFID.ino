long readRFID(){
  if ( ! mfrc522.PICC_IsNewCardPresent()){return 0;}
  if ( ! mfrc522.PICC_ReadCardSerial())  {return 0;}
  long code = 0;
  for (int i = 0; i < mfrc522.uid.size; i++){code=((code+mfrc522.uid.uidByte[i])*10);}
  return code;
}

void runRFIDRead(){
  eingabeActive = true;
  long code_toProof;
  while(eingabeActive){
    EasyGetPoint;
    if (pos.z > 0){
      pos.x = x_calc; pos.y = y_calc;
      if (pos.x >= 225 && pos.x <= 235 && pos.y >= 4 && pos.y <= 14){
        reset(); delay(200); return;
      }
    }
    code_toProof = readRFID();
    if (code_toProof > 0 && code_toProof != code_toWrite){
      code_toWrite = code_toProof;
      tft.fillRect(6, 43, 228, 35, WHITE);
      PrintLong(code_toWrite, 11, 52, BLACK, 2);
      eingabeActive = false;
    }
    delay(10);
  }
  searchBluray();
  if (index == -1){
    if (blurayCount == ArrMaxLen){buildBibVollScreen(); reset();}
    else{buildAnlegenScreen(); blurayAnlegenYN();}
  }else{
    buildVZLScreen(); blurayVZL();
  }
}
