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
	 ready, busy, thinking, eating,
}smv_enum;

const int smv_get_state_size() {
	return 43;
}

typedef struct state_t {
	smv_enum fork0;
	smv_enum fork1;
	smv_enum fork2;
	smv_enum fork3;
	smv_enum fork4;
	smv_enum fork5;
	smv_enum fork6;
	smv_enum fork7;
	smv_enum fork8;
	smv_enum fork9;
	smv_enum fork10;
	smv_enum fork11;
	smv_enum fork12;
	smv_enum fork13;
	smv_enum phil0_state;
	boolean phil0_running;
	smv_enum phil1_state;
	boolean phil1_running;
	smv_enum phil2_state;
	boolean phil2_running;
	smv_enum phil3_state;
	boolean phil3_running;
	smv_enum phil4_state;
	boolean phil4_running;
	smv_enum phil5_state;
	boolean phil5_running;
	smv_enum phil6_state;
	boolean phil6_running;
	smv_enum phil7_state;
	boolean phil7_running;
	smv_enum phil8_state;
	boolean phil8_running;
	smv_enum phil9_state;
	boolean phil9_running;
	smv_enum phil10_state;
	boolean phil10_running;
	smv_enum phil11_state;
	boolean phil11_running;
	smv_enum phil12_state;
	boolean phil12_running;
	smv_enum phil13_state;
	boolean phil13_running;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.fork0                                  = 0,
	.fork1                                  = 0,
	.fork2                                  = 0,
	.fork3                                  = 0,
	.fork4                                  = 0,
	.fork5                                  = 0,
	.fork6                                  = 0,
	.fork7                                  = 0,
	.fork8                                  = 0,
	.fork9                                  = 0,
	.fork10                                 = 0,
	.fork11                                 = 0,
	.fork12                                 = 0,
	.fork13                                 = 0,
	.phil0_state                            = 0,
	.phil0_running                          = FALSE,
	.phil1_state                            = 0,
	.phil1_running                          = FALSE,
	.phil2_state                            = 0,
	.phil2_running                          = FALSE,
	.phil3_state                            = 0,
	.phil3_running                          = FALSE,
	.phil4_state                            = 0,
	.phil4_running                          = FALSE,
	.phil5_state                            = 0,
	.phil5_running                          = FALSE,
	.phil6_state                            = 0,
	.phil6_running                          = FALSE,
	.phil7_state                            = 0,
	.phil7_running                          = FALSE,
	.phil8_state                            = 0,
	.phil8_running                          = FALSE,
	.phil9_state                            = 0,
	.phil9_running                          = FALSE,
	.phil10_state                           = 0,
	.phil10_running                         = FALSE,
	.phil11_state                           = 0,
	.phil11_running                         = FALSE,
	.phil12_state                           = 0,
	.phil12_running                         = FALSE,
	.phil13_state                           = 0,
	.phil13_running                         = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"fork0",1,0x0},
	{"fork1",1,0x0},
	{"fork2",1,0x0},
	{"fork3",1,0x0},
	{"fork4",1,0x0},
	{"fork5",1,0x0},
	{"fork6",1,0x0},
	{"fork7",1,0x0},
	{"fork8",1,0x0},
	{"fork9",1,0x0},
	{"fork10",1,0x0},
	{"fork11",1,0x0},
	{"fork12",1,0x0},
	{"fork13",1,0x0},
	{"phil0_state",1,0x0},
	{"phil0_running",1,0x0},
	{"phil1_state",1,0x0},
	{"phil1_running",1,0x0},
	{"phil2_state",1,0x0},
	{"phil2_running",1,0x0},
	{"phil3_state",1,0x0},
	{"phil3_running",1,0x0},
	{"phil4_state",1,0x0},
	{"phil4_running",1,0x0},
	{"phil5_state",1,0x0},
	{"phil5_running",1,0x0},
	{"phil6_state",1,0x0},
	{"phil6_running",1,0x0},
	{"phil7_state",1,0x0},
	{"phil7_running",1,0x0},
	{"phil8_state",1,0x0},
	{"phil8_running",1,0x0},
	{"phil9_state",1,0x0},
	{"phil9_running",1,0x0},
	{"phil10_state",1,0x0},
	{"phil10_running",1,0x0},
	{"phil11_state",1,0x0},
	{"phil11_running",1,0x0},
	{"phil12_state",1,0x0},
	{"phil12_running",1,0x0},
	{"phil13_state",1,0x0},
	{"phil13_running",1,0x0},
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
	int cpy[43] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int donoteat;
		donoteat = in->phil0_state == thinking;
		out->fork0 = ready;
		cpy[((int *)&out->fork0 - (int *)out)] = 0;
		out->fork1 = ready;
		cpy[((int *)&out->fork1 - (int *)out)] = 0;
		out->fork2 = ready;
		cpy[((int *)&out->fork2 - (int *)out)] = 0;
		out->fork3 = ready;
		cpy[((int *)&out->fork3 - (int *)out)] = 0;
		out->fork4 = ready;
		cpy[((int *)&out->fork4 - (int *)out)] = 0;
		out->fork5 = ready;
		cpy[((int *)&out->fork5 - (int *)out)] = 0;
		out->fork6 = ready;
		cpy[((int *)&out->fork6 - (int *)out)] = 0;
		out->fork7 = ready;
		cpy[((int *)&out->fork7 - (int *)out)] = 0;
		out->fork8 = ready;
		cpy[((int *)&out->fork8 - (int *)out)] = 0;
		out->fork9 = ready;
		cpy[((int *)&out->fork9 - (int *)out)] = 0;
		out->fork10 = ready;
		cpy[((int *)&out->fork10 - (int *)out)] = 0;
		out->fork11 = ready;
		cpy[((int *)&out->fork11 - (int *)out)] = 0;
		out->fork12 = ready;
		cpy[((int *)&out->fork12 - (int *)out)] = 0;
		out->fork13 = ready;
		cpy[((int *)&out->fork13 - (int *)out)] = 0;
		out->phil0_state = thinking;
		cpy[((int *)&out->phil0_state - (int *)out)] = 0;
		out->phil1_state = thinking;
		cpy[((int *)&out->phil1_state - (int *)out)] = 0;
		out->phil2_state = thinking;
		cpy[((int *)&out->phil2_state - (int *)out)] = 0;
		out->phil3_state = thinking;
		cpy[((int *)&out->phil3_state - (int *)out)] = 0;
		out->phil4_state = thinking;
		cpy[((int *)&out->phil4_state - (int *)out)] = 0;
		out->phil5_state = thinking;
		cpy[((int *)&out->phil5_state - (int *)out)] = 0;
		out->phil6_state = thinking;
		cpy[((int *)&out->phil6_state - (int *)out)] = 0;
		out->phil7_state = thinking;
		cpy[((int *)&out->phil7_state - (int *)out)] = 0;
		out->phil8_state = thinking;
		cpy[((int *)&out->phil8_state - (int *)out)] = 0;
		out->phil9_state = thinking;
		cpy[((int *)&out->phil9_state - (int *)out)] = 0;
		out->phil10_state = thinking;
		cpy[((int *)&out->phil10_state - (int *)out)] = 0;
		out->phil11_state = thinking;
		cpy[((int *)&out->phil11_state - (int *)out)] = 0;
		out->phil12_state = thinking;
		cpy[((int *)&out->phil12_state - (int *)out)] = 0;
		out->phil13_state = thinking;
		cpy[((int *)&out->phil13_state - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		out->phil0_running = FALSE;
		cpy[((int *)&out->phil0_running - (int *)out)] = 0;
		out->phil0_state =  ( (in->phil0_state == thinking && in->fork0 == ready && in->fork1 == ready) ? eating :  ( (in->phil0_state == eating) ? thinking : in->phil0_state )  ) ;
		cpy[((int *)&out->phil0_state - (int *)out)] = 0;
		out->fork0 =  ( (in->fork0 == ready) ? busy :  ( (in->fork0 == busy) ? ready : in->fork0 )  ) ;
		cpy[((int *)&out->fork0 - (int *)out)] = 0;
		out->fork1 =  ( (in->fork1 == ready) ? busy :  ( (in->fork1 == busy) ? ready : in->fork1 )  ) ;
		cpy[((int *)&out->fork1 - (int *)out)] = 0;
		transition_labels[0] = 1;
		transition_info.group = 1;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 2: {
		memcpy(out, in, sizeof(state_t));
		out->phil1_running = FALSE;
		cpy[((int *)&out->phil1_running - (int *)out)] = 0;
		out->phil1_state =  ( (in->phil1_state == thinking && in->fork1 == ready && in->fork2 == ready) ? eating :  ( (in->phil1_state == eating) ? thinking : in->phil1_state )  ) ;
		cpy[((int *)&out->phil1_state - (int *)out)] = 0;
		out->fork1 =  ( (in->fork1 == ready) ? busy :  ( (in->fork1 == busy) ? ready : in->fork1 )  ) ;
		cpy[((int *)&out->fork1 - (int *)out)] = 0;
		out->fork2 =  ( (in->fork2 == ready) ? busy :  ( (in->fork2 == busy) ? ready : in->fork2 )  ) ;
		cpy[((int *)&out->fork2 - (int *)out)] = 0;
		transition_labels[0] = 2;
		transition_info.group = 2;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 3: {
		memcpy(out, in, sizeof(state_t));
		out->phil2_running = FALSE;
		cpy[((int *)&out->phil2_running - (int *)out)] = 0;
		out->phil2_state =  ( (in->phil2_state == thinking && in->fork2 == ready && in->fork3 == ready) ? eating :  ( (in->phil2_state == eating) ? thinking : in->phil2_state )  ) ;
		cpy[((int *)&out->phil2_state - (int *)out)] = 0;
		out->fork2 =  ( (in->fork2 == ready) ? busy :  ( (in->fork2 == busy) ? ready : in->fork2 )  ) ;
		cpy[((int *)&out->fork2 - (int *)out)] = 0;
		out->fork3 =  ( (in->fork3 == ready) ? busy :  ( (in->fork3 == busy) ? ready : in->fork3 )  ) ;
		cpy[((int *)&out->fork3 - (int *)out)] = 0;
		transition_labels[0] = 3;
		transition_info.group = 3;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 4: {
		memcpy(out, in, sizeof(state_t));
		out->phil3_running = FALSE;
		cpy[((int *)&out->phil3_running - (int *)out)] = 0;
		out->phil3_state =  ( (in->phil3_state == thinking && in->fork3 == ready && in->fork4 == ready) ? eating :  ( (in->phil3_state == eating) ? thinking : in->phil3_state )  ) ;
		cpy[((int *)&out->phil3_state - (int *)out)] = 0;
		out->fork3 =  ( (in->fork3 == ready) ? busy :  ( (in->fork3 == busy) ? ready : in->fork3 )  ) ;
		cpy[((int *)&out->fork3 - (int *)out)] = 0;
		out->fork4 =  ( (in->fork4 == ready) ? busy :  ( (in->fork4 == busy) ? ready : in->fork4 )  ) ;
		cpy[((int *)&out->fork4 - (int *)out)] = 0;
		transition_labels[0] = 4;
		transition_info.group = 4;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 5: {
		memcpy(out, in, sizeof(state_t));
		out->phil4_running = FALSE;
		cpy[((int *)&out->phil4_running - (int *)out)] = 0;
		out->phil4_state =  ( (in->phil4_state == thinking && in->fork4 == ready && in->fork5 == ready) ? eating :  ( (in->phil4_state == eating) ? thinking : in->phil4_state )  ) ;
		cpy[((int *)&out->phil4_state - (int *)out)] = 0;
		out->fork4 =  ( (in->fork4 == ready) ? busy :  ( (in->fork4 == busy) ? ready : in->fork4 )  ) ;
		cpy[((int *)&out->fork4 - (int *)out)] = 0;
		out->fork5 =  ( (in->fork5 == ready) ? busy :  ( (in->fork5 == busy) ? ready : in->fork5 )  ) ;
		cpy[((int *)&out->fork5 - (int *)out)] = 0;
		transition_labels[0] = 5;
		transition_info.group = 5;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 6: {
		memcpy(out, in, sizeof(state_t));
		out->phil5_running = FALSE;
		cpy[((int *)&out->phil5_running - (int *)out)] = 0;
		out->phil5_state =  ( (in->phil5_state == thinking && in->fork5 == ready && in->fork6 == ready) ? eating :  ( (in->phil5_state == eating) ? thinking : in->phil5_state )  ) ;
		cpy[((int *)&out->phil5_state - (int *)out)] = 0;
		out->fork5 =  ( (in->fork5 == ready) ? busy :  ( (in->fork5 == busy) ? ready : in->fork5 )  ) ;
		cpy[((int *)&out->fork5 - (int *)out)] = 0;
		out->fork6 =  ( (in->fork6 == ready) ? busy :  ( (in->fork6 == busy) ? ready : in->fork6 )  ) ;
		cpy[((int *)&out->fork6 - (int *)out)] = 0;
		transition_labels[0] = 6;
		transition_info.group = 6;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 7: {
		memcpy(out, in, sizeof(state_t));
		out->phil6_running = FALSE;
		cpy[((int *)&out->phil6_running - (int *)out)] = 0;
		out->phil6_state =  ( (in->phil6_state == thinking && in->fork6 == ready && in->fork7 == ready) ? eating :  ( (in->phil6_state == eating) ? thinking : in->phil6_state )  ) ;
		cpy[((int *)&out->phil6_state - (int *)out)] = 0;
		out->fork6 =  ( (in->fork6 == ready) ? busy :  ( (in->fork6 == busy) ? ready : in->fork6 )  ) ;
		cpy[((int *)&out->fork6 - (int *)out)] = 0;
		out->fork7 =  ( (in->fork7 == ready) ? busy :  ( (in->fork7 == busy) ? ready : in->fork7 )  ) ;
		cpy[((int *)&out->fork7 - (int *)out)] = 0;
		transition_labels[0] = 7;
		transition_info.group = 7;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 8: {
		memcpy(out, in, sizeof(state_t));
		out->phil7_running = FALSE;
		cpy[((int *)&out->phil7_running - (int *)out)] = 0;
		out->phil7_state =  ( (in->phil7_state == thinking && in->fork7 == ready && in->fork8 == ready) ? eating :  ( (in->phil7_state == eating) ? thinking : in->phil7_state )  ) ;
		cpy[((int *)&out->phil7_state - (int *)out)] = 0;
		out->fork7 =  ( (in->fork7 == ready) ? busy :  ( (in->fork7 == busy) ? ready : in->fork7 )  ) ;
		cpy[((int *)&out->fork7 - (int *)out)] = 0;
		out->fork8 =  ( (in->fork8 == ready) ? busy :  ( (in->fork8 == busy) ? ready : in->fork8 )  ) ;
		cpy[((int *)&out->fork8 - (int *)out)] = 0;
		transition_labels[0] = 8;
		transition_info.group = 8;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 9: {
		memcpy(out, in, sizeof(state_t));
		out->phil8_running = FALSE;
		cpy[((int *)&out->phil8_running - (int *)out)] = 0;
		out->phil8_state =  ( (in->phil8_state == thinking && in->fork8 == ready && in->fork9 == ready) ? eating :  ( (in->phil8_state == eating) ? thinking : in->phil8_state )  ) ;
		cpy[((int *)&out->phil8_state - (int *)out)] = 0;
		out->fork8 =  ( (in->fork8 == ready) ? busy :  ( (in->fork8 == busy) ? ready : in->fork8 )  ) ;
		cpy[((int *)&out->fork8 - (int *)out)] = 0;
		out->fork9 =  ( (in->fork9 == ready) ? busy :  ( (in->fork9 == busy) ? ready : in->fork9 )  ) ;
		cpy[((int *)&out->fork9 - (int *)out)] = 0;
		transition_labels[0] = 9;
		transition_info.group = 9;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 10: {
		memcpy(out, in, sizeof(state_t));
		out->phil9_running = FALSE;
		cpy[((int *)&out->phil9_running - (int *)out)] = 0;
		out->phil9_state =  ( (in->phil9_state == thinking && in->fork9 == ready && in->fork10 == ready) ? eating :  ( (in->phil9_state == eating) ? thinking : in->phil9_state )  ) ;
		cpy[((int *)&out->phil9_state - (int *)out)] = 0;
		out->fork9 =  ( (in->fork9 == ready) ? busy :  ( (in->fork9 == busy) ? ready : in->fork9 )  ) ;
		cpy[((int *)&out->fork9 - (int *)out)] = 0;
		out->fork10 =  ( (in->fork10 == ready) ? busy :  ( (in->fork10 == busy) ? ready : in->fork10 )  ) ;
		cpy[((int *)&out->fork10 - (int *)out)] = 0;
		transition_labels[0] = 10;
		transition_info.group = 10;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 11: {
		memcpy(out, in, sizeof(state_t));
		out->phil10_running = FALSE;
		cpy[((int *)&out->phil10_running - (int *)out)] = 0;
		out->phil10_state =  ( (in->phil10_state == thinking && in->fork10 == ready && in->fork11 == ready) ? eating :  ( (in->phil10_state == eating) ? thinking : in->phil10_state )  ) ;
		cpy[((int *)&out->phil10_state - (int *)out)] = 0;
		out->fork10 =  ( (in->fork10 == ready) ? busy :  ( (in->fork10 == busy) ? ready : in->fork10 )  ) ;
		cpy[((int *)&out->fork10 - (int *)out)] = 0;
		out->fork11 =  ( (in->fork11 == ready) ? busy :  ( (in->fork11 == busy) ? ready : in->fork11 )  ) ;
		cpy[((int *)&out->fork11 - (int *)out)] = 0;
		transition_labels[0] = 11;
		transition_info.group = 11;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 12: {
		memcpy(out, in, sizeof(state_t));
		out->phil11_running = FALSE;
		cpy[((int *)&out->phil11_running - (int *)out)] = 0;
		out->phil11_state =  ( (in->phil11_state == thinking && in->fork11 == ready && in->fork12 == ready) ? eating :  ( (in->phil11_state == eating) ? thinking : in->phil11_state )  ) ;
		cpy[((int *)&out->phil11_state - (int *)out)] = 0;
		out->fork11 =  ( (in->fork11 == ready) ? busy :  ( (in->fork11 == busy) ? ready : in->fork11 )  ) ;
		cpy[((int *)&out->fork11 - (int *)out)] = 0;
		out->fork12 =  ( (in->fork12 == ready) ? busy :  ( (in->fork12 == busy) ? ready : in->fork12 )  ) ;
		cpy[((int *)&out->fork12 - (int *)out)] = 0;
		transition_labels[0] = 12;
		transition_info.group = 12;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 13: {
		memcpy(out, in, sizeof(state_t));
		out->phil12_running = FALSE;
		cpy[((int *)&out->phil12_running - (int *)out)] = 0;
		out->phil12_state =  ( (in->phil12_state == thinking && in->fork12 == ready && in->fork13 == ready) ? eating :  ( (in->phil12_state == eating) ? thinking : in->phil12_state )  ) ;
		cpy[((int *)&out->phil12_state - (int *)out)] = 0;
		out->fork12 =  ( (in->fork12 == ready) ? busy :  ( (in->fork12 == busy) ? ready : in->fork12 )  ) ;
		cpy[((int *)&out->fork12 - (int *)out)] = 0;
		out->fork13 =  ( (in->fork13 == ready) ? busy :  ( (in->fork13 == busy) ? ready : in->fork13 )  ) ;
		cpy[((int *)&out->fork13 - (int *)out)] = 0;
		transition_labels[0] = 13;
		transition_info.group = 13;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 14: {
		memcpy(out, in, sizeof(state_t));
		out->phil13_running = FALSE;
		cpy[((int *)&out->phil13_running - (int *)out)] = 0;
		out->phil13_state =  ( (in->phil13_state == thinking && in->fork13 == ready && in->fork0 == ready) ? eating :  ( (in->phil13_state == eating) ? thinking : in->phil13_state )  ) ;
		cpy[((int *)&out->phil13_state - (int *)out)] = 0;
		out->fork13 =  ( (in->fork13 == ready) ? busy :  ( (in->fork13 == busy) ? ready : in->fork13 )  ) ;
		cpy[((int *)&out->fork13 - (int *)out)] = 0;
		out->fork0 =  ( (in->fork0 == ready) ? busy :  ( (in->fork0 == busy) ? ready : in->fork0 )  ) ;
		cpy[((int *)&out->fork0 - (int *)out)] = 0;
		transition_labels[0] = 14;
		transition_info.group = 14;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 15: {
		memcpy(out, in, sizeof(state_t));
		transition_labels[0] = 15;
		transition_info.group = 15;
		out->phil0_running= TRUE;
		cpy[((int *)&out->phil0_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil0_running= FALSE;
		cpy[((int *)&out->phil0_running - (int *)out)] = 1;
		out->phil1_running= TRUE;
		cpy[((int *)&out->phil1_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil1_running= FALSE;
		cpy[((int *)&out->phil1_running - (int *)out)] = 1;
		out->phil2_running= TRUE;
		cpy[((int *)&out->phil2_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil2_running= FALSE;
		cpy[((int *)&out->phil2_running - (int *)out)] = 1;
		out->phil3_running= TRUE;
		cpy[((int *)&out->phil3_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil3_running= FALSE;
		cpy[((int *)&out->phil3_running - (int *)out)] = 1;
		out->phil4_running= TRUE;
		cpy[((int *)&out->phil4_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil4_running= FALSE;
		cpy[((int *)&out->phil4_running - (int *)out)] = 1;
		out->phil5_running= TRUE;
		cpy[((int *)&out->phil5_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil5_running= FALSE;
		cpy[((int *)&out->phil5_running - (int *)out)] = 1;
		out->phil6_running= TRUE;
		cpy[((int *)&out->phil6_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil6_running= FALSE;
		cpy[((int *)&out->phil6_running - (int *)out)] = 1;
		out->phil7_running= TRUE;
		cpy[((int *)&out->phil7_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil7_running= FALSE;
		cpy[((int *)&out->phil7_running - (int *)out)] = 1;
		out->phil8_running= TRUE;
		cpy[((int *)&out->phil8_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil8_running= FALSE;
		cpy[((int *)&out->phil8_running - (int *)out)] = 1;
		out->phil9_running= TRUE;
		cpy[((int *)&out->phil9_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil9_running= FALSE;
		cpy[((int *)&out->phil9_running - (int *)out)] = 1;
		out->phil10_running= TRUE;
		cpy[((int *)&out->phil10_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil10_running= FALSE;
		cpy[((int *)&out->phil10_running - (int *)out)] = 1;
		out->phil11_running= TRUE;
		cpy[((int *)&out->phil11_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil11_running= FALSE;
		cpy[((int *)&out->phil11_running - (int *)out)] = 1;
		out->phil12_running= TRUE;
		cpy[((int *)&out->phil12_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->phil12_running= FALSE;
		cpy[((int *)&out->phil12_running - (int *)out)] = 1;
		out->phil13_running= TRUE;
		cpy[((int *)&out->phil13_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		return 14;
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
		if(in->phil0_running == TRUE){
			smv_get_actions(model,1,in,callback,arg);
		}
	}
	case 2: {
		if(in->phil1_running == TRUE){
			smv_get_actions(model,2,in,callback,arg);
		}
	}
	case 3: {
		if(in->phil2_running == TRUE){
			smv_get_actions(model,3,in,callback,arg);
		}
	}
	case 4: {
		if(in->phil3_running == TRUE){
			smv_get_actions(model,4,in,callback,arg);
		}
	}
	case 5: {
		if(in->phil4_running == TRUE){
			smv_get_actions(model,5,in,callback,arg);
		}
	}
	case 6: {
		if(in->phil5_running == TRUE){
			smv_get_actions(model,6,in,callback,arg);
		}
	}
	case 7: {
		if(in->phil6_running == TRUE){
			smv_get_actions(model,7,in,callback,arg);
		}
	}
	case 8: {
		if(in->phil7_running == TRUE){
			smv_get_actions(model,8,in,callback,arg);
		}
	}
	case 9: {
		if(in->phil8_running == TRUE){
			smv_get_actions(model,9,in,callback,arg);
		}
	}
	case 10: {
		if(in->phil9_running == TRUE){
			smv_get_actions(model,10,in,callback,arg);
		}
	}
	case 11: {
		if(in->phil10_running == TRUE){
			smv_get_actions(model,11,in,callback,arg);
		}
	}
	case 12: {
		if(in->phil11_running == TRUE){
			smv_get_actions(model,12,in,callback,arg);
		}
	}
	case 13: {
		if(in->phil12_running == TRUE){
			smv_get_actions(model,13,in,callback,arg);
		}
	}
	case 14: {
		if(in->phil13_running == TRUE){
			smv_get_actions(model,14,in,callback,arg);
		}
	}
	case 15: {
		if(!((in->virtual_init == TRUE)||(in->phil0_running == TRUE)||(in->phil1_running == TRUE)||(in->phil2_running == TRUE)||(in->phil3_running == TRUE)||(in->phil4_running == TRUE)||(in->phil5_running == TRUE)||(in->phil6_running == TRUE)||(in->phil7_running == TRUE)||(in->phil8_running == TRUE)||(in->phil9_running == TRUE)||(in->phil10_running == TRUE)||(in->phil11_running == TRUE)||(in->phil12_running == TRUE)||(in->phil13_running == TRUE))){
			return smv_get_actions(model,15,in,callback,arg);
		}
	}
	}
}

int smv_get_transition_groups() {
	return 16;
}

int smv_get_label(void* model, int g, state_t* in){
	switch (g){
		case 0: return (in->virtual_init == TRUE)!=0;
		case 1: return (in->phil0_running == TRUE) !=0;
		case 2: return (in->phil1_running == TRUE) !=0;
		case 3: return (in->phil2_running == TRUE) !=0;
		case 4: return (in->phil3_running == TRUE) !=0;
		case 5: return (in->phil4_running == TRUE) !=0;
		case 6: return (in->phil5_running == TRUE) !=0;
		case 7: return (in->phil6_running == TRUE) !=0;
		case 8: return (in->phil7_running == TRUE) !=0;
		case 9: return (in->phil8_running == TRUE) !=0;
		case 10: return (in->phil9_running == TRUE) !=0;
		case 11: return (in->phil10_running == TRUE) !=0;
		case 12: return (in->phil11_running == TRUE) !=0;
		case 13: return (in->phil12_running == TRUE) !=0;
		case 14: return (in->phil13_running == TRUE) !=0;
		case 15: return !((in->virtual_init == TRUE)||(in->phil0_running == TRUE)||(in->phil1_running == TRUE)||(in->phil2_running == TRUE)||(in->phil3_running == TRUE)||(in->phil4_running == TRUE)||(in->phil5_running == TRUE)||(in->phil6_running == TRUE)||(in->phil7_running == TRUE)||(in->phil8_running == TRUE)||(in->phil9_running == TRUE)||(in->phil10_running == TRUE)||(in->phil11_running == TRUE)||(in->phil12_running == TRUE)||(in->phil13_running == TRUE));
	}
}

int smv_get_label_count() {
	return 16;
}

int *read_m[16] = {
	((int[]){0}),
	((int[]){3,0,1,14}),
	((int[]){3,1,2,16}),
	((int[]){3,2,3,18}),
	((int[]){3,3,4,20}),
	((int[]){3,4,5,22}),
	((int[]){3,5,6,24}),
	((int[]){3,6,7,26}),
	((int[]){3,7,8,28}),
	((int[]){3,8,9,30}),
	((int[]){4,1,9,10,32}),
	((int[]){4,1,10,11,34}),
	((int[]){4,1,11,12,36}),
	((int[]){4,1,12,13,38}),
	((int[]){4,0,1,13,40}),
	((int[]){0})
};

int *write_m[16] = {
	((int[]){29,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42}),
	((int[]){4,15,14,0,1}),
	((int[]){4,17,16,1,2}),
	((int[]){4,19,18,2,3}),
	((int[]){4,21,20,3,4}),
	((int[]){4,23,22,4,5}),
	((int[]){4,25,24,5,6}),
	((int[]){4,27,26,6,7}),
	((int[]){4,29,28,7,8}),
	((int[]){4,31,30,8,9}),
	((int[]){4,33,32,9,10}),
	((int[]){4,35,34,10,11}),
	((int[]){4,37,36,11,12}),
	((int[]){4,39,38,12,13}),
	((int[]){4,41,40,13,0}),
	((int[]){14,15,17,19,21,23,25,27,29,31,33,35,37,39,41})
};

int *label_m[16] = {
	((int[]){1,42}),
	((int[]){1,15}),
	((int[]){1,17}),
	((int[]){1,19}),
	((int[]){1,21}),
	((int[]){1,23}),
	((int[]){1,25}),
	((int[]){1,27}),
	((int[]){1,29}),
	((int[]){1,31}),
	((int[]){1,33}),
	((int[]){1,35}),
	((int[]){1,37}),
	((int[]){1,39}),
	((int[]){1,41}),
	((int[]){15,15,17,19,21,23,25,27,29,31,33,35,37,39,41,42})
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
char pins_plugin_name[] = "phils";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"fork0");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"fork1");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"fork2");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"fork3");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"fork4");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"fork5");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"fork6");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"fork7");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"fork8");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"fork9");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"fork10");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"fork11");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"fork12");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"fork13");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"phil0_state");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"phil0_running");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"phil1_state");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"phil1_running");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"phil2_state");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"phil2_running");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"phil3_state");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"phil3_running");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"phil4_state");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"phil4_running");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"phil5_state");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"phil5_running");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"phil6_state");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"phil6_running");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"phil7_state");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"phil7_running");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"phil8_state");
	lts_type_set_state_typeno(ltstype, 30,int_type);
	lts_type_set_state_name(ltstype, 31,"phil8_running");
	lts_type_set_state_typeno(ltstype, 31,int_type);
	lts_type_set_state_name(ltstype, 32,"phil9_state");
	lts_type_set_state_typeno(ltstype, 32,int_type);
	lts_type_set_state_name(ltstype, 33,"phil9_running");
	lts_type_set_state_typeno(ltstype, 33,int_type);
	lts_type_set_state_name(ltstype, 34,"phil10_state");
	lts_type_set_state_typeno(ltstype, 34,int_type);
	lts_type_set_state_name(ltstype, 35,"phil10_running");
	lts_type_set_state_typeno(ltstype, 35,int_type);
	lts_type_set_state_name(ltstype, 36,"phil11_state");
	lts_type_set_state_typeno(ltstype, 36,int_type);
	lts_type_set_state_name(ltstype, 37,"phil11_running");
	lts_type_set_state_typeno(ltstype, 37,int_type);
	lts_type_set_state_name(ltstype, 38,"phil12_state");
	lts_type_set_state_typeno(ltstype, 38,int_type);
	lts_type_set_state_name(ltstype, 39,"phil12_running");
	lts_type_set_state_typeno(ltstype, 39,int_type);
	lts_type_set_state_name(ltstype, 40,"phil13_state");
	lts_type_set_state_typeno(ltstype, 40,int_type);
	lts_type_set_state_name(ltstype, 41,"phil13_running");
	lts_type_set_state_typeno(ltstype, 41,int_type);
	lts_type_set_state_name(ltstype, 42,"virtual_init");
	lts_type_set_state_typeno(ltstype, 42,int_type);

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
	lts_type_set_state_label_name (ltstype, 1, "now_phil0_running");
	lts_type_set_state_label_typeno (ltstype, 2, bool_type);
	lts_type_set_state_label_name (ltstype, 2, "now_phil1_running");
	lts_type_set_state_label_typeno (ltstype, 3, bool_type);
	lts_type_set_state_label_name (ltstype, 3, "now_phil2_running");
	lts_type_set_state_label_typeno (ltstype, 4, bool_type);
	lts_type_set_state_label_name (ltstype, 4, "now_phil3_running");
	lts_type_set_state_label_typeno (ltstype, 5, bool_type);
	lts_type_set_state_label_name (ltstype, 5, "now_phil4_running");
	lts_type_set_state_label_typeno (ltstype, 6, bool_type);
	lts_type_set_state_label_name (ltstype, 6, "now_phil5_running");
	lts_type_set_state_label_typeno (ltstype, 7, bool_type);
	lts_type_set_state_label_name (ltstype, 7, "now_phil6_running");
	lts_type_set_state_label_typeno (ltstype, 8, bool_type);
	lts_type_set_state_label_name (ltstype, 8, "now_phil7_running");
	lts_type_set_state_label_typeno (ltstype, 9, bool_type);
	lts_type_set_state_label_name (ltstype, 9, "now_phil8_running");
	lts_type_set_state_label_typeno (ltstype, 10, bool_type);
	lts_type_set_state_label_name (ltstype, 10, "now_phil9_running");
	lts_type_set_state_label_typeno (ltstype, 11, bool_type);
	lts_type_set_state_label_name (ltstype, 11, "now_phil10_running");
	lts_type_set_state_label_typeno (ltstype, 12, bool_type);
	lts_type_set_state_label_name (ltstype, 12, "now_phil11_running");
	lts_type_set_state_label_typeno (ltstype, 13, bool_type);
	lts_type_set_state_label_name (ltstype, 13, "now_phil12_running");
	lts_type_set_state_label_typeno (ltstype, 14, bool_type);
	lts_type_set_state_label_name (ltstype, 14, "now_phil13_running");
	lts_type_set_state_label_typeno (ltstype, 15, bool_type);
	lts_type_set_state_label_name (ltstype, 15, "choose_running");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("phil0_running"));
	pins_chunk_put(m, action_type, chunk_str("phil1_running"));
	pins_chunk_put(m, action_type, chunk_str("phil2_running"));
	pins_chunk_put(m, action_type, chunk_str("phil3_running"));
	pins_chunk_put(m, action_type, chunk_str("phil4_running"));
	pins_chunk_put(m, action_type, chunk_str("phil5_running"));
	pins_chunk_put(m, action_type, chunk_str("phil6_running"));
	pins_chunk_put(m, action_type, chunk_str("phil7_running"));
	pins_chunk_put(m, action_type, chunk_str("phil8_running"));
	pins_chunk_put(m, action_type, chunk_str("phil9_running"));
	pins_chunk_put(m, action_type, chunk_str("phil10_running"));
	pins_chunk_put(m, action_type, chunk_str("phil11_running"));
	pins_chunk_put(m, action_type, chunk_str("phil12_running"));
	pins_chunk_put(m, action_type, chunk_str("phil13_running"));
	pins_chunk_put(m, action_type, chunk_str("choose_running"));
	int state[43];
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
