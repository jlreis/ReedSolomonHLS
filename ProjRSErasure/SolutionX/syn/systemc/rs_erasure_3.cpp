#include "rs_erasure.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void rs_erasure::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"codeidx_ap_vld\" :  \"" << codeidx_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_0\" :  \"" << c_0.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_0_ap_vld\" :  \"" << c_0_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_1\" :  \"" << c_1.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_1_ap_vld\" :  \"" << c_1_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_2\" :  \"" << c_2.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_2_ap_vld\" :  \"" << c_2_ap_vld.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_3\" :  \"" << c_3.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"c_3_ap_vld\" :  \"" << c_3_ap_vld.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_0\" :  \"" << d_0.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_1\" :  \"" << d_1.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_2\" :  \"" << d_2.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_3\" :  \"" << d_3.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_4\" :  \"" << d_4.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_5\" :  \"" << d_5.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_6\" :  \"" << d_6.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_7\" :  \"" << d_7.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_8\" :  \"" << d_8.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_9\" :  \"" << d_9.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_10\" :  \"" << d_10.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"d_11\" :  \"" << d_11.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"survival_pattern\" :  \"" << survival_pattern.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"codeidx\" :  \"" << codeidx.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

