#include <libiptcdata/iptc-data.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * 这个函数用来介绍如何使用 iptc_data_foreach_data 调用来实现属性的遍历
 * */
void qn_get_jpeg_iptc_info(const char *jpeg_file_path);

void qn_set_jpeg_iptc_info(const char *jpeg_srcfile_path, const char *jpeg_destfile_path);

void qn_set_jpeg_iptc_info2(const char *jpeg_srcfile_path, const char *jpeg_destfile_path);

/*
 * 这个函数用来在 iptc_data_foreach_dataset 调用的时候实现对每个 dataset 的处理
 * 其中 filter 参数可以用来指定一个数据集的名称来实现获取指定数据集数据的功能
 */
void dataset_iter_func(IptcDataSet *dataset, void *filter);
