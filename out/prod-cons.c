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
	 EMPTYENUM0, EMPTYENUM1, EMPTYENUM2, EMPTYENUM3, new_val, dec, EMPTYENUM4, test, inc, poebuf, req, wait, bufful, sort, subst, sort_ready,
}smv_enum;

const int smv_get_state_size() {
	return 19;
}

typedef struct state_t {
	smv_enum buffer1;
	smv_enum buffer2;
	smv_enum buffer3;
	smv_enum bufsize;
	smv_enum sim_state;
	smv_enum sim_val;
	boolean sim_running;
	smv_enum sm_state;
	boolean sm_running;
	smv_enum srt_state;
	smv_enum srt_buffer_aux1;
	smv_enum srt_buffer_aux2;
	smv_enum srt_buffer_aux3;
	boolean srt_ord;
	boolean srt_running;
	boolean sort_OK;
	boolean sort_req;
	boolean lock;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.buffer1                                = 0,
	.buffer2                                = 0,
	.buffer3                                = 0,
	.bufsize                                = 0,
	.sim_state                              = 0,
	.sim_val                                = 0,
	.sim_running                            = FALSE,
	.sm_state                               = 0,
	.sm_running                             = FALSE,
	.srt_state                              = 0,
	.srt_buffer_aux1                        = 0,
	.srt_buffer_aux2                        = 0,
	.srt_buffer_aux3                        = 0,
	.srt_ord                                = FALSE,
	.srt_running                            = FALSE,
	.sort_OK                                = FALSE,
	.sort_req                               = FALSE,
	.lock                                   = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"buffer1",1,0x0},
	{"buffer2",1,0x0},
	{"buffer3",1,0x0},
	{"bufsize",1,0x0},
	{"sim_state",1,0x0},
	{"sim_val",1,0x0},
	{"sim_running",1,0x0},
	{"sm_state",1,0x0},
	{"sm_running",1,0x0},
	{"srt_state",1,0x0},
	{"srt_buffer_aux1",1,0x0},
	{"srt_buffer_aux2",1,0x0},
	{"srt_buffer_aux3",1,0x0},
	{"srt_ord",1,0x0},
	{"srt_running",1,0x0},
	{"sort_OK",1,0x0},
	{"sort_req",1,0x0},
	{"lock",1,0x0},
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
	int cpy[19] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		out->bufsize = 0;
		cpy[((int *)&out->bufsize - (int *)out)] = 0;
		out->sort_OK = FALSE;
		cpy[((int *)&out->sort_OK - (int *)out)] = 0;
		out->sort_req = FALSE;
		cpy[((int *)&out->sort_req - (int *)out)] = 0;
		out->sim_state = new_val;
		cpy[((int *)&out->sim_state - (int *)out)] = 0;
		out->sim_val = 0;
		cpy[((int *)&out->sim_val - (int *)out)] = 0;
		out->sm_state = test;
		cpy[((int *)&out->sm_state - (int *)out)] = 0;
		out->srt_state = wait;
		cpy[((int *)&out->srt_state - (int *)out)] = 0;
		out->srt_ord = FALSE;
		cpy[((int *)&out->srt_ord - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->buffer1 = smv_non_deterministic("buffer1",4,1,2,3,4);
		cpy[((int *)&out->buffer1 - (int *)out)] = 0;
		out->buffer2 = smv_non_deterministic("buffer2",4,1,2,3,4);
		cpy[((int *)&out->buffer2 - (int *)out)] = 0;
		out->buffer3 = smv_non_deterministic("buffer3",4,1,2,3,4);
		cpy[((int *)&out->buffer3 - (int *)out)] = 0;
		out->srt_buffer_aux1 = smv_non_deterministic("srt_buffer_aux1",4,1,2,3,4);
		cpy[((int *)&out->srt_buffer_aux1 - (int *)out)] = 0;
		out->srt_buffer_aux2 = smv_non_deterministic("srt_buffer_aux2",4,1,2,3,4);
		cpy[((int *)&out->srt_buffer_aux2 - (int *)out)] = 0;
		out->srt_buffer_aux3 = smv_non_deterministic("srt_buffer_aux3",4,1,2,3,4);
		cpy[((int *)&out->srt_buffer_aux3 - (int *)out)] = 0;
		out->lock = smv_non_deterministic("lock",2,FALSE,TRUE);
		cpy[((int *)&out->lock - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		out->sim_running = FALSE;
		cpy[((int *)&out->sim_running - (int *)out)] = 0;
		out->sim_state =  ( in->sim_state == new_val && in->sort_OK ? dec :  ( in->sim_state == dec ? new_val : in->sim_state )  ) ;
		cpy[((int *)&out->sim_state - (int *)out)] = 0;
		out->sim_val =  ( in->sim_state == new_val && in->sort_OK && in->bufsize == 1 ? in->buffer1 :  ( in->sim_state == new_val && in->sort_OK && in->bufsize == 2 ? in->buffer2 :  ( in->sim_state == new_val && in->sort_OK && in->bufsize == 3 ? in->buffer3 : in->sim_val )  )  ) ;
		cpy[((int *)&out->sim_val - (int *)out)] = 0;
		out->bufsize =  ( in->sim_state == dec && in->bufsize == 1 ? 0 :  ( in->sim_state == dec && in->bufsize == 2 ? 1 :  ( in->sim_state == dec && in->bufsize == 3 ? 2 : in->bufsize )  )  ) ;
		cpy[((int *)&out->bufsize - (int *)out)] = 0;
		transition_labels[0] = 1;
		transition_info.group = 1;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 2: {
		memcpy(out, in, sizeof(state_t));
		out->sm_running = FALSE;
		cpy[((int *)&out->sm_running - (int *)out)] = 0;
		out->sm_state =  ( in->sm_state == test && in->bufsize<3 ? inc :  ( in->sm_state == test && in->bufsize == 3 ? bufful :  ( in->sm_state == inc ? poebuf :  ( in->sm_state == poebuf ? req :  ( in->sm_state == req ? wait :  ( in->sm_state == wait && in->sort_OK ? test :  ( in->sm_state == bufful && in->bufsize<3 ? poebuf : in->sm_state )  )  )  )  )  )  ) ;
		cpy[((int *)&out->sm_state - (int *)out)] = 0;
		out->bufsize =  ( in->sm_state == inc && in->bufsize<3 ? in->bufsize + 1 : in->bufsize ) ;
		cpy[((int *)&out->bufsize - (int *)out)] = 0;
		out->buffer1 =  ( in->sm_state == poebuf && in->bufsize == 1 ? smv_non_deterministic("buffer1",4,1,2,3,4) : in->buffer1 ) ;
		cpy[((int *)&out->buffer1 - (int *)out)] = 0;
		out->buffer2 =  ( in->sm_state == poebuf && in->bufsize == 2 ? smv_non_deterministic("buffer2",4,1,2,3,4) : in->buffer2 ) ;
		cpy[((int *)&out->buffer2 - (int *)out)] = 0;
		out->buffer3 =  ( in->sm_state == poebuf && in->bufsize == 3 ? smv_non_deterministic("buffer3",4,1,2,3,4) : in->buffer3 ) ;
		cpy[((int *)&out->buffer3 - (int *)out)] = 0;
		out->sort_req =  ( in->sm_state == req ? TRUE : in->sort_req ) ;
		cpy[((int *)&out->sort_req - (int *)out)] = 0;
		out->sort_OK =  ( in->sm_state == poebuf ? FALSE : in->sort_OK ) ;
		cpy[((int *)&out->sort_OK - (int *)out)] = 0;
		transition_labels[0] = 2;
		transition_info.group = 2;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 3: {
		memcpy(out, in, sizeof(state_t));
		out->srt_running = FALSE;
		cpy[((int *)&out->srt_running - (int *)out)] = 0;
		out->srt_state =  ( in->srt_state == wait && in->sort_req ? sort :  ( in->srt_state == sort && in->srt_ord ? subst :  ( in->srt_state == subst ? sort_ready :  ( in->srt_state == sort && !in->srt_ord ? sort :  ( in->srt_state == sort_ready ? wait : in->srt_state )  )  )  )  ) ;
		cpy[((int *)&out->srt_state - (int *)out)] = 0;
		out->srt_buffer_aux1 =  ( in->srt_state == sort && in->buffer2>in->buffer1 && in->bufsize>1 ? in->buffer2 : in->buffer1 ) ;
		cpy[((int *)&out->srt_buffer_aux1 - (int *)out)] = 0;
		out->srt_buffer_aux2 =  ( in->srt_state == sort && in->buffer2>in->buffer1 && in->bufsize>1 ? in->buffer1 :  ( in->srt_state == sort && in->buffer3>in->buffer2 && in->bufsize>2 ? in->buffer3 : in->buffer2 )  ) ;
		cpy[((int *)&out->srt_buffer_aux2 - (int *)out)] = 0;
		out->srt_buffer_aux3 =  ( in->srt_state == sort && in->buffer3>in->buffer2 && in->bufsize>2 ? in->buffer2 : in->buffer3 ) ;
		cpy[((int *)&out->srt_buffer_aux3 - (int *)out)] = 0;
		out->srt_ord =  ( in->srt_state == sort && in->srt_buffer_aux1>in->srt_buffer_aux2 && in->srt_buffer_aux1>in->srt_buffer_aux3 && in->srt_buffer_aux2>in->srt_buffer_aux3 && in->bufsize == 3 ? TRUE :  ( in->srt_state == sort && in->srt_buffer_aux1>in->srt_buffer_aux2 && in->bufsize == 2 ? TRUE :  ( in->srt_state == sort && (in->bufsize == 1 || in->bufsize == 0) ? TRUE : in->srt_ord )  )  ) ;
		cpy[((int *)&out->srt_ord - (int *)out)] = 0;
		out->sort_OK =  ( in->srt_state == sort_ready ? TRUE : in->sort_OK ) ;
		cpy[((int *)&out->sort_OK - (int *)out)] = 0;
		out->sort_req =  ( in->srt_state == sort_ready ? FALSE : in->sort_req ) ;
		cpy[((int *)&out->sort_req - (int *)out)] = 0;
		out->buffer1 =  ( in->srt_state == subst ? in->srt_buffer_aux1 : in->buffer1 ) ;
		cpy[((int *)&out->buffer1 - (int *)out)] = 0;
		out->buffer2 =  ( in->srt_state == subst ? in->srt_buffer_aux2 : in->buffer2 ) ;
		cpy[((int *)&out->buffer2 - (int *)out)] = 0;
		out->buffer3 =  ( in->srt_state == subst ? in->srt_buffer_aux3 : in->buffer3 ) ;
		cpy[((int *)&out->buffer3 - (int *)out)] = 0;
		transition_labels[0] = 3;
		transition_info.group = 3;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 4: {
		memcpy(out, in, sizeof(state_t));
		transition_labels[0] = 4;
		transition_info.group = 4;
		out->sim_running= TRUE;
		cpy[((int *)&out->sim_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->sim_running= FALSE;
		cpy[((int *)&out->sim_running - (int *)out)] = 1;
		out->sm_running= TRUE;
		cpy[((int *)&out->sm_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		out->sm_running= FALSE;
		cpy[((int *)&out->sm_running - (int *)out)] = 1;
		out->srt_running= TRUE;
		cpy[((int *)&out->srt_running - (int *)out)] = 0;
		callback(arg,&transition_info,out,cpy);
		return 3;
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
		if(in->sim_running == TRUE){
			smv_get_actions(model,1,in,callback,arg);
		}
	}
	case 2: {
		if(in->sm_running == TRUE){
			smv_get_actions(model,2,in,callback,arg);
		}
	}
	case 3: {
		if(in->srt_running == TRUE){
			smv_get_actions(model,3,in,callback,arg);
		}
	}
	case 4: {
		if(!((in->virtual_init == TRUE)||(in->sim_running == TRUE)||(in->sm_running == TRUE)||(in->srt_running == TRUE))){
			return smv_get_actions(model,4,in,callback,arg);
		}
	}
	}
}

int smv_get_transition_groups() {
	return 5;
}

int smv_get_label(void* model, int g, state_t* in){
	switch (g){
		case 0: return (in->virtual_init == TRUE)!=0;
		case 1: return (in->sim_running == TRUE) !=0;
		case 2: return (in->sm_running == TRUE) !=0;
		case 3: return (in->srt_running == TRUE) !=0;
		case 4: return !((in->virtual_init == TRUE)||(in->sim_running == TRUE)||(in->sm_running == TRUE)||(in->srt_running == TRUE));
		case 5: return (in->sim_val<=in->buffer1);
		case 6: return (in->sim_val<=in->buffer2);
		case 7: return (in->sim_val<=in->buffer3);
	}
}

int smv_get_label_count() {
	return 8;
}

int *read_m[5] = {
	((int[]){0}),
	((int[]){7,4,15,0,1,2,3,5}),
	((int[]){7,3,7,15,0,1,2,16}),
	((int[]){11,9,13,16,0,1,3,2,10,11,12,15}),
	((int[]){0})
};

int *write_m[5] = {
	((int[]){16,3,15,16,4,5,7,9,13,18,0,1,2,10,11,12,17}),
	((int[]){4,6,4,5,3}),
	((int[]){8,8,7,3,0,1,2,16,15}),
	((int[]){11,14,9,10,11,12,13,15,16,0,1,2}),
	((int[]){3,6,8,14})
};

int *label_m[8] = {
	((int[]){1,18}),
	((int[]){1,6}),
	((int[]){1,8}),
	((int[]){1,14}),
	((int[]){4,6,8,14,18}),
	((int[]){2,0,5}),
	((int[]){2,1,5}),
	((int[]){2,2,5})
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
char pins_plugin_name[] = "prod-cons";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"buffer1");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"buffer2");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"buffer3");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"bufsize");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"sim_state");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"sim_val");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"sim_running");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"sm_state");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"sm_running");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"srt_state");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"srt_buffer_aux1");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"srt_buffer_aux2");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"srt_buffer_aux3");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"srt_ord");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"srt_running");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"sort_OK");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"sort_req");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"lock");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"virtual_init");
	lts_type_set_state_typeno(ltstype, 18,int_type);

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
	lts_type_set_state_label_name (ltstype, 1, "now_sim_running");
	lts_type_set_state_label_typeno (ltstype, 2, bool_type);
	lts_type_set_state_label_name (ltstype, 2, "now_sm_running");
	lts_type_set_state_label_typeno (ltstype, 3, bool_type);
	lts_type_set_state_label_name (ltstype, 3, "now_srt_running");
	lts_type_set_state_label_typeno (ltstype, 4, bool_type);
	lts_type_set_state_label_name (ltstype, 4, "choose_running");
	lts_type_set_state_label_typeno (ltstype, 5, bool_type);
	lts_type_set_state_label_name (ltstype, 5, "valbuf1");
		lts_type_set_state_label_typeno (ltstype, 6, bool_type);
	lts_type_set_state_label_name (ltstype, 6, "valbuf2");
		lts_type_set_state_label_typeno (ltstype, 7, bool_type);
	lts_type_set_state_label_name (ltstype, 7, "valbuf3");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("sim_running"));
	pins_chunk_put(m, action_type, chunk_str("sm_running"));
	pins_chunk_put(m, action_type, chunk_str("srt_running"));
	pins_chunk_put(m, action_type, chunk_str("choose_running"));
	int state[19];
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
