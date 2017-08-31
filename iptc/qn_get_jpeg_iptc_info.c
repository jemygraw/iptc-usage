#include <string.h>
#include "iptc_examples.h"

void qn_get_jpeg_iptc_info(const char *jpeg_file_path) {
    IptcData *iptcData = iptc_data_new_from_jpeg(jpeg_file_path);
    if (iptcData == NULL) {
        fprintf(stderr, "open jpeg file failed");
        return;
    }

    // 并不是所有的jpeg图片都有 iptc 信息，所以可以检查一下
    if (iptcData->count > 0) {
        // 输出全部的 iptc 信息
        printf("-----------------print all iptc info-------------------\n");
        iptc_data_foreach_dataset(iptcData, dataset_iter_func, NULL);
        printf("-----------------print Keywords info of iptc-------------------\n");
        // 只输出 iptc 信息中的 Keywords 属性的值
        iptc_data_foreach_dataset(iptcData, dataset_iter_func, "Keywords");
        printf("------------------get iptc info by attribute name------------------\n");
        // 这里通过属性的名称来获取属性的值，不过有讲究，有些属性只有一个值，而有些属性有很多个值
        // 只有一个值的属性，可以通过 iptc_data_get_dataset 获取即可
        IptcDataSet *objectNameDataSet = iptc_data_get_dataset(iptcData, IPTC_RECORD_APP_2, IPTC_TAG_OBJECT_NAME);
        if (objectNameDataSet != NULL) {
            printf("ObjectName: %s\n", objectNameDataSet->data);
        }
        // 而另外的一些属性，比如 Keywords 可能存在多个值，这个时候需要配合 iptc_data_get_next_dataset 来获取剩余的属性值
        IptcDataSet *keywordsDataSet = iptc_data_get_dataset(iptcData, IPTC_RECORD_APP_2, IPTC_TAG_KEYWORDS);
        while (keywordsDataSet != NULL) {
            printf("Keywords: %s\n", keywordsDataSet->data);
            keywordsDataSet = iptc_data_get_next_dataset(iptcData, keywordsDataSet, IPTC_RECORD_APP_2,
                                                         IPTC_TAG_KEYWORDS);
        }
    } else {
        fprintf(stderr, "no datasets found");
    }

    // 记得释放获取的句柄
    iptc_data_unref(iptcData);
}