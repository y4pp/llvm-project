//===-- Unittests for strlen ----------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "src/string/strlen.h"
#include "test/UnitTest/Test.h"

TEST(LlvmLibcStrLenTest, EmptyString) {
  const char *empty = "";

  size_t result = LIBC_NAMESPACE::strlen(empty);
  ASSERT_EQ((size_t)0, result);
}

TEST(LlvmLibcStrLenTest, AnyString) {
  const char *any = "Hello World!";

  size_t result = LIBC_NAMESPACE::strlen(any);
  ASSERT_EQ((size_t)12, result);
}

TEST(LlvmLibcStrLenTest, LongString) {
  const char *long_str = "This is a very long string used for testing strlen. "
                         "It is much longer than typical strings.";

  size_t result = LIBC_NAMESPACE::strlen(long_str);
  ASSERT_EQ((size_t)95, result);
}

TEST(LlvmLibcStrLenTest, AlignedBoundary) {
  const char *aligned = "AlignedWordBoundary";

  size_t result = LIBC_NAMESPACE::strlen(aligned);
  ASSERT_EQ((size_t)19, result);
}

TEST(LlvmLibcStrLenTest, UnalignedBoundary) {
  const char *unaligned = " Unaligned";

  size_t result = LIBC_NAMESPACE::strlen(unaligned);
  ASSERT_EQ((size_t)10, result);
}

TEST(LlvmLibcStrLenTest, ZeroEdgeCase) {
  const char embedded_null[] = {'a', 'b', '\0', 'c', '\0'};

  size_t result = LIBC_NAMESPACE::strlen(embedded_null);
  ASSERT_EQ((size_t)2, result);
}
