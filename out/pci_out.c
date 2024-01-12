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
	 FP, RR, EMPTYENUM0, EMPTYENUM1, EMPTYENUM2, EMPTYENUM3, EMPTYENUM4, EMPTYENUM5, idle, address, data, IDLE, MEM_READ, MEM_WRITE,
}smv_enum;

const int smv_get_state_size() {
	return 41;
}

typedef struct state_t {
	smv_enum arb_policy0;
	smv_enum arb_policy1;
	smv_enum arb_policy2;
	smv_enum arb_policy3;
	smv_enum arb_bank0_last;
	smv_enum arb_bank1_last;
	smv_enum arb_bank2_last;
	smv_enum arb_bank3_last;
	smv_enum arb_grant;
	boolean isa_bridge_req;
	smv_enum isa_bridge_state;
	int isa_bridge__count;
	smv_enum isa_bridge_c_bd;
	boolean isa_bridge_irdy;
	boolean isa_bridge_trdy;
	boolean isa_bridge_issue_next;
	boolean scsi_ctrl_req;
	smv_enum scsi_ctrl_state;
	int scsi_ctrl__count;
	smv_enum scsi_ctrl_c_bd;
	boolean scsi_ctrl_irdy;
	boolean scsi_ctrl_trdy;
	boolean scsi_ctrl_issue_next;
	boolean vga_ctrl_req;
	smv_enum vga_ctrl_state;
	int vga_ctrl__count;
	smv_enum vga_ctrl_c_bd;
	boolean vga_ctrl_irdy;
	boolean vga_ctrl_trdy;
	boolean vga_ctrl_issue_next;
	boolean processor_req;
	smv_enum processor_state;
	int processor__count;
	smv_enum processor_c_bd;
	boolean processor_irdy;
	boolean processor_trdy;
	boolean processor_issue_next;
	boolean b_frame_old;
	int abort_count;
	boolean abort_random;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.arb_policy0                            = 0,
	.arb_policy1                            = 0,
	.arb_policy2                            = 0,
	.arb_policy3                            = 0,
	.arb_bank0_last                         = 0,
	.arb_bank1_last                         = 0,
	.arb_bank2_last                         = 0,
	.arb_bank3_last                         = 0,
	.arb_grant                              = 0,
	.isa_bridge_req                         = FALSE,
	.isa_bridge_state                       = 0,
	.isa_bridge__count                      = 0,
	.isa_bridge_c_bd                        = 0,
	.isa_bridge_irdy                        = FALSE,
	.isa_bridge_trdy                        = FALSE,
	.isa_bridge_issue_next                  = FALSE,
	.scsi_ctrl_req                          = FALSE,
	.scsi_ctrl_state                        = 0,
	.scsi_ctrl__count                       = 0,
	.scsi_ctrl_c_bd                         = 0,
	.scsi_ctrl_irdy                         = FALSE,
	.scsi_ctrl_trdy                         = FALSE,
	.scsi_ctrl_issue_next                   = FALSE,
	.vga_ctrl_req                           = FALSE,
	.vga_ctrl_state                         = 0,
	.vga_ctrl__count                        = 0,
	.vga_ctrl_c_bd                          = 0,
	.vga_ctrl_irdy                          = FALSE,
	.vga_ctrl_trdy                          = FALSE,
	.vga_ctrl_issue_next                    = FALSE,
	.processor_req                          = FALSE,
	.processor_state                        = 0,
	.processor__count                       = 0,
	.processor_c_bd                         = 0,
	.processor_irdy                         = FALSE,
	.processor_trdy                         = FALSE,
	.processor_issue_next                   = FALSE,
	.b_frame_old                            = FALSE,
	.abort_count                            = 0,
	.abort_random                           = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"arb_policy0",1,0x0},
	{"arb_policy1",1,0x0},
	{"arb_policy2",1,0x0},
	{"arb_policy3",1,0x0},
	{"arb_bank0_last",1,0x0},
	{"arb_bank1_last",1,0x0},
	{"arb_bank2_last",1,0x0},
	{"arb_bank3_last",1,0x0},
	{"arb_grant",1,0x0},
	{"isa_bridge_req",1,0x0},
	{"isa_bridge_state",1,0x0},
	{"isa_bridge__count",1,0x0},
	{"isa_bridge_c_bd",1,0x0},
	{"isa_bridge_irdy",1,0x0},
	{"isa_bridge_trdy",1,0x0},
	{"isa_bridge_issue_next",1,0x0},
	{"scsi_ctrl_req",1,0x0},
	{"scsi_ctrl_state",1,0x0},
	{"scsi_ctrl__count",1,0x0},
	{"scsi_ctrl_c_bd",1,0x0},
	{"scsi_ctrl_irdy",1,0x0},
	{"scsi_ctrl_trdy",1,0x0},
	{"scsi_ctrl_issue_next",1,0x0},
	{"vga_ctrl_req",1,0x0},
	{"vga_ctrl_state",1,0x0},
	{"vga_ctrl__count",1,0x0},
	{"vga_ctrl_c_bd",1,0x0},
	{"vga_ctrl_irdy",1,0x0},
	{"vga_ctrl_trdy",1,0x0},
	{"vga_ctrl_issue_next",1,0x0},
	{"processor_req",1,0x0},
	{"processor_state",1,0x0},
	{"processor__count",1,0x0},
	{"processor_c_bd",1,0x0},
	{"processor_irdy",1,0x0},
	{"processor_trdy",1,0x0},
	{"processor_issue_next",1,0x0},
	{"b_frame_old",1,0x0},
	{"abort_count",1,0x0},
	{"abort_random",1,0x0},
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
	int cpy[41] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int arb_bank0_grant;
		int arb_bank1_grant;
		int arb_bank2_grant;
		int arb_bank3_grant;
		int arb_reqbank0;
		int arb_reqbank1;
		int arb_reqbank3;
		int arb_change_now;
		int isa_bridge_ad;
		int isa_bridge_bus_idle;
		int isa_bridge_start_transaction;
		int isa_bridge_end_transaction;
		int isa_bridge_frame;
		int scsi_ctrl_ad;
		int scsi_ctrl_bus_idle;
		int scsi_ctrl_start_transaction;
		int scsi_ctrl_end_transaction;
		int scsi_ctrl_frame;
		int vga_ctrl_ad;
		int vga_ctrl_bus_idle;
		int vga_ctrl_start_transaction;
		int vga_ctrl_end_transaction;
		int vga_ctrl_frame;
		int slot0_c_bd;
		int slot0_ad;
		int slot0_frame;
		int slot0_irdy;
		int slot0_trdy;
		int slot0_req;
		int processor_ad;
		int processor_bus_idle;
		int processor_start_transaction;
		int processor_end_transaction;
		int processor_frame;
		int slot1_c_bd;
		int slot1_ad;
		int slot1_frame;
		int slot1_irdy;
		int slot1_trdy;
		int slot1_req;
		int b_frame;
		int b_irdy;
		int b_trdy;
		int b_c_bd;
		int bus_idle;
		int b_frame_switch;
		int abort;
		arb_bank0_grant =  ( in->arb_policy0 == FP ?  ( in->isa_bridge_req ? 0 :  ( in->scsi_ctrl_req ? 1 : idle )  )  :  ( in->arb_bank0_last == 0 ?  ( in->scsi_ctrl_req ? 1 :  ( in->isa_bridge_req ? 0 : idle )  )  :  ( in->isa_bridge_req ? 0 :  ( in->scsi_ctrl_req ? 1 : idle )  )  )  ) ;
		arb_bank1_grant =  ( in->arb_policy1 == FP ?  ( in->vga_ctrl_req ? 0 :  ( slot0_req ? 1 : idle )  )  :  ( in->arb_bank1_last == 0 ?  ( slot0_req ? 1 :  ( in->vga_ctrl_req ? 0 : idle )  )  :  ( in->vga_ctrl_req ? 0 :  ( slot0_req ? 1 : idle )  )  )  ) ;
		arb_bank2_grant =  ( in->arb_policy2 == FP ?  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 : idle )  )  )  :  ( in->arb_bank2_last == 0 ?  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 :  ( arb_reqbank0 ? 0 : idle )  )  )  :  ( in->arb_bank2_last == 1 ?  ( arb_reqbank3 ? 2 :  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 : idle )  )  )  :  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 : idle )  )  )  )  )  ) ;
		arb_bank3_grant =  ( in->arb_policy3 == FP ?  ( in->processor_req ? 0 :  ( slot1_req ? 1 : idle )  )  :  ( in->arb_bank3_last == 0 ?  ( slot1_req ? 1 :  ( in->processor_req ? 0 : idle )  )  :  ( in->processor_req ? 0 :  ( slot1_req ? 1 : idle )  )  )  ) ;
		arb_reqbank0 = !(arb_bank0_grant == idle);
		arb_reqbank1 = !(arb_bank1_grant == idle);
		arb_reqbank3 = !(arb_bank3_grant == idle);
		arb_change_now = !(!b_frame_switch && in->arb_grant!=idle);
		isa_bridge_ad = 0;
		isa_bridge_bus_idle = !b_frame && !b_irdy;
		isa_bridge_start_transaction = (in->arb_grant == 0) && isa_bridge_bus_idle;
		isa_bridge_end_transaction = (in->isa_bridge_state == data) && (in->isa_bridge__count == 0);
		isa_bridge_frame = (in->isa_bridge_state == address) || ((in->isa_bridge_state == data) && (in->isa_bridge__count>0));
		scsi_ctrl_ad = 0;
		scsi_ctrl_bus_idle = !b_frame && !b_irdy;
		scsi_ctrl_start_transaction = (in->arb_grant == 1) && scsi_ctrl_bus_idle;
		scsi_ctrl_end_transaction = (in->scsi_ctrl_state == data) && (in->scsi_ctrl__count == 0);
		scsi_ctrl_frame = (in->scsi_ctrl_state == address) || ((in->scsi_ctrl_state == data) && (in->scsi_ctrl__count>0));
		vga_ctrl_ad = 0;
		vga_ctrl_bus_idle = !b_frame && !b_irdy;
		vga_ctrl_start_transaction = (in->arb_grant == 2) && vga_ctrl_bus_idle;
		vga_ctrl_end_transaction = (in->vga_ctrl_state == data) && (in->vga_ctrl__count == 0);
		vga_ctrl_frame = (in->vga_ctrl_state == address) || ((in->vga_ctrl_state == data) && (in->vga_ctrl__count>0));
		slot0_c_bd = 0;
		slot0_ad = 0;
		slot0_frame = FALSE;
		slot0_irdy = FALSE;
		slot0_trdy = FALSE;
		slot0_req = FALSE;
		processor_ad = 0;
		processor_bus_idle = !b_frame && !b_irdy;
		processor_start_transaction = (in->arb_grant == 4) && processor_bus_idle;
		processor_end_transaction = (in->processor_state == data) && (in->processor__count == 0);
		processor_frame = (in->processor_state == address) || ((in->processor_state == data) && (in->processor__count>0));
		slot1_c_bd = 0;
		slot1_ad = 0;
		slot1_frame = FALSE;
		slot1_irdy = FALSE;
		slot1_trdy = FALSE;
		slot1_req = FALSE;
		b_frame = isa_bridge_frame || scsi_ctrl_frame || vga_ctrl_frame || slot0_frame || processor_frame || slot1_frame;
		b_irdy = in->isa_bridge_irdy || in->scsi_ctrl_irdy || in->vga_ctrl_irdy || slot0_irdy || in->processor_irdy || slot1_irdy;
		b_trdy = in->isa_bridge_trdy || in->scsi_ctrl_trdy || in->vga_ctrl_trdy || slot0_trdy || in->processor_trdy || slot1_trdy;
		b_c_bd =  ( isa_bridge_frame ? in->isa_bridge_c_bd :  ( scsi_ctrl_frame ? in->scsi_ctrl_c_bd :  ( vga_ctrl_frame ? in->vga_ctrl_c_bd :  ( slot0_frame ? slot0_c_bd :  ( processor_frame ? in->processor_c_bd : slot1_c_bd )  )  )  )  ) ;
		bus_idle = !b_frame && !b_irdy;
		b_frame_switch = b_frame && !in->b_frame_old;
		abort = in->abort_random && b_frame;
		out->arb_bank0_last = 0;
		cpy[((int *)&out->arb_bank0_last - (int *)out)] = 0;
		out->arb_bank1_last = 0;
		cpy[((int *)&out->arb_bank1_last - (int *)out)] = 0;
		out->arb_bank2_last = 0;
		cpy[((int *)&out->arb_bank2_last - (int *)out)] = 0;
		out->arb_bank3_last = 0;
		cpy[((int *)&out->arb_bank3_last - (int *)out)] = 0;
		out->arb_grant = idle;
		cpy[((int *)&out->arb_grant - (int *)out)] = 0;
		out->isa_bridge_req = FALSE;
		cpy[((int *)&out->isa_bridge_req - (int *)out)] = 0;
		out->isa_bridge_state = idle;
		cpy[((int *)&out->isa_bridge_state - (int *)out)] = 0;
		out->isa_bridge__count = 0;
		cpy[((int *)&out->isa_bridge__count - (int *)out)] = 0;
		out->isa_bridge_c_bd = IDLE;
		cpy[((int *)&out->isa_bridge_c_bd - (int *)out)] = 0;
		out->isa_bridge_irdy = FALSE;
		cpy[((int *)&out->isa_bridge_irdy - (int *)out)] = 0;
		out->isa_bridge_trdy = FALSE;
		cpy[((int *)&out->isa_bridge_trdy - (int *)out)] = 0;
		out->scsi_ctrl_req = FALSE;
		cpy[((int *)&out->scsi_ctrl_req - (int *)out)] = 0;
		out->scsi_ctrl_state = idle;
		cpy[((int *)&out->scsi_ctrl_state - (int *)out)] = 0;
		out->scsi_ctrl__count = 0;
		cpy[((int *)&out->scsi_ctrl__count - (int *)out)] = 0;
		out->scsi_ctrl_c_bd = IDLE;
		cpy[((int *)&out->scsi_ctrl_c_bd - (int *)out)] = 0;
		out->scsi_ctrl_irdy = FALSE;
		cpy[((int *)&out->scsi_ctrl_irdy - (int *)out)] = 0;
		out->scsi_ctrl_trdy = FALSE;
		cpy[((int *)&out->scsi_ctrl_trdy - (int *)out)] = 0;
		out->vga_ctrl_req = FALSE;
		cpy[((int *)&out->vga_ctrl_req - (int *)out)] = 0;
		out->vga_ctrl_state = idle;
		cpy[((int *)&out->vga_ctrl_state - (int *)out)] = 0;
		out->vga_ctrl__count = 0;
		cpy[((int *)&out->vga_ctrl__count - (int *)out)] = 0;
		out->vga_ctrl_c_bd = IDLE;
		cpy[((int *)&out->vga_ctrl_c_bd - (int *)out)] = 0;
		out->vga_ctrl_irdy = FALSE;
		cpy[((int *)&out->vga_ctrl_irdy - (int *)out)] = 0;
		out->vga_ctrl_trdy = FALSE;
		cpy[((int *)&out->vga_ctrl_trdy - (int *)out)] = 0;
		out->processor_req = FALSE;
		cpy[((int *)&out->processor_req - (int *)out)] = 0;
		out->processor_state = idle;
		cpy[((int *)&out->processor_state - (int *)out)] = 0;
		out->processor__count = 0;
		cpy[((int *)&out->processor__count - (int *)out)] = 0;
		out->processor_c_bd = IDLE;
		cpy[((int *)&out->processor_c_bd - (int *)out)] = 0;
		out->processor_irdy = FALSE;
		cpy[((int *)&out->processor_irdy - (int *)out)] = 0;
		out->processor_trdy = FALSE;
		cpy[((int *)&out->processor_trdy - (int *)out)] = 0;
		out->b_frame_old = FALSE;
		cpy[((int *)&out->b_frame_old - (int *)out)] = 0;
		out->abort_count = 0;
		cpy[((int *)&out->abort_count - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->arb_policy0 = smv_non_deterministic("arb_policy0",2,FP,RR);
		cpy[((int *)&out->arb_policy0 - (int *)out)] = 0;
		out->arb_policy1 = smv_non_deterministic("arb_policy1",2,FP,RR);
		cpy[((int *)&out->arb_policy1 - (int *)out)] = 0;
		out->arb_policy2 = smv_non_deterministic("arb_policy2",2,FP,RR);
		cpy[((int *)&out->arb_policy2 - (int *)out)] = 0;
		out->arb_policy3 = smv_non_deterministic("arb_policy3",2,FP,RR);
		cpy[((int *)&out->arb_policy3 - (int *)out)] = 0;
		out->isa_bridge_issue_next = smv_non_deterministic("isa_bridge_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->isa_bridge_issue_next - (int *)out)] = 0;
		out->scsi_ctrl_issue_next = smv_non_deterministic("scsi_ctrl_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->scsi_ctrl_issue_next - (int *)out)] = 0;
		out->vga_ctrl_issue_next = smv_non_deterministic("vga_ctrl_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->vga_ctrl_issue_next - (int *)out)] = 0;
		out->processor_issue_next = smv_non_deterministic("processor_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->processor_issue_next - (int *)out)] = 0;
		out->abort_random = smv_non_deterministic("abort_random",2,FALSE,TRUE);
		cpy[((int *)&out->abort_random - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int arb_bank0_grant;
		int arb_bank1_grant;
		int arb_bank2_grant;
		int arb_bank3_grant;
		int arb_reqbank0;
		int arb_reqbank1;
		int arb_reqbank3;
		int arb_change_now;
		int isa_bridge_ad;
		int isa_bridge_bus_idle;
		int isa_bridge_start_transaction;
		int isa_bridge_end_transaction;
		int isa_bridge_frame;
		int scsi_ctrl_ad;
		int scsi_ctrl_bus_idle;
		int scsi_ctrl_start_transaction;
		int scsi_ctrl_end_transaction;
		int scsi_ctrl_frame;
		int vga_ctrl_ad;
		int vga_ctrl_bus_idle;
		int vga_ctrl_start_transaction;
		int vga_ctrl_end_transaction;
		int vga_ctrl_frame;
		int slot0_c_bd;
		int slot0_ad;
		int slot0_frame;
		int slot0_irdy;
		int slot0_trdy;
		int slot0_req;
		int processor_ad;
		int processor_bus_idle;
		int processor_start_transaction;
		int processor_end_transaction;
		int processor_frame;
		int slot1_c_bd;
		int slot1_ad;
		int slot1_frame;
		int slot1_irdy;
		int slot1_trdy;
		int slot1_req;
		int b_frame;
		int b_irdy;
		int b_trdy;
		int b_c_bd;
		int bus_idle;
		int b_frame_switch;
		int abort;
		arb_bank0_grant =  ( in->arb_policy0 == FP ?  ( in->isa_bridge_req ? 0 :  ( in->scsi_ctrl_req ? 1 : idle )  )  :  ( in->arb_bank0_last == 0 ?  ( in->scsi_ctrl_req ? 1 :  ( in->isa_bridge_req ? 0 : idle )  )  :  ( in->isa_bridge_req ? 0 :  ( in->scsi_ctrl_req ? 1 : idle )  )  )  ) ;
		arb_bank1_grant =  ( in->arb_policy1 == FP ?  ( in->vga_ctrl_req ? 0 :  ( slot0_req ? 1 : idle )  )  :  ( in->arb_bank1_last == 0 ?  ( slot0_req ? 1 :  ( in->vga_ctrl_req ? 0 : idle )  )  :  ( in->vga_ctrl_req ? 0 :  ( slot0_req ? 1 : idle )  )  )  ) ;
		arb_bank2_grant =  ( in->arb_policy2 == FP ?  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 : idle )  )  )  :  ( in->arb_bank2_last == 0 ?  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 :  ( arb_reqbank0 ? 0 : idle )  )  )  :  ( in->arb_bank2_last == 1 ?  ( arb_reqbank3 ? 2 :  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 : idle )  )  )  :  ( arb_reqbank0 ? 0 :  ( arb_reqbank1 ? 1 :  ( arb_reqbank3 ? 2 : idle )  )  )  )  )  ) ;
		arb_bank3_grant =  ( in->arb_policy3 == FP ?  ( in->processor_req ? 0 :  ( slot1_req ? 1 : idle )  )  :  ( in->arb_bank3_last == 0 ?  ( slot1_req ? 1 :  ( in->processor_req ? 0 : idle )  )  :  ( in->processor_req ? 0 :  ( slot1_req ? 1 : idle )  )  )  ) ;
		arb_reqbank0 = !(arb_bank0_grant == idle);
		arb_reqbank1 = !(arb_bank1_grant == idle);
		arb_reqbank3 = !(arb_bank3_grant == idle);
		arb_change_now = !(!b_frame_switch && in->arb_grant!=idle);
		isa_bridge_ad = 0;
		isa_bridge_bus_idle = !b_frame && !b_irdy;
		isa_bridge_start_transaction = (in->arb_grant == 0) && isa_bridge_bus_idle;
		isa_bridge_end_transaction = (in->isa_bridge_state == data) && (in->isa_bridge__count == 0);
		isa_bridge_frame = (in->isa_bridge_state == address) || ((in->isa_bridge_state == data) && (in->isa_bridge__count>0));
		scsi_ctrl_ad = 0;
		scsi_ctrl_bus_idle = !b_frame && !b_irdy;
		scsi_ctrl_start_transaction = (in->arb_grant == 1) && scsi_ctrl_bus_idle;
		scsi_ctrl_end_transaction = (in->scsi_ctrl_state == data) && (in->scsi_ctrl__count == 0);
		scsi_ctrl_frame = (in->scsi_ctrl_state == address) || ((in->scsi_ctrl_state == data) && (in->scsi_ctrl__count>0));
		vga_ctrl_ad = 0;
		vga_ctrl_bus_idle = !b_frame && !b_irdy;
		vga_ctrl_start_transaction = (in->arb_grant == 2) && vga_ctrl_bus_idle;
		vga_ctrl_end_transaction = (in->vga_ctrl_state == data) && (in->vga_ctrl__count == 0);
		vga_ctrl_frame = (in->vga_ctrl_state == address) || ((in->vga_ctrl_state == data) && (in->vga_ctrl__count>0));
		slot0_c_bd = 0;
		slot0_ad = 0;
		slot0_frame = FALSE;
		slot0_irdy = FALSE;
		slot0_trdy = FALSE;
		slot0_req = FALSE;
		processor_ad = 0;
		processor_bus_idle = !b_frame && !b_irdy;
		processor_start_transaction = (in->arb_grant == 4) && processor_bus_idle;
		processor_end_transaction = (in->processor_state == data) && (in->processor__count == 0);
		processor_frame = (in->processor_state == address) || ((in->processor_state == data) && (in->processor__count>0));
		slot1_c_bd = 0;
		slot1_ad = 0;
		slot1_frame = FALSE;
		slot1_irdy = FALSE;
		slot1_trdy = FALSE;
		slot1_req = FALSE;
		b_frame = isa_bridge_frame || scsi_ctrl_frame || vga_ctrl_frame || slot0_frame || processor_frame || slot1_frame;
		b_irdy = in->isa_bridge_irdy || in->scsi_ctrl_irdy || in->vga_ctrl_irdy || slot0_irdy || in->processor_irdy || slot1_irdy;
		b_trdy = in->isa_bridge_trdy || in->scsi_ctrl_trdy || in->vga_ctrl_trdy || slot0_trdy || in->processor_trdy || slot1_trdy;
		b_c_bd =  ( isa_bridge_frame ? in->isa_bridge_c_bd :  ( scsi_ctrl_frame ? in->scsi_ctrl_c_bd :  ( vga_ctrl_frame ? in->vga_ctrl_c_bd :  ( slot0_frame ? slot0_c_bd :  ( processor_frame ? in->processor_c_bd : slot1_c_bd )  )  )  )  ) ;
		bus_idle = !b_frame && !b_irdy;
		b_frame_switch = b_frame && !in->b_frame_old;
		abort = in->abort_random && b_frame;
		out->arb_policy0 = in->arb_policy0;
		cpy[((int *)&out->arb_policy0 - (int *)out)] = 0;
		out->arb_policy1 = in->arb_policy1;
		cpy[((int *)&out->arb_policy1 - (int *)out)] = 0;
		out->arb_policy2 = in->arb_policy2;
		cpy[((int *)&out->arb_policy2 - (int *)out)] = 0;
		out->arb_policy3 = in->arb_policy3;
		cpy[((int *)&out->arb_policy3 - (int *)out)] = 0;
		out->arb_bank0_last =  ( !(arb_bank2_grant == 0) || !arb_change_now ? in->arb_bank0_last :  ( arb_bank0_grant == 0 ? 0 :  ( arb_bank0_grant == 1 ? 1 : in->arb_bank0_last )  )  ) ;
		cpy[((int *)&out->arb_bank0_last - (int *)out)] = 0;
		out->arb_bank1_last =  ( !(arb_bank2_grant == 1) || !arb_change_now ? in->arb_bank1_last :  ( arb_bank1_grant == 0 ? 0 :  ( arb_bank1_grant == 1 ? 1 : in->arb_bank1_last )  )  ) ;
		cpy[((int *)&out->arb_bank1_last - (int *)out)] = 0;
		out->arb_bank2_last =  ( !arb_change_now ? in->arb_bank2_last :  ( arb_bank2_grant == 0 ? 0 :  ( arb_bank2_grant == 1 ? 1 :  ( arb_bank2_grant == 2 ? 2 : in->arb_bank2_last )  )  )  ) ;
		cpy[((int *)&out->arb_bank2_last - (int *)out)] = 0;
		out->arb_bank3_last =  ( !(arb_bank2_grant == 2) || !arb_change_now ? in->arb_bank3_last :  ( arb_bank3_grant == 0 ? 0 :  ( arb_bank3_grant == 1 ? 1 : in->arb_bank3_last )  )  ) ;
		cpy[((int *)&out->arb_bank3_last - (int *)out)] = 0;
		out->arb_grant =  ( !b_frame_switch && in->arb_grant!=idle ? in->arb_grant :  ( arb_bank2_grant == idle ? idle :  ( arb_bank2_grant == 0 ?  ( arb_bank0_grant == 0 ? 0 : 1 )  :  ( arb_bank2_grant == 1 ?  ( arb_bank1_grant == 0 ? 2 : 3 )  :  ( arb_bank3_grant == 0 ? 4 : 5 )  )  )  )  ) ;
		cpy[((int *)&out->arb_grant - (int *)out)] = 0;
		out->isa_bridge_req =  ( isa_bridge_frame && abort ? TRUE :  ( !in->isa_bridge_req ?  ( in->isa_bridge_issue_next ? TRUE : FALSE )  :  ( (in->arb_grant == 0) ? FALSE : TRUE )  )  ) ;
		cpy[((int *)&out->isa_bridge_req - (int *)out)] = 0;
		out->isa_bridge_state =  ( abort ? idle :  ( in->isa_bridge_state == idle ?  ( !isa_bridge_start_transaction ? idle : address )  :  ( in->isa_bridge_state == address ? data :  ( in->isa_bridge__count == 0 ? idle : data )  )  )  ) ;
		cpy[((int *)&out->isa_bridge_state - (int *)out)] = 0;
		out->isa_bridge__count =  ( abort ? 0 :  ( isa_bridge_start_transaction ? smv_non_deterministic("isa_bridge__count",15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15) :  ( isa_bridge_end_transaction ? 0 :  ( !(in->isa_bridge_state == data) ? in->isa_bridge__count :  ( !b_trdy ? in->isa_bridge__count :  ( in->isa_bridge__count>0 ? in->isa_bridge__count - 1 : in->isa_bridge__count )  )  )  )  )  ) ;
		cpy[((int *)&out->isa_bridge__count - (int *)out)] = 0;
		out->isa_bridge_c_bd =  ( abort ? IDLE :  ( isa_bridge_start_transaction ? smv_non_deterministic("isa_bridge_c_bd",2,MEM_READ,MEM_WRITE) :  ( isa_bridge_end_transaction ? IDLE : in->isa_bridge_c_bd )  )  ) ;
		cpy[((int *)&out->isa_bridge_c_bd - (int *)out)] = 0;
		out->isa_bridge_irdy =  ( abort ? FALSE :  ( in->isa_bridge_state == address ? TRUE :  ( isa_bridge_end_transaction ? FALSE : in->isa_bridge_irdy )  )  ) ;
		cpy[((int *)&out->isa_bridge_irdy - (int *)out)] = 0;
		out->isa_bridge_trdy =  ( abort ? FALSE :  ( in->isa_bridge_state!=idle ? FALSE :  ( !in->isa_bridge_trdy ?  ( b_c_bd == MEM_READ && b_irdy ? TRUE :  ( b_c_bd == MEM_WRITE && b_frame ? TRUE : FALSE )  )  :  ( b_frame ? TRUE : FALSE )  )  )  ) ;
		cpy[((int *)&out->isa_bridge_trdy - (int *)out)] = 0;
		out->scsi_ctrl_req =  ( scsi_ctrl_frame && abort ? TRUE :  ( !in->scsi_ctrl_req ?  ( in->scsi_ctrl_issue_next ? TRUE : FALSE )  :  ( (in->arb_grant == 1) ? FALSE : TRUE )  )  ) ;
		cpy[((int *)&out->scsi_ctrl_req - (int *)out)] = 0;
		out->scsi_ctrl_state =  ( abort ? idle :  ( in->scsi_ctrl_state == idle ?  ( !scsi_ctrl_start_transaction ? idle : address )  :  ( in->scsi_ctrl_state == address ? data :  ( in->scsi_ctrl__count == 0 ? idle : data )  )  )  ) ;
		cpy[((int *)&out->scsi_ctrl_state - (int *)out)] = 0;
		out->scsi_ctrl__count =  ( abort ? 0 :  ( scsi_ctrl_start_transaction ? smv_non_deterministic("scsi_ctrl__count",15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15) :  ( scsi_ctrl_end_transaction ? 0 :  ( !(in->scsi_ctrl_state == data) ? in->scsi_ctrl__count :  ( !b_trdy ? in->scsi_ctrl__count :  ( in->scsi_ctrl__count>0 ? in->scsi_ctrl__count - 1 : in->scsi_ctrl__count )  )  )  )  )  ) ;
		cpy[((int *)&out->scsi_ctrl__count - (int *)out)] = 0;
		out->scsi_ctrl_c_bd =  ( abort ? IDLE :  ( scsi_ctrl_start_transaction ? smv_non_deterministic("scsi_ctrl_c_bd",2,MEM_READ,MEM_WRITE) :  ( scsi_ctrl_end_transaction ? IDLE : in->scsi_ctrl_c_bd )  )  ) ;
		cpy[((int *)&out->scsi_ctrl_c_bd - (int *)out)] = 0;
		out->scsi_ctrl_irdy =  ( abort ? FALSE :  ( in->scsi_ctrl_state == address ? TRUE :  ( scsi_ctrl_end_transaction ? FALSE : in->scsi_ctrl_irdy )  )  ) ;
		cpy[((int *)&out->scsi_ctrl_irdy - (int *)out)] = 0;
		out->scsi_ctrl_trdy =  ( abort ? FALSE :  ( in->scsi_ctrl_state!=idle ? FALSE :  ( !in->scsi_ctrl_trdy ?  ( b_c_bd == MEM_READ && b_irdy ? TRUE :  ( b_c_bd == MEM_WRITE && b_frame ? TRUE : FALSE )  )  :  ( b_frame ? TRUE : FALSE )  )  )  ) ;
		cpy[((int *)&out->scsi_ctrl_trdy - (int *)out)] = 0;
		out->vga_ctrl_req =  ( vga_ctrl_frame && abort ? TRUE :  ( !in->vga_ctrl_req ?  ( in->vga_ctrl_issue_next ? TRUE : FALSE )  :  ( (in->arb_grant == 2) ? FALSE : TRUE )  )  ) ;
		cpy[((int *)&out->vga_ctrl_req - (int *)out)] = 0;
		out->vga_ctrl_state =  ( abort ? idle :  ( in->vga_ctrl_state == idle ?  ( !vga_ctrl_start_transaction ? idle : address )  :  ( in->vga_ctrl_state == address ? data :  ( in->vga_ctrl__count == 0 ? idle : data )  )  )  ) ;
		cpy[((int *)&out->vga_ctrl_state - (int *)out)] = 0;
		out->vga_ctrl__count =  ( abort ? 0 :  ( vga_ctrl_start_transaction ? smv_non_deterministic("vga_ctrl__count",15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15) :  ( vga_ctrl_end_transaction ? 0 :  ( !(in->vga_ctrl_state == data) ? in->vga_ctrl__count :  ( !b_trdy ? in->vga_ctrl__count :  ( in->vga_ctrl__count>0 ? in->vga_ctrl__count - 1 : in->vga_ctrl__count )  )  )  )  )  ) ;
		cpy[((int *)&out->vga_ctrl__count - (int *)out)] = 0;
		out->vga_ctrl_c_bd =  ( abort ? IDLE :  ( vga_ctrl_start_transaction ? smv_non_deterministic("vga_ctrl_c_bd",2,MEM_READ,MEM_WRITE) :  ( vga_ctrl_end_transaction ? IDLE : in->vga_ctrl_c_bd )  )  ) ;
		cpy[((int *)&out->vga_ctrl_c_bd - (int *)out)] = 0;
		out->vga_ctrl_irdy =  ( abort ? FALSE :  ( in->vga_ctrl_state == address ? TRUE :  ( vga_ctrl_end_transaction ? FALSE : in->vga_ctrl_irdy )  )  ) ;
		cpy[((int *)&out->vga_ctrl_irdy - (int *)out)] = 0;
		out->vga_ctrl_trdy =  ( abort ? FALSE :  ( in->vga_ctrl_state!=idle ? FALSE :  ( !in->vga_ctrl_trdy ?  ( b_c_bd == MEM_READ && b_irdy ? TRUE :  ( b_c_bd == MEM_WRITE && b_frame ? TRUE : FALSE )  )  :  ( b_frame ? TRUE : FALSE )  )  )  ) ;
		cpy[((int *)&out->vga_ctrl_trdy - (int *)out)] = 0;
		out->processor_req =  ( processor_frame && abort ? TRUE :  ( !in->processor_req ?  ( in->processor_issue_next ? TRUE : FALSE )  :  ( (in->arb_grant == 4) ? FALSE : TRUE )  )  ) ;
		cpy[((int *)&out->processor_req - (int *)out)] = 0;
		out->processor_state =  ( abort ? idle :  ( in->processor_state == idle ?  ( !processor_start_transaction ? idle : address )  :  ( in->processor_state == address ? data :  ( in->processor__count == 0 ? idle : data )  )  )  ) ;
		cpy[((int *)&out->processor_state - (int *)out)] = 0;
		out->processor__count =  ( abort ? 0 :  ( processor_start_transaction ? smv_non_deterministic("processor__count",15,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15) :  ( processor_end_transaction ? 0 :  ( !(in->processor_state == data) ? in->processor__count :  ( !b_trdy ? in->processor__count :  ( in->processor__count>0 ? in->processor__count - 1 : in->processor__count )  )  )  )  )  ) ;
		cpy[((int *)&out->processor__count - (int *)out)] = 0;
		out->processor_c_bd =  ( abort ? IDLE :  ( processor_start_transaction ? smv_non_deterministic("processor_c_bd",2,MEM_READ,MEM_WRITE) :  ( processor_end_transaction ? IDLE : in->processor_c_bd )  )  ) ;
		cpy[((int *)&out->processor_c_bd - (int *)out)] = 0;
		out->processor_irdy =  ( abort ? FALSE :  ( in->processor_state == address ? TRUE :  ( processor_end_transaction ? FALSE : in->processor_irdy )  )  ) ;
		cpy[((int *)&out->processor_irdy - (int *)out)] = 0;
		out->processor_trdy =  ( abort ? FALSE :  ( in->processor_state!=idle ? FALSE :  ( !in->processor_trdy ?  ( b_c_bd == MEM_READ && b_irdy ? TRUE :  ( b_c_bd == MEM_WRITE && b_frame ? TRUE : FALSE )  )  :  ( b_frame ? TRUE : FALSE )  )  )  ) ;
		cpy[((int *)&out->processor_trdy - (int *)out)] = 0;
		out->b_frame_old = b_frame;
		cpy[((int *)&out->b_frame_old - (int *)out)] = 0;
		out->abort_count =  ( abort ?  ( in->abort_count == 3 ? 3 : in->abort_count + 1 )  : in->abort_count ) ;
		cpy[((int *)&out->abort_count - (int *)out)] = 0;
		out->isa_bridge_issue_next = smv_non_deterministic("isa_bridge_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->isa_bridge_issue_next - (int *)out)] = 0;
		out->scsi_ctrl_issue_next = smv_non_deterministic("scsi_ctrl_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->scsi_ctrl_issue_next - (int *)out)] = 0;
		out->vga_ctrl_issue_next = smv_non_deterministic("vga_ctrl_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->vga_ctrl_issue_next - (int *)out)] = 0;
		out->processor_issue_next = smv_non_deterministic("processor_issue_next",2,FALSE,TRUE);
		cpy[((int *)&out->processor_issue_next - (int *)out)] = 0;
		out->abort_random = smv_non_deterministic("abort_random",2,FALSE,TRUE);
		cpy[((int *)&out->abort_random - (int *)out)] = 0;
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
	((int[]){38,0,1,2,3,4,5,6,7,8,9,15,10,11,12,13,14,16,22,17,18,19,20,21,23,29,24,25,26,27,28,30,36,31,32,33,34,35,38})
};

int *write_m[2] = {
	((int[]){41,4,5,6,7,8,9,10,11,12,13,14,16,17,18,19,20,21,23,24,25,26,27,28,30,31,32,33,34,35,37,38,40,0,1,2,3,15,22,29,36,39}),
	((int[]){40,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,17,18,19,20,21,23,24,25,26,27,28,30,31,32,33,34,35,37,38,15,22,29,36,39})
};

int *label_m[2] = {
	((int[]){1,40}),
	((int[]){1,40})
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
char pins_plugin_name[] = "pci";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"arb_policy0");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"arb_policy1");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"arb_policy2");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"arb_policy3");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"arb_bank0_last");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"arb_bank1_last");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"arb_bank2_last");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"arb_bank3_last");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"arb_grant");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"isa_bridge_req");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"isa_bridge_state");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"isa_bridge__count");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"isa_bridge_c_bd");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"isa_bridge_irdy");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"isa_bridge_trdy");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"isa_bridge_issue_next");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"scsi_ctrl_req");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"scsi_ctrl_state");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"scsi_ctrl__count");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"scsi_ctrl_c_bd");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"scsi_ctrl_irdy");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"scsi_ctrl_trdy");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"scsi_ctrl_issue_next");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"vga_ctrl_req");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"vga_ctrl_state");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"vga_ctrl__count");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"vga_ctrl_c_bd");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"vga_ctrl_irdy");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"vga_ctrl_trdy");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"vga_ctrl_issue_next");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"processor_req");
	lts_type_set_state_typeno(ltstype, 30,int_type);
	lts_type_set_state_name(ltstype, 31,"processor_state");
	lts_type_set_state_typeno(ltstype, 31,int_type);
	lts_type_set_state_name(ltstype, 32,"processor__count");
	lts_type_set_state_typeno(ltstype, 32,int_type);
	lts_type_set_state_name(ltstype, 33,"processor_c_bd");
	lts_type_set_state_typeno(ltstype, 33,int_type);
	lts_type_set_state_name(ltstype, 34,"processor_irdy");
	lts_type_set_state_typeno(ltstype, 34,int_type);
	lts_type_set_state_name(ltstype, 35,"processor_trdy");
	lts_type_set_state_typeno(ltstype, 35,int_type);
	lts_type_set_state_name(ltstype, 36,"processor_issue_next");
	lts_type_set_state_typeno(ltstype, 36,int_type);
	lts_type_set_state_name(ltstype, 37,"b_frame_old");
	lts_type_set_state_typeno(ltstype, 37,int_type);
	lts_type_set_state_name(ltstype, 38,"abort_count");
	lts_type_set_state_typeno(ltstype, 38,int_type);
	lts_type_set_state_name(ltstype, 39,"abort_random");
	lts_type_set_state_typeno(ltstype, 39,int_type);
	lts_type_set_state_name(ltstype, 40,"virtual_init");
	lts_type_set_state_typeno(ltstype, 40,int_type);

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
	int state[41];
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
