#include <stdio.h>
#include "iptc_examples.h"

int main() {
    char *jpg_file_path = "/Users/jemy/CLionProjects/iptc/iptc-base.jpg";
    qn_get_jpeg_iptc_info(jpg_file_path);
}