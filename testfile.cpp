#include <gtest/gtest.h>
#include "functions.h"
#include <string>

namespace Prog1 {

    TEST(JoinFunctionTests, RelativePathStartsWithPathSeparator) {
        std::string basePath = "/home/user";
        std::string relativePath = "/documents";
        EXPECT_EQ(join(basePath, relativePath), "\nThe second argument must be a relative path!!!");
    }

    TEST(JoinFunctionTests, RelativePathIsEmpty) {
        std::string basePath = "/home/user";
        std::string relativePath;
        EXPECT_EQ(join(basePath, relativePath), "\nThe second argument must be a relative path!!!");
    }

    TEST(JoinFunctionTests, BasePathEndsWithPathSeparator) {std::string basePath = "/home/user/";
        std::string relativePath = "documents";
        EXPECT_EQ(join(basePath, relativePath), "/home/user/documents");
    }

    TEST(JoinFunctionTests, BasePathDoesNotEndWithPathSeparator) {
        std::string basePath = "/home/user";
        std::string relativePath = "documents";
        EXPECT_EQ(join(basePath, relativePath), "/home/user/documents");
    }

    TEST(AbsoluteFunctionTests, RelativePathIsEmpty) {
        std::string relativePath;
        EXPECT_EQ(absolute(relativePath), "");
    }

    TEST(AbsoluteFunctionTests, RelativePathStartsWithPathSeparator) {
        std::string relativePath = "/documents";
        EXPECT_EQ(absolute(relativePath), "/documents");
    }

    TEST(AbsoluteFunctionTests, RelativePathToBeConvertedToAbsolute) {
        std::string relativePath = "documents";
        EXPECT_EQ(absolute(relativePath), "/mnt/c/Users/myDesk/Desktop/ObjectOP/b23505_volkov.ed/1/cmake-build-debug/documents");
    }

    TEST(RelativeFunctionTests, AbsolutePathIsEmpty) {
        std::string absolutePath;
        EXPECT_EQ(relative(absolutePath), "");
    }

    TEST(RelativeFunctionTests, AbsolutePathDoesNotStartWithPathSeparator) {
        std::string absolutePath = "documents";
        EXPECT_EQ(relative(absolutePath), "documents");
    }

    TEST(RelativeFunctionTests, AbsolutePathToBeConvertedToRelative) {
        std::string absolutePath = "/mnt/c/Users/myDesk/Desktop/ObjectOP/b23505_volkov.ed/etc/hosts";
        std::string expected = "../../etc/hosts";
        EXPECT_EQ(relative(absolutePath), expected);
    }

    TEST(RelativeFunctionTests, AbsolutePathOutsideCurrentDirectory) {
        std::string absolutePath = "/etc/hosts";
        EXPECT_EQ(relative(absolutePath), "../../../../../../../../../etc/hosts");
    }

    TEST(RelativizeFunctionTests, OneOfThePathsIsNotAbsolute) {
        std::string basePath = "home/user";
        std::string path = "/documents";
        EXPECT_EQ(relativize(basePath, path), "\nOne of the arguments is not an absolute path!");
    }

    TEST(RelativizeFunctionTests, BothPathsAreAbsoluteAndHaveCommonPrefix) {
        std::string basePath = "/home/user/projects/";
        std::string path = "/home/user/documents/file.txt";
        EXPECT_EQ(relativize(basePath, path), "../documents/file.txt");
    }
}