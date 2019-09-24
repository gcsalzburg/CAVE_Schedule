# 📋 CAVE_Tasks

Basic task scheduler for Arduino platforms.

No frills - just an endless loop of event calls based on the timing.

N.B: Nothing to do with [troglodytes](https://en.wikipedia.org/wiki/Troglodyte)...

```c++
#include <CAVE_Tasks.h>

// Create function prototype
void print_hello(){
   Serial.println("Hello");
}

// Create task to print Hello every second
CAVE::Task my_task(increment_counter, 1000);

void setup() {
   Serial.begin(9600); // Start Serial (for demo)
   CAVE::tasks_register({my_task}); // Register a list of tasks
}

void loop() {
   CAVE::tasks_update(); // Call task updater as only item in loop
}
```