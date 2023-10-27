
# Functions

# Entry

TEST(Title, Section)

# 基本的なアサーション

| 致命的なアサーション                | 致命的ではないアサーション               | 検証内容                |
|-----------------------------------|----------------------------------------|------------------------|
| `ASSERT_TRUE(condition);`         | `EXPECT_TRUE(condition);`              | `condition が true`    |
| `ASSERT_FALSE(condition);`        | `EXPECT_FALSE(condition);`              | `condition が false`   |


# 比較

| 致命的なアサーション                  | 致命的ではないアサーション                 | 検証内容         |
|-------------------------------------|------------------------------------------|------------------|
| `ASSERT_EQ(expected, actual);`      | `EXPECT_EQ(expected, actual);`          | `expected == actual` |
| `ASSERT_NE(val1, val2);`            | `EXPECT_NE(val1, val2);`                | `val1 != val2`      |
| `ASSERT_LT(val1, val2);`            | `EXPECT_LT(val1, val2);`                | `val1 < val2`        |
| `ASSERT_LE(val1, val2);`            | `EXPECT_LE(val1, val2);`                | `val1 <= val2`       |
| `ASSERT_GT(val1, val2);`            | `EXPECT_GT(val1, val2);`                | `val1 > val2`        |
| `ASSERT_GE(val1, val2);`            | `EXPECT_GE(val1, val2);`                | `val1 >= val2`       |

# 文字列の比較

| Assertion                                 | Expectation                                  | 説明                                                          |
|-------------------------------------------|----------------------------------------------|---------------------------------------------------------------|
| `ASSERT_STREQ(expected_str, actual_str);`  | `EXPECT_STREQ(expected_str, actual_str);`    | 2つの C 文字列の内容が等しい                                   |
| `ASSERT_STRNE(str1, str2);`               | `EXPECT_STRNE(str1, str2);`                  | 2つの C 文字列の内容が等しくない                               |
| `ASSERT_STRCASEEQ(expected_str, actual_str);` | `EXPECT_STRCASEEQ(expected_str, actual_str);` | 大文字小文字を無視した場合，2つの C 文字列の内容が等しい       |
| `ASSERT_STRCASENE(str1, str2);`           | `EXPECT_STRCASENE(str1, str2);`              | 大文字小文字を無視した場合，2つの C 文字列の内容が等しくない   |
