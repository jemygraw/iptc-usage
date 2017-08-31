#include <libiptcdata/iptc-data.h>
#include <string.h>
#include <stdio.h>

/*
 * 这个函数用来在 iptc_data_foreach_dataset 调用的时候实现对每个 dataset 的处理
 * 其中 filter 参数可以用来指定一个数据集的名称来实现获取指定数据集数据的功能
 */
void dataset_iter_func(IptcDataSet *dataset, void *filter) {
    const char *dataset_name = dataset->info->name;
    if (filter && strcmp(filter, dataset_name) != 0) {
        return;
    }
    IptcFormat dataFmt = dataset->info->format;
    char *dataFmtStr = NULL;
    switch (dataFmt) {
        case IPTC_FORMAT_BINARY:
            dataFmtStr = "binary";
            break;
        case IPTC_FORMAT_STRING:
            dataFmtStr = "string";
            break;
        case IPTC_FORMAT_BYTE:
            dataFmtStr = "byte";
            break;
        case IPTC_FORMAT_SHORT:
            dataFmtStr = "short";
            break;
        case IPTC_FORMAT_LONG:
            dataFmtStr = "long";
            break;
        case IPTC_FORMAT_DATE:
            dataFmtStr = "date";
            break;
        case IPTC_FORMAT_TIME:
            dataFmtStr = "time";
            break;
        case IPTC_FORMAT_NUMERIC_STRING:
            dataFmtStr = "numeric string";
            break;
        case IPTC_FORMAT_UNKNOWN:
            dataFmtStr = "unknown";
            break;
    }
    printf("Format: %s, Name: %s, Data: %s\n", dataFmtStr, dataset->info->name, dataset->data);
}
