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

const int smv_get_state_size() {
	return 32;
}

typedef struct state_t {
	boolean main_token_in;
	boolean e10_Persistent;
	boolean e10_Token;
	boolean e10_Request;
	boolean e9_Persistent;
	boolean e9_Token;
	boolean e9_Request;
	boolean e8_Persistent;
	boolean e8_Token;
	boolean e8_Request;
	boolean e7_Persistent;
	boolean e7_Token;
	boolean e7_Request;
	boolean e6_Persistent;
	boolean e6_Token;
	boolean e6_Request;
	boolean e5_Persistent;
	boolean e5_Token;
	boolean e5_Request;
	boolean e4_Persistent;
	boolean e4_Token;
	boolean e4_Request;
	boolean e3_Persistent;
	boolean e3_Token;
	boolean e3_Request;
	boolean e2_Persistent;
	boolean e2_Token;
	boolean e2_Request;
	boolean e1_Persistent;
	boolean e1_Token;
	boolean e1_Request;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.main_token_in                          = FALSE,
	.e10_Persistent                         = FALSE,
	.e10_Token                              = FALSE,
	.e10_Request                            = FALSE,
	.e9_Persistent                          = FALSE,
	.e9_Token                               = FALSE,
	.e9_Request                             = FALSE,
	.e8_Persistent                          = FALSE,
	.e8_Token                               = FALSE,
	.e8_Request                             = FALSE,
	.e7_Persistent                          = FALSE,
	.e7_Token                               = FALSE,
	.e7_Request                             = FALSE,
	.e6_Persistent                          = FALSE,
	.e6_Token                               = FALSE,
	.e6_Request                             = FALSE,
	.e5_Persistent                          = FALSE,
	.e5_Token                               = FALSE,
	.e5_Request                             = FALSE,
	.e4_Persistent                          = FALSE,
	.e4_Token                               = FALSE,
	.e4_Request                             = FALSE,
	.e3_Persistent                          = FALSE,
	.e3_Token                               = FALSE,
	.e3_Request                             = FALSE,
	.e2_Persistent                          = FALSE,
	.e2_Token                               = FALSE,
	.e2_Request                             = FALSE,
	.e1_Persistent                          = FALSE,
	.e1_Token                               = FALSE,
	.e1_Request                             = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"main_token_in",1,0x0},
	{"e10_Persistent",1,0x0},
	{"e10_Token",1,0x0},
	{"e10_Request",1,0x0},
	{"e9_Persistent",1,0x0},
	{"e9_Token",1,0x0},
	{"e9_Request",1,0x0},
	{"e8_Persistent",1,0x0},
	{"e8_Token",1,0x0},
	{"e8_Request",1,0x0},
	{"e7_Persistent",1,0x0},
	{"e7_Token",1,0x0},
	{"e7_Request",1,0x0},
	{"e6_Persistent",1,0x0},
	{"e6_Token",1,0x0},
	{"e6_Request",1,0x0},
	{"e5_Persistent",1,0x0},
	{"e5_Token",1,0x0},
	{"e5_Request",1,0x0},
	{"e4_Persistent",1,0x0},
	{"e4_Token",1,0x0},
	{"e4_Request",1,0x0},
	{"e3_Persistent",1,0x0},
	{"e3_Token",1,0x0},
	{"e3_Request",1,0x0},
	{"e2_Persistent",1,0x0},
	{"e2_Token",1,0x0},
	{"e2_Request",1,0x0},
	{"e1_Persistent",1,0x0},
	{"e1_Token",1,0x0},
	{"e1_Request",1,0x0},
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
	int cpy[32] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int e10_override_out;
		int e10_grant_out;
		int e10_ack_out;
		int e9_override_out;
		int e9_grant_out;
		int e9_ack_out;
		int e8_override_out;
		int e8_grant_out;
		int e8_ack_out;
		int e7_override_out;
		int e7_grant_out;
		int e7_ack_out;
		int e6_override_out;
		int e6_grant_out;
		int e6_ack_out;
		int e5_override_out;
		int e5_grant_out;
		int e5_ack_out;
		int e4_override_out;
		int e4_grant_out;
		int e4_ack_out;
		int e3_override_out;
		int e3_grant_out;
		int e3_ack_out;
		int e2_override_out;
		int e2_grant_out;
		int e2_ack_out;
		int e1_override_out;
		int e1_grant_out;
		int e1_ack_out;
		int grant_in;
		int override_out;
		int grant_out;
		e10_override_out = e10_override_out || (in->e10_Persistent && in->e10_Token);
		e10_grant_out = !in->e10_Request && e9_grant_out;
		e10_ack_out = in->e10_Request && (in->e10_Persistent && in->e10_Token || e9_grant_out);
		e9_override_out = e10_override_out || (in->e9_Persistent && in->e9_Token);
		e9_grant_out = !in->e9_Request && e8_grant_out;
		e9_ack_out = in->e9_Request && (in->e9_Persistent && in->e9_Token || e8_grant_out);
		e8_override_out = e9_override_out || (in->e8_Persistent && in->e8_Token);
		e8_grant_out = !in->e8_Request && e7_grant_out;
		e8_ack_out = in->e8_Request && (in->e8_Persistent && in->e8_Token || e7_grant_out);
		e7_override_out = e8_override_out || (in->e7_Persistent && in->e7_Token);
		e7_grant_out = !in->e7_Request && e6_grant_out;
		e7_ack_out = in->e7_Request && (in->e7_Persistent && in->e7_Token || e6_grant_out);
		e6_override_out = e7_override_out || (in->e6_Persistent && in->e6_Token);
		e6_grant_out = !in->e6_Request && e5_grant_out;
		e6_ack_out = in->e6_Request && (in->e6_Persistent && in->e6_Token || e5_grant_out);
		e5_override_out = e6_override_out || (in->e5_Persistent && in->e5_Token);
		e5_grant_out = !in->e5_Request && e4_grant_out;
		e5_ack_out = in->e5_Request && (in->e5_Persistent && in->e5_Token || e4_grant_out);
		e4_override_out = e5_override_out || (in->e4_Persistent && in->e4_Token);
		e4_grant_out = !in->e4_Request && e3_grant_out;
		e4_ack_out = in->e4_Request && (in->e4_Persistent && in->e4_Token || e3_grant_out);
		e3_override_out = e4_override_out || (in->e3_Persistent && in->e3_Token);
		e3_grant_out = !in->e3_Request && e2_grant_out;
		e3_ack_out = in->e3_Request && (in->e3_Persistent && in->e3_Token || e2_grant_out);
		e2_override_out = e3_override_out || (in->e2_Persistent && in->e2_Token);
		e2_grant_out = !in->e2_Request && e1_grant_out;
		e2_ack_out = in->e2_Request && (in->e2_Persistent && in->e2_Token || e1_grant_out);
		e1_override_out = e2_override_out || (in->e1_Persistent && in->e1_Token);
		e1_grant_out = !in->e1_Request && e1_grant_out;
		e1_ack_out = in->e1_Request && (in->e1_Persistent && in->e1_Token || e1_grant_out);
		grant_in = TRUE;
		override_out = FALSE;
		grant_out = grant_in && !e1_override_out;
		out->e10_Persistent = FALSE;
		cpy[((int *)&out->e10_Persistent - (int *)out)] = 0;
		out->e10_Token = FALSE;
		cpy[((int *)&out->e10_Token - (int *)out)] = 0;
		out->e9_Persistent = FALSE;
		cpy[((int *)&out->e9_Persistent - (int *)out)] = 0;
		out->e9_Token = FALSE;
		cpy[((int *)&out->e9_Token - (int *)out)] = 0;
		out->e8_Persistent = FALSE;
		cpy[((int *)&out->e8_Persistent - (int *)out)] = 0;
		out->e8_Token = FALSE;
		cpy[((int *)&out->e8_Token - (int *)out)] = 0;
		out->e7_Persistent = FALSE;
		cpy[((int *)&out->e7_Persistent - (int *)out)] = 0;
		out->e7_Token = FALSE;
		cpy[((int *)&out->e7_Token - (int *)out)] = 0;
		out->e6_Persistent = FALSE;
		cpy[((int *)&out->e6_Persistent - (int *)out)] = 0;
		out->e6_Token = FALSE;
		cpy[((int *)&out->e6_Token - (int *)out)] = 0;
		out->e5_Persistent = FALSE;
		cpy[((int *)&out->e5_Persistent - (int *)out)] = 0;
		out->e5_Token = FALSE;
		cpy[((int *)&out->e5_Token - (int *)out)] = 0;
		out->e4_Persistent = FALSE;
		cpy[((int *)&out->e4_Persistent - (int *)out)] = 0;
		out->e4_Token = FALSE;
		cpy[((int *)&out->e4_Token - (int *)out)] = 0;
		out->e3_Persistent = FALSE;
		cpy[((int *)&out->e3_Persistent - (int *)out)] = 0;
		out->e3_Token = FALSE;
		cpy[((int *)&out->e3_Token - (int *)out)] = 0;
		out->e2_Persistent = FALSE;
		cpy[((int *)&out->e2_Persistent - (int *)out)] = 0;
		out->e2_Token = FALSE;
		cpy[((int *)&out->e2_Token - (int *)out)] = 0;
		out->e1_Persistent = FALSE;
		cpy[((int *)&out->e1_Persistent - (int *)out)] = 0;
		out->e1_Token = TRUE;
		cpy[((int *)&out->e1_Token - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->main_token_in = smv_non_deterministic("main_token_in",2,FALSE,TRUE);
		cpy[((int *)&out->main_token_in - (int *)out)] = 0;
		out->e10_Request = smv_non_deterministic("e10_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e10_Request - (int *)out)] = 0;
		out->e9_Request = smv_non_deterministic("e9_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e9_Request - (int *)out)] = 0;
		out->e8_Request = smv_non_deterministic("e8_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e8_Request - (int *)out)] = 0;
		out->e7_Request = smv_non_deterministic("e7_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e7_Request - (int *)out)] = 0;
		out->e6_Request = smv_non_deterministic("e6_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e6_Request - (int *)out)] = 0;
		out->e5_Request = smv_non_deterministic("e5_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e5_Request - (int *)out)] = 0;
		out->e4_Request = smv_non_deterministic("e4_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e4_Request - (int *)out)] = 0;
		out->e3_Request = smv_non_deterministic("e3_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e3_Request - (int *)out)] = 0;
		out->e2_Request = smv_non_deterministic("e2_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e2_Request - (int *)out)] = 0;
		out->e1_Request = smv_non_deterministic("e1_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e1_Request - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int e10_override_out;
		int e10_grant_out;
		int e10_ack_out;
		int e9_override_out;
		int e9_grant_out;
		int e9_ack_out;
		int e8_override_out;
		int e8_grant_out;
		int e8_ack_out;
		int e7_override_out;
		int e7_grant_out;
		int e7_ack_out;
		int e6_override_out;
		int e6_grant_out;
		int e6_ack_out;
		int e5_override_out;
		int e5_grant_out;
		int e5_ack_out;
		int e4_override_out;
		int e4_grant_out;
		int e4_ack_out;
		int e3_override_out;
		int e3_grant_out;
		int e3_ack_out;
		int e2_override_out;
		int e2_grant_out;
		int e2_ack_out;
		int e1_override_out;
		int e1_grant_out;
		int e1_ack_out;
		int grant_in;
		int override_out;
		int grant_out;
		e10_override_out = e10_override_out || (in->e10_Persistent && in->e10_Token);
		e10_grant_out = !in->e10_Request && e9_grant_out;
		e10_ack_out = in->e10_Request && (in->e10_Persistent && in->e10_Token || e9_grant_out);
		e9_override_out = e10_override_out || (in->e9_Persistent && in->e9_Token);
		e9_grant_out = !in->e9_Request && e8_grant_out;
		e9_ack_out = in->e9_Request && (in->e9_Persistent && in->e9_Token || e8_grant_out);
		e8_override_out = e9_override_out || (in->e8_Persistent && in->e8_Token);
		e8_grant_out = !in->e8_Request && e7_grant_out;
		e8_ack_out = in->e8_Request && (in->e8_Persistent && in->e8_Token || e7_grant_out);
		e7_override_out = e8_override_out || (in->e7_Persistent && in->e7_Token);
		e7_grant_out = !in->e7_Request && e6_grant_out;
		e7_ack_out = in->e7_Request && (in->e7_Persistent && in->e7_Token || e6_grant_out);
		e6_override_out = e7_override_out || (in->e6_Persistent && in->e6_Token);
		e6_grant_out = !in->e6_Request && e5_grant_out;
		e6_ack_out = in->e6_Request && (in->e6_Persistent && in->e6_Token || e5_grant_out);
		e5_override_out = e6_override_out || (in->e5_Persistent && in->e5_Token);
		e5_grant_out = !in->e5_Request && e4_grant_out;
		e5_ack_out = in->e5_Request && (in->e5_Persistent && in->e5_Token || e4_grant_out);
		e4_override_out = e5_override_out || (in->e4_Persistent && in->e4_Token);
		e4_grant_out = !in->e4_Request && e3_grant_out;
		e4_ack_out = in->e4_Request && (in->e4_Persistent && in->e4_Token || e3_grant_out);
		e3_override_out = e4_override_out || (in->e3_Persistent && in->e3_Token);
		e3_grant_out = !in->e3_Request && e2_grant_out;
		e3_ack_out = in->e3_Request && (in->e3_Persistent && in->e3_Token || e2_grant_out);
		e2_override_out = e3_override_out || (in->e2_Persistent && in->e2_Token);
		e2_grant_out = !in->e2_Request && e1_grant_out;
		e2_ack_out = in->e2_Request && (in->e2_Persistent && in->e2_Token || e1_grant_out);
		e1_override_out = e2_override_out || (in->e1_Persistent && in->e1_Token);
		e1_grant_out = !in->e1_Request && e1_grant_out;
		e1_ack_out = in->e1_Request && (in->e1_Persistent && in->e1_Token || e1_grant_out);
		grant_in = TRUE;
		override_out = FALSE;
		grant_out = grant_in && !e1_override_out;
		out->e10_Persistent = in->e10_Request && (in->e10_Persistent || in->e10_Token);
		cpy[((int *)&out->e10_Persistent - (int *)out)] = 0;
		out->e10_Token = in->e9_Token;
		cpy[((int *)&out->e10_Token - (int *)out)] = 0;
		out->e9_Persistent = in->e9_Request && (in->e9_Persistent || in->e9_Token);
		cpy[((int *)&out->e9_Persistent - (int *)out)] = 0;
		out->e9_Token = in->e8_Token;
		cpy[((int *)&out->e9_Token - (int *)out)] = 0;
		out->e8_Persistent = in->e8_Request && (in->e8_Persistent || in->e8_Token);
		cpy[((int *)&out->e8_Persistent - (int *)out)] = 0;
		out->e8_Token = in->e7_Token;
		cpy[((int *)&out->e8_Token - (int *)out)] = 0;
		out->e7_Persistent = in->e7_Request && (in->e7_Persistent || in->e7_Token);
		cpy[((int *)&out->e7_Persistent - (int *)out)] = 0;
		out->e7_Token = in->e6_Token;
		cpy[((int *)&out->e7_Token - (int *)out)] = 0;
		out->e6_Persistent = in->e6_Request && (in->e6_Persistent || in->e6_Token);
		cpy[((int *)&out->e6_Persistent - (int *)out)] = 0;
		out->e6_Token = in->e5_Token;
		cpy[((int *)&out->e6_Token - (int *)out)] = 0;
		out->e5_Persistent = in->e5_Request && (in->e5_Persistent || in->e5_Token);
		cpy[((int *)&out->e5_Persistent - (int *)out)] = 0;
		out->e5_Token = in->e4_Token;
		cpy[((int *)&out->e5_Token - (int *)out)] = 0;
		out->e4_Persistent = in->e4_Request && (in->e4_Persistent || in->e4_Token);
		cpy[((int *)&out->e4_Persistent - (int *)out)] = 0;
		out->e4_Token = in->e3_Token;
		cpy[((int *)&out->e4_Token - (int *)out)] = 0;
		out->e3_Persistent = in->e3_Request && (in->e3_Persistent || in->e3_Token);
		cpy[((int *)&out->e3_Persistent - (int *)out)] = 0;
		out->e3_Token = in->e2_Token;
		cpy[((int *)&out->e3_Token - (int *)out)] = 0;
		out->e2_Persistent = in->e2_Request && (in->e2_Persistent || in->e2_Token);
		cpy[((int *)&out->e2_Persistent - (int *)out)] = 0;
		out->e2_Token = in->e1_Token;
		cpy[((int *)&out->e2_Token - (int *)out)] = 0;
		out->e1_Persistent = in->e1_Request && (in->e1_Persistent || in->e1_Token);
		cpy[((int *)&out->e1_Persistent - (int *)out)] = 0;
		out->e1_Token = in->main_token_in;
		cpy[((int *)&out->e1_Token - (int *)out)] = 0;
		out->main_token_in = smv_non_deterministic("main_token_in",2,FALSE,TRUE);
		cpy[((int *)&out->main_token_in - (int *)out)] = 0;
		out->e10_Request = smv_non_deterministic("e10_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e10_Request - (int *)out)] = 0;
		out->e9_Request = smv_non_deterministic("e9_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e9_Request - (int *)out)] = 0;
		out->e8_Request = smv_non_deterministic("e8_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e8_Request - (int *)out)] = 0;
		out->e7_Request = smv_non_deterministic("e7_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e7_Request - (int *)out)] = 0;
		out->e6_Request = smv_non_deterministic("e6_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e6_Request - (int *)out)] = 0;
		out->e5_Request = smv_non_deterministic("e5_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e5_Request - (int *)out)] = 0;
		out->e4_Request = smv_non_deterministic("e4_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e4_Request - (int *)out)] = 0;
		out->e3_Request = smv_non_deterministic("e3_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e3_Request - (int *)out)] = 0;
		out->e2_Request = smv_non_deterministic("e2_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e2_Request - (int *)out)] = 0;
		out->e1_Request = smv_non_deterministic("e1_Request",2,FALSE,TRUE);
		cpy[((int *)&out->e1_Request - (int *)out)] = 0;
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
	((int[]){31,1,2,3,5,4,6,8,7,9,11,10,12,14,13,15,17,16,18,20,19,21,23,22,24,26,25,27,29,28,30,0})
};

int *write_m[2] = {
	((int[]){32,1,2,4,5,7,8,10,11,13,14,16,17,19,20,22,23,25,26,28,29,31,0,3,6,9,12,15,18,21,24,27,30}),
	((int[]){31,1,2,4,5,7,8,10,11,13,14,16,17,19,20,22,23,25,26,28,29,0,3,6,9,12,15,18,21,24,27,30})
};

int *label_m[2] = {
	((int[]){1,31}),
	((int[]){1,31})
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
char pins_plugin_name[] = "syncarb10";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"main_token_in");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"e10_Persistent");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"e10_Token");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"e10_Request");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"e9_Persistent");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"e9_Token");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"e9_Request");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"e8_Persistent");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"e8_Token");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"e8_Request");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"e7_Persistent");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"e7_Token");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"e7_Request");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"e6_Persistent");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"e6_Token");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"e6_Request");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"e5_Persistent");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"e5_Token");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"e5_Request");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"e4_Persistent");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"e4_Token");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"e4_Request");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"e3_Persistent");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"e3_Token");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"e3_Request");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"e2_Persistent");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"e2_Token");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"e2_Request");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"e1_Persistent");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"e1_Token");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"e1_Request");
	lts_type_set_state_typeno(ltstype, 30,int_type);
	lts_type_set_state_name(ltstype, 31,"virtual_init");
	lts_type_set_state_typeno(ltstype, 31,int_type);

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
	int state[32];
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
