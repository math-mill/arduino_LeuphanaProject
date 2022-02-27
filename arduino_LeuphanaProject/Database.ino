boolean blurayVerliehen[20];
long    blurayID[20];
String  blurayNameVerlAn[20][2];

//############################################
void blurayAnlegenYN(){
  eingabeActive = true;
  while(eingabeActive){
    EasyGetPoint;
    if (pos.z > 0){
      pos.x = x_calc; pos.y = y_calc;
      if (pos.x >= 4 && pos.x <= 84 && pos.y >= 81 && pos.y <= 121){
        AnlegenJaButtonAnim();
        blurayAnlegen();
        reset(); delay(200); return;
      }
      if (pos.x >= 85 && pos.x <= 165 && pos.y >= 81 && pos.y <= 121){
        AnlegenNeinButtonAnim();
        reset(); delay(200); return;
      }
    }
  }
}
//############################################

//############################################
void blurayAnlegen(){
  blurayID           [blurayCount]    = code_toWrite;
  blurayNameVerlAn   [blurayCount][0] = blurayGetName(16);
  if(blurayNameVerlAn[blurayCount][0] != ""){
    blurayVerliehen  [blurayCount] = false;
    blurayNameVerlAn [blurayCount][1] = "";
    buildBlurayAngelegtScreen();
    blurayCount += 1;
    Sortieren();
  }else{
    blurayID         [blurayCount] = 0;
    delay(200);
  }
}
//############################################

//############################################
void blurayVZL(){
  eingabeActive = true;
  while(eingabeActive){
    EasyGetPoint;
    if (pos.z > 0){
      pos.x = x_calc; pos.y = y_calc;
      if (pos.x >= 225 && pos.x <= 235 && pos.y >= 4 && pos.y <= 14){
        reset(); delay(200); return;
      }
      if (pos.x >= 4 && pos.x <= 84 && pos.y >= 81 && pos.y <= 121){
        if(blurayVerliehen[index]){
          AnlegenJaButtonAnim(); blurayZurueck();
          reset(); delay(200); return;
        }else{
          AnlegenJaButtonAnim(); blurayVerleihen();
          reset(); delay(200); return;
        }
      }
      if (pos.x >= 85 && pos.x <= 165 && pos.y >= 81 && pos.y <= 121){
        AnlegenNeinButtonAnim(); blurayLoeschen();
        reset(); delay(200); return;
      }
    }
  }
}
//############################################

//############################################
void blurayVerleihen(){
  blurayNameVerlAn[index][1] = blurayGetName(13);
  if(blurayNameVerlAn[index][1] != ""){blurayVerliehen[index] = true;}  
}
//############################################

//############################################
void blurayZurueck(){
  blurayNameVerlAn[index][1] = "";
  blurayVerliehen[index] = false;
}
//############################################

//############################################
void blurayLoeschen(){
  blurayVerliehen[index]     = blurayVerliehen[blurayCount];
  blurayID[index]            = blurayID[blurayCount];
  blurayNameVerlAn[index][0] = blurayNameVerlAn[blurayCount][0];
  blurayNameVerlAn[index][1] = blurayNameVerlAn[blurayCount][1];
  blurayCount -= 1;
  Sortieren();
}
//############################################

//############################################
String blurayGetName(int maxlen){
  startEingabe();
  return runEingabe(maxlen);
}
//############################################

//############################################
void searchBluray(){
  for (int i = 0; i < ArrMaxLen; i++){
    if(blurayID[i] != 0 && blurayID[i] == code_toWrite){
      index = i;
    }
  }
}
//############################################

//############################################
void Sortieren(){
  String tempStr;
  boolean tempBool;
  long tempLong;
  if(blurayCount > 1){
    for(int i = 0; i < blurayCount; i++){
      for(int j = 0; j < blurayCount - i - 1; j++){
        if(blurayID[j + 1] > 0){
          if(blurayNameVerlAn[j][0].compareTo(blurayNameVerlAn[j + 1][0]) >= 0){
            tempStr = blurayNameVerlAn[j][0];
            blurayNameVerlAn[j][0] = blurayNameVerlAn[j + 1][0];
            blurayNameVerlAn[j + 1][0] = tempStr;
            
            tempStr = blurayNameVerlAn[j][1];
            blurayNameVerlAn[j][1] = blurayNameVerlAn[j + 1][1];
            blurayNameVerlAn[j + 1][1] = tempStr;
            
            tempBool = blurayVerliehen[j];
            blurayVerliehen[j] = blurayVerliehen[j + 1];
            blurayVerliehen[j + 1] = tempBool;
            
            tempLong = blurayID[j];
            blurayID[j] = blurayID[j + 1];
            blurayID[j + 1] = tempLong;
          }
        }
      }      
    }
  }
}
//############################################
