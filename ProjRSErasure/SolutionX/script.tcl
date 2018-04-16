############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project ProjRSErasure
set_top rs_erasure
add_files src/rs_erasure.c
add_files -tb tv/tv_rs_erasure_mout.txt
add_files -tb tv/tv_rs_erasure_in.txt
add_files -tb tb/tb_rs_erasure.c
open_solution "SolutionX"
set_part {xc7a35tcpg236-1}
create_clock -period 3.3 -name default
set_clock_uncertainty 0.3ns
source "./ProjRSErasure/SolutionX/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog -display_name "ReedSolomonCodecHLS"
