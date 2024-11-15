//===-- Implementation of strlen ------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/string/strlen.h"
#include "src/__support/macros/config.h"
#include "src/string/string_utils.h"

#include "src/__support/common.h"

namespace LIBC_NAMESPACE_DECL {

// his version reads the string in blocks of machine word size for improved performance 
// while still falling back to a byte-by-byte check for unaligned portions
LLVM_LIBC_FUNCTION(size_t, strlen, (const char *src)) {
  // Use wide read if possible
#ifdef LIBC_COPT_STRING_UNSAFE_WIDE_READ
  return internal::string_length_wide_read<unsigned int>(src);
#else
  return internal::string_length_byte_read(src);
#endif
}

} // namespace LIBC_NAMESPACE_DECL
