############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_array_partition -type complete -dim 1 "rs_erasure" c
set_directive_array_partition -type complete -dim 1 "rs_erasure" d
set_directive_interface -mode ap_none "rs_erasure" d
set_directive_interface -mode ap_vld "rs_erasure" codeidx
set_directive_pipeline -II 1 "rs_erasure"
