SHELL = /bin/bash

include Makefrag

V_SRC_DIR = src/main/verilog

V_TEST_DIR = src/test/verilog

SIM_DIR = sim

MEM_DIR = src/test/inputs

OUT_DIR = output

IVERILOG = iverilog

IVERILOG_OPTS = -Wall -g 2001  -c iverilog_cmd

MAX_CYCLES = 1000000

SIMV_OPTS = -k $(OUT_DIR)/ucli.key -q

DESIGN_SRCS = $(addprefix $(V_SRC_DIR)/, \
vscale_core.v \
vscale_hasti_bridge.v \
vscale_pipeline.v \
vscale_ctrl.v \
vscale_regfile.v \
vscale_src_a_mux.v \
vscale_src_b_mux.v \
vscale_imm_gen.v \
vscale_alu.v \
vscale_mul_div.v \
vscale_csr_file.v \
vscale_PC_mux.v \
)

SIM_SRCS = $(addprefix $(V_TEST_DIR)/, \
vscale_sim_top.v \
vscale_dp_hasti_sram.v \
)

IVERILOG_TOP = $(V_TEST_DIR)/vscale_hex_tb.v

HDRS = $(addprefix $(V_SRC_DIR)/, \
vscale_ctrl_constants.vh \
rv32_opcodes.vh \
vscale_alu_ops.vh \
vscale_md_constants.vh \
vscale_hasti_constants.vh \
vscale_csr_addr_map.vh \
)

TEST_VPD_FILES = $(addprefix $(OUT_DIR)/,$(addsuffix .vpd,$(RV32_TESTS)))

default: $(SIM_DIR)/simv

run-asm-tests: $(TEST_VPD_FILES)

$(OUT_DIR)/%.vpd: $(MEM_DIR)/%.hex $(SIM_DIR)/simv
	mkdir -p output
	$(SIM_DIR)/simv $(SIMV_OPTS) +max-cycles=$(MAX_CYCLES) +loadmem=$< +vpdfile=$@ && [ $$PIPESTATUS -eq 0 ]

$(SIM_DIR)/simv: $(IVERILOG_TOP) $(SIM_SRCS) $(DESIGN_SRCS) $(HDRS)
	mkdir -p sim
	$(IVERILOG) $(IVERILOG_OPTS) -o $@ -s vscale_hex_tb $(IVERILOG_TOP) $(SIM_SRCS) $(DESIGN_SRCS)

clean:
	rm -rf $(SIM_DIR)/* $(OUT_DIR)/*

.PHONY: clean run-asm-tests
