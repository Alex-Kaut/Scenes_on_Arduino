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
      case 1:                       //seсond step
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
Such code can be difficult for beginners to understand, therefore, we will analyze it in more detail:

The first part of the code is a timer on millis()
```C++
  static uint32_t tmr, period;      //timer variable
  static byte mode = 0;             //step
  if (millis() - tmr >= period){    //timer
    tmr = millis();
    if (++mode >= 4) mode = 0;
  }
```
In this piece of code, the "mode" variable is incremented by one when time passes equal to the "period" variable. And if "mode == 4", the variable is reset to zero

Second part is ordinary switch
```C++
switch(mode){
      case 0:                       //first step
        //do something;
        period = 1000;              //step execution time, 1000 = 1 second
        break;                      
      case 1:                       //seсond step
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
```
While "mode == 0", case 0 is executed, when mode becomes equal to 1, case 1 is executed. This is obvious. The important point is "break;", it is necessary. Each case is a step of the scene. Period sets the running time of this step, as soon as it passes, mode will increase by one and the next step will begin. "period = 1000" is one second

Now consider the alternative


Let's assume that there is no time binding, actions must occur under some conditions. In this case, it is enough to simply make a switch with the conditions
```C++
switch(mode){
      case 0:                       
        //do something;
        if(condition){mode+=1;}
        break;                      
      case 1:                       
        //do something;
        if(condition){mode+=1;}
        break;
      case 2:
        //do something;
        if(condition){mode = 0;}
        break;
    }
```


An option in which some of the steps of the scene do not depend on time (for example, waiting for a button to be pressed)
```C++
switch(mode){
    case 0:
      //do something;
      if(condition){mode+=1;}
      break;

    case 1: 
      if(millis() - tmr >= 10000){    //10000 means waiting for 10 seconds 
        tmr = millis();
        mode = 2;
        }
      break;

    case 2:
      //do something;
      if(condition){mode = 0;}
      break;                     
}
```

It is also worth mentioning the fact that some functions must be performed once, for example, starting an mp3 file in dfminiMP3, if you perform this function many times, the track will return to the very beginning and will not be executed. The solution is simple
```C++
switch(mode){
    case 0:
      //do something;
      if(condition){mode+=1;}
      break;

    case 1: 
      //do function that must be executed once
      mode += 1;
      break;

    case 2:
      //do something;
      if(condition){mode = 0;}
      break;                     
}
```
Yes, it's enough just to make a case that will be executed once and immediately after that will move on to the next step

Thanks to these templates, you can make any scene on the arduino, good luck!
