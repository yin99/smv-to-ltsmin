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
	 get, send, wait_for_ack, mt, data0, data1, error, receive, deliver, send_ack, ack0, ack1,
}smv_enum;

const int smv_get_state_size() {
	return 17;
}

typedef struct state_t {
	smv_enum sender_state;
	boolean sender_abp;
	int sender_data;
	boolean sender_running;
	smv_enum s2r_in_tag;
	int s2r_in_data;
	smv_enum s2r_out_tag;
	int s2r_out_data;
	smv_enum receiver_state;
	boolean receiver_abp;
	int receiver_data;
	boolean receiver_running;
	smv_enum r2s_in_tag;
	smv_enum r2s_out_tag;
	boolean r2s_running;
	boolean s2r_running;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.sender_state                           = 0,
	.sender_abp                             = FALSE,
	.sender_data                            = 0,
	.sender_running                         = FALSE,
	.s2r_in_tag                             = 0,
	.s2r_in_data                            = 0,
	.s2r_out_tag                            = 0,
	.s2r_out_data                           = 0,
	.receiver_state                         = 0,
	.receiver_abp                           = FALSE,
	.receiver_data                          = 0,
	.receiver_running                       = FALSE,
	.r2s_in_tag                             = 0,
	.r2s_out_tag                            = 0,
	.r2s_running                            = FALSE,
	.s2r_running                            = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"sender_state",1,0x0},
	{"sender_abp",1,0x0},
	{"sender_data",1,0x0},
	{"sender_running",1,0x0},
	{"s2r_in_tag",1,0x0},
	{"s2r_in_data",1,0x0},
	{"s2r_out_tag",1,0x0},
	{"s2r_out_data",1,0x0},
	{"receiver_state",1,0x0},
	{"receiver_abp",1,0x0},
	{"receiver_data",1,0x0},
	{"receiver_running",1,0x0},
	{"r2s_in_tag",1,0x0},
	{"r2s_out_tag",1,0x0},
	{"r2s_running",1,0x0},
	{"s2r_running",1,0x0},
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
	int cpy[17] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		out->s2r_in_tag = mt;
		cpy[((int *)&out->s2r_in_tag - (int *)out)] = 0;
		out->s2r_out_tag = mt;
		cpy[((int *)&out->s2r_out_tag - (int *)out)] = 0;
		out->r2s_in_tag = mt;
		cpy[((int *)&out->r2s_in_tag - (int *)out)] = 0;
		out->r2s_out_tag = mt;
		cpy[((int *)&out->r2s_out_tag - (int *)out)] = 0;
		out->sender_state = get;
		cpy[((int *)&out->sender_state - (int *)out)] = 0;
		out->sender_abp = FALSE;
		cpy[((int *)&out->sender_abp - (int *)out)] = 0;
		out->receiver_state = receive;
		cpy[((int *)&out->receiver_state - (int *)out)] = 0;
		out->receiver_abp = FALSE;
		cpy[((int *)&out->receiver_abp - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->sender_data = smv_non_deterministic("sender_data",256,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255);
		cpy[((int *)&out->sender_data - (int *)out)] = 0;
		out->s2r_in_data = smv_non_deterministic("s2r_in_data",256,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255);
		cpy[((int *)&out->s2r_in_data - (int *)out)] = 0;
		out->s2r_out_data = smv_non_deterministic("s2r_out_data",256,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255);
		cpy[((int *)&out->s2r_out_data - (int *)out)] = 0;
		out->receiver_data = smv_non_deterministic("receiver_data",256,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255);
		cpy[((int *)&out->receiver_data - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		out->sender_running = FALSE;
		cpy[((int *)&out->sender_running - (int *)out)] = 0;
		out->sender_state =  ( in->sender_state == get ? send :  ( in->sender_state == send && in->s2r_in_tag == mt ? wait_for_ack :  ( in->sender_state == send && !(in->s2r_in_tag == mt) ? send :  ( in->sender_state == wait_for_ack && (!in->sender_abp && in->r2s_out_tag == ack0 || in->sender_abp && in->r2s_out_tag == ack1) ? get :  ( in->sender_state == wait_for_ack && (in->sender_abp && in->r2s_out_tag == ack0 || !in->sender_abp && in->r2s_out_tag == ack1 || in->r2s_out_tag == error) ? send : wait_for_ack )  )  )  )  ) ;
		cpy[((int *)&out->sender_state - (int *)out)] = 0;
		out->sender_abp =  ( in->sender_state == wait_for_ack && (!in->sender_abp && in->r2s_out_tag == ack0 || in->sender_abp && in->r2s_out_tag == ack1) ? !in->sender_abp : in->sender_abp ) ;
		cpy[((int *)&out->sender_abp - (int *)out)] = 0;
		out->sender_data =  ( in->sender_state == wait_for_ack && (!in->sender_abp && in->r2s_out_tag == ack0 || in->sender_abp && in->r2s_out_tag == ack1) ? smv_non_deterministic("data",256,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255) : in->sender_data ) ;
		cpy[((int *)&out->sender_data - (int *)out)] = 0;
		out->s2r_in_tag =  ( in->sender_state == send && in->s2r_in_tag == mt ?  ( in->sender_abp ? data1 : data0 )  : in->s2r_in_tag ) ;
		cpy[((int *)&out->s2r_in_tag - (int *)out)] = 0;
		out->s2r_in_data =  ( in->sender_state == send && in->s2r_in_tag == mt ? in->sender_data : in->s2r_in_data ) ;
		cpy[((int *)&out->s2r_in_data - (int *)out)] = 0;
		out->r2s_out_tag =  ( in->sender_state == wait_for_ack ? mt : in->r2s_out_tag ) ;
		cpy[((int *)&out->r2s_out_tag - (int *)out)] = 0;
		transition_labels[0] = 1;
		transition_info.group = 1;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 2: {
		memcpy(out, in, sizeof(state_t));
		out->receiver_running = FALSE;
		cpy[((int *)&out->receiver_running - (int *)out)] = 0;
		out->receiver_state =  ( in->receiver_state == receive && (!in->receiver_abp && in->s2r_out_tag == data0 || in->receiver_abp && in->s2r_out_tag == data1) ? deliver :  ( in->receiver_state == receive && (in->receiver_abp && in->s2r_out_tag == data0 || !in->receiver_abp && in->s2r_out_tag == data1 || in->s2r_out_tag == error) ? send_ack :  ( in->receiver_state == receive && in->s2r_out_tag == mt ? in->receiver_state :  ( in->receiver_state == deliver ? send_ack :  ( in->receiver_state == send_ack && in->r2s_in_tag == mt ? receive : in->receiver_state )  )  )  )  ) ;
		cpy[((int *)&out->receiver_state - (int *)out)] = 0;
		out->receiver_abp =  ( in->receiver_state == deliver ? !in->receiver_abp : in->receiver_abp ) ;
		cpy[((int *)&out->receiver_abp - (int *)out)] = 0;
		out->receiver_data =  ( in->receiver_state == receive && (!in->receiver_abp && in->s2r_out_tag == data0 || in->receiver_abp && in->s2r_out_tag == data1) ? in->s2r_out_data : in->receiver_data ) ;
		cpy[((int *)&out->receiver_data - (int *)out)] = 0;
		out->s2r_out_tag =  ( in->receiver_state == receive ? mt : in->s2r_out_tag ) ;
		cpy[((int *)&out->s2r_out_tag - (int *)out)] = 0;
		out->s2r_out_data = in->s2r_out_data;
		cpy[((int *)&out->s2r_out_data - (int *)out)] = 0;
		out->r2s_in_tag =  ( in->receiver_state == send_ack && in->r2s_in_tag == mt ?  ( in->receiver_abp ? ack0 : ack1 )  : in->r2s_in_tag ) ;
		cpy[((int *)&out->r2s_in_tag - (int *)out)] = 0;
		transition_labels[0] = 2;
		transition_info.group = 2;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 3: {
		memcpy(out, in, sizeof(state_t));
		out->r2s_running = FALSE;
		cpy[((int *)&out->r2s_running - (int *)out)] = 0;
		out->r2s_out_tag =  ( in->r2s_out_tag == mt && !(in->r2s_in_tag == mt) ? smv_non_deterministic("r2s_out_tag",2,in->r2s_in_tag,error) : in->r2s_out_tag ) ;
		cpy[((int *)&out->r2s_out_tag - (int *)out)] = 0;
		out->r2s_in_tag =  ( in->r2s_out_tag == mt && !(in->r2s_in_tag == mt) ? mt : in->r2s_in_tag ) ;
		cpy[((int *)&out->r2s_in_tag - (int *)out)] = 0;
		transition_labels[0] = 3;
		transition_info.group = 3;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 4: {
		memcpy(out, in, sizeof(state_t));
		out->s2r_running = FALSE;
		cpy[((int *)&out->s2r_running - (int *)out)] = 0;
		out->s2r_out_tag =  ( in->s2r_out_tag == mt && !(in->s2r_in_tag == mt) ? smv_non_deterministic("s2r_out_tag",2,in->s2r_in_tag,error) : in->s2r_out_tag ) ;
		cpy[((int *)&out->s2r_out_tag - (int *)out)] = 0;
		out->s2r_in_tag =  ( in->s2r_out_tag == mt && !(in->s2r_in_tag == mt) ? mt : in->s2r_in_tag ) ;
		cpy[((int *)&out->s2r_in_tag - (int *)out)] = 0;
		out->s2r_out_data =  ( in->s2r_out_tag == mt && !(in->s2r_in_tag == mt) ? in->s2r_in_data : in->s2r_out_data ) ;
		cpy[((int *)&out->s2r_out_data - (int *)out)] = 0;
		out->s2r_in_data = in->s2r_in_data;
		cpy[((int *)&out->s2r_in_data - (int *)out)] = 0;
		transition_labels[0] = 4;
		transition_info.group = 4;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 5: {
		memcpy(out, in, sizeof(state_t));
		transition_labels[0] = 5;
		transition_info.group = 5;
		out->sender_running= TRUE;
		cpy[((int *)&out->sender_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->sender_running= FALSE;
		cpy[((int *)&out->sender_running - (int *)out)] = 1;
		out->receiver_running= TRUE;
		cpy[((int *)&out->receiver_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->receiver_running= FALSE;
		cpy[((int *)&out->receiver_running - (int *)out)] = 1;
		out->r2s_running= TRUE;
		cpy[((int *)&out->r2s_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->r2s_running= FALSE;
		cpy[((int *)&out->r2s_running - (int *)out)] = 1;
		out->s2r_running= TRUE;
		cpy[((int *)&out->s2r_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		return 4;
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
		if(in->sender_running == TRUE){
			smv_get_actions(model,1,in,callback,arg);
		}
	}
	case 2: {
		if(in->receiver_running == TRUE){
			smv_get_actions(model,2,in,callback,arg);
		}
	}
	case 3: {
		if(in->r2s_running == TRUE){
			smv_get_actions(model,3,in,callback,arg);
		}
	}
	case 4: {
		if(in->s2r_running == TRUE){
			smv_get_actions(model,4,in,callback,arg);
		}
	}
	case 5: {
		if(!((in->virtual_init == TRUE)||(in->sender_running == TRUE)||(in->receiver_running == TRUE)||(in->r2s_running == TRUE)||(in->s2r_running == TRUE))){
			return smv_get_actions(model,5,in,callback,arg);
		}
	}
	}
}

int smv_get_transition_groups() {
	return 6;
}

int smv_get_label(void* model, int g, state_t* in){
	switch (g){
		case 0: return (in->virtual_init == TRUE)!=0;
		case 1: return (in->sender_running == TRUE) !=0;
		case 2: return (in->receiver_running == TRUE) !=0;
		case 3: return (in->r2s_running == TRUE) !=0;
		case 4: return (in->s2r_running == TRUE) !=0;
		case 5: return !((in->virtual_init == TRUE)||(in->sender_running == TRUE)||(in->receiver_running == TRUE)||(in->r2s_running == TRUE)||(in->s2r_running == TRUE));
	}
}

int smv_get_label_count() {
	return 6;
}

int *read_m[6] = {
	((int[]){0}),
	((int[]){6,0,1,4,13,2,5}),
	((int[]){6,6,8,9,12,7,10}),
	((int[]){2,12,13}),
	((int[]){4,4,6,5,7}),
	((int[]){0})
};

int *write_m[6] = {
	((int[]){13,4,6,12,13,0,1,8,9,16,2,5,7,10}),
	((int[]){7,3,0,1,2,4,5,13}),
	((int[]){7,11,8,9,10,6,7,12}),
	((int[]){3,14,13,12}),
	((int[]){5,15,6,4,7,5}),
	((int[]){4,3,11,14,15})
};

int *label_m[6] = {
	((int[]){1,16}),
	((int[]){1,3}),
	((int[]){1,11}),
	((int[]){1,14}),
	((int[]){1,15}),
	((int[]){5,3,11,14,15,16})
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
char pins_plugin_name[] = "abp8";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"sender_state");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"sender_abp");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"sender_data");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"sender_running");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"s2r_in_tag");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"s2r_in_data");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"s2r_out_tag");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"s2r_out_data");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"receiver_state");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"receiver_abp");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"receiver_data");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"receiver_running");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"r2s_in_tag");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"r2s_out_tag");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"r2s_running");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"s2r_running");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"virtual_init");
	lts_type_set_state_typeno(ltstype, 16,int_type);

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
	lts_type_set_state_label_name (ltstype, 1, "now_sender_running");
	lts_type_set_state_label_typeno (ltstype, 2, bool_type);
	lts_type_set_state_label_name (ltstype, 2, "now_receiver_running");
	lts_type_set_state_label_typeno (ltstype, 3, bool_type);
	lts_type_set_state_label_name (ltstype, 3, "now_r2s_running");
	lts_type_set_state_label_typeno (ltstype, 4, bool_type);
	lts_type_set_state_label_name (ltstype, 4, "now_s2r_running");
	lts_type_set_state_label_typeno (ltstype, 5, bool_type);
	lts_type_set_state_label_name (ltstype, 5, "choose_running");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("sender_running"));
	pins_chunk_put(m, action_type, chunk_str("receiver_running"));
	pins_chunk_put(m, action_type, chunk_str("r2s_running"));
	pins_chunk_put(m, action_type, chunk_str("s2r_running"));
	pins_chunk_put(m, action_type, chunk_str("choose_running"));
	int state[17];
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
