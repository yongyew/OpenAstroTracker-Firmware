#pragma once

// include currently configured board 
#if BOARD == BOARD_AVR_MEGA2560
    #include "board/mega2560/board.h"
#elif BOARD == BOARD_AVR_MKS_GEN_L_V21
    #include "board/mks_gen_l_v2.1/board.h"
#else
    #error Unsupported AVR board
#endif

#include "stdint.h"

#define IS_SRX_PIN(p) (p >= 10 && p <= 15) || (p >= 50 && p <= 53) || (p >= 62 && p <= 69)
#define IS_STX_PIN(p) (p >= 2 && p <= 13) || (p >= 20 && p <= 69)