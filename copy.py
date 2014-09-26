#!/usr/bin/env python
# encoding: utf-8

import os

filePaths = os.listdir("./src")

list.sort(filePaths)

output = open("leetcode.cpp", "w")
for filePath in filePaths:
    with open("./src/" + filePath) as f:
        output.write("// " + filePath + "\n")
        output.writelines(f.readlines())
        output.write("\n")
        f.close()
output.close()

filePaths = os.listdir("./alg")

list.sort(filePaths)

output = open("alg.cpp", "w")
for filePath in filePaths:
    with open("./alg/" + filePath) as f:
        output.write("// " + filePath + "\n")
        output.writelines(f.readlines())
        output.write("\n")
        f.close()
output.close()

