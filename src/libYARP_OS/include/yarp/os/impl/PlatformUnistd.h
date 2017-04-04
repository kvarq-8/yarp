/*
 * Copyright (C) 2017 iCub Facility, Istituto Italiano di Tecnologia (IIT)
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#ifndef YARP_OS_IMPL_PLATFORMUNISTD_H
#define YARP_OS_IMPL_PLATFORMUNISTD_H

#include <yarp/conf/system.h>
#ifdef YARP_HAS_ACE
# include <ace/OS_NS_unistd.h>
#else
# include <unistd.h>
#endif

namespace yarp {
namespace os {
namespace impl {

#if defined(YARP_HAS_ACE)
    using ACE_OS::rmdir;
    inline int gethostname(char *name, size_t len) { return ACE_OS::hostname(name, len); }
    using ACE_OS::getpid;
    using ACE_OS::getppid;
    using ACE_OS::isatty;
    using ACE_OS::getcwd;
    using ACE_OS::fork;
    using ACE_OS::pipe;
    using ACE_OS::dup;
    using ACE_OS::dup2;
    using ACE_OS::execlp;
    using ACE_OS::execvp;
    using ACE_OS::chdir;
    using ACE_OS::unlink;
#else
    using ::rmdir;
    using ::gethostname;
    using ::getpid;
    using ::getppid;
    using ::isatty;
    using ::getcwd;
    using ::fork;
    using ::pipe;
    using ::dup;
    using ::dup2;
    using ::execlp;
    using ::execvp;
    using ::chdir;
    using ::unlink;
#endif

} // namespace impl
} // namespace os
} // namespace yarp


#endif // YARP_OS_IMPL_PLATFORMUNISTD_H
