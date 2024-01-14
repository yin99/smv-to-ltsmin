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
	return 68;
}

typedef struct state_t {
	boolean repeat;
	int step;
	boolean again;
	int opstep;
	boolean log1_CR0307;
	boolean log1_CR0308;
	boolean log1_CR0299;
	boolean log1_CR0075;
	boolean log1_CR0048;
	boolean log1_CR0261;
	boolean log1_f;
	boolean log1_CR0270;
	boolean log1_CR0069;
	boolean log1_TS0272l;
	boolean log1_CR0085;
	boolean log1_TS0274l;
	boolean log1_CR0089;
	boolean log1_CR0082;
	boolean log1_m;
	boolean log1_TT0300l;
	boolean log1_CR0309;
	boolean log1_o;
	boolean log1_CR0101;
	boolean log1_p;
	boolean log1_change;
	boolean log2_CR0065;
	boolean log2_q;
	boolean log2_CR0106;
	boolean log2_TT0276l;
	boolean log2_TS0297l;
	boolean log2_TT0262l;
	boolean log2_TS0271l;
	boolean log2_CR0077;
	boolean log2_CR0081;
	boolean log2_CR0080;
	boolean log2_ab;
	boolean log2_CR0278;
	boolean log2_ac;
	boolean log2_change;
	boolean log3_CR0287;
	boolean log3_CR0285;
	boolean log3_change;
	boolean ti0276_t;
	int ti0297_t;
	boolean ti0297_done;
	boolean ti0262_t;
	boolean ti0271_t;
	boolean ti0272_t;
	boolean ti0274_t;
	boolean ti0300_t;
	boolean bc56_working;
	boolean wghgat_z;
	int wghhop_h;
	boolean mixgat_z;
	boolean eirich_material;
	boolean eirich_watsol;
	boolean eirich_ms34;
	boolean eirich_mf34;
	boolean eirich_m7;
	boolean eirich_m9;
	boolean flare_air_sol;
	boolean flare_pilot_valve;
	boolean flare_main_valve;
	boolean flare_flame;
	boolean bc57_working;
	int fail0148hl;
	int fail0149hl;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.repeat                                 = FALSE,
	.step                                   = 0,
	.again                                  = FALSE,
	.opstep                                 = 0,
	.log1_CR0307                            = FALSE,
	.log1_CR0308                            = FALSE,
	.log1_CR0299                            = FALSE,
	.log1_CR0075                            = FALSE,
	.log1_CR0048                            = FALSE,
	.log1_CR0261                            = FALSE,
	.log1_f                                 = FALSE,
	.log1_CR0270                            = FALSE,
	.log1_CR0069                            = FALSE,
	.log1_TS0272l                           = FALSE,
	.log1_CR0085                            = FALSE,
	.log1_TS0274l                           = FALSE,
	.log1_CR0089                            = FALSE,
	.log1_CR0082                            = FALSE,
	.log1_m                                 = FALSE,
	.log1_TT0300l                           = FALSE,
	.log1_CR0309                            = FALSE,
	.log1_o                                 = FALSE,
	.log1_CR0101                            = FALSE,
	.log1_p                                 = FALSE,
	.log1_change                            = FALSE,
	.log2_CR0065                            = FALSE,
	.log2_q                                 = FALSE,
	.log2_CR0106                            = FALSE,
	.log2_TT0276l                           = FALSE,
	.log2_TS0297l                           = FALSE,
	.log2_TT0262l                           = FALSE,
	.log2_TS0271l                           = FALSE,
	.log2_CR0077                            = FALSE,
	.log2_CR0081                            = FALSE,
	.log2_CR0080                            = FALSE,
	.log2_ab                                = FALSE,
	.log2_CR0278                            = FALSE,
	.log2_ac                                = FALSE,
	.log2_change                            = FALSE,
	.log3_CR0287                            = FALSE,
	.log3_CR0285                            = FALSE,
	.log3_change                            = FALSE,
	.ti0276_t                               = FALSE,
	.ti0297_t                               = 0,
	.ti0297_done                            = FALSE,
	.ti0262_t                               = FALSE,
	.ti0271_t                               = FALSE,
	.ti0272_t                               = FALSE,
	.ti0274_t                               = FALSE,
	.ti0300_t                               = FALSE,
	.bc56_working                           = FALSE,
	.wghgat_z                               = FALSE,
	.wghhop_h                               = 0,
	.mixgat_z                               = FALSE,
	.eirich_material                        = FALSE,
	.eirich_watsol                          = FALSE,
	.eirich_ms34                            = FALSE,
	.eirich_mf34                            = FALSE,
	.eirich_m7                              = FALSE,
	.eirich_m9                              = FALSE,
	.flare_air_sol                          = FALSE,
	.flare_pilot_valve                      = FALSE,
	.flare_main_valve                       = FALSE,
	.flare_flame                            = FALSE,
	.bc57_working                           = FALSE,
	.fail0148hl                             = 0,
	.fail0149hl                             = 0,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"repeat",1,0x0},
	{"step",1,0x0},
	{"again",1,0x0},
	{"opstep",1,0x0},
	{"log1_CR0307",1,0x0},
	{"log1_CR0308",1,0x0},
	{"log1_CR0299",1,0x0},
	{"log1_CR0075",1,0x0},
	{"log1_CR0048",1,0x0},
	{"log1_CR0261",1,0x0},
	{"log1_f",1,0x0},
	{"log1_CR0270",1,0x0},
	{"log1_CR0069",1,0x0},
	{"log1_TS0272l",1,0x0},
	{"log1_CR0085",1,0x0},
	{"log1_TS0274l",1,0x0},
	{"log1_CR0089",1,0x0},
	{"log1_CR0082",1,0x0},
	{"log1_m",1,0x0},
	{"log1_TT0300l",1,0x0},
	{"log1_CR0309",1,0x0},
	{"log1_o",1,0x0},
	{"log1_CR0101",1,0x0},
	{"log1_p",1,0x0},
	{"log1_change",1,0x0},
	{"log2_CR0065",1,0x0},
	{"log2_q",1,0x0},
	{"log2_CR0106",1,0x0},
	{"log2_TT0276l",1,0x0},
	{"log2_TS0297l",1,0x0},
	{"log2_TT0262l",1,0x0},
	{"log2_TS0271l",1,0x0},
	{"log2_CR0077",1,0x0},
	{"log2_CR0081",1,0x0},
	{"log2_CR0080",1,0x0},
	{"log2_ab",1,0x0},
	{"log2_CR0278",1,0x0},
	{"log2_ac",1,0x0},
	{"log2_change",1,0x0},
	{"log3_CR0287",1,0x0},
	{"log3_CR0285",1,0x0},
	{"log3_change",1,0x0},
	{"ti0276_t",1,0x0},
	{"ti0297_t",1,0x0},
	{"ti0297_done",1,0x0},
	{"ti0262_t",1,0x0},
	{"ti0271_t",1,0x0},
	{"ti0272_t",1,0x0},
	{"ti0274_t",1,0x0},
	{"ti0300_t",1,0x0},
	{"bc56_working",1,0x0},
	{"wghgat_z",1,0x0},
	{"wghhop_h",1,0x0},
	{"mixgat_z",1,0x0},
	{"eirich_material",1,0x0},
	{"eirich_watsol",1,0x0},
	{"eirich_ms34",1,0x0},
	{"eirich_mf34",1,0x0},
	{"eirich_m7",1,0x0},
	{"eirich_m9",1,0x0},
	{"flare_air_sol",1,0x0},
	{"flare_pilot_valve",1,0x0},
	{"flare_main_valve",1,0x0},
	{"flare_flame",1,0x0},
	{"bc57_working",1,0x0},
	{"fail0148hl",1,0x0},
	{"fail0149hl",1,0x0},
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
	int cpy[68] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int bc56_q;
		int wghhop_full;
		int flare_q;
		int flare_gas;
		int bc57_q;
		int IN0146;
		int IN0111;
		int IN0095;
		int IN0094;
		int IN0056;
		int IN0135;
		int IN0136;
		int IN0108;
		int IN0114;
		int IN0120;
		int IN0145;
		int IN0097;
		int IN0098;
		int IN0112;
		int IN0113;
		int IN0148;
		int IN0149;
		int IN0054;
		int IN0107;
		int IN0103;
		int IN0138;
		int IN0102;
		int IN0122;
		int IN0116;
		int IN0053;
		int IN0137;
		int TT0276;
		int TS0297;
		int TT0262;
		int TS0271;
		int TS0272;
		int TS0274;
		int TT0300;
		bc56_q = in->bc56_working && IN0053 && 1;
		wghhop_full = (in->wghhop_h>3);
		flare_q = in->flare_air_sol && 1;
		flare_gas = in->flare_pilot_valve || in->flare_main_valve;
		bc57_q = in->bc57_working && in->mixgat_z && 1;
		IN0146 =  ( (in->opstep == 0) ? 1 : 0 ) ;
		IN0111 =  ( (in->opstep == 1) ? 1 : 0 ) ;
		IN0095 =  ( (in->opstep == 3) ? 1 : 0 ) ;
		IN0094 =  ( (in->opstep == 5) ? 0 : 1 ) ;
		IN0056 =  ( (in->opstep == 7) ? 0 : 1 ) ;
		IN0135 =  ( (in->opstep == 9) ? 1 : 0 ) ;
		IN0136 =  ( (in->opstep == 11) ? 0 : 1 ) ;
		IN0108 =  ( (in->opstep == 13) ? 0 : 1 ) ;
		IN0114 =  ( (in->opstep == 14) ? 0 : 1 ) ;
		IN0120 =  ( (in->opstep == 15) ? 0 : 1 ) ;
		IN0145 =  ( (in->opstep == 16) ? 0 : 1 ) ;
		IN0097 = in->bc56_working;
		IN0098 = in->bc56_working;
		IN0112 = in->eirich_mf34;
		IN0113 = in->eirich_ms34;
		IN0148 = (in->bc57_working || (in->fail0148hl / 2)) && !(in->fail0148hl % 2);
		IN0149 = (in->bc57_working || (in->fail0149hl / 2)) && !(in->fail0149hl % 2);
		IN0054 = wghhop_full;
		IN0107 = in->flare_flame;
		IN0103 = in->wghgat_z;
		IN0138 = !in->mixgat_z;
		IN0102 = !in->wghgat_z;
		IN0122 = in->eirich_m9;
		IN0116 = in->eirich_m7;
		IN0053 = (in->bc56_working && !wghhop_full);
		IN0137 = in->mixgat_z;
		TT0276 = in->ti0276_t;
		TS0297 = in->ti0297_done;
		TT0262 = in->ti0262_t;
		TS0271 = in->ti0271_t;
		TS0272 = in->ti0272_t;
		TS0274 = in->ti0274_t;
		TT0300 = in->ti0300_t;
		out->step = 1;
		cpy[((int *)&out->step - (int *)out)] = 0;
		out->again = 0;
		cpy[((int *)&out->again - (int *)out)] = 0;
		out->opstep = 0;
		cpy[((int *)&out->opstep - (int *)out)] = 0;
		out->log1_CR0307 = 0;
		cpy[((int *)&out->log1_CR0307 - (int *)out)] = 0;
		out->log1_CR0308 = 0;
		cpy[((int *)&out->log1_CR0308 - (int *)out)] = 0;
		out->log1_CR0299 = 0;
		cpy[((int *)&out->log1_CR0299 - (int *)out)] = 0;
		out->log1_CR0075 = 0;
		cpy[((int *)&out->log1_CR0075 - (int *)out)] = 0;
		out->log1_CR0048 = 0;
		cpy[((int *)&out->log1_CR0048 - (int *)out)] = 0;
		out->log1_CR0261 = 0;
		cpy[((int *)&out->log1_CR0261 - (int *)out)] = 0;
		out->log1_CR0270 = 0;
		cpy[((int *)&out->log1_CR0270 - (int *)out)] = 0;
		out->log1_CR0069 = 0;
		cpy[((int *)&out->log1_CR0069 - (int *)out)] = 0;
		out->log1_TS0272l = 0;
		cpy[((int *)&out->log1_TS0272l - (int *)out)] = 0;
		out->log1_CR0085 = 0;
		cpy[((int *)&out->log1_CR0085 - (int *)out)] = 0;
		out->log1_TS0274l = 0;
		cpy[((int *)&out->log1_TS0274l - (int *)out)] = 0;
		out->log1_CR0089 = 0;
		cpy[((int *)&out->log1_CR0089 - (int *)out)] = 0;
		out->log1_CR0082 = 0;
		cpy[((int *)&out->log1_CR0082 - (int *)out)] = 0;
		out->log1_TT0300l = 0;
		cpy[((int *)&out->log1_TT0300l - (int *)out)] = 0;
		out->log1_CR0309 = 0;
		cpy[((int *)&out->log1_CR0309 - (int *)out)] = 0;
		out->log1_CR0101 = 0;
		cpy[((int *)&out->log1_CR0101 - (int *)out)] = 0;
		out->log1_change = 0;
		cpy[((int *)&out->log1_change - (int *)out)] = 0;
		out->log2_CR0065 = 0;
		cpy[((int *)&out->log2_CR0065 - (int *)out)] = 0;
		out->log2_CR0106 = 0;
		cpy[((int *)&out->log2_CR0106 - (int *)out)] = 0;
		out->log2_TT0276l = 0;
		cpy[((int *)&out->log2_TT0276l - (int *)out)] = 0;
		out->log2_TS0297l = 0;
		cpy[((int *)&out->log2_TS0297l - (int *)out)] = 0;
		out->log2_TT0262l = 0;
		cpy[((int *)&out->log2_TT0262l - (int *)out)] = 0;
		out->log2_TS0271l = 0;
		cpy[((int *)&out->log2_TS0271l - (int *)out)] = 0;
		out->log2_CR0077 = 0;
		cpy[((int *)&out->log2_CR0077 - (int *)out)] = 0;
		out->log2_CR0081 = 0;
		cpy[((int *)&out->log2_CR0081 - (int *)out)] = 0;
		out->log2_CR0080 = 0;
		cpy[((int *)&out->log2_CR0080 - (int *)out)] = 0;
		out->log2_CR0278 = 0;
		cpy[((int *)&out->log2_CR0278 - (int *)out)] = 0;
		out->log2_change = 0;
		cpy[((int *)&out->log2_change - (int *)out)] = 0;
		out->log3_CR0287 = 0;
		cpy[((int *)&out->log3_CR0287 - (int *)out)] = 0;
		out->log3_CR0285 = 0;
		cpy[((int *)&out->log3_CR0285 - (int *)out)] = 0;
		out->log3_change = 0;
		cpy[((int *)&out->log3_change - (int *)out)] = 0;
		out->ti0276_t = 0;
		cpy[((int *)&out->ti0276_t - (int *)out)] = 0;
		out->ti0297_t = 0;
		cpy[((int *)&out->ti0297_t - (int *)out)] = 0;
		out->ti0297_done = 0;
		cpy[((int *)&out->ti0297_done - (int *)out)] = 0;
		out->ti0262_t = 0;
		cpy[((int *)&out->ti0262_t - (int *)out)] = 0;
		out->ti0271_t = 0;
		cpy[((int *)&out->ti0271_t - (int *)out)] = 0;
		out->ti0272_t = 0;
		cpy[((int *)&out->ti0272_t - (int *)out)] = 0;
		out->ti0274_t = 0;
		cpy[((int *)&out->ti0274_t - (int *)out)] = 0;
		out->ti0300_t = 0;
		cpy[((int *)&out->ti0300_t - (int *)out)] = 0;
		out->bc56_working = 0;
		cpy[((int *)&out->bc56_working - (int *)out)] = 0;
		out->wghgat_z = 0;
		cpy[((int *)&out->wghgat_z - (int *)out)] = 0;
		out->wghhop_h = 0;
		cpy[((int *)&out->wghhop_h - (int *)out)] = 0;
		out->mixgat_z = 0;
		cpy[((int *)&out->mixgat_z - (int *)out)] = 0;
		out->eirich_material = 0;
		cpy[((int *)&out->eirich_material - (int *)out)] = 0;
		out->eirich_watsol = 0;
		cpy[((int *)&out->eirich_watsol - (int *)out)] = 0;
		out->eirich_ms34 = 0;
		cpy[((int *)&out->eirich_ms34 - (int *)out)] = 0;
		out->eirich_mf34 = 0;
		cpy[((int *)&out->eirich_mf34 - (int *)out)] = 0;
		out->eirich_m7 = 0;
		cpy[((int *)&out->eirich_m7 - (int *)out)] = 0;
		out->eirich_m9 = 0;
		cpy[((int *)&out->eirich_m9 - (int *)out)] = 0;
		out->flare_air_sol = 0;
		cpy[((int *)&out->flare_air_sol - (int *)out)] = 0;
		out->flare_pilot_valve = 0;
		cpy[((int *)&out->flare_pilot_valve - (int *)out)] = 0;
		out->flare_main_valve = 0;
		cpy[((int *)&out->flare_main_valve - (int *)out)] = 0;
		out->flare_flame = 0;
		cpy[((int *)&out->flare_flame - (int *)out)] = 0;
		out->bc57_working = 0;
		cpy[((int *)&out->bc57_working - (int *)out)] = 0;
		out->fail0148hl = 0;
		cpy[((int *)&out->fail0148hl - (int *)out)] = 0;
		out->fail0149hl = 0;
		cpy[((int *)&out->fail0149hl - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->repeat = smv_non_deterministic("repeat",2,FALSE,TRUE);
		cpy[((int *)&out->repeat - (int *)out)] = 0;
		out->log1_f = smv_non_deterministic("log1_f",2,FALSE,TRUE);
		cpy[((int *)&out->log1_f - (int *)out)] = 0;
		out->log1_m = smv_non_deterministic("log1_m",2,FALSE,TRUE);
		cpy[((int *)&out->log1_m - (int *)out)] = 0;
		out->log1_o = smv_non_deterministic("log1_o",2,FALSE,TRUE);
		cpy[((int *)&out->log1_o - (int *)out)] = 0;
		out->log1_p = smv_non_deterministic("log1_p",2,FALSE,TRUE);
		cpy[((int *)&out->log1_p - (int *)out)] = 0;
		out->log2_q = smv_non_deterministic("log2_q",2,FALSE,TRUE);
		cpy[((int *)&out->log2_q - (int *)out)] = 0;
		out->log2_ab = smv_non_deterministic("log2_ab",2,FALSE,TRUE);
		cpy[((int *)&out->log2_ab - (int *)out)] = 0;
		out->log2_ac = smv_non_deterministic("log2_ac",2,FALSE,TRUE);
		cpy[((int *)&out->log2_ac - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int bc56_q;
		int wghhop_full;
		int flare_q;
		int flare_gas;
		int bc57_q;
		int IN0146;
		int IN0111;
		int IN0095;
		int IN0094;
		int IN0056;
		int IN0135;
		int IN0136;
		int IN0108;
		int IN0114;
		int IN0120;
		int IN0145;
		int IN0097;
		int IN0098;
		int IN0112;
		int IN0113;
		int IN0148;
		int IN0149;
		int IN0054;
		int IN0107;
		int IN0103;
		int IN0138;
		int IN0102;
		int IN0122;
		int IN0116;
		int IN0053;
		int IN0137;
		int TT0276;
		int TS0297;
		int TT0262;
		int TS0271;
		int TS0272;
		int TS0274;
		int TT0300;
		bc56_q = in->bc56_working && IN0053 && 1;
		wghhop_full = (in->wghhop_h>3);
		flare_q = in->flare_air_sol && 1;
		flare_gas = in->flare_pilot_valve || in->flare_main_valve;
		bc57_q = in->bc57_working && in->mixgat_z && 1;
		IN0146 =  ( (in->opstep == 0) ? 1 : 0 ) ;
		IN0111 =  ( (in->opstep == 1) ? 1 : 0 ) ;
		IN0095 =  ( (in->opstep == 3) ? 1 : 0 ) ;
		IN0094 =  ( (in->opstep == 5) ? 0 : 1 ) ;
		IN0056 =  ( (in->opstep == 7) ? 0 : 1 ) ;
		IN0135 =  ( (in->opstep == 9) ? 1 : 0 ) ;
		IN0136 =  ( (in->opstep == 11) ? 0 : 1 ) ;
		IN0108 =  ( (in->opstep == 13) ? 0 : 1 ) ;
		IN0114 =  ( (in->opstep == 14) ? 0 : 1 ) ;
		IN0120 =  ( (in->opstep == 15) ? 0 : 1 ) ;
		IN0145 =  ( (in->opstep == 16) ? 0 : 1 ) ;
		IN0097 = in->bc56_working;
		IN0098 = in->bc56_working;
		IN0112 = in->eirich_mf34;
		IN0113 = in->eirich_ms34;
		IN0148 = (in->bc57_working || (in->fail0148hl / 2)) && !(in->fail0148hl % 2);
		IN0149 = (in->bc57_working || (in->fail0149hl / 2)) && !(in->fail0149hl % 2);
		IN0054 = wghhop_full;
		IN0107 = in->flare_flame;
		IN0103 = in->wghgat_z;
		IN0138 = !in->mixgat_z;
		IN0102 = !in->wghgat_z;
		IN0122 = in->eirich_m9;
		IN0116 = in->eirich_m7;
		IN0053 = (in->bc56_working && !wghhop_full);
		IN0137 = in->mixgat_z;
		TT0276 = in->ti0276_t;
		TS0297 = in->ti0297_done;
		TT0262 = in->ti0262_t;
		TS0271 = in->ti0271_t;
		TS0272 = in->ti0272_t;
		TS0274 = in->ti0274_t;
		TT0300 = in->ti0300_t;
		out->step =  ( (in->step == 0) ? 1 :  ( (in->step == 1) ? 2 :  ( (in->step == 2) ? 3 :  ( (in->step == 3) ? 4 :  ( (in->step == 4) && in->repeat ? 1 : 0 )  )  )  )  ) ;
		cpy[((int *)&out->step - (int *)out)] = 0;
		out->again =  ( (in->step>0) ? in->again :  ( (in->opstep == 4) ? smv_non_deterministic("again",2,0,1) : in->again )  ) ;
		cpy[((int *)&out->again - (int *)out)] = 0;
		out->opstep =  ( (in->step == 0) ?  ( (in->opstep == 0) ? 1 :  ( (in->opstep == 1) ? 2 :  ( (in->opstep == 2) && in->log3_CR0285 ? 3 :  ( (in->opstep == 3) ? 4 :  ( (in->opstep == 4) && in->log2_CR0080 ? 5 :  ( (in->opstep == 5) ? 6 :  ( (in->opstep == 6) && in->eirich_watsol ? 7 :  ( (in->opstep == 7) ? 8 :  ( (in->opstep == 8) ? 9 :  ( (in->opstep == 9) ? 10 :  ( (in->opstep == 10) && IN0137 ? 11 :  ( (in->opstep == 11) ? 12 :  ( (in->opstep == 12) ?  ( !in->again ? 13 : 2 )  :  ( (in->opstep == 13) ? 14 :  ( (in->opstep == 14) ? 15 :  ( (in->opstep == 15) ? 16 :  ( (in->opstep == 16) ? 17 :  ( (in->opstep == 17) && !in->log1_CR0048 ? 0 : in->opstep )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  : in->opstep ) ;
		cpy[((int *)&out->opstep - (int *)out)] = 0;
		out->log1_CR0307 =  ( (in->step == 1) ? IN0097 && IN0098 : in->log1_CR0307 ) ;
		cpy[((int *)&out->log1_CR0307 - (int *)out)] = 0;
		out->log1_CR0308 =  ( (in->step == 1) ? IN0148 && IN0149 : in->log1_CR0308 ) ;
		cpy[((int *)&out->log1_CR0308 - (int *)out)] = 0;
		out->log1_CR0299 =  ( (in->step == 1) ? (IN0054 || in->log1_CR0299) && !IN0135 : in->log1_CR0299 ) ;
		cpy[((int *)&out->log1_CR0299 - (int *)out)] = 0;
		out->log1_CR0075 =  ( (in->step == 1) ? TT0276 || (in->log1_CR0075 && IN0056) : in->log1_CR0075 ) ;
		cpy[((int *)&out->log1_CR0075 - (int *)out)] = 0;
		out->log1_CR0048 =  ( (in->step == 1) ? (IN0148 || in->log1_CR0048) && !TS0297 : in->log1_CR0048 ) ;
		cpy[((int *)&out->log1_CR0048 - (int *)out)] = 0;
		out->log1_CR0261 =  ( (in->step == 1) ? in->log1_f : in->log1_CR0261 ) ;
		cpy[((int *)&out->log1_CR0261 - (int *)out)] = 0;
		out->log1_CR0270 =  ( (in->step == 1) ? IN0108 && TT0262 : in->log1_CR0270 ) ;
		cpy[((int *)&out->log1_CR0270 - (int *)out)] = 0;
		out->log1_CR0069 =  ( (in->step == 1) ? TS0271 : in->log1_CR0069 ) ;
		cpy[((int *)&out->log1_CR0069 - (int *)out)] = 0;
		out->log1_TS0272l =  ( (in->step == 1) ? IN0112 : in->log1_TS0272l ) ;
		cpy[((int *)&out->log1_TS0272l - (int *)out)] = 0;
		out->log1_CR0085 =  ( (in->step == 1) ? TS0272 || (IN0116 && IN0114) : in->log1_CR0085 ) ;
		cpy[((int *)&out->log1_CR0085 - (int *)out)] = 0;
		out->log1_TS0274l =  ( (in->step == 1) ? IN0116 : in->log1_TS0274l ) ;
		cpy[((int *)&out->log1_TS0274l - (int *)out)] = 0;
		out->log1_CR0089 =  ( (in->step == 1) ? TS0274 || (IN0122 && IN0120) : in->log1_CR0089 ) ;
		cpy[((int *)&out->log1_CR0089 - (int *)out)] = 0;
		out->log1_CR0082 =  ( (in->step == 1) ? in->log1_m : in->log1_CR0082 ) ;
		cpy[((int *)&out->log1_CR0082 - (int *)out)] = 0;
		out->log1_TT0300l =  ( (in->step == 1) ? in->log2_CR0080 && !IN0102 : in->log1_TT0300l ) ;
		cpy[((int *)&out->log1_TT0300l - (int *)out)] = 0;
		out->log1_CR0309 =  ( (in->step == 1) ? in->log1_o : in->log1_CR0309 ) ;
		cpy[((int *)&out->log1_CR0309 - (int *)out)] = 0;
		out->log1_CR0101 =  ( (in->step == 1) ? in->log1_p : in->log1_CR0101 ) ;
		cpy[((int *)&out->log1_CR0101 - (int *)out)] = 0;
		out->log1_change =  ( !(in->log1_CR0307 == out->log1_CR0307) ? 1 :  ( !(in->log1_CR0308 == out->log1_CR0308) ? 1 :  ( !(in->log1_CR0299 == out->log1_CR0299) ? 1 :  ( !(in->log1_CR0075 == out->log1_CR0075) ? 1 :  ( !(in->log1_CR0048 == out->log1_CR0048) ? 1 :  ( !(in->log1_CR0261 == out->log1_CR0261) ? 1 :  ( !(in->log1_CR0270 == out->log1_CR0270) ? 1 :  ( !(in->log1_CR0069 == out->log1_CR0069) ? 1 :  ( !(in->log1_TS0272l == out->log1_TS0272l) ? 1 :  ( !(in->log1_CR0085 == out->log1_CR0085) ? 1 :  ( !(in->log1_TS0274l == out->log1_TS0274l) ? 1 :  ( !(in->log1_CR0089 == out->log1_CR0089) ? 1 :  ( !(in->log1_CR0082 == out->log1_CR0082) ? 1 :  ( !(in->log1_TT0300l == out->log1_TT0300l) ? 1 :  ( !(in->log1_CR0309 == out->log1_CR0309) ? 1 :  ( !(in->log1_CR0101 == out->log1_CR0101) ? 1 :  ( (in->step<4) ? in->log1_change : 0 )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  )  ) ;
		cpy[((int *)&out->log1_change - (int *)out)] = 0;
		out->log2_CR0065 =  ( (in->step == 2) ? in->log2_q : in->log2_CR0065 ) ;
		cpy[((int *)&out->log2_CR0065 - (int *)out)] = 0;
		out->log2_CR0106 =  ( (in->step == 2) ? (IN0146 || in->log1_CR0308) && IN0145 : in->log2_CR0106 ) ;
		cpy[((int *)&out->log2_CR0106 - (int *)out)] = 0;
		out->log2_TT0276l =  ( (in->step == 2) ?  ( !TT0276 ? in->log1_CR0299 && !in->log3_CR0287 && IN0107 : in->log1_CR0299 && IN0056 && IN0107 )  : in->log2_TT0276l ) ;
		cpy[((int *)&out->log2_TT0276l - (int *)out)] = 0;
		out->log2_TS0297l =  ( (in->step == 2) ?  ( !TS0297 ? !IN0148 : in->log1_CR0048 )  : in->log2_TS0297l ) ;
		cpy[((int *)&out->log2_TS0297l - (int *)out)] = 0;
		out->log2_TT0262l =  ( (in->step == 2) ?  ( !TT0262 ? in->log1_CR0261 : (in->log1_CR0261 || in->log3_CR0285) )  : in->log2_TT0262l ) ;
		cpy[((int *)&out->log2_TT0262l - (int *)out)] = 0;
		out->log2_TS0271l =  ( (in->step == 2) ? in->log1_CR0270 : in->log2_TS0271l ) ;
		cpy[((int *)&out->log2_TS0271l - (int *)out)] = 0;
		out->log2_CR0077 =  ( (in->step == 2) ? in->log1_CR0270 && !TS0271 : in->log2_CR0077 ) ;
		cpy[((int *)&out->log2_CR0077 - (int *)out)] = 0;
		out->log2_CR0081 =  ( (in->step == 2) ? in->log1_CR0309 && !IN0103 : in->log2_CR0081 ) ;
		cpy[((int *)&out->log2_CR0081 - (int *)out)] = 0;
		out->log2_CR0080 =  ( (in->step == 2) ? in->log2_ab : in->log2_CR0080 ) ;
		cpy[((int *)&out->log2_CR0080 - (int *)out)] = 0;
		out->log2_CR0278 =  ( (in->step == 2) ? in->log2_ac : in->log2_CR0278 ) ;
		cpy[((int *)&out->log2_CR0278 - (int *)out)] = 0;
		out->log2_change =  ( !(in->log2_CR0065 == out->log2_CR0065) ? 1 :  ( !(in->log2_CR0106 == out->log2_CR0106) ? 1 :  ( !(in->log2_TT0276l == out->log2_TT0276l) ? 1 :  ( !(in->log2_TS0297l == out->log2_TS0297l) ? 1 :  ( !(in->log2_TT0262l == out->log2_TT0262l) ? 1 :  ( !(in->log2_TS0271l == out->log2_TS0271l) ? 1 :  ( !(in->log2_CR0077 == out->log2_CR0077) ? 1 :  ( !(in->log2_CR0081 == out->log2_CR0081) ? 1 :  ( !(in->log2_CR0080 == out->log2_CR0080) ? 1 :  ( !(in->log2_CR0278 == out->log2_CR0278) ? 1 :  ( (in->step<4) ? in->log2_change : 0 )  )  )  )  )  )  )  )  )  )  ) ;
		cpy[((int *)&out->log2_change - (int *)out)] = 0;
		out->log3_CR0287 =  ( (in->step == 3) ? (TT0276 || in->log3_CR0287) && in->log1_CR0299 : in->log3_CR0287 ) ;
		cpy[((int *)&out->log3_CR0287 - (int *)out)] = 0;
		out->log3_CR0285 =  ( (in->step == 3) ? IN0112 && IN0116 && IN0122 : in->log3_CR0285 ) ;
		cpy[((int *)&out->log3_CR0285 - (int *)out)] = 0;
		out->log3_change =  ( !(in->log3_CR0287 == out->log3_CR0287) ? 1 :  ( !(in->log3_CR0285 == out->log3_CR0285) ? 1 :  ( (in->step<4) ? in->log3_change : 0 )  )  ) ;
		cpy[((int *)&out->log3_change - (int *)out)] = 0;
		out->ti0276_t =  ( !in->log2_TT0276l ? 0 :  ( (in->step>0) ? in->ti0276_t : in->log2_TT0276l )  ) ;
		cpy[((int *)&out->ti0276_t - (int *)out)] = 0;
		out->ti0297_t =  ( !in->log2_TS0297l ? 0 :  ( (in->step>0) ? in->ti0297_t :  ( (in->ti0297_t == 0) ? 1 :  ( (in->ti0297_t == 1) ? 2 :  ( (in->ti0297_t == 2) ? 2 : in->ti0297_t )  )  )  )  ) ;
		cpy[((int *)&out->ti0297_t - (int *)out)] = 0;
		out->ti0297_done =  ( (in->step>0) ? in->ti0297_done :  ( !in->log2_TS0297l ? 0 :  ( (in->ti0297_t<2) ? 0 :  ( in->ti0297_done ? 1 : smv_non_deterministic("ti0297_done",2,0,1) )  )  )  ) ;
		cpy[((int *)&out->ti0297_done - (int *)out)] = 0;
		out->ti0262_t =  ( !in->log2_TT0262l ? 0 :  ( (in->step>0) ? in->ti0262_t : in->log2_TT0262l )  ) ;
		cpy[((int *)&out->ti0262_t - (int *)out)] = 0;
		out->ti0271_t =  ( !in->log2_TS0271l ? 0 :  ( (in->step>0) ? in->ti0271_t : in->log2_TS0271l )  ) ;
		cpy[((int *)&out->ti0271_t - (int *)out)] = 0;
		out->ti0272_t =  ( !in->log1_TS0272l ? 0 :  ( (in->step>0) ? in->ti0272_t : in->log1_TS0272l )  ) ;
		cpy[((int *)&out->ti0272_t - (int *)out)] = 0;
		out->ti0274_t =  ( !in->log1_TS0274l ? 0 :  ( (in->step>0) ? in->ti0274_t : in->log1_TS0274l )  ) ;
		cpy[((int *)&out->ti0274_t - (int *)out)] = 0;
		out->ti0300_t =  ( !in->log1_TT0300l ? 0 :  ( (in->step>0) ? in->ti0300_t : in->log1_TT0300l )  ) ;
		cpy[((int *)&out->ti0300_t - (int *)out)] = 0;
		out->bc56_working =  ( (in->step<4) ? in->bc56_working : in->log2_CR0065 ) ;
		cpy[((int *)&out->bc56_working - (int *)out)] = 0;
		out->wghgat_z =  ( (in->step>0) ? in->wghgat_z :  ( in->log2_CR0081 ? 1 :  ( in->log1_CR0082 ? 0 : in->wghgat_z )  )  ) ;
		cpy[((int *)&out->wghgat_z - (int *)out)] = 0;
		out->wghhop_h =  ( (in->step>0) ? in->wghhop_h :  ( in->wghgat_z ? 0 :  ( bc56_q ?  ( in->wghhop_h == 7 ? in->wghhop_h : in->wghhop_h + 1 )  : in->wghhop_h )  )  ) ;
		cpy[((int *)&out->wghhop_h - (int *)out)] = 0;
		out->mixgat_z =  ( (in->step>0) ? in->mixgat_z :  ( in->log1_CR0101 ? 1 :  ( !in->log1_CR0101 ? 0 : in->mixgat_z )  )  ) ;
		cpy[((int *)&out->mixgat_z - (int *)out)] = 0;
		out->eirich_material =  ( (in->step<4) ? in->eirich_material :  ( in->mixgat_z ? 0 :  ( (in->wghgat_z && (in->wghhop_h>0)) ? 1 : in->eirich_material )  )  ) ;
		cpy[((int *)&out->eirich_material - (int *)out)] = 0;
		out->eirich_watsol =  ( (in->step<4) ? in->eirich_watsol : in->log1_CR0075 ) ;
		cpy[((int *)&out->eirich_watsol - (int *)out)] = 0;
		out->eirich_ms34 =  ( (in->step<4) ? in->eirich_ms34 : in->log2_CR0077 ) ;
		cpy[((int *)&out->eirich_ms34 - (int *)out)] = 0;
		out->eirich_mf34 =  ( (in->step<4) ? in->eirich_mf34 : in->log1_CR0069 ) ;
		cpy[((int *)&out->eirich_mf34 - (int *)out)] = 0;
		out->eirich_m7 =  ( (in->step<4) ? in->eirich_m7 : in->log1_CR0085 ) ;
		cpy[((int *)&out->eirich_m7 - (int *)out)] = 0;
		out->eirich_m9 =  ( (in->step<4) ? in->eirich_m9 : in->log1_CR0089 ) ;
		cpy[((int *)&out->eirich_m9 - (int *)out)] = 0;
		out->flare_air_sol =  ( (in->step<4) ? in->flare_air_sol : in->log1_CR0048 ) ;
		cpy[((int *)&out->flare_air_sol - (int *)out)] = 0;
		out->flare_pilot_valve =  ( (in->step<4) ? in->flare_pilot_valve : IN0148 ) ;
		cpy[((int *)&out->flare_pilot_valve - (int *)out)] = 0;
		out->flare_main_valve =  ( (in->step<4) ? in->flare_main_valve :  ( !IN0148 ? 0 :  ( in->flare_flame ? 1 : in->flare_main_valve )  )  ) ;
		cpy[((int *)&out->flare_main_valve - (int *)out)] = 0;
		out->flare_flame =  ( (in->step<4) ? in->flare_flame :  ( flare_q && flare_gas ? 1 : 0 )  ) ;
		cpy[((int *)&out->flare_flame - (int *)out)] = 0;
		out->bc57_working =  ( (in->step<4) ? in->bc57_working : in->log2_CR0106 ) ;
		cpy[((int *)&out->bc57_working - (int *)out)] = 0;
		out->fail0148hl =  ( (in->step<4) ? in->fail0148hl :  ( (in->fail0148hl == 0) ? smv_non_deterministic("fail0148hl",2,1,2) :  ( (in->fail0148hl == 3) ? 0 : in->fail0148hl )  )  ) ;
		cpy[((int *)&out->fail0148hl - (int *)out)] = 0;
		out->fail0149hl =  ( (in->step<4) ? in->fail0149hl :  ( (in->fail0149hl == 0) ? smv_non_deterministic("fail0149hl",2,1,2) :  ( (in->fail0149hl == 3) ? 0 : in->fail0149hl )  )  ) ;
		cpy[((int *)&out->fail0149hl - (int *)out)] = 0;
		out->repeat = smv_non_deterministic("repeat",2,FALSE,TRUE);
		cpy[((int *)&out->repeat - (int *)out)] = 0;
		out->log1_f = smv_non_deterministic("log1_f",2,FALSE,TRUE);
		cpy[((int *)&out->log1_f - (int *)out)] = 0;
		out->log1_m = smv_non_deterministic("log1_m",2,FALSE,TRUE);
		cpy[((int *)&out->log1_m - (int *)out)] = 0;
		out->log1_o = smv_non_deterministic("log1_o",2,FALSE,TRUE);
		cpy[((int *)&out->log1_o - (int *)out)] = 0;
		out->log1_p = smv_non_deterministic("log1_p",2,FALSE,TRUE);
		cpy[((int *)&out->log1_p - (int *)out)] = 0;
		out->log2_q = smv_non_deterministic("log2_q",2,FALSE,TRUE);
		cpy[((int *)&out->log2_q - (int *)out)] = 0;
		out->log2_ab = smv_non_deterministic("log2_ab",2,FALSE,TRUE);
		cpy[((int *)&out->log2_ab - (int *)out)] = 0;
		out->log2_ac = smv_non_deterministic("log2_ac",2,FALSE,TRUE);
		cpy[((int *)&out->log2_ac - (int *)out)] = 0;
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
	((int[]){67,0,1,2,3,8,34,40,55,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,39,29,30,31,32,33,35,36,37,38,41,42,43,44,45,46,47,48,49,50,51,52,53,54,56,57,58,59,60,61,62,63,64,65,66})
};

int *write_m[2] = {
	((int[]){68,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,19,20,22,24,25,27,28,29,30,31,32,33,34,36,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,0,10,18,21,23,26,35,37}),
	((int[]){67,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,19,20,22,24,25,27,28,29,30,31,32,33,34,36,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,0,10,18,21,23,26,35,37})
};

int *label_m[2] = {
	((int[]){1,67}),
	((int[]){1,67})
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
char pins_plugin_name[] = "bc57-sensors";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"repeat");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"step");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"again");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"opstep");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"log1_CR0307");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"log1_CR0308");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"log1_CR0299");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"log1_CR0075");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"log1_CR0048");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"log1_CR0261");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"log1_f");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"log1_CR0270");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"log1_CR0069");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"log1_TS0272l");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"log1_CR0085");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"log1_TS0274l");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"log1_CR0089");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"log1_CR0082");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"log1_m");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"log1_TT0300l");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"log1_CR0309");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"log1_o");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"log1_CR0101");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"log1_p");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"log1_change");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"log2_CR0065");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"log2_q");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"log2_CR0106");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"log2_TT0276l");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"log2_TS0297l");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"log2_TT0262l");
	lts_type_set_state_typeno(ltstype, 30,int_type);
	lts_type_set_state_name(ltstype, 31,"log2_TS0271l");
	lts_type_set_state_typeno(ltstype, 31,int_type);
	lts_type_set_state_name(ltstype, 32,"log2_CR0077");
	lts_type_set_state_typeno(ltstype, 32,int_type);
	lts_type_set_state_name(ltstype, 33,"log2_CR0081");
	lts_type_set_state_typeno(ltstype, 33,int_type);
	lts_type_set_state_name(ltstype, 34,"log2_CR0080");
	lts_type_set_state_typeno(ltstype, 34,int_type);
	lts_type_set_state_name(ltstype, 35,"log2_ab");
	lts_type_set_state_typeno(ltstype, 35,int_type);
	lts_type_set_state_name(ltstype, 36,"log2_CR0278");
	lts_type_set_state_typeno(ltstype, 36,int_type);
	lts_type_set_state_name(ltstype, 37,"log2_ac");
	lts_type_set_state_typeno(ltstype, 37,int_type);
	lts_type_set_state_name(ltstype, 38,"log2_change");
	lts_type_set_state_typeno(ltstype, 38,int_type);
	lts_type_set_state_name(ltstype, 39,"log3_CR0287");
	lts_type_set_state_typeno(ltstype, 39,int_type);
	lts_type_set_state_name(ltstype, 40,"log3_CR0285");
	lts_type_set_state_typeno(ltstype, 40,int_type);
	lts_type_set_state_name(ltstype, 41,"log3_change");
	lts_type_set_state_typeno(ltstype, 41,int_type);
	lts_type_set_state_name(ltstype, 42,"ti0276_t");
	lts_type_set_state_typeno(ltstype, 42,int_type);
	lts_type_set_state_name(ltstype, 43,"ti0297_t");
	lts_type_set_state_typeno(ltstype, 43,int_type);
	lts_type_set_state_name(ltstype, 44,"ti0297_done");
	lts_type_set_state_typeno(ltstype, 44,int_type);
	lts_type_set_state_name(ltstype, 45,"ti0262_t");
	lts_type_set_state_typeno(ltstype, 45,int_type);
	lts_type_set_state_name(ltstype, 46,"ti0271_t");
	lts_type_set_state_typeno(ltstype, 46,int_type);
	lts_type_set_state_name(ltstype, 47,"ti0272_t");
	lts_type_set_state_typeno(ltstype, 47,int_type);
	lts_type_set_state_name(ltstype, 48,"ti0274_t");
	lts_type_set_state_typeno(ltstype, 48,int_type);
	lts_type_set_state_name(ltstype, 49,"ti0300_t");
	lts_type_set_state_typeno(ltstype, 49,int_type);
	lts_type_set_state_name(ltstype, 50,"bc56_working");
	lts_type_set_state_typeno(ltstype, 50,int_type);
	lts_type_set_state_name(ltstype, 51,"wghgat_z");
	lts_type_set_state_typeno(ltstype, 51,int_type);
	lts_type_set_state_name(ltstype, 52,"wghhop_h");
	lts_type_set_state_typeno(ltstype, 52,int_type);
	lts_type_set_state_name(ltstype, 53,"mixgat_z");
	lts_type_set_state_typeno(ltstype, 53,int_type);
	lts_type_set_state_name(ltstype, 54,"eirich_material");
	lts_type_set_state_typeno(ltstype, 54,int_type);
	lts_type_set_state_name(ltstype, 55,"eirich_watsol");
	lts_type_set_state_typeno(ltstype, 55,int_type);
	lts_type_set_state_name(ltstype, 56,"eirich_ms34");
	lts_type_set_state_typeno(ltstype, 56,int_type);
	lts_type_set_state_name(ltstype, 57,"eirich_mf34");
	lts_type_set_state_typeno(ltstype, 57,int_type);
	lts_type_set_state_name(ltstype, 58,"eirich_m7");
	lts_type_set_state_typeno(ltstype, 58,int_type);
	lts_type_set_state_name(ltstype, 59,"eirich_m9");
	lts_type_set_state_typeno(ltstype, 59,int_type);
	lts_type_set_state_name(ltstype, 60,"flare_air_sol");
	lts_type_set_state_typeno(ltstype, 60,int_type);
	lts_type_set_state_name(ltstype, 61,"flare_pilot_valve");
	lts_type_set_state_typeno(ltstype, 61,int_type);
	lts_type_set_state_name(ltstype, 62,"flare_main_valve");
	lts_type_set_state_typeno(ltstype, 62,int_type);
	lts_type_set_state_name(ltstype, 63,"flare_flame");
	lts_type_set_state_typeno(ltstype, 63,int_type);
	lts_type_set_state_name(ltstype, 64,"bc57_working");
	lts_type_set_state_typeno(ltstype, 64,int_type);
	lts_type_set_state_name(ltstype, 65,"fail0148hl");
	lts_type_set_state_typeno(ltstype, 65,int_type);
	lts_type_set_state_name(ltstype, 66,"fail0149hl");
	lts_type_set_state_typeno(ltstype, 66,int_type);
	lts_type_set_state_name(ltstype, 67,"virtual_init");
	lts_type_set_state_typeno(ltstype, 67,int_type);

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
	int state[68];
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
