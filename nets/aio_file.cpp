
#include <stdio.h>
#include <errno.h>
#include <libaio.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <inttypes.h>


#define TEST_FILE          "aio_test_file"
#define TEST_FILE_SIZE  (127 * 1024)
#define NUM_EVENTS     128
#define ALIGN_SIZE        512
#define RD_WD_SIZE     1024


























