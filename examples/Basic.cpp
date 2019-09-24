#include <Arduino.h>
#include <CAVE_Tasks.h>

// Define a couple of functions
uint16_t i=0;
void increment_counter(){
	i++;
}
void print_counter(){
	Serial.println(i);
}

// Create tasks and add to a list
CAVE::Task task1(increment_counter, 50);
CAVE::Task task2(print_counter, 		1000);

CAVE::Task task_list[] = {
	task1,
	task2
};

void setup() {

	// Start Serial (for demo)
	Serial.begin(115200);

	// Register tasks
	CAVE::tasks_register(task_list);
}

void loop() {
	// Call task updater
	CAVE::tasks_update();
}