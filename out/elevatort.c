#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ltsmin/pins.h>
#include <ltsmin/pins-util.h>
#include <ltsmin/ltsmin-standard.h>
#include <ltsmin/lts-type.h>

typedef struct basic_var{
	char *name;
	int num;
	int *value;
}smv_basic_var;


typedef enum boolean{
	FALSE, TRUE
}boolean;

typedef enum smv_enum{
	 EMPTYENUM10, EMPTYENUM15, EMPTYENUM20, EMPTYENUM25, EMPTYENUM30, EMPTYENUM0, EMPTYENUM1, EMPTYENUM2, EMPTYENUM3, EMPTYENUM4, EMPTYENUM5, open, closed, move_up, move_down, stop, wait, nothing, close_,
}smv_enum;

const int smv_get_state_size() {
	return 28;
}

typedef struct state_t {
	boolean elevator_button1_pressed;
	boolean elevator_button2_pressed;
	boolean elevator_button3_pressed;
	boolean elevator_buttonOpenDoor_pressed;
	boolean elevator_moving;
	smv_enum elevator_position;
	boolean elevator_waiting;
	smv_enum elevator_move_counter;
	boolean Floor1btn_requestButton_pressed;
	smv_enum Floor1btn_location;
	boolean Floor2btn_requestButton_pressed;
	smv_enum Floor2btn_location;
	boolean Floor3btn_requestButton_pressed;
	smv_enum Floor3btn_location;
	smv_enum door_status;
	smv_enum door_door_counter;
	boolean ctrl_resetFloor1btn;
	boolean ctrl_resetFloor2btn;
	boolean ctrl_resetFloor3btn;
	boolean ctrl_resetButton1;
	boolean ctrl_resetButton2;
	boolean ctrl_resetButton3;
	boolean ctrl_resetButtonOpenDoor;
	smv_enum ctrl_move_cmd;
	smv_enum ctrl_door_action;
	boolean ctrl_last_dir;
	boolean ctrl_prev_direction_up;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.elevator_button1_pressed               = FALSE,
	.elevator_button2_pressed               = FALSE,
	.elevator_button3_pressed               = FALSE,
	.elevator_buttonOpenDoor_pressed        = FALSE,
	.elevator_moving                        = FALSE,
	.elevator_position                      = 0,
	.elevator_waiting                       = FALSE,
	.elevator_move_counter                  = 0,
	.Floor1btn_requestButton_pressed        = FALSE,
	.Floor1btn_location                     = 0,
	.Floor2btn_requestButton_pressed        = FALSE,
	.Floor2btn_location                     = 0,
	.Floor3btn_requestButton_pressed        = FALSE,
	.Floor3btn_location                     = 0,
	.door_status                            = 0,
	.door_door_counter                      = 0,
	.ctrl_resetFloor1btn                    = FALSE,
	.ctrl_resetFloor2btn                    = FALSE,
	.ctrl_resetFloor3btn                    = FALSE,
	.ctrl_resetButton1                      = FALSE,
	.ctrl_resetButton2                      = FALSE,
	.ctrl_resetButton3                      = FALSE,
	.ctrl_resetButtonOpenDoor               = FALSE,
	.ctrl_move_cmd                          = 0,
	.ctrl_door_action                       = 0,
	.ctrl_last_dir                          = FALSE,
	.ctrl_prev_direction_up                 = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"elevator_button1_pressed",1,0x0},
	{"elevator_button2_pressed",1,0x0},
	{"elevator_button3_pressed",1,0x0},
	{"elevator_buttonOpenDoor_pressed",1,0x0},
	{"elevator_moving",1,0x0},
	{"elevator_position",1,0x0},
	{"elevator_waiting",1,0x0},
	{"elevator_move_counter",1,0x0},
	{"Floor1btn_requestButton_pressed",1,0x0},
	{"Floor1btn_location",1,0x0},
	{"Floor2btn_requestButton_pressed",1,0x0},
	{"Floor2btn_location",1,0x0},
	{"Floor3btn_requestButton_pressed",1,0x0},
	{"Floor3btn_location",1,0x0},
	{"door_status",1,0x0},
	{"door_door_counter",1,0x0},
	{"ctrl_resetFloor1btn",1,0x0},
	{"ctrl_resetFloor2btn",1,0x0},
	{"ctrl_resetFloor3btn",1,0x0},
	{"ctrl_resetButton1",1,0x0},
	{"ctrl_resetButton2",1,0x0},
	{"ctrl_resetButton3",1,0x0},
	{"ctrl_resetButtonOpenDoor",1,0x0},
	{"ctrl_move_cmd",1,0x0},
	{"ctrl_door_action",1,0x0},
	{"ctrl_last_dir",1,0x0},
	{"ctrl_prev_direction_up",1,0x0},
	{"virtual_init",1,0x0},
};

int smv_non_deterministic(char *name ,int num,...){
	int i,j;
	va_list args; 
	for(i=0;i<smv_get_state_size();i++){
		if(strcmp(basic_var_list[i].name,name)==0)
			break;
	}
	basic_var_list[i].num = num;
	free(basic_var_list[i].value);
	basic_var_list[i].value = (int *)malloc(sizeof(int)*num);
	va_start(args, num); 
	for(j=0;j<num;j++){
		basic_var_list[i].value[j]= va_arg(args, int);
	}
	va_end(args); 
	return 0;
}

int states_emitted(state_t *out,transition_info_t *transition_info,int cpy[],void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy),void *arg,int i){
	int count =0;
	for(;i<smv_get_state_size();i++){
		if(basic_var_list[i].num>1 ){
			int j;
			for(j=0;j<basic_var_list[i].num;j++){
				int *change = (int *)out;
				*(int*)((char *)change + sizeof(int)*i) = basic_var_list[i].value[j];
				count += states_emitted(out,transition_info,cpy,callback,arg,i+1);
			}
			break;
		}
	}
	if(i==smv_get_state_size()){
		callback(arg,transition_info,out,cpy);
		count++;
	}else if(i == 0){
		for(;i<smv_get_state_size();i++){
			basic_var_list[i].num=1; 
		}
	}	return count;
}
void smv_get_initial_state(int *to){
	memcpy(to, (char*)&initial_s, sizeof(state_t));
}

int smv_get_actions (void* model, int t, state_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy), void *arg) {
	int transition_labels[2] = {0, 0, };
	transition_info_t transition_info = { transition_labels, t };
	state_t local_state;
	state_t* out = &local_state;
	int cpy[28] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int elevator_button1pressed;
		int elevator_button2pressed;
		int elevator_button3pressed;
		int elevator_buttonOpenDoorPressed;
		int Floor1btn_pressed;
		int Floor1btn_serviced;
		int Floor2btn_pressed;
		int Floor2btn_serviced;
		int Floor3btn_pressed;
		int Floor3btn_serviced;
		int ctrl_ReqestAtSameFloor;
		int ctrl_AnyOtherRequest;
		int ctrl_arrived;
		int ctrl_anyButtonPressed;
		int ctrl_IDLE;
		int ctrl_BUTTON_PRESSED;
		int ctrl_STARTED;
		int ctrl_ARRIVING;
		int ctrl_ARRIVED;
		int ctrl_SERVICED;
		int ctrl_direction_up;
		int ctrl_Floor1btnServiced;
		int ctrl_Floor2btnServiced;
		int ctrl_Floor3btnServiced;
		int ctrl_elevButton1Serviced;
		int ctrl_elevButton2Serviced;
		int ctrl_elevButton3Serviced;
		int betweenTheFloors;
		elevator_button1pressed = in->elevator_button1_pressed;
		elevator_button2pressed = in->elevator_button2_pressed;
		elevator_button3pressed = in->elevator_button3_pressed;
		elevator_buttonOpenDoorPressed = in->elevator_buttonOpenDoor_pressed;
		Floor1btn_pressed = in->Floor1btn_requestButton_pressed;
		Floor1btn_serviced = (10 == in->elevator_position && in->door_status == open);
		Floor2btn_pressed = in->Floor2btn_requestButton_pressed;
		Floor2btn_serviced = (20 == in->elevator_position && in->door_status == open);
		Floor3btn_pressed = in->Floor3btn_requestButton_pressed;
		Floor3btn_serviced = (30 == in->elevator_position && in->door_status == open);
		ctrl_ReqestAtSameFloor = (Floor1btn_pressed && in->elevator_position == 10) || (Floor2btn_pressed && in->elevator_position == 20) || (Floor3btn_pressed && in->elevator_position == 30) || (elevator_button1pressed && in->elevator_position == 10) || (elevator_button2pressed && in->elevator_position == 20) || (elevator_button3pressed && in->elevator_position == 30);
		ctrl_AnyOtherRequest = (ctrl_anyButtonPressed && !ctrl_ReqestAtSameFloor);
		ctrl_arrived = ctrl_ReqestAtSameFloor && !in->elevator_waiting;
		ctrl_anyButtonPressed = (elevator_button1pressed || elevator_button2pressed || elevator_button3pressed || Floor1btn_pressed || Floor2btn_pressed || Floor3btn_pressed);
		ctrl_IDLE = !in->elevator_moving && !ctrl_arrived && in->elevator_waiting && (in->door_status == open);
		ctrl_BUTTON_PRESSED = !in->elevator_moving && !(in->door_status == open) && (ctrl_anyButtonPressed || elevator_buttonOpenDoorPressed) && !ctrl_arrived && !in->elevator_waiting;
		ctrl_STARTED = in->elevator_moving && !(in->door_status == open) && ctrl_anyButtonPressed && !ctrl_arrived && !in->elevator_waiting;
		ctrl_ARRIVING = in->elevator_moving && !(in->door_status == open) && ctrl_ReqestAtSameFloor && ctrl_arrived && !in->elevator_waiting;
		ctrl_ARRIVED = !in->elevator_moving && !(in->door_status == open) && ctrl_ReqestAtSameFloor && ctrl_arrived && !in->elevator_waiting;
		ctrl_SERVICED = !in->elevator_moving && (in->door_status == open) && !ctrl_ReqestAtSameFloor && !elevator_buttonOpenDoorPressed && !ctrl_arrived && !in->elevator_waiting;
		ctrl_direction_up = (in->elevator_position == 10 && ((Floor2btn_pressed || elevator_button2pressed) || (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 15 && ((Floor2btn_pressed || elevator_button2pressed) || (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 20 && (!(Floor1btn_pressed || elevator_button1pressed) && (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 20 && ((Floor1btn_pressed || elevator_button1pressed) && (Floor3btn_pressed || elevator_button3pressed)) && !in->ctrl_prev_direction_up) || (in->elevator_position == 25 && ((Floor3btn_pressed || elevator_button3pressed)));
		ctrl_Floor1btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 10);
		ctrl_Floor2btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 20);
		ctrl_Floor3btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 30);
		ctrl_elevButton1Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 10);
		ctrl_elevButton2Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 20);
		ctrl_elevButton3Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 30);
		betweenTheFloors = (in->elevator_position == 15 || in->elevator_position == 25);
		out->elevator_button1_pressed = FALSE;
		cpy[((int *)&out->elevator_button1_pressed - (int *)out)] = 0;
		out->elevator_button2_pressed = FALSE;
		cpy[((int *)&out->elevator_button2_pressed - (int *)out)] = 0;
		out->elevator_button3_pressed = FALSE;
		cpy[((int *)&out->elevator_button3_pressed - (int *)out)] = 0;
		out->elevator_buttonOpenDoor_pressed = FALSE;
		cpy[((int *)&out->elevator_buttonOpenDoor_pressed - (int *)out)] = 0;
		out->elevator_moving = FALSE;
		cpy[((int *)&out->elevator_moving - (int *)out)] = 0;
		out->elevator_position = 10;
		cpy[((int *)&out->elevator_position - (int *)out)] = 0;
		out->elevator_waiting = TRUE;
		cpy[((int *)&out->elevator_waiting - (int *)out)] = 0;
		out->elevator_move_counter = 0;
		cpy[((int *)&out->elevator_move_counter - (int *)out)] = 0;
		out->Floor1btn_requestButton_pressed = FALSE;
		cpy[((int *)&out->Floor1btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor1btn_location = 10;
		cpy[((int *)&out->Floor1btn_location - (int *)out)] = 0;
		out->Floor2btn_requestButton_pressed = FALSE;
		cpy[((int *)&out->Floor2btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor2btn_location = 20;
		cpy[((int *)&out->Floor2btn_location - (int *)out)] = 0;
		out->Floor3btn_requestButton_pressed = FALSE;
		cpy[((int *)&out->Floor3btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor3btn_location = 30;
		cpy[((int *)&out->Floor3btn_location - (int *)out)] = 0;
		out->door_status = open;
		cpy[((int *)&out->door_status - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->door_door_counter = smv_non_deterministic("door_door_counter",5,0,1,2,3,4);
		cpy[((int *)&out->door_door_counter - (int *)out)] = 0;
		out->ctrl_resetFloor1btn = smv_non_deterministic("ctrl_resetFloor1btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor1btn - (int *)out)] = 0;
		out->ctrl_resetFloor2btn = smv_non_deterministic("ctrl_resetFloor2btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor2btn - (int *)out)] = 0;
		out->ctrl_resetFloor3btn = smv_non_deterministic("ctrl_resetFloor3btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor3btn - (int *)out)] = 0;
		out->ctrl_resetButton1 = smv_non_deterministic("ctrl_resetButton1",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton1 - (int *)out)] = 0;
		out->ctrl_resetButton2 = smv_non_deterministic("ctrl_resetButton2",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton2 - (int *)out)] = 0;
		out->ctrl_resetButton3 = smv_non_deterministic("ctrl_resetButton3",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton3 - (int *)out)] = 0;
		out->ctrl_resetButtonOpenDoor = smv_non_deterministic("ctrl_resetButtonOpenDoor",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButtonOpenDoor - (int *)out)] = 0;
		out->ctrl_move_cmd = smv_non_deterministic("ctrl_move_cmd",5,move_up,move_down,stop,wait,nothing);
		cpy[((int *)&out->ctrl_move_cmd - (int *)out)] = 0;
		out->ctrl_door_action = smv_non_deterministic("ctrl_door_action",3,open,close_,nothing);
		cpy[((int *)&out->ctrl_door_action - (int *)out)] = 0;
		out->ctrl_last_dir = smv_non_deterministic("ctrl_last_dir",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_last_dir - (int *)out)] = 0;
		out->ctrl_prev_direction_up = smv_non_deterministic("ctrl_prev_direction_up",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_prev_direction_up - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int elevator_button1pressed;
		int elevator_button2pressed;
		int elevator_button3pressed;
		int elevator_buttonOpenDoorPressed;
		int Floor1btn_pressed;
		int Floor1btn_serviced;
		int Floor2btn_pressed;
		int Floor2btn_serviced;
		int Floor3btn_pressed;
		int Floor3btn_serviced;
		int ctrl_ReqestAtSameFloor;
		int ctrl_AnyOtherRequest;
		int ctrl_arrived;
		int ctrl_anyButtonPressed;
		int ctrl_IDLE;
		int ctrl_BUTTON_PRESSED;
		int ctrl_STARTED;
		int ctrl_ARRIVING;
		int ctrl_ARRIVED;
		int ctrl_SERVICED;
		int ctrl_direction_up;
		int ctrl_Floor1btnServiced;
		int ctrl_Floor2btnServiced;
		int ctrl_Floor3btnServiced;
		int ctrl_elevButton1Serviced;
		int ctrl_elevButton2Serviced;
		int ctrl_elevButton3Serviced;
		int betweenTheFloors;
		elevator_button1pressed = in->elevator_button1_pressed;
		elevator_button2pressed = in->elevator_button2_pressed;
		elevator_button3pressed = in->elevator_button3_pressed;
		elevator_buttonOpenDoorPressed = in->elevator_buttonOpenDoor_pressed;
		Floor1btn_pressed = in->Floor1btn_requestButton_pressed;
		Floor1btn_serviced = (10 == in->elevator_position && in->door_status == open);
		Floor2btn_pressed = in->Floor2btn_requestButton_pressed;
		Floor2btn_serviced = (20 == in->elevator_position && in->door_status == open);
		Floor3btn_pressed = in->Floor3btn_requestButton_pressed;
		Floor3btn_serviced = (30 == in->elevator_position && in->door_status == open);
		ctrl_ReqestAtSameFloor = (Floor1btn_pressed && in->elevator_position == 10) || (Floor2btn_pressed && in->elevator_position == 20) || (Floor3btn_pressed && in->elevator_position == 30) || (elevator_button1pressed && in->elevator_position == 10) || (elevator_button2pressed && in->elevator_position == 20) || (elevator_button3pressed && in->elevator_position == 30);
		ctrl_AnyOtherRequest = (ctrl_anyButtonPressed && !ctrl_ReqestAtSameFloor);
		ctrl_arrived = ctrl_ReqestAtSameFloor && !in->elevator_waiting;
		ctrl_anyButtonPressed = (elevator_button1pressed || elevator_button2pressed || elevator_button3pressed || Floor1btn_pressed || Floor2btn_pressed || Floor3btn_pressed);
		ctrl_IDLE = !in->elevator_moving && !ctrl_arrived && in->elevator_waiting && (in->door_status == open);
		ctrl_BUTTON_PRESSED = !in->elevator_moving && !(in->door_status == open) && (ctrl_anyButtonPressed || elevator_buttonOpenDoorPressed) && !ctrl_arrived && !in->elevator_waiting;
		ctrl_STARTED = in->elevator_moving && !(in->door_status == open) && ctrl_anyButtonPressed && !ctrl_arrived && !in->elevator_waiting;
		ctrl_ARRIVING = in->elevator_moving && !(in->door_status == open) && ctrl_ReqestAtSameFloor && ctrl_arrived && !in->elevator_waiting;
		ctrl_ARRIVED = !in->elevator_moving && !(in->door_status == open) && ctrl_ReqestAtSameFloor && ctrl_arrived && !in->elevator_waiting;
		ctrl_SERVICED = !in->elevator_moving && (in->door_status == open) && !ctrl_ReqestAtSameFloor && !elevator_buttonOpenDoorPressed && !ctrl_arrived && !in->elevator_waiting;
		ctrl_direction_up = (in->elevator_position == 10 && ((Floor2btn_pressed || elevator_button2pressed) || (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 15 && ((Floor2btn_pressed || elevator_button2pressed) || (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 20 && (!(Floor1btn_pressed || elevator_button1pressed) && (Floor3btn_pressed || elevator_button3pressed))) || (in->elevator_position == 20 && ((Floor1btn_pressed || elevator_button1pressed) && (Floor3btn_pressed || elevator_button3pressed)) && !in->ctrl_prev_direction_up) || (in->elevator_position == 25 && ((Floor3btn_pressed || elevator_button3pressed)));
		ctrl_Floor1btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 10);
		ctrl_Floor2btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 20);
		ctrl_Floor3btnServiced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 30);
		ctrl_elevButton1Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 10);
		ctrl_elevButton2Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 20);
		ctrl_elevButton3Serviced = (!in->elevator_moving && (in->door_status == open) && in->elevator_position == 30);
		betweenTheFloors = (in->elevator_position == 15 || in->elevator_position == 25);
		out->elevator_button1_pressed =  ( in->elevator_button1_pressed && in->ctrl_resetButton1 ? FALSE :  ( !in->elevator_button1_pressed && in->ctrl_resetButton1 ? FALSE :  ( in->elevator_button1_pressed && !in->ctrl_resetButton1 ? TRUE : smv_non_deterministic("elevator_button1_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->elevator_button1_pressed - (int *)out)] = 0;
		out->elevator_button2_pressed =  ( in->elevator_button2_pressed && in->ctrl_resetButton2 ? FALSE :  ( !in->elevator_button2_pressed && in->ctrl_resetButton2 ? FALSE :  ( in->elevator_button2_pressed && !in->ctrl_resetButton2 ? TRUE : smv_non_deterministic("elevator_button2_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->elevator_button2_pressed - (int *)out)] = 0;
		out->elevator_button3_pressed =  ( in->elevator_button3_pressed && in->ctrl_resetButton3 ? FALSE :  ( !in->elevator_button3_pressed && in->ctrl_resetButton3 ? FALSE :  ( in->elevator_button3_pressed && !in->ctrl_resetButton3 ? TRUE : smv_non_deterministic("elevator_button3_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->elevator_button3_pressed - (int *)out)] = 0;
		out->elevator_buttonOpenDoor_pressed =  ( in->elevator_buttonOpenDoor_pressed && in->ctrl_resetButtonOpenDoor ? FALSE :  ( !in->elevator_buttonOpenDoor_pressed && in->ctrl_resetButtonOpenDoor ? FALSE :  ( in->elevator_buttonOpenDoor_pressed && !in->ctrl_resetButtonOpenDoor ? TRUE : smv_non_deterministic("elevator_buttonOpenDoor_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->elevator_buttonOpenDoor_pressed - (int *)out)] = 0;
		out->elevator_moving =  ( in->ctrl_move_cmd == move_up ? TRUE :  ( in->ctrl_move_cmd == move_down ? TRUE :  ( in->ctrl_move_cmd == stop ? FALSE : in->elevator_moving )  )  ) ;
		cpy[((int *)&out->elevator_moving - (int *)out)] = 0;
		out->elevator_position =  ( in->ctrl_move_cmd == move_up ?  ( in->elevator_position == 30 ? 30 : in->elevator_position + 5 )  :  ( in->ctrl_move_cmd == move_down ?  ( in->elevator_position == 10 ? 10 : in->elevator_position - 5 )  : in->elevator_position )  ) ;
		cpy[((int *)&out->elevator_position - (int *)out)] = 0;
		out->elevator_waiting =  ( in->ctrl_move_cmd == wait ? TRUE :  ( in->ctrl_move_cmd == move_up ? FALSE :  ( in->ctrl_move_cmd == move_down ? FALSE :  ( in->ctrl_move_cmd == nothing ? FALSE :  ( in->ctrl_move_cmd == stop ? FALSE : in->elevator_waiting )  )  )  )  ) ;
		cpy[((int *)&out->elevator_waiting - (int *)out)] = 0;
		out->elevator_move_counter =  ( in->ctrl_move_cmd == stop ? 0 :  ( in->elevator_move_counter == 5 ? 5 :  ( in->ctrl_move_cmd == move_up ? (in->elevator_move_counter + 1) :  ( in->ctrl_move_cmd == move_down ? (in->elevator_move_counter + 1) : in->elevator_move_counter )  )  )  ) ;
		cpy[((int *)&out->elevator_move_counter - (int *)out)] = 0;
		out->Floor1btn_requestButton_pressed =  ( in->Floor1btn_requestButton_pressed && in->ctrl_resetFloor1btn ? FALSE :  ( !in->Floor1btn_requestButton_pressed && in->ctrl_resetFloor1btn ? FALSE :  ( in->Floor1btn_requestButton_pressed && !in->ctrl_resetFloor1btn ? TRUE : smv_non_deterministic("Floor1btn_requestButton_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->Floor1btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor1btn_location = 10;
		cpy[((int *)&out->Floor1btn_location - (int *)out)] = 0;
		out->Floor2btn_requestButton_pressed =  ( in->Floor2btn_requestButton_pressed && in->ctrl_resetFloor2btn ? FALSE :  ( !in->Floor2btn_requestButton_pressed && in->ctrl_resetFloor2btn ? FALSE :  ( in->Floor2btn_requestButton_pressed && !in->ctrl_resetFloor2btn ? TRUE : smv_non_deterministic("Floor2btn_requestButton_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->Floor2btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor2btn_location = 20;
		cpy[((int *)&out->Floor2btn_location - (int *)out)] = 0;
		out->Floor3btn_requestButton_pressed =  ( in->Floor3btn_requestButton_pressed && in->ctrl_resetFloor3btn ? FALSE :  ( !in->Floor3btn_requestButton_pressed && in->ctrl_resetFloor3btn ? FALSE :  ( in->Floor3btn_requestButton_pressed && !in->ctrl_resetFloor3btn ? TRUE : smv_non_deterministic("Floor3btn_requestButton_pressed",2,FALSE,TRUE) )  )  ) ;
		cpy[((int *)&out->Floor3btn_requestButton_pressed - (int *)out)] = 0;
		out->Floor3btn_location = 30;
		cpy[((int *)&out->Floor3btn_location - (int *)out)] = 0;
		out->door_status =  ( in->ctrl_door_action == open ? open :  ( in->ctrl_door_action == close_ ? closed : in->door_status )  ) ;
		cpy[((int *)&out->door_status - (int *)out)] = 0;
		out->door_door_counter =  ( in->ctrl_door_action == stop ? 0 :  ( in->door_door_counter == 4 ? 4 :  ( in->ctrl_door_action == open ? (in->door_door_counter + 1) : 0 )  )  ) ;
		cpy[((int *)&out->door_door_counter - (int *)out)] = 0;
		out->ctrl_last_dir =  ( ctrl_BUTTON_PRESSED ? ctrl_direction_up : in->ctrl_last_dir ) ;
		cpy[((int *)&out->ctrl_last_dir - (int *)out)] = 0;
		out->ctrl_prev_direction_up =  ( ctrl_BUTTON_PRESSED && in->elevator_position == 20 ? ctrl_direction_up : in->ctrl_prev_direction_up ) ;
		cpy[((int *)&out->ctrl_prev_direction_up - (int *)out)] = 0;
		out->ctrl_resetFloor1btn = smv_non_deterministic("ctrl_resetFloor1btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor1btn - (int *)out)] = 0;
		out->ctrl_resetFloor2btn = smv_non_deterministic("ctrl_resetFloor2btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor2btn - (int *)out)] = 0;
		out->ctrl_resetFloor3btn = smv_non_deterministic("ctrl_resetFloor3btn",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetFloor3btn - (int *)out)] = 0;
		out->ctrl_resetButton1 = smv_non_deterministic("ctrl_resetButton1",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton1 - (int *)out)] = 0;
		out->ctrl_resetButton2 = smv_non_deterministic("ctrl_resetButton2",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton2 - (int *)out)] = 0;
		out->ctrl_resetButton3 = smv_non_deterministic("ctrl_resetButton3",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButton3 - (int *)out)] = 0;
		out->ctrl_resetButtonOpenDoor = smv_non_deterministic("ctrl_resetButtonOpenDoor",2,FALSE,TRUE);
		cpy[((int *)&out->ctrl_resetButtonOpenDoor - (int *)out)] = 0;
		out->ctrl_move_cmd = smv_non_deterministic("ctrl_move_cmd",5,move_up,move_down,stop,wait,nothing);
		cpy[((int *)&out->ctrl_move_cmd - (int *)out)] = 0;
		out->ctrl_door_action = smv_non_deterministic("ctrl_door_action",3,open,close_,nothing);
		cpy[((int *)&out->ctrl_door_action - (int *)out)] = 0;
		transition_labels[0] = 1;
		transition_info.group = 1;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	}
}

int smv_next_state(void* model, int t, state_t *in, void (*callback)(void* arg, transition_info_t *transition_info, state_t *out, int *cpy), void *arg){
	switch(t){
	case 0: {
		if(in->virtual_init){
			return smv_get_actions(model,0,in,callback,arg);
		}
	}
	case 1: {
		if(!((in->virtual_init == TRUE))){
			return smv_get_actions(model,1,in,callback,arg);
		}
	}
	}
}

int smv_get_transition_groups() {
	return 2;
}

int smv_get_label(void* model, int g, state_t* in){
	switch (g){
		case 0: return (in->virtual_init == TRUE)!=0;
		case 1: return !((in->virtual_init == TRUE));
	}
}

int smv_get_label_count() {
	return 2;
}

int *read_m[2] = {
	((int[]){0}),
	((int[]){24,0,19,1,20,2,21,3,22,4,23,5,6,7,8,16,10,17,12,18,14,24,15,25,26})
};

int *write_m[2] = {
	((int[]){28,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,27,15,16,17,18,19,20,21,22,23,24,25,26}),
	((int[]){27,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,25,26,16,17,18,19,20,21,22,23,24})
};

int *label_m[2] = {
	((int[]){1,27}),
	((int[]){1,27})
};

int state_label_many(void* model, int * src, int * label, int guards_only) {
	(void)model;
	return 0;
}
void sl_group (model_t model, sl_group_enum_t group, int*src, int *label)
	{
	state_label_many (model, src, label, group == GB_SL_GUARDS);
	(void) group;
	}
void sl_all (model_t model, int*src, int *label)
	{
	state_label_many (model, src, label, 0);
	}
char pins_plugin_name[] = "elevatort";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"elevator_button1_pressed");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"elevator_button2_pressed");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"elevator_button3_pressed");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"elevator_buttonOpenDoor_pressed");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"elevator_moving");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"elevator_position");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"elevator_waiting");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"elevator_move_counter");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"Floor1btn_requestButton_pressed");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"Floor1btn_location");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"Floor2btn_requestButton_pressed");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"Floor2btn_location");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"Floor3btn_requestButton_pressed");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"Floor3btn_location");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"door_status");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"door_door_counter");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"ctrl_resetFloor1btn");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"ctrl_resetFloor2btn");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"ctrl_resetFloor3btn");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"ctrl_resetButton1");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"ctrl_resetButton2");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"ctrl_resetButton3");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"ctrl_resetButtonOpenDoor");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"ctrl_move_cmd");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"ctrl_door_action");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"ctrl_last_dir");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"ctrl_prev_direction_up");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"virtual_init");
	lts_type_set_state_typeno(ltstype, 27,int_type);

	// add an action type for edge labels
	int action_type = lts_type_add_type(ltstype, "action", NULL);
	lts_type_set_format (ltstype, action_type, LTStypeEnum);
	lts_type_set_edge_label_count (ltstype, 1);
	lts_type_set_edge_label_name(ltstype, 0, "action");
	lts_type_set_edge_label_type(ltstype, 0, "action");
	lts_type_set_edge_label_typeno(ltstype, 0, action_type);

	// add bool type for state labels
	int bool_type = lts_type_put_type (ltstype, "boolean", LTStypeBool, NULL);
	lts_type_set_state_label_count (ltstype, smv_get_label_count());
	lts_type_set_state_label_typeno (ltstype, 0, bool_type);
	lts_type_set_state_label_name (ltstype, 0, "init");
	lts_type_set_state_label_typeno (ltstype, 1, bool_type);
	lts_type_set_state_label_name (ltstype, 1, "next");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("next"));
	int state[28];
	smv_get_initial_state(state);
	GBsetInitialState(m,state);
	GBsetNextStateLong(m, (next_method_grey_t) smv_next_state);
	GBsetStateLabelLong(m, (get_label_method_t) smv_get_label);
	matrix_t *cm = malloc(sizeof(matrix_t));
	dm_create(cm, smv_get_transition_groups(), smv_get_state_size());
	matrix_t *rm = malloc(sizeof(matrix_t));
	dm_create(rm, smv_get_transition_groups(), smv_get_state_size());
	for (int i = 0; i < smv_get_transition_groups(); i++) {
		int sz = read_m[i][0];
		for (int j = 1; j < sz + 1; j++) {
			int indj = read_m[i][j];
			dm_set(cm, i, indj);
			dm_set(rm, i, indj);
		}
	}
	GBsetDMInfoRead(m, rm);
	matrix_t *wm = malloc(sizeof(matrix_t));
	dm_create(wm, smv_get_transition_groups(), smv_get_state_size());
	for (int i = 0; i < smv_get_transition_groups(); i++) {
		int sz = write_m[i][0];
		for (int j = 1; j < sz + 1; j++) {
			int indj = write_m[i][j];
			dm_set(cm, i, indj);
			dm_set(wm, i, indj);
		}
	}
	GBsetDMInfoMustWrite(m, wm);
	GBsetDMInfo(m, cm);
	matrix_t *lm = malloc(sizeof(matrix_t));
	dm_create(lm, smv_get_label_count(), smv_get_state_size());
	for (int i = 0; i < smv_get_label_count(); i++) {
		int sz = label_m[i][0];
		for (int j = 1; j < sz + 1; j++) {
			dm_set(lm, i, label_m[i][j]);
	  }
	}
	GBsetStateLabelInfo(m, lm);
	int sl_size = smv_get_label_count();
	sl_group_t* sl_group_all = malloc(sizeof(sl_group_t) + sl_size * sizeof(int));
	sl_group_all->count = sl_size;
	for(int i=0; i < sl_group_all->count; i++) sl_group_all->sl_idx[i] = i;
	GBsetStateLabelGroupInfo(m, GB_SL_ALL, sl_group_all);
	GBsetStateLabelsGroup(m, sl_group);
}
