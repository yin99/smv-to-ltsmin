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
	return 19;
}

typedef struct state_t {
	boolean i2;
	boolean i4;
	boolean i6;
	boolean i8;
	boolean l10;
	boolean l12;
	boolean l14;
	boolean l16;
	boolean l18;
	boolean l20;
	boolean l22;
	boolean l24;
	boolean l26;
	boolean l28;
	boolean l30;
	boolean l32;
	boolean l34;
	boolean l36;
	boolean virtual_init;
} state_t;

state_t initial_s = (state_t) {
	.i2                                     = FALSE,
	.i4                                     = FALSE,
	.i6                                     = FALSE,
	.i8                                     = FALSE,
	.l10                                    = FALSE,
	.l12                                    = FALSE,
	.l14                                    = FALSE,
	.l16                                    = FALSE,
	.l18                                    = FALSE,
	.l20                                    = FALSE,
	.l22                                    = FALSE,
	.l24                                    = FALSE,
	.l26                                    = FALSE,
	.l28                                    = FALSE,
	.l30                                    = FALSE,
	.l32                                    = FALSE,
	.l34                                    = FALSE,
	.l36                                    = FALSE,
	.virtual_init                           = TRUE
};

smv_basic_var basic_var_list[] = {
	{"i2",1,0x0},
	{"i4",1,0x0},
	{"i6",1,0x0},
	{"i8",1,0x0},
	{"l10",1,0x0},
	{"l12",1,0x0},
	{"l14",1,0x0},
	{"l16",1,0x0},
	{"l18",1,0x0},
	{"l20",1,0x0},
	{"l22",1,0x0},
	{"l24",1,0x0},
	{"l26",1,0x0},
	{"l28",1,0x0},
	{"l30",1,0x0},
	{"l32",1,0x0},
	{"l34",1,0x0},
	{"l36",1,0x0},
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
		int a38;
		int a40;
		int a42;
		int a44;
		int a46;
		int a48;
		int a50;
		int a52;
		int a54;
		int a56;
		int a58;
		int a60;
		int a62;
		int a64;
		int a66;
		int a68;
		int a70;
		int a72;
		int a74;
		int a76;
		int a78;
		int a80;
		int a82;
		int a84;
		int a86;
		int a88;
		int a90;
		int a92;
		int a94;
		int a96;
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
		int a300;
		int a302;
		int a304;
		int a306;
		int a308;
		int a310;
		int a312;
		int a314;
		int a316;
		int a318;
		int a320;
		int a322;
		int a324;
		int a326;
		int a328;
		int a330;
		int a332;
		int a334;
		int a336;
		int a338;
		int a340;
		int a342;
		int a344;
		int a346;
		int a348;
		int a350;
		int a352;
		int a354;
		int a356;
		int a358;
		int a360;
		int a362;
		int a364;
		int a366;
		int a368;
		int a370;
		int a372;
		int a374;
		int a376;
		int a378;
		int a380;
		int a382;
		int a384;
		int a386;
		int a388;
		int a390;
		int a392;
		int a394;
		int a396;
		int a398;
		int a400;
		int a402;
		int a404;
		int a406;
		int a408;
		int a410;
		int a412;
		int a414;
		int a416;
		int a418;
		int a420;
		int a422;
		int a424;
		int a426;
		int a428;
		int a430;
		int a432;
		int a434;
		int a436;
		int a438;
		int a440;
		int a442;
		int a444;
		int a446;
		int a448;
		int a450;
		int a452;
		int a454;
		int a456;
		int a458;
		int a460;
		int a462;
		int a464;
		int a466;
		int a468;
		int a470;
		int a472;
		int a474;
		int a476;
		int a478;
		int a480;
		int a482;
		int a484;
		int a486;
		int a488;
		int a490;
		int a492;
		int a494;
		int a496;
		int a498;
		int a500;
		int a502;
		int a504;
		int a506;
		int a508;
		int a510;
		int a512;
		int a514;
		int a516;
		int a518;
		int a520;
		int a522;
		int a524;
		int a526;
		int a528;
		int a530;
		int a532;
		int a534;
		int a536;
		int a538;
		int a540;
		int a542;
		int a544;
		int a546;
		int a548;
		int a550;
		int a552;
		int a554;
		int a556;
		int a558;
		int a560;
		int a562;
		int a564;
		int a566;
		int a568;
		int a570;
		int a572;
		int a574;
		int a576;
		int a578;
		int a580;
		int a582;
		int a584;
		int a586;
		int a588;
		int a590;
		int a592;
		int a594;
		int a596;
		int a598;
		int a600;
		int a602;
		int a604;
		int a606;
		int a608;
		int a610;
		int a612;
		a38 = in->l18 && !in->i4;
		a40 = !in->l18 && in->i4;
		a42 = !a40 && !a38;
		a44 = in->l28 && !in->i2;
		a46 = !in->l28 && in->i2;
		a48 = !a46 && !a44;
		a50 = a48 && a42;
		a52 = in->l16 && !in->i4;
		a54 = !in->l16 && in->i4;
		a56 = !a54 && !a52;
		a58 = in->l36 && !in->i2;
		a60 = !in->l36 && in->i2;
		a62 = !a60 && !a58;
		a64 = a62 && a56;
		a66 = in->l34 && !in->i4;
		a68 = !in->l34 && in->i4;
		a70 = !a68 && !a66;
		a72 = in->l26 && !in->i2;
		a74 = !in->l26 && in->i2;
		a76 = !a74 && !a72;
		a78 = a76 && a70;
		a80 = in->l24 && !in->i4;
		a82 = !in->l24 && in->i4;
		a84 = !a82 && !a80;
		a86 = in->l14 && !in->i2;
		a88 = !in->l14 && in->i2;
		a90 = !a88 && !a86;
		a92 = a90 && a84;
		a94 = !a92 && !a78;
		a96 = a94 && !a64;
		a98 = a96 && !a50;
		a100 = in->l12 && !in->i4;
		a102 = !in->l12 && in->i4;
		a104 = !a102 && !a100;
		a106 = in->l32 && !in->i2;
		a108 = !in->l32 && in->i2;
		a110 = !a108 && !a106;
		a112 = a110 && a104;
		a114 = in->l30 && !in->i4;
		a116 = !in->l30 && in->i4;
		a118 = !a116 && !a114;
		a120 = in->l22 && !in->i2;
		a122 = !in->l22 && in->i2;
		a124 = !a122 && !a120;
		a126 = a124 && a118;
		a128 = !a126 && !a112;
		a130 = !a128 && !a92;
		a132 = a130 && !a78;
		a134 = !a132 && !a64;
		a136 = in->l20 && !in->i4;
		a138 = !in->l20 && in->i4;
		a140 = !a138 && !a136;
		a142 = in->l10 && !in->i2;
		a144 = !in->l10 && in->i2;
		a146 = !a144 && !a142;
		a148 = a146 && a140;
		a150 = a148 && !a126;
		a152 = !a150 && !a112;
		a154 = !a152 && !a92;
		a156 = !a154 && !a78;
		a158 = !a156 && !a64;
		a160 = !a158 && !a50;
		a162 = a160 && a134;
		a164 = a162 && a98;
		a166 = a134 && !a50;
		a168 = a166 && a158;
		a170 = a160 && !a134;
		a172 = !a170 && !a168;
		a174 = a172 && a160;
		a176 = a162 && !a98;
		a178 = !a162 && a98;
		a180 = !a178 && !a176;
		a182 = a180 && a174;
		a184 = !a182 && !a164;
		a186 = in->l18 && !in->i6;
		a188 = !in->l18 && in->i6;
		a190 = !a188 && !a186;
		a192 = in->l28 && !in->i8;
		a194 = !in->l28 && in->i8;
		a196 = !a194 && !a192;
		a198 = a196 && a190;
		a200 = in->l16 && !in->i6;
		a202 = !in->l16 && in->i6;
		a204 = !a202 && !a200;
		a206 = in->l36 && !in->i8;
		a208 = !in->l36 && in->i8;
		a210 = !a208 && !a206;
		a212 = a210 && a204;
		a214 = in->l34 && !in->i6;
		a216 = !in->l34 && in->i6;
		a218 = !a216 && !a214;
		a220 = in->l26 && !in->i8;
		a222 = !in->l26 && in->i8;
		a224 = !a222 && !a220;
		a226 = a224 && a218;
		a228 = in->l24 && !in->i6;
		a230 = !in->l24 && in->i6;
		a232 = !a230 && !a228;
		a234 = in->l14 && !in->i8;
		a236 = !in->l14 && in->i8;
		a238 = !a236 && !a234;
		a240 = a238 && a232;
		a242 = in->l12 && !in->i6;
		a244 = !in->l12 && in->i6;
		a246 = !a244 && !a242;
		a248 = in->l32 && !in->i8;
		a250 = !in->l32 && in->i8;
		a252 = !a250 && !a248;
		a254 = a252 && a246;
		a256 = in->l30 && !in->i6;
		a258 = !in->l30 && in->i6;
		a260 = !a258 && !a256;
		a262 = in->l22 && !in->i8;
		a264 = !in->l22 && in->i8;
		a266 = !a264 && !a262;
		a268 = a266 && a260;
		a270 = in->l20 && !in->i6;
		a272 = !in->l20 && in->i6;
		a274 = !a272 && !a270;
		a276 = in->l10 && !in->i8;
		a278 = !in->l10 && in->i8;
		a280 = !a278 && !a276;
		a282 = a280 && a274;
		a284 = a282 && !a268;
		a286 = !a284 && !a254;
		a288 = !a286 && !a240;
		a290 = !a288 && !a226;
		a292 = !a290 && !a212;
		a294 = !a292 && !a198;
		a296 = a294 && !a160;
		a298 = a296 && !a166;
		a300 = !a268 && !a254;
		a302 = !a300 && !a240;
		a304 = a302 && !a226;
		a306 = !a304 && !a212;
		a308 = a306 && !a198;
		a310 = a308 && !a166;
		a312 = !a310 && !a298;
		a314 = a308 && a296;
		a316 = !a314 && a312;
		a318 = !a316 && !a98;
		a320 = !a240 && !a226;
		a322 = a320 && !a212;
		a324 = a322 && !a198;
		a326 = a324 && !a98;
		a328 = !a326 && !a318;
		a330 = a324 && !a316;
		a332 = !a330 && a328;
		a334 = !a294 && a160;
		a336 = !a334 && !a296;
		a338 = !a308 && a166;
		a340 = !a338 && !a310;
		a342 = !a340 && !a296;
		a344 = a340 && a296;
		a346 = !a344 && !a342;
		a348 = a346 && a336;
		a350 = !a324 && a98;
		a352 = !a350 && !a326;
		a354 = !a352 && a316;
		a356 = a352 && !a316;
		a358 = !a356 && !a354;
		a360 = a358 && a348;
		a362 = !a360 && !a332;
		a364 = a362 && a184;
		a366 = !a364 && !in->l10;
		a368 = a168 && a98;
		a370 = !a368 && !in->l10;
		a372 = a368 && !in->i8;
		a374 = !a372 && !a370;
		a376 = !a374 && a364;
		a378 = !a376 && !a366;
		a380 = !a378 && a364;
		a382 = !a380 && !a366;
		a384 = !a364 && !in->l12;
		a386 = !a166 && !a160;
		a388 = a386 && a98;
		a390 = !a388 && !in->l12;
		a392 = a388 && !in->i6;
		a394 = !a392 && !a390;
		a396 = !a394 && a364;
		a398 = !a396 && !a384;
		a400 = !a398 && a364;
		a402 = !a400 && !a384;
		a404 = !a364 && !in->l14;
		a406 = a166 && !a158;
		a408 = a406 && !a98;
		a410 = !a408 && !in->l14;
		a412 = a408 && !in->i8;
		a414 = !a412 && !a410;
		a416 = !a414 && a364;
		a418 = !a416 && !a404;
		a420 = !a418 && a364;
		a422 = !a420 && !a404;
		a424 = !a364 && !in->l16;
		a426 = a170 && !a98;
		a428 = !a426 && !in->l16;
		a430 = a426 && !in->i6;
		a432 = !a430 && !a428;
		a434 = !a432 && a364;
		a436 = !a434 && !a424;
		a438 = !a436 && a364;
		a440 = !a438 && !a424;
		a442 = !a364 && !in->l18;
		a444 = a386 && !a98;
		a446 = !a444 && !in->l18;
		a448 = a444 && !in->i6;
		a450 = !a448 && !a446;
		a452 = !a450 && a364;
		a454 = !a452 && !a442;
		a456 = !a454 && a364;
		a458 = !a456 && !a442;
		a460 = !a364 && !in->l20;
		a462 = !a368 && !in->l20;
		a464 = a368 && !in->i6;
		a466 = !a464 && !a462;
		a468 = !a466 && a364;
		a470 = !a468 && !a460;
		a472 = !a470 && a364;
		a474 = !a472 && !a460;
		a476 = !a364 && !in->l22;
		a478 = a170 && a98;
		a480 = !a478 && !in->l22;
		a482 = a478 && !in->i8;
		a484 = !a482 && !a480;
		a486 = !a484 && a364;
		a488 = !a486 && !a476;
		a490 = !a488 && a364;
		a492 = !a490 && !a476;
		a494 = !a364 && !in->l24;
		a496 = !a408 && !in->l24;
		a498 = a408 && !in->i6;
		a500 = !a498 && !a496;
		a502 = !a500 && a364;
		a504 = !a502 && !a494;
		a506 = !a504 && a364;
		a508 = !a506 && !a494;
		a510 = !a364 && !in->l26;
		a512 = a168 && !a98;
		a514 = !a512 && !in->l26;
		a516 = a512 && !in->i8;
		a518 = !a516 && !a514;
		a520 = !a518 && a364;
		a522 = !a520 && !a510;
		a524 = !a522 && a364;
		a526 = !a524 && !a510;
		a528 = !a364 && !in->l28;
		a530 = !a444 && !in->l28;
		a532 = a444 && !in->i8;
		a534 = !a532 && !a530;
		a536 = !a534 && a364;
		a538 = !a536 && !a528;
		a540 = !a538 && a364;
		a542 = !a540 && !a528;
		a544 = !a364 && !in->l30;
		a546 = !a478 && !in->l30;
		a548 = a478 && !in->i6;
		a550 = !a548 && !a546;
		a552 = !a550 && a364;
		a554 = !a552 && !a544;
		a556 = !a554 && a364;
		a558 = !a556 && !a544;
		a560 = !a364 && !in->l32;
		a562 = !a388 && !in->l32;
		a564 = a388 && !in->i8;
		a566 = !a564 && !a562;
		a568 = !a566 && a364;
		a570 = !a568 && !a560;
		a572 = !a570 && a364;
		a574 = !a572 && !a560;
		a576 = !a364 && !in->l34;
		a578 = !a512 && !in->l34;
		a580 = a512 && !in->i6;
		a582 = !a580 && !a578;
		a584 = !a582 && a364;
		a586 = !a584 && !a576;
		a588 = !a586 && a364;
		a590 = !a588 && !a576;
		a592 = !a364 && !in->l36;
		a594 = !a426 && !in->l36;
		a596 = a426 && !in->i8;
		a598 = !a596 && !a594;
		a600 = !a598 && a364;
		a602 = !a600 && !a592;
		a604 = !a602 && a364;
		a606 = !a604 && !a592;
		a608 = !in->l20 && in->l10;
		a610 = !in->l20 && !in->l10;
		a612 = in->l20 && !in->l10;
		out->l10 = FALSE;
		cpy[((int *)&out->l10 - (int *)out)] = 0;
		out->l12 = FALSE;
		cpy[((int *)&out->l12 - (int *)out)] = 0;
		out->l14 = FALSE;
		cpy[((int *)&out->l14 - (int *)out)] = 0;
		out->l16 = FALSE;
		cpy[((int *)&out->l16 - (int *)out)] = 0;
		out->l18 = FALSE;
		cpy[((int *)&out->l18 - (int *)out)] = 0;
		out->l20 = FALSE;
		cpy[((int *)&out->l20 - (int *)out)] = 0;
		out->l22 = FALSE;
		cpy[((int *)&out->l22 - (int *)out)] = 0;
		out->l24 = FALSE;
		cpy[((int *)&out->l24 - (int *)out)] = 0;
		out->l26 = FALSE;
		cpy[((int *)&out->l26 - (int *)out)] = 0;
		out->l28 = FALSE;
		cpy[((int *)&out->l28 - (int *)out)] = 0;
		out->l30 = FALSE;
		cpy[((int *)&out->l30 - (int *)out)] = 0;
		out->l32 = FALSE;
		cpy[((int *)&out->l32 - (int *)out)] = 0;
		out->l34 = FALSE;
		cpy[((int *)&out->l34 - (int *)out)] = 0;
		out->l36 = FALSE;
		cpy[((int *)&out->l36 - (int *)out)] = 0;
		out->virtual_init = FALSE;
		cpy[((int *)&out->virtual_init - (int *)out)] = 0;
		out->i2 = smv_non_deterministic("i2",2,FALSE,TRUE);
		cpy[((int *)&out->i2 - (int *)out)] = 0;
		out->i4 = smv_non_deterministic("i4",2,FALSE,TRUE);
		cpy[((int *)&out->i4 - (int *)out)] = 0;
		out->i6 = smv_non_deterministic("i6",2,FALSE,TRUE);
		cpy[((int *)&out->i6 - (int *)out)] = 0;
		out->i8 = smv_non_deterministic("i8",2,FALSE,TRUE);
		cpy[((int *)&out->i8 - (int *)out)] = 0;
		transition_labels[0] = 0;
		transition_info.group = 0;
		return states_emitted(out,&transition_info,cpy,callback,arg,0);
	}
	case 1: {
		memcpy(out, in, sizeof(state_t));
		int a38;
		int a40;
		int a42;
		int a44;
		int a46;
		int a48;
		int a50;
		int a52;
		int a54;
		int a56;
		int a58;
		int a60;
		int a62;
		int a64;
		int a66;
		int a68;
		int a70;
		int a72;
		int a74;
		int a76;
		int a78;
		int a80;
		int a82;
		int a84;
		int a86;
		int a88;
		int a90;
		int a92;
		int a94;
		int a96;
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
		int a300;
		int a302;
		int a304;
		int a306;
		int a308;
		int a310;
		int a312;
		int a314;
		int a316;
		int a318;
		int a320;
		int a322;
		int a324;
		int a326;
		int a328;
		int a330;
		int a332;
		int a334;
		int a336;
		int a338;
		int a340;
		int a342;
		int a344;
		int a346;
		int a348;
		int a350;
		int a352;
		int a354;
		int a356;
		int a358;
		int a360;
		int a362;
		int a364;
		int a366;
		int a368;
		int a370;
		int a372;
		int a374;
		int a376;
		int a378;
		int a380;
		int a382;
		int a384;
		int a386;
		int a388;
		int a390;
		int a392;
		int a394;
		int a396;
		int a398;
		int a400;
		int a402;
		int a404;
		int a406;
		int a408;
		int a410;
		int a412;
		int a414;
		int a416;
		int a418;
		int a420;
		int a422;
		int a424;
		int a426;
		int a428;
		int a430;
		int a432;
		int a434;
		int a436;
		int a438;
		int a440;
		int a442;
		int a444;
		int a446;
		int a448;
		int a450;
		int a452;
		int a454;
		int a456;
		int a458;
		int a460;
		int a462;
		int a464;
		int a466;
		int a468;
		int a470;
		int a472;
		int a474;
		int a476;
		int a478;
		int a480;
		int a482;
		int a484;
		int a486;
		int a488;
		int a490;
		int a492;
		int a494;
		int a496;
		int a498;
		int a500;
		int a502;
		int a504;
		int a506;
		int a508;
		int a510;
		int a512;
		int a514;
		int a516;
		int a518;
		int a520;
		int a522;
		int a524;
		int a526;
		int a528;
		int a530;
		int a532;
		int a534;
		int a536;
		int a538;
		int a540;
		int a542;
		int a544;
		int a546;
		int a548;
		int a550;
		int a552;
		int a554;
		int a556;
		int a558;
		int a560;
		int a562;
		int a564;
		int a566;
		int a568;
		int a570;
		int a572;
		int a574;
		int a576;
		int a578;
		int a580;
		int a582;
		int a584;
		int a586;
		int a588;
		int a590;
		int a592;
		int a594;
		int a596;
		int a598;
		int a600;
		int a602;
		int a604;
		int a606;
		int a608;
		int a610;
		int a612;
		a38 = in->l18 && !in->i4;
		a40 = !in->l18 && in->i4;
		a42 = !a40 && !a38;
		a44 = in->l28 && !in->i2;
		a46 = !in->l28 && in->i2;
		a48 = !a46 && !a44;
		a50 = a48 && a42;
		a52 = in->l16 && !in->i4;
		a54 = !in->l16 && in->i4;
		a56 = !a54 && !a52;
		a58 = in->l36 && !in->i2;
		a60 = !in->l36 && in->i2;
		a62 = !a60 && !a58;
		a64 = a62 && a56;
		a66 = in->l34 && !in->i4;
		a68 = !in->l34 && in->i4;
		a70 = !a68 && !a66;
		a72 = in->l26 && !in->i2;
		a74 = !in->l26 && in->i2;
		a76 = !a74 && !a72;
		a78 = a76 && a70;
		a80 = in->l24 && !in->i4;
		a82 = !in->l24 && in->i4;
		a84 = !a82 && !a80;
		a86 = in->l14 && !in->i2;
		a88 = !in->l14 && in->i2;
		a90 = !a88 && !a86;
		a92 = a90 && a84;
		a94 = !a92 && !a78;
		a96 = a94 && !a64;
		a98 = a96 && !a50;
		a100 = in->l12 && !in->i4;
		a102 = !in->l12 && in->i4;
		a104 = !a102 && !a100;
		a106 = in->l32 && !in->i2;
		a108 = !in->l32 && in->i2;
		a110 = !a108 && !a106;
		a112 = a110 && a104;
		a114 = in->l30 && !in->i4;
		a116 = !in->l30 && in->i4;
		a118 = !a116 && !a114;
		a120 = in->l22 && !in->i2;
		a122 = !in->l22 && in->i2;
		a124 = !a122 && !a120;
		a126 = a124 && a118;
		a128 = !a126 && !a112;
		a130 = !a128 && !a92;
		a132 = a130 && !a78;
		a134 = !a132 && !a64;
		a136 = in->l20 && !in->i4;
		a138 = !in->l20 && in->i4;
		a140 = !a138 && !a136;
		a142 = in->l10 && !in->i2;
		a144 = !in->l10 && in->i2;
		a146 = !a144 && !a142;
		a148 = a146 && a140;
		a150 = a148 && !a126;
		a152 = !a150 && !a112;
		a154 = !a152 && !a92;
		a156 = !a154 && !a78;
		a158 = !a156 && !a64;
		a160 = !a158 && !a50;
		a162 = a160 && a134;
		a164 = a162 && a98;
		a166 = a134 && !a50;
		a168 = a166 && a158;
		a170 = a160 && !a134;
		a172 = !a170 && !a168;
		a174 = a172 && a160;
		a176 = a162 && !a98;
		a178 = !a162 && a98;
		a180 = !a178 && !a176;
		a182 = a180 && a174;
		a184 = !a182 && !a164;
		a186 = in->l18 && !in->i6;
		a188 = !in->l18 && in->i6;
		a190 = !a188 && !a186;
		a192 = in->l28 && !in->i8;
		a194 = !in->l28 && in->i8;
		a196 = !a194 && !a192;
		a198 = a196 && a190;
		a200 = in->l16 && !in->i6;
		a202 = !in->l16 && in->i6;
		a204 = !a202 && !a200;
		a206 = in->l36 && !in->i8;
		a208 = !in->l36 && in->i8;
		a210 = !a208 && !a206;
		a212 = a210 && a204;
		a214 = in->l34 && !in->i6;
		a216 = !in->l34 && in->i6;
		a218 = !a216 && !a214;
		a220 = in->l26 && !in->i8;
		a222 = !in->l26 && in->i8;
		a224 = !a222 && !a220;
		a226 = a224 && a218;
		a228 = in->l24 && !in->i6;
		a230 = !in->l24 && in->i6;
		a232 = !a230 && !a228;
		a234 = in->l14 && !in->i8;
		a236 = !in->l14 && in->i8;
		a238 = !a236 && !a234;
		a240 = a238 && a232;
		a242 = in->l12 && !in->i6;
		a244 = !in->l12 && in->i6;
		a246 = !a244 && !a242;
		a248 = in->l32 && !in->i8;
		a250 = !in->l32 && in->i8;
		a252 = !a250 && !a248;
		a254 = a252 && a246;
		a256 = in->l30 && !in->i6;
		a258 = !in->l30 && in->i6;
		a260 = !a258 && !a256;
		a262 = in->l22 && !in->i8;
		a264 = !in->l22 && in->i8;
		a266 = !a264 && !a262;
		a268 = a266 && a260;
		a270 = in->l20 && !in->i6;
		a272 = !in->l20 && in->i6;
		a274 = !a272 && !a270;
		a276 = in->l10 && !in->i8;
		a278 = !in->l10 && in->i8;
		a280 = !a278 && !a276;
		a282 = a280 && a274;
		a284 = a282 && !a268;
		a286 = !a284 && !a254;
		a288 = !a286 && !a240;
		a290 = !a288 && !a226;
		a292 = !a290 && !a212;
		a294 = !a292 && !a198;
		a296 = a294 && !a160;
		a298 = a296 && !a166;
		a300 = !a268 && !a254;
		a302 = !a300 && !a240;
		a304 = a302 && !a226;
		a306 = !a304 && !a212;
		a308 = a306 && !a198;
		a310 = a308 && !a166;
		a312 = !a310 && !a298;
		a314 = a308 && a296;
		a316 = !a314 && a312;
		a318 = !a316 && !a98;
		a320 = !a240 && !a226;
		a322 = a320 && !a212;
		a324 = a322 && !a198;
		a326 = a324 && !a98;
		a328 = !a326 && !a318;
		a330 = a324 && !a316;
		a332 = !a330 && a328;
		a334 = !a294 && a160;
		a336 = !a334 && !a296;
		a338 = !a308 && a166;
		a340 = !a338 && !a310;
		a342 = !a340 && !a296;
		a344 = a340 && a296;
		a346 = !a344 && !a342;
		a348 = a346 && a336;
		a350 = !a324 && a98;
		a352 = !a350 && !a326;
		a354 = !a352 && a316;
		a356 = a352 && !a316;
		a358 = !a356 && !a354;
		a360 = a358 && a348;
		a362 = !a360 && !a332;
		a364 = a362 && a184;
		a366 = !a364 && !in->l10;
		a368 = a168 && a98;
		a370 = !a368 && !in->l10;
		a372 = a368 && !in->i8;
		a374 = !a372 && !a370;
		a376 = !a374 && a364;
		a378 = !a376 && !a366;
		a380 = !a378 && a364;
		a382 = !a380 && !a366;
		a384 = !a364 && !in->l12;
		a386 = !a166 && !a160;
		a388 = a386 && a98;
		a390 = !a388 && !in->l12;
		a392 = a388 && !in->i6;
		a394 = !a392 && !a390;
		a396 = !a394 && a364;
		a398 = !a396 && !a384;
		a400 = !a398 && a364;
		a402 = !a400 && !a384;
		a404 = !a364 && !in->l14;
		a406 = a166 && !a158;
		a408 = a406 && !a98;
		a410 = !a408 && !in->l14;
		a412 = a408 && !in->i8;
		a414 = !a412 && !a410;
		a416 = !a414 && a364;
		a418 = !a416 && !a404;
		a420 = !a418 && a364;
		a422 = !a420 && !a404;
		a424 = !a364 && !in->l16;
		a426 = a170 && !a98;
		a428 = !a426 && !in->l16;
		a430 = a426 && !in->i6;
		a432 = !a430 && !a428;
		a434 = !a432 && a364;
		a436 = !a434 && !a424;
		a438 = !a436 && a364;
		a440 = !a438 && !a424;
		a442 = !a364 && !in->l18;
		a444 = a386 && !a98;
		a446 = !a444 && !in->l18;
		a448 = a444 && !in->i6;
		a450 = !a448 && !a446;
		a452 = !a450 && a364;
		a454 = !a452 && !a442;
		a456 = !a454 && a364;
		a458 = !a456 && !a442;
		a460 = !a364 && !in->l20;
		a462 = !a368 && !in->l20;
		a464 = a368 && !in->i6;
		a466 = !a464 && !a462;
		a468 = !a466 && a364;
		a470 = !a468 && !a460;
		a472 = !a470 && a364;
		a474 = !a472 && !a460;
		a476 = !a364 && !in->l22;
		a478 = a170 && a98;
		a480 = !a478 && !in->l22;
		a482 = a478 && !in->i8;
		a484 = !a482 && !a480;
		a486 = !a484 && a364;
		a488 = !a486 && !a476;
		a490 = !a488 && a364;
		a492 = !a490 && !a476;
		a494 = !a364 && !in->l24;
		a496 = !a408 && !in->l24;
		a498 = a408 && !in->i6;
		a500 = !a498 && !a496;
		a502 = !a500 && a364;
		a504 = !a502 && !a494;
		a506 = !a504 && a364;
		a508 = !a506 && !a494;
		a510 = !a364 && !in->l26;
		a512 = a168 && !a98;
		a514 = !a512 && !in->l26;
		a516 = a512 && !in->i8;
		a518 = !a516 && !a514;
		a520 = !a518 && a364;
		a522 = !a520 && !a510;
		a524 = !a522 && a364;
		a526 = !a524 && !a510;
		a528 = !a364 && !in->l28;
		a530 = !a444 && !in->l28;
		a532 = a444 && !in->i8;
		a534 = !a532 && !a530;
		a536 = !a534 && a364;
		a538 = !a536 && !a528;
		a540 = !a538 && a364;
		a542 = !a540 && !a528;
		a544 = !a364 && !in->l30;
		a546 = !a478 && !in->l30;
		a548 = a478 && !in->i6;
		a550 = !a548 && !a546;
		a552 = !a550 && a364;
		a554 = !a552 && !a544;
		a556 = !a554 && a364;
		a558 = !a556 && !a544;
		a560 = !a364 && !in->l32;
		a562 = !a388 && !in->l32;
		a564 = a388 && !in->i8;
		a566 = !a564 && !a562;
		a568 = !a566 && a364;
		a570 = !a568 && !a560;
		a572 = !a570 && a364;
		a574 = !a572 && !a560;
		a576 = !a364 && !in->l34;
		a578 = !a512 && !in->l34;
		a580 = a512 && !in->i6;
		a582 = !a580 && !a578;
		a584 = !a582 && a364;
		a586 = !a584 && !a576;
		a588 = !a586 && a364;
		a590 = !a588 && !a576;
		a592 = !a364 && !in->l36;
		a594 = !a426 && !in->l36;
		a596 = a426 && !in->i8;
		a598 = !a596 && !a594;
		a600 = !a598 && a364;
		a602 = !a600 && !a592;
		a604 = !a602 && a364;
		a606 = !a604 && !a592;
		a608 = !in->l20 && in->l10;
		a610 = !in->l20 && !in->l10;
		a612 = in->l20 && !in->l10;
		out->l10 = a382;
		cpy[((int *)&out->l10 - (int *)out)] = 0;
		out->l12 = a402;
		cpy[((int *)&out->l12 - (int *)out)] = 0;
		out->l14 = a422;
		cpy[((int *)&out->l14 - (int *)out)] = 0;
		out->l16 = a440;
		cpy[((int *)&out->l16 - (int *)out)] = 0;
		out->l18 = a458;
		cpy[((int *)&out->l18 - (int *)out)] = 0;
		out->l20 = a474;
		cpy[((int *)&out->l20 - (int *)out)] = 0;
		out->l22 = a492;
		cpy[((int *)&out->l22 - (int *)out)] = 0;
		out->l24 = a508;
		cpy[((int *)&out->l24 - (int *)out)] = 0;
		out->l26 = a526;
		cpy[((int *)&out->l26 - (int *)out)] = 0;
		out->l28 = a542;
		cpy[((int *)&out->l28 - (int *)out)] = 0;
		out->l30 = a558;
		cpy[((int *)&out->l30 - (int *)out)] = 0;
		out->l32 = a574;
		cpy[((int *)&out->l32 - (int *)out)] = 0;
		out->l34 = a590;
		cpy[((int *)&out->l34 - (int *)out)] = 0;
		out->l36 = a606;
		cpy[((int *)&out->l36 - (int *)out)] = 0;
		out->i2 = smv_non_deterministic("i2",2,FALSE,TRUE);
		cpy[((int *)&out->i2 - (int *)out)] = 0;
		out->i4 = smv_non_deterministic("i4",2,FALSE,TRUE);
		cpy[((int *)&out->i4 - (int *)out)] = 0;
		out->i6 = smv_non_deterministic("i6",2,FALSE,TRUE);
		cpy[((int *)&out->i6 - (int *)out)] = 0;
		out->i8 = smv_non_deterministic("i8",2,FALSE,TRUE);
		cpy[((int *)&out->i8 - (int *)out)] = 0;
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
	((int[]){0})
};

int *write_m[2] = {
	((int[]){19,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,0,1,2,3}),
	((int[]){18,4,5,6,7,8,9,10,11,12,13,14,15,16,17,0,1,2,3})
};

int *label_m[2] = {
	((int[]){1,18}),
	((int[]){1,18})
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
char pins_plugin_name[] = "cuhanoi7ro";
void pins_model_init(model_t m) {
	// create the LTS type LTSmin will generate
	lts_type_t ltstype=lts_type_create();
	// set the length of the state
	lts_type_set_state_length(ltstype, smv_get_state_size());
	// add an int type for a state slot
	int int_type = lts_type_add_type(ltstype, "int", NULL);
	lts_type_set_format (ltstype, int_type, LTStypeDirect);
	lts_type_set_state_name(ltstype, 0,"i2");
	lts_type_set_state_typeno(ltstype, 0,int_type);
	lts_type_set_state_name(ltstype, 1,"i4");
	lts_type_set_state_typeno(ltstype, 1,int_type);
	lts_type_set_state_name(ltstype, 2,"i6");
	lts_type_set_state_typeno(ltstype, 2,int_type);
	lts_type_set_state_name(ltstype, 3,"i8");
	lts_type_set_state_typeno(ltstype, 3,int_type);
	lts_type_set_state_name(ltstype, 4,"l10");
	lts_type_set_state_typeno(ltstype, 4,int_type);
	lts_type_set_state_name(ltstype, 5,"l12");
	lts_type_set_state_typeno(ltstype, 5,int_type);
	lts_type_set_state_name(ltstype, 6,"l14");
	lts_type_set_state_typeno(ltstype, 6,int_type);
	lts_type_set_state_name(ltstype, 7,"l16");
	lts_type_set_state_typeno(ltstype, 7,int_type);
	lts_type_set_state_name(ltstype, 8,"l18");
	lts_type_set_state_typeno(ltstype, 8,int_type);
	lts_type_set_state_name(ltstype, 9,"l20");
	lts_type_set_state_typeno(ltstype, 9,int_type);
	lts_type_set_state_name(ltstype, 10,"l22");
	lts_type_set_state_typeno(ltstype, 10,int_type);
	lts_type_set_state_name(ltstype, 11,"l24");
	lts_type_set_state_typeno(ltstype, 11,int_type);
	lts_type_set_state_name(ltstype, 12,"l26");
	lts_type_set_state_typeno(ltstype, 12,int_type);
	lts_type_set_state_name(ltstype, 13,"l28");
	lts_type_set_state_typeno(ltstype, 13,int_type);
	lts_type_set_state_name(ltstype, 14,"l30");
	lts_type_set_state_typeno(ltstype, 14,int_type);
	lts_type_set_state_name(ltstype, 15,"l32");
	lts_type_set_state_typeno(ltstype, 15,int_type);
	lts_type_set_state_name(ltstype, 16,"l34");
	lts_type_set_state_typeno(ltstype, 16,int_type);
	lts_type_set_state_name(ltstype, 17,"l36");
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
	lts_type_set_state_label_name (ltstype, 1, "next");
	lts_type_validate(ltstype);
	GBsetLTStype(m, ltstype);
	pins_chunk_put(m, action_type, chunk_str("init"));
	pins_chunk_put(m, action_type, chunk_str("next"));
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
