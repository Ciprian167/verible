// Copyright 2017-2020 The Verible Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "verilog/parser/verilog_token_classifications.h"

#include "gtest/gtest.h"
#include "verilog/parser/verilog_token_enum.h"

namespace verilog {
namespace {

TEST(VerilogTokenTest, IsWhitespaceTest) {
  EXPECT_TRUE(IsWhitespace(verilog_tokentype::TK_NEWLINE));
  EXPECT_TRUE(IsWhitespace(verilog_tokentype::TK_SPACE));
  EXPECT_FALSE(IsWhitespace(verilog_tokentype::TK_class));
  EXPECT_FALSE(IsWhitespace(verilog_tokentype::SymbolIdentifier));
}

// Given a verilog_tokentype, test that IsComment returns true only for comments
TEST(VerilogTokenTest, IsCommentTest) {
  EXPECT_TRUE(IsComment(verilog_tokentype::TK_COMMENT_BLOCK));
  EXPECT_TRUE(IsComment(verilog_tokentype::TK_EOL_COMMENT));
  EXPECT_FALSE(IsComment(verilog_tokentype::DR_begin_keywords));
  EXPECT_FALSE(IsComment(verilog_tokentype::SymbolIdentifier));
}

TEST(VerilogTokenTest, IsUnaryOperatorTest) {
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype('*')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype('/')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('+')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('-')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('~')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('&')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('!')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('|')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype('^')));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype::TK_NAND));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype::TK_NOR));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype::TK_NXOR));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype::TK_INCR));
  EXPECT_TRUE(IsUnaryOperator(verilog_tokentype::TK_DECR));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype(':')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype('?')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype(',')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype('.')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype(';')));
  EXPECT_FALSE(IsUnaryOperator(verilog_tokentype('#')));
}

TEST(VerilogTokenTest, IsTernaryOperatorTest) {
  EXPECT_FALSE(IsTernaryOperator(verilog_tokentype('*')));
  EXPECT_FALSE(IsTernaryOperator(verilog_tokentype('/')));
  EXPECT_FALSE(IsTernaryOperator(verilog_tokentype('+')));
  EXPECT_FALSE(IsTernaryOperator(verilog_tokentype('-')));
  EXPECT_TRUE(IsTernaryOperator(verilog_tokentype('?')));
  EXPECT_TRUE(IsTernaryOperator(verilog_tokentype(':')));
}

}  // namespace
}  // namespace verilog
