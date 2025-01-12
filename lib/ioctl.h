/*****************************************************************************
 *
 *  Copyright (C) 2006-2012  Florian Pose, Ingenieurgemeinschaft IgH
 *
 *  This file is part of the IgH EtherCAT master userspace library.
 *
 *  The IgH EtherCAT master userspace library is free software; you can
 *  redistribute it and/or modify it under the terms of the GNU Lesser General
 *  Public License as published by the Free Software Foundation; version 2.1
 *  of the License.
 *
 *  The IgH EtherCAT master userspace library is distributed in the hope that
 *  it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 *  warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with the IgH EtherCAT master userspace library. If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

#ifndef __EC_LIB_IOCTL_H__
#define __EC_LIB_IOCTL_H__

/****************************************************************************/

#ifdef USE_RTDM
#include <rtdm/rtdm.h>
#else
#include <sys/ioctl.h>
#endif

/****************************************************************************/

#include "master/ioctl.h"

/****************************************************************************/

#ifdef USE_RTDM

#define ioctl rt_dev_ioctl

/* rt_dev_ioctl() returns negative error code */
#define EC_IOCTL_IS_ERROR(X) ((X) < 0)
#define EC_IOCTL_ERRNO(X) (-(X))

#else

#define ioctl ioctl

/* libc's ioctl() always returns -1 on error and sets errno */
#define EC_IOCTL_IS_ERROR(X) ((X) == -1)
#define EC_IOCTL_ERRNO(X) (errno)

#include <errno.h>

#endif

/****************************************************************************/

#endif /* __EC_LIB_IOCTL_H__ */

/****************************************************************************/
