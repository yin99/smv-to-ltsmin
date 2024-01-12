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
	 None, Rd, RdX, Wr, Owned, idle, Ld, St, stable_I, stable_S, stable_M, pend_Rd_I, pend_RdX_I, pend_RdX_S, pend_WB_M, EMPTYENUM0, EMPTYENUM1, EMPTYENUM2,
}smv_enum;

const int smv_get_state_size() {
	return 32;
}

typedef struct state_t {
	smv_enum BUS_CMD;
	boolean BUS_DATA;
	boolean BUS_ADDR;
	smv_enum SNOOP_RESP;
	smv_enum n0_p_mem_req;
	boolean n0_p_eff_addr;
	boolean n0_p_register;
	smv_enum n0_c_impl_state;
	boolean n0_c_data;
	boolean n0_c_tag;
	smv_enum n0_bus_req;
	boolean n0_bus_master;
	smv_enum n1_p_mem_req;
	boolean n1_p_eff_addr;
	boolean n1_p_register;
	smv_enum n1_c_impl_state;
	boolean n1_c_data;
	boolean n1_c_tag;
	smv_enum n1_bus_req;
	boolean n1_bus_master;
	smv_enum n2_p_mem_req;
	boolean n2_p_eff_addr;
	boolean n2_p_register;
	smv_enum n2_c_impl_state;
	boolean n2_c_data;
	boolean n2_c_tag;
	smv_enum n2_bus_req;
	boolean n2_bus_master;
	boolean m_data0;
	boolean m_data1;
	smv_enum last_master;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.BUS_CMD                                = 0,
	.BUS_DATA                               = FALSE,
	.BUS_ADDR                               = FALSE,
	.SNOOP_RESP                             = 0,
	.n0_p_mem_req                           = 0,
	.n0_p_eff_addr                          = FALSE,
	.n0_p_register                          = FALSE,
	.n0_c_impl_state                        = 0,
	.n0_c_data                              = FALSE,
	.n0_c_tag                               = FALSE,
	.n0_bus_req                             = 0,
	.n0_bus_master                          = FALSE,
	.n1_p_mem_req                           = 0,
	.n1_p_eff_addr                          = FALSE,
	.n1_p_register                          = FALSE,
	.n1_c_impl_state                        = 0,
	.n1_c_data                              = FALSE,
	.n1_c_tag                               = FALSE,
	.n1_bus_req                             = 0,
	.n1_bus_master                          = FALSE,
	.n2_p_mem_req                           = 0,
	.n2_p_eff_addr                          = FALSE,
	.n2_p_register                          = FALSE,
	.n2_c_impl_state                        = 0,
	.n2_c_data                              = FALSE,
	.n2_c_tag                               = FALSE,
	.n2_bus_req                             = 0,
	.n2_bus_master                          = FALSE,
	.m_data0                                = FALSE,
	.m_data1                                = FALSE,
	.last_master                            = 0,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"BUS_CMD",1,0x0},
	{"BUS_DATA",1,0x0},
	{"BUS_ADDR",1,0x0},
	{"SNOOP_RESP",1,0x0},
	{"n0_p_mem_req",1,0x0},
	{"n0_p_eff_addr",1,0x0},
	{"n0_p_register",1,0x0},
	{"n0_c_impl_state",1,0x0},
	{"n0_c_data",1,0x0},
	{"n0_c_tag",1,0x0},
	{"n0_bus_req",1,0x0},
	{"n0_bus_master",1,0x0},
	{"n1_p_mem_req",1,0x0},
	{"n1_p_eff_addr",1,0x0},
	{"n1_p_register",1,0x0},
	{"n1_c_impl_state",1,0x0},
	{"n1_c_data",1,0x0},
	{"n1_c_tag",1,0x0},
	{"n1_bus_req",1,0x0},
	{"n1_bus_master",1,0x0},
	{"n2_p_mem_req",1,0x0},
	{"n2_p_eff_addr",1,0x0},
	{"n2_p_register",1,0x0},
	{"n2_c_impl_state",1,0x0},
	{"n2_c_data",1,0x0},
	{"n2_c_tag",1,0x0},
	{"n2_bus_req",1,0x0},
	{"n2_bus_master",1,0x0},
	{"m_data0",1,0x0},
	{"m_data1",1,0x0},
	{"last_master",1,0x0},
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
		int n0_c_invalid;
		int n0_c_shared;
		int n0_c_modified;
		int n0_c_pending;
		int n0_c_snoop_hit;
		int n0_c_satisfied;
		int n0_c_busy;
		int n0_bus_req_addr;
		int n0_bus_req_data;
		int n0_reply_owned;
		int n1_c_invalid;
		int n1_c_shared;
		int n1_c_modified;
		int n1_c_pending;
		int n1_c_snoop_hit;
		int n1_c_satisfied;
		int n1_c_busy;
		int n1_bus_req_addr;
		int n1_bus_req_data;
		int n1_reply_owned;
		int n2_c_invalid;
		int n2_c_shared;
		int n2_c_modified;
		int n2_c_pending;
		int n2_c_snoop_hit;
		int n2_c_satisfied;
		int n2_c_busy;
		int n2_bus_req_addr;
		int n2_bus_req_data;
		int n2_reply_owned;
		n0_c_invalid = (in->n0_c_impl_state == stable_I) || (in->n0_c_impl_state == pend_Rd_I) || (in->n0_c_impl_state == pend_RdX_I);
		n0_c_shared = (in->n0_c_impl_state == stable_S) || (in->n0_c_impl_state == pend_RdX_S);
		n0_c_modified = (in->n0_c_impl_state == stable_M) || (in->n0_c_impl_state == pend_WB_M);
		n0_c_pending = (in->n0_c_impl_state == pend_Rd_I) || (in->n0_c_impl_state == pend_RdX_I) || (in->n0_c_impl_state == pend_RdX_S) || (in->n0_c_impl_state == pend_WB_M);
		n0_c_snoop_hit = (in->BUS_ADDR == in->n0_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n0_c_satisfied = ((in->n0_c_tag == in->n0_p_eff_addr) && (in->n0_p_mem_req == St) && n0_c_modified) || ((in->n0_c_tag == in->n0_p_eff_addr) && (in->n0_p_mem_req == Ld) && (n0_c_shared || n0_c_modified)) || (in->n0_p_mem_req == idle);
		n0_c_busy = n0_c_snoop_hit || !n0_c_satisfied;
		n0_bus_req_addr =  ( (in->n0_bus_req == Wr) ? in->n0_c_tag : in->n0_p_eff_addr ) ;
		n0_bus_req_data = in->n0_c_data;
		n0_reply_owned = (in->BUS_ADDR == in->n0_c_tag) && n0_c_modified;
		n1_c_invalid = (in->n1_c_impl_state == stable_I) || (in->n1_c_impl_state == pend_Rd_I) || (in->n1_c_impl_state == pend_RdX_I);
		n1_c_shared = (in->n1_c_impl_state == stable_S) || (in->n1_c_impl_state == pend_RdX_S);
		n1_c_modified = (in->n1_c_impl_state == stable_M) || (in->n1_c_impl_state == pend_WB_M);
		n1_c_pending = (in->n1_c_impl_state == pend_Rd_I) || (in->n1_c_impl_state == pend_RdX_I) || (in->n1_c_impl_state == pend_RdX_S) || (in->n1_c_impl_state == pend_WB_M);
		n1_c_snoop_hit = (in->BUS_ADDR == in->n1_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n1_c_satisfied = ((in->n1_c_tag == in->n1_p_eff_addr) && (in->n1_p_mem_req == St) && n1_c_modified) || ((in->n1_c_tag == in->n1_p_eff_addr) && (in->n1_p_mem_req == Ld) && (n1_c_shared || n1_c_modified)) || (in->n1_p_mem_req == idle);
		n1_c_busy = n1_c_snoop_hit || !n1_c_satisfied;
		n1_bus_req_addr =  ( (in->n1_bus_req == Wr) ? in->n1_c_tag : in->n1_p_eff_addr ) ;
		n1_bus_req_data = in->n1_c_data;
		n1_reply_owned = (in->BUS_ADDR == in->n1_c_tag) && n1_c_modified;
		n2_c_invalid = (in->n2_c_impl_state == stable_I) || (in->n2_c_impl_state == pend_Rd_I) || (in->n2_c_impl_state == pend_RdX_I);
		n2_c_shared = (in->n2_c_impl_state == stable_S) || (in->n2_c_impl_state == pend_RdX_S);
		n2_c_modified = (in->n2_c_impl_state == stable_M) || (in->n2_c_impl_state == pend_WB_M);
		n2_c_pending = (in->n2_c_impl_state == pend_Rd_I) || (in->n2_c_impl_state == pend_RdX_I) || (in->n2_c_impl_state == pend_RdX_S) || (in->n2_c_impl_state == pend_WB_M);
		n2_c_snoop_hit = (in->BUS_ADDR == in->n2_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n2_c_satisfied = ((in->n2_c_tag == in->n2_p_eff_addr) && (in->n2_p_mem_req == St) && n2_c_modified) || ((in->n2_c_tag == in->n2_p_eff_addr) && (in->n2_p_mem_req == Ld) && (n2_c_shared || n2_c_modified)) || (in->n2_p_mem_req == idle);
		n2_c_busy = n2_c_snoop_hit || !n2_c_satisfied;
		n2_bus_req_addr =  ( (in->n2_bus_req == Wr) ? in->n2_c_tag : in->n2_p_eff_addr ) ;
		n2_bus_req_data = in->n2_c_data;
		n2_reply_owned = (in->BUS_ADDR == in->n2_c_tag) && n2_c_modified;
		out->n0_p_mem_req = idle;
		cpy[((int *)&out->n0_p_mem_req - (int *)out)] = 0;
		out->n0_p_eff_addr = FALSE;
		cpy[((int *)&out->n0_p_eff_addr - (int *)out)] = 0;
		out->n0_p_register = FALSE;
		cpy[((int *)&out->n0_p_register - (int *)out)] = 0;
		out->n0_c_impl_state = stable_I;
		cpy[((int *)&out->n0_c_impl_state - (int *)out)] = 0;
		out->n0_c_data = smv_non_deterministic("n0_c_data",2,FALSE,TRUE);
		cpy[((int *)&out->n0_c_data - (int *)out)] = 0;
		out->n0_c_tag = smv_non_deterministic("n0_c_tag",2,FALSE,TRUE);
		cpy[((int *)&out->n0_c_tag - (int *)out)] = 0;
		out->n1_p_mem_req = idle;
		cpy[((int *)&out->n1_p_mem_req - (int *)out)] = 0;
		out->n1_p_eff_addr = FALSE;
		cpy[((int *)&out->n1_p_eff_addr - (int *)out)] = 0;
		out->n1_p_register = FALSE;
		cpy[((int *)&out->n1_p_register - (int *)out)] = 0;
		out->n1_c_impl_state = stable_I;
		cpy[((int *)&out->n1_c_impl_state - (int *)out)] = 0;
		out->n1_c_data = smv_non_deterministic("n1_c_data",2,FALSE,TRUE);
		cpy[((int *)&out->n1_c_data - (int *)out)] = 0;
		out->n1_c_tag = smv_non_deterministic("n1_c_tag",2,FALSE,TRUE);
		cpy[((int *)&out->n1_c_tag - (int *)out)] = 0;
		out->n2_p_mem_req = idle;
		cpy[((int *)&out->n2_p_mem_req - (int *)out)] = 0;
		out->n2_p_eff_addr = FALSE;
		cpy[((int *)&out->n2_p_eff_addr - (int *)out)] = 0;
		out->n2_p_register = FALSE;
		cpy[((int *)&out->n2_p_register - (int *)out)] = 0;
		out->n2_c_impl_state = stable_I;
		cpy[((int *)&out->n2_c_impl_state - (int *)out)] = 0;
		out->n2_c_data = smv_non_deterministic("n2_c_data",2,FALSE,TRUE);
		cpy[((int *)&out->n2_c_data - (int *)out)] = 0;
		out->n2_c_tag = smv_non_deterministic("n2_c_tag",2,FALSE,TRUE);
		cpy[((int *)&out->n2_c_tag - (int *)out)] = 0;
		out->m_data0 = FALSE;
		cpy[((int *)&out->m_data0 - (int *)out)] = 0;
		out->m_data1 = FALSE;
		cpy[((int *)&out->m_data1 - (int *)out)] = 0;
		out->last_master = smv_non_deterministic("last_master",3,0,1,2);
		cpy[((int *)&out->last_master - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->BUS_CMD = smv_non_deterministic("BUS_CMD",4,None,Rd,RdX,Wr);
		cpy[((int *)&out->BUS_CMD - (int *)out)] = 0;
		out->BUS_DATA = smv_non_deterministic("BUS_DATA",2,FALSE,TRUE);
		cpy[((int *)&out->BUS_DATA - (int *)out)] = 0;
		out->BUS_ADDR = smv_non_deterministic("BUS_ADDR",2,FALSE,TRUE);
		cpy[((int *)&out->BUS_ADDR - (int *)out)] = 0;
		out->SNOOP_RESP = smv_non_deterministic("SNOOP_RESP",2,Owned,None);
		cpy[((int *)&out->SNOOP_RESP - (int *)out)] = 0;
		out->n0_bus_req = smv_non_deterministic("n0_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n0_bus_req - (int *)out)] = 0;
		out->n0_bus_master = smv_non_deterministic("n0_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n0_bus_master - (int *)out)] = 0;
		out->n1_bus_req = smv_non_deterministic("n1_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n1_bus_req - (int *)out)] = 0;
		out->n1_bus_master = smv_non_deterministic("n1_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n1_bus_master - (int *)out)] = 0;
		out->n2_bus_req = smv_non_deterministic("n2_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n2_bus_req - (int *)out)] = 0;
		out->n2_bus_master = smv_non_deterministic("n2_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n2_bus_master - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int n0_c_invalid;
		int n0_c_shared;
		int n0_c_modified;
		int n0_c_pending;
		int n0_c_snoop_hit;
		int n0_c_satisfied;
		int n0_c_busy;
		int n0_bus_req_addr;
		int n0_bus_req_data;
		int n0_reply_owned;
		int n1_c_invalid;
		int n1_c_shared;
		int n1_c_modified;
		int n1_c_pending;
		int n1_c_snoop_hit;
		int n1_c_satisfied;
		int n1_c_busy;
		int n1_bus_req_addr;
		int n1_bus_req_data;
		int n1_reply_owned;
		int n2_c_invalid;
		int n2_c_shared;
		int n2_c_modified;
		int n2_c_pending;
		int n2_c_snoop_hit;
		int n2_c_satisfied;
		int n2_c_busy;
		int n2_bus_req_addr;
		int n2_bus_req_data;
		int n2_reply_owned;
		n0_c_invalid = (in->n0_c_impl_state == stable_I) || (in->n0_c_impl_state == pend_Rd_I) || (in->n0_c_impl_state == pend_RdX_I);
		n0_c_shared = (in->n0_c_impl_state == stable_S) || (in->n0_c_impl_state == pend_RdX_S);
		n0_c_modified = (in->n0_c_impl_state == stable_M) || (in->n0_c_impl_state == pend_WB_M);
		n0_c_pending = (in->n0_c_impl_state == pend_Rd_I) || (in->n0_c_impl_state == pend_RdX_I) || (in->n0_c_impl_state == pend_RdX_S) || (in->n0_c_impl_state == pend_WB_M);
		n0_c_snoop_hit = (in->BUS_ADDR == in->n0_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n0_c_satisfied = ((in->n0_c_tag == in->n0_p_eff_addr) && (in->n0_p_mem_req == St) && n0_c_modified) || ((in->n0_c_tag == in->n0_p_eff_addr) && (in->n0_p_mem_req == Ld) && (n0_c_shared || n0_c_modified)) || (in->n0_p_mem_req == idle);
		n0_c_busy = n0_c_snoop_hit || !n0_c_satisfied;
		n0_bus_req_addr =  ( (in->n0_bus_req == Wr) ? in->n0_c_tag : in->n0_p_eff_addr ) ;
		n0_bus_req_data = in->n0_c_data;
		n0_reply_owned = (in->BUS_ADDR == in->n0_c_tag) && n0_c_modified;
		n1_c_invalid = (in->n1_c_impl_state == stable_I) || (in->n1_c_impl_state == pend_Rd_I) || (in->n1_c_impl_state == pend_RdX_I);
		n1_c_shared = (in->n1_c_impl_state == stable_S) || (in->n1_c_impl_state == pend_RdX_S);
		n1_c_modified = (in->n1_c_impl_state == stable_M) || (in->n1_c_impl_state == pend_WB_M);
		n1_c_pending = (in->n1_c_impl_state == pend_Rd_I) || (in->n1_c_impl_state == pend_RdX_I) || (in->n1_c_impl_state == pend_RdX_S) || (in->n1_c_impl_state == pend_WB_M);
		n1_c_snoop_hit = (in->BUS_ADDR == in->n1_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n1_c_satisfied = ((in->n1_c_tag == in->n1_p_eff_addr) && (in->n1_p_mem_req == St) && n1_c_modified) || ((in->n1_c_tag == in->n1_p_eff_addr) && (in->n1_p_mem_req == Ld) && (n1_c_shared || n1_c_modified)) || (in->n1_p_mem_req == idle);
		n1_c_busy = n1_c_snoop_hit || !n1_c_satisfied;
		n1_bus_req_addr =  ( (in->n1_bus_req == Wr) ? in->n1_c_tag : in->n1_p_eff_addr ) ;
		n1_bus_req_data = in->n1_c_data;
		n1_reply_owned = (in->BUS_ADDR == in->n1_c_tag) && n1_c_modified;
		n2_c_invalid = (in->n2_c_impl_state == stable_I) || (in->n2_c_impl_state == pend_Rd_I) || (in->n2_c_impl_state == pend_RdX_I);
		n2_c_shared = (in->n2_c_impl_state == stable_S) || (in->n2_c_impl_state == pend_RdX_S);
		n2_c_modified = (in->n2_c_impl_state == stable_M) || (in->n2_c_impl_state == pend_WB_M);
		n2_c_pending = (in->n2_c_impl_state == pend_Rd_I) || (in->n2_c_impl_state == pend_RdX_I) || (in->n2_c_impl_state == pend_RdX_S) || (in->n2_c_impl_state == pend_WB_M);
		n2_c_snoop_hit = (in->BUS_ADDR == in->n2_c_tag) && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX));
		n2_c_satisfied = ((in->n2_c_tag == in->n2_p_eff_addr) && (in->n2_p_mem_req == St) && n2_c_modified) || ((in->n2_c_tag == in->n2_p_eff_addr) && (in->n2_p_mem_req == Ld) && (n2_c_shared || n2_c_modified)) || (in->n2_p_mem_req == idle);
		n2_c_busy = n2_c_snoop_hit || !n2_c_satisfied;
		n2_bus_req_addr =  ( (in->n2_bus_req == Wr) ? in->n2_c_tag : in->n2_p_eff_addr ) ;
		n2_bus_req_data = in->n2_c_data;
		n2_reply_owned = (in->BUS_ADDR == in->n2_c_tag) && n2_c_modified;
		out->n0_p_mem_req =  ( !n0_c_busy ? smv_non_deterministic("n0_p_mem_req",3,idle,Ld,St) : in->n0_p_mem_req ) ;
		cpy[((int *)&out->n0_p_mem_req - (int *)out)] = 0;
		out->n0_p_eff_addr =  ( !n0_c_busy ? smv_non_deterministic("n0_p_eff_addr",2,FALSE,TRUE) : in->n0_p_eff_addr ) ;
		cpy[((int *)&out->n0_p_eff_addr - (int *)out)] = 0;
		out->n0_p_register =  ( !n0_c_busy && (in->n0_p_mem_req == St) ? in->n0_p_register :  ( !n0_c_busy && (in->n0_p_mem_req == Ld) ? in->n0_c_data : smv_non_deterministic("n0_p_register",2,FALSE,TRUE) )  ) ;
		cpy[((int *)&out->n0_p_register - (int *)out)] = 0;
		out->n0_c_impl_state =  ( in->n0_bus_master ?  ( in->n0_c_impl_state == pend_Rd_I ? stable_S :  ( in->n0_c_impl_state == pend_RdX_I ? stable_M :  ( in->n0_c_impl_state == pend_RdX_S ? stable_M :  ( in->n0_c_impl_state == pend_WB_M ? stable_I : in->n0_c_impl_state )  )  )  )  :  ( !in->n0_bus_master && (in->BUS_CMD == Rd) && (in->n0_c_tag == in->BUS_ADDR) ?  ( in->n0_c_impl_state == stable_M ? stable_S :  ( in->n0_c_impl_state == pend_WB_M ? stable_I : in->n0_c_impl_state )  )  :  ( !in->n0_bus_master && (in->BUS_CMD == RdX) && (in->n0_c_tag == in->BUS_ADDR) ?  ( in->n0_c_impl_state == stable_S ? stable_I :  ( in->n0_c_impl_state == stable_M ? stable_I :  ( in->n0_c_impl_state == pend_RdX_S ? pend_RdX_I :  ( in->n0_c_impl_state == pend_WB_M ? stable_I : in->n0_c_impl_state )  )  )  )  :  ( !in->n0_bus_master && (in->n0_p_mem_req == Ld) && (in->n0_c_tag == in->n0_p_eff_addr) ?  ( in->n0_c_impl_state == stable_I ? pend_Rd_I : in->n0_c_impl_state )  :  ( !in->n0_bus_master && (in->n0_p_mem_req == St) && (in->n0_c_tag == in->n0_p_eff_addr) ?  ( in->n0_c_impl_state == stable_S ? pend_RdX_S :  ( in->n0_c_impl_state == stable_I ? pend_RdX_I : in->n0_c_impl_state )  )  :  ( !in->n0_bus_master && (in->n0_p_mem_req == Ld) && !(in->n0_c_tag == in->n0_p_eff_addr) ?  ( in->n0_c_impl_state == stable_I ? pend_Rd_I :  ( in->n0_c_impl_state == stable_S ? pend_Rd_I :  ( in->n0_c_impl_state == stable_M ? pend_WB_M : in->n0_c_impl_state )  )  )  :  ( !in->n0_bus_master && (in->n0_p_mem_req == St) && !(in->n0_c_tag == in->n0_p_eff_addr) ?  ( in->n0_c_impl_state == stable_I ? pend_RdX_I :  ( in->n0_c_impl_state == stable_S ? pend_RdX_I :  ( in->n0_c_impl_state == stable_M ? pend_WB_M : in->n0_c_impl_state )  )  )  : in->n0_c_impl_state )  )  )  )  )  )  ) ;
		cpy[((int *)&out->n0_c_impl_state - (int *)out)] = 0;
		out->n0_c_data =  ( (in->n0_c_impl_state == stable_M) && (in->n0_c_tag == in->n0_p_eff_addr) && (in->n0_p_mem_req == St) ? in->n0_p_register :  ( in->n0_bus_master && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX)) ? in->BUS_DATA : in->n0_c_data )  ) ;
		cpy[((int *)&out->n0_c_data - (int *)out)] = 0;
		out->n0_c_tag =  ( in->n0_bus_master && (in->BUS_CMD == Rd) ? in->BUS_ADDR :  ( in->n0_bus_master && (in->BUS_CMD == RdX) ? in->BUS_ADDR : in->n0_c_tag )  ) ;
		cpy[((int *)&out->n0_c_tag - (int *)out)] = 0;
		out->n1_p_mem_req =  ( !n1_c_busy ? smv_non_deterministic("n1_p_mem_req",3,idle,Ld,St) : in->n1_p_mem_req ) ;
		cpy[((int *)&out->n1_p_mem_req - (int *)out)] = 0;
		out->n1_p_eff_addr =  ( !n1_c_busy ? smv_non_deterministic("n1_p_eff_addr",2,FALSE,TRUE) : in->n1_p_eff_addr ) ;
		cpy[((int *)&out->n1_p_eff_addr - (int *)out)] = 0;
		out->n1_p_register =  ( !n1_c_busy && (in->n1_p_mem_req == St) ? in->n1_p_register :  ( !n1_c_busy && (in->n1_p_mem_req == Ld) ? in->n1_c_data : smv_non_deterministic("n1_p_register",2,FALSE,TRUE) )  ) ;
		cpy[((int *)&out->n1_p_register - (int *)out)] = 0;
		out->n1_c_impl_state =  ( in->n1_bus_master ?  ( in->n1_c_impl_state == pend_Rd_I ? stable_S :  ( in->n1_c_impl_state == pend_RdX_I ? stable_M :  ( in->n1_c_impl_state == pend_RdX_S ? stable_M :  ( in->n1_c_impl_state == pend_WB_M ? stable_I : in->n1_c_impl_state )  )  )  )  :  ( !in->n1_bus_master && (in->BUS_CMD == Rd) && (in->n1_c_tag == in->BUS_ADDR) ?  ( in->n1_c_impl_state == stable_M ? stable_S :  ( in->n1_c_impl_state == pend_WB_M ? stable_I : in->n1_c_impl_state )  )  :  ( !in->n1_bus_master && (in->BUS_CMD == RdX) && (in->n1_c_tag == in->BUS_ADDR) ?  ( in->n1_c_impl_state == stable_S ? stable_I :  ( in->n1_c_impl_state == stable_M ? stable_I :  ( in->n1_c_impl_state == pend_RdX_S ? pend_RdX_I :  ( in->n1_c_impl_state == pend_WB_M ? stable_I : in->n1_c_impl_state )  )  )  )  :  ( !in->n1_bus_master && (in->n1_p_mem_req == Ld) && (in->n1_c_tag == in->n1_p_eff_addr) ?  ( in->n1_c_impl_state == stable_I ? pend_Rd_I : in->n1_c_impl_state )  :  ( !in->n1_bus_master && (in->n1_p_mem_req == St) && (in->n1_c_tag == in->n1_p_eff_addr) ?  ( in->n1_c_impl_state == stable_S ? pend_RdX_S :  ( in->n1_c_impl_state == stable_I ? pend_RdX_I : in->n1_c_impl_state )  )  :  ( !in->n1_bus_master && (in->n1_p_mem_req == Ld) && !(in->n1_c_tag == in->n1_p_eff_addr) ?  ( in->n1_c_impl_state == stable_I ? pend_Rd_I :  ( in->n1_c_impl_state == stable_S ? pend_Rd_I :  ( in->n1_c_impl_state == stable_M ? pend_WB_M : in->n1_c_impl_state )  )  )  :  ( !in->n1_bus_master && (in->n1_p_mem_req == St) && !(in->n1_c_tag == in->n1_p_eff_addr) ?  ( in->n1_c_impl_state == stable_I ? pend_RdX_I :  ( in->n1_c_impl_state == stable_S ? pend_RdX_I :  ( in->n1_c_impl_state == stable_M ? pend_WB_M : in->n1_c_impl_state )  )  )  : in->n1_c_impl_state )  )  )  )  )  )  ) ;
		cpy[((int *)&out->n1_c_impl_state - (int *)out)] = 0;
		out->n1_c_data =  ( (in->n1_c_impl_state == stable_M) && (in->n1_c_tag == in->n1_p_eff_addr) && (in->n1_p_mem_req == St) ? in->n1_p_register :  ( in->n1_bus_master && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX)) ? in->BUS_DATA : in->n1_c_data )  ) ;
		cpy[((int *)&out->n1_c_data - (int *)out)] = 0;
		out->n1_c_tag =  ( in->n1_bus_master && (in->BUS_CMD == Rd) ? in->BUS_ADDR :  ( in->n1_bus_master && (in->BUS_CMD == RdX) ? in->BUS_ADDR : in->n1_c_tag )  ) ;
		cpy[((int *)&out->n1_c_tag - (int *)out)] = 0;
		out->n2_p_mem_req =  ( !n2_c_busy ? smv_non_deterministic("n2_p_mem_req",3,idle,Ld,St) : in->n2_p_mem_req ) ;
		cpy[((int *)&out->n2_p_mem_req - (int *)out)] = 0;
		out->n2_p_eff_addr =  ( !n2_c_busy ? smv_non_deterministic("n2_p_eff_addr",2,FALSE,TRUE) : in->n2_p_eff_addr ) ;
		cpy[((int *)&out->n2_p_eff_addr - (int *)out)] = 0;
		out->n2_p_register =  ( !n2_c_busy && (in->n2_p_mem_req == St) ? in->n2_p_register :  ( !n2_c_busy && (in->n2_p_mem_req == Ld) ? in->n2_c_data : smv_non_deterministic("n2_p_register",2,FALSE,TRUE) )  ) ;
		cpy[((int *)&out->n2_p_register - (int *)out)] = 0;
		out->n2_c_impl_state =  ( in->n2_bus_master ?  ( in->n2_c_impl_state == pend_Rd_I ? stable_S :  ( in->n2_c_impl_state == pend_RdX_I ? stable_M :  ( in->n2_c_impl_state == pend_RdX_S ? stable_M :  ( in->n2_c_impl_state == pend_WB_M ? stable_I : in->n2_c_impl_state )  )  )  )  :  ( !in->n2_bus_master && (in->BUS_CMD == Rd) && (in->n2_c_tag == in->BUS_ADDR) ?  ( in->n2_c_impl_state == stable_M ? stable_S :  ( in->n2_c_impl_state == pend_WB_M ? stable_I : in->n2_c_impl_state )  )  :  ( !in->n2_bus_master && (in->BUS_CMD == RdX) && (in->n2_c_tag == in->BUS_ADDR) ?  ( in->n2_c_impl_state == stable_S ? stable_I :  ( in->n2_c_impl_state == stable_M ? stable_I :  ( in->n2_c_impl_state == pend_RdX_S ? pend_RdX_I :  ( in->n2_c_impl_state == pend_WB_M ? stable_I : in->n2_c_impl_state )  )  )  )  :  ( !in->n2_bus_master && (in->n2_p_mem_req == Ld) && (in->n2_c_tag == in->n2_p_eff_addr) ?  ( in->n2_c_impl_state == stable_I ? pend_Rd_I : in->n2_c_impl_state )  :  ( !in->n2_bus_master && (in->n2_p_mem_req == St) && (in->n2_c_tag == in->n2_p_eff_addr) ?  ( in->n2_c_impl_state == stable_S ? pend_RdX_S :  ( in->n2_c_impl_state == stable_I ? pend_RdX_I : in->n2_c_impl_state )  )  :  ( !in->n2_bus_master && (in->n2_p_mem_req == Ld) && !(in->n2_c_tag == in->n2_p_eff_addr) ?  ( in->n2_c_impl_state == stable_I ? pend_Rd_I :  ( in->n2_c_impl_state == stable_S ? pend_Rd_I :  ( in->n2_c_impl_state == stable_M ? pend_WB_M : in->n2_c_impl_state )  )  )  :  ( !in->n2_bus_master && (in->n2_p_mem_req == St) && !(in->n2_c_tag == in->n2_p_eff_addr) ?  ( in->n2_c_impl_state == stable_I ? pend_RdX_I :  ( in->n2_c_impl_state == stable_S ? pend_RdX_I :  ( in->n2_c_impl_state == stable_M ? pend_WB_M : in->n2_c_impl_state )  )  )  : in->n2_c_impl_state )  )  )  )  )  )  ) ;
		cpy[((int *)&out->n2_c_impl_state - (int *)out)] = 0;
		out->n2_c_data =  ( (in->n2_c_impl_state == stable_M) && (in->n2_c_tag == in->n2_p_eff_addr) && (in->n2_p_mem_req == St) ? in->n2_p_register :  ( in->n2_bus_master && ((in->BUS_CMD == Rd) || (in->BUS_CMD == RdX)) ? in->BUS_DATA : in->n2_c_data )  ) ;
		cpy[((int *)&out->n2_c_data - (int *)out)] = 0;
		out->n2_c_tag =  ( in->n2_bus_master && (in->BUS_CMD == Rd) ? in->BUS_ADDR :  ( in->n2_bus_master && (in->BUS_CMD == RdX) ? in->BUS_ADDR : in->n2_c_tag )  ) ;
		cpy[((int *)&out->n2_c_tag - (int *)out)] = 0;
		out->m_data0 =  ( ((in->BUS_CMD == RdX) || (in->BUS_CMD == Rd)) && (in->SNOOP_RESP == Owned) && (in->BUS_ADDR == FALSE) ? in->BUS_DATA :  ( (in->BUS_CMD == Wr) && (in->BUS_ADDR == FALSE) ? in->BUS_DATA : in->m_data0 )  ) ;
		cpy[((int *)&out->m_data0 - (int *)out)] = 0;
		out->m_data1 =  ( ((in->BUS_CMD == RdX) || (in->BUS_CMD == Rd)) && (in->SNOOP_RESP == Owned) && (in->BUS_ADDR == TRUE) ? in->BUS_DATA :  ( (in->BUS_CMD == Wr) && (in->BUS_ADDR == TRUE) ? in->BUS_DATA : in->m_data1 )  ) ;
		cpy[((int *)&out->m_data1 - (int *)out)] = 0;
		out->last_master =  ( in->n0_bus_master ? 0 :  ( in->n1_bus_master ? 1 :  ( in->n2_bus_master ? 2 : in->last_master )  )  ) ;
		cpy[((int *)&out->last_master - (int *)out)] = 0;
		out->BUS_CMD = smv_non_deterministic("BUS_CMD",4,None,Rd,RdX,Wr);
		cpy[((int *)&out->BUS_CMD - (int *)out)] = 0;
		out->BUS_DATA = smv_non_deterministic("BUS_DATA",2,FALSE,TRUE);
		cpy[((int *)&out->BUS_DATA - (int *)out)] = 0;
		out->BUS_ADDR = smv_non_deterministic("BUS_ADDR",2,FALSE,TRUE);
		cpy[((int *)&out->BUS_ADDR - (int *)out)] = 0;
		out->SNOOP_RESP = smv_non_deterministic("SNOOP_RESP",2,Owned,None);
		cpy[((int *)&out->SNOOP_RESP - (int *)out)] = 0;
		out->n0_bus_req = smv_non_deterministic("n0_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n0_bus_req - (int *)out)] = 0;
		out->n0_bus_master = smv_non_deterministic("n0_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n0_bus_master - (int *)out)] = 0;
		out->n1_bus_req = smv_non_deterministic("n1_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n1_bus_req - (int *)out)] = 0;
		out->n1_bus_master = smv_non_deterministic("n1_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n1_bus_master - (int *)out)] = 0;
		out->n2_bus_req = smv_non_deterministic("n2_bus_req",4,Rd,RdX,Wr,None);
		cpy[((int *)&out->n2_bus_req - (int *)out)] = 0;
		out->n2_bus_master = smv_non_deterministic("n2_bus_master",2,FALSE,TRUE);
		cpy[((int *)&out->n2_bus_master - (int *)out)] = 0;
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
	((int[]){7,8,9,16,17,24,25,30}),
	((int[]){28,4,5,6,8,0,2,7,9,11,1,12,13,14,16,15,17,19,20,21,22,24,23,25,27,3,28,29,30})
};

int *write_m[2] = {
	((int[]){32,4,5,6,7,8,9,12,13,14,15,16,17,20,21,22,23,24,25,28,29,30,31,0,1,2,3,10,11,18,19,26,27}),
	((int[]){31,4,5,6,7,8,9,12,13,14,15,16,17,20,21,22,23,24,25,28,29,30,0,1,2,3,10,11,18,19,26,27})
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
char pins_plugin_name[] = "msi_wtrans";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"BUS_CMD");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"BUS_DATA");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"BUS_ADDR");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"SNOOP_RESP");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"n0_p_mem_req");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"n0_p_eff_addr");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"n0_p_register");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"n0_c_impl_state");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"n0_c_data");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"n0_c_tag");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"n0_bus_req");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"n0_bus_master");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"n1_p_mem_req");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"n1_p_eff_addr");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"n1_p_register");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"n1_c_impl_state");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"n1_c_data");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"n1_c_tag");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"n1_bus_req");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"n1_bus_master");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"n2_p_mem_req");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"n2_p_eff_addr");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"n2_p_register");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"n2_c_impl_state");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"n2_c_data");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"n2_c_tag");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"n2_bus_req");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"n2_bus_master");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"m_data0");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"m_data1");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"last_master");
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
