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
	 idle, entering, critical, exiting,
}smv_enum;

const int smv_get_state_size() {
	return 6;
}

typedef struct state_t {
	boolean semaphore;
	smv_enum proc1_state;
	boolean proc1_running;
	smv_enum proc2_state;
	boolean proc2_running;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.semaphore                              = FALSE,
	.proc1_state                            = 0,
	.proc1_running                          = FALSE,
	.proc2_state                            = 0,
	.proc2_running                          = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"semaphore",1,0x0},
	{"proc1_state",1,0x0},
	{"proc1_running",1,0x0},
	{"proc2_state",1,0x0},
	{"proc2_running",1,0x0},
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
	int cpy[6] = { 1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		out->semaphore = FALSE;
		cpy[((int *)&out->semaphore - (int *)out)] = 0;
		out->proc1_state = idle;
		cpy[((int *)&out->proc1_state - (int *)out)] = 0;
		out->proc2_state = idle;
		cpy[((int *)&out->proc2_state - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		out->proc1_running = FALSE;
		cpy[((int *)&out->proc1_running - (int *)out)] = 0;
		out->proc1_state =  ( in->proc1_state == idle ? smv_non_deterministic("proc1_state",2,idle,entering) :  ( in->proc1_state == entering && !in->semaphore ? critical :  ( in->proc1_state == critical ? smv_non_deterministic("proc1_state",2,critical,exiting) :  ( in->proc1_state == exiting ? idle : in->proc1_state )  )  )  ) ;
		cpy[((int *)&out->proc1_state - (int *)out)] = 0;
		out->semaphore =  ( in->proc1_state == entering ? TRUE :  ( in->proc1_state == exiting ? FALSE : in->semaphore )  ) ;
		cpy[((int *)&out->semaphore - (int *)out)] = 0;
		transition_labels[0] = 1;
		transition_info.group = 1;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 2: {
		memcpy(out, in, sizeof(state_t));
		out->proc2_running = FALSE;
		cpy[((int *)&out->proc2_running - (int *)out)] = 0;
		out->proc2_state =  ( in->proc2_state == idle ? smv_non_deterministic("proc2_state",2,idle,entering) :  ( in->proc2_state == entering && !in->semaphore ? critical :  ( in->proc2_state == critical ? smv_non_deterministic("proc2_state",2,critical,exiting) :  ( in->proc2_state == exiting ? idle : in->proc2_state )  )  )  ) ;
		cpy[((int *)&out->proc2_state - (int *)out)] = 0;
		out->semaphore =  ( in->proc2_state == entering ? TRUE :  ( in->proc2_state == exiting ? FALSE : in->semaphore )  ) ;
		cpy[((int *)&out->semaphore - (int *)out)] = 0;
		transition_labels[0] = 2;
		transition_info.group = 2;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 3: {
		memcpy(out, in, sizeof(state_t));
		transition_labels[0] = 3;
		transition_info.group = 3;
		out->proc1_running= TRUE;
		cpy[((int *)&out->proc1_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->proc1_running= FALSE;
		cpy[((int *)&out->proc1_running - (int *)out)] = 1;
		out->proc2_running= TRUE;
		cpy[((int *)&out->proc2_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		return 2;
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
		if(in->proc1_running == TRUE){
			smv_get_actions(model,1,in,callback,arg);
		}
	}
	case 2: {
		if(in->proc2_running == TRUE){
			smv_get_actions(model,2,in,callback,arg);
		}
	}
	case 3: {
		if(!((in->virtual_init == TRUE)||(in->proc1_running == TRUE)||(in->proc2_running == TRUE))){
			return smv_get_actions(model,3,in,callback,arg);
		}
	}
	}
}

int smv_get_transition_groups() {
	return 4;
}

int smv_get_label(void* model, int g, state_t* in){
	switch (g){
		case 0: return (in->virtual_init == TRUE)!=0;
		case 1: return (in->proc1_running == TRUE) !=0;
		case 2: return (in->proc2_running == TRUE) !=0;
		case 3: return !((in->virtual_init == TRUE)||(in->proc1_running == TRUE)||(in->proc2_running == TRUE));
	}
}

int smv_get_label_count() {
	return 4;
}

int *read_m[4] = {
	((int[]){0}),
	((int[]){2,0,1}),
	((int[]){2,0,3}),
	((int[]){0})
};

int *write_m[4] = {
	((int[]){4,0,1,3,5}),
	((int[]){3,2,1,0}),
	((int[]){3,4,3,0}),
	((int[]){2,2,4})
};

int *label_m[4] = {
	((int[]){1,5}),
	((int[]){1,2}),
	((int[]){1,4}),
	((int[]){3,2,4,5})
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
char pins_plugin_name[] = "semaphore";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"semaphore");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"proc1_state");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"proc1_running");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"proc2_state");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"proc2_running");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"virtual_init");
	lts_type_set_state_typeno(ltstype, 5,int_type);

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
	lts_type_set_state_label_name (ltstype, 1, "now_proc1_running");
	lts_type_set_state_label_typeno (ltstype, 2, bool_type);
	lts_type_set_state_label_name (ltstype, 2, "now_proc2_running");
	lts_type_set_state_label_typeno (ltstype, 3, bool_type);
	lts_type_set_state_label_name (ltstype, 3, "choose_running");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("proc1_running"));
	pins_chunk_put(m, action_type, chunk_str("proc2_running"));
	pins_chunk_put(m, action_type, chunk_str("choose_running"));
	int state[6];
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
