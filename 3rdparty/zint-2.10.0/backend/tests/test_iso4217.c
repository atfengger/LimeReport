/*
    libzint - the open source barcode library
    Copyright (C) 2021 Robin Stuart <rstuart114@gmail.com>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the project nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
 */
/* vim: set ts=4 sw=4 et : */

#include "testcommon.h"
#include "../iso4217.h"

static void test_numeric(int index) {

    struct item {
        int data;
        int ret;
    };
    // s/\/\*[ 0-9]*\*\//\=printf("\/*%3d*\/", line(".") - line("'<"))
    struct item data[] = {
        /*  0*/ { -1, 0 },
        /*  1*/ { 0, 0 },
        /*  2*/ { 1, 0 },
        /*  3*/ { 2, 0 },
        /*  4*/ { 3, 0 },
        /*  5*/ { 4, 0 },
        /*  6*/ { 5, 0 },
        /*  7*/ { 6, 0 },
        /*  8*/ { 7, 0 },
        /*  9*/ { 8, 1 },
        /* 10*/ { 9, 0 },
        /* 11*/ { 10, 0 },
        /* 12*/ { 11, 0 },
        /* 13*/ { 12, 1 },
        /* 14*/ { 13, 0 },
        /* 15*/ { 14, 0 },
        /* 16*/ { 15, 0 },
        /* 17*/ { 16, 0 },
        /* 18*/ { 17, 0 },
        /* 19*/ { 18, 0 },
        /* 20*/ { 19, 0 },
        /* 21*/ { 20, 0 },
        /* 22*/ { 21, 0 },
        /* 23*/ { 31, 0 },
        /* 24*/ { 32, 1 },
        /* 25*/ { 33, 0 },
        /* 26*/ { 34, 0 },
        /* 27*/ { 35, 0 },
        /* 28*/ { 36, 1 },
        /* 29*/ { 37, 0 },
        /* 30*/ { 43, 0 },
        /* 31*/ { 44, 1 },
        /* 32*/ { 45, 0 },
        /* 33*/ { 49, 0 },
        /* 34*/ { 50, 1 },
        /* 35*/ { 51, 1 },
        /* 36*/ { 52, 1 },
        /* 37*/ { 53, 0 },
        /* 38*/ { 59, 0 },
        /* 39*/ { 60, 1 },
        /* 40*/ { 61, 0 },
        /* 41*/ { 62, 0 },
        /* 42*/ { 63, 0 },
        /* 43*/ { 64, 1 },
        /* 44*/ { 65, 0 },
        /* 45*/ { 66, 0 },
        /* 46*/ { 67, 0 },
        /* 47*/ { 68, 1 },
        /* 48*/ { 69, 0 },
        /* 49*/ { 70, 0 },
        /* 50*/ { 71, 0 },
        /* 51*/ { 72, 1 },
        /* 52*/ { 73, 0 },
        /* 53*/ { 80, 0 },
        /* 54*/ { 81, 0 },
        /* 55*/ { 82, 0 },
        /* 56*/ { 83, 0 },
        /* 57*/ { 84, 1 },
        /* 58*/ { 85, 0 },
        /* 59*/ { 89, 0 },
        /* 60*/ { 90, 1 },
        /* 61*/ { 91, 0 },
        /* 62*/ { 99, 0 },
        /* 63*/ { 100, 0 },
        /* 64*/ { 101, 0 },
        /* 65*/ { 102, 0 },
        /* 66*/ { 103, 0 },
        /* 67*/ { 104, 1 },
        /* 68*/ { 105, 0 },
        /* 69*/ { 110, 0 },
        /* 70*/ { 120, 0 },
        /* 71*/ { 130, 0 },
        /* 72*/ { 131, 0 },
        /* 73*/ { 132, 1 },
        /* 74*/ { 133, 0 },
        /* 75*/ { 143, 0 },
        /* 76*/ { 144, 1 },
        /* 77*/ { 145, 0 },
        /* 78*/ { 146, 0 },
        /* 79*/ { 147, 0 },
        /* 80*/ { 148, 0 },
        /* 81*/ { 149, 0 },
        /* 82*/ { 150, 0 },
        /* 83*/ { 160, 0 },
        /* 84*/ { 169, 0 },
        /* 85*/ { 170, 1 },
        /* 86*/ { 171, 0 },
        /* 87*/ { 180, 0 },
        /* 88*/ { 190, 0 },
        /* 89*/ { 191, 1 },
        /* 90*/ { 192, 1 },
        /* 91*/ { 193, 0 },
        /* 92*/ { 200, 0 },
        /* 93*/ { 210, 0 },
        /* 94*/ { 220, 0 },
        /* 95*/ { 221, 0 },
        /* 96*/ { 222, 1 },
        /* 97*/ { 223, 0 },
        /* 98*/ { 229, 0 },
        /* 99*/ { 230, 1 },
        /*100*/ { 231, 0 },
        /*101*/ { 232, 1 },
        /*102*/ { 233, 0 },
        /*103*/ { 234, 0 },
        /*104*/ { 235, 0 },
        /*105*/ { 236, 0 },
        /*106*/ { 237, 0 },
        /*107*/ { 238, 1 },
        /*108*/ { 239, 0 },
        /*109*/ { 240, 0 },
        /*110*/ { 241, 0 },
        /*111*/ { 242, 1 },
        /*112*/ { 243, 0 },
        /*113*/ { 250, 0 },
        /*114*/ { 260, 0 },
        /*115*/ { 269, 0 },
        /*116*/ { 270, 1 },
        /*117*/ { 271, 0 },
        /*118*/ { 280, 0 },
        /*119*/ { 290, 0 },
        /*120*/ { 291, 0 },
        /*121*/ { 292, 1 },
        /*122*/ { 293, 0 },
        /*123*/ { 300, 0 },
        /*124*/ { 310, 0 },
        /*125*/ { 319, 0 },
        /*126*/ { 320, 1 },
        /*127*/ { 321, 0 },
        /*128*/ { 322, 0 },
        /*129*/ { 323, 0 },
        /*130*/ { 324, 1 },
        /*131*/ { 325, 0 },
        /*132*/ { 330, 0 },
        /*133*/ { 331, 0 },
        /*134*/ { 332, 1 },
        /*135*/ { 333, 0 },
        /*136*/ { 339, 0 },
        /*137*/ { 340, 1 },
        /*138*/ { 341, 0 },
        /*139*/ { 350, 0 },
        /*140*/ { 351, 0 },
        /*141*/ { 352, 1 },
        /*142*/ { 353, 0 },
        /*143*/ { 359, 0 },
        /*144*/ { 360, 1 },
        /*145*/ { 361, 0 },
        /*146*/ { 367, 0 },
        /*147*/ { 368, 1 },
        /*148*/ { 369, 0 },
        /*149*/ { 370, 0 },
        /*150*/ { 380, 0 },
        /*151*/ { 390, 0 },
        /*152*/ { 391, 0 },
        /*153*/ { 392, 1 },
        /*154*/ { 393, 0 },
        /*155*/ { 397, 0 },
        /*156*/ { 398, 1 },
        /*157*/ { 399, 0 },
        /*158*/ { 400, 1 },
        /*159*/ { 401, 0 },
        /*160*/ { 409, 0 },
        /*161*/ { 410, 1 },
        /*162*/ { 411, 0 },
        /*163*/ { 425, 0 },
        /*164*/ { 426, 1 },
        /*165*/ { 427, 0 },
        /*166*/ { 428, 0 },
        /*167*/ { 429, 0 },
        /*168*/ { 430, 1 },
        /*169*/ { 431, 0 },
        /*170*/ { 432, 0 },
        /*171*/ { 433, 0 },
        /*172*/ { 434, 1 },
        /*173*/ { 435, 0 },
        /*174*/ { 436, 0 },
        /*175*/ { 437, 0 },
        /*176*/ { 438, 0 },
        /*177*/ { 439, 0 },
        /*178*/ { 440, 0 },
        /*179*/ { 441, 0 },
        /*180*/ { 442, 0 },
        /*181*/ { 443, 0 },
        /*182*/ { 450, 0 },
        /*183*/ { 460, 0 },
        /*184*/ { 470, 0 },
        /*185*/ { 479, 0 },
        /*186*/ { 480, 1 },
        /*187*/ { 481, 0 },
        /*188*/ { 495, 0 },
        /*189*/ { 496, 1 },
        /*190*/ { 497, 0 },
        /*191*/ { 498, 1 },
        /*192*/ { 499, 0 },
        /*193*/ { 500, 0 },
        /*194*/ { 501, 0 },
        /*195*/ { 502, 0 },
        /*196*/ { 503, 0 },
        /*197*/ { 504, 1 },
        /*198*/ { 505, 0 },
        /*199*/ { 510, 0 },
        /*200*/ { 520, 0 },
        /*201*/ { 530, 0 },
        /*202*/ { 540, 0 },
        /*203*/ { 550, 0 },
        /*204*/ { 557, 0 },
        /*205*/ { 558, 1 },
        /*206*/ { 559, 0 },
        /*207*/ { 560, 0 },
        /*208*/ { 561, 0 },
        /*209*/ { 562, 0 },
        /*210*/ { 563, 0 },
        /*211*/ { 564, 0 },
        /*212*/ { 565, 0 },
        /*213*/ { 566, 1 },
        /*214*/ { 567, 0 },
        /*215*/ { 570, 0 },
        /*216*/ { 580, 0 },
        /*217*/ { 589, 0 },
        /*218*/ { 590, 1 },
        /*219*/ { 591, 0 },
        /*220*/ { 597, 0 },
        /*221*/ { 598, 1 },
        /*222*/ { 599, 0 },
        /*223*/ { 600, 1 },
        /*224*/ { 601, 0 },
        /*225*/ { 610, 0 },
        /*226*/ { 611, 0 },
        /*227*/ { 612, 0 },
        /*228*/ { 613, 0 },
        /*229*/ { 620, 0 },
        /*230*/ { 630, 0 },
        /*231*/ { 640, 0 },
        /*232*/ { 650, 0 },
        /*233*/ { 660, 0 },
        /*234*/ { 670, 0 },
        /*235*/ { 677, 0 },
        /*236*/ { 678, 0 },
        /*237*/ { 679, 0 },
        /*238*/ { 680, 0 },
        /*239*/ { 681, 0 },
        /*240*/ { 682, 1 },
        /*241*/ { 683, 0 },
        /*242*/ { 689, 0 },
        /*243*/ { 690, 1 },
        /*244*/ { 691, 0 },
        /*245*/ { 700, 0 },
        /*246*/ { 701, 0 },
        /*247*/ { 702, 1 },
        /*248*/ { 703, 0 },
        /*249*/ { 704, 1 },
        /*250*/ { 705, 0 },
        /*251*/ { 706, 1 },
        /*252*/ { 707, 0 },
        /*253*/ { 708, 0 },
        /*254*/ { 709, 0 },
        /*255*/ { 710, 1 },
        /*256*/ { 711, 0 },
        /*257*/ { 720, 0 },
        /*258*/ { 730, 0 },
        /*259*/ { 740, 0 },
        /*260*/ { 750, 0 },
        /*261*/ { 751, 0 },
        /*262*/ { 752, 1 },
        /*263*/ { 753, 0 },
        /*264*/ { 759, 0 },
        /*265*/ { 760, 1 },
        /*266*/ { 761, 0 },
        /*267*/ { 770, 0 },
        /*268*/ { 779, 0 },
        /*269*/ { 780, 1 },
        /*270*/ { 781, 0 },
        /*271*/ { 790, 0 },
        /*272*/ { 799, 0 },
        /*273*/ { 800, 1 },
        /*274*/ { 801, 0 },
        /*275*/ { 810, 0 },
        /*276*/ { 820, 0 },
        /*277*/ { 830, 0 },
        /*278*/ { 839, 0 },
        /*279*/ { 840, 1 },
        /*280*/ { 841, 0 },
        /*281*/ { 857, 0 },
        /*282*/ { 858, 1 },
        /*283*/ { 859, 0 },
        /*284*/ { 860, 1 },
        /*285*/ { 861, 0 },
        /*286*/ { 870, 0 },
        /*287*/ { 880, 0 },
        /*288*/ { 881, 0 },
        /*289*/ { 882, 1 },
        /*290*/ { 883, 0 },
        /*291*/ { 884, 0 },
        /*292*/ { 885, 0 },
        /*293*/ { 886, 1 },
        /*294*/ { 887, 0 },
        /*295*/ { 888, 0 },
        /*296*/ { 889, 0 },
        /*297*/ { 890, 0 },
        /*298*/ { 891, 0 },
        /*299*/ { 892, 0 },
        /*300*/ { 893, 0 },
        /*301*/ { 894, 0 },
        /*302*/ { 895, 0 },
        /*303*/ { 896, 0 },
        /*304*/ { 897, 0 },
        /*305*/ { 898, 0 },
        /*306*/ { 899, 0 },
        /*307*/ { 900, 0 },
        /*308*/ { 901, 1 },
        /*309*/ { 902, 0 },
        /*310*/ { 926, 0 },
        /*311*/ { 927, 1 },
        /*312*/ { 928, 1 },
        /*313*/ { 929, 1 },
        /*314*/ { 930, 1 },
        /*315*/ { 931, 1 },
        /*316*/ { 932, 1 },
        /*317*/ { 933, 1 },
        /*318*/ { 934, 1 },
        /*319*/ { 935, 0 },
        /*320*/ { 936, 1 },
        /*321*/ { 937, 0 },
        /*322*/ { 938, 1 },
        /*323*/ { 939, 0 },
        /*324*/ { 940, 1 },
        /*325*/ { 941, 1 },
        /*326*/ { 942, 0 },
        /*327*/ { 943, 1 },
        /*328*/ { 944, 1 },
        /*329*/ { 945, 0 },
        /*330*/ { 946, 1 },
        /*331*/ { 947, 1 },
        /*332*/ { 948, 1 },
        /*333*/ { 949, 1 },
        /*334*/ { 950, 1 },
        /*335*/ { 951, 1 },
        /*336*/ { 952, 1 },
        /*337*/ { 953, 1 },
        /*338*/ { 954, 0 },
        /*339*/ { 955, 1 },
        /*340*/ { 956, 1 },
        /*341*/ { 957, 1 },
        /*342*/ { 958, 1 },
        /*343*/ { 959, 1 },
        /*344*/ { 960, 1 },
        /*345*/ { 961, 1 },
        /*346*/ { 962, 1 },
        /*347*/ { 963, 1 },
        /*348*/ { 964, 1 },
        /*349*/ { 965, 1 },
        /*350*/ { 966, 0 },
        /*351*/ { 967, 1 },
        /*352*/ { 968, 1 },
        /*353*/ { 969, 1 },
        /*354*/ { 970, 1 },
        /*355*/ { 971, 1 },
        /*356*/ { 972, 1 },
        /*357*/ { 973, 1 },
        /*358*/ { 974, 0 },
        /*359*/ { 975, 1 },
        /*360*/ { 976, 1 },
        /*361*/ { 977, 1 },
        /*362*/ { 978, 1 },
        /*363*/ { 979, 1 },
        /*364*/ { 980, 1 },
        /*365*/ { 981, 1 },
        /*366*/ { 982, 0 },
        /*367*/ { 983, 0 },
        /*368*/ { 984, 1 },
        /*369*/ { 985, 1 },
        /*370*/ { 986, 1 },
        /*371*/ { 987, 0 },
        /*372*/ { 988, 0 },
        /*373*/ { 989, 0 },
        /*374*/ { 990, 1 },
        /*375*/ { 991, 0 },
        /*376*/ { 992, 0 },
        /*377*/ { 993, 0 },
        /*378*/ { 994, 1 },
        /*379*/ { 995, 0 },
        /*380*/ { 996, 0 },
        /*381*/ { 997, 1 },
        /*382*/ { 998, 0 },
        /*383*/ { 999, 1 },
        /*384*/ { 1000, 0 },
        /*385*/ { 2000, 0 },
    };
    int data_size = ARRAY_SIZE(data);
    int i, ret;

    testStart("test_numeric");

    for (i = 0; i < data_size; i++) {

        if (index != -1 && i != index) continue;

        ret = iso4217_numeric(data[i].data);
        assert_equal(ret, data[i].ret, "i:%d ret %d != %d\n", i, ret, data[i].ret);
    }

    testFinish();
}

/* Binary chop version: Whether ISO 4217 numeric */
static int bc_iso4217_numeric(int cc) {
    static const short codes[179] = {
        /*ALL*/   8, /*DZD*/  12, /*ARS*/  32, /*AUD*/  36, /*BSD*/  44, /*BHD*/  48, /*BDT*/  50, /*AMD*/  51, /*BBD*/  52, /*BMD*/  60,
        /*BTN*/  64, /*BOB*/  68, /*BWP*/  72, /*BZD*/  84, /*SBD*/  90, /*BND*/  96, /*MMK*/ 104, /*BIF*/ 108, /*KHR*/ 116, /*CAD*/ 124,
        /*CVE*/ 132, /*KYD*/ 136, /*LKR*/ 144, /*CLP*/ 152, /*CNY*/ 156, /*COP*/ 170, /*KMF*/ 174, /*CRC*/ 188, /*HRK*/ 191, /*CUP*/ 192,
        /*CZK*/ 203, /*DKK*/ 208, /*DOP*/ 214, /*SVC*/ 222, /*ETB*/ 230, /*ERN*/ 232, /*FKP*/ 238, /*FJD*/ 242, /*DJF*/ 262, /*GMD*/ 270,
        /*GIP*/ 292, /*GTQ*/ 320, /*GNF*/ 324, /*GYD*/ 328, /*HTG*/ 332, /*HNL*/ 340, /*HKD*/ 344, /*HUF*/ 348, /*ISK*/ 352, /*INR*/ 356,
        /*IDR*/ 360, /*IRR*/ 364, /*IQD*/ 368, /*ILS*/ 376, /*JMD*/ 388, /*JPY*/ 392, /*KZT*/ 398, /*JOD*/ 400, /*KES*/ 404, /*KPW*/ 408,
        /*KRW*/ 410, /*KWD*/ 414, /*KGS*/ 417, /*LAK*/ 418, /*LBP*/ 422, /*LSL*/ 426, /*LRD*/ 430, /*LYD*/ 434, /*MOP*/ 446, /*MWK*/ 454,
        /*MYR*/ 458, /*MVR*/ 462, /*MUR*/ 480, /*MXN*/ 484, /*MNT*/ 496, /*MDL*/ 498, /*MAD*/ 504, /*OMR*/ 512, /*NAD*/ 516, /*NPR*/ 524,
        /*ANG*/ 532, /*AWG*/ 533, /*VUV*/ 548, /*NZD*/ 554, /*NIO*/ 558, /*NGN*/ 566, /*NOK*/ 578, /*PKR*/ 586, /*PAB*/ 590, /*PGK*/ 598,
        /*PYG*/ 600, /*PEN*/ 604, /*PHP*/ 608, /*QAR*/ 634, /*RUB*/ 643, /*RWF*/ 646, /*SHP*/ 654, /*SAR*/ 682, /*SCR*/ 690, /*SLL*/ 694,
        /*SGD*/ 702, /*VND*/ 704, /*SOS*/ 706, /*ZAR*/ 710, /*SSP*/ 728, /*SZL*/ 748, /*SEK*/ 752, /*CHF*/ 756, /*SYP*/ 760, /*THB*/ 764,
        /*TOP*/ 776, /*TTD*/ 780, /*AED*/ 784, /*TND*/ 788, /*UGX*/ 800, /*MKD*/ 807, /*EGP*/ 818, /*GBP*/ 826, /*TZS*/ 834, /*USD*/ 840,
        /*UYU*/ 858, /*UZS*/ 860, /*WST*/ 882, /*YER*/ 886, /*TWD*/ 901, /*UYW*/ 927, /*VES*/ 928, /*MRU*/ 929, /*STN*/ 930, /*CUC*/ 931,
        /*ZWL*/ 932, /*BYN*/ 933, /*TMT*/ 934, /*GHS*/ 936, /*SDG*/ 938, /*UYI*/ 940, /*RSD*/ 941, /*MZN*/ 943, /*AZN*/ 944, /*RON*/ 946,
        /*CHE*/ 947, /*CHW*/ 948, /*TRY*/ 949, /*XAF*/ 950, /*XCD*/ 951, /*XOF*/ 952, /*XPF*/ 953, /*XBA*/ 955, /*XBB*/ 956, /*XBC*/ 957,
        /*XBD*/ 958, /*XAU*/ 959, /*XDR*/ 960, /*XAG*/ 961, /*XPT*/ 962, /*XTS*/ 963, /*XPD*/ 964, /*XUA*/ 965, /*ZMW*/ 967, /*SRD*/ 968,
        /*MGA*/ 969, /*COU*/ 970, /*AFN*/ 971, /*TJS*/ 972, /*AOA*/ 973, /*BGN*/ 975, /*CDF*/ 976, /*BAM*/ 977, /*EUR*/ 978, /*MXV*/ 979,
        /*UAH*/ 980, /*GEL*/ 981, /*BOV*/ 984, /*PLN*/ 985, /*BRL*/ 986, /*CLF*/ 990, /*XSU*/ 994, /*USN*/ 997, /*XXX*/ 999,
    };

    int s = 0, e = ARRAY_SIZE(codes) - 1;

    while (s <= e) {
        int m = (s + e) / 2;
        if (codes[m] < cc) {
            s = m + 1;
        } else if (codes[m] > cc) {
            e = m - 1;
        } else {
            return 1;
        }
    }

    return 0;
}

static void test_numeric_bc(void) {

    int i, ret, bc_ret;

    testStart("test_numeric_bc");

    for (i = 0; i < 1001; i++) {
        ret = iso4217_numeric(i);
        bc_ret = bc_iso4217_numeric(i);
        assert_equal(ret, bc_ret, "i:%d ret %d != bc_ret %d\n", i, ret, bc_ret);
    }

    testFinish();
}

int main(int argc, char *argv[]) {

    testFunction funcs[] = { /* name, func, has_index, has_generate, has_debug */
        { "test_numeric", test_numeric, 1, 0, 0 },
        { "test_numeric_bc", test_numeric_bc, 0, 0, 0 },
    };

    testRun(argc, argv, funcs, ARRAY_SIZE(funcs));

    testReport();

    return 0;
}