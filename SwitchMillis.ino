void setup() {

}

void loop() {
  static uint32_t tmr, period;      //timer variable
  static byte mode = 0;             //step
  if (millis() - tmr >= period){    //timer
    tmr = millis();
    if (++mode >= 4) mode = 0;      //moving to the next step by timer
    switch(mode){
      case 0:                       //first step
        //do something;
        period = 1000;              //step execution time, 1000 = 1 second
        break;                      
      case 1:                       //sedond step
        //do something;
        period = 1000;              //then similarly
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
