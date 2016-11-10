#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "rv32_opcodes.h"

#define OPCODE(i) ((i) & 0x0000007fU)
#define FUNCT3(i) ((i) & 0x00007000U)
#define RS1(i)    ((i) & 0x000f1000U)
#define RS2(i)    ((i) & 0x01f00000U)

#define MEM_TYPE_SB 0
#define MEM_TYPE_SH 1
#define MEM_TYPE_SW 2
#define MEM_TYPE_SD 3

#define WORDLEN 8

void ppc_dasm_one(char *buf, uint32_t hx);

int main(void)
{
#if(1)
    while (!feof(stdin))
    {
        char buf[WORDLEN + 1]  = { 0 },
             buf2[WORDLEN + 1] = { 0 };
        memset(buf, 0, sizeof(buf));
        fgets(buf, WORDLEN + 1, stdin);

        if (strlen(buf) == 8) {
            uint32_t hx;
            sscanf(buf, "%x", &hx);
            ppc_dasm_one(buf2, hx);
            //printf("%s\n", buf2);
            fflush(stdout);
        }
    }
#else
    ppc_dasm_one(NULL, 0xf1002573);
    ppc_dasm_one(NULL, 0x00051063);
    ppc_dasm_one(NULL, 0x00055863);
    ppc_dasm_one(NULL, 0x0ff0000f);
    ppc_dasm_one(NULL, 0x00000297);
#endif

    return 0;
}

void ppc_dasm_one(char *buf, uint32_t instr)
{
    uint8_t opcode = OPCODE(instr);
    uint8_t funct3 = FUNCT3(instr);

    switch (opcode) {
        case RV32_LOAD:
            printf("LOAD\n");
            break;
        case RV32_STORE:
        {
            uint8_t src = RS2(instr);
            uint8_t width = funct3;
            switch (width) {
                case MEM_TYPE_SB:
                    printf("sb x%d,\n", src);
                    break;
                case MEM_TYPE_SH:
                    printf("sh x%d,\n", src);
                    break;
                case MEM_TYPE_SW:
                    printf("sw x%d,\n", src);
                    break;
                case MEM_TYPE_SD:
                    printf("sd x%d,\n", src);
                    break;
                default:
                    puts("UNKNOWN");
            }
            break;
        }
        case RV32_MADD:
            puts("MADD");
            break;
        case RV32_BRANCH:
        {
            uint8_t src1 = RS1(instr);
            uint8_t src2 = RS2(instr);
            switch (funct3) {
                case RV32_FUNCT3_BEQ:
                    printf("beq x%d, x%d,\n", src1, src2);
                    break;
                case RV32_FUNCT3_BNE:
                    printf("bne x%d, x%d,\n", src1, src2);
                    break;
                case RV32_FUNCT3_BLT:
                    printf("blt x%d, x%d,\n", src1, src2);
                    break;
                case RV32_FUNCT3_BGE:
                    printf("bge x%d, x%d,\n", src1, src2);
                    break;
                case RV32_FUNCT3_BLTU:
                    printf("bltu x%d, x%d,\n", src1, src2);
                    break;
                case RV32_FUNCT3_BGEU:
                    printf("bgeu x%d, x%d,\n", src1, src2);
                    break;
                default:
                    puts("UNKNOWN");
            }
            break;
        }
        case RV32_LOAD_FP:
            puts("LOAD_FP");
            break;
        case RV32_STORE_FP:
            puts("STORE_FP");
            break;
        case RV32_MSUB:
            puts("MSUB");
            break;
        case RV32_JALR:
            puts("JALR");
            break;
        case RV32_CUSTOM_0:
            puts("CUSTOM_0");
            break;
        case RV32_CUSTOM_1:
            puts("CUSTOM_1");
            break;
        case RV32_NMSUB:
            puts("NMSUB");
            break;
        case RV32_MISC_MEM:
            printf("MISC_MEM:");
            switch (funct3) {
                case RV32_FUNCT3_FENCE:
                    puts("FENCE");
                    break;
                case RV32_FUNCT3_FENCE_I:
                    puts("FENCE_I");
                    break;
                default:
                    puts("UNKNOWN");
            }
            break;
        case RV32_AMO:
            puts("AMO");
            break;
        case RV32_NMADD:
            puts("NMADD");
            break;
        case RV32_JAL:
            puts("JAL");
            break;
        case RV32_OP_IMM:
            puts("OP_IMM");
            break;
        case RV32_OP:
            printf("OP:");
            switch (funct3) {
                case RV32_FUNCT3_ADD_SUB:
                    puts("ADD_SUB");
                    break;
                case RV32_FUNCT3_SLL:
                    puts("SLL");
                    break;
                case RV32_FUNCT3_SLT:
                    puts("SLT");
                    break;
                case RV32_FUNCT3_SLTU:
                    puts("SLTU");
                    break;
                case RV32_FUNCT3_XOR:
                    puts("XOR");
                    break;
                case RV32_FUNCT3_SRA_SRL:
                    puts("SRA_SRL");
                    break;
                case RV32_FUNCT3_OR:
                    puts("OR");
                    break;
                case RV32_FUNCT3_AND:
                    puts("AND");
                    break;
                default:
                    puts("UNKNOWN");
            }
            break;
        case RV32_OP_FP:
            puts("OP_FP");
            break;
        case RV32_SYSTEM:
            printf("SYSTEM:");
            switch (funct3) {
                case RV32_FUNCT3_PRIV:
                    puts("PRIV");
                    break;
                case RV32_FUNCT3_CSRRW:
                    puts("CSRRW");
                    break;
                case RV32_FUNCT3_CSRRS:
                    puts("CSRRS");
                    break;
                case RV32_FUNCT3_CSRRC:
                    puts("CSRRC");
                    break;
                case RV32_FUNCT3_CSRRWI:
                    puts("CSRRWI");
                    break;
                case RV32_FUNCT3_CSRRSI:
                    puts("CSRRSI");
                    break;
                case RV32_FUNCT3_CSRRCI:
                    puts("CSRRCI");
                    break;
                default:
                    puts("UNKNOWN");
            }
            break;
        case RV32_AUIPC:
            puts("AUIPC");
            break;
        case RV32_LUI:
            puts("LUI");
            break;
        default:
            puts("UNKNOWN");
    }

}
