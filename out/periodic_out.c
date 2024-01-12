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
	 idle, p11, p12, p13, p21, p22, p23, p31, p32, p33,
}smv_enum;

const int smv_get_state_size() {
	return 12;
}

typedef struct state_t {
	int timer;
	int P11_state;
	int P12_state;
	int P13_state;
	int P21_state;
	int P22_state;
	int P23_state;
	int P31_state;
	int P32_state;
	int P33_state;
	smv_enum aux;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.timer                                  = 0,
	.P11_state                              = 0,
	.P12_state                              = 0,
	.P13_state                              = 0,
	.P21_state                              = 0,
	.P22_state                              = 0,
	.P23_state                              = 0,
	.P31_state                              = 0,
	.P32_state                              = 0,
	.P33_state                              = 0,
	.aux                                    = 0,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"timer",1,0x0},
	{"P11_state",1,0x0},
	{"P12_state",1,0x0},
	{"P13_state",1,0x0},
	{"P21_state",1,0x0},
	{"P22_state",1,0x0},
	{"P23_state",1,0x0},
	{"P31_state",1,0x0},
	{"P32_state",1,0x0},
	{"P33_state",1,0x0},
	{"aux",1,0x0},
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
	int cpy[12] = { 1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int P11_start;
		int P11_finish;
		int P11_request;
		int P12_start;
		int P12_finish;
		int P12_request;
		int P13_start;
		int P13_finish;
		int P13_request;
		int P21_start;
		int P21_finish;
		int P21_request;
		int P22_start;
		int P22_finish;
		int P22_request;
		int P23_start;
		int P23_finish;
		int P23_request;
		int P31_start;
		int P31_finish;
		int P31_request;
		int P32_start;
		int P32_finish;
		int P32_request;
		int P33_start;
		int P33_finish;
		int P33_request;
		int timeout100;
		int timeout50;
		int timeout20;
		int processor_granted;
		int error;
		P11_start = in->P11_state == 0 && timeout20;
		P11_finish = in->P11_state == 3;
		P11_request =  ( in->P11_state == 0 ? FALSE : TRUE ) ;
		P12_start = in->P12_state == 0 && timeout20;
		P12_finish = in->P12_state == 3;
		P12_request =  ( in->P12_state == 0 ? FALSE : TRUE ) ;
		P13_start = in->P13_state == 0 && timeout20;
		P13_finish = in->P13_state == 4;
		P13_request =  ( in->P13_state == 0 ? FALSE : TRUE ) ;
		P21_start = in->P21_state == 0 && timeout50;
		P21_finish = in->P21_state == 6;
		P21_request =  ( in->P21_state == 0 ? FALSE : TRUE ) ;
		P22_start = in->P22_state == 0 && timeout50;
		P22_finish = in->P22_state == 4;
		P22_request =  ( in->P22_state == 0 ? FALSE : TRUE ) ;
		P23_start = in->P23_state == 0 && timeout50;
		P23_finish = in->P23_state == 5;
		P23_request =  ( in->P23_state == 0 ? FALSE : TRUE ) ;
		P31_start = in->P31_state == 0 && timeout100;
		P31_finish = in->P31_state == 5;
		P31_request =  ( in->P31_state == 0 ? FALSE : TRUE ) ;
		P32_start = in->P32_state == 0 && timeout100;
		P32_finish = in->P32_state == 6;
		P32_request =  ( in->P32_state == 0 ? FALSE : TRUE ) ;
		P33_start = in->P33_state == 0 && timeout100;
		P33_finish = in->P33_state == 5;
		P33_request =  ( in->P33_state == 0 ? FALSE : TRUE ) ;
		timeout100 = in->timer % 100 == 0;
		timeout50 = in->timer % 50 == 0;
		timeout20 = in->timer % 20 == 0;
		processor_granted =  ( P11_request ? p11 :  ( P12_request ? p12 :  ( P13_request ? p13 :  ( P21_request ? p21 :  ( P22_request ? p22 :  ( P23_request ? p23 :  ( P31_request ? p31 :  ( P32_request ? p32 :  ( P33_request ? p33 : idle )  )  )  )  )  )  )  )  ) ;
		error = timeout20 && !(in->P11_state == 0) || timeout20 && !(in->P12_state == 0) || timeout20 && !(in->P13_state == 0) || timeout50 && !(in->P21_state == 0) || timeout50 && !(in->P22_state == 0) || timeout50 && !(in->P23_state == 0) || timeout100 && !(in->P31_state == 0) || timeout100 && !(in->P32_state == 0) || timeout100 && !(in->P33_state == 0);
		out->timer = 0;
		cpy[((int *)&out->timer - (int *)out)] = 0;
		out->P11_state = 0;
		cpy[((int *)&out->P11_state - (int *)out)] = 0;
		out->P12_state = 0;
		cpy[((int *)&out->P12_state - (int *)out)] = 0;
		out->P13_state = 0;
		cpy[((int *)&out->P13_state - (int *)out)] = 0;
		out->P21_state = 0;
		cpy[((int *)&out->P21_state - (int *)out)] = 0;
		out->P22_state = 0;
		cpy[((int *)&out->P22_state - (int *)out)] = 0;
		out->P23_state = 0;
		cpy[((int *)&out->P23_state - (int *)out)] = 0;
		out->P31_state = 0;
		cpy[((int *)&out->P31_state - (int *)out)] = 0;
		out->P32_state = 0;
		cpy[((int *)&out->P32_state - (int *)out)] = 0;
		out->P33_state = 0;
		cpy[((int *)&out->P33_state - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->aux = smv_non_deterministic("aux",10,idle,p11,p12,p13,p21,p22,p23,p31,p32,p33);
		cpy[((int *)&out->aux - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int P11_start;
		int P11_finish;
		int P11_request;
		int P12_start;
		int P12_finish;
		int P12_request;
		int P13_start;
		int P13_finish;
		int P13_request;
		int P21_start;
		int P21_finish;
		int P21_request;
		int P22_start;
		int P22_finish;
		int P22_request;
		int P23_start;
		int P23_finish;
		int P23_request;
		int P31_start;
		int P31_finish;
		int P31_request;
		int P32_start;
		int P32_finish;
		int P32_request;
		int P33_start;
		int P33_finish;
		int P33_request;
		int timeout100;
		int timeout50;
		int timeout20;
		int processor_granted;
		int error;
		P11_start = in->P11_state == 0 && timeout20;
		P11_finish = in->P11_state == 3;
		P11_request =  ( in->P11_state == 0 ? FALSE : TRUE ) ;
		P12_start = in->P12_state == 0 && timeout20;
		P12_finish = in->P12_state == 3;
		P12_request =  ( in->P12_state == 0 ? FALSE : TRUE ) ;
		P13_start = in->P13_state == 0 && timeout20;
		P13_finish = in->P13_state == 4;
		P13_request =  ( in->P13_state == 0 ? FALSE : TRUE ) ;
		P21_start = in->P21_state == 0 && timeout50;
		P21_finish = in->P21_state == 6;
		P21_request =  ( in->P21_state == 0 ? FALSE : TRUE ) ;
		P22_start = in->P22_state == 0 && timeout50;
		P22_finish = in->P22_state == 4;
		P22_request =  ( in->P22_state == 0 ? FALSE : TRUE ) ;
		P23_start = in->P23_state == 0 && timeout50;
		P23_finish = in->P23_state == 5;
		P23_request =  ( in->P23_state == 0 ? FALSE : TRUE ) ;
		P31_start = in->P31_state == 0 && timeout100;
		P31_finish = in->P31_state == 5;
		P31_request =  ( in->P31_state == 0 ? FALSE : TRUE ) ;
		P32_start = in->P32_state == 0 && timeout100;
		P32_finish = in->P32_state == 6;
		P32_request =  ( in->P32_state == 0 ? FALSE : TRUE ) ;
		P33_start = in->P33_state == 0 && timeout100;
		P33_finish = in->P33_state == 5;
		P33_request =  ( in->P33_state == 0 ? FALSE : TRUE ) ;
		timeout100 = in->timer % 100 == 0;
		timeout50 = in->timer % 50 == 0;
		timeout20 = in->timer % 20 == 0;
		processor_granted =  ( P11_request ? p11 :  ( P12_request ? p12 :  ( P13_request ? p13 :  ( P21_request ? p21 :  ( P22_request ? p22 :  ( P23_request ? p23 :  ( P31_request ? p31 :  ( P32_request ? p32 :  ( P33_request ? p33 : idle )  )  )  )  )  )  )  )  ) ;
		error = timeout20 && !(in->P11_state == 0) || timeout20 && !(in->P12_state == 0) || timeout20 && !(in->P13_state == 0) || timeout50 && !(in->P21_state == 0) || timeout50 && !(in->P22_state == 0) || timeout50 && !(in->P23_state == 0) || timeout100 && !(in->P31_state == 0) || timeout100 && !(in->P32_state == 0) || timeout100 && !(in->P33_state == 0);
		out->timer = (in->timer + 1) % 100;
		cpy[((int *)&out->timer - (int *)out)] = 0;
		out->P11_state =  ( P11_start ? 1 :  ( P11_finish ? 0 :  ( processor_granted!=p11 ? in->P11_state :  ( in->P11_state == 0 ? 0 : (in->P11_state + 1) % 4 )  )  )  ) ;
		cpy[((int *)&out->P11_state - (int *)out)] = 0;
		out->P12_state =  ( P12_start ? 1 :  ( P12_finish ? 0 :  ( processor_granted!=p12 ? in->P12_state :  ( in->P12_state == 0 ? 0 : (in->P12_state + 1) % 4 )  )  )  ) ;
		cpy[((int *)&out->P12_state - (int *)out)] = 0;
		out->P13_state =  ( P13_start ? 1 :  ( P13_finish ? 0 :  ( processor_granted!=p13 ? in->P13_state :  ( in->P13_state == 0 ? 0 : (in->P13_state + 1) % 5 )  )  )  ) ;
		cpy[((int *)&out->P13_state - (int *)out)] = 0;
		out->P21_state =  ( P21_start ? 1 :  ( P21_finish ? 0 :  ( processor_granted!=p21 ? in->P21_state :  ( in->P21_state == 0 ? 0 : (in->P21_state + 1) % 7 )  )  )  ) ;
		cpy[((int *)&out->P21_state - (int *)out)] = 0;
		out->P22_state =  ( P22_start ? 1 :  ( P22_finish ? 0 :  ( processor_granted!=p22 ? in->P22_state :  ( in->P22_state == 0 ? 0 : (in->P22_state + 1) % 5 )  )  )  ) ;
		cpy[((int *)&out->P22_state - (int *)out)] = 0;
		out->P23_state =  ( P23_start ? 1 :  ( P23_finish ? 0 :  ( processor_granted!=p23 ? in->P23_state :  ( in->P23_state == 0 ? 0 : (in->P23_state + 1) % 6 )  )  )  ) ;
		cpy[((int *)&out->P23_state - (int *)out)] = 0;
		out->P31_state =  ( P31_start ? 1 :  ( P31_finish ? 0 :  ( processor_granted!=p31 ? in->P31_state :  ( in->P31_state == 0 ? 0 : (in->P31_state + 1) % 6 )  )  )  ) ;
		cpy[((int *)&out->P31_state - (int *)out)] = 0;
		out->P32_state =  ( P32_start ? 1 :  ( P32_finish ? 0 :  ( processor_granted!=p32 ? in->P32_state :  ( in->P32_state == 0 ? 0 : (in->P32_state + 1) % 7 )  )  )  ) ;
		cpy[((int *)&out->P32_state - (int *)out)] = 0;
		out->P33_state =  ( P33_start ? 1 :  ( P33_finish ? 0 :  ( processor_granted!=p33 ? in->P33_state :  ( in->P33_state == 0 ? 0 : (in->P33_state + 1) % 6 )  )  )  ) ;
		cpy[((int *)&out->P33_state - (int *)out)] = 0;
		out->aux = smv_non_deterministic("aux",10,idle,p11,p12,p13,p21,p22,p23,p31,p32,p33);
		cpy[((int *)&out->aux - (int *)out)] = 0;
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
	((int[]){10,0,1,2,3,4,5,6,7,8,9})
};

int *write_m[2] = {
	((int[]){12,0,1,2,3,4,5,6,7,8,9,11,10}),
	((int[]){11,0,1,2,3,4,5,6,7,8,9,10})
};

int *label_m[2] = {
	((int[]){1,11}),
	((int[]){1,11})
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
char pins_plugin_name[] = "periodic";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"timer");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"P11_state");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"P12_state");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"P13_state");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"P21_state");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"P22_state");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"P23_state");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"P31_state");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"P32_state");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"P33_state");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"aux");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"virtual_init");
	lts_type_set_state_typeno(ltstype, 11,int_type);

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
	int state[12];
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
