// Width-related constants
/*
`define INST_WIDTH     32
`define REG_ADDR_WIDTH  5
`define XPR_LEN        32
`define DOUBLE_XPR_LEN 64
`define LOG2_XPR_LEN    5
`define SHAMT_WIDTH     5
*/

#define RV_NOP 0x13

// Opcodes

#define RV32_LOAD     0x03
#define RV32_STORE    0x23
#define RV32_MADD     0x43
#define RV32_BRANCH   0x63

#define RV32_LOAD_FP  0x07
#define RV32_STORE_FP 0x27
#define RV32_MSUB     0x47
#define RV32_JALR     0x67

#define RV32_CUSTOM_0 0x0b
#define RV32_CUSTOM_1 0x2b
#define RV32_NMSUB    0x4b
// 0x6b is reserved

#define RV32_MISC_MEM 0x0f
#define RV32_AMO      0x2f
#define RV32_NMADD    0x4f
#define RV32_JAL      0x6f

#define RV32_OP_IMM   0x13
#define RV32_OP       0x33
#define RV32_OP_FP    0x53
#define RV32_SYSTEM   0x73

#define RV32_AUIPC    0x17
#define RV32_LUI      0x37
// 7'b1010111 is reserved
// 7'b1110111 is reserved

// 7'b0011011 is RV64-specific
// 7'b0111011 is RV64-specific
/*
#define RV32_CUSTOM_2 7'b1011011
#define RV32_CUSTOM_3 7'b1111011
*/

// Arithmetic FUNCT3 encodings

#define RV32_FUNCT3_ADD_SUB 0
#define RV32_FUNCT3_SLL     1
#define RV32_FUNCT3_SLT     2
#define RV32_FUNCT3_SLTU    3
#define RV32_FUNCT3_XOR     4
#define RV32_FUNCT3_SRA_SRL 5
#define RV32_FUNCT3_OR      6
#define RV32_FUNCT3_AND     7

// Branch FUNCT3 encodings

#define RV32_FUNCT3_BEQ  0
#define RV32_FUNCT3_BNE  1
#define RV32_FUNCT3_BLT  4
#define RV32_FUNCT3_BGE  5
#define RV32_FUNCT3_BLTU 6
#define RV32_FUNCT3_BGEU 7

// MISC-MEM FUNCT3 encodings
#define RV32_FUNCT3_FENCE   0
#define RV32_FUNCT3_FENCE_I 1

// SYSTEM FUNCT3 encodings

#define RV32_FUNCT3_PRIV   0
#define RV32_FUNCT3_CSRRW  1
#define RV32_FUNCT3_CSRRS  2
#define RV32_FUNCT3_CSRRC  3
#define RV32_FUNCT3_CSRRWI 5
#define RV32_FUNCT3_CSRRSI 6
#define RV32_FUNCT3_CSRRCI 7

// PRIV FUNCT12 encodings
/*
#define RV32_FUNCT12_ECALL  12'b000000000000
#define RV32_FUNCT12_EBREAK 12'b000000000001
#define RV32_FUNCT12_ERET   12'b000100000000
#define RV32_FUNCT12_WFI    12'b000100000010
*/

// RV32M encodings
#define RV32_FUNCT7_MUL_DIV 1

#define RV32_FUNCT3_MUL    0
#define RV32_FUNCT3_MULH   1
#define RV32_FUNCT3_MULHSU 2
#define RV32_FUNCT3_MULHU  3
#define RV32_FUNCT3_DIV    4
#define RV32_FUNCT3_DIVU   5
#define RV32_FUNCT3_REM    6
#define RV32_FUNCT3_REMU   7
