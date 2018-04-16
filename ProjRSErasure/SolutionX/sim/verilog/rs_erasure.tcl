
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set c_group [add_wave_group c(wire) -into $coutputgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_3_ap_vld -into $c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_3 -into $c_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_2_ap_vld -into $c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_2 -into $c_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_1_ap_vld -into $c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_1 -into $c_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_0_ap_vld -into $c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/c_0 -into $c_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set survival_pattern_group [add_wave_group survival_pattern(wire) -into $cinputgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/survival_pattern -into $survival_pattern_group -radix hex
set d_group [add_wave_group d(wire) -into $cinputgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_11 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_10 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_9 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_8 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_7 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_6 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_5 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_4 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_3 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_2 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_1 -into $d_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/d_0 -into $d_group -radix hex
set codeidx_group [add_wave_group codeidx(wire) -into $cinputgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/codeidx -into $codeidx_group -radix hex
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/codeidx_ap_vld -into $codeidx_group -color #ffff00 -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_start -into $blocksiggroup
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_done -into $blocksiggroup
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_idle -into $blocksiggroup
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_rs_erasure_top/AESL_inst_rs_erasure/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_rs_erasure_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_rs_erasure_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_rs_erasure_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_c_0 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_c_1 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_c_2 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_c_3 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_0 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_1 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_2 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_3 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_4 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_5 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_6 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_7 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_8 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_9 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_10 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_d_11 -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_survival_pattern -into $tb_portdepth_group -radix hex
add_wave /apatb_rs_erasure_top/LENGTH_codeidx -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_c_group [add_wave_group c(wire) -into $tbcoutputgroup]
add_wave /apatb_rs_erasure_top/c_3_ap_vld -into $tb_c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/c_3 -into $tb_c_group -radix hex
add_wave /apatb_rs_erasure_top/c_2_ap_vld -into $tb_c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/c_2 -into $tb_c_group -radix hex
add_wave /apatb_rs_erasure_top/c_1_ap_vld -into $tb_c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/c_1 -into $tb_c_group -radix hex
add_wave /apatb_rs_erasure_top/c_0_ap_vld -into $tb_c_group -color #ffff00 -radix hex
add_wave /apatb_rs_erasure_top/c_0 -into $tb_c_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_survival_pattern_group [add_wave_group survival_pattern(wire) -into $tbcinputgroup]
add_wave /apatb_rs_erasure_top/survival_pattern -into $tb_survival_pattern_group -radix hex
set tb_d_group [add_wave_group d(wire) -into $tbcinputgroup]
add_wave /apatb_rs_erasure_top/d_11 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_10 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_9 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_8 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_7 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_6 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_5 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_4 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_3 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_2 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_1 -into $tb_d_group -radix hex
add_wave /apatb_rs_erasure_top/d_0 -into $tb_d_group -radix hex
set tb_codeidx_group [add_wave_group codeidx(wire) -into $tbcinputgroup]
add_wave /apatb_rs_erasure_top/codeidx -into $tb_codeidx_group -radix hex
add_wave /apatb_rs_erasure_top/codeidx_ap_vld -into $tb_codeidx_group -color #ffff00 -radix hex
save_wave_config rs_erasure.wcfg
run all
quit

