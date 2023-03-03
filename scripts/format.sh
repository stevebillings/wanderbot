#!/bin/bash

echo "Making these changes automatically:"
ament_clang_format --config ./.clang-format --reformat
ament_uncrustify --reformat
echo "YOU MUST MAKE THESE CHANGES:"
ament_cpplint
