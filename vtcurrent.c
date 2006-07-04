#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/vt.h>
#include <unistd.h>

// in misc-console-utils.c ripped from console-tools
int get_console_fd(char* tty_name);

int main(void)
{
    int ttyfd;
    struct vt_stat vts;
    memset(&vts,0,sizeof(vts));

    if (-1 == (ttyfd = get_console_fd(0))) { exit(1); }

    if (ioctl(ttyfd, VT_GETSTATE, &vts) < 0)
    {
	perror("ioctl");
	exit(1);
    }

    close(ttyfd);

    printf("%d\n",vts.v_active);

    return 0;
}
