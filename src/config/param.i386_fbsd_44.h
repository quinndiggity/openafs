#ifndef UKERNEL
/* This section for kernel libafs compiles only */

#ifndef	AFS_PARAM_H
#define	AFS_PARAM_H

#ifndef IGNORE_STDS_H
#include <sys/param.h>
#endif

#define AFS_XBSD_ENV 1		/* {Free,Open,Net}BSD */
#define AFS_X86_XBSD_ENV 1

#define AFS_NAMEI_ENV     1	/* User space interface to file system */
#define AFS_64BIT_ENV 1
#define AFS_64BIT_IOPS_ENV 1	/* Needed for NAMEI */
#define AFS_FBSD_ENV 1
#define AFS_FBSD40_ENV 1
#define AFS_FBSD42_ENV 1
#define AFS_FBSD43_ENV 1
#define AFS_FBSD44_ENV 1
#define AFS_X86_FBSD_ENV 1
#define AFS_X86_FBSD40_ENV 1
#define AFS_X86_FBSD42_ENV 1
#define AFS_X86_FBSD43_ENV 1
#define AFS_X86_FBSD44_ENV 1
#define AFS_X86_ENV 1
#define AFS_NONFSTRANS 1
#define O_SYNC O_FSYNC
#define FTRUNC O_TRUNC

#define IUPD 0x0010
#define IACC 0x0020
#define ICHG 0x0040
#define IMOD 0x0080

#define IN_LOCK(ip)     lockmgr(&ip->i_lock, LK_EXCLUSIVE, \
                                NULL, curproc)
#define IN_UNLOCK(ip)   lockmgr(&ip->i_lock, LK_RELEASE, \
                                NULL, curproc)

#include <afs/afs_sysnames.h>

#define AFS_VM_RDWR_ENV	1
#define AFS_VFS_ENV	1
#define AFS_VFSINCL_ENV 1
#define AFS_GREEDY43_ENV	1
#define AFS_ENV  	1

#define AFS_SYSCALL	210
#define AFS_MOUNT_AFS	"afs"

#ifndef MOUNT_UFS
#define MOUNT_UFS "ufs"
#endif

#ifndef	MOUNT_AFS
#define	MOUNT_AFS AFS_MOUNT_AFS
#endif
#define SYS_NAME	"i386_fbsd_44"
#define SYS_NAME_ID	SYS_NAME_ID_i386_fbsd_44

#define AFS_HAVE_FFS            1	/* Use system's ffs. */
#define AFS_HAVE_STATVFS	0	/* System doesn't supports statvfs */

#define RXK_LISTENER_ENV 1
#define AFS_GCPAGS	        0	/* if nonzero, garbage collect PAGs */
#define AFS_USE_GETTIMEOFDAY    1	/* use gettimeofday to implement rx clock */

#define AFSLITTLE_ENDIAN 1

/* Extra kernel definitions (from kdefs file) */
#ifdef _KERNEL
#define AFS_GLOBAL_SUNLOCK        1
#define	AFS_VFS34	1	/* What is VFS34??? */
#define	AFS_SHORTGID	1	/* are group id's short? */
#define	afsio_iov	uio_iov
#define	afsio_iovcnt	uio_iovcnt
#define	afsio_offset	uio_offset
#define	afsio_seg	uio_segflg
#define	afsio_resid	uio_resid
#define	AFS_UIOSYS	UIO_SYSSPACE
#define	AFS_UIOUSER	UIO_USERSPACE
#define	AFS_CLBYTES	CLBYTES
#define	osi_GetTime(x)	microtime(x)
#define AFS_KALLOC(x)   osi_fbsd_alloc((x), 1)
#undef	AFS_KALLOC_NOSLEEP
#define	AFS_KALLOC_NOSLEEP(x) osi_fbsd_alloc((x), 0)
#define AFS_KFREE(x,y)  osi_fbsd_free((x))
#define	v_count		v_usecount
#define v_vfsp		v_mount
#define vfs_bsize	mnt_stat.f_bsize
#define vfs_fsid	mnt_stat.f_fsid
#define va_nodeid	va_fileid
#define vfs_vnodecovered mnt_vnodecovered
#define direct		dirent
#define vnode_t		struct vnode

#ifndef MUTEX_DEFAULT
#define MUTEX_DEFAULT   0
#endif /* MUTEX_DEFAULT */

#ifndef SSYS
#define SSYS            0x00002
#endif /* SSYS */

#define p_rcred         p_ucred

#if	!defined(ASSEMBLER) && !defined(__LANGUAGE_ASSEMBLY__)
enum vcexcl { NONEXCL, EXCL };

#ifdef KERNEL
#ifndef MIN
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#endif
#ifndef MAX
#define MAX(A,B) ((A) > (B) ? (A) : (B))
#endif
#endif /* KERNEL */

#endif /* ! ASSEMBLER & ! __LANGUAGE_ASSEMBLY__ */
#endif /* _KERNEL */

#endif /* AFS_PARAM_H */

#else /* !defined(UKERNEL) */

/* This section for user space compiles only */

#ifndef AFS_PARAM_H
#define AFS_PARAM_H


#define UKERNEL			1	/* user space kernel */
#define AFS_ENV			1
#define AFS_VFSINCL_ENV         1
#define AFS_USR_FBSD40_ENV	1
#define AFS_USR_FBSD42_ENV	1
#define AFS_USR_FBSD43_ENV	1
#define AFS_USR_FBSD44_ENV	1
#define AFS_USR_FBSD_ENV	1
#define AFS_NONFSTRANS 1

#define O_SYNC O_FSYNC

#define AFS_MOUNT_AFS "afs"	/* The name of the filesystem type. */
#define AFS_SYSCALL 210
#define AFS_NAMEI_ENV         1	/* User space interface to file system */
#define AFS_64BIT_ENV 1
#define AFS_64BIT_IOPS_ENV    1	/* Needed for NAMEI */
#include <afs/afs_sysnames.h>

#define AFS_USERSPACE_IP_ADDR 1
#define RXK_LISTENER_ENV      1
#define AFS_GCPAGS	      0	/* if nonzero, garbage collect PAGs */

/* Machine / Operating system information */
#define SYS_NAME	"i386_fbsd_44"
#define SYS_NAME_ID	SYS_NAME_ID_i386_fbsd_44
#define AFSLITTLE_ENDIAN    1
#define AFS_HAVE_FFS        1	/* Use system's ffs. */
#define AFS_HAVE_STATVFS    0	/* System doesn't support statvfs */
#define AFS_VM_RDWR_ENV	    1	/* read/write implemented via VM */

#define	afsio_iov	uio_iov
#define	afsio_iovcnt	uio_iovcnt
#define	afsio_offset	uio_offset
#define	afsio_seg	uio_segflg
#define	afsio_fmode	uio_fmode
#define	afsio_resid	uio_resid
#define	AFS_UIOSYS	1
#define	AFS_UIOUSER	UIO_USERSPACE
#define	AFS_CLBYTES	MCLBYTES
#define	AFS_MINCHANGE	2
#define	VATTR_NULL	usr_vattr_null

#define AFS_DIRENT
#ifndef CMSERVERPREF
#define CMSERVERPREF
#endif

#include <limits.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <sys/fcntl.h>
#include <netinet/in.h>
#include <sys/uio.h>
#include <sys/socket.h>

#endif /* AFS_PARAM_H */

#endif /* !defined(UKERNEL) */