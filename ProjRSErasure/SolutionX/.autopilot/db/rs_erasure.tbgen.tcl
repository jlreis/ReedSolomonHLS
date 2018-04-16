set C_TypeInfoList {{ 
"rs_erasure" : [[], { "return": [[], "void"]} , [{"ExternC" : 0}], [ {"c": [[], {"array": [ {"scalar": "unsigned char"}, [4]]}] }, {"d": [[], {"array": [ {"scalar": "unsigned char"}, [12]]}] }, {"survival_pattern": [[], {"scalar": "unsigned short"}] }, {"codeidx": [[], {"scalar": "unsigned char"}] }],[],""]
}}
set moduleName rs_erasure
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type function
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set C_modelName {rs_erasure}
set C_modelType { void 0 }
set C_modelArgList {
	{ c_0 int 8 regular {pointer 1}  }
	{ c_1 int 8 regular {pointer 1}  }
	{ c_2 int 8 regular {pointer 1}  }
	{ c_3 int 8 regular {pointer 1}  }
	{ d_0 int 8 regular {pointer 0}  }
	{ d_1 int 8 regular {pointer 0}  }
	{ d_2 int 8 regular {pointer 0}  }
	{ d_3 int 8 regular {pointer 0}  }
	{ d_4 int 8 regular {pointer 0}  }
	{ d_5 int 8 regular {pointer 0}  }
	{ d_6 int 8 regular {pointer 0}  }
	{ d_7 int 8 regular {pointer 0}  }
	{ d_8 int 8 regular {pointer 0}  }
	{ d_9 int 8 regular {pointer 0}  }
	{ d_10 int 8 regular {pointer 0}  }
	{ d_11 int 8 regular {pointer 0}  }
	{ survival_pattern uint 16 regular  }
	{ codeidx uint 8 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "c_0", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "c","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "c_1", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "c","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "c_2", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "c","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "c_3", "interface" : "wire", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "c","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "d_0", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "d_1", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "d_2", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "d_3", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "d_4", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "d_5", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "d_6", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "d_7", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "d_8", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 8,"up" : 8,"step" : 2}]}]}]} , 
 	{ "Name" : "d_9", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 9,"up" : 9,"step" : 2}]}]}]} , 
 	{ "Name" : "d_10", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 10,"up" : 10,"step" : 2}]}]}]} , 
 	{ "Name" : "d_11", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "d","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 11,"up" : 11,"step" : 2}]}]}]} , 
 	{ "Name" : "survival_pattern", "interface" : "wire", "bitwidth" : 16, "direction" : "READONLY", "bitSlice":[{"low":0,"up":15,"cElement": [{"cName": "survival_pattern","cData": "unsigned short","bit_use": { "low": 0,"up": 15},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "codeidx", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "codeidx","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 29
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ codeidx_ap_vld sc_in sc_logic 1 invld 17 } 
	{ c_0 sc_out sc_lv 8 signal 0 } 
	{ c_0_ap_vld sc_out sc_logic 1 outvld 0 } 
	{ c_1 sc_out sc_lv 8 signal 1 } 
	{ c_1_ap_vld sc_out sc_logic 1 outvld 1 } 
	{ c_2 sc_out sc_lv 8 signal 2 } 
	{ c_2_ap_vld sc_out sc_logic 1 outvld 2 } 
	{ c_3 sc_out sc_lv 8 signal 3 } 
	{ c_3_ap_vld sc_out sc_logic 1 outvld 3 } 
	{ d_0 sc_in sc_lv 8 signal 4 } 
	{ d_1 sc_in sc_lv 8 signal 5 } 
	{ d_2 sc_in sc_lv 8 signal 6 } 
	{ d_3 sc_in sc_lv 8 signal 7 } 
	{ d_4 sc_in sc_lv 8 signal 8 } 
	{ d_5 sc_in sc_lv 8 signal 9 } 
	{ d_6 sc_in sc_lv 8 signal 10 } 
	{ d_7 sc_in sc_lv 8 signal 11 } 
	{ d_8 sc_in sc_lv 8 signal 12 } 
	{ d_9 sc_in sc_lv 8 signal 13 } 
	{ d_10 sc_in sc_lv 8 signal 14 } 
	{ d_11 sc_in sc_lv 8 signal 15 } 
	{ survival_pattern sc_in sc_lv 16 signal 16 } 
	{ codeidx sc_in sc_lv 8 signal 17 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "codeidx_ap_vld", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "codeidx", "role": "ap_vld" }} , 
 	{ "name": "c_0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c_0", "role": "default" }} , 
 	{ "name": "c_0_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "c_0", "role": "ap_vld" }} , 
 	{ "name": "c_1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c_1", "role": "default" }} , 
 	{ "name": "c_1_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "c_1", "role": "ap_vld" }} , 
 	{ "name": "c_2", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c_2", "role": "default" }} , 
 	{ "name": "c_2_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "c_2", "role": "ap_vld" }} , 
 	{ "name": "c_3", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "c_3", "role": "default" }} , 
 	{ "name": "c_3_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "c_3", "role": "ap_vld" }} , 
 	{ "name": "d_0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_0", "role": "default" }} , 
 	{ "name": "d_1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_1", "role": "default" }} , 
 	{ "name": "d_2", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_2", "role": "default" }} , 
 	{ "name": "d_3", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_3", "role": "default" }} , 
 	{ "name": "d_4", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_4", "role": "default" }} , 
 	{ "name": "d_5", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_5", "role": "default" }} , 
 	{ "name": "d_6", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_6", "role": "default" }} , 
 	{ "name": "d_7", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_7", "role": "default" }} , 
 	{ "name": "d_8", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_8", "role": "default" }} , 
 	{ "name": "d_9", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_9", "role": "default" }} , 
 	{ "name": "d_10", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_10", "role": "default" }} , 
 	{ "name": "d_11", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "d_11", "role": "default" }} , 
 	{ "name": "survival_pattern", "direction": "in", "datatype": "sc_lv", "bitwidth":16, "type": "signal", "bundle":{"name": "survival_pattern", "role": "default" }} , 
 	{ "name": "codeidx", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "codeidx", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50"],
		"CDFG" : "rs_erasure",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "Aligned", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "42", "EstimateLatencyMin" : "42", "EstimateLatencyMax" : "42",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"InDataflowNetwork" : "0",
		"Port" : [
			{"Name" : "c_0", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "c_1", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "c_2", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "c_3", "Type" : "Vld", "Direction" : "O"},
			{"Name" : "d_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_3", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_4", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_5", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_6", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_7", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_8", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_9", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_10", "Type" : "None", "Direction" : "I"},
			{"Name" : "d_11", "Type" : "None", "Direction" : "I"},
			{"Name" : "survival_pattern", "Type" : "None", "Direction" : "I"},
			{"Name" : "codeidx", "Type" : "Vld", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "codeidx_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "F_tbl", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_26", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_27", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_28", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_30", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_31", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_32", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_33", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_34", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_35", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_36", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_37", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_38", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_39", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_40", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_41", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_42", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_43", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_44", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_45", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_46", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "DECMAT_ROM_47", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.F_tbl_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_0_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_1_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_2_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_3_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_4_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_5_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_6_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_7_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_8_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_9_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_10_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_11_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_12_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_13_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_14_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_15_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_16_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_17_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_18_U", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_19_U", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_20_U", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_21_U", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_22_U", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_23_U", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_24_U", "Parent" : "0"},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_25_U", "Parent" : "0"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_26_U", "Parent" : "0"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_27_U", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_28_U", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_29_U", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_30_U", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_31_U", "Parent" : "0"},
	{"ID" : "34", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_32_U", "Parent" : "0"},
	{"ID" : "35", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_33_U", "Parent" : "0"},
	{"ID" : "36", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_34_U", "Parent" : "0"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_35_U", "Parent" : "0"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_36_U", "Parent" : "0"},
	{"ID" : "39", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_37_U", "Parent" : "0"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_38_U", "Parent" : "0"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_39_U", "Parent" : "0"},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_40_U", "Parent" : "0"},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_41_U", "Parent" : "0"},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_42_U", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_43_U", "Parent" : "0"},
	{"ID" : "46", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_44_U", "Parent" : "0"},
	{"ID" : "47", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_45_U", "Parent" : "0"},
	{"ID" : "48", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_46_U", "Parent" : "0"},
	{"ID" : "49", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.DECMAT_ROM_47_U", "Parent" : "0"},
	{"ID" : "50", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rs_erasure_mux_42Xh4_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	rs_erasure {
		c_0 {Type O LastRead -1 FirstWrite 42}
		c_1 {Type O LastRead -1 FirstWrite 42}
		c_2 {Type O LastRead -1 FirstWrite 42}
		c_3 {Type O LastRead -1 FirstWrite 42}
		d_0 {Type I LastRead 0 FirstWrite -1}
		d_1 {Type I LastRead 0 FirstWrite -1}
		d_2 {Type I LastRead 0 FirstWrite -1}
		d_3 {Type I LastRead 0 FirstWrite -1}
		d_4 {Type I LastRead 0 FirstWrite -1}
		d_5 {Type I LastRead 0 FirstWrite -1}
		d_6 {Type I LastRead 0 FirstWrite -1}
		d_7 {Type I LastRead 0 FirstWrite -1}
		d_8 {Type I LastRead 0 FirstWrite -1}
		d_9 {Type I LastRead 0 FirstWrite -1}
		d_10 {Type I LastRead 0 FirstWrite -1}
		d_11 {Type I LastRead 0 FirstWrite -1}
		survival_pattern {Type I LastRead 0 FirstWrite -1}
		codeidx {Type I LastRead 0 FirstWrite -1}
		F_tbl {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_0 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_1 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_2 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_3 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_4 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_5 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_6 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_7 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_8 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_9 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_10 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_11 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_12 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_13 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_14 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_15 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_16 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_17 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_18 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_19 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_20 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_21 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_22 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_23 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_24 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_25 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_26 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_27 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_28 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_29 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_30 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_31 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_32 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_33 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_34 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_35 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_36 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_37 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_38 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_39 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_40 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_41 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_42 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_43 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_44 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_45 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_46 {Type I LastRead -1 FirstWrite -1}
		DECMAT_ROM_47 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "42", "Max" : "42"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	c_0 { ap_vld {  { c_0 out_data 1 8 }  { c_0_ap_vld out_vld 1 1 } } }
	c_1 { ap_vld {  { c_1 out_data 1 8 }  { c_1_ap_vld out_vld 1 1 } } }
	c_2 { ap_vld {  { c_2 out_data 1 8 }  { c_2_ap_vld out_vld 1 1 } } }
	c_3 { ap_vld {  { c_3 out_data 1 8 }  { c_3_ap_vld out_vld 1 1 } } }
	d_0 { ap_none {  { d_0 in_data 0 8 } } }
	d_1 { ap_none {  { d_1 in_data 0 8 } } }
	d_2 { ap_none {  { d_2 in_data 0 8 } } }
	d_3 { ap_none {  { d_3 in_data 0 8 } } }
	d_4 { ap_none {  { d_4 in_data 0 8 } } }
	d_5 { ap_none {  { d_5 in_data 0 8 } } }
	d_6 { ap_none {  { d_6 in_data 0 8 } } }
	d_7 { ap_none {  { d_7 in_data 0 8 } } }
	d_8 { ap_none {  { d_8 in_data 0 8 } } }
	d_9 { ap_none {  { d_9 in_data 0 8 } } }
	d_10 { ap_none {  { d_10 in_data 0 8 } } }
	d_11 { ap_none {  { d_11 in_data 0 8 } } }
	survival_pattern { ap_none {  { survival_pattern in_data 0 16 } } }
	codeidx { ap_vld {  { codeidx_ap_vld in_vld 0 1 }  { codeidx in_data 0 8 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
