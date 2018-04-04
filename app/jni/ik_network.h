
#ifndef __IK_NETWORK_H__
#define __IK_NETWORK_H__

#include "ik_public.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <netinet/ether.h>
#include <sys/ioctl.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <linux/route.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <net/if_arp.h> 
#include <dirent.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>
#include <errno.h>

int getHost(char *pValue, int pLen);


#endif /* __IK_NETWORK_H__ */
