#include "iptc_examples.h"

// 这个例子介绍如何为图片增加一些 iptc 信息，如果已存在 iptc 信息，也可以进行修改
// 我们主要通过几个属性的变动来进行，ObjectName，Keywords，City 和 OriginatingProgram
void qn_set_jpeg_iptc_info(const char *jpeg_srcfile_path, const char *jpeg_destfile_path) {
    IptcData *iptcData = iptc_data_new_from_jpeg(jpeg_srcfile_path);
    if (iptcData == NULL) {
        fprintf(stderr, "open jpeg file failed");
        return;
    }
}