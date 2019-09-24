#ifndef CAVE_SCHEDULE_H_
#define CAVE_SCHEDULE_H_

#include "Arduino.h"

namespace CAVE{

	class Task{

		public:
			Task();
			Task(uint32_t d);

			Task(void(*callbackPointer)(void), uint32_t d);

			uint32_t delay;
			uint32_t last_fired;

			void fire(uint32_t ts);

			void(*callback)(void);
	};

	void tasks_register_with_cnt(Task* task_table, uint16_t cnt);
	void tasks_update(void);
};


// Redefine tasks_register to include array size
#define tasks_register(c) tasks_register_with_cnt(c, (sizeof(c)/sizeof(c[0])) )

#endif /* CAVE_SCHEDULE_H_ */