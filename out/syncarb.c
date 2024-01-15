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
	return 51;
}

typedef struct state_t {
	boolean AIGER_NEXT_e10_Request;
	boolean AIGER_NEXT_e9_Request;
	boolean AIGER_NEXT_e8_Request;
	boolean AIGER_NEXT_e7_Request;
	boolean AIGER_NEXT_e6_Request;
	boolean AIGER_NEXT_e5_Request;
	boolean AIGER_NEXT_e4_Request;
	boolean AIGER_NEXT_e3_Request;
	boolean AIGER_NEXT_e2_Request;
	boolean AIGER_NEXT_e1_Request;
	boolean AIGER_NEXT_LTL_1_SPECF_3;
	boolean AIGER_NEXT_LTL_1_SPECF_1;
	boolean AIGER_NEXT_IGNORE_LTL_1;
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
	boolean LTL_1_SPECF_3;
	boolean LTL_1_SPECF_1;
	boolean IGNORE_LTL_1;
	boolean AIGER_VALID;
	boolean AIGER_INITIALIZED;
	boolean VA296;
	boolean VA298;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.AIGER_NEXT_e10_Request                 = FALSE,
	.AIGER_NEXT_e9_Request                  = FALSE,
	.AIGER_NEXT_e8_Request                  = FALSE,
	.AIGER_NEXT_e7_Request                  = FALSE,
	.AIGER_NEXT_e6_Request                  = FALSE,
	.AIGER_NEXT_e5_Request                  = FALSE,
	.AIGER_NEXT_e4_Request                  = FALSE,
	.AIGER_NEXT_e3_Request                  = FALSE,
	.AIGER_NEXT_e2_Request                  = FALSE,
	.AIGER_NEXT_e1_Request                  = FALSE,
	.AIGER_NEXT_LTL_1_SPECF_3               = FALSE,
	.AIGER_NEXT_LTL_1_SPECF_1               = FALSE,
	.AIGER_NEXT_IGNORE_LTL_1                = FALSE,
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
	.LTL_1_SPECF_3                          = FALSE,
	.LTL_1_SPECF_1                          = FALSE,
	.IGNORE_LTL_1                           = FALSE,
	.AIGER_VALID                            = FALSE,
	.AIGER_INITIALIZED                      = FALSE,
	.VA296                                  = FALSE,
	.VA298                                  = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"AIGER_NEXT_e10_Request",1,0x0},
	{"AIGER_NEXT_e9_Request",1,0x0},
	{"AIGER_NEXT_e8_Request",1,0x0},
	{"AIGER_NEXT_e7_Request",1,0x0},
	{"AIGER_NEXT_e6_Request",1,0x0},
	{"AIGER_NEXT_e5_Request",1,0x0},
	{"AIGER_NEXT_e4_Request",1,0x0},
	{"AIGER_NEXT_e3_Request",1,0x0},
	{"AIGER_NEXT_e2_Request",1,0x0},
	{"AIGER_NEXT_e1_Request",1,0x0},
	{"AIGER_NEXT_LTL_1_SPECF_3",1,0x0},
	{"AIGER_NEXT_LTL_1_SPECF_1",1,0x0},
	{"AIGER_NEXT_IGNORE_LTL_1",1,0x0},
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
	{"LTL_1_SPECF_3",1,0x0},
	{"LTL_1_SPECF_1",1,0x0},
	{"IGNORE_LTL_1",1,0x0},
	{"AIGER_VALID",1,0x0},
	{"AIGER_INITIALIZED",1,0x0},
	{"VA296",1,0x0},
	{"VA298",1,0x0},
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
	int cpy[51] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
	switch(t) {
	case 0: {
		memcpy(out, in, sizeof(state_t));
		int a98;
		int a100;
		int a102;
		int a104;
		int a106;
		int a108;
		int a110;
		int a112;
		int a114;
		int a116;
		int a118;
		int a120;
		int a122;
		int a124;
		int a126;
		int a128;
		int a130;
		int a132;
		int a134;
		int a136;
		int a138;
		int a140;
		int a142;
		int a144;
		int a146;
		int a148;
		int a150;
		int a152;
		int a154;
		int a156;
		int a158;
		int a160;
		int a162;
		int a164;
		int a166;
		int a168;
		int a170;
		int a172;
		int a174;
		int a176;
		int a178;
		int a180;
		int a182;
		int a184;
		int a186;
		int a188;
		int a190;
		int a192;
		int a194;
		int a196;
		int a198;
		int a200;
		int a202;
		int a204;
		int a206;
		int a208;
		int a210;
		int a212;
		int a214;
		int a216;
		int a218;
		int a220;
		int a222;
		int a224;
		int a226;
		int a228;
		int a230;
		int a232;
		int a234;
		int a236;
		int a238;
		int a240;
		int a242;
		int a244;
		int a246;
		int a248;
		int a250;
		int a252;
		int a254;
		int a256;
		int a258;
		int a260;
		int a262;
		int a264;
		int a266;
		int a268;
		int a270;
		int a272;
		int a274;
		int a276;
		int a278;
		int a280;
		int a282;
		int a284;
		int a286;
		int a288;
		int a290;
		int a292;
		int a294;
		int a296;
		int a298;
		a98 = !in->e10_Persistent && !in->e10_Token;
		a100 = in->e10_Request && !a98;
		a102 = a100 && in->AIGER_INITIALIZED;
		a104 = in->e9_Token && in->AIGER_INITIALIZED;
		a106 = !in->e9_Persistent && !in->e9_Token;
		a108 = in->e9_Request && !a106;
		a110 = a108 && in->AIGER_INITIALIZED;
		a112 = in->e8_Token && in->AIGER_INITIALIZED;
		a114 = !in->e8_Persistent && !in->e8_Token;
		a116 = in->e8_Request && !a114;
		a118 = a116 && in->AIGER_INITIALIZED;
		a120 = in->e7_Token && in->AIGER_INITIALIZED;
		a122 = !in->e7_Persistent && !in->e7_Token;
		a124 = in->e7_Request && !a122;
		a126 = a124 && in->AIGER_INITIALIZED;
		a128 = in->e6_Token && in->AIGER_INITIALIZED;
		a130 = !in->e6_Persistent && !in->e6_Token;
		a132 = in->e6_Request && !a130;
		a134 = a132 && in->AIGER_INITIALIZED;
		a136 = in->e5_Token && in->AIGER_INITIALIZED;
		a138 = !in->e5_Persistent && !in->e5_Token;
		a140 = in->e5_Request && !a138;
		a142 = a140 && in->AIGER_INITIALIZED;
		a144 = in->e4_Token && in->AIGER_INITIALIZED;
		a146 = !in->e4_Persistent && !in->e4_Token;
		a148 = in->e4_Request && !a146;
		a150 = a148 && in->AIGER_INITIALIZED;
		a152 = in->e3_Token && in->AIGER_INITIALIZED;
		a154 = !in->e3_Persistent && !in->e3_Token;
		a156 = in->e3_Request && !a154;
		a158 = a156 && in->AIGER_INITIALIZED;
		a160 = in->e2_Token && in->AIGER_INITIALIZED;
		a162 = !in->e2_Persistent && !in->e2_Token;
		a164 = in->e2_Request && !a162;
		a166 = a164 && in->AIGER_INITIALIZED;
		a168 = in->e1_Token && in->AIGER_INITIALIZED;
		a170 = !in->e1_Persistent && !in->e1_Token;
		a172 = in->e1_Request && !a170;
		a174 = a172 && in->AIGER_INITIALIZED;
		a176 = !in->e10_Token && in->AIGER_INITIALIZED;
		a178 = !in->AIGER_NEXT_LTL_1_SPECF_1 && !in->AIGER_NEXT_IGNORE_LTL_1;
		a180 = !in->AIGER_INITIALIZED && a178;
		a182 = in->IGNORE_LTL_1 && !in->AIGER_NEXT_IGNORE_LTL_1;
		a184 = in->e9_Token && a100;
		a186 = in->e8_Token && a108;
		a188 = !a184 && !a186;
		a190 = in->e7_Token && a116;
		a192 = a188 && !a190;
		a194 = in->e6_Token && a124;
		a196 = a192 && !a194;
		a198 = in->e5_Token && a132;
		a200 = a196 && !a198;
		a202 = in->e4_Token && a140;
		a204 = a200 && !a202;
		a206 = in->e3_Token && a148;
		a208 = a204 && !a206;
		a210 = in->e2_Token && a156;
		a212 = a208 && !a210;
		a214 = in->e1_Token && a164;
		a216 = a212 && !a214;
		a218 = in->e10_Token && a172;
		a220 = !a216 && !a218;
		a222 = in->AIGER_NEXT_e1_Request && a220;
		a224 = !in->AIGER_NEXT_LTL_1_SPECF_3 && a222;
		a226 = !in->AIGER_NEXT_LTL_1_SPECF_1 && !a224;
		a228 = in->LTL_1_SPECF_1 && a226;
		a230 = !in->LTL_1_SPECF_1 && !a226;
		a232 = !a228 && !a230;
		a234 = in->LTL_1_SPECF_3 && a224;
		a236 = !in->LTL_1_SPECF_3 && !a224;
		a238 = !a234 && !a236;
		a240 = a232 && a238;
		a242 = !in->IGNORE_LTL_1 && !a240;
		a244 = !a182 && !a242;
		a246 = a244 && in->AIGER_VALID;
		a248 = !a246 && in->AIGER_INITIALIZED;
		a250 = !a180 && !a248;
		a252 = in->e10_Persistent && in->e10_Token;
		a254 = in->e9_Persistent && in->e9_Token;
		a256 = !a252 && !a254;
		a258 = in->e8_Persistent && in->e8_Token;
		a260 = a256 && !a258;
		a262 = in->e7_Persistent && in->e7_Token;
		a264 = a260 && !a262;
		a266 = in->e6_Persistent && in->e6_Token;
		a268 = a264 && !a266;
		a270 = in->e5_Persistent && in->e5_Token;
		a272 = a268 && !a270;
		a274 = in->e4_Persistent && in->e4_Token;
		a276 = a272 && !a274;
		a278 = in->e3_Persistent && in->e3_Token;
		a280 = a276 && !a278;
		a282 = in->e2_Persistent && in->e2_Token;
		a284 = a280 && !a282;
		a286 = in->e1_Persistent && in->e1_Token;
		a288 = !a284 && !a286;
		a290 = in->e1_Request && a288;
		a292 = a290 && !in->LTL_1_SPECF_3;
		a294 = !a292 && in->LTL_1_SPECF_1;
		a296 = !a294 && in->AIGER_VALID;
		a298 = !in->IGNORE_LTL_1 && in->AIGER_VALID;
		out->e10_Persistent = FALSE;
		cpy[((int *)&out->e10_Persistent - (int *)out)] = 0;
		out->e10_Token = FALSE;
		cpy[((int *)&out->e10_Token - (int *)out)] = 0;
		out->e10_Request = FALSE;
		cpy[((int *)&out->e10_Request - (int *)out)] = 0;
		out->e9_Persistent = FALSE;
		cpy[((int *)&out->e9_Persistent - (int *)out)] = 0;
		out->e9_Token = FALSE;
		cpy[((int *)&out->e9_Token - (int *)out)] = 0;
		out->e9_Request = FALSE;
		cpy[((int *)&out->e9_Request - (int *)out)] = 0;
		out->e8_Persistent = FALSE;
		cpy[((int *)&out->e8_Persistent - (int *)out)] = 0;
		out->e8_Token = FALSE;
		cpy[((int *)&out->e8_Token - (int *)out)] = 0;
		out->e8_Request = FALSE;
		cpy[((int *)&out->e8_Request - (int *)out)] = 0;
		out->e7_Persistent = FALSE;
		cpy[((int *)&out->e7_Persistent - (int *)out)] = 0;
		out->e7_Token = FALSE;
		cpy[((int *)&out->e7_Token - (int *)out)] = 0;
		out->e7_Request = FALSE;
		cpy[((int *)&out->e7_Request - (int *)out)] = 0;
		out->e6_Persistent = FALSE;
		cpy[((int *)&out->e6_Persistent - (int *)out)] = 0;
		out->e6_Token = FALSE;
		cpy[((int *)&out->e6_Token - (int *)out)] = 0;
		out->e6_Request = FALSE;
		cpy[((int *)&out->e6_Request - (int *)out)] = 0;
		out->e5_Persistent = FALSE;
		cpy[((int *)&out->e5_Persistent - (int *)out)] = 0;
		out->e5_Token = FALSE;
		cpy[((int *)&out->e5_Token - (int *)out)] = 0;
		out->e5_Request = FALSE;
		cpy[((int *)&out->e5_Request - (int *)out)] = 0;
		out->e4_Persistent = FALSE;
		cpy[((int *)&out->e4_Persistent - (int *)out)] = 0;
		out->e4_Token = FALSE;
		cpy[((int *)&out->e4_Token - (int *)out)] = 0;
		out->e4_Request = FALSE;
		cpy[((int *)&out->e4_Request - (int *)out)] = 0;
		out->e3_Persistent = FALSE;
		cpy[((int *)&out->e3_Persistent - (int *)out)] = 0;
		out->e3_Token = FALSE;
		cpy[((int *)&out->e3_Token - (int *)out)] = 0;
		out->e3_Request = FALSE;
		cpy[((int *)&out->e3_Request - (int *)out)] = 0;
		out->e2_Persistent = FALSE;
		cpy[((int *)&out->e2_Persistent - (int *)out)] = 0;
		out->e2_Token = FALSE;
		cpy[((int *)&out->e2_Token - (int *)out)] = 0;
		out->e2_Request = FALSE;
		cpy[((int *)&out->e2_Request - (int *)out)] = 0;
		out->e1_Persistent = FALSE;
		cpy[((int *)&out->e1_Persistent - (int *)out)] = 0;
		out->e1_Token = TRUE;
		cpy[((int *)&out->e1_Token - (int *)out)] = 0;
		out->e1_Request = FALSE;
		cpy[((int *)&out->e1_Request - (int *)out)] = 0;
		out->LTL_1_SPECF_3 = FALSE;
		cpy[((int *)&out->LTL_1_SPECF_3 - (int *)out)] = 0;
		out->LTL_1_SPECF_1 = FALSE;
		cpy[((int *)&out->LTL_1_SPECF_1 - (int *)out)] = 0;
		out->IGNORE_LTL_1 = FALSE;
		cpy[((int *)&out->IGNORE_LTL_1 - (int *)out)] = 0;
		out->AIGER_VALID = FALSE;
		cpy[((int *)&out->AIGER_VALID - (int *)out)] = 0;
		out->AIGER_INITIALIZED = FALSE;
		cpy[((int *)&out->AIGER_INITIALIZED - (int *)out)] = 0;
		out->VA296 = FALSE;
		cpy[((int *)&out->VA296 - (int *)out)] = 0;
		out->VA298 = FALSE;
		cpy[((int *)&out->VA298 - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->AIGER_NEXT_e10_Request = smv_non_deterministic("AIGER_NEXT_e10_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e10_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e9_Request = smv_non_deterministic("AIGER_NEXT_e9_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e9_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e8_Request = smv_non_deterministic("AIGER_NEXT_e8_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e8_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e7_Request = smv_non_deterministic("AIGER_NEXT_e7_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e7_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e6_Request = smv_non_deterministic("AIGER_NEXT_e6_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e6_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e5_Request = smv_non_deterministic("AIGER_NEXT_e5_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e5_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e4_Request = smv_non_deterministic("AIGER_NEXT_e4_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e4_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e3_Request = smv_non_deterministic("AIGER_NEXT_e3_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e3_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e2_Request = smv_non_deterministic("AIGER_NEXT_e2_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e2_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e1_Request = smv_non_deterministic("AIGER_NEXT_e1_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e1_Request - (int *)out)] = 0;
		out->AIGER_NEXT_LTL_1_SPECF_3 = smv_non_deterministic("AIGER_NEXT_LTL_1_SPECF_3",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_LTL_1_SPECF_3 - (int *)out)] = 0;
		out->AIGER_NEXT_LTL_1_SPECF_1 = smv_non_deterministic("AIGER_NEXT_LTL_1_SPECF_1",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_LTL_1_SPECF_1 - (int *)out)] = 0;
		out->AIGER_NEXT_IGNORE_LTL_1 = smv_non_deterministic("AIGER_NEXT_IGNORE_LTL_1",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_IGNORE_LTL_1 - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int a98;
		int a100;
		int a102;
		int a104;
		int a106;
		int a108;
		int a110;
		int a112;
		int a114;
		int a116;
		int a118;
		int a120;
		int a122;
		int a124;
		int a126;
		int a128;
		int a130;
		int a132;
		int a134;
		int a136;
		int a138;
		int a140;
		int a142;
		int a144;
		int a146;
		int a148;
		int a150;
		int a152;
		int a154;
		int a156;
		int a158;
		int a160;
		int a162;
		int a164;
		int a166;
		int a168;
		int a170;
		int a172;
		int a174;
		int a176;
		int a178;
		int a180;
		int a182;
		int a184;
		int a186;
		int a188;
		int a190;
		int a192;
		int a194;
		int a196;
		int a198;
		int a200;
		int a202;
		int a204;
		int a206;
		int a208;
		int a210;
		int a212;
		int a214;
		int a216;
		int a218;
		int a220;
		int a222;
		int a224;
		int a226;
		int a228;
		int a230;
		int a232;
		int a234;
		int a236;
		int a238;
		int a240;
		int a242;
		int a244;
		int a246;
		int a248;
		int a250;
		int a252;
		int a254;
		int a256;
		int a258;
		int a260;
		int a262;
		int a264;
		int a266;
		int a268;
		int a270;
		int a272;
		int a274;
		int a276;
		int a278;
		int a280;
		int a282;
		int a284;
		int a286;
		int a288;
		int a290;
		int a292;
		int a294;
		int a296;
		int a298;
		a98 = !in->e10_Persistent && !in->e10_Token;
		a100 = in->e10_Request && !a98;
		a102 = a100 && in->AIGER_INITIALIZED;
		a104 = in->e9_Token && in->AIGER_INITIALIZED;
		a106 = !in->e9_Persistent && !in->e9_Token;
		a108 = in->e9_Request && !a106;
		a110 = a108 && in->AIGER_INITIALIZED;
		a112 = in->e8_Token && in->AIGER_INITIALIZED;
		a114 = !in->e8_Persistent && !in->e8_Token;
		a116 = in->e8_Request && !a114;
		a118 = a116 && in->AIGER_INITIALIZED;
		a120 = in->e7_Token && in->AIGER_INITIALIZED;
		a122 = !in->e7_Persistent && !in->e7_Token;
		a124 = in->e7_Request && !a122;
		a126 = a124 && in->AIGER_INITIALIZED;
		a128 = in->e6_Token && in->AIGER_INITIALIZED;
		a130 = !in->e6_Persistent && !in->e6_Token;
		a132 = in->e6_Request && !a130;
		a134 = a132 && in->AIGER_INITIALIZED;
		a136 = in->e5_Token && in->AIGER_INITIALIZED;
		a138 = !in->e5_Persistent && !in->e5_Token;
		a140 = in->e5_Request && !a138;
		a142 = a140 && in->AIGER_INITIALIZED;
		a144 = in->e4_Token && in->AIGER_INITIALIZED;
		a146 = !in->e4_Persistent && !in->e4_Token;
		a148 = in->e4_Request && !a146;
		a150 = a148 && in->AIGER_INITIALIZED;
		a152 = in->e3_Token && in->AIGER_INITIALIZED;
		a154 = !in->e3_Persistent && !in->e3_Token;
		a156 = in->e3_Request && !a154;
		a158 = a156 && in->AIGER_INITIALIZED;
		a160 = in->e2_Token && in->AIGER_INITIALIZED;
		a162 = !in->e2_Persistent && !in->e2_Token;
		a164 = in->e2_Request && !a162;
		a166 = a164 && in->AIGER_INITIALIZED;
		a168 = in->e1_Token && in->AIGER_INITIALIZED;
		a170 = !in->e1_Persistent && !in->e1_Token;
		a172 = in->e1_Request && !a170;
		a174 = a172 && in->AIGER_INITIALIZED;
		a176 = !in->e10_Token && in->AIGER_INITIALIZED;
		a178 = !in->AIGER_NEXT_LTL_1_SPECF_1 && !in->AIGER_NEXT_IGNORE_LTL_1;
		a180 = !in->AIGER_INITIALIZED && a178;
		a182 = in->IGNORE_LTL_1 && !in->AIGER_NEXT_IGNORE_LTL_1;
		a184 = in->e9_Token && a100;
		a186 = in->e8_Token && a108;
		a188 = !a184 && !a186;
		a190 = in->e7_Token && a116;
		a192 = a188 && !a190;
		a194 = in->e6_Token && a124;
		a196 = a192 && !a194;
		a198 = in->e5_Token && a132;
		a200 = a196 && !a198;
		a202 = in->e4_Token && a140;
		a204 = a200 && !a202;
		a206 = in->e3_Token && a148;
		a208 = a204 && !a206;
		a210 = in->e2_Token && a156;
		a212 = a208 && !a210;
		a214 = in->e1_Token && a164;
		a216 = a212 && !a214;
		a218 = in->e10_Token && a172;
		a220 = !a216 && !a218;
		a222 = in->AIGER_NEXT_e1_Request && a220;
		a224 = !in->AIGER_NEXT_LTL_1_SPECF_3 && a222;
		a226 = !in->AIGER_NEXT_LTL_1_SPECF_1 && !a224;
		a228 = in->LTL_1_SPECF_1 && a226;
		a230 = !in->LTL_1_SPECF_1 && !a226;
		a232 = !a228 && !a230;
		a234 = in->LTL_1_SPECF_3 && a224;
		a236 = !in->LTL_1_SPECF_3 && !a224;
		a238 = !a234 && !a236;
		a240 = a232 && a238;
		a242 = !in->IGNORE_LTL_1 && !a240;
		a244 = !a182 && !a242;
		a246 = a244 && in->AIGER_VALID;
		a248 = !a246 && in->AIGER_INITIALIZED;
		a250 = !a180 && !a248;
		a252 = in->e10_Persistent && in->e10_Token;
		a254 = in->e9_Persistent && in->e9_Token;
		a256 = !a252 && !a254;
		a258 = in->e8_Persistent && in->e8_Token;
		a260 = a256 && !a258;
		a262 = in->e7_Persistent && in->e7_Token;
		a264 = a260 && !a262;
		a266 = in->e6_Persistent && in->e6_Token;
		a268 = a264 && !a266;
		a270 = in->e5_Persistent && in->e5_Token;
		a272 = a268 && !a270;
		a274 = in->e4_Persistent && in->e4_Token;
		a276 = a272 && !a274;
		a278 = in->e3_Persistent && in->e3_Token;
		a280 = a276 && !a278;
		a282 = in->e2_Persistent && in->e2_Token;
		a284 = a280 && !a282;
		a286 = in->e1_Persistent && in->e1_Token;
		a288 = !a284 && !a286;
		a290 = in->e1_Request && a288;
		a292 = a290 && !in->LTL_1_SPECF_3;
		a294 = !a292 && in->LTL_1_SPECF_1;
		a296 = !a294 && in->AIGER_VALID;
		a298 = !in->IGNORE_LTL_1 && in->AIGER_VALID;
		out->e10_Persistent = a102;
		cpy[((int *)&out->e10_Persistent - (int *)out)] = 0;
		out->e10_Token = a104;
		cpy[((int *)&out->e10_Token - (int *)out)] = 0;
		out->e10_Request = in->AIGER_NEXT_e10_Request;
		cpy[((int *)&out->e10_Request - (int *)out)] = 0;
		out->e9_Persistent = a110;
		cpy[((int *)&out->e9_Persistent - (int *)out)] = 0;
		out->e9_Token = a112;
		cpy[((int *)&out->e9_Token - (int *)out)] = 0;
		out->e9_Request = in->AIGER_NEXT_e9_Request;
		cpy[((int *)&out->e9_Request - (int *)out)] = 0;
		out->e8_Persistent = a118;
		cpy[((int *)&out->e8_Persistent - (int *)out)] = 0;
		out->e8_Token = a120;
		cpy[((int *)&out->e8_Token - (int *)out)] = 0;
		out->e8_Request = in->AIGER_NEXT_e8_Request;
		cpy[((int *)&out->e8_Request - (int *)out)] = 0;
		out->e7_Persistent = a126;
		cpy[((int *)&out->e7_Persistent - (int *)out)] = 0;
		out->e7_Token = a128;
		cpy[((int *)&out->e7_Token - (int *)out)] = 0;
		out->e7_Request = in->AIGER_NEXT_e7_Request;
		cpy[((int *)&out->e7_Request - (int *)out)] = 0;
		out->e6_Persistent = a134;
		cpy[((int *)&out->e6_Persistent - (int *)out)] = 0;
		out->e6_Token = a136;
		cpy[((int *)&out->e6_Token - (int *)out)] = 0;
		out->e6_Request = in->AIGER_NEXT_e6_Request;
		cpy[((int *)&out->e6_Request - (int *)out)] = 0;
		out->e5_Persistent = a142;
		cpy[((int *)&out->e5_Persistent - (int *)out)] = 0;
		out->e5_Token = a144;
		cpy[((int *)&out->e5_Token - (int *)out)] = 0;
		out->e5_Request = in->AIGER_NEXT_e5_Request;
		cpy[((int *)&out->e5_Request - (int *)out)] = 0;
		out->e4_Persistent = a150;
		cpy[((int *)&out->e4_Persistent - (int *)out)] = 0;
		out->e4_Token = a152;
		cpy[((int *)&out->e4_Token - (int *)out)] = 0;
		out->e4_Request = in->AIGER_NEXT_e4_Request;
		cpy[((int *)&out->e4_Request - (int *)out)] = 0;
		out->e3_Persistent = a158;
		cpy[((int *)&out->e3_Persistent - (int *)out)] = 0;
		out->e3_Token = a160;
		cpy[((int *)&out->e3_Token - (int *)out)] = 0;
		out->e3_Request = in->AIGER_NEXT_e3_Request;
		cpy[((int *)&out->e3_Request - (int *)out)] = 0;
		out->e2_Persistent = a166;
		cpy[((int *)&out->e2_Persistent - (int *)out)] = 0;
		out->e2_Token = a168;
		cpy[((int *)&out->e2_Token - (int *)out)] = 0;
		out->e2_Request = in->AIGER_NEXT_e2_Request;
		cpy[((int *)&out->e2_Request - (int *)out)] = 0;
		out->e1_Persistent = a174;
		cpy[((int *)&out->e1_Persistent - (int *)out)] = 0;
		out->e1_Token = !a176;
		cpy[((int *)&out->e1_Token - (int *)out)] = 0;
		out->e1_Request = in->AIGER_NEXT_e1_Request;
		cpy[((int *)&out->e1_Request - (int *)out)] = 0;
		out->LTL_1_SPECF_3 = in->AIGER_NEXT_LTL_1_SPECF_3;
		cpy[((int *)&out->LTL_1_SPECF_3 - (int *)out)] = 0;
		out->LTL_1_SPECF_1 = in->AIGER_NEXT_LTL_1_SPECF_1;
		cpy[((int *)&out->LTL_1_SPECF_1 - (int *)out)] = 0;
		out->IGNORE_LTL_1 = in->AIGER_NEXT_IGNORE_LTL_1;
		cpy[((int *)&out->IGNORE_LTL_1 - (int *)out)] = 0;
		out->AIGER_VALID = a250;
		cpy[((int *)&out->AIGER_VALID - (int *)out)] = 0;
		out->AIGER_INITIALIZED = TRUE;
		cpy[((int *)&out->AIGER_INITIALIZED - (int *)out)] = 0;
		out->VA296 = a296;
		cpy[((int *)&out->VA296 - (int *)out)] = 0;
		out->VA298 = a298;
		cpy[((int *)&out->VA298 - (int *)out)] = 0;
		out->AIGER_NEXT_e10_Request = smv_non_deterministic("AIGER_NEXT_e10_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e10_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e9_Request = smv_non_deterministic("AIGER_NEXT_e9_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e9_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e8_Request = smv_non_deterministic("AIGER_NEXT_e8_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e8_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e7_Request = smv_non_deterministic("AIGER_NEXT_e7_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e7_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e6_Request = smv_non_deterministic("AIGER_NEXT_e6_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e6_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e5_Request = smv_non_deterministic("AIGER_NEXT_e5_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e5_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e4_Request = smv_non_deterministic("AIGER_NEXT_e4_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e4_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e3_Request = smv_non_deterministic("AIGER_NEXT_e3_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e3_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e2_Request = smv_non_deterministic("AIGER_NEXT_e2_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e2_Request - (int *)out)] = 0;
		out->AIGER_NEXT_e1_Request = smv_non_deterministic("AIGER_NEXT_e1_Request",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_e1_Request - (int *)out)] = 0;
		out->AIGER_NEXT_LTL_1_SPECF_3 = smv_non_deterministic("AIGER_NEXT_LTL_1_SPECF_3",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_LTL_1_SPECF_3 - (int *)out)] = 0;
		out->AIGER_NEXT_LTL_1_SPECF_1 = smv_non_deterministic("AIGER_NEXT_LTL_1_SPECF_1",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_LTL_1_SPECF_1 - (int *)out)] = 0;
		out->AIGER_NEXT_IGNORE_LTL_1 = smv_non_deterministic("AIGER_NEXT_IGNORE_LTL_1",2,FALSE,TRUE);
		cpy[((int *)&out->AIGER_NEXT_IGNORE_LTL_1 - (int *)out)] = 0;
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
	((int[]){26,0,15,1,18,2,21,3,24,4,27,5,30,6,33,7,36,8,39,9,42,10,43,11,44,12,45})
};

int *write_m[2] = {
	((int[]){51,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,0,1,2,3,4,5,6,7,8,9,10,11,12}),
	((int[]){50,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,0,1,2,3,4,5,6,7,8,9,10,11,12})
};

int *label_m[2] = {
	((int[]){1,50}),
	((int[]){1,50})
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
char pins_plugin_name[] = "ttt";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"AIGER_NEXT_e10_Request");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"AIGER_NEXT_e9_Request");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"AIGER_NEXT_e8_Request");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"AIGER_NEXT_e7_Request");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"AIGER_NEXT_e6_Request");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"AIGER_NEXT_e5_Request");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"AIGER_NEXT_e4_Request");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"AIGER_NEXT_e3_Request");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"AIGER_NEXT_e2_Request");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"AIGER_NEXT_e1_Request");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"AIGER_NEXT_LTL_1_SPECF_3");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"AIGER_NEXT_LTL_1_SPECF_1");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"AIGER_NEXT_IGNORE_LTL_1");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"e10_Persistent");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"e10_Token");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"e10_Request");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"e9_Persistent");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"e9_Token");
	lts_type_set_state_typeno(ltstype, 17,int_type);
	lts_type_set_state_name(ltstype, 18,"e9_Request");
	lts_type_set_state_typeno(ltstype, 18,int_type);
	lts_type_set_state_name(ltstype, 19,"e8_Persistent");
	lts_type_set_state_typeno(ltstype, 19,int_type);
	lts_type_set_state_name(ltstype, 20,"e8_Token");
	lts_type_set_state_typeno(ltstype, 20,int_type);
	lts_type_set_state_name(ltstype, 21,"e8_Request");
	lts_type_set_state_typeno(ltstype, 21,int_type);
	lts_type_set_state_name(ltstype, 22,"e7_Persistent");
	lts_type_set_state_typeno(ltstype, 22,int_type);
	lts_type_set_state_name(ltstype, 23,"e7_Token");
	lts_type_set_state_typeno(ltstype, 23,int_type);
	lts_type_set_state_name(ltstype, 24,"e7_Request");
	lts_type_set_state_typeno(ltstype, 24,int_type);
	lts_type_set_state_name(ltstype, 25,"e6_Persistent");
	lts_type_set_state_typeno(ltstype, 25,int_type);
	lts_type_set_state_name(ltstype, 26,"e6_Token");
	lts_type_set_state_typeno(ltstype, 26,int_type);
	lts_type_set_state_name(ltstype, 27,"e6_Request");
	lts_type_set_state_typeno(ltstype, 27,int_type);
	lts_type_set_state_name(ltstype, 28,"e5_Persistent");
	lts_type_set_state_typeno(ltstype, 28,int_type);
	lts_type_set_state_name(ltstype, 29,"e5_Token");
	lts_type_set_state_typeno(ltstype, 29,int_type);
	lts_type_set_state_name(ltstype, 30,"e5_Request");
	lts_type_set_state_typeno(ltstype, 30,int_type);
	lts_type_set_state_name(ltstype, 31,"e4_Persistent");
	lts_type_set_state_typeno(ltstype, 31,int_type);
	lts_type_set_state_name(ltstype, 32,"e4_Token");
	lts_type_set_state_typeno(ltstype, 32,int_type);
	lts_type_set_state_name(ltstype, 33,"e4_Request");
	lts_type_set_state_typeno(ltstype, 33,int_type);
	lts_type_set_state_name(ltstype, 34,"e3_Persistent");
	lts_type_set_state_typeno(ltstype, 34,int_type);
	lts_type_set_state_name(ltstype, 35,"e3_Token");
	lts_type_set_state_typeno(ltstype, 35,int_type);
	lts_type_set_state_name(ltstype, 36,"e3_Request");
	lts_type_set_state_typeno(ltstype, 36,int_type);
	lts_type_set_state_name(ltstype, 37,"e2_Persistent");
	lts_type_set_state_typeno(ltstype, 37,int_type);
	lts_type_set_state_name(ltstype, 38,"e2_Token");
	lts_type_set_state_typeno(ltstype, 38,int_type);
	lts_type_set_state_name(ltstype, 39,"e2_Request");
	lts_type_set_state_typeno(ltstype, 39,int_type);
	lts_type_set_state_name(ltstype, 40,"e1_Persistent");
	lts_type_set_state_typeno(ltstype, 40,int_type);
	lts_type_set_state_name(ltstype, 41,"e1_Token");
	lts_type_set_state_typeno(ltstype, 41,int_type);
	lts_type_set_state_name(ltstype, 42,"e1_Request");
	lts_type_set_state_typeno(ltstype, 42,int_type);
	lts_type_set_state_name(ltstype, 43,"LTL_1_SPECF_3");
	lts_type_set_state_typeno(ltstype, 43,int_type);
	lts_type_set_state_name(ltstype, 44,"LTL_1_SPECF_1");
	lts_type_set_state_typeno(ltstype, 44,int_type);
	lts_type_set_state_name(ltstype, 45,"IGNORE_LTL_1");
	lts_type_set_state_typeno(ltstype, 45,int_type);
	lts_type_set_state_name(ltstype, 46,"AIGER_VALID");
	lts_type_set_state_typeno(ltstype, 46,int_type);
	lts_type_set_state_name(ltstype, 47,"AIGER_INITIALIZED");
	lts_type_set_state_typeno(ltstype, 47,int_type);
	lts_type_set_state_name(ltstype, 48,"VA296");
	lts_type_set_state_typeno(ltstype, 48,int_type);
	lts_type_set_state_name(ltstype, 49,"VA298");
	lts_type_set_state_typeno(ltstype, 49,int_type);
	lts_type_set_state_name(ltstype, 50,"virtual_init");
	lts_type_set_state_typeno(ltstype, 50,int_type);

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
	int state[51];
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
