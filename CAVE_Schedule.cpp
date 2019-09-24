#include "Arduino.h"
#include "CAVE_Schedule.h"

CAVE::Task* tasks = 0;
uint16_t 	num_tasks = 0;

CAVE::Task::Task(){};

CAVE::Task::Task(uint32_t d) :
	delay(d)
{};

CAVE::Task::Task(void(*callbackPointer)(void), uint32_t d){
	delay = d;
	callback = callbackPointer;
};

void CAVE::Task::fire(uint32_t ts){
	callback();
	last_fired = ts;
}

void CAVE::tasks_register_with_cnt(Task* task_table, uint16_t cnt){
	tasks = task_table;
	num_tasks = cnt;
}

void CAVE::tasks_update(void){
	// Task handling
	uint32_t curr_ms = millis();
	for(uint16_t i = 0; i < num_tasks; i++){
		if(curr_ms - tasks[i].last_fired > tasks[i].delay){
			tasks[i].fire(millis());
		}
	}
}