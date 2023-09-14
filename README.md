# Scenes on Arduino
Sometimes I am asked to make electronic scenes for museums, exhibitions and other events. For such tasks, it is most convenient to use Arduino microcontrollers, since they are very affordable, the code for them is written quickly, high performance is not needed, and there is usually little time to complete the task

With these templates, you can create a variety of scenes that can perform many actions in parallel

Let's take a look at the classic "switch + millis()" template


[.ino file with this code](https://github.com/Alex-Kaut/Scenes_on_Arduino/blob/main/SwitchMillis.ino)
```c++
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
```
Such code can be difficult for beginners to understand, therefore, we will analyze it in more detail

