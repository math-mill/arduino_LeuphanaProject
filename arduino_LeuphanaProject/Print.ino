void PrintText(String text_to_print, int cur_x, int cur_y, int f_color, int f_size){
  tft.setCursor(cur_x, cur_y); tft.setTextColor(f_color); tft.setTextSize(f_size);
  tft.println(text_to_print);
}

void PrintLong(long long_to_print, int cur_x, int cur_y, int f_color, int f_size){
  tft.setCursor(cur_x, cur_y); tft.setTextColor(f_color); tft.setTextSize(f_size);
  tft.println(long_to_print);
}

void PrintChar(char char_to_print, int cur_x, int cur_y, int f_color, int f_size){
  tft.setCursor(cur_x, cur_y); tft.setTextColor(f_color); tft.setTextSize(f_size);
  tft.println(char_to_print);
}
