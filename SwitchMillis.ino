void setup() {

}

void loop() {
  static uint32_t tmr, period;
  static byte mode = 0;
  if (millis() - tmr >= period){
    tmr = millis();
    if (++mode >= 4) mode = 0;
    switch(mode){
      case 0:
        //do something;
        period = 1000;
        break;
      case 1:
        //do something;
        period = 1000;
        break;
      case 2:
        //do something;
        period = 1000;
        break;
      case 3:
        //do something;
        period = 1000;
        break;
    }
  }
}
